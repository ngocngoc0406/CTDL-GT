#include <iostream>
using namespace std;

int Min(int a[], int n)
{
    int i, min;
    min = a[0];
    for(i = 1; i < n; i++)
        if (a[i] < min)
            min = a[i];
    return min;
}

int main()
{
    int arr[] = {5, 3, 4, 1, 2};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout << "Minimum element of array: " << Min(arr, n);
    return 0;
}
