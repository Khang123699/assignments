#ifndef FUNCTION_POINTER_H
#define FUNCTION_POINTER_H

// Operation function callback
typedef int (*op_fn)(int, int);

int compute(int a, int b, op_fn operation);

int add(int a, int b);
int multiply(int a, int b);

#endif // FUNCTION_POINTER_H
