///PRE ,, POST ,, InOrder ,, MIN ,, MAX ,, Kth smallest number


#include <iostream>
using namespace std;

struct TreeNode {
    int key;
    TreeNode* parent;
    TreeNode* left;
    TreeNode* right;
};

TreeNode* root = NULL;

TreeNode* createNode(int value) {
    TreeNode* newNode = new TreeNode();   // Allocate memory for a new node.
    newNode->key = value;                 // Assign the given value to the key of the node.
    newNode->parent = NULL;               // Initialize the parent pointer to NULL.
    newNode->left = NULL;                 // Initialize the left child pointer to NULL.
    newNode->right = NULL;                // Initialize the right child pointer to NULL.
    return newNode;                       // Return the pointer to the new node.
}


void insertInBST(int value) {
    TreeNode* z = createNode(value);  // Create a new node `z` with the given value.
    TreeNode* y = NULL;               // `y` is used to keep track of the parent node of `z`.
    TreeNode* x = root;               // Start at the root of the tree.

    while (x != NULL) {               // Traverse the tree until a NULL position is found.
        y = x;                        // Update `y` to the current node (`x`).
        if (z->key < x->key) {        // If the new value is smaller, move left.
            x = x->left;
        } else {                      // If the new value is greater or equal, move right.
            x = x->right;
        }
    }

    z->parent = y;                    // Link the new node `z` to its parent `y`.
    if (y == NULL) {                  // If `y` is NULL, the tree was empty; `z` becomes the root.
        root = z;
    } else if (z->key < y->key) {     // If `z` is smaller than `y`, make it the left child.
        y->left = z;
    } else {                          // Otherwise, make it the right child.
        y->right = z;
    }
}


void preOrder(TreeNode* ptr) {
    if (ptr == NULL) return;
    cout << ptr->key << " ";
    preOrder(ptr->left);
    preOrder(ptr->right);
}

void inOrder(TreeNode* ptr) {
    if (ptr == NULL) return;
    inOrder(ptr->left);
    cout << ptr->key << " ";
    inOrder(ptr->right);
}

void postOrder(TreeNode* ptr) {
    if (ptr == NULL) return;
    postOrder(ptr->left);
    postOrder(ptr->right);
    cout << ptr->key << " ";
}

TreeNode* minimum(TreeNode* x) {
    if (x == NULL) return NULL;
    while (x->left != NULL) {
        x = x->left;
    }
    return x;
}

TreeNode* maximum(TreeNode* x) {
    if (x == NULL) return NULL;
    while (x->right != NULL) {
        x = x->right;
    }
    return x;
}

TreeNode* findKthSmallest(TreeNode* node, int& k) {
    if (node == NULL) return NULL;

    // Search in the left subtree
    TreeNode* left = findKthSmallest(node->left, k);
    if (left != NULL) return left; // Found in the left subtree

    // Visit current node
    k--;
    if (k == 0) return node;

    // Search in the right subtree
    return findKthSmallest(node->right, k);
}

void displayMinMax() {
    TreeNode* maxNode = maximum(root);
    TreeNode* minNode = minimum(root);
    if (maxNode) cout << "Maximum value: " << maxNode->key << endl;
    if (minNode) cout << "Minimum value: " << minNode->key << endl;
}

int main() {
    int n, value, k;

    cout << "Enter the number of nodes to insert: ";
    cin >> n;

    for (int i = 0; i < n; ++i) {
        cout << "Enter value for node " << i + 1 << ": ";
        cin >> value;
        insertInBST(value);
    }

    cout << "\nPre-order traversal: ";
    preOrder(root);
    cout << endl;

    cout << "In-order traversal: ";
    inOrder(root);
    cout << endl;

    cout << "Post-order traversal: ";
    postOrder(root);
    cout << endl;

    displayMinMax();

    cout << "\nEnter the value of K to find the K-th smallest node: ";
    cin >> k;

    TreeNode* kthNode = findKthSmallest(root, k);
    if (kthNode != NULL) {
        cout << "The K-th smallest node value is: " << kthNode->key << endl;
    } else {
        cout << "The value of K is invalid!" << endl;
    }

    return 0;
}




