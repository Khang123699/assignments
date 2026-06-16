#ifndef RING_BUFFER_H
#define RING_BUFFER_H

#include <stdint.h>
#include <stdbool.h>

/*RBC Struct*/
typedef struct {
    uint16_t tail_index;
    uint16_t head_index;
    uint16_t fill_size;
    uint16_t buffer_size;
    uint8_t* buffer;
} ring_buffer_char_t;
 
/*Declare functions*/
void ring_buffer_char_init(ring_buffer_char_t* ring_buffer, void* buffer, uint16_t buffer_size);
void ring_buffer_char_put(ring_buffer_char_t* ring_buffer, uint8_t c);
uint8_t ring_buffer_char_get(ring_buffer_char_t* ring_buffer);
bool ring_buffer_char_empty(ring_buffer_char_t* ring_buffer);
bool ring_buffer_char_full(ring_buffer_char_t* ring_buffer);

#endif