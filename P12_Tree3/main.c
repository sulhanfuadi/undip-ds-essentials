/* File : main.c */
/* Deskripsi : aplikasi driver ADT bintree3 berkait dengan representasi fisik pointer */
/* NIM & Nama : 24060123130115 & Sulhan Fuadi*/
/* Tanggal : 06 Desember 2024 */

#include <stdio.h>
#include <stdlib.h>
#include "pohon3.c"
#include "list1.c"

int main() {
  //kamus
  bintree3 W;
  List1 L;

  //algoritma
  W = Tree3(NIL,'A',false,
            Tree3(NIL,'B',false, 
                  NIL, 
                  Tree3(NIL,'D',false,NIL,NIL)),
            Tree3(NIL,'C',false, 
                  Tree3(NIL,'E',false,NIL,NIL),
                  Tree3(NIL,'F',false,NIL,NIL)));
  
  // Print Depth-First Search (DFS)
  printf("DFS Traversal: ");
  printDFS(W);
  printf("\n");

  // Print Path to Node 'D'
  printf("Path to Node 'D': ");
  printPathX(W, 'D');
  printf("\n");

  // Print Path to Leaf Node 'D'
  printf("Path to Leaf Node 'D': ");
  printPathDaunX(W, 'D');
  printf("\n");

  // Print All Paths from Root to Leaves
  printf("All Paths from Root to Leaves: ");
  printAllPaths(W);
  printf("\n");

  // Print Number of Elements in Tree
  printf("Number of Elements in Tree: %d\n", NbElmTree(W));

  // Print Number of Leaves in Tree
  printf("Number of Leaves in Tree: %d\n", NbDaun(W));

  // Print Height of Tree
  printf("Height of Tree: %d\n", Tinggi(W));

  // Print Level of Node 'D'
  printf("Level of Node 'D': %d\n", Level(left(right(W))));

  // Print Number of Nodes at Level 2
  printf("Number of Nodes at Level 2: %d\n", CountLevelT(W, 2));

  // Print Nodes at Level 2
  printf("Nodes at Level 2: ");
  PrintLevel(W, 2);
  printf("\n");

  // Print Breadth-First Search (BFS)
  printf("BFS Traversal: ");
  PrintBFS(W);
  printf("\n");

  // Reset Visited Nodes
  resetVisited(W);
  printf("Visited nodes reset.\n");

  // Linearization Tests
  printf("Linear Prefix: ");
  L = LinearPrefix(W);
  PrintList(L);
  printf("\n");

  printf("Linear Postfix: ");
  L = LinearPosfix(W);
  PrintList(L);
  printf("\n");

  printf("Linear Infix: ");
  L = LinearInfix(W);
  PrintList(L);
  printf("\n");

  printf("Linear Breadth-First Search: ");
  L = LinearBreadthFS(W);
  PrintList(L);
  printf("\n");

  return 0;
}