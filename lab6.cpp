#include <bits/stdc++.h>
using namespace std;
typedef struct Tree_node *Tnode;
struct Tree_node
{
    int data;
    Tnode Left;
    Tnode Right;
};
Tnode createNode(int value)
{
    Tnode temp;
    temp = new Tree_node;
    temp->Left = NULL;
    temp->Right = NULL;
    temp->data = value;
    return temp;
}
Tnode inserNode(Tnode root, int x)
{
    if (root)
    {
        if (root->data > x)
        {
            root->Left = inserNode(root->Left, x);
        }
        else
        {
            root->Right = inserNode(root->Right, x);
        }
    }
    else
        root = createNode(x);
    return root;
}
bool check(Tnode p)
{
    if (p->Left == NULL)
        return false;
    return true;
}
void inorder(Tnode p)
{
    if (p != NULL)
    {
        inorder(p->Left);
        cout << p->data << " ";
        inorder(p->Right);
    }
}
void preorder(Tnode p)
{
    if (p != NULL)
    {
        cout << (p->data) << " ";
        preorder(p->Left);

        preorder(p->Right);
    }
}
void postorder(Tnode p)
{
    if (p != NULL)
    {

        postorder(p->Left);
        postorder(p->Right);
        cout << (p->data) << " ";
    }
}
Tnode smallest(Tnode root)
{
    if (root != NULL)
    {
        if (root->Left == NULL)
        {
            return root;
        }
        else
        {
            return smallest(root->Left);
        }
    }
    else
        return NULL;
}
Tnode largest(Tnode root)
{
    if (root != NULL)
    {
        if (root->Right == NULL)
        {
            return root;
        }
        else
        {
            return largest(root->Right);
        }
    }
    else
        return NULL;
}
Tnode Search(Tnode root, int value)
{
    if (root != NULL)
    {
        if (root->data == value)
            return root;
        else if (root->data < value)
            return Search(root->Right, value);
        else
            return Search(root->Left, value);
    }
    else
        return NULL;
}
int CountNode(Tnode root)
{
    if (root == NULL)
        return 0;
    else
        return (1 + CountNode(root->Left) + CountNode(root->Right));
}
int Countleft(Tnode root)
{
    if (root != NULL)
    {
        if ((root->Left == NULL) && (root->Right == NULL))
            return 1;
        else
            return (Countleft(root->Left) + Countleft(root->Right));
    }
    else
        return 0;
}
int CountInternal(Tnode root)
{
    return CountNode(root) - Countleft(root);
}
void deleteNode(int x, Tnode *root) {
    if ((*root) == NULL)
        return;
    if ((*root)->data > x) {
        deleteNode(x, &(*root)->Left);
    } else if ((*root)->data < x) {
        deleteNode(x, &(*root)->Right);
    } else { //data = x, root la node can xoa
        if ((*root)->Left == NULL && (*root)->Right == NULL) {
            (*root) = NULL;

        } else{
            if((*root)->Left==NULL ){
                Tnode *p = root;
                (*root)=(*root)->Right;
                delete *p;
            }else if((*root)->Right == NULL){
                Tnode *p = root;
                (*root)=(*root)->Left;
                delete *p;
            }else{
                Tnode p = (*root)->Left;
                Tnode *temp;
                if (p->Right != NULL)
                    while(p->Right!=NULL){
                        temp = &(p->Right);
                        p = p->Right;
                    }
                (*root)->data = p->data;
                *temp = (*temp)->Left;
                delete (temp);
            }
        }

    }
} 
int Level(Tnode root){
    if(root==NULL){
        return -1;
    }else{

            return 1 + max(Level(root->Left),Level(root->Right));    
    }
}
int main()
{
    Tnode root = NULL;
    root = inserNode(root, 10);
    root = inserNode(root, 7);
    root = inserNode(root, 11);
    root = inserNode(root, 11);
    postorder(root);
    cout << endl;
    inorder(root);
    cout << endl;
    preorder(root);
    cout << endl;
    // cout << smallest(root)->data << endl;
    // cout << largest(root)->data << endl;
    // cout << Search(root, 7)->data << endl;
    // cout << CountInternal(root)<<endl;
    // cout<<Level(root)<<endl;
    Tnode *p = &root;
    deleteNode(7, &root);
    cout<<"hello";

}
