/* Program   : matriks.c */
/* Deskripsi : file BODY modul matriks integer */
/* NIM/Nama  : 24060123130115/Sulhan Fuadi */
/* Tanggal   : 13 September 2024*/
/***********************************/

#include <stdio.h>
#include <stdlib.h>
#include "matriks.h"

/* KONSTRUKTOR */		
/* procedure initMatriks(output M: Matriks)
	{I.S.: - }
	{F.S.: Matriks M terdefinisi}
	{Proses mengisi elemen cell dengan -999, nbaris 0, nkolom 0} */
void initMatriks(Matriks *M) {
  /* Kamus Lokal */
  int i, j;
  
  /* Algoritma */
  for (i = 1; i <= 10; i++) {
    for (j = 1; j <= 10; j++) {
      (*M).cell[i][j] = -999;
    }
  }
  (*M).nbaris = 0;
  (*M).nkolom = 0;
}

/* SELEKTOR */
/* function getNBaris(M: Matriks) -> integer
	{mengembalikan banyak baris matriks M yang terisi } */
int getNBaris(Matriks M) {
  /* Kamus Lokal */
  
  /* Algoritma */
  return M.nbaris;
}

/* function getNKolom(M: Matriks) -> integer
	{mengembalikan banyak kolom matriks M yang terisi } */
int getNKolom(Matriks M) {
  /* Kamus Lokal */
  
  /* Algoritma */
  return M.nkolom;
}

/* PREDIKAT */
/* function isEmptyMatriks(M: Matriks) -> boolean
	{mengembalikan True jika matriks M kosong } */
boolean isEmptyMatriks(Matriks M) {
  /* Kamus Lokal */
  
  /* Algoritma */
  return (M.nbaris == 0 && M.nkolom == 0);
}

/* function isFullMatriks(M: Matriks) -> boolean
	{mengembalikan True jika matriks M penuh } */
boolean isFullMatriks(Matriks M) {
  /*Kamus lokal*/
	int i,j,jum;

  /*Algoritma*/
	jum = 0;
  for (i = 1; i <= 10; i++) {
    for (j = 1; j <= 10; j++) {
      if (M.cell[i][j] != -999){
        jum++;
      }
    }
  }
	return jum == 100;
}

/* OPERASI PENCARIAN*/
/* procedure searchX( input M:Matriks, input X: integer, output row: integer, output col: integer )
	{I.S.: M terdefinisi, X terdefinisi }
	{F.S.: row berisi indeks baris dan col berisi indeks kolom ketemu X di M.cell, atau -999 jika tidak ketemu}
	{Proses: mencari elemen bernilai X dalam M.cell} */
void searchX(Matriks M, int X, int *row, int *col) {
  /* Kamus lokal */
  int i, j;
  int found = 0;

  /* Algoritma */
  *row = -999;
  *col = -999;
  if (!isEmptyMatriks(M)) {
    for (i = 1; i <= getNBaris(M) && !found; i++) {
      for (j = 1; j <= getNKolom(M); j++) {
        if (M.cell[i][j] == X) {
          *row = i;
          *col = j;
          found = 1;
          break;
        }
      }
    }
  }
}

/* function countX (M:Matriks, X: integer) -> integer
	{mengembalikan banyaknya elemen bernilai X dalam M.cell} */
int countX (Matriks M, int X) {
  /* Kamus Lokal */
  int i, j, count;

  /* Algoritma */
  count = 0;
  if (isEmptyMatriks(M)){
    return count;
  } else {
    for (i = 1; i <= getNBaris(M);i++){
      for (j = 1; j <= getNKolom(M); j++){
        if (M.cell[i][j] == X){
          count += 1;
        }
      }
    }
    return count;
  }
}

/* MUTATOR */
/* procedure addX (input/output M:Matriks, input X:integer, row:integer, col:integer)
	{I.S.: M terdefinisi, X terdefinisi }
	{F.S.: isi M.cell bertambah 1 elemen pada baris ke-row dan kolom ke-col jika belum penuh}
	{Proses: mengisi elemen M.cell dengan nilai X} */
void addX (Matriks *M, int X, int row, int col) {
  /* Kamus Lokal */
  
  /* Algoritma */
  if ((!isFullMatriks(*M)) && ((*M).cell[row][col] = -999)) {
    (*M).cell[row][col] = X;
    if (row > getNBaris(*M)) {
      (*M).nbaris = row;
    }
    if (col > getNKolom(*M)) {
      (*M).nkolom = col;
    }
  }
}

