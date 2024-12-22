/* File       : main.c */
/* Deskripsi  : aplikasi driver ADT list berkait, representasi fisik pointer */
/* NIM & Nama : 24060123130115 & Sulhan Fuadi */
/* Tanggal    : 01 November 2024 */

#include <stdio.h>
#include <stdlib.h>
#include "list1.c"

int main() {
  /* Kamus */
  address P, R;
  List1 Senarai, Senarai2, SenaraiGabu, Senarai1, Senarai3, SenaraiSalin;
  infotype V;

  /* Algoritma */
  // Membuat list dan mengisi elemen list 
  printf("=== Inisialisasi dan Menampilkan List ===\n");
  CreateList(&Senarai);
  InsertVLast(&Senarai, 'K');
  InsertVLast(&Senarai, 'L');
  InsertVLast(&Senarai, 'M');
  InsertVLast(&Senarai, 'N');
  InsertVLast(&Senarai, 'O');
  printf("Isi Senarai Awal: ");
  PrintList(Senarai);
  printf("\n");

  // Menambahkan elemen di awal dan akhir list
  printf("\n=== Menambah Elemen di Awal dan Akhir ===\n");
  InsertVFirst(&Senarai, 'J');
  InsertVFirst(&Senarai, 'I');
  InsertVLast(&Senarai, 'P');
  InsertVLast(&Senarai, 'Q');
  printf("Isi Senarai setelah penambahan elemen: ");
  PrintList(Senarai);
  printf("\n");

  // Menghapus elemen pertama dan terakhir list
  printf("\n=== Menghapus Elemen Pertama dan Terakhir ===\n");
  DeleteVFirst(&Senarai, &V);
  printf("Elemen pertama yang dihapus: %c\n", V);
  DeleteVLast(&Senarai, &V);
  printf("Elemen terakhir yang dihapus: %c\n", V);
  printf("Isi Senarai setelah penghapusan: ");
  PrintList(Senarai);
  printf("\n");

  // Mencari elemen dalam list
  printf("\n=== Pencarian Elemen ===\n");
  SearchX(Senarai, 'K', P);
  if (P != NIL) {
    printf("Elemen 'K' ditemukan\n");
  } else {
    printf("Elemen 'K' tidak ditemukan\n");
  }
  SearchX(Senarai, 'I', R);
  if (R != NIL) {
    printf("Elemen 'I' ditemukan\n");
  } else {
    printf("Elemen 'I' tidak ditemukan\n");
  }

  // Update elemen tertentu X
  printf("\n=== Memperbarui Elemen ===\n");
  UpdateX(&Senarai, 'J', 'A');
  UpdateX(&Senarai, 'P', 'Z');
  printf("Isi Senarai setelah UpdateX (J -> A, P -> Z): ");
  PrintList(Senarai);
  printf("\n");

  // Membalik urutan elemen
  printf("\n=== Membalik Urutan Elemen ===\n");
  Invers(&Senarai);
  printf("Isi Senarai setelah Invers: ");
  PrintList(Senarai);
  printf("\n");

  // Menambah kemunculan elemen tertentu X dan menghitung jumlahnya
  printf("\n=== Menghitung Kemunculan Elemen 'Z' ===\n");
  InsertVFirst(&Senarai, 'Z');
  InsertVLast(&Senarai, 'Z');
  printf("Isi Senarai setelah menambahkan 'Z': ");
  PrintList(Senarai);
  printf("\n");
  printf("Jumlah kemunculan 'Z': %d\n", CountX(Senarai, 'Z'));

  // Menghitung frekuensi kemunculan elemen 'Z' di list
  printf("\n=== Menghitung Frekuensi Kemunculan Elemen 'Z' ===\n");
  printf("Frekuensi kemunculan 'Z': %.2f\n", FrekuensiX(Senarai, 'Z'));

  // Menampilkan semua posisi elemen 'Z' di list
  printf("\n=== Menampilkan Posisi Kemunculan Elemen 'Z' ===\n");
  printf("Posisi kemunculan 'Z' dalam Senarai: ");
  SearchAllX(Senarai, 'Z');
  printf("\n");

  // Mengupdate semua kemunculan 'Z' menjadi 'A' di list
  printf("\n=== Memperbarui Semua Elemen 'Z' Menjadi 'A' ===\n");
  UpdateAllX(&Senarai, 'Z', 'A');
  printf("Isi Senarai setelah UpdateAllX (Z -> A): ");
  PrintList(Senarai);
  printf("\n");

  // InsertVAfter dan menghitung kemunculan terbanyak
  printf("\n=== Menambah Elemen Setelah Elemen Tertentu ===\n");
  InsertVAfter(&Senarai, 'M', 'N');
  printf("Isi Senarai setelah InsertVAfter (M->N): ");
  PrintList(Senarai);
  printf("\n");

  printf("\n=== Menghitung Elemen yang Paling Banyak Muncul ===\n");
  printf("Jumlah elemen yang paling banyak muncul: %d\n", MaxMember(Senarai));

  // Modus elemen di list
  printf("\n=== Menampilkan Modus Elemen ===\n");
  printf("Modus elemen dalam Senarai: %c\n", Modus(Senarai));

  // Menggabungkan dua list
  printf("\n=== Menggabungkan Dua List ===\n");
  CreateList(&Senarai2);
  InsertVLast(&Senarai2, 'B');
  InsertVLast(&Senarai2, 'C');
  InsertVLast(&Senarai2, 'D');
  ConcatList(Senarai, Senarai2, &SenaraiGabu);
  printf("Isi Senarai Gabungan setelah ConcatList: ");
  PrintList(SenaraiGabu);
  printf("\n");

  // Split list menjadi dua bagian
  printf("\n=== Memecah List Menjadi Dua ===\n");
  SplitList(SenaraiGabu, &Senarai1, &Senarai3);
  printf("Isi Senarai1 setelah SplitList: ");
  PrintList(Senarai1);
  printf("\n");
  printf("Isi Senarai3 setelah SplitList: ");
  PrintList(Senarai3);
  printf("\n");

  // Menyalin list
  printf("\n=== Menyalin List ===\n");
  CopyList(Senarai, &SenaraiSalin);
  printf("Isi Senarai Salinan setelah CopyList: ");
  PrintList(SenaraiSalin);
  printf("\n");

  return 0;
}