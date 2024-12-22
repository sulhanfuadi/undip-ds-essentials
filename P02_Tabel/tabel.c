#ifndef   tabel_c
#define   tabel_c
#include "tabel.h"
/* Deskripsi : realisasi body modul Tabel*/
/* NIM/Nama  : 24060123130115/Sulhan Fuadi */
/* Tanggal   : 06 September 2024*/

void createTable (Tabel *T) {
  (*T).size = 0;
  for (int i = 1; i <= 10; i++) {
    (*T).wadah[i] = -999;
  }
};

int getSize (Tabel T) {
  return T.size;
};

boolean isEmptyTable (Tabel T) {
  return T.size == 0;
};

boolean isFullTable (Tabel T){
  return T.size == 10;
};

int searchX (Tabel T, int X) {
  int i = 1;
  while (i <= T.size && T.wadah[i] != X) {
    i++;
  }
  if (i > T.size) {
    return 0;
  } else {
    return i;
  }
}

int countX (Tabel T, int X) {
  int count = 0;
  for (int i = 1; i <= T.size; i++) {
    if (T.wadah[i] == X) {
      count++;
    }
  }
  return count;
}

int countEmpty (Tabel T) {
  // return 10 - T.size;
  int count = 0;
  for (int i = 1; i <= 10; i++) {
    if (T.wadah[i] == -999) {
      count++;
    }
  }
  return count;
}

void addXTable (Tabel *T, int X) {
  if (!isFullTable(*T)) {
    (*T).size++;
    (*T).wadah[(*T).size] = X;
  }
}

void delXTable (Tabel *T, int X) {
  int pos = searchX(*T, X);
  if (!isEmptyTable(*T) && pos != 0) {
    for (int i = pos; i < (*T).size; i++) {
      (*T).wadah[i] = (*T).wadah[i + 1];
    }
    (*T).wadah[(*T).size] = -999;
    (*T).size--;
  }
}

void delAllXTable (Tabel *T, int X) {
  int pos = searchX(*T, X);
  if (!isEmptyTable(*T)) {
    while (pos != 0) {
      for (int i = pos; i < (*T).size; i++) {
        (*T).wadah[i] = (*T).wadah[i + 1];
      }
      (*T).wadah[(*T).size] = -999;
      (*T).size--;
      pos = searchX(*T, X);
    }
  }
}

void printTable (Tabel T) {
  for (int i = 1; i <= 10; i++) {
    printf("%d ", T.wadah[i]);
  }
  printf("\n");
}

void viewTable (Tabel T) {
  for (int i = 1; i <= T.size; i++) {
    printf("%d ", T.wadah[i]);
  }
  printf("\n");
}

void populate1 (Tabel *T, int N) {
  for (int i = 1; i <= N; i++) {
    int X;
    scanf("%d", &X);
    addXTable(T, X);
  }
}

// void populate2 (Tabel *T, int N) {
//   for (int i = 1; i <= N; i++) {
//     int X;
//     scanf("%d", &X);
//     if (X > 0) {
//       addXTable(T, X);
//     } else {
//       break;
//     }
//   }
// }

void populate2 (Tabel *T) {
  int X;
  do {
    scanf("%d", &X);
    if (X > 0) {
      addXTable(T, X);
    }
  } while (X > 0);
}

int SumEl (Tabel T) {
  if (!isEmptyTable(T)) {
    int sum = 0;
    for (int i = 1; i <= T.size; i++) {
      sum += T.wadah[i];
    }
    return sum;
  }
}

float AverageEl (Tabel T) {
  if (!isEmptyTable(T)) {
    return (float) SumEl(T) / T.size;
  }
}

int getMaxEl (Tabel T) {
  if (!isEmptyTable(T)) {
    int max = T.wadah[1];
    for (int i = 2; i <= T.size; i++) {
      if (T.wadah[i] > max) {
        max = T.wadah[i];
      }
    }
    return max;
  }
}

int getMinEl (Tabel T) {
  if (!isEmptyTable(T)) {
    int min = T.wadah[1];
    for (int i = 2; i <= T.size; i++) {
      if (T.wadah[i] < min) {
        min = T.wadah[i];
      }
    }
    return min;
  }
}

int Modus (Tabel T) {
  if (!isEmptyTable(T)) {
    int modus = T.wadah[1];
    int count = countX(T, T.wadah[1]);
    for (int i = 2; i <= T.size; i++) {
      if (countX(T, T.wadah[i]) > count) {
        modus = T.wadah[i];
        count = countX(T, T.wadah[i]);
      }
    }
    return modus;
  }
};

void sortAsc (Tabel *T) {
  for (int i = 1; i <= (*T).size; i++) {
    for (int j = i + 1; j <= (*T).size; j++) {
      if ((*T).wadah[i] > (*T).wadah[j]) {
        int temp = (*T).wadah[i];
        (*T).wadah[i] = (*T).wadah[j];
        (*T).wadah[j] = temp;
      }
    }
  }
}

void sortDesc (Tabel *T) {
  for (int i = 1; i <= (*T).size; i++) {
    for (int j = i + 1; j <= (*T).size; j++) {
      if ((*T).wadah[i] < (*T).wadah[j]) {
        int temp = (*T).wadah[i];
        (*T).wadah[i] = (*T).wadah[j];
        (*T).wadah[j] = temp;
      }
    }
  }
}

#endif