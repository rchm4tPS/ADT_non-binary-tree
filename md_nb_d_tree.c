/**
 * @file md_nb_d_tree.c
 * @author Rachmat Purwa Saputra, 211524054
 * @brief Main driver for testing non-binary tree ADT
 * @version 0.1
 * @date 2022-04-15
 * 
 */

#include "nb_d_tree.c"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    nbTree tree;
    InitTree(&tree);

    nbAddr root = InsertNode(&tree, nil, "Ujang Kartiwa", "Kepala Lembaga");

    nbAddr child1 = InsertNode(&tree, root, "Engkos Koswara", "Kepala Bagian Perencanaan");
    nbAddr child2 = InsertNode(&tree, root, "Hoerul Anam", "Kepala Bagian SDM");
    nbAddr child3 = InsertNode(&tree, root, "Dana Sukirman", "Kepala Bagian Keuangan");

    nbAddr child11 = InsertNode(&tree, child1, "Tati Sulastri", "Kepala Sub Bagian Anggaran");
    nbAddr child12 = InsertNode(&tree, child1, "Irvan Susilo", "Kepala Sub Bagian Pendataan");
    nbAddr child13 = InsertNode(&tree, child1, "Evi Sukaesih", "Kepala Sub Bagian Evaluasi");
    nbAddr child21 = InsertNode(&tree, child2, "Sambas Nugroho", "Kepala Sub Bagian Kepegawaian");
    nbAddr child22 = InsertNode(&tree, child2, "Mujani Gani", "Kepala Sub Bagian Tata Laksana");
    nbAddr child31 = InsertNode(&tree, child3, "Noviyanti", "Kepala Sub Bagian Pelaksana Keuangan");

    nbAddr staf111 = InsertNode(&tree, child11, "Muktadi", "Staf");
    nbAddr staf112 = InsertNode(&tree, child11, "Hartanto Utomo", "Staf");
    nbAddr staf121 = InsertNode(&tree, child12, "Candra Dimuka", "Staf");
    nbAddr staf131 = InsertNode(&tree, child13, "Kartono", "Staf");
    nbAddr staf211 = InsertNode(&tree, child21, "Markonah", "Staf");
    nbAddr staf212 = InsertNode(&tree, child21, "Jaelani Supri Utama", "Staf");
    nbAddr staf213 = InsertNode(&tree, child21, "Ukar Mustopa", "Staf");
    nbAddr staf221 = InsertNode(&tree, child22, "Marcelino", "Staf");
    nbAddr staf222 = InsertNode(&tree, child22, "Opik Taufik", "Staf");

    // nbAddr nodeTemp = findParent(findName(root, "Kartono"));
    // printf("\nAtasan dari kartono adalah %s\n", nodeTemp->nama);

    // nodeTemp = findChild(findName(root, "Sambas Nugroho"));
    // printf("\nBawahan dari Sambas Nugroho.\n");
    // while (nodeTemp != nil)
    // {
    //     printf(" > %s\n", nodeTemp->nama);
    //     nodeTemp = nodeTemp->nb;
    // }

    // nbAddr kabag = findKaBag(tree, "Opik Taufik");
    // printf("\nKepala bagian dari Opik Taufik adalah : %s\n", kabag->nama);

    // printTree(root);

    int menuChosen = -999;
    char namaPejabat[50];
    char jabatan[50];
    char namaAtasan[50];
    nbAddr newNode;

    while (menuChosen != 0) {
        printMenu();
        scanf(" %d", &menuChosen);
        
        switch (menuChosen)
        {
            case 1:
                // Menambah jabatan
                printf("\n Siapa nama pejabat yg akan ditambahkan ke daftar : ");
                scanf(" %[^\n]%*c", namaPejabat);
                printf(" Apa jabatannya : ");
                scanf(" %[^\n]%*c", jabatan);
                printf(" Siapa atasannya : ");
                scanf(" %[^\n]%*c", namaAtasan);

                newNode = InsertNode(&tree, findName(root, namaAtasan), namaPejabat, jabatan);

                break;
            case 2:
                // Menelusuri pejabat
                printf("\n Baik. Ingin menelusuri apa?\n [9 untuk atasan, 99 untuk bawahan, dan 100 untuk kepala bagian]  ---> ");
                scanf(" %d", &menuChosen);

                if(menuChosen == 9)
                {
                    printf("Siapa nama pejabat yang ingin diketahui atasannya : ");
                    scanf(" %[^\n]%*c", namaPejabat);

                    newNode = findParent(findName(root, namaPejabat));

                    if (newNode != nil) {
                        printf("\nAtasan dari %s adalah %s\n", namaPejabat, newNode->nama);
                    } else {
                        printf("\nMaaf, sepertinya ia merupakan kepala lembaga.\nIa adalah atasan tertinggi disini\n\n");
                    }
                    
                }
                else if (menuChosen == 99)
                {
                    printf("Siapa nama pejabat yang ingin diketahui bawahannya : ");
                    scanf(" %[^\n]%*c", namaPejabat);

                    newNode = findChild(findName(root, namaPejabat));

                    printf("\nBawahan dari %s.\n", namaPejabat);
                    if (newNode == nil) printf(" > TIDAK ADA (N/A)\n");

                    while (newNode != nil)
                    {
                        printf(" > %s\n", newNode->nama);
                        newNode = newNode->nb;
                    }
                                        
                    newNode = AlokasiNode("", "", nil, nil, nil);
                }
                else if (menuChosen == 100)
                {
                    printf("Siapa nama pejabat yang ingin diketahui kepala bagiannya : ");
                    scanf(" %[^\n]%*c", namaPejabat);

                    newNode = findKaBag(tree, namaPejabat);
                    
                    if (newNode != nil)
                        printf("\nKepala bagian dari %s adalah : %s\n", namaPejabat, newNode->nama);
                    else 
                        printf("\nMohon maaf, tidak ada ketua bagian dengan nama tersebut disini...\n");
                }
                else {
                    printf("\n Harap memasukkan angka 9, 99, atau 100 yaa!\n");
                }
                
                break;
            case 3:
                // Melihat para pejabat
                printTree(root);
                break;
            case 0:
                // Mencoba hapus tree saat keluar
                deleteTree(&tree);
                if (tree.root == nil) printf("\n > Tree dikosongkan. . .\n");
                exit(0);

            default:
                printf("\n\t >>> WARNING!! Harap memasukkan pilihan 0, 1, 2, atau 3!\n\t ========== >>> <<< ==========\n\n");
        }
    }

    return 0;
}
