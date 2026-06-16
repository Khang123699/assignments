#include "ring_buffer.h"
#include <stdio.h>

int main() {
    ring_buffer_char_t rb;
    uint8_t buffer[3];
    ring_buffer_char_init(&rb, buffer, 3);
    //Test put function
    ring_buffer_char_put(&rb, 'A');
    ring_buffer_char_put(&rb, 'B');
    ring_buffer_char_put(&rb, 'C');
    //Test full function
    ring_buffer_char_full(&rb) ? printf("Buffer is full\n") : printf("Buffer is not full\n");
    //Test overwrite when 
    ring_buffer_char_put(&rb, 'D');
    //Test get function
    printf("%c\n", ring_buffer_char_get(&rb)); 
    printf("%c\n", ring_buffer_char_get(&rb)); 
    printf("%c\n", ring_buffer_char_get(&rb));
    //Test empty function
    ring_buffer_char_empty(&rb) ? printf("Buffer is empty\n") : printf("Buffer is not empty\n");

    printf("ALL TEST PASSED\n");
    return 0;
}