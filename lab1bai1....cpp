#include <iostream>
#include <cstdlib> // cho ham rand() va srand()
#include <ctime> // cho ham time()
using namespace std;

// Nhap du lieu cho mang
void nhapMang(int* p, int n);
// In ra mang
void inMang(int* p, int n);
// Loai bo cac so le khoi mang
void xoaSoLe(int* &p, int &n);

int main()
{
    int n;
    cout << "Nhap kich thuoc mang: ";
    cin >> n;

    int* A = new int[n]; // cap phat dong bo nho
    nhapMang(A, n);
    cout << "Mang vua nhap la: ";
    inMang(A, n);

    xoaSoLe(A, n);
    cout << "Mang sau khi xoa cac so le la: ";
    inMang(A, n);

    delete[] A; // giai phong bo nho
    return 0;
}

void nhapMang(int* p, int n)
{
    srand(time(0)); // khoi tao bo sinh so ngau nhien voi thoi gian hien tai
    for (int i = 0; i < n; i++)
    {
        *(p + i) = rand() ; 
    }
}

void inMang(int* p, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << *(p + i) << " ";
    }
    cout << endl;
}

void xoaSoLe(int* &p, int &n)
{
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (*(p + i) % 2 == 0) // kiem tra xem so do co phai la so chan khong
        {
            *(p + count) = *(p + i); // sao chep so chan len dau mang
            count++;
        }
    }
    n = count; // cap nhat kich thuoc cua mang
    p = (int*) realloc(p, n * sizeof(int)); // thay doi kich thuoc cua mang
}

