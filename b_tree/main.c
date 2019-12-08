#include <stdio.h>
#include "tree.h"

int main()
{
    int array[] = {6,5,2,5,7,8};
    int num = sizeof(array)/sizeof(array[0]);
    int i ;
    for (i=0; i<num; i++) {
        tree_add(array[i]);
    } 

    print_tree_all();
    
    return 0;
}
