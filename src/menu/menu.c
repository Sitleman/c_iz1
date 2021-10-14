#include "stdio.h"
#include "string.h"

#include "menu.h"
#include "input.h"
#include "automobile.h"


void menu(){
    const char *add = "add";
    const char *find = "find";
    const char *show = "show";

    storage* automobile_storage = storage_constructor();
    char cmd[MAX_WORD_SIZE];

    while (printf("\nInput command (help): "), input_string(cmd)){
        if (!strcmp(cmd, add)){
            automobile car;
            if (input_automobile(&car)){
                add_automobile(automobile_storage, &car);
                printf("ОК");
            } else {
                printf("Automobile wasn't added");
            }
            continue;
        }
        if (!strcmp(cmd, find)){
            printf("2");
            continue;
        }
        if (!strcmp(cmd, show)){
            show_automobile(automobile_storage);
            //printf("5");
            continue;
        }
    }
}