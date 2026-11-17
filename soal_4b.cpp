#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* kiri;
    Node* kanan;
};

Node* buatNode(int nilai) {
    return new Node{nilai, nullptr, nullptr};
}

Node* insert(Node* root, int nilai) {
    if (root == nullptr) return buatNode(nilai);
    if (nilai < root->data) root->kiri = insert(root->kiri, nilai);
    else if (nilai > root->data) root->kanan = insert(root->kanan, nilai);
    // nilai duplikat diabaikan
    return root;
}

// Inorder dengan pemangkasan: tampilkan nilai dalam [bawah, atas] dari kecil ke besar
void tampilRentang(Node* root, int bawah, int atas, bool& ada) {
    if (root == nullptr) return;
    if (root->data > bawah) tampilRentang(root->kiri, bawah, atas, ada);
    if (root->data >= bawah && root->data <= atas) {
        cout << root->data << " ";
        ada = true;
    }
    if (root->data < atas) tampilRentang(root->kanan, bawah, atas, ada);
}

bool cari(Node* root, int nilai) {
    while (root != nullptr) {
        if (nilai == root->data) return true;
        root = (nilai < root->data) ? root->kiri : root->kanan;
    }
    return false;
}

void hapusTree(Node* root) {
    if (root == nullptr) return;
    hapusTree(root->kiri);
    hapusTree(root->kanan);
    delete root;
}

int main() {
    Node* root = nullptr;
    int x;

    cout << "Masukkan bilangan bulat (-1 untuk berhenti):" << endl;
    while (true) {
        cout << "> ";
        cin >> x;
        if (x == -1) break;
        root = insert(root, x);
    }

    if (root == nullptr) {
        cout << "BST kosong." << endl;
        return 0;
    }

    int bawah, atas;
    cout << "Batas bawah: ";
    cin >> bawah;
    cout << "Batas atas : ";
    cin >> atas;
    if (bawah > atas) swap(bawah, atas);

    cout << "Nilai dalam rentang [" << bawah << ", " << atas << "]: ";
    bool ada = false;
    tampilRentang(root, bawah, atas, ada);
    if (!ada) cout << "(tidak ada)";
    cout << endl;

    int cariNilai;
    cout << "Masukkan nilai yang ingin diperiksa: ";
    cin >> cariNilai;
    if (cari(root, cariNilai))
        cout << "Nilai " << cariNilai << " ADA di dalam BST." << endl;
    else
        cout << "Nilai " << cariNilai << " TIDAK ADA di dalam BST." << endl;

    hapusTree(root);
    return 0;
}