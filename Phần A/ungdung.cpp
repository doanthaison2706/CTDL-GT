#include<iostream>
#include"danhsach.cpp"

using namespace std;

#ifndef APP_CPP
#define APP_CPP
class UngDungGiaoThong {
private:
    DanhSachPhuongTien danhSachPhuongTien;
public:
    void hienThiMenu() {
        cout << "===== He Thong Quan Ly Giao Thong =====" << endl;
        cout << "1. Them Phuong Tien" << endl;
        cout << "2. Them Danh Sach Phuong Tien" << endl;
        cout << "3. Hien Thi Danh Sach Phuong Tien" << endl;
        cout << "4. Sap Xep Phuong Tien Theo Khoang Cach" << endl;
        cout << "5. Tim Phuong Tien Theo So Hieu Tuyen" << endl;
        cout << "6. Xoa Phuong Tien Theo So Hieu Tuyen" << endl;
        cout << "7. Xuat Danh Sach Phuong Tien Ra File" << endl; 
        cout << "8. Cap Nhat Thong Tin Phuong Tien" << endl; 
        cout << "0. Thoat" << endl;
        cout << "=======================================" << endl;
        cout << "Nhap lua chon cua ban: ";
    }
    void xuLyLuaChonCuaNguoiDung(int luaChon) {
        switch (luaChon) {
        case 1: { 
            PhuongTienCongCong phuongTien("", "", 0, 0.0, 0.0, "");
            cin >> phuongTien; 
            danhSachPhuongTien.themPhuongTien(phuongTien);
            cout << "Phuong tien da duoc them thanh cong!" << endl;
            break;
        }
        case 2: { 
            string tenFile;
            cout << "Nhap ten file de doc phuong tien: ";
            cin >> tenFile;
            ifstream file(tenFile);
            if (!file) {
                cout << "Ten file \"" << tenFile << "\" khong hop le hoac khong ton tai!" << endl;
                break;
            }
            danhSachPhuongTien.docFile(tenFile); 
            cout << "Danh sach phuong tien da duoc them thanh cong!" << endl;
            break;
        }
        case 3: {
            danhSachPhuongTien.hienThiDanhSach();
            break;
        }
        case 4: {
            danhSachPhuongTien.sapXepPhuongTien();
            cout << "Phuong tien da duoc sap xep thanh cong!" << endl;
            break;
        }
        case 5: { 
            string soHieuTuyen;
            cout << "Nhap so hieu tuyen de tim: ";
            cin >> soHieuTuyen;
            danhSachPhuongTien.timPhuongTien(soHieuTuyen);
            break;
        }
        case 6: {
            string soHieuTuyen;
            cout << "Nhap so hieu tuyen de xoa: ";
            cin >> soHieuTuyen;
            danhSachPhuongTien.xoaPhuongTien(soHieuTuyen);
            break;
        }
        case 7: { 
            string tenFile;
            cout << "Nhap ten file de xuat: ";
            cin >> tenFile;
            ofstream file(tenFile);
            if (!file) {
                cout << "Ten file \"" << tenFile << "\" khong hop le hoac khong mo duoc de xuat!" << endl;
                break;
            }   
            danhSachPhuongTien.xuatFile(tenFile); 
            cout << "Danh sach phuong tien da duoc xuat thanh cong!" << endl;
            break;
        }
        case 8: { 
            danhSachPhuongTien.capNhatThongTinPhuongTien(); 
            break;
        }
        case 0: {
            cout << "Thoat khoi ung dung." << endl;
            break;
        }
        default: {
            cout << "Lua chon khong hop le. Vui long thu lai." << endl;
            break;
        }  
        }
    }
    void chay() {
        int luaChon;
        do {
            hienThiMenu();
            cin >> luaChon;
            xuLyLuaChonCuaNguoiDung(luaChon);
        } while (luaChon != 0);
    }
};
#endif