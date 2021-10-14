#pragma once

#define MAX_WORD_SIZE 50

typedef struct{
    char model[MAX_WORD_SIZE];
    char engine_power[MAX_WORD_SIZE];
    char speed[MAX_WORD_SIZE];
    char fuel_spend[MAX_WORD_SIZE];
    char body_shape[MAX_WORD_SIZE];
} automobile;

typedef struct{
    int size;
    automobile **data;
} storage;

storage* storage_constructor();

char add_automobile(storage* automobile_storage, automobile* car);
void show_automobile(storage* automobile_storage);
void find_automobile(storage* automobile_storage, automobile* car);

void storage_destructor(storage* storage);
