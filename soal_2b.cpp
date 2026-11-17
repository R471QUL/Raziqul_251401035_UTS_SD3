#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* head = nullptr;

void tambahBelakang(int nilai) {
    Node* baru = new Node{nilai, nullptr};
    if (head == nullptr) {
        head = baru;
        return;
    }
    Node* bantu = head;
    while (bantu->next != nullptr) bantu = bantu->next;
    bantu->next = baru;
}

void tampil() {
    if (head == nullptr) {
        cout << "Linked list kosong." << endl;
        return;
    }
    cout << "Isi linked list: ";
    for (Node* p = head; p != nullptr; p = p->next) {
        cout << p->data;
        if (p->next != nullptr) cout << " -> ";
    }
    cout << " -> NULL" << endl;
}

// Hapus node tepat setelah node bernilai 'nilai'
void hapusSetelah(int nilai) {
    Node* p = head;
    while (p != nullptr && p->data != nilai) p = p->next;

    if (p == nullptr) {
        cout << "Nilai " << nilai << " tidak ditemukan." << endl;
        return;
    }
    if (p->next == nullptr) {
        cout << "Nilai " << nilai << " tidak memiliki node setelahnya." << endl;
        return;
    }
    Node* hapus = p->next;
    p->next = hapus->next;
    cout << "Node " << hapus->data << " (setelah " << nilai << ") dihapus." << endl;
    delete hapus;
}

// Balik urutan node tanpa membuat list baru (ubah arah pointer)
void balik() {
    Node* prev = nullptr;
    Node* curr = head;
    while (curr != nullptr) {
        Node* nxt = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nxt;
    }
    head = prev;
    cout << "Linked list berhasil dibalik." << endl;
}

void hapusSemua() {
    while (head != nullptr) {
        Node* t = head;
        head = head->next;
        delete t;
    }
}

int main() {
    int n;
    cout << "Banyak bilangan yang akan dimasukkan: ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x;
        cout << "Bilangan ke-" << i + 1 << ": ";
        cin >> x;
        tambahBelakang(x);
    }

    int pilihan;
    do {
        cout << "\n=== MENU ===\n"
             << "1. Tampilkan data\n"
             << "2. Hapus node setelah nilai tertentu\n"
             << "3. Balik urutan linked list\n"
             << "0. Keluar\n"
             << "Pilihan: ";
        cin >> pilihan;
        switch (pilihan) {
            case 1: tampil(); break;
            case 2: {
                int v;
                cout << "Hapus node setelah nilai: ";
                cin >> v;
                hapusSetelah(v);
                break;
            }
            case 3: balik(); break;
            case 0: cout << "Program selesai." << endl; break;
            default: cout << "Pilihan tidak valid." << endl;
        }
    } while (pilihan != 0);

    hapusSemua();
    return 0;
}