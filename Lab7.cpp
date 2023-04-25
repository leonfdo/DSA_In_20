#include <iostream>
using namespace std;

struct node {
    int key;
    struct node* left, * right;
};

// Inorder traversal
void traverseInOrder(struct node* root) {
    if (root == NULL) {
        return;          //if the node pointer is null return
    }
    traverseInOrder(root->left);              //go to the left corner of the tree
    cout << root->key<<" ";               //if there is no other term to left cout the value
    traverseInOrder(root->right);            //after that go to the right

}

// Insert a node
struct node* insertNode(struct node* node, int key) {
    if (node == NULL) {
        struct node* new_node = new struct node;  //if the tree is empty create a new node to create the tree
        new_node->key = key;                //assigning the key to the new node key
        new_node->left = NULL;             //making the left node pointer NULL
        new_node->right = NULL;             // making the right node pointer NULL
        return new_node;
    }
    else if (key < node->key) {
        node->left=insertNode(node->left, key);   // if the key is less than node key value insert the node of the key to the left
    }
    else {
        node->right=insertNode(node->right, key);   //otherwise inserting to the right
    }
    return node;
}


//finding the node containing the minimum value

struct node* minimum_node(struct node* node) {
    if (node == NULL) { 
        return NULL; //if the tree does not contain any node
    }
    else if (node->left == NULL) { 
        return node;   //returning the corner most left node
    }
    else { 
        return minimum_node(node->left);  //transversing to the left corner most node
    }
}




// Deleting a node
struct node* deleteNode(struct node* root, int key) {
    if (root == NULL) { 
        cout << "the tree is empty";  //checking whether the tree is empty
        return NULL;
    }
    else if (key < root->key) { 
        root->left = deleteNode(root->left, key); //if the key is less than node value check left side nodes
    }
    else if (key > root->key) { 
        root->right = deleteNode(root->right, key); //if the key is greater than node value check right side nodes
    }
    else { 
        if (root->left == NULL) {   //if there is only right node or there is no nodes
            struct node* temp_node = root; 
            root = root->right; 
            delete temp_node;
        }
        else if (root->right == NULL) { //if there is only left node
            struct node* temp_node = root; 
            root = root->left; 
            delete temp_node; 
        }
        else { //if it contains both left node and right node
            struct node* temp_node = minimum_node(root->right); //finding the node containg the minimum value in right 
            root->key = temp_node->key; 
            root->right = deleteNode(root->right, temp_node->key); 
        }
    }
    return root;
}

// Driver code
int main() {
    struct node* root = NULL;

    int operation;
    int operand;
    cin >> operation;

    while (operation != -1) {
        switch (operation) {
        case 1: // insert
            cin >> operand;
            root = insertNode(root, operand);
            cin >> operation;
            break;
        case 2: // delete
            cin >> operand;
            root = deleteNode(root, operand);
            cin >> operation;
            break;
        default:
            cout << "Invalid Operator!\n";
            return 0;
        }
    }

    traverseInOrder(root);
}