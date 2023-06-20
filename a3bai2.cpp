#include<bits/stdc++.h>
using namespace std;
typedef struct node *pnode;
struct node
{
    int num;    // du lieu chua trong 1 cái node
    pnode next; // con tro liên ket giua các cái node vs nhau
};
pnode ptr = NULL;
#define IS_EMPTY(ptr) (!(ptr));
#define IS_FULL(ptr) (!(ptr));
pnode createNode(int value)
{
    pnode temp;
    temp = new node;
    temp->next = NULL;
    temp->num = value;
    return temp;
}
pnode addhead(pnode head, int value)
{
    pnode temp = createNode(value);
    temp->next = head;
    head = temp;
    return head;
}
pnode insertlast(pnode head, int value)
{   
    if(head == NULL){
        head=createNode(value);
        return head;
    }
    pnode temp, p;
    p = head;
    temp = createNode(value);
    while (p->next != NULL)
    {
        p = p->next;
    }
    p->next = temp;
    return head;
}
pnode RemoveHead(pnode head){
    pnode p=head;
    head = p->next;
    delete(p);
    return head;
}
pnode RemoveLast(pnode head){
    pnode p=head,temp;
    while(p->next->next!=NULL){
        p=p->next;
    }
    temp=p->next;
    p->next=NULL;
    delete(temp);
    return head;
}
void display(pnode head)
{
    pnode p = head;
    while (p != NULL)
    {
        cout << p->num << " ";
        p = p->next;
    }
}
int countNode(pnode head){
    pnode p=head;
    int count =1;
    while(p->next!=NULL){
        p=p->next;
        count++;
    }
    return count;
}
void placeNode(pnode head, int value){
    pnode p=head;
    int place=0;
    while(p!=NULL){
        if(p->num==value){
            cout<<place<<" ";
        }
        p=p->next;
        place++;
    }
}
void findNode(pnode head, int place){
    pnode p=head;
    int index=0;
    if(place>=countNode(head)){
          cout<<"chi so khong hop le"<<endl  ;
          return;
    }
    
    while(p!=NULL){
        if(index==place){
            cout<< p->num<<endl;
        }
        p=p->next;
        index++;
    }
    
}
pnode remove_by_index(pnode head, int index){
    pnode p=head,temp;
    int place =0;
    if(index==0){
       head = RemoveHead(head);
        return head;
    }
    if(index>=countNode(head)){
        cout<<"vi tri khong hop le"<<endl;
        return head;
    }
    while(p!=NULL){
        if((index-1)==place){
            break;
        }
        p=p->next;
        place++;
    }
    temp=p->next;
    p->next=p->next->next;
    delete(temp);
    return head;

}
pnode insert_by_index(pnode head, int index, int value){
    pnode p=head;
    pnode temp = createNode(value);
    int place =0;
    if(index ==0){
        head=addhead(head,value);
        return head;
    }
    if(index>countNode(head)){
        cout<<"vi tri khong hop le";
        return head;
    }
    if(index==countNode(head)){
        head=insertlast(head,value);
        return head;
    }
    while(p!=NULL){
        if((index-1)==place){
            break;
        }
        p=p->next;
        place++;
    }
    temp->next=p->next;
    p->next=temp;
    return head;
}
pnode match_pnode(pnode head1, pnode head2){
    pnode p1=head1;
    pnode p2=head2;
    while(p1->next!=NULL){
        p1=p1->next;
    }
    p1->next=p2;
    return head1;
}
pnode sort_pnode(pnode head1, pnode head2){
    pnode p1=head1;
    pnode p2=head2;
    pnode head3 = NULL;
    pnode p3=head3;
    while(p1!=NULL&&p2!=NULL){
        if(p1->num>=p2->num){
            head3=insertlast(head3,p2->num);
            p2=p2->next;
        }else{
            head3=insertlast(head3,p1->num);
            p1=p1->next;
        }
    }
    while(p1!=NULL){
        head3=insertlast(head3,p1->num);
        p1=p1->next;
    }
    while(p2!=NULL){
        head3=insertlast(head3,p2->num);
        p2=p2->next;
    }
    return head3;
    
}

