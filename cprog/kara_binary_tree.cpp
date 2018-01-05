#include<iostream>

// Binary Tree structure
struct tree {
    int data;
    struct tree *left;
    struct tree *right;
};

// Generic code
//------------------------------------------------------------
tree *create_node(int val){
    tree *new_node = new tree;
    new_node->data = val;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

void insert_node(tree **root, int val){

    if((*root)==NULL) {
        *root = create_node(val);
        return;
    }
    if((*root)->data > val) {
        insert_node(&((*root)->left),val);
    } else {
        insert_node(&((*root)->right),val);
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

//------------------------------------------------------------


// Q1. Find Max element in binary tree
int get_max(tree *root) {

  int max_elem = INT_MIN;
  if(root==NULL){
    return 0;
  }
  if(root->left==NULL && root->right==NULL && root->data > max_elem) {
    max_elem = root->data;
    return max_elem;
  }

  int max_left = get_max(root->left);
  int max_right = get_max(root->right);
  int max_subtrees = (max_left > max_right ? max_left : max_right);
  return (max_subtrees > root->data ? max_subtrees : root->data);
}

// Q2. Search element in binary tree
bool search_tree(tree *root, int elem) {
  if(root==NULL) {
    return 0;
  }
  if(root->data == elem) {
    return 1;
  }
  if (search_tree(root->left, elem)) {
    return 1;
  } else {
    return search_tree(root->right, elem);
  }
  return 0;
}

// Q3. Find size of binary tree
int get_size_tree(tree *root) {
  if(root==NULL) {
    return 0;
  }
  static int count=0;
  count++;
  get_size_tree(root->left);
  get_size_tree(root->right);
  return count;
}

//Q4. Delete a binary tree
void delete_tree(tree **root){
  if(*root==NULL) {
    return;
  }
  //delete_tree(&((*root)->left));
  //delete_tree(&((*root)->right));
  delete *root;
  *root = NULL;
}

//Q5. Get height of a binary tree
int get_height_tree(tree *root) {
  if(root==NULL){
    return 0;
  }
  int left_tree_height = get_height_tree(root->left);
  int right_tree_height = get_height_tree(root->right);
  return (left_tree_height > right_tree_height ? left_tree_height+1 : right_tree_height+1);
}

//Q6. Print all root to leaf paths
void print_root_to_leaf(tree *root, int path[], int path_length) {
  if(root==NULL) {
    return;
  }
  path[path_length] = root->data;
  path_length++;
  if(root->left==NULL && root->right==NULL) {
    for(int i=0; i<path_length; i++){
      std::cout<<path[i]<<"\t";
    }
    std::cout<<"\n";
  }
  print_root_to_leaf(root->left, path, path_length);
  print_root_to_leaf(root->right, path, path_length);
}

//Q7. Check for existence of path with given sum
bool path_with_sum_exists(tree *root, int sum){
  if(root==NULL) {
    return (sum==0);
  }

  int remain = sum - root->data;
  return path_with_sum_exists(root->left, remain) || path_with_sum_exists(root->right, remain);
}

//Q8. Convert to mirror
tree * convert_to_mirror(tree *root){
  tree *temp = NULL;
  if(root==NULL) {
    return NULL;
  }
  convert_to_mirror(root->left);
  convert_to_mirror(root->right);
  temp = root->left;
  root->left = root->right;
  root->right = temp;

  return root;
}

//Q9. Find LCA of 2 nodes in binary tree
tree * findLCA(tree *root, tree *a, tree *b){
  tree *left, *right;
  if(root == NULL) {
    return root;
  }
  //if(!(search_tree(root, a->data) && search_tree(root, b->data))) {
  //  return NULL;
  //}
  if(root==a || root==b) {
    return root;
  }
  left = findLCA(root->left, a, b);
  right = findLCA(root->right, a, b);
  if(left && right) {
    return root;
  } else {
    return (left ? left:right);
  }
}

//Q10. Print all ancestors
void print_ancestors(tree *root, int path[], int path_length, int num) {
  if(root==NULL) {
    return;
  }
  path[path_length] = root->data;
  path_length++;
  if(root->data == num) {
    for(int i=0; i<path_length; i++){
      std::cout<<path[i]<<"\t";
    }
  }
  print_ancestors(root->left, path, path_length, num);
  print_ancestors(root->right, path, path_length, num);
}

// Q11. Find next sibling
void find_next_sibling(tree *root, tree *prev, int node_data) {
  tree *temp, *sibling;
  if(root==NULL) {
    return;
  }
  if(root->data == node_data) {
    temp = root;
    if(prev->left == temp) {
      sibling = prev->right;
    } else if(prev->right == temp){
      sibling = prev->left;
    } else {
      sibling = prev;
    }
    std::cout<<"\n\nNext Sibling of "<<node_data<<" : "<<sibling->data<<std::endl;
    exit(1);
  }
  prev = root;
  find_next_sibling(root->left, prev, node_data);
  find_next_sibling(root->right, prev, node_data);
}

struct tree* invertTree(struct tree* root) {

    if(root==NULL){
        return NULL;
    }

    struct tree* temp;
    temp = root->left;
    root->left = root->right;
    root->right = temp;

    //if(root->left) {
    invertTree(root->left);
    invertTree(root->right);

    //}
    //if (root->right) {
      //  return invertTree(root->right);
    //}
}

int diameter(struct tree* root, int &ans) {
  if(!root) {
    return 0;
  }
  int left = diameter(root->left, ans);
  int right = diameter(root->right, ans);
  ans = std::max(ans, 1+left+right);
  return(std::max(left,right) + 1);
}

int main()
{
  tree *root = NULL;
  int arr[] = {1,2,4,5,3,6,7};
  int len = sizeof(arr)/sizeof(arr[0]);
  for(int i=0; i<len; i++) {
    insert_node(&root, arr[i]);
  }
  preorder_traversal(root);

  /*
  //Q1
  std::cout<<"\n\nMax element : "<<get_max(root)<<std::endl;

  //Q2
  int num = 8;
  std::cout<<"\n\nFind Element "<<num<<" : "<<search_tree(root, num)<<std::endl;

  //Q3
  std::cout<<"\n\nSize of Tree : "<<get_size_tree(root)<<std::endl;

  //Q4
  //std::cout<<"\n\nDeleting Tree : "<<std::endl;
  //delete_tree(&root);
  //std::cout<<"\n\nTrying to access root after Deleting Tree : "<<root<<std::endl;

  //Q5
  std::cout<<"\n\nHeight of Tree : "<<get_height_tree(root)<<std::endl;

  //Q6
  std::cout<<"\n\nAll Root to Leaf paths of Tree : "<<std::endl;
  int path[] = {};
  int path_length = 0;
  print_root_to_leaf(root, path, path_length);

  //Q7
  int sum = 13;
  std::cout<<"\n\n"<<sum<<" Sum in path of Tree : "<<path_with_sum_exists(root,sum)<<std::endl;

  //Q8
  tree * mirror = convert_to_mirror(root);
  std::cout<<"\n\nMirror of root : "<<std::endl;
  preorder_traversal(mirror);

  //Q9
  /*tree *a = create_node(1);
  tree *b = create_node(5);
  tree * lca = findLCA(root, a, b);
  std::cout<<"\n\nLeast common ancestor of "<<a->data<<" and "<<b->data<<" is : "<<lca->data<<std::endl;


  //Q10
  int num1 = 2;
  std::cout<<"\n\nAll ancestors of "<<num1<<" : ";
  int path1[] = {};
  int path_length1 = 0;
  print_ancestors(root, path1, path_length1, num1);

  //Q11
  int node_data = 2;
  find_next_sibling(root,NULL, node_data);
  std::cout<<"\n\n";

  */

  //Q12
  tree * temp = invertTree(root);
  std::cout<<"Inverted tree : \n\n";
  preorder_traversal(root);

  int ans;
  std::cout<<std::endl<<"Diameter of tree : "<<diameter(root, ans)<<std::endl;
}
