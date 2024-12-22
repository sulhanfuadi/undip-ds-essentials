/* Program   : mtqueue2.c */
/* Deskripsi : file DRIVER modul queue karakter model II */
/* NIM/Nama  : 24060123130115/Sulhan Fuadi */
/* Tanggal   : 04 Oktober 2024*/
/***********************************/

#include <stdio.h>
#include <string.h>
#include "tqueue2.h"
#include "tqueue2.c"

int main() {
  // Kamus Lokal
  tqueue2 A, B, C, D, F;
  char X;
  char E;
  int N;
  boolean result;

  // Algoritma
  printf("Halo, ini driver modul Queue II\n");
  printf("========================================\n");

  // Buat queue A, B, dan C
  createQueue2(&A);
  createQueue2(&B);
  createQueue2(&C);
  printf("Queue A, B, dan C telah dibuat.\n");

  // Tampilkan status awal queue A
  printf("Queue A kosong? %s\n", isEmptyQueue2(A) ? "Ya" : "Tidak");
  printf("Queue A penuh? %s\n", isFullQueue2(A) ? "Ya" : "Tidak");
  printf("========================================\n");

  // Tambahkan elemen ke queue A
  printf("Masukkan elemen ke queue A (masukkan karakter '0' untuk berhenti):\n");
  for (int i = 1; i <= 5; i++) {
    scanf(" %c", &X);
    if (X == '0') break;
    enqueue2(&A, X);
  }
  printf("========================================\n");

  // Tampilkan queue A setelah penambahan elemen menggunakan printQueue2
  printf("Isi queue A setelah penambahan elemen (menggunakan printQueue2):\n");
  printQueue2(A);
  printf("\n========================================\n");

  // Tampilkan elemen head dan tail queue A serta ukuran queue A
  if (!isEmptyQueue2(A)) {
    printf("Elemen head queue A: %c\n", infoHead2(A));
    printf("Elemen tail queue A: %c\n", infoTail2(A));
    N = sizeQueue2(A);
    printf("Ukuran queue A: %d\n", N);
  } else {
    printf("Queue A kosong.\n");
  }
  printf("========================================\n");

  // Hapus elemen dari queue A
  printf("Menghapus elemen dari queue A:\n");
  dequeue2(&A, &E);
  printf("Elemen yang dihapus (head): %c\n", E);
  printf("Isi queue A setelah penghapusan elemen (menggunakan printQueue2):\n");
  printQueue2(A);
  printf("\n========================================\n");

  // Tambahkan elemen ke queue B
  printf("Masukkan elemen ke queue B (masukkan karakter '0' untuk berhenti):\n");
  for (int i = 1; i <= 5; i++) {
    scanf(" %c", &X);
    if (X == '0') break;
    enqueue2(&B, X);
  }
  printf("========================================\n");

  // Tampilkan queue B setelah penambahan elemen menggunakan printQueue2
  printf("Isi queue B setelah penambahan elemen (menggunakan printQueue2):\n");
  printQueue2(B);
  printf("\n========================================\n");

  // Tambahkan elemen ke queue C
  printf("Masukkan elemen ke queue C (masukkan karakter '0' untuk berhenti):\n");
  for (int i = 1; i <= 5; i++) {
    scanf(" %c", &X);
    if (X == '0') break;
    enqueue2(&C, X);
  }
  printf("========================================\n");

  // Tampilkan queue C setelah penambahan elemen menggunakan printQueue2
  printf("Isi queue C setelah penambahan elemen (menggunakan printQueue2):\n");
  printQueue2(C);
  printf("\n========================================\n");

  // Tampilkan elemen-elemen queue A menggunakan viewQueue2
  printf("Isi queue A (menggunakan viewQueue2):\n");
  viewQueue2(A);
  printf("\n========================================\n");

  // Tampilkan elemen-elemen queue B menggunakan viewQueue2
  printf("Isi queue B (menggunakan viewQueue2):\n");
  viewQueue2(B);
  printf("\n========================================\n");

  // Tampilkan elemen-elemen queue C menggunakan viewQueue2
  printf("Isi queue C (menggunakan viewQueue2):\n");
  viewQueue2(C);
  printf("\n========================================\n");

  // Tambahkan beberapa elemen ke queue A menggunakan enqueue2N
  printf("Masukkan jumlah elemen yang ingin ditambahkan ke queue A: ");
  scanf("%d", &N);
  enqueue2N(&A, N);
  printf("Isi queue A setelah penambahan elemen (menggunakan printQueue2):\n");
  printQueue2(A);
  printf("\n========================================\n");

  // Tambahkan beberapa elemen ke queue B menggunakan enqueue2N
  printf("Masukkan jumlah elemen yang ingin ditambahkan ke queue B: ");
  scanf("%d", &N);
  enqueue2N(&B, N);
  printf("Isi queue B setelah penambahan elemen (menggunakan printQueue2):\n");
  printQueue2(B);
  printf("\n========================================\n");

  // Periksa apakah tail queue A berada di posisi stop
  printf("Tail queue A berada di posisi stop? %s\n", isTailStop(A) ? "Ya" : "Tidak");
  printf("========================================\n");

  // Periksa apakah tail queue B berada di posisi stop
  printf("Tail queue B berada di posisi stop? %s\n", isTailStop(B) ? "Ya" : "Tidak");
  printf("========================================\n");

  // Periksa apakah queue A dan queue B sama
  result = isEqualQueue2(A, B);
  printf("Queue A dan Queue B sama? %s\n", result ? "Ya" : "Tidak");
  printf("========================================\n");

  // Test isOneElement2
  printf("Testing isOneElement2:\n");
  createQueue2(&D);
  enqueue2(&D, 'A');
  printf("Isi queue D sebelum pengecekan isOneElement2:\n");
  printQueue2(D);
  printf("\nQueue D berisi satu elemen? %s\n", isOneElement2(D) ? "Ya" : "Tidak");
  enqueue2(&D, 'B');
  printf("Isi queue D sebelum pengecekan isOneElement2:\n");
  printQueue2(D);
  printf("\nQueue D berisi satu elemen? %s\n", isOneElement2(D) ? "Ya" : "Tidak");
  printf("========================================\n");

  // Test resetHead
  printf("Testing resetHead:\n");
  createQueue2(&F);
  for (int i = 1; i <= 5; i++) {
    enqueue2(&F, 'A' + i);
  }
  for (int i = 1; i <= 3; i++) {
    dequeue2(&F, &E);
  }
  printf("Isi queue F sebelum resetHead (menggunakan printQueue2):\n");
  printQueue2(F);
  enqueue2(&F, 'F');
  enqueue2(&F, 'G');
  printf("\nIsi queue F setelah resetHead dengan penambahan elemen (menggunakan printQueue2):\n");
  printQueue2(F);
  printf("\n========================================\n");

  return 0;
}