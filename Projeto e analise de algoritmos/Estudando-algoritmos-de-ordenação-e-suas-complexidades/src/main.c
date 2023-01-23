#include "../headers/selection_sort.h"
#include "../headers/merge_sort.h"
#include "../headers/radix_sort.h"

int main(int argc, char *argv[])
{
  srand(13);
  clock_t start_t, end_t;
  double total_t;

  if (argc != 3)
  {
    printf("Expected parameter to function.");
    exit(1);
  }

  bigNum tam = atoi(argv[1]);
  int num = atoi(argv[2]);

  create_test_instances_files(tam);

  bigNum *numbers = NULL;
  numbers = crate_new_array_with_malloc(numbers, tam);

  // start_t = clock();
  // printf("Início do programa de ordenação, start_t = %ld\n", start_t);

  // read_numbers_array_from_txt_file(numbers, tam, num);

  // radix_sort(numbers, tam);

  // end_t = clock();
  // printf("\nFim do programa de ordenação, end_t = %ld\n", end_t);

  // total_t = (double)(end_t - start_t) / CLOCKS_PER_SEC;
  // printf("Tempo total da CPU: %f\n", total_t);

  // printf("AH NÃOOO \n");

  // numbers = create_ordered_numbers_array(numbers, tam);

  // numbers = random_shuffle_numbers_array(numbers, tam);

  // merge_sort(numbers, tam);

  // write_numbers_array_to_txt_file(numbers, tam);

  return 0;
}