/* procedure editX (input/output M:Matriks, input X:integer, row:integer, col:integer)
	{I.S.: M terdefinisi, X terdefinisi }
	{F.S.: isi M.cell pada baris ke-row dan kolom ke-col diubah dengan nilai X}
	{Proses: mengubah isi M.cell pada baris ke-row dan kolom ke-col dengan nilai X} */
void editX (Matriks *M, int X, int row, int col) {
  /* Kamus Lokal */
  
  /* Algoritma */
  if (!isEmptyMatriks(*M)) {
    (*M).cell[row][col] = X;
  }
}

/* procedure delX (input/output M:Matriks, input X:integer )
	{I.S.: M terdefinisi, X terdefinisi}
	{F.S.: elemen M.cell berkurang 1}
	{Proses: menghapus 1 elemen bernilai X dari M.cell*/
void delX (Matriks *M, int X) {
  /* Kamus Lokal */
  int i, j, row, col;
  int hasValueInRow, hasValueInCol;
  
  /* Algoritma */
  searchX(*M, X, &row, &col);
  if ((!isEmptyMatriks(*M)) && (row != -999 && col != -999)) {
    (*M).cell[row][col] = -999;
  }

  // Cek baris kosong setelah penghapusan
  for (i = (*M).nbaris - 1; i >= 0; i--) {
    hasValueInRow = 0;
    for (j = 0; j < (*M).nkolom; j++) {
      if ((*M).cell[i][j] != -999) {
        hasValueInRow = 1;
        break;
      }
    }
    if (hasValueInRow == 0) {
      (*M).nbaris--;
    } else {
      break;
    }
  }

  // Cek kolom kosong setelah penghapusan
  for (j = (*M).nkolom - 1; j >= 0; j--) {
    hasValueInCol = 0;
    for (i = 0; i < (*M).nbaris; i++) {
      if ((*M).cell[i][j] != -999) {
        hasValueInCol = 1;
        break;
      }
    }
    if (hasValueInCol == 0) {
      (*M).nkolom--;
    } else {
      break;
    }
  }
}

/* procedure isiMatriksRandom(input/output M: Matriks, input x: integer, input y: integer)
	{I.S.: M terdefinisi}
	{F.S.: M terisi dengan bilangan random sejumlah x baris dan y kolom, nbaris=x, nkolom=y}
	{proses: mengisi matriks dengan bilangan integer random dengan jumlah baris x dan kolom y} */
void isiMatriksRandom(Matriks *M, int x, int y) {
  /* Kamus Lokal */
  int i, j, random;
  
  /* Algoritma */
  for (i = 1; i <= x; i++) {
    for (j = 1; j <= y; j++) {
      random = rand() % 100; // rand() % 100 will produce a random number in the range [0, 99]
      addX(&(*M), random, i, j);
    }
  }
  (*M).nbaris = x;
  (*M).nkolom = y;
}

/* procedure isiMatriksIdentitas(input/output M: Matriks, input n: integer)
	{I.S.: M terdefinisi}
	{F.S.: M terisi dengan matriks identitas berukuran n x n, nbaris=nkolom=n}
	{proses: mengisi matriks dengan matriks identitas berukuran n x n} */
void isiMatriksIdentitas(Matriks *M, int n) {
  /* Kamus Lokal */
  int i, j;
  
  /* Algoritma */
  for (i = 1; i <= n; i++) {
    for (j = 1; j <= n; j++) {
      if (i == j) {
        addX(&(*M), 1, i, j);
      } else {
        addX(&(*M), 0, i, j);
      }
    }
  }
  (*M).nbaris = n;
  (*M).nkolom = n;
}

/* OPERASI BACA/TULIS */
/* procedure populateMatriks(input/output M: Matriks, input x: integer, input y: integer)
{I.S.: M terdefinisi}
{F.S.: M terisi dengan inputan dari keybord sejumlah x baris dan y kolom, nbaris=x, nkolom=y}
{proses: mengisi matriks dengan meminta inputan dari keyboard dengan jumlah baris x dan kolom y} */
void populateMatriks(Matriks *M, int x, int y) {
  /* Kamus Lokal */
  int i, j;
  
  /* Algoritma */
  // if(isFullMatriks(*M) == false){
  //   for(i = getNBaris(*M); i <= getNBaris(*M) + x; i++){
	// 		for(j = getNKolom(*M); j <= getNKolom(*M) + y; j++){
	// 			printf("Masukkan elemen baris ke-%d kolom ke-%d: ",i,j);
	// 			scanf("%d",&(*M).cell[i][j]);
	// 		}
	// 	}
	// 	(*M).nbaris = x;
	// 	(*M).nkolom = y;
	// }
  for (i = 1; i <= x; i++) {
    for (j = 1; j <= y; j++) {
      printf("Masukkan elemen baris ke-%d kolom ke-%d: ", i, j);
      scanf("%d", &(*M).cell[i][j]);
    }
  }
  (*M).nbaris = x;
  (*M).nkolom = y;
}

