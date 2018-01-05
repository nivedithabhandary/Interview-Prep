#include <iostream>

struct tree {
    int data;
    struct tree *left;
    struct tree *right;
    struct tree *parent;
};

tree * create_node(int value) {
    tree *node = new tree;
    node->data = value;
    node->left = NULL;
    node->right = NULL;
    node->parent = NULL;

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

tree * max_key(tree *t) {
    if(t==NULL) {
        std::cout<<"NULL tree cant find max!";
        return NULL;
    }

    std::cout<<"inside max key fun";

    while(t->right!=NULL){
        t = t->right;
    }

    std::cout<<t->data;
    return t;
}

void delete_node_recursive(tree **root, int value) {
    tree *temp = create_node(0);
    if((*root) == NULL) {
        std::cout<<"Error: Value to be deleted not found!";
        return;
    }

    if((*root)->data > value) {
        delete_node_recursive(&((*root)->left),value);
    } else if ((*root)->data < value) {
        delete_node_recursive(&((*root)->right),value);
    } else {
        // if root has both children
        if((*root)->left && (*root)->right) {
            temp = max_key((*root)->left);
            (*root)->data = temp->data;
            delete_node_recursive(&((*root)->left),(*root)->data);
        }
        // if root has only one child
        temp = (*root);
        if((*root)->left == NULL){
            temp = (*root)->right;
            (*root)->data = temp->data;
        } else {
            temp = (*root)->left;
            (*root)->data = temp->data;
        }
        //No child
        delete temp;
        std::cout<<"Deleting leaf";
    }
    return;
}

void swap(int *num1, int *num2){
    int temp = *num1;
    *num1 = *num2;
    *num2 = temp;
}

void delete_node(tree **root, int value) {
	tree *temp = *root;
	tree *temp2 = *root;
	tree *pre_node = *root;
	if((*root)->data == value) {
		if(temp->right!=NULL) {
			while(temp->right!=NULL) {
				pre_node = temp;
				temp = temp->right;
			}
			swap(&((*root)->data), &(temp->data));
			(pre_node)->right = NULL;
			while((temp2->right)!=NULL && ((temp2->data) > (temp2->right->data))) {
				swap(&(temp2->data), &(temp2->right->data));
				temp2 = temp2->right;
			}
		} else if(temp->left!=NULL) {
			while(temp->left!=NULL) {
				pre_node = temp;
				temp = temp->left;
			}
			swap(&((*root)->data), &(temp->data));
			(pre_node)->left = NULL;
			while((temp2->left)!=NULL && ((temp2->data) < (temp2->left->data))) {
				swap(&(temp2->data), &(temp2->left->data));
				temp2 = temp2->left;
			}
		} else { //Leaf node
			free (*root);
		}

		return;
	}

	if ((*root)->data < value) {
        delete_node(&((*root)->right), value);
    } else {
        delete_node(&((*root)->left), value);
    }

}

int * print_tree(tree *root) {
    static int i=0;
    static int arr[20];
    if (root) {
        print_tree(root->left);
        std::cout << root->data << "\t";
        arr[i] = root->data;
        i++;
        print_tree(root->right);
    }
    return arr;
}

tree * concatenate_trees(tree *first_tree, tree *second_tree) {
/* Precondition: All the values in second_tree and greater than values
in first tree */

    // Root of the concatenated tree will be equal to max element in first_tree
    int root_val =  max_key(first_tree)->data;
    tree *concat_tree = create_node(root_val);
    delete_node(&first_tree, root_val);

    int * first_tree_elements = print_tree(first_tree);
    int * second_tree_elements = print_tree(second_tree);

    int len1 = sizeof(first_tree_elements)/sizeof(first_tree_elements[0]);
    int len2 = sizeof(second_tree_elements)/sizeof(second_tree_elements[0]);

    for(int i = 0; i < len1 ; i++) {
        insert_node(&concat_tree, first_tree_elements[i]);
    }

    for(int i = 0; i < len2 ; i++) {
        insert_node(&concat_tree, second_tree_elements[i]);
    }

    return concat_tree;
}

tree * findLCA(tree *root, tree *a, tree *b){
    if(root==NULL) {
        return NULL;
    }
    if(((a->data < root->data) && (b->data > root->data)) || ((a->data > root->data) && (b->data < root->data))) {
        return root;
    }
    if((a->data < root->data) && (b->data < root->data)) {
        return findLCA(root->left, a, b);
    } else if((a->data > root->data) && (b->data > root->data)) {
        return findLCA(root->right, a, b);
    }
    return NULL;
}

tree * search (tree *root, int value) {
  if(root == NULL) {
    std::cout<<"Value Not found!";
      return NULL;
  }
  if(root->data == value) {
    return root;
  } else if (root->data < value) {
      return search(root->right, value);
  } else {
      return search(root->left, value);
  }
}

int prev = INT_MIN;
// Inorder traversal (Left-data-right) of BST will give values in ascending order.
// If not ascending order then the tree is not BST
bool isBST(tree *root, int prev) {
  if(root==NULL){
    return true;
  }
  if(!isBST((root->left),prev)) {
    return false;
  }
  if(root->data<prev){
    return false;
  }
  prev = root->data;
  if(!isBST((root->right),prev)) {
    return false;
  }
  return true;

}

/*
tree * get_kth_smallest(tree *root, int k, int count) {
  if(root==NULL) {
    return NULL;
  }
  get_kth_smallest(root->left, k, count);
  if(k==++count){
    return root;
  }
  get_kth_smallest(root->right, k, count);
}
*/
int arr1[128];
void print_root_to_leaf (tree *root, int i) {
  if(!root) {
    return;
  }

  print_root_to_leaf(root->left, i);
  print_root_to_leaf(root->right,i);
  arr1[i] = root->data;
  i++;
  if(root->left==NULL && root->right==NULL) {
    for(int j=0; j<i; j++) {
      std::cout<<arr1[j]<<"\t";
    }
    std::cout<<"\n";
    i--;
    return;
  }

  return;
}

tree* deleteNode(tree* root, int key) {
    if(root==NULL) {
        return NULL;
    }

    if(root->data == key) {
        if(!root->right) {
           tree* left = root->left;
            delete root;
            return left;
        } else {
            tree* right = root->right;
            while(right->left) {
                right = right->left;
            }
            swap(&root->data, &right->data);
        }
    }

    root->left = deleteNode(root->left, key);
    root->right = deleteNode(root->right, key);
    return root;
}



void print_levels(tree *root) {


}

int main()
{

    int arr[] = {4,2,1,3,6,5,7};
    int len = sizeof(arr)/sizeof(arr[0]);

    tree *root = NULL;

    for(int i = 0; i < len; i++) {
        insert_node(&root, arr[i]);
    }
    int *p = print_tree(root);

    std::cout<<"\n\n root to leaf paths : \n";
    print_root_to_leaf(root, 0);
    //std::cout<<"Kth smallest element : "<<get_kth_smallest(root, 2, 0)->data<<std::endl;

    /*

    tree *a = search(root, -2);
    tree *b = search(root, -6);
    tree *lca = findLCA(root,a,b);

    if(lca!=NULL) {
      std::cout<<"Least common ancestor data : "<<lca->data<<std::endl;
    }

    if(isBST(root, prev)) {
      std::cout<<"It is a BST!"<<std::endl;
    }

*/
    //delete_node_recursive(&root, 3);
    tree *temp = deleteNode(root, 7);
    std::cout<<"\n print after delete"<<std::endl;
    print_tree(temp);
    std::cout<<"end of code!"<<std::endl;

/*
    int first[] = {4,3,2,1,5};
    int len = sizeof(first)/sizeof(first[0]);
    tree *first_tree = NULL;
    for(int i = 0; i < len; i++) {
        insert_node(&first_tree, first[i]);
    }
    std::cout<<"\n First tree : ";
    int *a = print_tree(first_tree);


    int second[] = {6,8,7,10,9};
    int len2 = sizeof(second)/sizeof(second[0]);
    tree *second_tree = NULL;
    for(int i = 0; i < len2; i++) {
        insert_node(&second_tree, second[i]);
    }
    std::cout<<"\n Second tree : ";
    int *b = print_tree(second_tree);


    tree *concat_tree = concatenate_trees(first_tree, second_tree);
    std::cout<<"\n concat_tree  : ";
    int *c = print_tree(concat_tree);
    */
}
