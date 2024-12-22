/* File : main.c */
/* Deskripsi : aplikasi driver ADT bintree berkait dengan representasi fisik pointer */
/* NIM & Nama : 24060123130115 & Sulhan Fuadi*/
/* Tanggal : 22 November 2024 */

#include <stdio.h>
#include <stdlib.h>
#include "pohon1.h"
#include "pohon1.c"

int main() {
  // Kamus
  bintree P1, P2, P3, P4;
  infotype cari, ganti;
  char daunTerkiri;

  // Membentuk pohon
  printf("--------------------------------------------------\n");
  printf("Membentuk pohon\n");
  printf("--------------------------------------------------\n");
  P1 = Tree('A', Tree('B', Tree('C', Tree('D', NIL, NIL), NIL), NIL), Tree('E', NIL, Tree('F', NIL, Tree('G', NIL, Tree('H', NIL, NIL)))));
  P2 = Tree('X', Tree('Y', Tree('Y', NIL, NIL), Tree('Z', NIL, NIL)), Tree('W', NIL, NIL));
  P3 = Tree('L', Tree('M', Tree('N', NIL, NIL), NIL), Tree('O', Tree('P', NIL, NIL), NIL));
  P4 = Tree('K', NIL, Tree('J', NIL, NIL)); 
  printf("Pohon P1, P2, P3, dan P4 berhasil dibentuk...\n");

  // Menampilkan pohon dalam bentuk prefix
  printf("--------------------------------------------------\n");
  printf("Menampilkan pohon dalam bentuk prefix\n");
  printf("--------------------------------------------------\n");
  printf("Pohon P1: ");
  PrintPrefix(P1);
  printf("\nPohon P2: ");
  PrintPrefix(P2);
  printf("\nPohon P3: ");
  PrintPrefix(P3);
  printf("\nPohon P4: ");
  PrintPrefix(P4);

  // Banyak Elemen
  printf("\n--------------------------------------------------\n");
  printf("Menampilkan banyak elemen dalam pohon\n");
  printf("--------------------------------------------------\n");
  printf("Banyak elemen di P1: %d\n", NbElm(P1));
  printf("Banyak elemen di P2: %d\n", NbElm(P2));
  printf("Banyak elemen di P3: %d\n", NbElm(P3));
  printf("Banyak elemen di P4: %d\n", NbElm(P4));

  // Banyak Daun
  printf("--------------------------------------------------\n");
  printf("Menampilkan banyak daun dalam pohon\n");
  printf("--------------------------------------------------\n");
  printf("Banyak daun di P1: %d\n", NbDaun(P1));
  printf("Banyak daun di P2: %d\n", NbDaun(P2));
  printf("Banyak daun di P3: %d\n", NbDaun(P3));
  printf("Banyak daun di P4: %d\n", NbDaun(P4));

  // Tinggi Pohon
  printf("--------------------------------------------------\n");
  printf("Menampilkan tinggi pohon\n");
  printf("--------------------------------------------------\n");
  printf("Tinggi pohon P1: %d\n", Tinggi(P1));
  printf("Tinggi pohon P2: %d\n", Tinggi(P2));
  printf("Tinggi pohon P3: %d\n", Tinggi(P3));
  printf("Tinggi pohon P4: %d\n", Tinggi(P4));

  // Pencarian X
  printf("--------------------------------------------------\n");
  printf("Pencarian elemen dalam pohon\n");
  printf("--------------------------------------------------\n");
  printf("Apakah elemen 'F' ada di pohon P1? %s\n", SearchX(P1, 'F') ? "Ya" : "Tidak");
  printf("Apakah elemen 'Z' ada di pohon P2? %s\n", SearchX(P2, 'Z') ? "Ya" : "Tidak");
  printf("Apakah elemen 'K' ada di pohon P3? %s\n", SearchX(P3, 'K') ? "Ya" : "Tidak");
  printf("Apakah elemen 'I' ada di pohon P4? %s\n", SearchX(P4, 'I') ? "Ya" : "Tidak");

  // Update X
  printf("--------------------------------------------------\n");
  printf("Mengganti elemen dalam pohon\n");
  printf("--------------------------------------------------\n");
  
  printf("Pohon P1 sebelum update (Prefix): ");
  PrintPrefixSwalow(P1);
  printf("\nPohon P2 sebelum update (Prefix): ");
  PrintPrefixSwalow(P2);
  printf("\nPohon P3 sebelum update (Prefix): ");
  PrintPrefixSwalow(P3);
  printf("\nPohon P4 sebelum update (Prefix): ");
  PrintPrefixSwalow(P4);
  
  printf("\nMengganti elemen 'C' dengan 'G' di pohon P1\n");
  UpdateX(&P1, 'C', 'G');
  printf("Mengganti elemen 'Y' dengan 'V' di pohon P2\n");
  UpdateX(&P2, 'Y', 'V');
  printf("Mengganti elemen 'N' dengan 'Q' di pohon P3\n");
  UpdateX(&P3, 'N', 'Q');
  printf("Mengganti elemen 'J' dengan 'R' di pohon P4\n");
  UpdateX(&P4, 'J', 'R');

  printf("Pohon P1 setelah update (Prefix): ");
  PrintPrefixSwalow(P1);
  printf("\nPohon P2 setelah update (Prefix): ");
  PrintPrefixSwalow(P2);
  printf("\nPohon P3 setelah update (Prefix): ");
  PrintPrefixSwalow(P3);
  printf("\nPohon P4 setelah update (Prefix): ");
  PrintPrefixSwalow(P4);

  // Hitung X
  printf("\n--------------------------------------------------\n");
  printf("Menghitung jumlah elemen tertentu dalam pohon\n");
  printf("--------------------------------------------------\n");
  printf("Jumlah elemen 'F' dalam pohon P1: %d\n", CountX(P1, 'F'));
  printf("Jumlah elemen 'U' dalam pohon P2: %d\n", CountX(P2, 'U'));
  printf("Jumlah elemen 'L' dalam pohon P3: %d\n", CountX(P3, 'L'));
  printf("Jumlah elemen 'O' dalam pohon P4: %d\n", CountX(P4, 'O'));

  // Kemiringan
  printf("--------------------------------------------------\n");
  printf("Menampilkan apakah pohon condong kiri atau kanan\n");
  printf("--------------------------------------------------\n");
  printf("Apakah pohon P1 condong kiri? %s\n", IsSkewLeft(P1) ? "Ya" : "Tidak");
  printf("Apakah pohon P2 condong kiri? %s\n", IsSkewLeft(P2) ? "Ya" : "Tidak");
  printf("Apakah pohon P3 condong kiri? %s\n", IsSkewLeft(P3) ? "Ya" : "Tidak");
  printf("Apakah pohon P4 condong kiri? %s\n", IsSkewLeft(P4) ? "Ya" : "Tidak");

  printf("Apakah pohon P1 condong kanan? %s\n", IsSkewRight(P1) ? "Ya" : "Tidak");
  printf("Apakah pohon P2 condong kanan? %s\n", IsSkewRight(P2) ? "Ya" : "Tidak");
  printf("Apakah pohon P3 condong kanan? %s\n", IsSkewRight(P3) ? "Ya" : "Tidak");
  printf("Apakah pohon P4 condong kanan? %s\n", IsSkewRight(P4) ? "Ya" : "Tidak");

  // Level X
  printf("--------------------------------------------------\n");
  printf("Menampilkan level elemen tertentu dalam pohon\n");
  printf("--------------------------------------------------\n");
  printf("Level elemen 'G' di pohon P1: %d\n", LevelX(P1, 'G'));
  printf("Level elemen 'V' di pohon P2: %d\n", LevelX(P2, 'V'));
  printf("Level elemen 'Q' di pohon P3: %d\n", LevelX(P3, 'Q'));
  printf("Level elemen 'R' di pohon P4: %d\n", LevelX(P4, 'R'));

  // CountLevelT
  printf("--------------------------------------------------\n");
  printf("Menghitung jumlah elemen pada tingkat tertentu dalam pohon\n");
  printf("--------------------------------------------------\n");
  printf("Jumlah elemen pada level 2 di pohon P1: %d\n", CountLevelT(P1, 2));
  printf("Jumlah elemen pada level 1 di pohon P2: %d\n", CountLevelT(P2, 1));
  printf("Jumlah elemen pada level 3 di pohon P3: %d\n", CountLevelT(P3, 3));
  printf("Jumlah elemen pada level 4 di pohon P4: %d\n", CountLevelT(P4, 4));

  // Daun terkiri
  printf("--------------------------------------------------\n");
  printf("Menampilkan daun terkiri dalam pohon\n");
  printf("--------------------------------------------------\n");
  daunTerkiri = GetDaunTerkiri(P1);
  printf("Daun terkiri di pohon P1: '%c'\n", daunTerkiri);
  daunTerkiri = GetDaunTerkiri(P2);
  printf("Daun terkiri di pohon P2: '%c'\n", daunTerkiri);
  daunTerkiri = GetDaunTerkiri(P3);
  printf("Daun terkiri di pohon P3: '%c'\n", daunTerkiri);
  daunTerkiri = GetDaunTerkiri(P4);
  printf("Daun terkiri di pohon P4: '%c'\n", daunTerkiri);

  // Frekuensi X
  printf("--------------------------------------------------\n");
  printf("Menghitung frekuensi elemen tertentu dalam pohon\n");
  printf("--------------------------------------------------\n");
  printf("Frekuensi elemen 'G' di pohon P1: %.2f\n", FrekuensiX(P1, 'G'));
  printf("Frekuensi elemen 'V' di pohon P2: %.2f\n", FrekuensiX(P2, 'V'));
  printf("Frekuensi elemen 'Q' di pohon P3: %.2f\n", FrekuensiX(P3, 'Q'));
  printf("Frekuensi elemen 'R' di pohon P4: %.2f\n", FrekuensiX(P4, 'R'));

  // CountVocal
  printf("--------------------------------------------------\n");
  printf("Menghitung jumlah huruf vokal dalam pohon\n");
  printf("--------------------------------------------------\n");
  printf("Jumlah huruf vokal dalam pohon P1: %d\n", CountVocal(P1));
  printf("Jumlah huruf vokal dalam pohon P2: %d\n", CountVocal(P2));
  printf("Jumlah huruf vokal dalam pohon P3: %d\n", CountVocal(P3));
  printf("Jumlah huruf vokal dalam pohon P4: %d\n", CountVocal(P4));

  // Modus
  printf("--------------------------------------------------\n");
  printf("Menampilkan modus dari pohon\n");
  printf("--------------------------------------------------\n");
  printf("Modus dari pohon P1: '%c'\n", Modus(P1));
  printf("Modus dari pohon P2: '%c'\n", Modus(P2));
  printf("Modus dari pohon P3: '%c'\n", Modus(P3));
  printf("Modus dari pohon P4: '%c'\n", Modus(P4));

  // Dealokasi pohon
  printf("--------------------------------------------------\n");
  printf("Dealokasi semua pohon yang digunakan\n");
  printf("--------------------------------------------------\n");
  Dealokasi(&P1);
  Dealokasi(&P2);
  Dealokasi(&P3);
  Dealokasi(&P4);
  printf("Semua pohon yang digunakan berhasil di-dealokasi\n");

  printf("--------------------------------------------------\n");
  printf("--------------------------------------------------\n");
  printf("Pengujian selesai.\n");

  return 0;
}