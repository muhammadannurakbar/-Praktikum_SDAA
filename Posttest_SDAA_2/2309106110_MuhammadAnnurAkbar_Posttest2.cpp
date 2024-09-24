#include <iostream>
#include <cstring>
using namespace std;

struct PenghuniAsrama {
    int nomorKTM;            
    char namaPenghuni[50];   
    int usiaPenghuni;        
    char alamatPenghuni[100];
};

void tambahPenghuni(PenghuniAsrama *daftarPenghuni, int *totalPenghuni) {
    PenghuniAsrama penghuniBaru;
    
    cout << "Masukkan Nomor KTM penghuni: ";
    cin >> penghuniBaru.nomorKTM;
    cout << "Masukkan nama penghuni: ";
    cin.ignore();
    cin.getline(penghuniBaru.namaPenghuni, 50);
    cout << "Masukkan usia penghuni: ";
    cin >> penghuniBaru.usiaPenghuni;
    cout << "Masukkan alamat penghuni: ";
    cin.ignore();
    cin.getline(penghuniBaru.alamatPenghuni, 100);
    
    daftarPenghuni[*totalPenghuni] = penghuniBaru;
    (*totalPenghuni)++;
    
    cout << "Penghuni baru berhasil ditambahkan!" << endl;
}

void lihatPenghuni(PenghuniAsrama *daftarPenghuni, int totalPenghuni) {
    if (totalPenghuni == 0) {
        cout << "Belum ada penghuni yang terdaftar." << endl;
        return;
    }

    cout << "Daftar Penghuni Asrama Putra:" << endl;
    for (int i = 0; i < totalPenghuni; i++) {
        cout << "Nomor KTM: " << daftarPenghuni[i].nomorKTM << endl;
        cout << "Nama: " << daftarPenghuni[i].namaPenghuni << endl;
        cout << "Usia: " << daftarPenghuni[i].usiaPenghuni << endl;
        cout << "Alamat: " << daftarPenghuni[i].alamatPenghuni << endl;
        cout << "-----------------------" << endl;
    }
}

void editPenghuni(PenghuniAsrama *daftarPenghuni, int totalPenghuni) {
    int nomorKTM, ditemukan = 0;
    
    cout << "Masukkan Nomor KTM penghuni yang ingin diedit: ";
    cin >> nomorKTM;
    
    for (int i = 0; i < totalPenghuni; i++) {
        if (daftarPenghuni[i].nomorKTM == nomorKTM) {
            ditemukan = 1;
            cout << "Masukkan nama baru: ";
            cin.ignore();
            cin.getline(daftarPenghuni[i].namaPenghuni, 50);
            cout << "Masukkan usia baru: ";
            cin >> daftarPenghuni[i].usiaPenghuni;
            cout << "Masukkan alamat baru: ";
            cin.ignore();
            cin.getline(daftarPenghuni[i].alamatPenghuni, 100);
            cout << "Data penghuni berhasil diperbarui!" << endl;
            break;
        }
    }

    if (!ditemukan) {
        cout << "Penghuni dengan Nomor KTM " << nomorKTM << " tidak ditemukan." << endl;
    }
}

void hapusPenghuni(PenghuniAsrama *daftarPenghuni, int *totalPenghuni) {
    int nomorKTM, ditemukan = 0;
    
    cout << "Masukkan Nomor KTM penghuni yang ingin dihapus: ";
    cin >> nomorKTM;
    
    for (int i = 0; i < *totalPenghuni; i++) {
        if (daftarPenghuni[i].nomorKTM == nomorKTM) {
            ditemukan = 1;
            for (int j = i; j < (*totalPenghuni) - 1; j++) {
                daftarPenghuni[j] = daftarPenghuni[j + 1];
            }
            (*totalPenghuni)--;
            cout << "Penghuni berhasil dihapus!" << endl;
            break;
        }
    }

    if (!ditemukan) {
        cout << "Penghuni dengan Nomor KTM " << nomorKTM << " tidak ditemukan." << endl;
    }
}

int main() {
    PenghuniAsrama daftarPenghuni[100];
    int totalPenghuni = 0;
    int pilihanMenu;
    
    do {
        cout << "=== Sistem Pendaftaran Penghuni Asrama Putra ===" << endl;
        cout << "1. Tambah Penghuni Asrama" << endl;
        cout << "2. Lihat Daftar Penghuni" << endl;
        cout << "3. Edit Data Penghuni" << endl;
        cout << "4. Hapus Penghuni Asrama" << endl;
        cout << "5. Keluar" << endl;
        cout << "Pilih menu: ";
        cin >> pilihanMenu;
        
        switch (pilihanMenu) {
            case 1:
                tambahPenghuni(daftarPenghuni, &totalPenghuni);
                break;
            case 2:
                lihatPenghuni(daftarPenghuni, totalPenghuni);
                break;
            case 3:
                editPenghuni(daftarPenghuni, totalPenghuni);
                break;
            case 4:
                hapusPenghuni(daftarPenghuni, &totalPenghuni);
                break;
            case 5:
                cout << "Terima kasih! program selesai :)." << endl;
                break;
            default:
                cout << "Pilihan tidak valid. Silakan coba lagi." << endl;
        }
    } while (pilihanMenu != 5);
    
    return 0;
}
