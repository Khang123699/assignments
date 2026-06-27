## 1. Description
A simple function pointer example implementation in C

## 2. How to run in Linux
Type the `make` command in the terminal of your project directory.

![alt text](https://docs.google.com/uc?export=view&id=1DMPo7G6tq8GgmHxp8ZyGuB9BuM-EOjhw)

(Make sure you have gcc installed and a configured makefile)

If build is successful, you will see the compilation command and have a file named `function_pointer_test`:

```bash
gcc -Wall -Wextra -g function_pointer.c unit_test.c -o function_pointer_test
```

Run file `function_pointer_test` to see the test result by command `./function_pointer_test`

## 3. Test case overview

Note: Each test case calls the `compute` function passing two integers and a specific operation callback.

**TEST 1: Addition callback (`add`)**
- **Purpose:** Ensure `compute` correctly invokes the `add` callback function and returns the sum of the two inputs.
- **Input:** `x = 10`, `y = 5`, callback = `add`.
- **Expected:** Returns `15`.

**TEST 2: Multiplication callback (`multiply`)**
- **Purpose:** Ensure `compute` correctly invokes the `multiply` callback function and returns the product of the two inputs.
- **Input:** `x = 10`, `y = 5`, callback = `multiply`.
- **Expected:** Returns `50`.

## 4. Test result
If all tests pass, the output will look like:
```text
Running function pointer unit tests...

Test 1: add
test1 add:          PASS

Test 2: multiply
test2 multiply:     PASS

 ALL TEST PASS!!! 
```
