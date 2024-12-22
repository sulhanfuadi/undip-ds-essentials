/* File       : main.c */
/* Deskripsi  : aplikasi driver ADT list sirkular, representasi fisik pointer */
/* NIM & Nama : 24060123130115 Sulhan Fuadi */
/* Tanggal    : 8 November 2024 */

#include <stdio.h>
#include <stdlib.h>
#include "list2.c"

void PrintSeparator() {
    printf("--------------------------------------------------\n");
}

int main() {
    /* Kamus */
    address A, B, P;
    List2 Senarai, Senarai2, SenaraiGabu, Senarai1, Senarai3, SenaraiSalin;
    infotype V;

    // Membuat list dan mengisi elemen list 
    PrintSeparator();
    printf("Membuat dan Menampilkan List\n");
    PrintSeparator();
    CreateList(&Senarai);
    printf("Apakah senarai kosong? %s\n", IsEmptyList(Senarai) ? "Ya" : "Tidak");
    InsertVLast(&Senarai, 'K');
    printf("Isi Senarai Awal: ");
    PrintList(Senarai);
    printf("\nApakah senarai hanya memiliki satu elemen? %s\n", IsOneElm(Senarai) ? "Ya" : "Tidak");
    printf("Perbarui kembali Senarai...\n");
    InsertVLast(&Senarai, 'L');
    InsertVLast(&Senarai, 'M');
    InsertVLast(&Senarai, 'N');
    InsertVLast(&Senarai, 'O');
    printf("Isi Senarai: ");
    PrintList(Senarai);
    printf("\nBanyak elemen di senarai adalah %d\n", NbElm(Senarai));

    // Menambahkan elemen di awal dan akhir list
    PrintSeparator();
    printf("Menambahkan Elemen di Awal dan Akhir\n");
    PrintSeparator();
    InsertVFirst(&Senarai, 'J');
    InsertVFirst(&Senarai, 'I');
    InsertVLast(&Senarai, 'P');
    InsertVLast(&Senarai, 'Q');
    InsertVLast(&Senarai, 'R');
    printf("Isi Senarai setelah penambahan elemen di awal dan akhir: ");
    PrintList(Senarai);
    printf("\nBanyak elemen di senarai sekarang adalah %d\n", NbElm(Senarai));

    // Menghapus elemen pertama dan terakhir list
    PrintSeparator();
    printf("Menghapus Elemen Pertama dan Terakhir\n");
    PrintSeparator();
    DeleteVFirst(&Senarai, &V);
    printf("Elemen pertama yang dihapus: %c\n", V);
    PrintList(Senarai);
    printf("\n");
    DeleteVLast(&Senarai, &V);
    printf("Elemen terakhir yang dihapus: %c\n", V);
    PrintList(Senarai);
    printf("\n");

    // Menghapus elemen tertentu
    PrintSeparator();
    printf("Menghapus Elemen Bernilai P\n");
    PrintSeparator();
    DeleteX(&Senarai, 'P');
    PrintList(Senarai);
    printf("\n");

    // Mengganti elemen tertentu
    PrintSeparator();
    printf("Mengganti Elemen Bernilai Q dengan Z\n");
    PrintSeparator();
    UpdateX(&Senarai, 'Q', 'Z');
    PrintList(Senarai);
    printf("\n");

    // Membalikkan urutan list
    PrintSeparator();
    printf("Membalik Urutan List\n");
    PrintSeparator();
    Invers(&Senarai);
    PrintList(Senarai);
    printf("\n");

    // Perbarui Senarai: tambahkan beberapa elemen lagi
    PrintSeparator();
    printf("Isi Senarai Sekarang: \n");
    PrintList(Senarai);
    printf("\n");
    printf("Perbarui kembali Senarai...\n");
    InsertVLast(&Senarai, 'A');
    InsertVLast(&Senarai, 'N');
    InsertVLast(&Senarai, 'G');
    InsertVLast(&Senarai, 'A');
    printf("Isi Senarai: ");
    PrintList(Senarai);
    printf("\nBanyak elemen di senarai sekarang adalah %d\n", NbElm(Senarai));

    // Menghitung kemunculan elemen A
    PrintSeparator();
    printf("Menghitung Kemunculan Elemen A\n");
    PrintSeparator();
    printf("Jumlah kemunculan 'A': %d\n", CountX(Senarai, 'A'));

    // Menghitung rasio kemunculan elemen A
    PrintSeparator();
    printf("Menghitung Frekuensi Elemen A\n");
    PrintSeparator();
    printf("Frekuensi kemunculan 'A': %.2f\n", FrekuensiX(Senarai, 'A'));

    // Menghitung banyaknya huruf vokal
    PrintSeparator();
    printf("Menghitung Huruf Vokal\n");
    PrintSeparator();
    printf("Jumlah huruf vokal: %d\n", CountVocal(Senarai));

    // Menghitung huruf N yang diikuti huruf G
    PrintSeparator();
    printf("Menghitung Huruf N yang Diikuti G ('NG') \n");
    PrintSeparator();
    printf("Jumlah 'NG': %d\n", CountNG(Senarai));

    // Menyisipkan elemen X setelah O
    PrintSeparator();
    printf("Menyisipkan Elemen X Setelah O\n");
    PrintSeparator();
    InsertVAfterX(&Senarai, 'O', 'X');
    PrintList(Senarai);
    printf("\n");

    // Menyisipkan elemen Y sebelum O
    PrintSeparator();
    printf("Menyisipkan Elemen Y Sebelum O\n");
    PrintSeparator();
    InsertVBeforeX(&Senarai, 'O', 'Y');
    PrintList(Senarai);
    printf("\n");

    // Menghapus elemen setelah Z
    PrintSeparator();
    printf("Menghapus Elemen Y Setelah Z\n");
    PrintSeparator();
    DeleteVAfterX(&Senarai, 'Z', &V);
    printf("Elemen yang dihapus setelah 'Z': %c\n", V);
    PrintList(Senarai);
    printf("\n");

    // Menghapus elemen sebelum N
    PrintSeparator();
    printf("Menghapus Elemen X Sebelum N\n");
    PrintSeparator();
    DeleteVBeforeX(&Senarai, 'N', &V);
    printf("Elemen yang dihapus sebelum 'N': %c\n", V);
    PrintList(Senarai);
    printf("\n");

    // Menghapus semua elemen A
    PrintSeparator();
    printf("Menghapus Semua Elemen A\n");
    PrintSeparator();
    DeleteAllX(&Senarai, 'A');
    PrintList(Senarai);
    printf("\n");

    // Menampilkan address kemunculan J
    PrintSeparator();
    printf("Menampilkan Address Elemen J\n");
    PrintSeparator();
    SearchX(Senarai, 'J', &A);
    printf("Elemen J ada di alamat : %p\n", A);

    // Perbarui Senarai: tambahkan beberapa elemen lagi
    PrintSeparator();
    printf("Isi Senarai Sekarang: \n");
    PrintList(Senarai);
    printf("\n");
    printf("Perbarui kembali Senarai...\n");
    InsertVLast(&Senarai, 'Z');
    InsertVLast(&Senarai, 'Z');
    printf("Isi Senarai: ");
    PrintList(Senarai);
    printf("\nBanyak elemen di senarai sekarang adalah %d\n", NbElm(Senarai));
    
    // Menampilkan semua posisi kemunculan semua X
    PrintSeparator();
    printf("Menampilkan Semua Posisi Kemunculan Elemen Z\n");
    PrintSeparator();
    printf("Posisi kemunculan 'Z': ");
    SearchAllX(Senarai, 'Z');
    printf("\n");

    // Menghitung huruf yang paling banyak muncul
    PrintSeparator();
    printf("Menghitung Huruf yang Paling Banyak Muncul\n");
    PrintSeparator();
    printf("Jumlah huruf yang paling banyak muncul: %d\n", MaxMember(Senarai));

    // Menghitung modus dari list
    PrintSeparator();
    printf("Menghitung Modus List\n");
    PrintSeparator();
    printf("Modus dari list: %c\n", Modus(Senarai));

    // Menggabungkan dua list
    PrintSeparator();
    printf("Menggabungkan Dua List\n");
    PrintSeparator();
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
    PrintSeparator();
    printf("Membagi List Menjadi Dua\n");
    PrintSeparator();
    SplitList(SenaraiGabu, &Senarai1, &Senarai3);
    printf("List1: ");
    PrintList(Senarai1);
    printf("\nList2: ");
    PrintList(Senarai3);
    printf("\n");

    // Menyalin list
    PrintSeparator();
    printf("Menyalin List\n");
    PrintSeparator();
    printf("List Awal: ");
    PrintList(Senarai);
    CopyList(Senarai, &SenaraiSalin);
    printf("\nList Salinan: ");
    PrintList(SenaraiSalin);
    printf("\n");

    return 0;
}