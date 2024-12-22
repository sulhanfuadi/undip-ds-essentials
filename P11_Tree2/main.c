/* File : main.c */
/* Deskripsi : aplikasi driver ADT bintree2 berkait dengan representasi fisik pointer */
/* NIM & Nama : 24060123130115 & Sulhan Fuadi*/
/* Tanggal : 29 November 2024 */

#include <stdio.h>
#include <stdlib.h>
#include "pohon1.c"
#include "pohon2.c"

int main() {
    //kamus
    bintree P1, P2, P3, P4, P5, P6, A, BST;
    int n;
    infotype daunTerkiri, X;

    //algoritma
    //Membuat pohon
    P1 = Tree('A', Tree('B', Tree('C', Tree('D', NIL, NIL), NIL), NIL), Tree('E', NIL, Tree('F', Tree('F', Tree('J', NIL, NIL), NIL), Tree('G', NIL, Tree('F', NIL, NIL)))));
    P2 = Tree('X', Tree('Y', Tree('Y', NIL, NIL), Tree('Z', NIL, NIL)), Tree('W', NIL, NIL));
    P3 = Tree('L', Tree('M', Tree('N', NIL, NIL), NIL), Tree('O', Tree('P', NIL, NIL), NIL));
    P4 = Tree('K', NIL, Tree('J', NIL, NIL));
    P5 = Tree('R', Tree('S', NIL, NIL), Tree('T', NIL, NIL));
    P6 = Tree('U', Tree('V', NIL, NIL), Tree('W', NIL, NIL));
    BST = Tree('F', Tree('A', NIL, Tree('C', NIL, NIL)), Tree('H', NIL, Tree('J', Tree('I', NIL, Tree('K', NIL, NIL)), NIL)));

    //Menampilkan untuk semua pohon
    printf("\n--------------------------------------------------\n");
    printf("Menampilkan untuk semua pohon\n");
    printf("--------------------------------------------------\n");
    printf("\nMenampilkan Pohon P1: \n");
    PrintTreeInden(P1, 2);
    printf("\nMenampilkan Pohon P2: \n");
    PrintTreeInden(P2, 2);
    printf("\nMenampilkan Pohon P3: \n");
    PrintTreeInden(P3, 2);
    printf("\nMenampilkan Pohon P4: \n");
    PrintTreeInden(P4, 2);
    printf("\nMenampilkan Pohon P5: \n");
    PrintTreeInden(P5, 2);
    printf("\nMenampilkan Pohon P6: \n");
    PrintTreeInden(P6, 2);

    //Menampilkan semua akar pada level N
    // printf("\n");
    printf("\n\n--------------------------------------------------\n");
    printf("Menampilkan semua akar pada level N\n");
    printf("--------------------------------------------------\n");
    printf("\nMenampilkan elemen pada level %d di Pohon P1\n", 3);
    PrintLevel(P1, 3);
    printf("\nMenampilkan elemen pada level %d di Pohon P2\n", 2);
    PrintLevel(P2, 2);
    printf("\nMenampilkan elemen pada level %d di Pohon P3\n", 2);
    PrintLevel(P3, 2);
    printf("\nMenampilkan elemen pada level %d di Pohon P4\n", 1);
    PrintLevel(P4, 1);

    //Membuat balance tree
    printf("\n\n--------------------------------------------------\n");
    printf("Membuat Pohon Balance\n");
    printf("--------------------------------------------------\n");
    A = BuildBalanceTree(7);
    printf("\n\nMenampilkan Pohon A: \n");
    PrintTreeInden(A, 2);

    //Apakah pohon balance?
    printf("\n\n--------------------------------------------------\n");
    printf("Mengecek Pohon Balance\n");
    printf("--------------------------------------------------\n");
    printf("\nApakah pohon P1 balance? %s", IsBalanceTree(P1) ? "Ya" : "Tidak");
    printf("\nApakah pohon P2 balance? %s", IsBalanceTree(P2) ? "Ya" : "Tidak");
    printf("\nApakah pohon P3 balance? %s", IsBalanceTree(P3) ? "Ya" : "Tidak");
    printf("\nApakah pohon P4 balance? %s", IsBalanceTree(P4) ? "Ya" : "Tidak");

    //Menambahkan ke daun terkiri
    printf("\n\n--------------------------------------------------\n");
    printf("Menambahkan daun terkiri\n");
    printf("--------------------------------------------------\n");
    AddDaunTerkiri(P1, 'U');
    printf("\nMenampilkan Pohon P1: \n");
    PrintTreeInden(P1, 2);
    AddDaunTerkiri(P2, 'L');
    printf("\nMenampilkan Pohon P2: \n");
    PrintTreeInden(P2, 2);
    AddDaunTerkiri(P3, 'B');
    printf("\nMenampilkan Pohon P3: \n");
    PrintTreeInden(P3, 2);
    AddDaunTerkiri(P4, 'F');
    printf("\nMenampilkan Pohon P4: \n");
    PrintTreeInden(P4, 2);

    //Menambahkan daun
    printf("\n\n--------------------------------------------------\n");
    printf("Menambah daun\n");
    printf("--------------------------------------------------\n");
    AddDaun(P1, 'A', 'Q', true);
    printf("\nMenampilkan Pohon P1: \n");
    PrintTreeInden(P1, 2);
    AddDaun(P2, 'W', 'T', false);
    printf("\nMenampilkan Pohon P2: \n");
    PrintTreeInden(P2, 2);
    AddDaun(P3, 'O', 'D', true);
    printf("\nMenampilkan Pohon P3: \n");
    PrintTreeInden(P3, 2);
    AddDaun(P4, 'K', 'C', false);
    printf("\nMenampilkan Pohon P4: \n");
    PrintTreeInden(P4, 2);

    //Insert X
    printf("\n\n--------------------------------------------------\n");
    printf("Insert X\n");
    printf("--------------------------------------------------\n");
    InsertX(P1, 'V');
    printf("\nMenampilkan Pohon P1: \n");
    PrintTreeInden(P1, 2);
    InsertX(P2, 'O');
    printf("\nMenampilkan Pohon P2: \n");
    PrintTreeInden(P2, 2);
    InsertX(P3, 'P');
    printf("\nMenampilkan Pohon P3: \n");
    PrintTreeInden(P3, 2);
    InsertX(P4, 'U');
    printf("\nMenampilkan Pohon P4: \n");
    PrintTreeInden(P4, 2);

    //Menghapus daun terkiri X
    printf("\n\n--------------------------------------------------\n");
    printf("Hapus Daun Terkiri\n");
    printf("--------------------------------------------------\n");
    DelDaunTerkiri(&P1, &daunTerkiri);
    printf("\nMenampilkan Pohon P1: \n");
    PrintTreeInden(P1, 2);
    printf("\n\nDaun terkiri P1 yang dihapus: '%c'\n", daunTerkiri);

    DelDaunTerkiri(&P5, &daunTerkiri);
    printf("\nMenampilkan Pohon P5: \n");
    PrintTreeInden(P5, 2);
    printf("\n\nDaun terkiri P5 yang dihapus: '%c'\n", daunTerkiri);

    //Menghapus daun X
    printf("\n--------------------------------------------------\n");
    printf("Hapus Daun X\n");
    printf("--------------------------------------------------\n");
    printf("\nMenghapus daun F dari Pohon P1");
    DelDaun(&P1, 'F');
    printf("\nMenampilkan Pohon P1: \n");
    PrintTreeInden(P1, 2);
    printf("\n");
    printf("\nMenghapus daun T dari Pohon P2");
    DelDaun(&P2, 'T');
    printf("\nMenampilkan Pohon P2: \n");
    PrintTreeInden(P2, 2);

    //Menghapus simpul X
    printf("\n\n--------------------------------------------------\n");
    printf("Hapus Simpul X\n");
    printf("--------------------------------------------------\n");
    printf("\nMenghapus simpul B dari pohon P1");
    DeleteX(&P1, 'B');
    printf("\nMenampilkan Pohon P1: \n");
    PrintTreeInden(P1, 2);
    
    //Mengupdate semua X menjadi Y
    printf("\n\n--------------------------------------------------\n");
    printf("Mengupdate Semua X Menjadi Y\n");
    printf("--------------------------------------------------\n");
    printf("\nMengupdate semua F menjadi Q di pohon P1");
    UpdateAllX(&P1, 'F', 'Q');
    printf("\nMenampilkan Pohon P1: \n");
    PrintTreeInden(P1, 2);

    //Mencari huruf terbesar
    printf("\n\n--------------------------------------------------\n");
    printf("Mencari Huruf Terbesar\n");
    printf("--------------------------------------------------\n");
    printf("\nElemen terbesar di pohon P1 adalah: %c", maxTree(P1));
    printf("\nElemen terbesar di pohon P2 adalah: %c", maxTree(P2));
    printf("\nElemen terbesar di pohon P3 adalah: %c", maxTree(P3));
    printf("\nElemen terbesar di pohon P4 adalah: %c", maxTree(P4));

    //Mencari huruf terkecil
    printf("\n\n--------------------------------------------------\n");
    printf("Mencari Huruf Terkecil\n");
    printf("--------------------------------------------------\n");
    printf("\nElemen terkecil di pohon P1 adalah: %c", minTree(P1));
    printf("\nElemen terkecil di pohon P2 adalah: %c", minTree(P2));
    printf("\nElemen terkecil di pohon P3 adalah: %c", minTree(P3));
    printf("\nElemen terkecil di pohon P4 adalah: %c", minTree(P4));

    //Binary Search Tree

    //Mencari X di BST
    printf("\n\n--------------------------------------------------\n");
    printf("Mencari X di BST\n");
    printf("--------------------------------------------------\n");
    printf("\nApakah F ada di BST? %s", BSearch(BST, 'F') ? "Ya" : "Tidak");
    printf("\nMenampilkan Pohon BST: \n");
    PrintTreeInden(BST, 2);

    //Menambahkan X ke BST
    printf("\n\n--------------------------------------------------\n");
    printf("Menambahkan X ke BST\n");
    printf("--------------------------------------------------\n");
    printf("\nMenambahkan L di BST");
    InsSearch(BST, 'L');
    printf("\nMenampilkan Pohon BST: \n");
    PrintTreeInden(BST, 2);

    //Menghapus X di BST
    printf("\n\n--------------------------------------------------\n");
    printf("Menghapus X dari BST\n");
    printf("--------------------------------------------------\n");
    printf("\nMenghapus L di BST");
    DelBtree(&BST, 'L');
    printf("\nMenampilkan Pohon BST: \n");
    PrintTreeInden(BST, 2);

    return 0;
}
