all: main

main: ./bin/obj/main.o ./bin/obj/utils.o ./bin/obj/merge_sort.o ./bin/obj/selection_sort.o ./bin/obj/radix_sort.o
	gcc -o ./bin/main $^

./bin/obj/%.o: ./src/%.c
	gcc -o $@ -c $^ -W -Wall



