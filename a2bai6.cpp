#include <iostream>
#include <vector>

using namespace std;

int product(vector<int>& a, int left, int right) {
    if (left == right) {
        return a[left];
    }
    
    int mid = (left + right) / 2;
    
    int leftProduct = product(a, left, mid);
    int rightProduct = product(a, mid+1, right);
    
    return leftProduct * rightProduct;
}

int main() {
    vector<int> a(5);
    a[0]=1;
    a[1]=2;
    a[2]=3;
    a[3]=4;
    a[4]=5;
    int n = a.size();
    
    int p = product(a, 0, n-1);
    
    cout << "Product of array elements: " << p << endl;
    
    return 0;
}

