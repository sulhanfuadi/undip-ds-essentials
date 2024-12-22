/* File       : main.c */
/* Deskripsi  : aplikasi driver ADT list lanjar kait ganda, representasi fisik pointer */
/* NIM & Nama : 24060123130115 & Sulhan Fuadi */
/* Tanggal    : 14 November 2024 */

#include <stdio.h>
#include <stdlib.h>
#include "list3.c"

int main() {
    /* Kamus */
    address A, B, P;
    List3 Senarai, Senarai1, Senarai2, Senarai3, SenaraiGabu, SenaraiSalin;
    infotype V;

    // Membuat list dan mengisi elemen list 
    printf("--------------------------------------------------\n");
    printf("Membuat dan Menampilkan List\n");
    printf("--------------------------------------------------\n");
    CreateList(&Senarai);
    printf("Isi Senarai Awal: ");
    PrintList(Senarai);
    printf("\nApakah senarai kosong? %s\n", IsEmptyList(Senarai) ? "Ya" : "Tidak");
    InsertVLast(&Senarai, 'K');
    InsertVLast(&Senarai, 'L');
    InsertVLast(&Senarai, 'M');
    InsertVLast(&Senarai, 'N');
    InsertVLast(&Senarai, 'O');
    printf("Isi Senarai Sekarang: ");
    PrintList(Senarai);
    printf("\nBanyak elemen di senarai adalah %d\n", NbElm(Senarai));

    // Menambahkan elemen di awal dan akhir list
    printf("--------------------------------------------------\n");
    printf("Menambahkan Elemen di Awal dan Akhir\n");
    printf("--------------------------------------------------\n");
    InsertVFirst(&Senarai, 'J');
    InsertVFirst(&Senarai, 'I');
    printf("Isi Senarai setelah penambahan elemen di awal: ");
    PrintList(Senarai);
    InsertVLast(&Senarai, 'P');
    InsertVLast(&Senarai, 'Q');
    InsertVLast(&Senarai, 'R');
    printf("\nIsi Senarai setelah penambahan elemen di akhir: ");
    PrintList(Senarai);
    printf("\nBanyak elemen di senarai sekarang adalah %d\n", NbElm(Senarai));

    // Menghapus elemen pertama dan terakhir list
    printf("--------------------------------------------------\n");
    printf("Menghapus Elemen Pertama dan Terakhir\n");
    printf("--------------------------------------------------\n");
    DeleteVFirst(&Senarai, &V);
    printf("Elemen pertama yang dihapus: %c\n", V);
    PrintList(Senarai);
    printf("\n");
    DeleteVLast(&Senarai, &V);
    printf("Elemen terakhir yang dihapus: %c\n", V);
    PrintList(Senarai);
    printf("\n");

    // Menghapus elemen tertentu
    printf("--------------------------------------------------\n");
    printf("Menghapus Elemen Bernilai P\n");
    printf("--------------------------------------------------\n");
    printf("Isi Senarai Sebelum Dihapus: ");
    PrintList(Senarai);
    DeleteX(&Senarai, 'P');
    printf("\nIsi Senarai Sekarang: ");
    PrintList(Senarai);
    printf("\n");

    // Mencari elemen tertentu
    printf("--------------------------------------------------\n");
    printf("Mencari Elemen Tertentu dan Mengembalikannya dengan Alamat\n");
    printf("--------------------------------------------------\n");
    SearchX(Senarai, 'J', &A);
    printf("Elemen J ada di alamat : %p\n", A);
    SearchX(Senarai, 'Z', &B);
    printf("Elemen Z ada di alamat : %p\n", B);

    // Mengganti elemen tertentu
    printf("--------------------------------------------------\n");
    printf("Mengganti Elemen Bernilai Q dengan Z\n");
    printf("--------------------------------------------------\n");
    printf("Isi Senarai Sebelum Diganti: ");
    PrintList(Senarai);
    UpdateX(&Senarai, 'Q', 'Z');
    printf("\nIsi Senarai Sekarang: ");
    PrintList(Senarai);
    printf("\n");

    // Membalikkan urutan list
    printf("--------------------------------------------------\n");
    printf("Membalik Urutan List\n");
    printf("--------------------------------------------------\n");
    printf("Isi Senarai Sebelum Dibalik (di-inverse): ");
    PrintList(Senarai);
    Invers(&Senarai);
    printf("\nIsi Senarai Sekarang: ");
    PrintList(Senarai);
    printf("\n");

    // Perbarui Senarai: tambahkan beberapa elemen lagi
    printf("--------------------------------------------------\n");
    printf("Isi Senarai Sekarang: \n");
    PrintList(Senarai);
    printf("\n");
    printf("Perbarui kembali Senarai...\n");
    InsertVLast(&Senarai, 'A');
    InsertVLast(&Senarai, 'N');
    InsertVLast(&Senarai, 'G');
    InsertVLast(&Senarai, 'A');
    InsertVLast(&Senarai, 'A');
    InsertVLast(&Senarai, 'N');
    InsertVLast(&Senarai, 'G');
    printf("Isi Senarai setelah diperbarui: ");
    PrintList(Senarai);
    printf("\nBanyak elemen di senarai sekarang adalah %d\n", NbElm(Senarai));

    // Menyisipkan elemen X setelah O
    printf("--------------------------------------------------\n");
    printf("Menyisipkan Elemen X Setelah O\n");
    printf("--------------------------------------------------\n");
    InsertVAfterX(&Senarai, 'O', 'X');
    PrintList(Senarai);
    printf("\n");

    // Menyisipkan elemen Y sebelum O
    printf("--------------------------------------------------\n");
    printf("Menyisipkan Elemen Y Sebelum O\n");
    printf("--------------------------------------------------\n");
    InsertVBeforeX(&Senarai, 'O', 'Y');
    PrintList(Senarai);
    printf("\n");

    // Menghapus elemen setelah Z
    printf("--------------------------------------------------\n");
    printf("Menghapus Elemen Y Setelah Z\n");
    printf("--------------------------------------------------\n");
    DeleteVAfterX(&Senarai, 'Z', &V);
    printf("Elemen yang dihapus setelah 'Z': %c\n", V);
    PrintList(Senarai);
    printf("\n");

    // Menghapus elemen sebelum N
    printf("--------------------------------------------------\n");
    printf("Menghapus Elemen X Sebelum N\n");
    printf("--------------------------------------------------\n");
    DeleteVBeforeX(&Senarai, 'N', &V);
    printf("Elemen yang dihapus sebelum 'N': %c\n", V);
    PrintList(Senarai);
    printf("\n");

    // Menghitung kemunculan elemen A
    printf("--------------------------------------------------\n");
    printf("Menghitung Kemunculan Elemen A\n");
    printf("--------------------------------------------------\n");
    printf("Jumlah kemunculan 'A': %d\n", CountX(Senarai, 'A'));

    // Menghitung rasio kemunculan elemen A
    printf("--------------------------------------------------\n");
    printf("Menghitung Frekuensi Elemen A\n");
    printf("--------------------------------------------------\n");
    printf("Frekuensi kemunculan 'A': %.2f\n", FrekuensiX(Senarai, 'A'));

    // Menghitung banyaknya huruf vokal
    printf("--------------------------------------------------\n");
    printf("Menghitung Huruf Vokal\n");
    printf("--------------------------------------------------\n");
    printf("Jumlah huruf vokal: %d\n", CountVocal(Senarai));

    // Menghitung huruf N yang diikuti huruf G
    printf("--------------------------------------------------\n");
    printf("Menghitung Huruf N yang Diikuti G ('NG') \n");
    printf("--------------------------------------------------\n");
    printf("Jumlah 'NG': %d\n", CountNG(Senarai));

    // Menghapus semua elemen A
    printf("--------------------------------------------------\n");
    printf("Menghapus Semua Elemen A\n");
    printf("--------------------------------------------------\n");
    DeleteAllX(&Senarai, 'A');
    PrintList(Senarai);
    printf("\n");

    // Perbarui Senarai: tambahkan beberapa elemen lagi
    printf("--------------------------------------------------\n");
    printf("Isi Senarai Sekarang: \n");
    PrintList(Senarai);
    printf("\n");
    printf("Perbarui kembali Senarai...\n");
    InsertVLast(&Senarai, 'Z');
    InsertVLast(&Senarai, 'A');
    InsertVLast(&Senarai, 'Z');
    printf("Isi Senarai setelah diperbarui: ");
    PrintList(Senarai);
    printf("\nBanyak elemen di senarai sekarang adalah %d\n", NbElm(Senarai));
    
    // Menampilkan semua posisi kemunculan semua X
    printf("--------------------------------------------------\n");
    printf("Menampilkan Semua Posisi Kemunculan Elemen Z\n");
    printf("--------------------------------------------------\n");
    printf("Posisi kemunculan 'Z': ");
    SearchAllX(Senarai, 'Z');
    printf("\n");

    // Menghitung huruf yang paling banyak muncul
    printf("--------------------------------------------------\n");
    printf("Menghitung Huruf yang Paling Banyak Muncul\n");
    printf("--------------------------------------------------\n");
    printf("Jumlah huruf yang paling banyak muncul: %d\n", MaxMember(Senarai));

    // Mencari modus dari list
    printf("--------------------------------------------------\n");
    printf("Mencari Modus List\n");
    printf("--------------------------------------------------\n");
    printf("Modus dari list: %c\n", Modus(Senarai));

    // Menggabungkan dua list
    printf("--------------------------------------------------\n");
    printf("Menggabungkan Dua List\n");
    printf("--------------------------------------------------\n");
    CreateList(&Senarai2);
    InsertVLast(&Senarai2, 'A');
    InsertVLast(&Senarai2, 'B');
    InsertVLast(&Senarai2, 'C');
    InsertVLast(&Senarai2, 'B');
    InsertVLast(&Senarai2, 'A');
    printf("List1: ");
    PrintList(Senarai);
    printf("\nList2: ");
    PrintList(Senarai2);
    ConcatList(Senarai, Senarai2, &SenaraiGabu);
    printf("\nList Gabungan: ");
    PrintList(SenaraiGabu);
    printf("\n");

    // Membagi list menjadi dua bagian
    printf("--------------------------------------------------\n");
    printf("Membagi List Menjadi Dua\n");
    printf("--------------------------------------------------\n");
    SplitList(SenaraiGabu, &Senarai1, &Senarai3);
    printf("List Awal: ");
    PrintList(SenaraiGabu);
    printf("\nList1: ");
    PrintList(Senarai1);
    printf("\nList2: ");
    PrintList(Senarai3);
    printf("\n");

    // Menyalin list
    printf("--------------------------------------------------\n");
    printf("Menyalin List\n");
    printf("--------------------------------------------------\n");
    printf("List Awal: ");
    PrintList(Senarai);
    CopyList(Senarai, &SenaraiSalin);
    printf("\nList Salinan: ");
    PrintList(SenaraiSalin);
    printf("\n");

    return 0;
}
