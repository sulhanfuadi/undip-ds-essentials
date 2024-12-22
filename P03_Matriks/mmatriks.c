/***********************************/
/* Program   : mmatriks.c          */
/* Deskripsi : driver ADT matriks integer */
/* NIM/Nama  : 24060123130115/Sulhan Fuadi */
/* Tanggal   : 13 September 2024    */
/***********************************/

#include <stdio.h>
#include <stdlib.h>
#include "matriks.c"

int main() {
  /* Kamus */
  Matriks M1, M2, M3, M4, M5, M6, M7, M8, M9, M10;
  int row, col, count, sum, max, min;
  float avg;
  
  /* Algoritma */
  printf("Halo, ini driver modul Matriks\n");
  printf("========================================\n");

  // Inisialisasi Matriks
  initMatriks(&M1);
  initMatriks(&M2);
  initMatriks(&M3);
  initMatriks(&M4);
  initMatriks(&M5);
  initMatriks(&M6);
  initMatriks(&M7);
  initMatriks(&M8);
  initMatriks(&M9);
  initMatriks(&M10);
  printf("Matriks M1 sampai M10 telah diinisialisasi.\n");
  printf("========================================\n");

  // Isi Matriks dengan nilai random
  isiMatriksRandom(&M1, 3, 3);
  printf("Matriks M1 (Random):\n");
  printMatriks(M1);
  printf("========================================\n");

  // Isi Matriks dengan nilai identitas
  isiMatriksIdentitas(&M2, 3);
  printf("Matriks M2 (Identitas):\n");
  printMatriks(M2);
  printf("========================================\n");

  // Pengecekan panjang baris, kolom, dan status matriks
  printf("Panjang Baris M1 yang terisi adalah %d", getNBaris(M1));
  printf("\nPanjang Kolom M1 yang terisi adalah %d", getNKolom(M1));
  printf("\n========================================\n");

  printf("Apakah matriks M1 kosong? %s", isEmptyMatriks(M1) ? "Ya" : "Tidak");
  printf("\nApakah matriks M1 full? %s", isFullMatriks(M1) ? "Ya" : "Tidak");
  printf("\nApakah matriks M2 full? %s", isFullMatriks(M2) ? "Ya" : "Tidak");
  printf("\n========================================\n");

  // Tambah elemen ke Matriks
  addX(&M1, 5, 2, 2);
  printf("Matriks M1 setelah addX(5, 2, 2):\n");
  printMatriks(M1);
  printf("========================================\n");

  // Edit elemen di Matriks
  editX(&M1, 10, 2, 2);
  printf("Matriks M1 setelah editX(10, 2, 2):\n");
  printMatriks(M1);
  printf("========================================\n");

  // Hapus elemen dari Matriks
  delX(&M1, 10);
  printf("Matriks M1 setelah delX(10):\n");
  printMatriks(M1);
  printf("========================================\n");

  // Cari elemen di Matriks
  searchX(M1, 5, &row, &col);
  printf("Elemen 5 ditemukan di baris %d kolom %d\n", row, col);
  searchX(M1, 58, &row, &col);
  printf("Elemen 58 ditemukan di baris %d kolom %d\n", row, col);
  printf("========================================\n");

  // Hitung elemen di Matriks
  count = countX(M1, 5);
  printf("Jumlah elemen 5 di Matriks M1: %d\n", count);
  count = countX(M2, 1);
  printf("Jumlah elemen 1 di Matriks M2: %d\n", count);
  printf("========================================\n");

  // Jumlahkan dua Matriks
  M3 = addMatriks(M1, M2);
  printf("Matriks M3 (M1 + M2):\n");
  printMatriks(M3);
  printf("========================================\n");

  // Kurangi dua Matriks
  M4 = subMatriks(M1, M2);
  printf("Matriks M4 (M1 - M2):\n");
  printMatriks(M4);
  printf("========================================\n");

  // Kalikan dua Matriks
  M5 = kaliMatriks(M1, M2);
  printf("Matriks M5 (M1 * M2):\n");
  printMatriks(M5);
  printf("========================================\n");

  // Kalikan Matriks dengan skalar
  M6 = kaliSkalarMatriks(M1, 2);
  printf("Matriks M6 (M1 * 2):\n");
  printMatriks(M6);
  printf("========================================\n");

  // Hitung jumlah elemen Matriks
  sum = getSumMatriks(M1);
  printf("Jumlah elemen di Matriks M1: %d\n", sum);
  printf("========================================\n");

  // Hitung rata-rata elemen Matriks
  avg = getAverageMatriks(M1);
  printf("Rata-rata elemen di Matriks M1: %.2f\n", avg);
  printf("========================================\n");

  // Cari elemen maksimum di Matriks
  max = getMaxMatriks(M1);
  printf("Elemen maksimum di Matriks M1: %d\n", max);
  printf("========================================\n");

  // Cari elemen minimum di Matriks
  min = getMinMatriks(M1);
  printf("Elemen minimum di Matriks M1: %d\n", min);
  printf("========================================\n");

  // Transpose Matriks
  transposeMatriks(&M1);
  printf("Matriks M1 setelah transpose:\n");
  printMatriks(M1);
  printf("========================================\n");

  // Dapatkan Matriks transpose
  M7 = getTransposeMatriks(M1);
  printf("Matriks M7 (Transpose dari M1):\n");
  printMatriks(M7);
  printf("========================================\n");

  // Populate Matriks dengan input dari keyboard
  printf("Masukkan elemen untuk Matriks M8:\n");
  populateMatriks(&M8, 2, 2);
  printf("Matriks M8:\n");
  printMatriks(M8);
  printf("========================================\n");

  // View Matriks yang terisi
  printf("View Matriks M8 yang terisi:\n");
  viewMatriks(M8);
  printf("========================================\n");

  return 0;
}
