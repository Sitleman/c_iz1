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

char input_automobile(automobile* car, char is_required){
    char str[MAX_WORD_SIZE];

    if (is_required) printf("\nAll fields are REQUIRED.");
    else printf("\nFields are NOT REQUIRED.");

    printf("\nInput model: ");
    if (!input_string(str) && is_required)
        return 0;
    strcpy(car->model, str);

    printf("\nInput speed: ");
    if (!input_string(str) && is_required)
        return 0;
    strcpy(car->speed, str);

    printf("\nInput engine power: ");
    if (!input_string(str) && is_required)
        return 0;
    strcpy(car->engine_power, str);

    printf("\nInput body shape: ");
    if (!input_string(str) && is_required)
        return 0;
    strcpy(car->body_shape, str);

    printf("\nInput fuel spend: ");
    if (!input_string(str) && is_required)
        return 0;
    strcpy(car->fuel_spend, str);

    return 1;
}