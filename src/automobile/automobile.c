#include "stdio.h"
#include "string.h"
#include "stdlib.h"

#include "automobile.h"


storage* storage_constructor(){
    storage* new_storage = malloc(sizeof(storage));
    new_storage->size = 0;
    new_storage->data = NULL;
    return new_storage;
}

void storage_destructor(storage** curr_storage){
    free((*curr_storage)->data);
    free(*curr_storage);
    *curr_storage = NULL;
}

char add_automobile(storage* automobile_storage, automobile* car){
    automobile* new_car = malloc(sizeof(automobile));
    strcpy(new_car->model, car->model);
    strcpy(new_car->engine_power, car->engine_power);
    strcpy(new_car->speed, car->speed);
    strcpy(new_car->fuel_spend, car->fuel_spend);
    strcpy(new_car->body_shape, car->body_shape);


    automobile_storage->data = realloc(automobile_storage->data, sizeof(automobile*) * (automobile_storage->size + 1));
    automobile_storage->data[automobile_storage->size] = new_car;
    automobile_storage->size++;
}

void output_automobile(automobile* car){
    printf("{%s;", car->model);
    printf(" %s (km/h);", car->speed);
    printf(" %s (hp);", car->engine_power);
    printf(" %s;", car->body_shape);
    printf(" %s (l/100km)}\n", car->fuel_spend);
}

void show_automobile(storage* automobile_storage){
    for (int i = 0; i < automobile_storage->size; i++){
        output_automobile(automobile_storage->data[i]);
    }
}

void find_automobile(storage* automobile_storage, automobile *car){
    for (int i = 0; i < automobile_storage->size; i++) {
        if (strcmp(automobile_storage->data[i]->model, car->model) && !(car->model[0] == '\0'))
            continue;
        if (strcmp(automobile_storage->data[i]->engine_power, car->engine_power) && !(car->engine_power[0] == '\0'))
            continue;
        if (strcmp(automobile_storage->data[i]->body_shape, car->body_shape) && !(car->body_shape[0] == '\0'))
            continue;
        if (strcmp(automobile_storage->data[i]->fuel_spend, car->fuel_spend) && !(car->fuel_spend[0] == '\0'))
            continue;
        if (strcmp(automobile_storage->data[i]->speed, car->speed) && !(car->speed[0] == '\0'))
            continue;
        output_automobile(automobile_storage->data[i]);
    }
}

