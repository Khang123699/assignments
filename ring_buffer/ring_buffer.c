#include "ring_buffer.h"
#include <stdio.h>

/* Initialize ring buffer */
void ring_buffer_char_init(ring_buffer_char_t* ring_buffer, void* buffer, uint16_t buffer_size) {
    ring_buffer->tail_index = 0;
    ring_buffer->head_index = 0;
    ring_buffer->fill_size = 0;
    ring_buffer->buffer_size = buffer_size;
    ring_buffer->buffer = (uint8_t*)buffer;
}

/* Put character into ring buffer */
void ring_buffer_char_put(ring_buffer_char_t* ring_buffer, uint8_t c) {
    ring_buffer->buffer[ring_buffer->tail_index] = c;
    ring_buffer->tail_index = (ring_buffer->tail_index + 1) % ring_buffer->buffer_size;

    if (ring_buffer->fill_size < ring_buffer->buffer_size) {
        ring_buffer->fill_size++;
    } else {
        ring_buffer->head_index = (ring_buffer->head_index + 1) % ring_buffer->buffer_size;
    }

    printf("Put char complete\n");
}

/* Get character from ring buffer */
uint8_t ring_buffer_char_get(ring_buffer_char_t* ring_buffer) {
    uint8_t value = ring_buffer->buffer[ring_buffer->head_index];
    ring_buffer->head_index = (ring_buffer->head_index + 1) % ring_buffer->buffer_size;
    ring_buffer->fill_size--;
    return value;
}

/* Check if ring buffer is empty */
bool ring_buffer_char_empty(ring_buffer_char_t* ring_buffer) {
    return ring_buffer->fill_size == 0;
}

/* Check if ring buffer is full */
bool ring_buffer_char_full(ring_buffer_char_t* ring_buffer) {
    return ring_buffer->fill_size == ring_buffer->buffer_size;
}