#ifndef DYNAMIC_ARR_H_EAS
#define DYNAMIC_ARR_H_EAS
#include <string>

/**
 * provides an interface for a dynamic (growable) array of
 * "Friend" types
 */

/*
 * a "friend" with a name and days_ago (days since spoken to)
 */
struct Friend
{
	std::string name;
	unsigned days_ago;
};

struct Arr
{
	Friend* p_friends;
	int elements;
	int size;
};

/**
 * grows the array p_array of size size, where it is assumed the size
 * is equal to the number of elements in the array
 */
void grow_array (Arr *array);

#endif /* DYNAMIC_ARR_H_EAS */
