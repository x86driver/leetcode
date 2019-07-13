#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "queue.h"

/** Initialize your data structure here. Set the size of the queue to be k. */
Queue* QueueCreate(int k) {
    Queue *q = (Queue*)calloc(1, sizeof(*q));
    q->size = k;
    q->elems = 0;
    return q;
}

/** Checks whether the circular queue is empty or not. */
bool QueueIsEmpty(Queue* obj) {
    return obj->elems == 0;
}

/** Checks whether the circular queue is full or not. */
bool QueueIsFull(Queue* obj) {
    return obj->size == obj->elems;
}

/** Insert an element into the circular queue. Return true if the operation is successful. */
bool QueueEnQueue(Queue* queue, int data) {
    if (QueueIsFull(queue)) {
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
bool QueueDeQueue(Queue* queue) {
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

bool QueueRemove(Queue* queue, int data) {
    if (queue->elems == 0) {
        return false;
    }
    struct QueueItem *item = queue->head;
    if (item->data == data) {
        return QueueDeQueue(queue);
    }

    while (item) {
        if (item->data == data) {
            item->prev->next = item->next;
            if (item->next) { // if has tail
                item->next->prev = item->prev;
            } else { // if item is last one
                queue->tail = item->prev;
            }
            free(item);
            --queue->elems;
            return true;
        }
        item = item->next;
    }
    return false;
}

/** Get the front item from the queue. */
int QueueFront(Queue* obj) {
    if (obj->elems <= 0) {
        return -1;
    }
    return obj->head->data;
}

/** Get the last item from the queue. */
int QueueRear(Queue* obj) {
    if (obj->elems <= 0) {
        return -1;
    }
    return obj->tail->data;
}

void QueueFree(Queue* obj) {
    if (!obj) {
        return;
    }
    while (QueueDeQueue(obj));
    free(obj);
}
