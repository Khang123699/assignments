#include <stdio.h>
#include "linked_list.h"

/* Helper to dump list, print result, and validate status */
static int verify(list_t* list, int status, const char* name, const char* err) {
    list_dump(list);
    printf("%s%s\n", name, status ? "PASS" : "FAIL");
    if (!status) {
        printf("%s\n", err);
        return 0;
    }
    return 1;
}

int main() {
    list_t msg_list;
    int status;
    printf("Running linked list unit tests...\n");

    // test 1: put_head
    printf("\nTest 1: put_head\n");
    list_init(&msg_list);
    list_put_head(&msg_list, 10);
    list_put_head(&msg_list, 20);
    status = (msg_list.head != NULL && msg_list.head->data == 20 && msg_list.tail->data == 10);
    if (!verify(&msg_list, status, "test1 put_head:     ", "Test 1 failed!")) return -1;

    // test 2: put_tail
    printf("\nTest 2: put_tail\n");
    list_init(&msg_list); 
    list_put_tail(&msg_list, 10);
    list_put_tail(&msg_list, 20);
    status = (msg_list.head != NULL && msg_list.head->data == 10 && msg_list.tail->data == 20);
    if (!verify(&msg_list, status, "test2 put_tail:     ", "Test 2 failed!")) return -1;

    // test 3: remove_head
    printf("\nTest 3: remove_head\n");
    list_init(&msg_list);
    list_put_tail(&msg_list, 10);
    list_put_tail(&msg_list, 20);
    list_remove_head(&msg_list);
    status = (msg_list.head != NULL && msg_list.head->data == 20 && msg_list.tail->data == 20);
    if (!verify(&msg_list, status, "test3 remove_head:  ", "Test 3 failed!")) return -1;

    // test 4: remove_empty
    printf("\nTest 4: remove_empty\n");
    list_init(&msg_list);
    list_remove_head(&msg_list);
    status = (msg_list.head == NULL && msg_list.tail == NULL);
    if (!verify(&msg_list, status, "test4 remove_empty: ", "Test 4 failed!")) return -1;

    printf("\n ALL TEST PASS!!! \n");
    return 0;
}