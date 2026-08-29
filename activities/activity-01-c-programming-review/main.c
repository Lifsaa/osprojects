#include "array_list.h"
#include <stdio.h>
#include <stdlib.h>

#include <string.h>

int main(int argc, char **argv)
{
    if (argc !=3) {
        printf("Proper usage is: %s <count>  <beginning-/end\n", argv[0]);
        return 1;
    }
    char *endptr;
    long count = strtol(argv[1], &endptr, 10);

    if (endptr ==  argv[1] || *endptr != '\0' || count < 0) {
        fprintf(stderr, "Count has to be positive");
        return 1;
    }
    int remove_beg = strcmp(argv[2], "beginning") == 0;
    int remove_end = strcmp(argv[2], "end") == 0;

    if (!remove_beg && !remove_end) {
        fprintf(stderr, "Removal must be either at the beginnign or at the end");
        return 1;
    }

    ArrayList* list = array_list_new(1);

    if (list == NULL) {
        return 1;
    }

    for (long value = 0; value < count; value++) {
        if (!array_list_add_to_end(list,value)) {
            array_list_free(list);
            return 1;
        }
    }

    while (list->size) {
        size_t index = remove_beg ? 0 : list->size -1;
    

        if (!array_list_remove(list, index)) {
            array_list_free(list);
            return 1;
        }
    }
    array_list_free(list);
    return 0;

}