#include <iostream>
using namespace std;
struct SinhVien {
    string hoTen;
    string lop;
    float diemTB;
    SinhVien* next;
};
class DanhSachSinhVien {
private:
    SinhVien* head;
public:
    DanhSachSinhVien() {
        head = NULL;
    }
    void themSinhVien(string hoTen, string lop, float diemTB) {
        SinhVien* sv = new SinhVien;
        sv->hoTen = hoTen;
        sv->lop = lop;
        sv->diemTB = diemTB;
        sv->next = NULL;
        if (head == NULL) {
            head = sv;
        } else {
            SinhVien* p = head;
            while (p->next != NULL) {
                p = p->next;
            }
            p->next = sv;
        }
    }
    void inDanhSach() {
        SinhVien* p = head;
        while (p != NULL) {
            cout << p->hoTen << " - " << p->lop << " - " << p->diemTB << endl;
            p = p->next;
        }
    }
};
DanhSachSinhVien dssv;
dssv.themSinhVien("Nguyen Van A", "K62CB", 8.5);
dssv.themSinhVien("Tran Thi B", "K63CB", 7.5);
dssv.themSinhVien("Le Van C", "K61CB", 6.0);
void timSinhVienDTBLonHon5(DanhSachSinhVien dssv) {
    SinhVien* p = dssv.head;
    while (p != NULL) {
        if (p->diemTB > 5.0) {
            cout << p->hoTen << " - " << p->lop << " - " << p->diemTB << endl;
        }
        p = p->next;
    }
}


