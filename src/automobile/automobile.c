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

char add_automobile(storage* automobile_storage, automobile* car){
    automobile* new_car = malloc(sizeof(automobile));
    strcpy(new_car->model, car->model);

    automobile_storage->data = (automobile*) realloc(automobile_storage->data, sizeof(automobile*) * (automobile_storage->size + 1));
    automobile_storage->data[automobile_storage->size] = new_car;
    automobile_storage->size++;
}

void show_automobile(storage* automobile_storage){
    printf("0nq");
    for (int i = 0; i < automobile_storage->size; i++){
        printf("%s %s\n", automobile_storage->data[i]->model, automobile_storage->data[i]->engine_power);
    }
}