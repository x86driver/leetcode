#include <gtest/gtest.h>
#include <stack>
#include <iostream>

using namespace std;

class MyQueue {
private:
  stack<int> s1;
  stack<int> s2;
  int front;
public:
  /** Initialize your data structure here. */
  MyQueue() {

  }

  /** Push element x to the back of queue. */
  void push(int x) {
      if (s1.empty()) {
          front = x;
      }
      s1.push(x);
  }

  /** Removes the element from in front of queue and returns that element. */
  int pop() {
      if (s2.empty()) {
          while (!s1.empty()) {
              s2.push(s1.top());
              s1.pop();
          }
      }
      int ret = s2.top();
      s2.pop();
      return ret;
  }

  /** Get the front element. */
  int peek() {
      if (!s2.empty()) {
          return s2.top();
      }
      return front;
  }

  /** Returns whether the queue is empty. */
  bool empty() {
      return s1.empty() && s2.empty();
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
