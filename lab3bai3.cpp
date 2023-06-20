#include <bits/stdc++.h>
using namespace std;
#define IS_EMPTY(ptr) (!(ptr));
#define IS_FULL(ptr) (!(ptr));

struct element
{
    int data;
};
typedef struct Queue *queue_pointer;
struct Queue
{
    element item;
    queue_pointer link;
};
struct pointer
{
    Queue *front;
    Queue *rear;
};

void addQ(pointer *p, element item)
{
    queue_pointer temp = new Queue;

    temp->item = item;
    temp->link = NULL;
    if ((*p).front != NULL)
    {
        ((*p).rear)->link = temp;
    }
    else
    {
        (*p).front = temp;
    }
    (*p).rear = temp;
}
// element DeleteQ(queue_pointer *front){
//     queue_pointer temp =*front;
//     element item;
//     // if(*front ==NULL&& *rear==NULL){
//     //     cout<<"The Queue is Empty";
//     // }

//     item = temp->item;
//     cout<<item.data;
//     *front = temp->link;
//     delete(temp);
//     return item;

// }
void Display(pointer p)
{

    queue_pointer temp = p.front;
    while (temp != p.rear)
    {
        cout << (temp)->item.data << " ";
        (temp) = (temp)->link;
    }
    cout << (temp)->item.data << " ";
    cout<<endl;
}
int solve(pointer p, int n)
{
    int count = 0;
    pointer temp;
    temp.front = NULL;
    temp.rear = NULL;
    int die = 1;

    while (count < n - 1)
    {
        queue_pointer temp1 = p.front;
        while (temp1 != NULL)
        {
            
            if (die == 1)
            {
                count++;
            }
            else
            {
                addQ(&temp, temp1->item);
            }
            die = 1 - die;
            (temp1) = (temp1)->link;
            
        }
        // cout << "N = " << count << endl;
        p = temp;
    }
    return p.front->item.data;
}
int main()
{
    pointer p;
    p.front = NULL;
    p.rear = NULL;
    element item;
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        item.data = i;
        addQ(&p, item);
    }
    Display(p);
    cout<<"Nguoi cuoi cung la ";
    cout<<solve(p,n);
}
