#include <iostream>
#include <math.h>
#include <ctype.h>
#include <string>
#include <cstring>
#include <iomanip>
#include <vector>
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
using namespace std;
struct mathang{
    char tenhang[100];
    int soluong;
    double giathanh;
};
typedef struct mathang mathang;
std::vector<mathang> kho(100);
void nhap2(std::vector<mathang>& kho, int n) {
    std::cin.ignore();
    std::cout << "Name: ";
    std::cin.getline(kho[n].tenhang, 100);
    std::cout << "Sl: ";
    std::cin >> kho[n].soluong;
    std::cin.ignore();
    std::cout << "Cost/item: ";
    std::cin >> kho[n].giathanh;
}
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
const int MAX_MAT_HANG = 100;//100 mặt hàng tối đa
//mathang kho[MAX_MAT_HANG];  // Mảng của cấu trúc mathang
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
    
    
}

int somathang(){
    int cnt = 0;
    for(int i = 0; i < kho.size(); i++){
        if(strlen(kho[i].tenhang)){
            cnt++;
        }
        else{
            break;
        }
    }
    return cnt;
}


void codeitem(string a){
    
}
long long costofwh(){
    long long cost = 0;
    for(int i = 0; i < somathang(); i++){
        cost += kho[i].soluong * kho[i].giathanh;
    }
    return cost;
}
void hienthikho(int n, int x){ //Hàm hiển thị kho hàng với các mặt hàng sẵn có
    cout << "$_____$_______________________$________________$___________________$"<< endl;
    cout << "| STT |" <<"    THE PRODUCT NAME   |" << "  THE QUANTITY  |" << "   COST/1item($)   |"<<endl;
    for(int i = 0; i < n; i++){
        if(i < 10){
            printf("|  %d  |", i);
        }
        else if(i >= 10 && i < 100){
            printf("|  %d |", i);
        }
        else if(i == 100){
            printf("|%d|", i);
        }
        int a = strlen(kho[i].tenhang);
        cout << kho[i].tenhang << setw(24 - a) << "|";
        int b = cnt(kho[i].soluong);
        cout << kho[i].soluong << setw(18 - b) << "|";
        int c = cnt(kho[i].giathanh);
        if(x == 1){
            //noidia
            cout << fixed <<kho[i].giathanh << " đ" << setw(12 - c) << "|"<<endl;
        }
        else if(x == 2){
            //america
            cout << fixed << kho[i].giathanh / 25454 << " $" << setw(16 - c) << "|"<<endl;
        }
        else if(x == 3){
            
        }
        else if(x == 4){
            
        }
    }
    
    cout << "$-----$-----------------------$----------------$-------------------$\n" << endl;
    printf( "The total value of goods in the warehouse at the moment is: %lld(dong)\n\n\n", costofwh());
    for(int i = 0; i < n; i++){
        if(kho[i].soluong < 20){
            printf("INFORM: Mat hang '%s' trong kho qua it de duy tri nhu cau\n\n", kho[i].tenhang);
        }
    }
}

void xuatkho(){
    taokho();
    while(1){
        cout << "Mat hang nay se xuat di dau:"<<endl;
        cout << "1.Cac dai li trong nuoc"<<endl;
        cout << "2.American(Dollar)"<<endl;
        cout << "3.JAV(JPY)"<<endl;
        cout << "4.Euro(Euro)"<<endl;
        int country;
        cin >> country;
            int xuat;
            cout << "The number of orders that need to be shipped: ";
            cin >> xuat;
            for(int i = 0; i < xuat; i++){
                int x;
                printf("Select the order code %d: ", i + 1); //hiện tại vẫn đang chọn số, sau đó sẽ cải tiến lên thành mã đơn hàng
                cin >> x;
                cout << "How many units are being exported: ";
                int a;
                cin >> a;
                kho[x].soluong -= a;
            }
            cout << "UPDATE WAREHOUSE INFORMATION AFTER IMPORT"<< endl;
            hienthikho(somathang(), country);
    }
}
void nhapkho(){
    taokho();
    cout << "The number of items curently in stock is: ";
    cout << somathang() << endl;
    cout << "How many more types of items would you like to add: ";
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        printf("Enter information for the %d item:\n", somathang() + i);
        nhap2(kho, somathang() + i);
    }
    cout << "UPDATE WAREHOUSE INFORMATION AFTER ENTRY"<<endl;
    hienthikho(somathang() + n, 1);
}
void baomat(){
    string a = "alester";
    string b = "top1thaibinh";
    cout << "LOG IN(Use the English keyboard to type.)"<<endl;
    while(1){
        cout << "User name:";
        string tk;
        cin >> tk;
        if(a.compare(tk) != 0){
            cout << "Wrong account, please enter again." << endl;
            continue;
        }
        else{
            cout << "Password:";
            string mk;
            cin >> mk;
            if(mk.compare(b) != 0){
                cout << "Wrong password, please re-enter." << endl;
                continue;
            }
            else{
                break;
            }
        }
    }
}
int main() {
    while(1){
        cout << "______WELCOME TO THE WAREHOUSE MANAGEMENT SYSTEM______" << endl;
        cout << "|  1.VIEW INVENTORY INFORMATION                      |" << endl;
        cout << "|  2.EXPORT FROM WAREHOUSE                           |" << endl;
        cout << "|  3.IMPORT GOODS IN TO THE WAREHOUSE                |" << endl;
        cout << "|  4.UPDATE PRODUCT INFORMATION                      |" << endl;
        cout << "|  0.EXIT THE SYSTEM.                                |" << endl;
        cout << "!____________________________________________________!" << endl;
        cout << "SELECT: ";
        int lc;
        cin >> lc;
        if(lc == 1){
            taokho();
            hienthikho(10, 1);
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
        else if(lc == 0){
            //FINISHED
            cout << "The system has closed"<<endl;
            return 0;
        }
    }
    return 0;
}
/*xây dựng chức năng của hệ thống quản lí kho hàng
 FINISHED 1.Bảo mật cho kho hàng-------baomat()
 FINISHED 2.Kiểm soát thông tin các mặt hàng tồn đọng trong kho(select 1)--------taokho(), hienthikho()
 3.Xuất kho(select 2) **new idea: mặt hàng nào dưới 20 sản phẩm sẽ có cảnh báo hàng quá ít**
 ------xuatkho()
 4.Nhập kho(select 3) **idea: các mặt hàng nhập vào sẽ tự động được thêm vào mảng cấu trúc**
 ------nhapkho()
 5.Kiểm tra lại thông tin kho hàng sau khi thao tác nhập xuất(select 4)
 
 FINISHED 6.Thoát hệ thống
 **Tính năng mới
 FINISHED       *Tính toán tổng số tiền hàng trong kho
       -----costofwh()
                *Quy đổi sang một số loại tiền tệ khác (Dollar, Pound, Euro, Yên Nhật...)
                Xuất khẩu sang nước ngoài, quy đổi tiền sang $,Yên, Pound...
                Thay đổi trong code(
      +> in ra bảng với đơn vị tiền tương ứng, tính toán tổng số tiền cũng tương ứng
 )
                *Tạo mã mặt hàng bằng cách lấy chữ cái in hoa đầu tiên của các tên(VD: Kem danh rang -> KDR)
       -----codeitem()
 #bỏ mục 5. đi cũng được vì sau hàm nhập với xuất có check lại kho rồi
 */
