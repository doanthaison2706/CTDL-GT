#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include"phuongtien.cpp"

using namespace std;

#ifndef DANH_SACH_PHUONG_TIEN_CPP
#define DANH_SACH_PHUONG_TIEN_CPP

class DanhSachPhuongTien {
private:
    vector<PhuongTienCongCong> danhSachPhuongTien;
public:
    // Thêm phương tiện mới vào danh sách
    void themPhuongTien(PhuongTienCongCong &phuongTien) {
        danhSachPhuongTien.push_back(phuongTien);
    }
    // Đọc danh sách từ file
    void docFile(const string &tenFile) {
        ifstream file(tenFile);
        if (!file) {
            cout << "Khong the mo file!" << endl;
            return;
        }
        PhuongTienCongCong phuongTien("", "", 0, 0.0, 0.0, "");
        while (phuongTien.docTuFile(file)) {
            themPhuongTien(phuongTien);
        }
        file.close();
    }
    // Hiển thị danh sách phương tiện
    void hienThiDanhSach() {
        if (danhSachPhuongTien.empty()) {
            cout << "Danh sach rong!" << endl;
            return;
        }
        cout << "\nDanh sach phuong tien:\n" << endl;
        for (int i = 0; i < danhSachPhuongTien.size(); i++) {
            cout << danhSachPhuongTien[i] << endl;  
        }
    }
    // Lưu danh sách vào file
    void xuatFile(string &tenFile) {
        if (danhSachPhuongTien.empty()) {
            cout << "Danh sach rong!" << endl;
            return;
        }
        ofstream file(tenFile);
        if (!file) {
            cout << "Khong the mo file!" << endl;
            return;
        }
        for (int i = 0; i < danhSachPhuongTien.size(); i++) {
            file << danhSachPhuongTien[i];  
        }
        file.close();
    }
    // Sắp xếp phương tiện theo khoảng cách
    void sapXepPhuongTien() {
        if (danhSachPhuongTien.empty()) {
            cout << "Danh sach rong!" << endl;
            return;
        }
        sort(danhSachPhuongTien.begin(), danhSachPhuongTien.end());
    }
    // Tìm phương tiện theo số hiệu tuyến
    PhuongTienCongCong* timPhuongTien(string &soHieuTuyen) {
        if (danhSachPhuongTien.empty()) {
            cout << "Danh sach rong!" << endl;
            return nullptr;
        }
        for (int i = 0; i < danhSachPhuongTien.size(); i++) {
            if (danhSachPhuongTien[i].getSoHieuTuyen() == soHieuTuyen) {
                cout << "Phuong tien tim thay:\n" << danhSachPhuongTien[i] << endl;
                return &danhSachPhuongTien[i];
            }
        }
        cout << "Khong tim thay!" << endl;
        return nullptr;
    }
    // Xóa phương tiện theo số hiệu tuyến
    void xoaPhuongTien(const string &soHieuTuyen) {
        if (danhSachPhuongTien.empty()) {
            cout << "Danh sach rong. Khong co phuong tien de xoa." << endl;
            return;
        }
        bool timThay = false;
        vector<PhuongTienCongCong> danhSachMoi;
        for (int i = 0; i < danhSachPhuongTien.size(); i++) {
            if (danhSachPhuongTien[i].getSoHieuTuyen() != soHieuTuyen) {
                danhSachMoi.push_back(danhSachPhuongTien[i]);
            } else {
                timThay = true;
            }
        }
        danhSachPhuongTien = danhSachMoi;
        if (timThay) {
            cout << "Phuong tien co so hieu tuyen " << soHieuTuyen << " da duoc xoa thanh cong." << endl;
        } else {
            cout << "Phuong tien co so hieu tuyen " << soHieuTuyen << " khong tim thay." << endl;
        }
    }
    // Cập nhật thông tin phương tiện
    void capNhatThongTinPhuongTien() {
        if (danhSachPhuongTien.empty()) {
            cout << "Danh sach rong!" << endl;
            return;
        }
        string loaiPhuongTien, soHieuTuyen;
        cout << "Nhap loai phuong tien can cap nhat: ";
        cin >> loaiPhuongTien;
        cout << "Nhap so hieu tuyen phuong tien can cap nhat: ";
        cin >> soHieuTuyen;
        for (int i = 0; i < danhSachPhuongTien.size(); i++) {
            if (danhSachPhuongTien[i].getLoaiPhuongTien() == loaiPhuongTien && danhSachPhuongTien[i].getSoHieuTuyen() == soHieuTuyen) {
                cout << "Phuong tien tim thay:\n" << danhSachPhuongTien[i] << endl;
                while (true) {
                    cout << "\nBan muon cap nhat thong tin nao?\n";
                    cout << "1. Suc chua\n";
                    cout << "2. Khoang cach\n";
                    cout << "3. Gia ve\n";
                    cout << "4. Mo ta tuyen\n";
                    cout << "5. Hoan tat (Ket thuc cap nhat)\n";
                    cout << "Nhap lua chon cua ban (1-5): ";
                    int luaChon;
                    cin >> luaChon;
                    switch (luaChon) {
                        case 1: {
                            int sucChuaMoi;
                            cout << "Nhap suc chua moi: ";
                            cin >> sucChuaMoi;
                            if (sucChuaMoi <= 0) {
                                cout << "Suc chua khong hop le! Phai lon hon 0.\n";
                            } else {
                                danhSachPhuongTien[i].setSucChua(sucChuaMoi);
                            }
                            break;
                        }
                        case 2: {
                            double khoangCachMoi;
                            cout << "Nhap khoang cach moi: ";
                            cin >> khoangCachMoi;
                            danhSachPhuongTien[i].setQuangDuong(khoangCachMoi);
                            break;
                        }
                        case 3: {
                            double giaVeMoi;
                            cout << "Nhap gia ve moi: ";
                            cin >> giaVeMoi;
                            danhSachPhuongTien[i].setGiaVe(giaVeMoi);
                            break;
                        }
                        case 4: {
                            string moTaTuyenMoi;
                            cout << "Nhap mo ta tuyen moi: ";
                            cin.ignore();
                            getline(cin, moTaTuyenMoi);
                            danhSachPhuongTien[i].setMoTaTuyen(moTaTuyenMoi);
                            break;
                        }
                        case 5:
                            cout << "Cap nhat hoan tat.\n";
                            cout << "\nThong tin phuong tien da cap nhat:\n" << danhSachPhuongTien[i] << endl;
                            return;
                        default:
                            cout << "Lua chon khong hop le! Vui long thu lai.\n";
                            break;
                    }
                }
            }
        }
        cout << "Khong tim thay phuong tien co loai \"" << loaiPhuongTien << "\" va so hieu tuyen \"" << soHieuTuyen << "\"!" << endl;
    }
};
#endif 