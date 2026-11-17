#include <iostream>
#include <string>
using namespace std;

struct Node {
    string nama;
    Node* next;
};

Node* front = nullptr;
Node* rear = nullptr;
int jumlah = 0;

bool kosong() { return front == nullptr; }

void enqueue(const string& nama) {
    Node* baru = new Node{nama, nullptr};
    if (kosong()) {
        front = rear = baru;
    } else {
        rear->next = baru;
        rear = baru;
    }
    jumlah++;
    cout << "Pelanggan " << nama << " masuk antrean." << endl;
}

void dequeue() {
    if (kosong()) {
        cout << "Antrean kosong, tidak ada pelanggan yang dilayani." << endl;
        return;
    }
    Node* hapus = front;
    cout << "Melayani pelanggan: " << hapus->nama << endl;
    front = front->next;
    if (front == nullptr) rear = nullptr; // pelanggan terakhir dilayani
    delete hapus;
    jumlah--;
}

void tampilDepanBelakang() {
    if (kosong()) {
        cout << "Antrean kosong." << endl;
        return;
    }
    cout << "Pelanggan paling depan   : " << front->nama << endl;
    cout << "Pelanggan paling belakang: " << rear->nama << endl;
}

void tampilJumlah() {
    cout << "Jumlah pelanggan yang menunggu: " << jumlah << endl;
}

int main() {
    int pilihan;
    do {
        cout << "\n=== SISTEM ANTREAN ===\n"
             << "1. Tambah pelanggan\n"
             << "2. Layani pelanggan terdepan\n"
             << "3. Tampilkan pelanggan depan & belakang\n"
             << "4. Hitung jumlah pelanggan menunggu\n"
             << "0. Keluar\n"
             << "Pilihan: ";
        cin >> pilihan;
        switch (pilihan) {
            case 1: {
                string nama;
                cout << "Nama pelanggan: ";
                cin >> ws;
                getline(cin, nama);
                enqueue(nama);
                break;
            }
            case 2: dequeue(); break;
            case 3: tampilDepanBelakang(); break;
            case 4: tampilJumlah(); break;
            case 0: cout << "Program selesai." << endl; break;
            default: cout << "Pilihan tidak valid." << endl;
        }
    } while (pilihan != 0);

    while (!kosong()) {
        Node* t = front;
        front = front->next;
        delete t;
    }
    return 0;
}