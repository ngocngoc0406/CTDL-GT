#include<bits/stdc++.h>
using namespace std;
//Queue
typedef struct Queue *queue_pointer;
struct Queue
{
    int item;
    queue_pointer link;
};
struct pointer
{
    Queue *front;
    Queue *rear;
};
void addQ(pointer *p, int item)
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
int DeleteQ(pointer *p){
    queue_pointer temp =(*p).front;
    int item;
    // if(*front ==NULL&& *rear==NULL){
    //     cout<<"The Queue is Empty";
    // }

    item = temp->item;
    // cout<<item;
    (*p).front = temp->link;
    delete(temp);
    return item;

}
void Display(pointer p)
{

    queue_pointer temp = p.front;
    while (temp != p.rear)
    {
        cout << (temp)->item << " ";
        (temp) = (temp)->link;
    }
    cout << (temp)->item << " ";
    cout<<endl;
}
bool ISEmpty(pointer p){
    return p.front == NULL;
}
//stack
typedef struct stack1 *stack_pointer;

struct stack1
{
    int item;
    stack_pointer link;
};

void push(stack_pointer *top, int item)
{
    stack_pointer temp = new stack1;
    temp->item = item;
    temp->link = *top;
    *top = temp;
}
int pop(stack_pointer *top)
{
    stack_pointer temp = *top;
    int item;
    item = temp->item;
    *top = temp->link;
    delete (temp);
    return item;
}

//Data Graph
bool DanhDau[100][100];

int n, m;

void BFS(int u, int v){
    bool DD[100];
    int H[100];
    for(int i=1; i<=n; i++){
        DD[i]=true;
        H[i]=-1;
    }
    pointer p;
    p.front = NULL;
    p.rear = NULL;
    addQ(&p, u);
    DD[u]=false;
    while(ISEmpty(p)==false){
        int k = DeleteQ(&p);
        // cout << " -- " <<k << endl;
        for(int i=1; i<=n; i++){
            if(DanhDau[k][i]==true&&DD[i]==true){
                addQ(&p,i);
                DD[i]=false;
                H[i]=k;
            }
        }
    }

    cout<< v<<" ";
    while(v!=u){
        v = H[v];
        cout<<v<<" ";
    }
}
// 
void DFS(int u, int v){
    bool DD[100];
    int H[100];
    for(int i=1; i<=n; i++){
        DD[i]=true;
        H[i]=-1;
    }
    stack_pointer top = NULL;
    push(&top,u);
    
    DD[u]=false;
    while(top!=NULL){
        int k = pop(&top);
        // cout << " -- " <<k << endl;
        for(int i=1; i<=n; i++){
            if(DanhDau[k][i]==true&&DD[i]==true){
                push(&top,i );
                DD[i]=false;
                H[i]=k;
            }
        }
    }

    cout<< v<<" ";
    while(v!=u){
        v = H[v];
        cout<<v<<" ";
    }
}

int main(){
    cin>>n>>m;
    for(int i=1; i<=n; i++){
        for(int j = 1; j<= n; j++){
            DanhDau[i][j]=false;
        }
    }
    for(int i = 1; i<= m; i++){
        int a,b; 
        cin>>a>>b ;
        DanhDau[a][b]=true;
        DanhDau[b][a]=true;
    }
    BFS(4,5);
    cout<<endl;
    DFS(4, 5);

}
