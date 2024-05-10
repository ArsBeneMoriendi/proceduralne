#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct Array
{
	float* dynamic_array;
	int size;
};

Array* create_array(int size);
void free_array(Array* old_array);
void random_fill(Array* new_array, float min, float max);
void bubble_sort(struct Array* new_array);
float sum(struct Array* new_array);
float min(struct Array* new_array, float max_from_given_range);
float max(struct Array* new_array, float min_from_given_range);
void struct_to_function_1(float (*func)(Array*), Array* new_array);
void struct_to_function_2(float (*func)(Array*, float), Array* new_array, float draw_limit);
