#include "function_pointer.h"

// Math helper routines
int add(int a, int b) {
    return a + b;
}

int multiply(int a, int b) {
    return a * b;
}

// Process computation via operation callback
int compute(int a, int b, op_fn operation) {
    return operation(a, b);
}
