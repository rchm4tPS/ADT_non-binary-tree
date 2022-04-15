/**
 * @file nb_d_tree.c
 * @author Rachmat Purwa Saputra, 211524054
 * @brief Definition for non-binary tree allocated dynamically.
 * @version 0.1
 * @date 2022-04-15
 * 
 */

#include "nb_d_tree.h"
#include "boolean.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void InitTree (nbTree* t)
{
    (*t).root = nil;
}

nbAddr AlokasiNode (char* nama, char* jabatan, 
                    nbAddr parent, nbAddr fson, nbAddr nbro)
{
    nbAddr newNode = (nbAddr)malloc(sizeof(struct nbTreeNode));

    strcpy(newNode->nama, nama);
    strcpy(newNode->jabatan, jabatan);
    newNode->parent = parent;
    newNode->fs = fson;
    newNode->nb = nbro;

    return newNode;
}

void deleteNode (nbAddr *node)
{
    // Harus mengecek kondisi apakah node adalah root atau bukan.

    // if (isRoot(*node) == false)
    // {
    //     if ((*node)->nb != nil)
    //     {
    //         (*node)->parent->fs = (*node)->nb;
    //     }
    //     else {
    //         (*node)->parent->fs = nil;
    //     }
    //     (*node)->fs = nil;
    //     (*node)->nb = nil;
    //     (*node)->parent = nil;

    //     free(*node);

    //     printf("\nBerhasil dihapus!\n\n");
    // }
    // else {
    //     printf("\nWARNING!!\nAnda berusaha menghapus seluruh tree!!\nProses penghapusan node dibatalkan . . .\n\n");
    // }
}

void deleteTree (nbTree *tree)
{
    // free(tree->root);
}

nbAddr getParent (nbAddr node)
{
    return node->parent;
}

nbAddr getFirstSon (nbAddr node)
{
    return node->fs;
}

nbAddr getNextBrother (nbAddr node)
{
    return node->nb;
}

void setNewNodeValue (nbAddr* node, char* newName, char* newJabatan)
{
    strcpy((*node)->nama, newName);
    strcpy((*node)->jabatan, newJabatan);
}

nbAddr InsertNode (nbTree* tree, nbAddr parent,
                   char* newName, char* newJabatan)
{
    nbAddr newNode, temp;

    newNode = AlokasiNode(newName, newJabatan, parent, nil, nil);

    // jika berhasil dialokasi
    if (newNode != nil)
    {
        // jika belum punya root tree tsb.
        if (parent == nil)
        {
            tree->root = newNode;
        }
        // jika sudah ada root
        else {
            temp = parent;

            // jika sudah punya first son
            if (temp->fs != nil)
            {
                // cari keberadaan next brother
                temp = temp->fs;
                while (temp->nb != nil)
                {
                    // jika masih ada next brother
                    temp = temp->nb;
                }
                // cari tempat kosong untuk menyimpan node baru sebagai next brother terakhir dari parent tersebut.
                temp->nb = newNode;
            }
            // jika belum punya first son
            else {
                // jadikan node baru sebagai first son dari parent node.
                temp->fs = newNode;
            }

            newNode->parent = parent;
        }
    }
    else {
        printf("Alokasi gagal . . .\n");
    }

    return newNode;
}

boolean isLeafNode (nbAddr node)
{
    return (node->fs == nil);
}

boolean isRoot (nbAddr node)
{
    return (node->parent == nil && node->nb == nil);
}

void printTree (nbAddr node)
{
    if (node != nil)
    {
        printf("%s - %s\n", node->nama, node->jabatan);
        printTree(node->fs);
        printTree(node->nb);
    }
}

void printMenu ()
{
    printf("\n\n\n\t >>>>> APLIKASI KEPEJABATAN <<<<< \n\n");
    printf("\t\t Silakan pilih nomor menu : \n");

    printf("\n\t\t [1] Menambah pegawai dan jabatannya");
    printf("\n\t\t [2] Menelusuri jabatan seorang pejabat");
    printf("\n\t\t [3] Melihat seluruh pegawai dan jabatannya");
    printf("\n\t\t [0] Keluar aplikasi");

    printf("\n\n \t\t Menu yang Anda pilih adalah :: ");
}

nbAddr findName (nbAddr node, char* name)
{
    nbAddr nSrc;
    if (node != nil)
    {
        if (strcasecmp(node->nama, name) == 0)
        {
            return node;
        }
        else {
            nSrc = findName(node->fs, name);
            if (nSrc == nil) {
                return findName(node->nb, name);
            }
            else {
                return nSrc;
            }
        }
    }

    return nil;
}

nbAddr findParent (nbAddr node)
{
    return node->parent;
}

nbAddr findChild (nbAddr node)
{
    nbAddr newNode = AlokasiNode("", "", nil, nil, nil);

    if (isLeafNode(node)) return nil;

    if (node->fs->nb == nil) return node->fs;
    else {
        newNode = findSibling(node->fs);
    }

    return newNode; 
}

nbAddr findSibling (nbAddr node)
{
    nbAddr tmp = node;

    if (node != nil)
    {
        tmp->nb = findSibling(node->nb);
        // node = node->nb;
    }

    return tmp;
}

nbAddr findKaBag (nbTree t, char* name)
{
    nbAddr curr = findName(t.root, name);
    
    if (curr != nil)
    {
        if (!isRoot(curr))
            while (!isRoot(curr->parent))
            {
                curr = curr->parent;
            }
        else return nil;
    }
    else {
        printf("Tidak ada elemen bernama %s di dalam tree!!!\n", name);
    }

    return curr;

}
