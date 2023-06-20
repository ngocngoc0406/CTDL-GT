#include <bits/stdc++.h>
using namespace std;
struct Dateofbirth
{
    int ngay;
    int thang;
    int nam;
};
struct SinhVien
{
    string ten;
    Dateofbirth namsinh;
    double dToan;
    double dLy;
    double dNgoaingu;
};
typedef struct node *pnode;
struct node
{
    SinhVien data;
    pnode Next;
};
pnode createNode(SinhVien value)
{
    pnode temp;
    temp = new node;
    temp->Next = NULL;
    temp->data = value;
    return temp;
}
Dateofbirth Nhapnamsinh()
{
    Dateofbirth namsinh;
    cout << "Nhap ngay ";
    cin >> namsinh.ngay;
    cout << "Nhap thang ";
    cin >> namsinh.thang;
    cout << "Nhap nam ";
    cin >> namsinh.nam;
    return namsinh;
}
SinhVien Nhapsinhvien()
{
    SinhVien s;
    cout << "nhap ten ";
    fflush(stdin);
    getline(cin, (s).ten);
    cout << "nhap Ngay thang nam sinh "<<endl;
    s.namsinh = Nhapnamsinh();
    cout << "nhap diem toan ";
    cin >> (s).dToan;
    cout << "nhap diem vat ly ";
    cin >> (s).dLy;
    cout << "Nhap diem ngoai ngu ";
    cin >> (s).dNgoaingu;
    return s;
}
pnode addhead(pnode head, SinhVien value)
{
    pnode temp = createNode(value);
    temp->Next = head;
    head = temp;
    return head;
}
pnode insertlast(pnode head, SinhVien value)
{
    if (head == NULL)
    {
        head = createNode(value);
        return head;
    }
    pnode temp, p;
    p = head;
    temp = createNode(value);
    while (p->Next != NULL)
    {
        p = p->Next;
    }
    p->Next = temp;
    return head;
}
pnode Nhapds(pnode head)
{
    SinhVien value;
    int n;
    cout << "nhap so sv trong ds ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        head = insertlast(head, Nhapsinhvien());
    }
    return head;
}

void display(pnode head)
{
    pnode p = head;
    while (p != NULL)
    {
        cout << p->data.ten << " \t" << p->data.namsinh.ngay << "/" << p->data.namsinh.thang << "/" << p->data.namsinh.nam << " \t"
             << p->data.dToan << " \t" << p->data.dLy << " \t" << p->data.dNgoaingu << endl;
        p = p->Next;
    }
}
int Demhs(pnode head, int nam)
{
    pnode p = head;
    int dem = 0;
    while (p != NULL)
    {
        if (nam == p->data.namsinh.nam)
            dem++;
        p = p->Next;
    }
    return dem;
}
void Kiemtrasv(pnode head, string Tensv)
{
    pnode p = head;
    while (p != NULL)
    {
        if (p->data.ten == Tensv)
        {
            cout << p->data.ten << " \t"
                 << p->data.namsinh.ngay << "/" << p->data.namsinh.thang << "/" << p->data.namsinh.nam << " \t"
                 << p->data.dToan << " \t" << p->data.dLy << " \t" << p->data.dNgoaingu << endl;
        }
        p = p->Next;
    }
}
double DiemTB(SinhVien s)
{
    return (s.dLy + s.dNgoaingu + s.dToan) / 3;
}
pnode RemoveHead(pnode head)
{
    pnode p = head;
    head = p->Next;
    delete (p);
    return head;
}
pnode Xoasv(pnode head, string Ten)
{
    pnode dsmoi = NULL;
    pnode p = head;
    while (p != NULL)
    {
        if (p->data.ten != Ten)
        {
            dsmoi = insertlast(dsmoi, p->data);
        }
        p = p->Next;
    }
    while (head != NULL)
    {
        head = RemoveHead(head);
    }
    return dsmoi;
}
void TimDiemTB(pnode head)
{
    double max = 0;
    pnode p = head;
    while (p != NULL)
    {
        if (DiemTB(p->data) >= max)
            max = DiemTB(p->data);
        p = p->Next;
    }
    p = head;
    while (p != NULL)
    {
        if (DiemTB(p->data) == max)
        {
            cout << p->data.ten << " \t" << p->data.namsinh.ngay << "/" << p->data.namsinh.thang << "/" << p->data.namsinh.nam << " \t"
                 << p->data.dToan << " \t" << p->data.dLy << " \t" << p->data.dNgoaingu << endl;
        }
        p = p->Next;
    }
}
void diemtoan(pnode head)
{
    pnode p = head;
    while (p != NULL)
    {
        if (p->data.dToan < 5)
        {
            cout << p->data.ten << " \t" << p->data.namsinh.ngay << "/" << p->data.namsinh.thang << "/" << p->data.namsinh.nam << " \t"
                 << p->data.dToan << " \t" << p->data.dLy << " \t" << p->data.dNgoaingu << endl;
        }
        p = p->Next;
    }
}
void Ghids(pnode head)
{
    ofstream o;
    o.open("StudentList.txt");
    pnode p = head;
    while (p != NULL)
    {
    
        o << p->data.ten << " \t" << p->data.namsinh.ngay << "/" << p->data.namsinh.thang << "/" << p->data.namsinh.nam << " \t"
             << p->data.dToan << " \t" << p->data.dLy << " \t" << p->data.dNgoaingu << endl;
             
        p = p->Next;
    }
    o.close();
    cout<< "Save succes"<<endl;
}

int main()
{
    int choose;
    SinhVien s;
    pnode head = NULL;
    string name;
    do
    {
        cout << "<----------Menu---------->" << endl;
        cout << "1- Input n students information" << endl;
        cout << "2- Print out the student list." << endl;
        cout << "3- Add a new student to the list." << endl;
        cout << "4- Count the number of students in a given year of birth." << endl;
        cout << "5- Check if a student name x exists in the list or not." << endl;
        cout << "6- Delete a student from the list by a given name x." << endl;
        cout << "7- Find the student(s) having the biggest average of math, physic and language marks." << endl;
        cout << "8- Print the list of students whose math mark is less than 5." << endl;
        cout << "9- Write the student list to a file named StudentList.txt." << endl;
        cout << "10- EXIT"<<endl;
        cout << "Enter choose menu ";
        cin >> choose;
        switch (choose)
        {
        case 1:
            head = Nhapds(head);
            break;
        case 2:
            display(head);
            break;
        case 3:
            head = insertlast(head, Nhapsinhvien());
            display(head);
            break;
        case 4:
            int nam;
            cout << "Nhap vao nam sinh can tim kiem ";
            cin >> nam;
            cout <<" Co " <<Demhs(head, nam)<<" sinh vien co nam sinh la "<<nam << endl;
            break;
        case 5:
            cout << "Nhap vao ten can tim ";
            getline(cin, name);
            Kiemtrasv(head, name);
            break;
        case 6:
            cout<<"Nhap vao ten can xoa ";
            getline(cin,name);
            head = Xoasv(head, name);
            break;
        case 7:
            TimDiemTB(head);
            break;
        case 8:
            diemtoan(head);
            break;
        case 9:
            Ghids(head);
            break;
        default:
            break;
        }

    }while (choose !=10 );
}
