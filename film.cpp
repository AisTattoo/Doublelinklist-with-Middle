#include <iostream>
using namespace std;

// deklarasi double linked list
struct DataFilm{
string namaFilm, durasi, asal, tahunTerbit;
DataFilm *kembali;
DataFilm *lanjut;
};

DataFilm *kepala, *ekor, *saatIni, *nodeBaru, *hapus, *setelahNode;

// Membuat Double Linked List
void createDoubleLinkedList( string data[4] ){
kepala = new DataFilm();
kepala->namaFilm = data[0];
kepala->durasi = data[1];
kepala->asal = data[2];
kepala->tahunTerbit = data[3];
kepala->kembali = NULL;
kepala->lanjut = NULL;
ekor = kepala;
}

// Mengitung Double Linked List
int countDoubleLinkedList()
{
if( kepala == NULL ){
cout << "Double Linked List belum dibuat!!!";
}else{
saatIni = kepala;
int jumlah = 0;
while( saatIni != NULL ){
jumlah++;
//step
saatIni = saatIni->lanjut;
}
return jumlah;
}
}

// Add First
void addFirst( string data[4] ){
if( kepala == NULL ){
cout << "Double Linked List belum dibuat!!!";
}else{
nodeBaru = new DataFilm();
nodeBaru->namaFilm = data[0];
nodeBaru->durasi = data[1];
nodeBaru->asal = data[2];
nodeBaru->tahunTerbit = data[3];
nodeBaru->kembali = NULL;
nodeBaru->lanjut = kepala;
kepala->kembali = nodeBaru;
kepala = nodeBaru;
}
}

// Add Last
void addLast( string data[4] ){
if( kepala == NULL ){
cout << "Double Linked List belum dibuat!!!";
}else{
nodeBaru = new DataFilm();
nodeBaru->namaFilm = data[0];
nodeBaru->durasi = data[1];
nodeBaru->asal = data[2];
nodeBaru->tahunTerbit = data[3];
nodeBaru->kembali = ekor;
nodeBaru->lanjut = NULL;
ekor->lanjut = nodeBaru;
ekor = nodeBaru;
}
}

// Add Middle
void addMiddle( string data[4], int posisi ){
if( kepala == NULL ){
cout << "Double Linked List belum dibuat!!!";
}else{if( posisi == 1 ){
  cout << "Posisi 1 itu bukan posisi tengah!!!" << endl;
}else if( posisi < 1 || posisi > countDoubleLinkedList() ){
  cout << "Posisi diluar jangkauan!!!" << endl;
}else{
  nodeBaru = new DataFilm();
  nodeBaru->namaFilm = data[0];
  nodeBaru->durasi = data[1];
  nodeBaru->asal = data[2];
  nodeBaru->tahunTerbit = data[3];

  // tranversing
  saatIni = kepala;
  int nomor = 1;
  while( nomor <  posisi - 1){
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

// remove First
void removeFirst()
{
if( kepala == NULL ){
cout << "Double Linked List belum dibuat!!!";
}else{
hapus = kepala;
kepala = kepala->lanjut;
kepala->kembali = NULL;
delete hapus;
}
}

// remove Last
void removeLast()
{
if( kepala == NULL ){
cout << "Double Linked List belum dibuat!!!";
}else{
hapus = ekor;
ekor = ekor->kembali;
ekor->lanjut = NULL;
delete hapus;
}
}

// remove Middle
void removeMiddle(int posisi){
if( kepala == NULL ){
cout << "Double Linked List belum dibuat!!!";
}else{
if( posisi == 1 || posisi == countDoubleLinkedList() ){
cout << "Posisi bukan posisi tegah!!" << endl;
}else if( posisi < 1 || posisi > countDoubleLinkedList() ){
cout << "Posisi diluar jangkauan!!" << endl;
}else{
int nomor = 1;
saatIni = kepala;
while( nomor < posisi - 1 ){
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
if( kepala == NULL ){
cout << "Double Linked List belum dibuat!!!";
}else{
cout << "Jumlah Data : " << countDoubleLinkedList() << endl;
cout << "Isi Data : " << endl;
saatIni = kepala;
while( saatIni != NULL ){
// print
cout << "Nama Film : " << saatIni->namaFilm << endl;
cout << "Durasi : " << saatIni->durasi << endl;
cout << "Asal : " << saatIni->asal << endl;
cout << "Tahun Terbit : " << saatIni->tahunTerbit << "\n" << endl;
//step
saatIni = saatIni->lanjut;
}
}
}

int main(){

string newData[4] = {"Vina", "120 menit", "Indonesia", "2023"};
createDoubleLinkedList(newData);

printDoubleLinkedList();

string data2[4] = {"Dilan 1945", "90 menit", "Indonesia", "2021"};

addFirst( data2 );

printDoubleLinkedList();

string data3[4] = {"Laskar Pelangi", "100 menit", "Indonesia", "2000"};

addLast( data3 );

printDoubleLinkedList();

string data4[4] = {"The Architecture of Love", "110 menit", "Indonesia", "2024"};
addMiddle(data4, 3);

printDoubleLinkedList();

removeMiddle(2);

printDoubleLinkedList();

}