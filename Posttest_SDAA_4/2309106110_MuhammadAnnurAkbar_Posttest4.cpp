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

void tambahPenghuniData(PenghuniAsrama** daftarPenghuni) {
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
}

void push(PenghuniAsrama** stack) {
    tambahPenghuniData(stack);
    cout << "Penghuni berhasil ditambahkan ke Stack!" << endl;
}

void pop(PenghuniAsrama** stack) {
    if (*stack == nullptr) {
        cout << "Stack kosong, tidak ada penghuni yang bisa dihapus!" << endl;
        return;
    }
    
    PenghuniAsrama* penghuniDihapus = *stack;
    *stack = (*stack)->next;
    delete penghuniDihapus;
    cout << "Penghuni berhasil dihapus dari Stack!" << endl;
}

void enqueue(PenghuniAsrama** queue) {
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
    
    penghuniBaru->next = nullptr;

    if (*queue == nullptr) {
        *queue = penghuniBaru;
    } else {
        PenghuniAsrama* penghuniSaatIni = *queue;
        while (penghuniSaatIni->next != nullptr) {
            penghuniSaatIni = penghuniSaatIni->next;
        }
        penghuniSaatIni->next = penghuniBaru;
    }
    cout << "Penghuni berhasil ditambahkan ke Queue!" << endl;
}

void dequeue(PenghuniAsrama** queue) {
    if (*queue == nullptr) {
        cout << "Queue kosong, tidak ada penghuni yang bisa dihapus!" << endl;
        return;
    }

    PenghuniAsrama* penghuniSaatIni = *queue;
    PenghuniAsrama* penghuniSebelumnya = nullptr;

    while (penghuniSaatIni->next != nullptr) {
        penghuniSebelumnya = penghuniSaatIni;
        penghuniSaatIni = penghuniSaatIni->next;
    }

    if (penghuniSebelumnya != nullptr) {
        penghuniSebelumnya->next = nullptr;
    } else {
        *queue = nullptr;
    }

    delete penghuniSaatIni;
    cout << "Penghuni berhasil dihapus dari Queue!" << endl;
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

int main() {
    PenghuniAsrama* stack = nullptr; 
    PenghuniAsrama* queue = nullptr; 
    int pilihanMenu;

    do {
        cout << "=== Sistem Pendaftaran Penghuni Asrama ===" << endl;
        cout << "1. Tambah Penghuni ke Stack" << endl;
        cout << "2. Hapus Penghuni dari Stack (Pop)" << endl;
        cout << "3. Lihat Penghuni di Stack" << endl;
        cout << "4. Tambah Penghuni ke Queue" << endl;
        cout << "5. Hapus Penghuni dari Queue (Dequeue)" << endl;
        cout << "6. Lihat Penghuni di Queue" << endl;
        cout << "7. Keluar" << endl;
        cout << "Pilih menu: ";
        cin >> pilihanMenu;

        switch (pilihanMenu) {
            case 1:
                push(&stack);
                break;
            case 2:
                pop(&stack);
                break;
            case 3:
                lihatPenghuni(stack);
                break;
            case 4:
                enqueue(&queue);
                break;
            case 5:
                dequeue(&queue);
                break;
            case 6:
                lihatPenghuni(queue);
                break;
            case 7:
                cout << "Terima kasih! Program selesai." << endl;
                break;
            default:
                cout << "Pilihan tidak valid. Silakan coba lagi." << endl;
        }
    } while (pilihanMenu != 7);

    return 0;
}