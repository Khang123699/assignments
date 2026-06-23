#include "linked_list.h"

/* Implementation of linked list functions */
//Initialize the list
void list_init(list_t* list) {
    if (list == NULL) return;
    list->head = NULL;
    list->tail = NULL;
}
//Allocate memory for a list
node_t* list_allocate_node() {
    node_t* new_node = (node_t*)malloc(sizeof(node_t));
    if (!new_node) {
        printf("[list_log] Memory allocation failed\n");
        exit(1);
    }
    return new_node;
}
//Add a new node to the head of the list
void list_put_head(list_t* list, int data) {
    node_t* new_node = list_allocate_node();

    new_node->data = data;
    new_node->next = NULL;

    if (list->head == NULL) {
        list->head = new_node;
        list->tail = new_node;
    }
    else {
        new_node->next = list->head;
        list->head = new_node;
    }
}
//Add a new node to the tail of the list
void list_put_tail(list_t* list, int data) {
    node_t* new_node = list_allocate_node();

    new_node->data = data;
    new_node->next = NULL;

    if (list->tail == NULL) {
        list->head = new_node;
        list->tail = new_node;
    }
    else {
        list->tail->next = new_node;
        list->tail = new_node;
    }
}
//Remove the head node from the list
void list_remove_head(list_t* list) {
    if (list->head == NULL) {
        printf("[list log] list is empty!\n");
        return;
    }
    
    node_t* node_rm = list->head;
    list->head = node_rm->next;
    free(node_rm);
    
    if (list->head == NULL) {
        list->tail = NULL;
    }
}
//Dump the contents of the list
void list_dump(list_t* list) {
    printf("\n");
    node_t* node_dump = list->head;
    while (node_dump != NULL) {
        printf("%d -> ", node_dump->data);
        node_dump = node_dump->next;
    }
    printf("NULL\n");
    printf("\n");
}