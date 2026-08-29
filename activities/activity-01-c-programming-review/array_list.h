#ifndef ARRAY_LIST_H
#define ARRAY_LIST_H

#include <stddef.h>



typedef struct {
    size_t capacity;
    size_t size;
    long* data;

} ArrayList;

ArrayList* array_list_new(size_t capacity);
int array_list_add_to_end(ArrayList* list, long value);
int array_list_remove(ArrayList* list, size_t index);
void array_list_free(ArrayList* list);

#endif