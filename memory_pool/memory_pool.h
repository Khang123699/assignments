#ifndef MEMORY_POOL_H
#define MEMORY_POOL_H

#include <stdint.h>
#include <stddef.h>

#define POOL_SIZE 16

/* Pool node structure */
typedef struct pool_node_t {
    struct pool_node_t* next;
    uint8_t payload[16];
} pool_node_t;

/* Memory pool structure */
typedef struct {
    pool_node_t* free_list;
    pool_node_t buffer[POOL_SIZE];
} memory_pool_t;

/* Pool operations */
void memory_pool_init(memory_pool_t* pool);
pool_node_t* memory_pool_alloc(memory_pool_t* pool);
void memory_pool_free(memory_pool_t* pool, pool_node_t* block);

#endif /* MEMORY_POOL_H */
