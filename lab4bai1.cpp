#include <bits/stdc++.h>
using namespace std;
#define max 100000
int arr[max];

int LinearSeach(int x, int n)
{
    for (int i = 0; i < n; i++)
    {
        if (x == *(arr + i))
        {
            return i;
        }
    }
    return -1;
}
int binarySearch(int n, int x)
{
    int L = 0;
    int R = n - 1;
    int M = (L + R) / 2;
    while (L <= R)
    {
        M = (L + R) / 2;
        if (x > *(arr + M))
        {
            L = M + 1;
        }
        if (x < *(arr + M))
        {
            R = M - 1;
        }
        if (x == *(arr + M))
        {
            return M;
        }
    }
    return -1;
}
void Display(int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
void SelectSort(int n)
{
    int temp;
    for (int i = 0; i < n - 1; i++)
    {
        int min = i;
        int j;
        for (j = i + 1; j < n; j++)
        {
            if (arr[min] > arr[j])
            {
                min = j;
            }
        }
        temp = arr[min];
        arr[min] = arr[i];
        arr[i] = temp;
    }
}
void QuickSort(int L, int R)
{
    int k = (L + R) / 2;
    int i = L;
    int j = R;
    int temp;
    while (i <= j)
    {
        while (arr[i] < arr[k])
        {
            i++;
        }
        while (arr[j] > arr[k])
        {
            j--;
        }
        if (i <= j)
        {
            temp = arr[j];
            arr[j] = arr[i];
            arr[i] = temp;
            i++;
            j--;
        }
    }
    if (i < R)
    {
        QuickSort(i, R);
    }
    if (L < j)
    {
        QuickSort(L, j);
    }
}
void merge(int s1, int e1, int s2, int e2)
{
    int nB = e1 - s1 + 1;
    int nC = e2 - s2 + 1;
    int B[nB];
    int C[nC];
    for (int i = 0; i < nB; i++)
    {
        B[i] = arr[s1 + i];
    }
    for (int i = 0; i < nC; i++)
    {
        C[i] = arr[s2 + i];
    }
    int i = 0, j = 0;
    while (i < nB && j < nC)
    {
        if (B[i] < C[j])
        {
            arr[s1] = B[i];
            s1++;
            i++;
        }
        else
        {
            arr[s1] = C[j];
            s1++;
            j++;
        }
    }
    while (i < nB)
    {
        arr[s1] = B[i];
        s1++;
        i++;
    }
    while (j < nC)
    {
        arr[s1] = C[j];
        s1++;
        j++;
    }
}

void MergeSort(int L, int R)
{
    int i = L;
    int j = R;
    int temp;
    int k = (L + R) / 2;
    if (k - i > 0)
    {
        MergeSort(i, k);
    }
    if (j - k - 1 > 0)
    {
        MergeSort(k + 1, j);
    }
    merge(i, k, k + 1, j);
}

void InsertSort(int n)
{
    for (int i = 1; i < n; i++)
    {
        int k = arr[i];
        int index = i;
        while (index > 0&& k< arr[index - 1])
        {
            
            arr[index] = arr[index - 1];
            index--;
        }
        arr[index] = k;
    }
}

void BubbleSort(int n)
{
    int temp;
    for (int i = n - 1; i > 0; i--)
    {
        for (int j = 0; j < i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void writetxt(double timesort, string namesort)
{
    ofstream o;

    o.open("SortingTime.txt", ios::app);
    o << namesort << " ";
    o << timesort << endl;
    o.close();
}
void randomarr(int n)
{
    srand(time(NULL));
    for (int i = 0; i < n; i++)
    {
        int a = (rand() * rand()) % 10000 + 1;
        *(arr + i) = a;
    }
}
// int Random(int m, int n){
//     int a = (rand()*rand())%(n-m+1)+m;
//     return a;

// }

int main()
{
    clock_t start;
    clock_t end;
    double timesort;
    ofstream o;
    o.open("SortingTime.txt");
    o.close();
    srand(time(NULL));
    int n;
    int x;
    int choose;
    cout << "nhap so phan tu cua mang ";
    cin >> n;
    for (int i = 0; i < n; i++)
            {
                int a = (rand() * rand()) % 10000 + 1;
                *(arr + i) = a;
            }
    

    do
    {
        cout << "<---------- Menu---------->" << endl;
        cout << "1.Input and output data of the array" << endl;
        cout << "2.Sort by SelectSort" << endl;
        cout << "3.Sort by InsertSort" << endl;
        cout << "4.Sort by BubbleSort" << endl;
        cout << "5.Sort by QuickSort" << endl;
        cout << "6.Sort by MergeSort" << endl;
        cout << "7.Write execution time of the sorting algorithms to SortingTime.txt" << endl;
        cout << "8.Search x by linear search" << endl;
        cout << "9.Search x by binary search" << endl;
        cout << "Choose, please!" << endl;
        cin >> choose;
        switch (choose)
        {
        case 1:
            for (int i = 0; i < n; i++)
            {
                int a = (rand() * rand()) % 10000 + 1;
                *(arr + i) = a;
            }
            for (int i = 0; i < n; i++)
            {
                cout << *(arr + i) << " ";
            }
            cout << endl;

            break;
        case 2:
            SelectSort(n);
            Display(n);
            break;
        case 3:
            InsertSort(n);
            Display(n);
            break;
        case 4:
            BubbleSort(n);
            Display(n);
            break;
        case 5:
            QuickSort(0, n - 1);
            Display(n);
            break;
        case 6:
            MergeSort(0, n - 1);
            Display(n);
            break;
        case 7:
            start = clock();
            SelectSort(n);
            end = clock();
            timesort = (double)(end - start) / CLOCKS_PER_SEC;
            writetxt(timesort, "SelectSort");

            randomarr(n);
            start = clock();
            QuickSort(0, n - 1);
            end = clock();
            timesort = (double)(end - start) / CLOCKS_PER_SEC;
            writetxt(timesort, "QuickSort");

            randomarr(n);
            start = clock();
            MergeSort(0, n - 1);
            end = clock();
            timesort = (double)(end - start) / CLOCKS_PER_SEC;
            writetxt(timesort, "MergeSort");

            randomarr(n);
            start = clock();
            InsertSort(n);
            end = clock();
            timesort = (double)(end - start) / CLOCKS_PER_SEC;
            writetxt(timesort, "InsertSort");

            randomarr(n);
            start = clock();
            BubbleSort(n);
            end = clock();
            timesort = (double)(end - start) / CLOCKS_PER_SEC;
            writetxt(timesort, "BubbleSort");
            break;
        case 8:
            cout << "nhap so can tim ";
            cin >> x;
            cout<<LinearSeach(x,n)<<endl;

            break;
        case 9:
            cout << "nhap so can tim ";
            cin >> x;
            cout<<binarySearch(n,x);

            break;

        default:
            break;
        }

    } while (choose != 10);

    
  
}
