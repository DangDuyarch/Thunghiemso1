#include <iostream>
#include <string>

using namespace std;

// Định nghĩa struct SinhVien
struct SinhVien {
    string hoTen;
    string maSo;
    float diemGPA;
};

int main() {
    // 1. Tạo (khởi tạo) một biến sv1 kiểu SinhVien
    SinhVien sv1;
    sv1.hoTen = "Dang Van Duy";
    sv1.maSo = "202XXXXX"; // Thay mã số của bạn vào đây nhé
    sv1.diemGPA = 3.6;

    SinhVien sv2;
    sv2.hoTen = "Nguyen Hoang Son";
    sv2.maSo = "202XXXXX"; // Thay mã số của bạn vào đây nhé
    sv2.diemGPA = 3.6;

    SinhVien sv3;
    sv3.hoTen = "Doan Ba Quy";
    sv3.maSo = "202XXXXX"; // Thay mã số của bạn vào đây nhé
    sv3.diemGPA = 3.6;

    // 2. In thông tin ra màn hình
    cout << "--- Thong tin sinh vien ---" << endl;
    cout << "Ho ten: " << sv1.hoTen << endl;
    cout << "MSSV: " << sv1.maSo << endl;
    cout << "Diem GPA: " << sv1.diemGPA << endl;
  cout << "--- Thong tin sinh vien ---" << endl;
    cout << "Ho ten: " << sv2.hoTen << endl;
    cout << "MSSV: " << sv2.maSo << endl;
    cout << "Diem GPA: " << sv2.diemGPA << endl;
      cout << "--- Thong tin sinh vien ---" << endl;
    cout << "Ho ten: " << sv3.hoTen << endl;
    cout << "MSSV: " << sv3.maSo << endl;
    cout << "Diem GPA: " << sv3.diemGPA << endl;
    return 0;
}