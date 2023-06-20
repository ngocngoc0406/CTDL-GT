#include<bits/stdc++.h>
using namespace std;
typedef struct node *pnode;
struct node{
    int num;
    int coeff;
    pnode next;
};
pnode createNode (int num, int coeff){
    pnode temp;
    temp = new node;
    temp->next = NULL;
    temp->num = num;
    temp->coeff=coeff;
    return temp;
}
pnode insertlast(pnode head, int num, int coeff)
{
    if(head == NULL){
        head=createNode(num,coeff);
        return head;
    }
    pnode temp, p;
    p = head;
    temp = createNode(num,coeff);
    while (p->next != NULL)
    {
        p = p->next;
    }
    p->next = temp;
    return head;
}
pnode Nhapdathuc(){
    pnode head = NULL;
    int n,num,coeff;
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>coeff >> num;
        head = insertlast(head, num, coeff);
    }
    return head;
}
void Display(pnode head){
    pnode p=head;
    while(p!=NULL){
        if (p->coeff > 0 && p != head)
            cout << "+";
        if (p->num == 0) {
            cout <<p->coeff << " ";
        } else if (p->num == 1) {
           cout<<p->coeff<<"x "; 
        } else
            cout<<p->coeff<<"x^"<<p->num << " ";
        p=p->next;
    }
    cout << endl;
}

pnode sum(pnode head1, pnode head2) {
    int max = 1000;
    int a[max];
    for (int i = 0; i < max; i++)
        a[i] = 0;
    pnode p = head1;
    while (p != NULL) {
        a[p->num] = p->coeff;
        p = p->next;
    }
    p = head2;
    while (p != NULL) {
        a[p->num] += p->coeff;
        p = p->next;
    }

    pnode head = NULL;
    for (int i = max - 1; i >= 0; i--) {
        if (a[i] != 0)
            head = insertlast(head, i, a[i]);
    }
    return head;
}
pnode sub(pnode head1, pnode head2) {
    int max = 1000;
    int a[max];
    for (int i = 0; i < max; i++)
        a[i] = 0;
    pnode p = head1;
    while (p != NULL) {
        a[p->num] = p->coeff;
        p = p->next;
    }
    p = head2;
    while (p != NULL) {
        a[p->num] -= p->coeff;
        p = p->next;
    }

    pnode head = NULL;
    for (int i = max - 1; i >= 0; i--) {
        if (a[i] != 0)
            head = insertlast(head, i, a[i]);
    }
    return head;
}

main() {
    cout<<"nhap da thuc 1";
    pnode head1 = Nhapdathuc();
    cout<<"nhap da thuc 2 ";
    pnode head2 = Nhapdathuc();
    pnode head3 = sum(head1, head2);
    pnode head4 = sub(head1, head2);
    Display(head1);
    Display(head2);
    Display(head3);
    Display(head4);
}
