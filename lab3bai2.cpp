#include <bits/stdc++.h>
using namespace std;
typedef struct element
{
    char data;
} ;
typedef struct stack1 *stack_pointer;

struct stack1
{
    element item;
    stack_pointer link;
};

void push(stack_pointer *top, element item)
{
    stack_pointer temp = new stack1;
    temp->item = item;
    temp->link = *top;
    *top = temp;
}
element pop(stack_pointer *top)
{
    stack_pointer temp = *top;
    element item;
    item = temp->item;
    *top = temp->link;
    delete (temp);
    return item;
}
bool check2(char a, char b){
    if(a=='('&&b==')'){
        return true;
    }
     if(a=='{'&&b=='}'){
        return true;
    }
     if(a=='['&&b==']'){
        return true;
    }
    return false;
}
bool check(string s){
    element item;
    stack_pointer top =NULL;
    for(int i=0; i<s.length(); i++){
        item.data=s[i];
        if(s[i]=='('||s[i]=='{'||s[i]=='['){
            push(&top,item );
        }else if(s[i]==')'||s[i]=='}'||s[i]==']'){
            if(top==NULL){
                return false;
            }else{
                element item2 = pop(&top);
                if(check2(item2.data, s[i])==false){
                    return false;
                }
            }
        }
    }
    if(top!=NULL){
        return false;
    }else{
        return true;
    }
}
int main()
{
    string s;
    getline(cin, s);
    if(check(s)==true){
        cout<<"Chuoi can bang "<<endl;
    }else{
        cout<<"Chuoi khong can bang "<<endl;
    }
}
