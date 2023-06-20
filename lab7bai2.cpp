#include <bits/stdc++.h>
using namespace std;
int Heap[100];
int n = 0;
void Insert(int x)
{
    Heap[++n] = x;
    int temp = n;
    while (temp != 1 && Heap[temp] > Heap[temp / 2])
    {
        swap(Heap[temp], Heap[temp / 2]);
        temp = temp / 2;
    }
}
int Search(int x)
{
    for (int i = 1; i <= n; i++)
    {
        if (Heap[i] == x)
        {
            return i;
        }
    }
    return -1;
}
void Delete(int x)
{
    int temp;
    int L, R;
    temp = Search(x);
    Heap[temp] = Heap[n--];
    while (temp != 1 && Heap[temp] > Heap[temp / 2])
    {
        swap(Heap[temp], Heap[temp / 2]);
        temp = temp / 2;
    }
    L = 2 * temp;
    R = 2 * temp + 1;
    while (L <= n || R <= n)
    {
        if (L <= n && R <= n)
        {
            if (Heap[temp] < Heap[L] && Heap[temp] < Heap[R])
            {
                if (Heap[L] < Heap[R])
                {
                    swap(Heap[temp], Heap[R]);
                    temp = R;
                }
                else
                {
                    swap(Heap[temp], Heap[L]);
                    temp = L;
                }
            }
            else if (Heap[temp] < Heap[R])
            {
                swap(Heap[temp], Heap[R]);
                temp = R;
            }
            else if (Heap[temp] < Heap[L])
            {
                swap(Heap[temp], Heap[L]);
                temp = L;
            }
            else{
                break;
            }
        } else if (L <= n){
            if (Heap[temp] < Heap[L])
            {
                swap(Heap[temp], Heap[L]);
                temp = L;
            }else{
                break;
            }
        }
        L = 2 * temp;
        R = 2 * temp + 1;
    }
}

void Display()
{
    for (int i = 1; i <= n; i++)
    {
        cout << Heap[i] << " ";
    }
}
void Sort(){
    sort(Heap+1, Heap+n+1,greater<int>());
}

int main()
{
    Insert(45);
    Insert(36);
    Insert(54);
    Insert(27);
    Insert(63);
    Insert(72);
    Insert(61);
    Insert(18);
    Delete(45);
    Delete(72);
    Sort();
    Display();
}
