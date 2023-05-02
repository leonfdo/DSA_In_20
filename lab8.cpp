#include <iostream>
using namespace std;

// function to heapify the tree
void heapify(int arr[], int n, int root)
{
	int max = root;  //assuming that the max value is root
	int left_child = 2 * root + 1;  //left child position
	int right_child = 2 * root + 2; //right child position

	if (arr[left_child] > arr[max] && left_child < n  ) {
		max = left_child;   // if left_child value is greater than max 
	}						//and int in the given range assign max as left child value

	if (arr[right_child] > arr[max] && right_child < n ) {
		max = right_child;    // if right_child value is greater than max 
						     //and int in the given range assign max as right child value
	}

	if (max != root) {
		int temp = arr[root];
		arr[root] = arr[max];
		arr[max] = temp;       //swapping the root and the max if they are different

		heapify(arr, n, max);   //again recursively implement the fuction to max position
	}

}

// implementing heap sort
void heapSort(int arr[], int n)
{
	for (int i = n / 2 - 1; i >= 0; i--) {
		heapify(arr, n, i);  //heapifying the array to obtain a max heap
	}

	for (int j = n - 1; j > 0; j--) {
		int temp = arr[0];
		arr[0] = arr[j];
		arr[j] = temp;   //swapping the first elemet with the last element which is not sorted

		heapify(arr, j, 0);  //then heapify the array to obtain max heap again

	}


}

/* print contents of array */
void displayArray(int arr[], int n)
{
	for (int i = 0; i < n; ++i)
		cout << arr[i] << " ";
	cout << "\n";
}

// main program
int main()
{
	int heap_arr[] = { 15,9,23,2,34,10};
	int n = sizeof(heap_arr) / sizeof(heap_arr[0]);
	cout << "Input array" << endl;
	displayArray(heap_arr, n);

	heapSort(heap_arr, n);

	cout << "Sorted array" << endl;
	displayArray(heap_arr, n);
}