/************************************/
/* Program   : mtabel.c */
/* Deskripsi : aplikasi driver modul Tabel */
/* NIM/Nama  : 24060123130115/Sulhan Fuadi */
/* Tanggal   : 06 September 2024*/
/***********************************/
#include <stdio.h>
#include "tabel.h"
#include "tabel.c"

int main() {
    // Kamus
    Tabel T1, T2, T3;
    int X, Y;

    // Algoritma
    printf("Halo, ini driver modul Tabel\n");
    printf("========================================\n");

    // Buat tabel T1
    createTable(&T1);
    printf("Tabel T1 telah dibuat.\n");

    // Tampilkan status awal tabel
    printf("Besar size Table T1 sekarang sebesar %d\n", getSize(T1));
    printf("Table T1 kosong? %s\n", isEmptyTable(T1) ? "Ya" : "Tidak");
    printf("Table T1 penuh? %s\n", isFullTable(T1) ? "Ya" : "Tidak");
    printf("========================================\n");

    // Tambahkan elemen ke tabel T1 (menggunakan populate2)
    printf("Masukkan elemen ke tabel T1 (masukkan angka negatif untuk berhenti):\n");
    populate2(&T1);
    printf("========================================\n");

    // Tampilkan tabel setelah penambahan elemen
    printf("Isi tabel T1 setelah penambahan elemen:\n");
    printTable(T1);
    printf("========================================\n");

    // Tampilkan ukuran tabel
    printf("Besar size Table sekarang sebesar %d\n", getSize(T1));
    printf("========================================\n");

    // Cari elemen dalam tabel
    printf("Masukkan elemen yang ingin dicari: ");
    scanf("%d", &X);
    int index = searchX(T1, X);
    if (index != 0) {
        printf("Elemen %d ditemukan pada indeks %d\n", X, index);
    } else {
        printf("Elemen %d tidak ditemukan dalam tabel\n", X);
    }
    printf("========================================\n");

    // Hapus elemen dari tabel
    printf("Masukkan elemen yang ingin dihapus: ");
    scanf("%d", &X);
    delXTable(&T1, X);
    printf("Isi tabel setelah penghapusan elemen:\n");
    printTable(T1);
    printf("========================================\n");

    // Tampilkan jumlah elemen dalam tabel
    printf("Jumlah elemen dalam tabel T1: %d\n", getSize(T1));
    printf("========================================\n");

    // Tampilkan jumlah elemen kosong dalam tabel
    printf("Jumlah elemen kosong dalam tabel T1: %d\n", countEmpty(T1));
    printf("========================================\n");

    // Tampilkan elemen maksimum dan minimum dalam tabel
    printf("Elemen maksimum dalam tabel T1: %d\n", getMaxEl(T1));
    printf("Elemen minimum dalam tabel T1: %d\n", getMinEl(T1));
    printf("========================================\n");

    // Tampilkan modus dari tabel
    printf("Modus dari tabel T1: %d\n", Modus(T1));
    printf("========================================\n");

    // Tampilkan jumlah dan rata-rata elemen dalam tabel
    printf("Hasil Penjumlahan elemen dalam tabel T1: %d\n", SumEl(T1));
    printf("Rata-rata elemen dalam tabel T1: %.2f\n", AverageEl(T1));
    printf("========================================\n");

    // Urutkan tabel secara ascending dan descending
    sortAsc(&T1);
    printf("Isi tabel T1 setelah diurutkan secara ascending:\n");
    printTable(T1);
    printf("========================================\n");

    sortDesc(&T1);
    printf("Isi tabel T1 setelah diurutkan secara descending:\n");
    printTable(T1);
    printf("========================================\n");

    // Buat tabel T2 dan T3
    createTable(&T2);
    createTable(&T3);
    printf("Tabel T2 dan T3 telah dibuat.\n");
    printf("========================================\n");

    // Populate T2 dengan 5 elemen
    printf("Masukkan 5 elemen ke tabel T2:\n");
    populate1(&T2, 5);
    printf("Isi tabel T2 setelah penambahan elemen:\n");
    printTable(T2);
    printf("========================================\n");

    // Populate T3 dengan elemen positif sampai input negatif
    printf("Masukkan elemen ke tabel T3 (masukkan angka negatif untuk berhenti):\n");
    populate2(&T3);
    printf("Isi tabel T3 setelah penambahan elemen:\n");
    printTable(T3);
    printf("========================================\n");

    // Hapus semua elemen X dari T2
    printf("Masukkan elemen yang ingin dihapus dari T2: ");
    scanf("%d", &X);
    delAllXTable(&T2, X);
    printf("Isi tabel T2 setelah penghapusan semua elemen %d:\n", X);
    printTable(T2);
    printf("========================================\n");

    // Tampilkan tabel T2 dan T3
    printf("Isi tabel T2:\n");
    viewTable(T2);
    printf("========================================\n");
    printf("Isi tabel T3:\n");
    viewTable(T3);
    printf("========================================\n");

    return 0;
}