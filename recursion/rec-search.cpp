/**
 * demonstrates how much slower a linear search is, compared
 * to a binary one in two separate recursive functions
 * 
 * EAS
 */

#include <iostream>
#include <ctime>
using namespace std;

#define SIZE 100000

bool bin_search (int needle, int arr[], int min, int max)
{
	if (max >= min)
	{
		int midpt = min + ((max - min) / 2);
		if (needle > arr[midpt])
			return bin_search(needle, arr, midpt+1, max);
		else if (needle < arr[midpt])
			return bin_search(needle, arr, min, midpt-1);
		else // needle == arr[midpt]
			return true;
	}
	else
	{
		return false;
	}
}

bool lin_search (int needle, int arr[], int cur_idx, int max)
{
	if (needle == arr[cur_idx])
		return true;
	else if (cur_idx > max)
		return false;

	return lin_search(needle, arr, cur_idx + 1, max);	
}

int main(void)
{
	/* 
	 * trivial tests
	 *
	 *
	int sorted_arr[] = {3, 5, 50, 72};

	cout << bin_search(3, sorted_arr, 0, 3) << endl; // true
	cout << bin_search(5, sorted_arr, 0, 3) << endl; // true
	cout << bin_search(50, sorted_arr, 0, 3) << endl; // true
	cout << bin_search(72, sorted_arr, 0, 3) << endl; // true
	cout << bin_search(-1, sorted_arr, 0, 3) << endl; // false
	cout << bin_search(56, sorted_arr, 0, 3) << endl; // false
	cout << bin_search(556, sorted_arr, 0, 3) << endl; // false

	cout << endl << endl;

	cout << lin_search(3, sorted_arr, 0, 3) << endl; // true
	cout << lin_search(5, sorted_arr, 0, 3) << endl; // true
	cout << lin_search(50, sorted_arr, 0, 3) << endl; // true
	cout << lin_search(72, sorted_arr, 0, 3) << endl; // true
	cout << lin_search(-1, sorted_arr, 0, 3) << endl; // false
	cout << lin_search(56, sorted_arr, 0, 3) << endl; // false
	cout << lin_search(556, sorted_arr, 0, 3) << endl; // false

	cout << endl << endl;

	*/

	int sorted_arr_2[SIZE];
	for (int i = 0; i < SIZE; ++i)
		sorted_arr_2[i] = (2 * i);

	clock_t begin = clock();

	cout << bin_search(185000, sorted_arr_2, 0, SIZE) << endl; // true
	cout << bin_search(68000, sorted_arr_2, 0, SIZE) << endl; // true
	cout << bin_search(198998, sorted_arr_2, 0, SIZE) << endl; // true
	cout << bin_search(190000, sorted_arr_2, 0, SIZE) << endl; // true
	cout << bin_search(-1, sorted_arr_2, 0, SIZE) << endl; // false
	cout << bin_search(557, sorted_arr_2, 0, SIZE) << endl; // false
	cout << bin_search(999999, sorted_arr_2, 0, SIZE) << endl; // false

	clock_t end = clock();

	double elapsed_secs = (double)(end - begin) / CLOCKS_PER_SEC;
	cout << endl << endl << "Binary took... " << elapsed_secs << " seconds"
		<< endl << endl;

	begin = clock();
	
	cout << lin_search(185000, sorted_arr_2, 0, SIZE) << endl; // true
	cout << lin_search(68000, sorted_arr_2, 0, SIZE) << endl; // true
	cout << lin_search(198998, sorted_arr_2, 0, SIZE) << endl; // true
	cout << lin_search(190000, sorted_arr_2, 0, SIZE) << endl; // true
	cout << lin_search(-1, sorted_arr_2, 0, SIZE) << endl; // false
	cout << lin_search(557, sorted_arr_2, 0, SIZE) << endl; // false
	cout << lin_search(999999, sorted_arr_2, 0, SIZE) << endl; // false

	end = clock();

	elapsed_secs = (double)(end - begin) / CLOCKS_PER_SEC;
	cout << endl << endl << "Linear took... " << elapsed_secs << " seconds"
		<< endl << endl;
}