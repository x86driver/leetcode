#pragma once
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
} Queue;

Queue* QueueCreate(int k);
bool QueueIsEmpty(Queue* obj);
bool QueueIsFull(Queue* obj);
bool QueueEnQueue(Queue* queue, int data);
bool QueueDeQueue(Queue* queue);
bool QueueRemove(Queue* queue, int data);
int QueueFront(Queue* obj);
int QueueRear(Queue* obj);
void QueueFree(Queue* obj);
