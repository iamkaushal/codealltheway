#include<stdio.h>
#include<stdlib.h>

// function to left rotate array
void rotate_left_array(int arr[], int size, int rotate_by)
{
	// declaring a temporary array to store the elements upto the index
	// to which array has to be rotated
	int temp[rotate_by];

	// assigning values to temp array
	for(int i = 0; i < rotate_by; ++i)
		temp[i] = arr[i];

	// rotating the elements in arr 
	for(int i = 0; i < size - rotate_by; ++i)
		arr[i] = arr[i + rotate_by];

	// assigning the last rotate_by elements in the arr to the value of temp
	for(int i = 0; i < rotate_by; ++i)
		arr[size - rotate_by + i] = temp[i];
}

// function to right rotate array
void rotate_right_array(int arr[], int size, int rotate_by)
{
	// declaring a temporary array to store the last rotate_by elements of arr
	int temp[rotate_by];

	// assigning values to temp array
	for(int i = 0; i < rotate_by; ++i)
		temp[i] = arr[size - rotate_by + i];

	// rotating the elements in arr 
	for(int i = size - 1 ; i >= rotate_by; --i)
		arr[i] = arr[i - rotate_by ];

	// assigning the last rotate_by elements in the arr to the value of temp
	for(int i = 0; i < rotate_by; ++i)
		arr[i] = temp[i];
}

// driver funtion starts here
int main()
{
	#ifndef LOCAL_TEST
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif

	// variable to store the size of array
	int n;
	scanf("%d", &n);

	// declaring array of size n
	int arr[n];

	//scanning array
	for(int i = 0; i < n; ++i)
		scanf("%d", &arr[i]);

	// variable to store the value to by m elements
	int m;
	scanf("%d", &m);

	// rotating array to left by m elements
	rotate_left_array(arr, n, m);

	// printing left rotated array
	for(int i = 0; i < n; ++i)
		printf("%d ", arr[i]);

	// printing new line
	printf("\n") ;

	// rotating array to right by m elements
	rotate_right_array(arr, n, m);

	// printing right rotated array 
	for(int i = 0; i < n; i++)
		printf("%d ", arr[i]);

	// printing new line
	printf("\n");

	return 0;
}