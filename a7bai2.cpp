#include<iostream>
using namespace std;
struct Node
{
 	char data;
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
void extractInfixExpression(Node* root) {
    if (root == NULL)
        return;

    if (root->left != NULL || root->right != NULL)
        cout << "(";

    extractInfixExpression(root->left);
    cout << root->data;
    extractInfixExpression(root->right);

    if (root->left != NULL || root->right != NULL)
        cout << ")";
}
void extractPrefixExpression(Node* root) {
    if (root == NULL)
        return;

    cout << root->data;
    extractPrefixExpression(root->left);
    extractPrefixExpression(root->right);
}

void extractPostfixExpression(Node* root) {
    if (root == NULL)
        return;

    extractPostfixExpression(root->left);
    extractPostfixExpression(root->right);
    cout << root->data;
}
int main(){
	Node* root = create('+',create('e',NULL,NULL), create('-',create('D',NULL,NULL),create('*',create('/',create('a',NULL,NULL),create('b',NULL,NULL)),create('c',NULL,NULL))));
	extractInfixExpression(root); cout<<endl;
	extractPostfixExpression(root); cout<<endl;
	extractPrefixExpression(root); cout<<endl;
	cout<<"Ket qua bieu thuc la: "<<(10+(30-((30/10)*2)));
}
 