bool Isset(pnode s){
    pnode p=s;
    int min = INT_MAX;
    while(p!=NULL){
        if(p->num<=min){
            min=p->num;
        }
        p=p->next;
    }
    int count[1000];
    p=s;
    while(p!=NULL){
        count[p->num-min]=0;
        p=p->next;
    }
    p=s;
    while(p!=NULL){
        count[p->num-min]++;
        p=p->next;
    }
    p=s;
    while(p!=NULL){
        if(count[p->num-min]>1){
            return false;
        }
        p=p->next;
    }
    return true;

}
bool subset(pnode s1,pnode s2){
    pnode p=s2;
    int min = INT_MAX;
    while(p!=NULL){
        if(p->num<=min){
            min=p->num;
        }
        p=p->next;
    }
   p=s1;
    while(p!=NULL){
        if(p->num<=min){
            min=p->num;
        }
        p=p->next;
    }
    int count[1000];
    p=s2;
    while(p!=NULL){
        count[p->num-min]=0;
        p=p->next;
    }
    p=s1;
    while(p!=NULL){
        count[p->num-min]=0;
        p=p->next;
    }
    p=s2;
    while(p!=NULL){
        count[p->num-min]++;
        p=p->next;
    }
    
     p=s1;
    while(p!=NULL){
        if(count[p->num-min]==0){

            return false;
        }
        p=p->next;
    }
    return true;
    
}
pnode Union(pnode s1,pnode s2){
    pnode p=s2;
    int min = INT_MAX;
    while(p!=NULL){
        if(p->num<=min){
            min=p->num;
        }
        p=p->next;
    }
   p=s1;
    while(p!=NULL){
        if(p->num<=min){
            min=p->num;
        }
        p=p->next;
    }
    int count[1000];
    p=s2;
    while(p!=NULL){
        count[p->num-min]=0;
        p=p->next;
    }
    p=s1;
    while(p!=NULL){
        count[p->num-min]=0;
        p=p->next;
    }
    p=s2;
    while(p!=NULL){
        count[p->num-min]++;
        p=p->next;
    }
    p=s1;
    while(p!=NULL){
        if(count[p->num-min]==0){
            s2=insertlast(s2,p->num);
        }
        p=p->next;
    }
    return s2;

}
pnode intersection(pnode s1,pnode s2){
    pnode p=s2;
    pnode s3=NULL;
    int min = INT_MAX;
    while(p!=NULL){
        if(p->num<=min){
            min=p->num;
        }
        p=p->next;
    }
   p=s1;
    while(p!=NULL){
        if(p->num<=min){
            min=p->num;
        }
        p=p->next;
    }
    int count[1000];
    p=s2;
    while(p!=NULL){
        count[p->num-min]=0;
        p=p->next;
    }
    p=s1;
    while(p!=NULL){
        count[p->num-min]=0;
        p=p->next;
    }
    p=s2;
    while(p!=NULL){
        count[p->num-min]++;
        p=p->next;
    }
    p=s1;
    while(p!=NULL){
        if(count[p->num-min]!=0){
            s3=insertlast(s3,p->num);
        }
        p=p->next;
    }
    return s3;

}

int main(){
     pnode head=NULL;
     pnode head2=NULL;
    head=insertlast(head,1);
    head=insertlast(head,2);
    head=insertlast(head,9);
    head=insertlast(head,3);
    head=insertlast(head,4);
    head=insertlast(head,-7);
    head2=insertlast(head2,1);
    head2=insertlast(head2,2);
    head2=insertlast(head2,9);
    head2=insertlast(head2,30);
    //cau a
    if(Isset(head)){
        cout<<"YES";
    }else{
        cout<<"NO";
    }
    //cau b
    if(subset(head,head2)){
        cout<<"YES";
    }else{
        cout<<"NO";
    }
    //cau c
    head=Union(head,head2);
    //cau d
    head=intersection(head,head2);
    display(head);

}
