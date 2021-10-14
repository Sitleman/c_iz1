#include <gtest/gtest.h>

extern "C"{
#include "input.h"
#include "automobile.h"
#include "stdlib.h"
}

TEST(AUTOMOBILE_STORAGE, CREATION){
    storage* exp_storage = reinterpret_cast<storage *>(malloc(sizeof(storage)));
    EXPECT_TRUE(exp_storage != NULL);
    exp_storage->size = 0;
    exp_storage->data = NULL;

    storage* got_storage = storage_constructor();
    EXPECT_TRUE(got_storage != NULL);

    EXPECT_EQ(exp_storage->size, got_storage->size);
    EXPECT_EQ(exp_storage->data, got_storage->data);

    free(exp_storage);
    free(got_storage);
}

TEST(AUTOMOBILE_STORAGE, ADDING_AUTO){
    storage* exp_storage = storage_constructor();
    storage* got_storage = storage_constructor();

    automobile car = {"audi", "130", "255", "18", "sedan"};

    exp_storage->data = (automobile**) (malloc(sizeof(automobile *) * 1));
    exp_storage->data[0] = (automobile*) malloc(sizeof(automobile));
    strcpy(exp_storage->data[0]->model, car.model);
    strcpy(exp_storage->data[0]->speed, car.speed);
    strcpy(exp_storage->data[0]->engine_power, car.engine_power);
    strcpy(exp_storage->data[0]->fuel_spend, car.fuel_spend);
    strcpy(exp_storage->data[0]->body_shape, car.body_shape);

    add_automobile(got_storage, &car);

    EXPECT_TRUE(!strcmp(exp_storage->data[0]->model, got_storage->data[0]->model));
    EXPECT_TRUE(!strcmp(exp_storage->data[0]->speed, got_storage->data[0]->speed));
    EXPECT_TRUE(!strcmp(exp_storage->data[0]->engine_power, got_storage->data[0]->engine_power));
    EXPECT_TRUE(!strcmp(exp_storage->data[0]->fuel_spend, got_storage->data[0]->fuel_spend));
    EXPECT_TRUE(!strcmp(exp_storage->data[0]->body_shape, got_storage->data[0]->body_shape));

    free(exp_storage->data);
    free(exp_storage);
    free(got_storage->data);
    free(got_storage);
}

TEST(AUTOMOBILE_STORAGE, DESTRUCTOR){
    storage* exp_storage = reinterpret_cast<storage *>(malloc(sizeof(storage)));
    EXPECT_TRUE(exp_storage != NULL);
    exp_storage->size = 0;
    exp_storage->data = NULL;

    storage* got_storage = storage_constructor();
    EXPECT_TRUE(got_storage != NULL);

    storage_destructor(&exp_storage);
    storage_destructor(&got_storage);

    EXPECT_TRUE(got_storage == exp_storage);
    EXPECT_TRUE(got_storage == nullptr);
}