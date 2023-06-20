#include <iostream>
#include <queue>
using namespace std;

int josephus(int n, int k)
{
    queue<int> q;
    for (int i = 1; i <= n; i++)
        q.push(i);

    while (q.size() > 1)
    {
        for (int i = 0; i < k-1; i++)
        {
            q.push(q.front());
            q.pop();
        }
        q.pop();
    }
    return q.front();
}

int main()
{
    int n, k;
    cout << "Enter the number of people in the circle: ";
    cin >> n;
    cout << "Enter the value of k: ";
    cin >> k;
    int winner = josephus(n, k);
    cout << "The winner is: " << winner << endl;
    return 0;
}

