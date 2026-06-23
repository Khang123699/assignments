#include <stdio.h>
#include "linked_list.h"

int main() {
    // Test setup
    list_t msg_list;
    int status;
    printf("Running linked list unit tests...\n");

    // test 1: put_head
    printf("\nTest 1: put_head\n");
    list_init(&msg_list);
    list_put_head(&msg_list, 10);
    list_put_head(&msg_list, 20);
    // expected: 20 -> 10
    status = (msg_list.head != NULL && msg_list.head->data == 20 && msg_list.tail->data == 10);
    list_dump(&msg_list); 
    printf("test1 put_head:     %s\n", status ? "PASS" : "FAIL");
    if (!status) {
        printf("Test 1 failed!\n");
        return -1;
    }

    // test 2: put_tail
    printf("\nTest 2: put_tail\n");
    list_init(&msg_list); 
    list_put_tail(&msg_list, 10);
    list_put_tail(&msg_list, 20);
    // expected: 10 -> 20
    status = (msg_list.head != NULL && msg_list.head->data == 10 && msg_list.tail->data == 20);
    list_dump(&msg_list); 
    printf("test2 put_tail:     %s\n", status ? "PASS" : "FAIL");
    if (!status) {
        printf("Test 2 failed!\n");
        return -1;
    }

    // test 3: remove_head
    printf("\nTest 3: remove_head\n");
    list_init(&msg_list);
    list_put_tail(&msg_list, 10);
    list_put_tail(&msg_list, 20);
    list_remove_head(&msg_list);
    // expected: element 10 is removed, list contains 20 -> NULL
    status = (msg_list.head != NULL && msg_list.head->data == 20 && msg_list.tail->data == 20);
    list_dump(&msg_list);
    printf("test3 remove_head:  %s\n", status ? "PASS" : "FAIL");
    if (!status) {
        printf("Test 3 failed!\n");
        return -1;
    }

    // test 4: remove_empty
    printf("\nTest 4: remove_empty\n");
    list_init(&msg_list);
    list_remove_head(&msg_list);
    // expected: removing an empty list does not cause errors, head and tail are still NULL
    status = (msg_list.head == NULL && msg_list.tail == NULL);
    list_dump(&msg_list);
    printf("test4 remove_empty: %s\n", status ? "PASS" : "FAIL");
    if (!status){
        printf("Test 4 failed!\n");
        return -1;
    }

    printf("\n ALL TEST PASS!!! \n");
    return 0;
}