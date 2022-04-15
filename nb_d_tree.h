/**
 * @file nb_d_tree.h
 * @author Rachmat Purwa Saputra, 211524054
 * @brief Type specification for non-binary tree allocated dynamically.
 * @version 0.1
 * @date 2022-04-15
 * 
 */

#ifndef nb_d_tree_H
#define nb_d_tree_H

#include "boolean.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define nil NULL

/********** STRUKTUR DATA NON-BINARY TREE **********/

/**
 * @brief Alias of nbTreeNode*
 * 
 */
typedef struct nbTreeNode* nbAddr;

/**
 * @brief Structure for one node in non-binary tree ADT.
 * 
 */
typedef struct nbTreeNode
{
    char jabatan[50];
    char nama[50];
    nbAddr parent;
    nbAddr fs;
    nbAddr nb;
} nbTreeNode;

/**
 * @brief Pointer to the first/root node of the tree.
 * 
 */
typedef struct {
    nbAddr root;
} nbTree;

/***************************************************************** }
 { DEFINISI PRIMITIF }
 ***************************************************************** }
 { KELOMPOK CONSTRUCTOR }
 *****************************************************************/ 

/**
 * @brief Membentuk sebuah tree kosong dengan nilai root = nil.
 * 
 * @param t Tipe nbTree^
 */
void InitTree (nbTree* t);

/**
 * @brief Membuat sebuah node baru secara alokasi dinamis.
 * 
 * @param nama Nama Pejabat dalam string
 * @param jabatan Nama Jabatan yg diduduki dalam string
 * @param parent address parent
 * @param fson address first-son
 * @param nbro address next-brother
 * @return nbAddr 
 */
nbAddr AlokasiNode (char* nama, char* jabatan, 
                    nbAddr parent, nbAddr fson, nbAddr nbro);


/***************************************************************** }
 { DEFINISI PRIMITIF }
 ***************************************************************** }
 { KELOMPOK DESTRUCTOR }
 *****************************************************************/ 

/**
 * @brief Menghapus sebuah node dari dalam tree. Masih terdapat bug di dalamnya!
 * 
 * @param node bertipe nbAddress^
 */
void deleteNode (nbAddr *node);

/**
 * @brief Menghapus tree secara keseluruhan. Masih terdapat bug di dalamnya!
 * 
 * @param tree bretipe nbTree^
 */
void deleteTree (nbTree *tree);


/***************************************************************** }
 { DEFINISI PRIMITIF }
 ***************************************************************** }
 { KELOMPOK SELEKTOR / GETTERS }
 *****************************************************************/ 

/**
 * @brief Get the Parent object
 * 
 * @param node 
 * @return nbAddr 
 */
nbAddr getParent (nbAddr node);

/**
 * @brief Get the First Son object
 * 
 * @param node 
 * @return nbAddr 
 */
nbAddr getFirstSon (nbAddr node);

/**
 * @brief Get the Next Brother object
 * 
 * @param node 
 * @return nbAddr 
 */
nbAddr getNextBrother (nbAddr node);


/***************************************************************** }
 { DEFINISI PRIMITIF }
 ***************************************************************** }
 { KELOMPOK MUTATOR / SETTERS }
 *****************************************************************/ 

/**
 * @brief Set a Node Value with new value from parameters.
 * 
 * @param node 
 * @param newName 
 * @param newJabatan 
 */
void setNewNodeValue (nbAddr* node,
                      char* newName, char* newJabatan);

/**
 * @brief To insert a new allocated node to the tree. Parents are telled
 * by the user.
 * 
 * @param tree 
 * @param parent 
 * @param newName 
 * @param newJabatan 
 * @return nbAddr 
 */
nbAddr InsertNode (nbTree* tree, nbAddr parent,
                   char* newName, char* newJabatan);


/***************************************************************** }
 { DEFINISI PRIMITIF }
 ***************************************************************** }
 { KELOMPOK VALIDATOR }
 *****************************************************************/ 

/**
 * @brief Mengecek apakah suatu node merupakan leaf atau bukan.
 * 
 * @param node 
 * @return boolean 
 */
boolean isLeafNode (nbAddr node);

/**
 * @brief Mengecek apakah suatu node merupakan root atau bukan.
 * 
 * @param node 
 * @return boolean 
 */
boolean isRoot (nbAddr node);


/***************************************************************** }
 { DEFINISI PRIMITIF }
 ***************************************************************** }
 { KELOMPOK BACA/TULIS (INPUT/OUTPUT) }
 *****************************************************************/

/**
 * @brief Menampilkan seluruh isi tree, field yg ditampilkan adalah
 * nama dan jabatan. Menggunakan rekursif pre-order traversal.
 * @param node 
 */
void printTree (nbAddr node);

/**
 * @brief Menampilkan menu aplikasi jabatan.
 * 
 */
void printMenu ();


/***************************************************************** }
 { DEFINISI PRIMITIF }
 ***************************************************************** }
 { KELOMPOK OPERASI LAIN }
 *****************************************************************/

/**
 * @brief Mencari nama name dalam tree t, mengembalikan record yang mengandung name.
 * 
 * @param node 
 * @param name 
 * @return nbAddr 
 */
nbAddr findName (nbAddr node, char* name);

/**
 * @brief Mencari node parent dari node.
 * 
 * @param node 
 * @return nbAddr 
 */
nbAddr findParent (nbAddr node);

/**
 * @brief Mencari node fson ataupun nbro-nya (jika ada) dari fson dari node.
 * 
 * @param node 
 * @return nbAddr 
 */
nbAddr findChild (nbAddr node);

/**
 * @brief Mencari seluruh node nbro dari node.
 * 
 * @param node 
 * @return nbAddr 
 */
nbAddr findSibling (nbAddr node);

/**
 * @brief Mencari siapa kabag dari elemen yang bernama name dari tree.
 * 
 * @param t 
 * @param name 
 * @return nbAddr 
 */
nbAddr findKaBag (nbTree t, char* name);


#endif