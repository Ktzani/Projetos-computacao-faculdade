#include "../headers/selection_sort.h"

void selection_sort(bigNum *numbers, bigNum tam)
{
  bigNum i, j, min; //O(1)
  for (i = 0; i < (tam - 1); i++)  //(n-1) * O(n) = O(n² - n) = O(n²)
  {
    min = i;
    for (j = (i + 1); j < tam; j++) //n * O(1) = O(n)
    {
      	if (numbers[j] < numbers[min]) //O(1)
        	min = j; //O(1)
    }
    if (i != min) //O(1)
    {
      	swap(&numbers[i], &numbers[min]); //O(1)
    }
  }
}