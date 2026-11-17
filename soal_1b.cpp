#include <iostream>
#include <iomanip>
using namespace std;

const int MHS = 5;
const int KOMP = 4;

int main() {
    string komponen[KOMP] = {"Tugas", "Kuis", "UTS", "Praktikum"};
    double nilai[MHS][KOMP];
    double rata[MHS];

    // Input nilai
    for (int i = 0; i < MHS; i++) {
        cout << "Mahasiswa ke-" << i + 1 << endl;
        for (int j = 0; j < KOMP; j++) {
            cout << "  Nilai " << komponen[j] << ": ";
            cin >> nilai[i][j];
        }
    }

    // Hitung rata-rata, cari tertinggi/terendah, hitung yang >= 75
    int idxMax = 0, idxMin = 0, jumlahLulus = 0;
    for (int i = 0; i < MHS; i++) {
        double total = 0;
        for (int j = 0; j < KOMP; j++) total += nilai[i][j];
        rata[i] = total / KOMP;

        if (rata[i] > rata[idxMax]) idxMax = i;
        if (rata[i] < rata[idxMin]) idxMin = i;
        if (rata[i] >= 75) jumlahLulus++;
    }

    cout << fixed << setprecision(2);
    cout << "\n=== Rata-rata Nilai Setiap Mahasiswa ===\n";
    for (int i = 0; i < MHS; i++)
        cout << "Mahasiswa " << i + 1 << ": " << rata[i] << endl;

    cout << "\nRata-rata tertinggi : Mahasiswa " << idxMax + 1
         << " (" << rata[idxMax] << ")" << endl;
    cout << "Rata-rata terendah  : Mahasiswa " << idxMin + 1
         << " (" << rata[idxMin] << ")" << endl;
    cout << "Jumlah mahasiswa dengan rata-rata >= 75: " << jumlahLulus << endl;

    return 0;
}