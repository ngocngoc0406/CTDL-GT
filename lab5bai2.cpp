#include<bits/stdc++.h>
using namespace std;
typedef struct Tree_node *pnode;
struct Tree_node{
    char data;
    pnode Left;
    pnode Right;
};

//infix ((8 - 5) * ((4 + 2) / 3))
pnode Leaf(char ch){
    pnode p = new Tree_node;
    p->Left = NULL;
    p->Right = NULL;
    p->data = ch;
    return p;
}
pnode Create_tree(){
    pnode a = Leaf('8');
    pnode b = Leaf('5');
    pnode c = Leaf('4');
    pnode d = Leaf('2');
    pnode e = Leaf('3');
    pnode f = Leaf('-');
    f->Left = a;
    f->Right = b;
    pnode g = Leaf('+');
    g->Left = c;
    g->Right = d;
    pnode h = Leaf('/');
    h->Left = g;
    h->Right = e;
    pnode root = Leaf('*');
    root->Left = f;
    root->Right = h;
    return root;

}

bool check(pnode p) {
    if (p->Left == NULL)
        return false;
    return true;
}
void inorder(pnode p){
    if(p!=NULL){
        if (check(p)){
            cout << "(";
            inorder(p->Left);
           
        }else
            inorder(p->Left);
        cout<<(p->data)<<"";
        if (check(p)){
           
            inorder(p->Right);
            cout << ")";
        }else
            inorder(p->Right);
    }
}
void preorder(pnode p){
    if(p!=NULL){
        cout<<(p->data)<<" ";
        preorder(p->Left);
        
        preorder(p->Right);
    }
}
void postorder(pnode p){
    if(p!=NULL){
        
        postorder(p->Left);
        postorder(p->Right);
        cout<<(p->data)<<" ";
    }
}
int main(){
    pnode p = Create_tree();
    inorder(p);
    cout<<endl;
    preorder(p);
    cout<<endl;
    postorder(p);
}


