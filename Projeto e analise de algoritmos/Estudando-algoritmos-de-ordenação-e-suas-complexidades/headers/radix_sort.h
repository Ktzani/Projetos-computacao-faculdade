#ifndef RADIX_SORT_H
#define RADIX_SORT_H

#include "./utils.h"

void radix_sort(bigNum *numbers, bigNum tam);
void counting_sort(bigNum *numbers, bigNum tam, bigNum place);

bigNum get_max(bigNum *numbers, bigNum tam);

#endif // RADIX_SORT_H