#include "array_list.h"
#include <stdio.h>

int main(int argc, char **argv)
{
    if (argc !=3) {
        printf("Proper usage is: %s <count>  <beginning-/end\n", argv[0]);
        return 1;
    }
    ArrayList *list = array_list_new(1);

    if (list == NULL)
        return 1;
    
    long count = strtol(argv[1], NULL, 10);
    
    if(count < 0) {
        fprint(stderr, "Count must be nonnegative\n");
        return 1;
    }

    printf("count: %ld\n", count);
    printf("removal node: %s\n", argv[2]);
    char* mode = argv[2];
    if (strcmp(mode,"beginning") == 0 &&
        strcmp(mode, "end") != 0) {
            return 1;
    }

    ArrayList* list = array_list_new(1);

    if (list == NULL){
        return 1;
    }
    
    for(long i = 0; i < count; i++) {
        array_list_add_to_end(list,i);
    }





    printf("size=%zu capacity=%zu values=%ld,%ld\n",
           list->size,
           list->capacity,
           list->data[0],
           list->data[1]);

    array_list_free(list);

    return 0;
}