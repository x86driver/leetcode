#include <gtest/gtest.h>
#include <stack>
#include <iostream>

using namespace std;

class MyQueue {
private:
  stack<int> s;
public:
  /** Initialize your data structure here. */
  MyQueue() {

  }

  /** Push element x to the back of queue. */
  void push(int x) {
      s.push(x);
  }

  /** Removes the element from in front of queue and returns that element. */
  int pop() {
      stack<int> temp;
      while (s.size() > 1) {
          temp.push(s.top());
          s.pop();
      }
      int ret = s.top();
      s.pop();
      while (temp.size() > 0) {
          s.push(temp.top());
          temp.pop();
      }
      return ret;
  }

  /** Get the front element. */
  int peek() {
      stack<int> temp = s;
      while (temp.size() > 1) {
          temp.pop();
      }
      return temp.top();
  }

  /** Returns whether the queue is empty. */
  bool empty() {
      return s.empty();
  }
};

#ifndef GOOGLE_TEST

int main() {
    MyQueue *obj = new MyQueue();
    obj->push(1);
    obj->push(2);
    obj->push(3);
    int param_1 = obj->pop();
    int param_2 = obj->pop();
    int param_3 = obj->pop();

    printf("%d, %d, %d\n", param_1, param_2, param_3);

    delete obj;
    return 0;
}
#else

TEST(MyQueue, test1) {
    MyQueue *obj = new MyQueue();
    obj->push(1);
    obj->push(2);
    obj->push(3);
    EXPECT_EQ(obj->pop(), 1);
    EXPECT_EQ(obj->pop(), 2);
    EXPECT_EQ(obj->pop(), 3);
    EXPECT_EQ(obj->empty(), true);
}

int main() {
    testing::InitGoogleTest();
    printf("test: %d\n", RUN_ALL_TESTS());
    return 0;
}

#endif