/* procedure printMatriks(input M:Matriks)
	{I.S.: M terdefinisi}
	{F.S.: -}
	{Proses: menampilkan semua elemen M.cell ke layar} */
void printMatriks(Matriks M) {
  /* Kamus Lokal */
  int i, j;
  
  /* Algoritma */
  if(!isEmptyMatriks(M)){
    for (i = 1; i <= 10; i++) {
      for (j = 1; j <= 10; j++) {
        printf("%d ", M.cell[i][j]);
      }
      printf("\n");
    }
  }
}

/* procedure viewMatriks (input M:Matriks)
	{I.S.: M terdefinisi}
	{F.S.: -}
	{Proses: menampilkan elemen M.cell yang terisi ke layar} */
void viewMatriks (Matriks M) {
  /* Kamus Lokal */
  int i, j;
  
  /* Algoritma */
  if(!isEmptyMatriks(M)){
    for (i = 1; i <= getNBaris(M); i++) {
      for (j = 1; j <= getNKolom(M); j++) {
        if (M.cell[i][j] != -999) {
          printf("%d ", M.cell[i][j]);
        }
      }
      printf("\n");
    }
  }
}

/* OPERASI ARITMATIKA */
/* function addMatriks(M1,M2: Matriks) -> Matriks
{mengembalikan hasil penjumlahan matriks M1 dengan M2} */
Matriks addMatriks(Matriks M1, Matriks M2) {
  /* Kamus Lokal */
  Matriks M;
  int i, j;
  
  /* Algoritma */
  initMatriks(&M);
  if (getNBaris(M1) == getNBaris(M2) && getNKolom(M1) == getNKolom(M2)) {
    for (i = 1; i <= getNBaris(M1); i++) {
      for (j = 1; j <= getNKolom(M1); j++) {
        if (M1.cell[i][j] != -999 && M2.cell[i][j] != -999) {
          M.cell[i][j] = M1.cell[i][j] + M2.cell[i][j];
        } else {
          M.cell[i][j] = -999;
        }
      }
    }
    M.nbaris = getNBaris(M1);
		M.nkolom = getNKolom(M1);
    return M;
  } else {
    printf("Ukuran matriks tidak sama, operasi tidak bisa dijalankan\n");
    return M;
  }
}

/* function subMatriks(M1,M2: Matriks) -> Matriks
{mengembalikan hasil pengurangan antara matriks M1 dengan M2} */
Matriks subMatriks(Matriks M1, Matriks M2) {
  /* Kamus Lokal */
  Matriks M;
  int i, j;
  
  /* Algoritma */
  initMatriks(&M);
  if (getNBaris(M1) == getNBaris(M2) && getNKolom(M1) == getNKolom(M2)) {
    for (i = 1; i <= getNBaris(M1); i++) {
      for (j = 1; j <= getNKolom(M1); j++) {
        if (M1.cell[i][j] != -999 && M2.cell[i][j] != -999) {
          M.cell[i][j] = M1.cell[i][j] - M2.cell[i][j];
        } else {
          M.cell[i][j] = -999;
        }
      }
    }
    M.nbaris = getNBaris(M1);
		M.nkolom = getNKolom(M1);
    return M;
  } else {
    printf("Ukuran matriks tidak sama, operasi tidak bisa dijalankan\n");
    return M;
  }
}

/* function kaliMatriks(M1,M2: Matriks) -> Matriks
{mengembalikan hasil perkalian antara matriks M1 dengan M2} */
Matriks kaliMatriks(Matriks M1, Matriks M2) {
  /* Kamus Lokal */
  Matriks M;
  int i, j, k;
  
  /* Algoritma */
  initMatriks(&M);
  if (getNKolom(M1) == getNBaris(M2)) {
    for (i = 1; i <= getNBaris(M1); i++) {
      for (j = 1; j <= getNKolom(M2); j++) {
        M.cell[i][j] = 0;
        for (k = 1; k <= getNKolom(M1); k++) {
          if (M1.cell[i][k] != -999 && M2.cell[k][j] != -999) {
            M.cell[i][j] += M1.cell[i][k] * M2.cell[k][j];
          }
        }
      }
    }
    M.nbaris = getNBaris(M1);
    M.nkolom = getNKolom(M2);
    return M;
  } else {
    printf("Ukuran matriks tidak sesuai aturan, operasi tidak bisa dijalankan\n");
    return M;
  }
}

