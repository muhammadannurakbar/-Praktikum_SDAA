#include <iostream>
using namespace std;

int hitungNilaiPascal(int baris, int kolom) {
    if (kolom == 0 || kolom == baris) {
        return 1;
    } else {
        return hitungNilaiPascal(baris - 1, kolom - 1) + hitungNilaiPascal(baris - 1, kolom);
    }
}

void cetakSegitigaSikuPascal(int tingkat) {
    for (int baris = 0; baris < tingkat; baris++) {
        for (int kolom = 0; kolom <= baris; kolom++) {
            int nilai = hitungNilaiPascal(baris, kolom);
            cout << nilai << " ";  // tambahkan spasi agar rapi
        }
        cout << endl;
    }
}

int main() {
    int jumlahTingkat = 3;  // Anda bisa mengubah jumlah tingkat sesuai keinginan
    cout << "Segitiga Pascal dengan " << jumlahTingkat << " tingkat:" << endl;
    cetakSegitigaSikuPascal(jumlahTingkat);
    return 0;
}
