#include "linked_list.h"
#include <stdio.h>
#include <stdlib.h>

/* Initialize list */
void list_init(list_t* list) {
    list->head = NULL;
    list->tail = NULL;
}

/* Allocate node */
node_t* list_allocate_node(void) {
    node_t* node = (node_t*)malloc(sizeof(node_t));
    if (node == NULL) {
        printf("[list log] memory allocation failed!\n");
        exit(1);
    }
    return node;
}

/* Insert at head */
void list_put_head(list_t* list, int data) {
    node_t* node = list_allocate_node();
    node->data = data;
    node->next = list->head;
    list->head = node;
    if (list->tail == NULL) {
        list->tail = node;
    }
}

/* Insert at tail */
void list_put_tail(list_t* list, int data) {
    node_t* node = list_allocate_node();
    node->data = data;
    node->next = NULL;
    if (list->tail != NULL) {
        list->tail->next = node;
    } else {
        list->head = node;
    }
    list->tail = node;
}

/* Remove head node */
void list_remove_head(list_t* list) {
    if (list->head == NULL) {
        printf("[list log] list is empty!\n");
        return;
    }
    node_t* rm_node = list->head;
    list->head = rm_node->next;
    if (list->head == NULL) {
        list->tail = NULL;
    }
    free(rm_node);
}

/* Print list */
void list_dump(list_t* list) {
    printf("\n");
    for (node_t* curr = list->head; curr != NULL; curr = curr->next) {
        printf("%d -> ", curr->data);
    }
    printf("NULL\n\n");
}