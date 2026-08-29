#include "array_list.h"
#include <stdlib.h>
#include <stdio.h>


ArrayList* array_list_new(size_t capacity) {
    if (capacity == 0) {
        return NULL;
    }
    ArrayList* list = malloc(sizeof (*list));

    if(list == NULL) {
        return NULL;
    }
    
    list->data = malloc(capacity * sizeof(*list->data));

    if (list->data == NULL) {
        free(list);
        return NULL;
    }

    list->capacity = capacity;
    list->size = 0;
    printf("size:%zu capacity:%zu\n", list->size, list->capacity);    
    return list;
}

int array_list_add_to_end(ArrayList* list, long value) {
    if (list == NULL) {
        return 0;
    }
    if (list->size == list->capacity) {
        size_t new_capacity = list->capacity * 4;

        long *new_data = realloc(list->data, new_capacity * sizeof (*new_data));

        if (new_data == NULL ){
            return 0;
        }
        
        list->data = new_data;
        list->capacity = new_capacity;
    };

    list->data[list->size] = value;
    list->size++;
    return 1;
    
}

int array_list_remove(ArrayList* list, size_t index) {
    if (list == NULL  || index >= list->size) {
        return 0;
    }

    for (size_t i = index; i + 1 < list->size; i++) {
        list->data[i] = list->data[i+1];

    }
    list->size--;

    if(list->capacity > 1 && list->size <= list->capacity /4) {
            size_t new_capacity = list->capacity /2;
            long *new_data = realloc(list->data, new_capacity * sizeof (*new_data));
        
            if (new_data != NULL) {
                list->data = new_data;
                list->capacity = new_capacity;
        }
        }
    return 1;
}

void array_list_free(ArrayList* list) {
    if (list == NULL) {
        return;      
    }
        free(list->data);
        free(list);
}


