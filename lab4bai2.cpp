#include <bits/stdc++.h>
using namespace std;
struct student
{
    char id[12];
    char name[30];
    char Class[10];
    float mMath;
    float mPhysical;
};
typedef struct node *pnode;
struct node
{
    student data;
    pnode next;
};
pnode createNode(student value)
{
    pnode temp;
    temp = new node;
    temp->next = NULL;
    temp->data = value;
    return temp;
}
pnode insertlast(pnode head, student value)
{
    if (head == NULL)
    {
        head = createNode(value);
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
student addSt()
{
    student s;

    cout << "input id ";
    fflush(stdin);
    gets(s.id);
    cout << "input name ";
    fflush(stdin);
    gets(s.name);
    cout << "input class ";
    fflush(stdin);
    gets(s.Class);
    cout << "input mark Math ";
    cin >> s.mMath;
    cout << "input mark Physical ";
    cin >> s.mPhysical;
    return s;
}
void Display(pnode head)
{
    pnode p = head;
    while (p != NULL)
    {
        cout << p->data.id << " \t" << p->data.name << "\t" << p->data.Class << "\t" << p->data.mMath << " \t"
             << p->data.mPhysical << endl;
        p = p->next;
    }
}
pnode Nhapds(pnode head)
{
    student value;
    int n;
    cout << "nhap so sv trong ds ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        head = insertlast(head, addSt());
    }
    return head;
}

void findstudent(pnode head, student s)
{
    pnode p = head;
    cout << "input id ";
    fflush(stdin);
    gets(s.id);
    while (p != NULL)
    {
        if (strcmp(p->data.id, s.id) == 0)
        {
            cout << p->data.id << " \t" << p->data.name << "\t" << p->data.Class << "\t" << p->data.mMath << " \t"
                 << p->data.mPhysical << endl;
        }
        p = p->next;
    }
}
double getAvg(student s) {
    return (s.mMath + s.mPhysical) / 2;
}
pnode SortList(pnode head){
    pnode p = head;
    while (p->next != NULL) {
        pnode min = p;
        pnode p2 = p->next;
        while(p2 != NULL) {
            if (getAvg(min->data) > getAvg(p2->data))
                min = p2;
            p2 = p2->next;
        }
        student temp = min->data;
        min->data = p->data;
        p->data = temp;
        
        p = p->next;
    }
    return head;

}


int main()
{
    student s;
    pnode head = NULL;
    int choose;
    do
    {
        cout << "<---------- Menu---------->" << endl;
        cout << "1. Input, output a list of student. " << endl;
        cout << "2. Search a student by identification." << endl;
        cout << "3.  Sort the list in descending order based on avg (avg = (mMath+ mPhysical)/2)." << endl;
        cout << "Choose, please!" << endl;
        cin >> choose;
        switch (choose)
        {
        case 1:
            head = Nhapds(head);
            Display(head);
            break;
        case 2: 
            findstudent(head, s);
            break;
        case 3:
            head = SortList(head);
            Display(head);
            break;
        }
       

    } while (choose != 4);

    
}
