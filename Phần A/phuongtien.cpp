#include <iostream>
#include <string>
#include <fstream>
#ifndef PHUONG_TIEN_CPP
#define PHUONG_TIEN_CPP

using namespace std;

class PhuongTienCongCong {
private:
    string loaiPhuongTien;
    string soHieuTuyen;
    int sucChua;
    double quangDuong;
    double giaVe;
    string moTaTuyen;
public:
    // Hàm tạo
    PhuongTienCongCong() : loaiPhuongTien(""), soHieuTuyen(""), sucChua(0), quangDuong(0.0), giaVe(0.0), moTaTuyen("") {}
    PhuongTienCongCong(string loaiPT = "", string soHieu = "", int suc = 0, double quang = 0.0, double gia = 0.0, string moTa = "") : loaiPhuongTien(loaiPT), soHieuTuyen(soHieu), sucChua(suc), quangDuong(quang), giaVe(gia), moTaTuyen(moTa) {}
    // Toán tử nhập
    friend istream &operator>>(istream &in, PhuongTienCongCong &phuongTien) {
        cout << "Nhap loai phuong tien: ";
        in >> phuongTien.loaiPhuongTien;
        cout << "Nhap so hieu tuyen: ";
        in >> phuongTien.soHieuTuyen;
        do {
            cout << "Nhap suc chua: ";
            in >> phuongTien.sucChua;
            if (phuongTien.sucChua <= 0) {
                cout << "Suc chua khong hop le. Vui long nhap lai!" << endl;
            }
        } while (phuongTien.sucChua <= 0);
        do {
            cout << "Nhap quang duong: ";
            in >> phuongTien.quangDuong;
            if (phuongTien.quangDuong <= 0) {
                cout << "Quang duong khong hop le. Vui long nhap lai!" << endl;
            }
        } while (phuongTien.quangDuong <= 0);
        do {
            cout << "Nhap gia ve: ";
            in >> phuongTien.giaVe;
            if (phuongTien.giaVe < 0) {
                cout << "Loi: Gia va khong duoc nho hon 0. Vui long kiem tra lai!" << endl;
            }
        } while (phuongTien.giaVe < 0);
        cout << "Nhap mo ta tuyen: ";
        in.ignore();
        getline(in, phuongTien.moTaTuyen);
        return in;
    }
    // Toán tử xuất
    friend ostream &operator<<(ostream &out, const PhuongTienCongCong &phuongTien) {
        out << "Loai phuong tien: " << phuongTien.loaiPhuongTien << endl;
        out << "So hieu tuyen: " << phuongTien.soHieuTuyen << endl;
        out << "Suc chua: " << phuongTien.sucChua << endl;
        out << "Quang duong: " << phuongTien.quangDuong << " km" << endl;
        out << "Gia ve: " << phuongTien.giaVe << " VND" << endl;
        out << "Mo ta tuyen: " << phuongTien.moTaTuyen << endl;
        return out;
    }
    // Toán tử so sánh
    bool operator<(const PhuongTienCongCong &khac) const {
        return this->quangDuong < khac.quangDuong;
    }
    // Phương thức đọc dư liệu từ file
    bool docTuFile(ifstream &file) {
        file >> loaiPhuongTien >> soHieuTuyen >> sucChua >> quangDuong >> giaVe;
        if (file.fail()) {
            cout << "Loi khi doc du lieu!" << endl;
            return false;
        }
        file.ignore();
        getline(file, moTaTuyen);
        return sucChua > 0 && quangDuong > 0;
    }
    // Các setter
    void setLoaiPhuongTien(string &loai) { 
        loaiPhuongTien = loai; 
    }
    void setSoHieuTuyen(string &soHieu) { 
        soHieuTuyen = soHieu; 
    }
    void setSucChua(int suc) { 
        if (suc > 0) {
            sucChua = suc; 
        } else {
            cout << "Suc chua khong hop le!" << endl;
        }
    }
    void setQuangDuong(double quang) {
        if (quang > 0) {
            quangDuong = quang;
        } else {
            cout << "Quang duong khong hop le!" << endl;
        }
    }
    void setGiaVe(double gia) { 
        if (gia >= 0) {
            giaVe = gia; 
        } else {
            cout << "Loi: Gia ve khong duoc nho hon 0. Vui long kiem tra lai" << endl;
        }
    }
    void setMoTaTuyen(string &moTa) { 
        moTaTuyen = moTa; 
    }
    // Các getter
    string getLoaiPhuongTien() { 
        return loaiPhuongTien; 
    }
    string getSoHieuTuyen() { 
        return soHieuTuyen; 
    }
    int getSucChua() { 
        return sucChua; 
    }
    double getQuangDuong() { 
        return quangDuong; 
    }
    double getGiaVe() { 
        return giaVe; 
    }
    string getMoTaTuyen() { 
        return moTaTuyen; 
    }
};
#endif