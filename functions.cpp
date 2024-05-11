#include"header.h"

Array* create_array(int size)
{
	Array* new_array = (Array*)malloc(sizeof(Array));
	new_array->dynamic_array = (float*)malloc(size * sizeof(float));
	new_array->size = size;

	printf("\nArray in struct created");

	return new_array;
}

void free_array(Array* old_array)
{
	free(old_array->dynamic_array);
	old_array->size = 0;

	printf("\n\nMemory is now free\n");
}

void random_fill(Array* new_array, float min, float max)
{
	for (int i = 0; i < new_array->size; i++) 
	{
		new_array->dynamic_array[i] = min + ((float)rand() / RAND_MAX) * (max - min);
	}

	printf("\nArray filled with random values from the given range:\n");

	for (int i = 0; i < new_array->size; i++)
	{
		printf("%.3f ", new_array->dynamic_array[i]);
	}
}

void bubble_sort(struct Array* new_array)
{
	for (int i = 0; i < new_array->size - 1; i++)
	{
		for (int j = 0; j < new_array->size - i - 1; j++)
		{
			if (new_array->dynamic_array[j] > new_array->dynamic_array[j + 1])
			{
				float temp = new_array->dynamic_array[j];
				new_array->dynamic_array[j] = new_array->dynamic_array[j + 1];
				new_array->dynamic_array[j + 1] = temp;
			}
		}
	}

	printf("\n\nArray sorted increasingly:\n");

	for (int i = 0; i < new_array->size; i++)
	{
		printf("%.3f ", new_array->dynamic_array[i]);
	}
}

float sum(struct Array* new_array)
{
	float sum = 0.0f;

	for (int i = 0; i < new_array->size; i++)
	{
		sum += new_array->dynamic_array[i];
	}

	printf("\n\nSum: %.3f", sum);

	return sum;
}

float min(struct Array* new_array, float max_from_given_range)
{
	float min = max_from_given_range;

	for (int i = 0; i < new_array->size; i++)
	{
		if (new_array->dynamic_array[i] < min)
		{
			min = new_array->dynamic_array[i];
		}
	}

	printf("\nMin: %.3f", min);

	return min;
}

float max(struct Array* new_array, float min_from_given_range)
{
	float max = min_from_given_range;

	for (int i = 0; i < new_array->size; i++)
	{
		if (new_array->dynamic_array[i] > max)
		{
			max = new_array->dynamic_array[i];
		}
	}

	printf("\nMax: %.3f", max);

	return max;
}

//min i max można oczywiście sczytać z tablicy po jej posortowaniu, jako pierwszy i ostatni element
//natomiast wedle polecenia funkcja ma znajdywać min i max, a nie sczytywać, więc funkcje te rozpisałam

void struct_to_function_1(float (*func)(Array*), Array* new_array)
{
	float result = func(new_array);
}

void struct_to_function_2(float (*func)(Array*, float), Array* new_array, float draw_limit)
{
	float result = func(new_array, draw_limit);
}
