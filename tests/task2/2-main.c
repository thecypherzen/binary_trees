#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"

/**
 * main - Entry point
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
    binary_tree_t *root, *temp_1, *temp_2;

    root = binary_tree_node(NULL, 98);
    root->left = binary_tree_node(root, 12);
    root->right = binary_tree_node(root, 402);
    binary_tree_print(root);
    printf("\n");
    temp_2 = binary_tree_insert_left(root->left, 54);
    temp_1 = binary_tree_insert_right(root, 128);
	binary_tree_insert_right(temp_1, -4);
	binary_tree_insert_left(temp_2, 144);
	temp_2 = binary_tree_insert_right(NULL, -99);
	printf("\tinsert_right(NULL, -99): %d\n",
		   temp_2 ? temp_2->n : '*');
    binary_tree_print(root);
    return (0);
}
