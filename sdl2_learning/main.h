#ifndef _TREE_H_
#define _TREE_H_

typedef struct tagNODE{
    int key;
//    struct tagNODE* parent;
    struct tagNODE* left;
    struct tagNODE* right;
}NODE;

int  tree_add(int key);
void inorder_tree_walk(NODE* node);
void print_tree_all();

#endif
