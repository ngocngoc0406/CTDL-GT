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

