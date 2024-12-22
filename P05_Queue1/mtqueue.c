/* Program   : mtqueue.c */
/* Deskripsi : file DRIVER modul queue karakter */
/* NIM/Nama  : 24060123130115/Sulhan Fuadi */
/* Tanggal   : 27 September 2024 */
/***********************************/

#include <stdio.h>
#include <string.h>
#include "tqueue.h"
#include "tqueue.c"

int main() {
  // Kamus Lokal
  tqueue A, B, C;
  char X;
  char e;
  int N;
  int i;

  // Algoritma
  printf("Halo, ini driver modul Queue\n");
  printf("========================================\n");

  // Buat queue A, B, dan C
  createQueue(&A);
  createQueue(&B);
  createQueue(&C);
  printf("Queue A, B, dan C telah dibuat.\n");

  // Tampilkan status awal queue A
  printf("Queue A kosong? %s\n", isEmptyQueue(A) ? "Ya" : "Tidak");
  printf("Queue A penuh? %s\n", isFullQueue(A) ? "Ya" : "Tidak");
  printf("========================================\n");

  // Tambahkan elemen ke queue A
  printf("Masukkan elemen ke queue A (masukkan karakter '0' untuk berhenti):\n");
  // while (1) {
  //   scanf(" %c", &X);
  //   if (X == '0') break;
  //   enqueue(&A, X);
  // }
  for (i = 1; i <= 5; i++) {
    scanf(" %c", &X);
    enqueue(&A, X);
  }
  printf("========================================\n");

  // Tampilkan queue A setelah penambahan elemen menggunakan printQueue
  printf("Isi queue A setelah penambahan elemen (menggunakan printQueue):\n");
  printQueue(A);
  printf("\n========================================\n");

  // Tampilkan elemen head dan tail queue A serta ukuran queue A
  if (!isEmptyQueue(A)) {
    printf("Elemen head queue A: %c\n", infoHead(A));
    printf("Elemen tail queue A: %c\n", infoTail(A));
    N = sizeQueue(A);
    printf("Ukuran queue A: %d\n", N);
  } else {
    printf("Queue A kosong.\n");
  }
  printf("========================================\n");

  // Hapus elemen dari queue A
  printf("Menghapus elemen dari queue A:\n");
  dequeue(&A, &e);
  printf("Elemen yang dihapus (head): %c\n", e);
  printf("Isi queue A setelah penghapusan elemen (menggunakan printQueue):\n");
  printQueue(A);
  printf("\n========================================\n");

  // Tambahkan elemen ke queue B
  printf("Masukkan elemen ke queue B (masukkan karakter '0' untuk berhenti):\n");
  while (1) {
    scanf(" %c", &X);
    if (X == '0') break;
    enqueue(&B, X);
  }
  printf("========================================\n");

  // Tampilkan queue B setelah penambahan elemen menggunakan printQueue
  printf("Isi queue B setelah penambahan elemen (menggunakan printQueue):\n");
  printQueue(B);
  printf("\n========================================\n");

  // Tambahkan elemen ke queue C
  printf("Masukkan elemen ke queue C (masukkan karakter '0' untuk berhenti):\n");
  while (1) {
    scanf(" %c", &X);
    if (X == '0') break;
    enqueue(&C, X);
  }
  printf("========================================\n");

  // Tampilkan queue C setelah penambahan elemen menggunakan printQueue
  printf("Isi queue C setelah penambahan elemen (menggunakan printQueue):\n");
  printQueue(C);
  printf("\n========================================\n");

  // Tambahkan elemen ke queue A atau B menggunakan enqueue2
  printf("Masukkan elemen ke queue A atau B (menggunakan enqueue2): ");
  scanf(" %c", &X);
  enqueue2(&A, &B, X);
  printf("Isi queue A setelah penambahan elemen (menggunakan printQueue):\n");
  printQueue(A);
  printf("\nIsi queue B setelah penambahan elemen (menggunakan printQueue):\n");
  printQueue(B);
  printf("\n========================================\n");

  // Hapus elemen dari queue A atau B menggunakan dequeue2
  printf("Menghapus elemen dari queue A atau B (menggunakan dequeue2):\n");
  dequeue2(&A, &B, &e);
  printf("Elemen yang dihapus (head): %c\n", e);
  printf("Isi queue A setelah penghapusan elemen (menggunakan printQueue):\n");
  printQueue(A);
  printf("\nIsi queue B setelah penghapusan elemen (menggunakan printQueue):\n");
  printQueue(B);
  printf("\n========================================\n");

  // Tambahkan elemen ke queue C menggunakan enqueue1
  printf("Masukkan elemen ke queue C (menggunakan enqueue1): ");
  scanf(" %c", &X);
  enqueue1(&C, X);
  printf("Isi queue C setelah penambahan elemen (menggunakan printQueue):\n");
  printQueue(C);
  printf("\n========================================\n");

  // Tampilkan ukuran queue yang terpanjang antara A dan B menggunakan maxlength
  N = maxlength(A, B);
  printf("Ukuran queue yang terpanjang antara A dan B: %d\n", N);
  printf("========================================\n");

  return 0;
}