#include "dynamic-array.h"

void grow_array (Arr *array)
{
	int newsize = array->size * 1.5;
	Friend *tmp = new Friend[ newsize ];

	for (int i = 0; i < array->elements; ++i)
		tmp[ i ] = array->p_friends[ i ];

	delete [] array->p_friends;
	array->p_friends = tmp;
}
