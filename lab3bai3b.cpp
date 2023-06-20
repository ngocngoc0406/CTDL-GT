#include <bits/stdc++.h>
using namespace std;
int binarySearch(int arr[], int n, int x){
    int L=0;
    int R=n-1;
    int M=(L+R)/2;
    while(L<=R){
        M=(L+R)/2;
        if(x>arr[M]){
            L=M+1;
        }
        if(x<arr[M]){
            R=M-1;
        }
        if(x==arr[M]){
            return M;
        }
    }
    return -1;
}

int binarySearchLeft(int arr[], int n, int x){
    int L=0;
    int R=n-1;
    int M=(L+R)/2;
    while(L<R){
        M=(L+R)/2;
        if(x>arr[M]){
            L=M+1;
        }
        else{
            R=M;
        }
        
    }
    if(arr[R]==x){
        return R;
    }
    return -1;
}

int binarySearchRight(int arr[], int n, int x){
    int L=0;
    int R=n-1;
    int M=(L+R)/2;
    while(L<R){
        
        M=(L+R+1)/2;
        
        if(x>=arr[M]){
            L=M;
        }
        else{
            R=M-1;
        }
        
        
    }
    if(arr[R]==x){
        return R;
    }
    return -1;
}
#include <iostream>
using namespace std;

int main() {
    int n, x;
    cout << "Nhap so phan tu n: ";
    cin >> n;
    cout << "Nhap phan tu can tim x: ";
    cin >> x;

    int arr[n];
    cout << "Nhap cac phan tu cua mang: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // goi hàm tim kiem và in ra ket qua 
    int index = binarySearchRight(arr, n, x);
    if (index != -1) {
        cout << "Phan tu " << x << " xuat hien tai vi tri " << index << " trong mang." << endl;
    }
    else {
        cout << "Phan tu " << x << " khong xuat hien trong mang." << endl;
    }
    return 0;
}

