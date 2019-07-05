#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <stdbool.h>
#include "list.h"

List *create_list() {
    List *list = (List*)calloc(1, sizeof(*list));
    if (list) {
        return list;
    }
    perror("calloc List error");
    return NULL;
}

bool insert_to_list(List *list, const void *data) {
    struct ListItem *item = (struct ListItem*)calloc(1, sizeof(*item));
    if (!item) {
        perror("calloc ListItem ereror");
        return false;
    }

    if (!list->head) {
        list->head = item;
    }

    if (list->tail) {
        list->tail->next = item;
    }

    list->tail = item;
    item->data = data;

    ++list->size;
    return true;
}

void destroy_list(List *list) {
    struct ListItem *item = list->head;
    while (item) {
        struct ListItem *tmp = item;
        item = item->next;
        free(tmp);
    }
    free(list);
}

void print_list(List *list) {
    struct ListItem *item = list->head;
    while (item) {
        printf("%ld -> ", (long)item->data);
        item = item->next;
    }
    printf("\n");
}

#ifndef _LIB_
int main() {
    List *list = create_list();
    for (long i = 0; i < 10; ++i) {
        insert_to_list(list, (void*)i);
    }
    print_list(list);
    destroy_list(list);
    return 0;
}
#endif
