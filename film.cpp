#include <iostream>
using namespace std;

// Deklarasi double linked list
struct DataFilm {
    string namaFilm;
    int durasi;
    int harga;
    DataFilm* kembali;
    DataFilm* lanjut;
};

DataFilm* kepala, * ekor, * saatIni, * nodeBaru, * hapus, * setelahNode;

// Membuat Double Linked List
void createDoubleLinkedList(string data[3]) {
    kepala = new DataFilm();
    kepala->namaFilm = data[0];
    kepala->durasi = stoi(data[1]);
    kepala->harga = stoi(data[2]);
    kepala->kembali = NULL;
    kepala->lanjut = NULL;
    ekor = kepala;
}

// Menghitung Double Linked List
int countDoubleLinkedList()
{
    if (kepala == NULL) {
        cout << "Double Linked List belum dibuat!!!";
    }
    else {
        saatIni = kepala;
        int jumlah = 0;
        while (saatIni != NULL) {
            jumlah++;
            //step
            saatIni = saatIni->lanjut;
        }
        return jumlah;
    }
}

// Add First
void addFirst(string data[3]) {
    if (kepala == NULL) {
        cout << "Double Linked List belum dibuat!!!";
    }
    else {
        nodeBaru = new DataFilm();
        nodeBaru->namaFilm = data[0];
        nodeBaru->durasi = stoi(data[1]);
        nodeBaru->harga = stoi(data[2]);
        nodeBaru->kembali = NULL;
        nodeBaru->lanjut = kepala;
        kepala->kembali = nodeBaru;
        kepala = nodeBaru;
    }
}

// Add Last
void addLast(string data[3]) {
    if (kepala == NULL) {
        cout << "Double Linked List belum dibuat!!!";
    }
    else {
        nodeBaru = new DataFilm();
        nodeBaru->namaFilm = data[0];
        nodeBaru->durasi = stoi(data[1]);
        nodeBaru->harga = stoi(data[2]);
        nodeBaru->kembali = ekor;
        nodeBaru->lanjut = NULL;
        ekor->lanjut = nodeBaru;
        ekor = nodeBaru;
    }
}

// Add Middle
void addMiddle(string data[3], int posisi) {
    if (kepala == NULL) {
        cout << "Double Linked List belum dibuat!!!";
    }
    else {
        if (posisi == 1) {
            cout << "Posisi 1 itu bukan posisi tengah!!!" << endl;
        }
        else if (posisi < 1 || posisi > countDoubleLinkedList()) {
            cout << "Posisi diluar jangkauan!!!" << endl;
        }
        else {
            nodeBaru = new DataFilm();
            nodeBaru->namaFilm = data[0];
            nodeBaru->durasi = stoi(data[1]);
            nodeBaru->harga = stoi(data[2]);

            // Tranversing
            saatIni = kepala;
            int nomor = 1;
            while (nomor < posisi - 1) {
                saatIni = saatIni->lanjut;
                nomor++;
            }

            setelahNode = saatIni->lanjut;
            nodeBaru->kembali = saatIni;
            nodeBaru->lanjut = setelahNode;
            saatIni->lanjut = nodeBaru;
            setelahNode->kembali = nodeBaru;
        }
    }
}

// Remove First
void removeFirst()
{
    if (kepala == NULL) {
        cout << "Double Linked List belum dibuat!!!";
    }
    else {
        hapus = kepala;
        kepala = kepala->lanjut;
        kepala->kembali = NULL;
        delete hapus;
    }
}

// Remove Last
void removeLast()
{
    if (kepala == NULL) {
        cout << "Double Linked List belum dibuat!!!";
    }
    else {
        hapus = ekor;
        ekor = ekor->kembali;
        ekor->lanjut = NULL;
        delete hapus;
    }
}

// Remove Middle
void removeMiddle(int posisi) {
    if (kepala == NULL) {
        cout << "Double Linked List belum dibuat!!!";
    }
    else {
        if (posisi == 1 || posisi == countDoubleLinkedList()) {
            cout << "Posisi bukan posisi tengah!!" << endl;
        }
        else if (posisi < 1 || posisi > countDoubleLinkedList()) {
            cout << "Posisi diluar jangkauan!!" << endl;
        }
        else {
            int nomor = 1;
            saatIni = kepala;
            while (nomor < posisi - 1) {
                saatIni = saatIni->lanjut;
                nomor++;
            }
            hapus = saatIni->lanjut;
            setelahNode = hapus->lanjut;
            saatIni->lanjut = setelahNode;
            setelahNode->kembali = saatIni;
            delete hapus;
        }
    }
}

// Print Double Linked List
void printDoubleLinkedList()
{
    if (kepala == NULL) {
        cout << "Double Linked List belum dibuat!!!";
    }
    else {
        cout << "Jumlah Data : " << countDoubleLinkedList() << endl;
        cout << "Isi Data : " << endl;
        saatIni = kepala;
        while (saatIni != NULL) {
            // print
            cout << "Nama Film : " << saatIni->namaFilm << endl;
            cout << "Durasi : " << saatIni->durasi << " menit" << endl;
            cout << "Harga : Rp. " << saatIni->harga << endl;
            cout << "\n";
            //step
            saatIni = saatIni->lanjut;
        }
    }
}

int main() {

    string newData[3] = { "Vina", "120", "50000" };
    createDoubleLinkedList(newData);

    printDoubleLinkedList();

    string data2[3] = { "Dilan 1945", "90", "35000" };
    addFirst(data2);

    printDoubleLinkedList();

    string data3[3] = { "Laskar Pelangi", "100", "45000" };
    addLast(data3);

    printDoubleLinkedList();

    string data4[3] = { "The Architecture of Love", "110", "55000" };
    addMiddle(data4, 3);

    printDoubleLinkedList();

    removeMiddle(2);

    printDoubleLinkedList();

    return 0;
}