#include<iostream>
#include<queue>
using namespace std;
struct Node
{
 	int data;
 	Node* left;
 	Node* right;
};

Node* create(int data, Node* left, Node* right){
	Node* p = new Node();
	p->data=data;
	p->left=left;
	p->right=right;
	return p;
}


    void preorderRecursive(Node* node) {
        if (node == NULL) {
            return;
        }
        cout << node->data << " ";
        preorderRecursive(node->left);
        preorderRecursive(node->right);
    }

    void inorderRecursive(Node* node) {
        if (node == NULL) {
            return;
        }
        inorderRecursive(node->left);
        cout << node->data << " ";
        inorderRecursive(node->right);
    }

    void postorderRecursive(Node* node) {
        if (node == NULL) {
            return;
        }
        postorderRecursive(node->left);
        postorderRecursive(node->right);
        cout << node->data << " ";
    }
    
    void levelOrderTraversal(Node* root) {
    if (root == NULL)
        return;

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* node = q.front();
        q.pop();

        cout << node->data << " ";

        if (node->left)
            q.push(node->left);
        if (node->right)
            q.push(node->right);
    }
}
int main(){
	Node* root =	create(8,create(3,create(1,NULL,NULL),create(6,create(4,NULL,NULL),create(7,NULL,NULL))), create(10,create(9,NULL,NULL),create(14,create(13,NULL,NULL),NULL)));
	preorderRecursive(root); cout<<endl;
	inorderRecursive(root); cout<<endl;
	postorderRecursive(root); cout<<endl;
	levelOrderTraversal(root);	
}

