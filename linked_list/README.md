## 1. Description
A singly linked list implementation in C

## 2. How to run in Linux
Type the `make` command in the terminal of your project directory.

![alt text](https://docs.google.com/uc?export=view&id=1DMPo7G6tq8GgmHxp8ZyGuB9BuM-EOjhw)

(Make sure you have gcc installed and a configured makefile)

If build is successful, you will see the following output and have file named `linked_list_test`:

![alt text](https://docs.google.com/uc?export=view&id=1UQr5nVcZJYDY7UA0lfUaQX3Wdfy83Yjm)

Run file `linked_list_test` to see the test result by command `./linked_list_test`

## 3. Test case overview

** Note:** Each test case uses a fresh list initialized via `list_init()` to ensure state isolation.

**TEST 1: Insert at the beginning (`put_head`)**
- **Purpose:** Ensure `list_put_head` inserts data correctly at the first position.
- **Input:** Empty list -> insert `10` -> insert `20`.
- **Expected:** `head` points to `20`, `tail` points to `10` (List: `20 -> 10`).

**TEST 2: Insert at the end (`put_tail`)**
- **Purpose:** Ensure `list_put_tail` appends data correctly to the end of the list.
- **Input:** Empty list -> insert `10` -> insert `20`.
- **Expected:** `head` points to `10`, `tail` points to `20` (List: `10 -> 20`).

**TEST 3: Remove the first element (`remove_head`)**
- **Purpose:** Ensure `list_remove_head` correctly removes the head node and updates the `head` pointer.
- **Input:** List contains `10 -> 20`. Call remove once.
- **Expected:** Node `10` is freed; `head` and `tail` both point to `20`.

**TEST 4: Handle empty list exception (`remove_empty`)**
- **Purpose:** Ensure the remove function does not crash the system when the list has no data.
- **Input:** Empty list. Call remove once.
- **Expected:** Prints a warning log; `head` and `tail` remain `NULL`.

## 4. Test result
![alt text](https://docs.google.com/uc?export=view&id=1dZdWKxTzHJ8mWG8NmwjSFqLoAQ3dfgFK)
