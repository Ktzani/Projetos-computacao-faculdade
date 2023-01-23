#include "../headers/radix_sort.h"

bigNum get_max(bigNum *numbers, bigNum tam)
{
  bigNum i;
  bigNum max = numbers[0];
  for (i = 1; i < tam; i++)
    if (numbers[i] > max)
      max = numbers[i];
  return max;
}

void counting_sort(bigNum *numbers, bigNum tam, bigNum place)
{
  bigNum i;
  long long int j;

  bigNum *output = NULL;
  output = crate_new_array_with_malloc(output, tam + 1);

  bigNum max = (numbers[0] / place) % 10;

  for (i = 1; i < tam; i++)
  {
    if (((numbers[i] / place) % 10) > max)
      max = numbers[i];
  }
  bigNum *count = NULL;
  count = crate_new_array_with_malloc(count, max + 1);

  for (i = 0; i < max; ++i)
    count[i] = 0;

  // Calculate count of elements
  for (i = 0; i < tam; i++)
    count[(numbers[i] / place) % 10]++;

  // Calculate cumulative count
  for (i = 1; i < 10; i++)
    count[i] += count[i - 1];

  // Place the elements in sorted order
  for (j = tam - 1; j >= 0; j--)
  {
    output[count[(numbers[j] / place) % 10] - 1] = numbers[j];
    count[(numbers[j] / place) % 10]--;
  }

  for (i = 0; i < tam; i++)
    numbers[i] = output[i];
}

// Main function to implement radix sort
void radix_sort(bigNum *numbers, bigNum tam)
{
  // Get maximum element
  bigNum max = get_max(numbers, tam);

  // Apply counting sort to sort elements based on place value.
  bigNum place;
  for (place = 1; max / place > 0; place *= 10)
    counting_sort(numbers, tam, place);
}