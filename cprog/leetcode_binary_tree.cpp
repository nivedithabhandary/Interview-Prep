#include <iostream>

struct tree {
  int data;
  tree * left;
  tree * right;
};

tree * create_node(int value) {
    tree *node = new tree;
    node->data = value;
    node->left = NULL;
    node->right = NULL;

    return node;
}

void insert_node(tree **root, int value) {
    if(*root == NULL) {
        *root = create_node(value);
        return;
    }

    if ((*root)->data < value) {
        insert_node(&((*root)->right), value);
    } else {
        insert_node(&((*root)->left), value);
    }
}

void preorder_traversal(tree *root) {
  if(root==NULL) {
    return;
  }
  std::cout<<root->data<<"\t";
  preorder_traversal(root->left);
  preorder_traversal(root->right);
}

int get_height_tree(tree *root) {
  if(root==NULL){
    return 0;
  }
  int left_tree_height = get_height_tree(root->left);
  int right_tree_height = get_height_tree(root->right);
  return (left_tree_height > right_tree_height ? left_tree_height+1 : right_tree_height+1);
}

void print_given_level(tree *root, int level) {
  if(root==NULL) {
    return;
  }
  if(level==1) {
    std::cout<<root->data<<"\t";
    return;
  }
  if(level>1) {
    print_given_level(root->left, level-1);
    print_given_level(root->right, level-1);
  }
}

tree * addOneRow(tree * root, int v, int d) {
  if(root==NULL) {
    return NULL;
  }
  if(d==1) {
    tree *node = create_node(v);
    node->left = root;
    root = node;
    return root;
  }
  if(d==2) {
    tree *node = create_node(v);
    node->left = root->left;
    root->left = node;

    tree *node2 = create_node(v);
    node2->right = root->right;
    root->right = node2;

    return root;
  }
  if(d > 2){
    addOneRow(root->left,v,d-1);
    addOneRow(root->right,v,d-1);
  }
}

tree* mergeTrees(tree* t1, tree* t2) {
    if(t1==NULL && t2==NULL) {
        return NULL;
    }
    if(t1==NULL || t2==NULL) {
        if(t1==NULL) {
            return t2;
        } else {
            return t1;
        }
    }
    tree * newTree = create_node(t1->data + t2->data);
    newTree->left = mergeTrees(t1->left, t2->left);
    newTree->right = mergeTrees(t1->right, t2->right);

    return newTree;
}

tree* helper(vector<int>& nums, int left, int right) {
  if(left > right) {
    return NULL;
  }
  int max_num = INT_MIN, max_index = left;
  for(int i = left; i<right; i++) {
      if(nums[i] > max_num) {
          max_index = i;
          max_num = nums[i];
        }
    }

  tree *newNode = create_node(max_num);
  newNode->left = helper(nums, left, max_index-1);
  newNode->right = helper(nums, max_index ,right);
  return newNode;
}

tree* max_tree(vector<int>& nums) {
  return helper(nums, 0, nums.size()-1);
}

int main()
{

    int arr[] = {4,2,1,3,6,5,7};
    int len = sizeof(arr)/sizeof(arr[0]);

    tree *root = NULL;

    for(int i = 0; i < len; i++) {
        insert_node(&root, arr[i]);
    }
    std::cout<<"\nPreorder : ";
    preorder_traversal(root);

    int arr2[] = {4,2,1,3,6,5,7};
    int len2 = sizeof(arr)/sizeof(arr[0]);

    tree *root2 = NULL;

    for(int j = 0; j < len2; j++) {
        insert_node(&root2, arr2[j]);
    }
    std::cout<<"\nPreorder : ";
    preorder_traversal(root2);

    tree *new_tree = mergeTrees(root,root2);
    std::cout<<"\nMerged : ";
    preorder_traversal(new_tree);

    /*
    int level = 2;
    std::cout<<"\nPrint level "<<level<<" : ";
    print_given_level(root, level);

    int v = 100;
    int d = 4;
    tree * new_root = addOneRow(root, v, d);
    std::cout<<"\n Adding row with value "<<v<<" at level "<<d<<" : ";
    preorder_traversal(new_root);
    */

    std::cout<<"\n\n";
}
