#include <iostream>
#include <cstring>
using namespace std;

struct mathang {
    char tenhang[100];
    int soluong;
    double giathanh;
};

const int MAX_MAT_HANG = 5;
mathang kho[MAX_MAT_HANG];  // Array of mathang structures

void taokho() {
    // Initialize values for each item in the warehouse
    strcpy(kho[0].tenhang, "Kem danh rang");
    kho[0].soluong = 10;
    kho[0].giathanh = 5.0;

    strcpy(kho[1].tenhang, "Sua tam");
    kho[1].soluong = 20;
    kho[1].giathanh = 7.5;

    strcpy(kho[2].tenhang, "Bao cao su");
    kho[2].soluong = 100;
    kho[2].giathanh = 10.0;

    strcpy(kho[3].tenhang, "Sex toy");
    kho[3].soluong = 2000;
    kho[3].giathanh = 100.0;

    strcpy(kho[4].tenhang, "May suc cu");
    kho[4].soluong = 20000;
    kho[4].giathanh = 10000.0;
}

void hienthikho() {
    cout << "|STT| TEN SAN PHAM       | SO LUONG | GIA/1sp |" << endl;
    for (int i = 0; i < MAX_MAT_HANG; i++) {
        cout << "| " << i + 1 << " | " << kho[i].tenhang 
             << " | " << kho[i].soluong 
             << " | " << kho[i].giathanh << " |" << endl;
    }
}

void nhap(mathang &a) {
    cout << "Nhap ten loai mat hang: ";
    cin.ignore();  // Clear the newline character from the input buffer
    cin.getline(a.tenhang, 100);
    cout << "Nhap so luong san pham co trong kho: ";
    cin >> a.soluong;
    cout << "Nhap gia tien tren mot san pham: ";
    cin >> a.giathanh;
}

void xuat(mathang a) {
    cout << "| " << a.tenhang << " | " << a.soluong << " | " << a.giathanh << " |" << endl;
}

int main() {
    taokho();  // Initialize the warehouse items
    while (1) {
        cout << "___CHAO MUNG BAN DEN VOI HE THONG QUAN LI KHO HANG___" << endl;
        cout << "|  1. Xem thong tin mat hang ton kho                |" << endl;
        cout << "|  2. Xuat kho                                      |" << endl;
        cout << "|  3. Nhap them so luog hang moi nhap ve kho       |" << endl;
        cout << "|  0. Thoat he thong                                |" << endl;
        cout << "|___________________________________________________|" << endl;

        int lc;
        cin >> lc;
        if (lc == 1) {
            hienthikho();
        } else if (lc == 2) {
            cout << "Ban can xuat bao nhieu loai mat hang:";
            int sl;
            cin >> sl;
            for (int i = 0; i < sl; i++) {
                mathang mh;
                nhap(mh);
                xuat(mh);
            }
        } else if (lc == 3) {
            cout << "He thong da dong" << endl;
            return 0;
        } else if (lc == 0) {
            break;
        } else {
            cout << "Lua chon khong hop le, vui long thu lai." << endl;
        }
    }
    return 0;
}
