#include <iostream>
#include <cstring>
using namespace std;

struct PenghuniAsrama {
    int nomorKTM;             
    char namaPenghuni[50];
    int usiaPenghuni;  
    char alamatPenghuni[100]; 
    
    PenghuniAsrama* next; 
};

void tambahPenghuni(PenghuniAsrama** daftarPenghuni) {
    PenghuniAsrama* penghuniBaru = new PenghuniAsrama;
    
    cout << "Masukkan Nomor KTM penghuni: ";
    cin >> penghuniBaru->nomorKTM;
    cout << "Masukkan nama penghuni: ";
    cin.ignore();
    cin.getline(penghuniBaru->namaPenghuni, 50);
    cout << "Masukkan usia penghuni: ";
    cin >> penghuniBaru->usiaPenghuni;
    cout << "Masukkan alamat penghuni: ";
    cin.ignore();
    cin.getline(penghuniBaru->alamatPenghuni, 100);
    
    penghuniBaru->next = *daftarPenghuni;
    *daftarPenghuni = penghuniBaru;
    
    cout << "Penghuni baru berhasil ditambahkan!" << endl;
}

void lihatPenghuni(PenghuniAsrama* daftarPenghuni) {

    if (daftarPenghuni == nullptr) {
        cout << "Belum ada penghuni yang terdaftar." << endl;
        return;
    }

    PenghuniAsrama* penghuniSaatIni = daftarPenghuni;
    cout << "Daftar Penghuni Asrama:" << endl;
    while (penghuniSaatIni != nullptr) {
        cout << "Nomor KTM: " << penghuniSaatIni->nomorKTM << endl;
        cout << "Nama: " << penghuniSaatIni->namaPenghuni << endl;
        cout << "Usia: " << penghuniSaatIni->usiaPenghuni << endl;
        cout << "Alamat: " << penghuniSaatIni->alamatPenghuni << endl;
        cout << "-----------------------" << endl;
        penghuniSaatIni = penghuniSaatIni->next;
    }
}

void editPenghuni(PenghuniAsrama* daftarPenghuni) {
    int nomorKTM;
    cout << "Masukkan Nomor KTM penghuni yang ingin diedit: ";
    cin >> nomorKTM;
    
    PenghuniAsrama* penghuniSaatIni = daftarPenghuni;
    
    while (penghuniSaatIni != nullptr) {
        if (penghuniSaatIni->nomorKTM == nomorKTM) {
            cout << "Masukkan nama baru: ";
            cin.ignore();
            cin.getline(penghuniSaatIni->namaPenghuni, 50);
            cout << "Masukkan usia baru: ";
            cin >> penghuniSaatIni->usiaPenghuni;
            cout << "Masukkan alamat baru: ";
            cin.ignore();
            cin.getline(penghuniSaatIni->alamatPenghuni, 100);
            cout << "Data penghuni berhasil diperbarui!" << endl;
            return;
        }
        penghuniSaatIni = penghuniSaatIni->next;
    }

    cout << "Penghuni dengan Nomor KTM " << nomorKTM << " tidak ditemukan." << endl;
}

void hapusPenghuni(PenghuniAsrama** daftarPenghuni) {
    int nomorKTM;
    cout << "Masukkan Nomor KTM penghuni yang ingin dihapus: ";
    cin >> nomorKTM;
    
    PenghuniAsrama* penghuniSaatIni = *daftarPenghuni;
    PenghuniAsrama* penghuniSebelumnya = nullptr;

    while (penghuniSaatIni != nullptr && penghuniSaatIni->nomorKTM != nomorKTM) {
        penghuniSebelumnya = penghuniSaatIni;
        penghuniSaatIni = penghuniSaatIni->next;
    }
    
    if (penghuniSaatIni == nullptr) {
        cout << "Penghuni dengan Nomor KTM " << nomorKTM << " tidak ditemukan." << endl;
        return;
    }

    if (penghuniSebelumnya == nullptr) {
        *daftarPenghuni = penghuniSaatIni->next;
    } else {
        penghuniSebelumnya->next = penghuniSaatIni->next;
    }

    delete penghuniSaatIni;
    cout << "Penghuni berhasil dihapus!" << endl;
}

int main() {
    PenghuniAsrama* daftarPenghuni = nullptr; 
    int pilihanMenu;
    
    do {
        cout << "=== Sistem Pendaftaran Penghuni Asrama ===" << endl;
        cout << "1. Tambah Penghuni Asrama" << endl;
        cout << "2. Lihat Daftar Penghuni" << endl;
        cout << "3. Edit Data Penghuni" << endl;
        cout << "4. Hapus Penghuni Asrama" << endl;
        cout << "5. Keluar" << endl;
        cout << "Pilih menu: ";
        cin >> pilihanMenu;
        
        switch (pilihanMenu) {
            case 1:
                tambahPenghuni(&daftarPenghuni);
                break;
            case 2:
                lihatPenghuni(daftarPenghuni);
                break;
            case 3:
                editPenghuni(daftarPenghuni);
                break;
            case 4:
                hapusPenghuni(&daftarPenghuni);
                break;
            case 5:
                cout << "Terima kasih! Program selesai dehh hehe." << endl;
                break;
            default:
                cout << "Pilihan tidak valid. Silakan coba lagi." << endl;
        }
    } while (pilihanMenu != 5);
    
    return 0;
}
