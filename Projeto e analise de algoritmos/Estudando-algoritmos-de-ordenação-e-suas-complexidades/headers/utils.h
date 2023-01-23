#ifndef UTILS_H
#define UTILS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

typedef unsigned long long bigNum;

bigNum *crate_new_array_with_malloc(bigNum *numbers, bigNum tam);
bigNum *deallocates_array(bigNum *numbers);
bigNum *create_ordered_numbers_array(bigNum *numbers, bigNum tam);
bigNum *random_shuffle_numbers_array(bigNum *numbers, bigNum tam);
void create_test_instances_files(bigNum tam);
void print_array(bigNum arr[], bigNum n);
void swap(bigNum *a, bigNum *b);

void write_numbers_array_to_txt_file(bigNum *numbers, bigNum tam, bigNum numArq);
void read_numbers_array_from_txt_file(bigNum *numbers, bigNum tam, bigNum numArq);
void create_random_ordered_file(bigNum tam, bigNum numArq);

#endif // UTILS_H