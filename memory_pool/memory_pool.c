#include "memory_pool.h"

/* Initialize the memory pool */
void memory_pool_init(memory_pool_t* pool) {
    pool->free_list = pool->buffer;
    for (int i = 0; i < POOL_SIZE - 1; i++) {
        pool->buffer[i].next = &pool->buffer[i + 1];
    }
    pool->buffer[POOL_SIZE - 1].next = NULL;
}

/* Allocate a block from the pool */
pool_node_t* memory_pool_alloc(memory_pool_t* pool) {
    if (pool->free_list == NULL) {
        return NULL;
    }
    pool_node_t* node = pool->free_list;
    pool->free_list = node->next;
    return node;
}

/* Free an allocated block back to the pool */
void memory_pool_free(memory_pool_t* pool, pool_node_t* block) {
    if (block == NULL) {
        return;
    }
    block->next = pool->free_list;
    pool->free_list = block;
}
