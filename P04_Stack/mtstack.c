/* Program   : mtstack.c */
/* Deskripsi : file DRIVER modul stack karakter */
/* NIM/Nama  : 24060123130115/Sulhan Fuadi */
/* Tanggal   : 20 September 2024*/
/***********************************/

#include <stdio.h>
#include <string.h>
#include "tstack.h"
#include "tstack.c"

/* function isPalindromStack(X: string) -> boolean
  {mengembalikan True jika string X adalah palindrom} */
boolean isPalindromStack(char X[]) {
  Tstack T1;
  boolean palindrome = true;
  int i, len;
	char E;

  createStack(&T1);
  len = strlen(X);

  for (i = 0; i < len / 2; i++) {
    push(&T1, X[i]);
  }

  if (len % 2 == 1) {
    i++;
  }

  while (!isEmptyStack(T1) && palindrome) {
    pop(&T1, &E);
    if (E != X[i]) {
      palindrome = false;
    }
    i++;
  }

  return palindrome;
}

boolean isPalindromStackV2(char X[]) {
  Tstack T1, T2;
  boolean palindrome = true;
  int i, len;
	char E1, E2;

  createStack(&T1);
  createStack(&T2);
  len = strlen(X);

  for (i = 0; i < len / 2; i++) {
    push(&T1, X[i]);
    push(&T2, X[len - 1 - i]);
  }

  while (!isEmptyStack(T1) && !isEmptyStack(T2) && palindrome) {
    pop(&T1, &E1);
    pop(&T2, &E2);
    if (E1 != E2) {
      palindrome = false;
    }
  }

  return palindrome;
}

int main() {
	// Kamus Lokal
	Tstack A, B, C;
	char X;
	int N;
	char str[100];

	// Algoritma
	printf("Halo, ini driver modul Stack\n");
	printf("========================================\n");

	// Buat stack A
	createStack(&A);
	printf("Stack A telah dibuat.\n");

	// Tampilkan status awal stack
	printf("Stack A kosong? %s\n", isEmptyStack(A) ? "Ya" : "Tidak");
	printf("Stack A penuh? %s\n", isFullStack(A) ? "Ya" : "Tidak");
	printf("========================================\n");

	// Tambahkan elemen ke stack A
	printf("Masukkan elemen ke stack A (masukkan karakter '0' untuk berhenti):\n");
	while (1) {
		scanf(" %c", &X);
		if (X == '0') break;
		push(&A, X);
	}
	printf("========================================\n");

	// Tampilkan stack setelah penambahan elemen menggunakan printStack
	printf("Isi stack A setelah penambahan elemen (menggunakan printStack):\n");
	printStack(A);
	printf("\n========================================\n");

	// Tampilkan stack setelah penambahan elemen menggunakan viewStack
	printf("Isi stack A setelah penambahan elemen (menggunakan viewStack):\n");
	viewStack(A);
	printf("\n========================================\n");

	// Tampilkan elemen top stack menggunakan infotop
	if (!isEmptyStack(A)) {
		printf("Elemen top stack A: %c\n", infotop(A));
	} else {
		printf("Stack A kosong.\n");
	}
	printf("========================================\n");

	// Tampilkan posisi top stack menggunakan top
	if (!isEmptyStack(A)) {
		printf("Posisi top stack A: %d\n", top(A));
	} else {
		printf("Stack A kosong.\n");
	}
	printf("========================================\n");

	// Hapus elemen dari stack
	printf("Menghapus elemen dari stack A:\n");
	pop(&A, &X);
	printf("Elemen yang dihapus (top): %c\n", X);
	printf("Isi stack A setelah penghapusan elemen (menggunakan printStack):\n");
	printStack(A);
	printf("\n========================================\n");

	// Tampilkan stack setelah penghapusan elemen menggunakan viewStack
	printf("Isi stack A setelah penghapusan elemen (menggunakan viewStack):\n");
	viewStack(A);
	printf("\n========================================\n");

	// Buat stack B dan C
	createStack(&B);
	createStack(&C);
	printf("Stack B dan C telah dibuat.\n");
	printf("========================================\n");

	// Tambahkan elemen ke stack B menggunakan pushN
	printf("Masukkan jumlah elemen yang ingin ditambahkan ke stack B: ");
	scanf("%d", &N);
	pushN(&B, N);
	// printf("Posisi top stack B: %d\n", top(B));
	printf("Isi stack B setelah penambahan elemen (menggunakan printStack):\n");
	printStack(B);
	printf("\n========================================\n");

	// Tampilkan stack B setelah penambahan elemen menggunakan viewStack
	printf("Isi stack B setelah penambahan elemen (menggunakan viewStack):\n");
	viewStack(B);
	printf("\n========================================\n");

	// Tambahkan elemen ke stack B menggunakan pushBabel1
	printf("Masukkan elemen ke stack B (menggunakan pushBabel1): ");
	scanf(" %c", &X);
	pushBabel1(&B, X);
	// printf("Posisi top stack B: %d\n", top(B));
	printf("Isi stack B setelah penambahan elemen (menggunakan printStack):\n");
	printStack(B);
	printf("\n========================================\n");

	// Tampilkan stack C setelah penambahan elemen menggunakan viewStack
	printf("Isi stack B setelah penambahan elemen (menggunakan viewStack):\n");
	viewStack(B);
	printf("\n========================================\n");

	// Tambahkan elemen ke stack C
	printf("Masukkan elemen ke stack C (masukkan karakter '0' untuk berhenti):\n");
	while (1) {
		scanf(" %c", &X);
		if (X == '0') break;
		push(&C, X);
	}
	printf("========================================\n");

	// Tampilkan stack setelah penambahan elemen menggunakan printStack
	printf("Isi stack A setelah penambahan elemen (menggunakan printStack):\n");
	printStack(C);
	printf("\n========================================\n");

	// Tampilkan stack setelah penambahan elemen menggunakan viewStack
	printf("Isi stack A setelah penambahan elemen (menggunakan viewStack):\n");
	viewStack(C);
	printf("\n========================================\n");
	
	// Tambahkan elemen ke stack C menggunakan pushZuma
	printf("Masukkan elemen ke stack C (menggunakan pushZuma): ");
	scanf(" %c", &X);
	pushZuma(&C, X);
	printf("Isi stack C setelah penambahan elemen (menggunakan printStack):\n");
	printStack(C);
	printf("\n========================================\n");

	// Tampilkan stack C setelah penambahan elemen menggunakan viewStack
	printf("Isi stack C setelah penambahan elemen (menggunakan viewStack):\n");
	viewStack(C);
	printf("\n========================================\n");

	// Uji fungsi isPalindromStack
	printf("Masukkan string untuk diuji apakah palindrom: ");
	scanf("%s", str);
	if (isPalindromStack(str)) {
		printf("String '%s' adalah palindrom.\n", str);
	} else {
		printf("String '%s' bukan palindrom.\n", str);
	}
	printf("========================================\n");

	return 0;
}
