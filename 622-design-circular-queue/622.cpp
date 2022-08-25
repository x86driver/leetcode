class MyCircularQueue {
private:
    int *data;
    int front, rear;
    int length;
    int k;
public:
    MyCircularQueue(int k) {
        data = new int[k];
        front = rear = 0;
        length = 0;
        this->k = k;
    }

    bool enQueue(int value) {
        if (!isFull()) {
            if (rear >= this->k) {
                rear = 0;
            }
            data[rear] = value;
            ++rear;
            ++length;
            return true;
        } else {
            return false;
        }
    }

    bool deQueue() {
        if (!isEmpty()) {
            ++front;
            if (front >= this->k) {
                front = 0;
            }
            --length;
            return true;
        } else {
            return false;
        }
    }

    int Front() {
        if (isEmpty()) {
            return -1;
        } else {
            return data[front];
        }
    }

    int Rear() {
        if (isEmpty()) {
            return -1;
        } else {
            return data[rear-1];
        }
    }

    bool isEmpty() {
        return length == 0;
    }

    bool isFull() {
        return length == this->k;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */
