class MovingAverage {
private:
    int sum;
    int size;
    int counter;
    queue<int> q;
public:
    MovingAverage(int size) {
        this->size = size;
        this->sum = 0;
        this->counter = 0;
    }

    double next(int val) {
        ++counter;
        q.push(val);
        if (q.size() > size) {
            --counter;
            sum -= q.front();
            q.pop();
        }
        sum += val;
        return (double)sum / counter / 1.0;
    }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */
