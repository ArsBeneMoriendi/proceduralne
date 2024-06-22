#include "header.h"

int main()
{
	int input;
	printf("Input the array size: ");
	scanf_s("%d", &input);

	Array* new_array = create_array(input);

	srand((unsigned int)time(NULL));
	float lower, upper;
	printf("\n\nLower draw limit: ");
	scanf_s("%f", &lower);
	printf("Upper draw limit: ");
	scanf_s("%f", &upper);
	random_fill(new_array, lower, upper);

	bubble_sort(new_array);

	struct_to_function_1(sum, new_array);
	struct_to_function_2(min, new_array, upper);
	struct_to_function_2(max, new_array, lower);

	free_array(new_array);

	return 0;
}
