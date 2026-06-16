#include "ring_buffer.h"
#include <stdio.h>
/*RBC constructor */
void ring_buffer_char_init(ring_buffer_char_t* ring_buffer, void* buffer, uint16_t buffer_size){
    ring_buffer->tail_index = 0;
    ring_buffer->head_index = 0;
    ring_buffer->fill_size =0;

    ring_buffer->buffer_size=buffer_size;
    ring_buffer->buffer=buffer;
}
// Put char to RBC
void ring_buffer_char_put(ring_buffer_char_t* ring_buffer, uint8_t c){
    uint16_t next_tail_index;
    uint16_t next_head_index;
    ring_buffer->buffer[ring_buffer->tail_index]=c;
    next_tail_index=(ring_buffer->tail_index+1)%ring_buffer->buffer_size;
    ring_buffer->tail_index=next_tail_index;
    if(ring_buffer->fill_size==ring_buffer->buffer_size){
        next_head_index=(ring_buffer->head_index+1)%ring_buffer->buffer_size;
        ring_buffer->head_index=next_head_index;
    }else{
        ring_buffer->fill_size++;
    }
    printf("Put char complete\n");
}
// Get char from RBC
uint8_t ring_buffer_char_get(ring_buffer_char_t* ring_buffer){
    uint16_t ret=0;
    uint16_t next_head_index;
    if(ring_buffer->fill_size){
        ret=ring_buffer->buffer[ring_buffer->head_index];
        next_head_index=(ring_buffer->head_index+1)%ring_buffer->buffer_size;
        ring_buffer->head_index=next_head_index;
        ring_buffer->fill_size--;
    }
    return ret;
}
// Check if RBC is empty
bool ring_buffer_char_empty(ring_buffer_char_t* ring_buffer){
    return ring_buffer->fill_size==0;
}
// Check if RBC is full
bool ring_buffer_char_full(ring_buffer_char_t* ring_buffer){
    return ring_buffer->fill_size==ring_buffer->buffer_size;
}