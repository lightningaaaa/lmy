#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

NODE *g_base = NULL;

NODE* init_new_node(int key)
{
    NODE* add_node = calloc(1, sizeof(NODE));
    add_node->key = key;
    return add_node;
}

int tree_add(int key)
{
    NODE* add_node = init_new_node(key);

    if(g_base == NULL) {
        g_base = add_node;
        return 0;
    }

    NODE* temp_node = g_base;
    while (temp_node != NULL) {
        if (key < temp_node->key) {
            if (temp_node->left == NULL) {
                temp_node->left = add_node;
                break;
            } else {
                temp_node = temp_node->left;
            }
        }
        else {
            if (temp_node->right == NULL) {
                temp_node->right = add_node;
                break;
            } else {
                temp_node = temp_node->right;
            }
        }
    }

    return 0;
}

void inorder_tree_walk(NODE* node)
{
    if (node == NULL) {
        return;
    }

    inorder_tree_walk(node->left);
    printf("%d\n",node->key);
    inorder_tree_walk(node->right);
}

void print_tree_all()
{
    inorder_tree_walk(g_base);
}