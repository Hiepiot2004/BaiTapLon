#include <iostream>
#include <math.h>
#include <ctype.h>
#include <string>
#include <cstring>
#include <iomanip>
using namespace std;
struct mathang{
    char tenhang[100];
    int soluong;
    double giathanh;
};
typedef struct mathang mathang;
int cnt(int n){ //Hàm tính độ dài của 1 số để căn lề bẳng sản phẩm
    int count = 1;
    if(n == 0){
        return 2;
    }
    while(n){
        count++;
        n /= 10;
    }
    return count;
}
const int MAX_MAT_HANG = 100; //tạm thời để có 5 mặt hàng
mathang kho[MAX_MAT_HANG];  // Mảng của cấu trúc mathang
int demhang=0;
void taokho() {
    
    // Khởi tạo các giá trị cho mỗi mặt hàng trong kho
    strcpy(kho[0].tenhang, "Kem danh rang");
    kho[0].soluong = 10;
    kho[0].giathanh = 35000;
    
    
    strcpy(kho[1].tenhang, "Sua tam");
    kho[1].soluong = 20;
    kho[1].giathanh = 75000;
    
    
    strcpy(kho[2].tenhang, "Ban chai");
    kho[2].soluong = 100;
    kho[2].giathanh = 45000;
    
    
    strcpy(kho[3].tenhang, "Khau trang");
    kho[3].soluong = 2000;
    kho[3].giathanh = 100000;
    
    
    strcpy(kho[4].tenhang, "My pham");
    kho[4].soluong = 250;
    kho[4].giathanh = 500000;
    
    
    strcpy(kho[5].tenhang, "Dau goi dau");
    kho[5].soluong = 200;
    kho[5].giathanh = 180000;
    
    
    strcpy(kho[6].tenhang, "Kem chong nang");
    kho[6].soluong = 150;
    kho[6].giathanh = 250000;
    
    
    strcpy(kho[7].tenhang, "Sua rua mat");
    kho[7].soluong = 100;
    kho[7].giathanh = 180000;
    
    
    strcpy(kho[8].tenhang, "Xa phong");
    kho[8].soluong = 1000;
    kho[8].giathanh = 150000;
    
    
    strcpy(kho[9].tenhang, "Serum");
    kho[9].soluong = 20000;
    kho[9].giathanh = 100000;
    demhang = 10;
}
int somathang(){
  return demhang;
}
void hienthikho(int n){ //Hàm hiển thị kho hàng với các mặt hàng sẵn có
    cout << "$___$____________________$____________$_________________$"<< endl;
    cout << "|STT |" <<"    TEN SAN PHAM    |" << "  SO LUONG  |" << "  GIA/1sp(dong)  |"<<endl;
    for(int i = 0; i < n; i++){
        printf("| %d  |", i+1);
        int a = strlen(kho[i].tenhang);
        cout << kho[i].tenhang << setw(21 - a) << "|";
        int b = cnt(kho[i].soluong);
        cout << kho[i].soluong << setw(14 - b) << "|";
        int c = cnt(kho[i].giathanh);
        cout << kho[i].giathanh << setw(19 - c) << "|"<<endl;
        }
    cout << "$---$--------------------$------------$-----------------$\n\n";
}
void nhap(mathang &a) { //Hàm nhập hàng
        cin.ignore();
        cout << "Nhap ten loai mat hang: ";
        cin.getline(a.tenhang, 100);
        cout << "Nhap so luong san pham nhap vao kho: ";
        cin >> a.soluong;
        cin.ignore();
        cout << "Nhap gia tien tren mot san pham: ";
        cin >> a.giathanh;
}
void xuatkho(){

   while(true){
    cout<<"nhập số loại sản phẩm cần xuất "<<endl;
    int a=0;
    cin>>a;
    for(int i=0;i<a;i++){
        int xuat;
        cout<<"nhập sản phẩm cần xuất kho thứ (STT):"<<i+1<<endl;
        cin>>xuat;
        if(xuat<0||xuat>somathang()){
            cout<<"tên sản phẩm không hợp lệ mời nhập lại "<<endl;
            continue;
        }
        if
        for(int i=xuat-1;i<=somathang();i++){
            kho[i]=kho[i]
        }
        int soluong=0;
        cout<<"nhập số lượng "<<endl;
        cin>>soluong;
        if(soluong<0||soluong>kho->soluong){
            cout<<"số lượng không hợp lệ vui lòng nhập lại "<<endl;
            continue;
        }


    }
   }
    hienthikho(somathang());
}
void nhapkho(){
    cout << "Số mặt hàng đang có trong kho là: ";
    cout << somathang() << endl;
    cout << "Bạn muốn nhập thêm bao nhiêu loại mặt hàng nữa: ";
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        printf("Nhập thông tin mặt hàng số %d:\n", somathang() + i + 1);
        nhap(kho[demhang + i]);
    }
    demhang+=n;
    cout << "CẬP NHẬT THÔNG TIN KHO HÀNG SAU KHI NHẬP KHO"<<endl;
    hienthikho(somathang());
}
void baomat(){
    string a = "alester";
    string b = "top1thaibinh";
    cout << "LOG IN(Dùng bàn phím tiếng Anh để nhập)"<<endl;
    while(1){
        cout << "User name:";
        string tk;
        cin >> tk;
        if(a.compare(tk) != 0){
            cout << "Sai tài khoản, yêu cầu nhập lại" << endl;
            continue;
        }
        else{
            cout << "Passwork:";
            string mk;
            cin >> mk;
            if(mk.compare(b) != 0){
                cout << "Sai mật khẩu, yêu cầu nhập lại" << endl;
                continue;
            }
            else{
                break;
            }
        }
    }
}
int main() {
    taokho();

    while(1){
        cout << "___CHAO MUNG BAN DEN VOI HE THONG QUAN LI KHO HANG___" << endl;
        cout << "|  1.Xem thong tin mat hang ton kho                 |" << endl;
        cout << "|  2.Xuat kho                                       |" << endl;
        cout << "|  3.Nhap them so luong hang moi nhap ve kho        |" << endl;
        cout << "|  4.Cap nhat thong tin kho sau khi nhap xuat       |" << endl;
        cout << "|  0.Thoat he thong                                 |" << endl;
        cout << "!___________________________________________________!" << endl;
        cout << "SELECT: ";
        int lc;
        cin >> lc;
        if(lc == 1){
            taokho();
            hienthikho(10);
            //FINISHED
        }
        else if(lc == 2){
           //FINISHED
            xuatkho();
        }
        else if(lc == 3){ // Tạo 1 hàm để xuất kho(idea: chọn stt tương ứng với mặt hàng, chọn số lượng cần xuất ra), việc này trực tiếp thực hiện trên việc thay đổi kho[i].soluong
            nhapkho();
        }
        else if(lc == 4){
            //Hàm này cập nhật lại cái bảng mặt hàng như lc == 1;nhưng sau khi thực hiện 2 hoặc 3
        }
        else if(lc == 0){//đóng hệ thống, không có gì cần làm
            cout << "He thong da dong"<<endl;
            return 0;
        }
    }
    return 0;
}
