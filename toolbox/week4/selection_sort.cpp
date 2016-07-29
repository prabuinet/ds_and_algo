#include <iostream>
#include <vector>

using namespace std;

void selection_sort(int arr[], int n) {
    for(int i = 0; i < n; i++) {

	int min_index = i;
	
	for(int j = i + 1; j < n; j++)
	    if(arr[j] < arr[min_index])
		min_index = j;

	if(min_index != i) {
	    int temp = arr[i];
	    arr[i] = arr[min_index];
	    arr[min_index] = temp;
	}
    }
}

int main() {
    int arr[] = { 1, 5, 10, -2, 3, 0 };
    
    selection_sort(arr, 6);

    for(int i = 0; i < 6; i++) 
	cout << arr[i] << ' ';
    
    cout << endl;
}
