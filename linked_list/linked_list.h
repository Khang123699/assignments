#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stdio.h>
#include <stdlib.h>

/*Define the data structure for a Node*/
typedef struct node_t {
    int data;
    struct node_t* next;
}node_t;

/*Define the data structure for a Linked List*/
typedef struct {
    node_t* head;
    node_t* tail;
}list_t;

/*Declare functions for managing and manipulating lists*/
void list_init(list_t* list);
node_t* list_allocate_node(); 
void list_put_head(list_t* list, int data);  
void list_put_tail(list_t* list, int data);  
void list_remove_head(list_t* list);         
void list_dump(list_t* list); 

#endif //LINKED_LIST_H