/* function kaliSkalarMatriks(M: Matriks, x: integer) -> Matriks
{mengembalikan perkalian antara matriks M dengan nilai skalar x} */
Matriks kaliSkalarMatriks(Matriks M1, int x) {
  /* Kamus Lokal */
  Matriks M;
  int i, j;
  
  /* Algoritma */
  initMatriks(&M);
  for (i = 1; i <= getNBaris(M1); i++) {
    for (j = 1; j <= getNKolom(M1); j++) {
      if (M1.cell[i][j] == -999) {
        M.cell[i][j] = -999;
      } else {
        M.cell[i][j] = M1.cell[i][j] * x;
      }
    }
  }
  M.nbaris = getNBaris(M1);
  M.nkolom = getNKolom(M1);
  return M;
}

/* OPERASI STATISTIK*/
/* function getSumMatriks (M:Matriks) -> integer 
	{mengembalikan jumlah semua elemen pengisi M.cell} */
int getSumMatriks (Matriks M) {
  /* Kamus Lokal */
  int i, j, sum;
  
  /* Algoritma */
  sum = 0;
  for (i = 1; i <= getNBaris(M); i++) {
    for (j = 1; j <= getNKolom(M); j++) {
      if (M.cell[i][j] != -999){
        sum += M.cell[i][j];
      }
    }
  }
  return sum;
}

/* function getAveragematriks (M:Matriks) -> real 
	{mengembalikan nilai rata-rata elemen pengisi M.cell} */
float getAverageMatriks (Matriks M) {
  /*Kamus lokal*/
  int i,j;
	float count;

  /*Algoritma*/
	count = 0;
  for (i = 1; i <= getNBaris(M); i++){
    for(j = 1; j <= getNKolom(M); j++){
      if (M.cell[i][j] != -999){
        count++;
      }
    }
  }
  if (count == 0){
    printf("Tidak bisa didapatkan rerata, Matriks merupakan matriks kosong \n");
  } else {
    return getSumMatriks(M)/count;
  }
}

/* function getMaxMatriks (M:Matriks) -> integer
	{mengembalikan nilai elemen terbesar pengisi M.cell } */
int getMaxMatriks (Matriks M) {
  /* Kamus Lokal */
  int i, j, max;
  
  /* Algoritma */
  max = M.cell[1][1];
  for (i = 1; i <= getNBaris(M); i++) {
    for (j = 1; j <= getNKolom(M); j++) {
      if (M.cell[i][j] > max) {
        max = M.cell[i][j];
      }
    }
  }
  return max;
}

/* function getMinMatriks (M:Matriks) -> integer
	{mengembalikan nilai elemen terkecil pengisi M.cell} */
int getMinMatriks (Matriks M) {
  /* Kamus Lokal */
  int i, j, min;
  
  /* Algoritma */
  min = M.cell[1][1];
  for (i = 1; i <= getNBaris(M); i++) {
    for (j = 1; j <= getNKolom(M); j++) {
      if ((M.cell[i][j] < min) && (M.cell[i][j] != -999)) {
        min = M.cell[i][j];
      }
    }
  }
  return min;
}

/* OPERASI LAINNYA */
/* procedure transposeMatriks(input/output M: Matriks)
	{I.S.: M terdefinisi}
	{F.S.: Matriks M sudah ditukar susunan baris dan kolomnya (Transpose)}
	{proses: mengubah susunan cell matriks, M.cell[i,j] menjadi M.cell[j,i]} */
void transposeMatriks(Matriks *M) {
  /* Kamus Lokal */
  Matriks temp;
  int i, j;
  
  /* Algoritma */
  initMatriks(&temp);
  for (i = 1; i <= getNBaris(*M); i++) {
    for (j = 1; j <= getNKolom(*M); j++) {
      temp.cell[j][i] = (*M).cell[i][j];
    }
  }
  temp.nbaris = (*M).nkolom;
  temp.nkolom = (*M).nbaris;
  (*M) = temp;
}

/* function getTransposeMatriks(M: Matriks)
	{menghasilkan sebuah matriks yang merupakan hasil transpose dari matriks M} */
Matriks getTransposeMatriks(Matriks M) {
  /* Kamus Lokal */
  Matriks Mtranspose;
  
  /* Algoritma */
  Mtranspose = M;
  transposeMatriks(&Mtranspose);
  return Mtranspose;
}
