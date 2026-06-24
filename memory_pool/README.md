## 1. Description
A memory pool allocator implementation in C

## 2. How to run in Linux
Type the `make` command in the terminal of your project directory.

(Make sure you have gcc installed and a configured makefile)

If build is successful, you will see the following output and have file named `memory_pool_test`:

Run file `memory_pool_test` to see the test result by command `./memory_pool_test`

## 3. Test case overview

Note: Each test case is run to verify a specific functionality of the memory pool.

**TEST 1: Allocate a block (`memory_pool_alloc`)**
- **Purpose:** Ensure `memory_pool_alloc` allocates a block from the memory pool correctly and returns a non-null pointer when blocks are available.
- **Input:** Initialized pool -> call `memory_pool_alloc`.
- **Expected:** Returns a valid node (`node1 != NULL`).

**TEST 2: Write and read payload data (`data read/write`)**
- **Purpose:** Ensure payload data can be written to and read from the allocated block successfully.
- **Input:** Allocated node -> write "Pool Test" into payload -> read payload.
- **Expected:** Read payload content matches "Pool Test".

**TEST 3: Free and re-allocate block (`free and re-allocate`)**
- **Purpose:** Ensure `memory_pool_free` returns a block to the free list, and a subsequent allocation retrieves the same block.
- **Input:** Allocated node -> free node -> allocate again.
- **Expected:** The newly allocated node matches the previously freed node.

## 4. Test result
![alt text](https://docs.google.com/uc?export=view&id=1nvhb-f_xhP8d4fwZg6V1U43oglKfycjU)

