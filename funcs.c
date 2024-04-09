// Malloc function allocates size bytes of memory and returns a pointer
// to the allocated memory.
// DEFINITIONS:
//      * Program break: (Unix/Linux) the end of the contiguous memory area
//                       allocated for the process's data segment which
//                       typically includes the heap
//      * `brk`: function call that sets the end of the data segment to
//               a specified value, resizing the heap
//      * `sbrk`: function call increments the program break by a specified
//                amount also increasing/decreasing the size of the heap
void *malloc(size_t);






void* malloc(size_t size)
{
    void* block;
    block = sbrk(size);

    // (void*) -1 is a void pointer with the value -1 which is
    // distinct from `NULL` (typically (void*) 0).
    // -1 indicates that there is an error since a memory address 
    // of -1 cannot exist
    if (block == (void*) - 1)
        return NULL;

    return block;
}
