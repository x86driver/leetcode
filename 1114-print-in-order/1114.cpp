class Foo {
private:
    std::promise<void> firstDone;
    std::shared_future<void> firstDoneFuture;

    std::promise<void> secondDone;
    std::shared_future<void> secondDoneFuture;

    std::promise<void> thirdDone;
    std::shared_future<void> thirdDoneFuture;
public:
    Foo() {
        firstDoneFuture = firstDone.get_future();

        secondDoneFuture = secondDone.get_future();

        thirdDoneFuture = thirdDone.get_future();
    }

    void first(function<void()> printFirst) {

        // printFirst() outputs "first". Do not change or remove this line.
        printFirst();
        firstDone.set_value();
    }

    void second(function<void()> printSecond) {

        firstDoneFuture.wait();
        // printSecond() outputs "second". Do not change or remove this line.
        printSecond();
        secondDone.set_value();
    }

    void third(function<void()> printThird) {

        secondDoneFuture.wait();
        // printThird() outputs "third". Do not change or remove this line.
        printThird();
        thirdDone.set_value();
    }
};
