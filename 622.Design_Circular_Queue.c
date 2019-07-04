#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

struct QueueItem {
  int data;
  struct QueueItem *prev;
  struct QueueItem *next;
};

typedef struct {
  struct QueueItem *head;
  struct QueueItem *tail;
  int size;
  int elems;
} MyCircularQueue;

/** Initialize your data structure here. Set the size of the queue to be k. */

MyCircularQueue* myCircularQueueCreate(int k) {
    MyCircularQueue *q = (MyCircularQueue*)calloc(1, sizeof(*q));
    q->size = k;
    q->elems = 0;
    return q;
}

/** Checks whether the circular queue is empty or not. */
bool myCircularQueueIsEmpty(MyCircularQueue* obj) {
    return obj->elems == 0;
}

/** Checks whether the circular queue is full or not. */
bool myCircularQueueIsFull(MyCircularQueue* obj) {
    return obj->size == obj->elems;
}

/** Insert an element into the circular queue. Return true if the operation is successful. */
bool myCircularQueueEnQueue(MyCircularQueue* queue, int data) {
    if (myCircularQueueIsFull(queue)) {
        return false;
    }

    struct QueueItem *item = (struct QueueItem*)calloc(1, sizeof(*item));
    item->data = data;
    item->next = item->prev = NULL;

    if (!queue->head) {
        queue->head = item;
    }

    if (queue->tail) {
        item->prev = queue->tail;
        queue->tail->next = item;
    }

    queue->tail = item;
    ++queue->elems;
    return true;
}

/** Delete an element from the circular queue. Return true if the operation is successful. */
bool myCircularQueueDeQueue(MyCircularQueue* queue) {
    if (queue->elems == 0) {
        return false;
    }
    struct QueueItem *head = queue->head;
    if (head->next) {
        queue->head = head->next;
    } else {
        queue->head = queue->tail = NULL;
    }

    free(head);
    --queue->elems;
    return true;
}

/** Get the front item from the queue. */
int myCircularQueueFront(MyCircularQueue* obj) {
    if (obj->elems <= 0) {
        return -1;
    }
    return obj->head->data;
}

/** Get the last item from the queue. */
int myCircularQueueRear(MyCircularQueue* obj) {
    if (obj->elems <= 0) {
        return -1;
    }
    return obj->tail->data;
}

void myCircularQueueFree(MyCircularQueue* obj) {
    if (!obj) {
        return;
    }
    while (myCircularQueueDeQueue(obj));
    free(obj);
}

int main() {
    MyCircularQueue* obj = myCircularQueueCreate(6);
    printf("enque 6: %d\n", myCircularQueueEnQueue(obj, 6));
    printf("rear: %d\n", myCircularQueueRear(obj));
    printf("rear: %d\n", myCircularQueueRear(obj));
    printf("deque: %d\n", myCircularQueueDeQueue(obj));
    printf("enque 5: %d\n", myCircularQueueEnQueue(obj, 5));
    printf("rear: %d\n", myCircularQueueRear(obj));
    printf("deque: %d\n", myCircularQueueDeQueue(obj));
    printf("front: %d\n", myCircularQueueFront(obj));
    printf("deque: %d\n", myCircularQueueDeQueue(obj));
    printf("deque: %d\n", myCircularQueueDeQueue(obj));
    printf("deque: %d\n", myCircularQueueDeQueue(obj));

    myCircularQueueFree(obj);
}
