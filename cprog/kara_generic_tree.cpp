#include <iostream>

struct generic_tree {
  int data;
  generic_tree * first_child;
  generic_tree * next_sibling;
}

//Q1 Find sum of all elements
int sum_elements(generic_tree *root) {
  if(root==NULL){
    return 0;
  }
  return root->data + sum_elements(next_sibling) + sum_elements(first_child);
}
