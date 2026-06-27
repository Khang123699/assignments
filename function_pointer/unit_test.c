#include <stdio.h>
#include "function_pointer.h"

/* Helper to print result and validate status */
static int verify(int status, const char* name, const char* error) {
    if (status) {
        printf("%sPASS\n", name);
    } else {
        printf("%sFAIL\n", name);
    }
    
    if (!status) {
        printf("%s\n", error);
        return 0;
    }
    return 1;
}

int main() {
    int x = 10;
    int y = 5;
    printf("Running function pointer unit tests...\n");

    // test 1: add
    printf("\nTest 1: add\n");
    int res_add = compute(x, y, add);
    int status = (res_add == 15);
    if (!verify(status, "test1 add:          ", "Test 1 failed!")) return -1;

    // test 2: multiply
    printf("\nTest 2: multiply\n");
    int res_mul = compute(x, y, multiply);
    status = (res_mul == 50);
    if (!verify(status, "test2 multiply:     ", "Test 2 failed!")) return -1;

    printf("\n ALL TEST PASS!!! \n");
    return 0;
}
