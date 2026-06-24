#include <stdio.h>
#include <string.h>
#include "memory_pool.h"

/* Validate test result */
static int check(const char* name, const char* err, int ok) {
    if (ok) {
        printf("%sPASS\n", name);
        return 1;
    }
    printf("%sFAIL\n", name);
    printf("%s\n", err);
    return 0;
}

int main(void) {
    memory_pool_t pool;
    printf("Running memory pool unit tests...\n");

    /* Initialize pool */
    memory_pool_init(&pool);

    /* Test 1: Allocate a block */
    printf("\nTest 1: allocate node\n");
    pool_node_t* node1 = memory_pool_alloc(&pool);
    if (!check("test1 alloc:         ", "Test 1 failed!", node1 != NULL)) return -1;

    /* Test 2: Write and read payload data */
    printf("\nTest 2: data read/write\n");
    strcpy((char*)node1->payload, "Pool Test");
    int data_ok = (strcmp((char*)node1->payload, "Pool Test") == 0);
    if (!check("test2 data:          ", "Test 2 failed!", data_ok)) return -1;

    /* Test 3: Free and re-allocate block */
    printf("\nTest 3: free and re-allocate\n");
    memory_pool_free(&pool, node1);
    pool_node_t* node2 = memory_pool_alloc(&pool);
    if (!check("test3 free_alloc:    ", "Test 3 failed!", node2 == node1)) return -1;

    printf("\n ALL TEST PASS!!! \n");
    return 0;
}
