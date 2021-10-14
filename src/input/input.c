#include "stdio.h"
#include "string.h"

#include "automobile.h"
#include "input.h"

char input_string(char* str){
    char c;
    int i = 0;
    c = getchar();
    while (c != '\n' && c != EOF && i < MAX_WORD_SIZE - 1){
        str[i] = c;
        c = getchar();
        i++;
    }
    str[i] = '\0';
    return i;
}

char input_automobile(automobile* car){
    char str[MAX_WORD_SIZE];
    printf("Adding new car... ");

    printf("\n\tInput model: ");
    if (!input_string(str))
        return 0;
    strcpy(car->model, str);

    printf("\n\tInput engine_power: ");
    if (!input_string(str))
        return 0;
    strcpy(car->engine_power, str);
}