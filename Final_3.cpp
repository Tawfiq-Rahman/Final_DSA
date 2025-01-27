Inorder traversal of the given Binary Search Tree is: 20 30 40 50 60 70 80
After deletion of 20: 30 40 50 60 70 80
After insertion of 25: 25 30 40 50 60 70 80
Node 25 found in the BST.




// C++ Program to implement binary search tree

#include <iostream>
using namespace std;

// Node structure for a Binary Search Tree
struct Node {
    int data;
    Node* left;
    Node* right;
};

// Function to create a new Node
Node* createNode(int data)
{
    Node* newNode = new Node();
    newNode->data = data;
    newNode->left = newNode->right = nullptr;
    return newNode;
}

// Function to insert a node in the BST
Node* insertNode(Node* root, int data)
{
    if (root == nullptr) { // If the tree is empty, return a
                           // new node
        return createNode(data);
    }

    // Otherwise, recur down the tree
    if (data < root->data) {
        root->left = insertNode(root->left, data);
    }
    else if (data > root->data) {
        root->right = insertNode(root->right, data);
    }

    // return the (unchanged) node pointer
    return root;
}

// Function to do inorder traversal of BST
void inorderTraversal(Node* root)
{
    if (root != nullptr) {
        inorderTraversal(root->left);
        cout << root->data << " ";
        inorderTraversal(root->right);
    }
}

// Function to search a given key in a given BST
Node* searchNode(Node* root, int key)
{
    // Base Cases: root is null or key is present at root
    if (root == nullptr || root->data == key) {
        return root;
    }

    // Key is greater than root's key
    if (root->data < key) {
        return searchNode(root->right, key);
    }

    // Key is smaller than root's key
    return searchNode(root->left, key);
}

// Function to find the inorder successor
Node* minValueNode(Node* node)
{
    Node* current = node;
    // loop down to find the leftmost leaf
    while (current && current->left != nullptr) {
        current = current->left;
    }
    return current;
}

// Function to delete a node
Node* deleteNode(Node* root, int data)
{
    if (root == nullptr)
        return root;

    // If the data to be deleted is smaller than the root's
    // data, then it lies in the left subtree
    if (data < root->data) {
        root->left = deleteNode(root->left, data);
    }
    // If the data to be deleted is greater than the root's
    // data, then it lies in the right subtree
    else if (data > root->data) {
        root->right = deleteNode(root->right, data);
    }
    // if data is same as root's data, then This is the node
    // to be deleted
    else {
        // node with only one child or no child
        if (root->left == nullptr) {
            Node* temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == nullptr) {
            Node* temp = root->left;
            delete root;
            return temp;
        }

        // node with two children: Get the inorder successor
        // (smallest in the right subtree)
        Node* temp = minValueNode(root->right);

        // Copy the inorder successor's content to this node
        root->data = temp->data;

        // Delete the inorder successor
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

// Main function to demonstrate the operations of BST
int main()
{

    Node* root = nullptr;
    // create a BST
    root = insertNode(root, 50);
    root = insertNode(root, 30);
    root = insertNode(root, 20);
    root = insertNode(root, 40);
    root = insertNode(root, 70);
    root = insertNode(root, 60);
    root = insertNode(root, 80);

    // Print the inorder traversal of a BST
    cout << "Inorder traversal of the given Binary Search "
            "Tree is: ";
    inorderTraversal(root);
    cout << endl;

    // delete a node in BST
    root = deleteNode(root, 20);
    cout << "After deletion of 20: ";
    inorderTraversal(root);
    cout << endl;

    // Insert a node in BST
    root = insertNode(root, 25);
    cout << "After insertion of 25: ";
    inorderTraversal(root);
    cout << endl;

    // Search a key in BST
    Node* found = searchNode(root, 25);

    // check if the key is found or not
    if (found != nullptr) {
        cout << "Node 25 found in the BST." << endl;
    }
    else {
        cout << "Node 25 not found in the BST." << endl;
    }

    return 0;
}










Floor in Binary Search Tree (BST)



// C++ implementation to find floor of given
// number x in BST
#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int x) {
        data = x;
        left = nullptr;
        right = nullptr;
    }
};

// This function is used to find floor
// of given number x
int floor(Node* root, int x) {

   // Base case: return -1 if no floor found
   if (root == nullptr) {
        return -1;
    }

    // If the root's data is equal to x,
    // we've found the floor
    if (root->data == x) {
        return root->data;
    }

    // If root's data is greater than x,
    // search in the left subtree
    if (root->data > x) {
        return floor(root->left, x);
    }

    // Else, search in the right subtree
    // and compare with current root
    int floorValue = floor(root->right, x);

    // If the right subtree returns
    //a valid floor, return that
    // Otherwise, return the current root's data
    return (floorValue <= x && floorValue != -1)
                              ? floorValue : root->data;
}

int main() {

    // Representation of the given tree
    //       10
    //       / \
    //      5  15
    //         / \
    //        12 30
    Node* root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(15);
    root->right->left = new Node(12);
    root->right->right = new Node(30);

    int x = 14;
    cout << floor(root, x) << endl;
    return 0;
}








Sum of all the levels in a Binary Search Tree

// C++ implementation of the approach
#include <iostream>
#include <queue>
using namespace std;

// A Binary Tree Node
struct Node {
    int data;
    struct Node *left, *right;
};

// Utility function to create a new tree node
Node* newNode(int data)
{
    Node* temp = new Node;
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

// Utility function to print
// the contents of an array
void printArr(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << endl;
}

// Function to return the height
// of the binary tree
int getHeight(Node* root)
{
    if (root->left == NULL && root->right == NULL)
        return 0;

    int left = 0;
    if (root->left != NULL)
        left = getHeight(root->left);

    int right = 0;
    if (root->right != NULL)
        right = getHeight(root->right);

    return (max(left, right) + 1);
}

// Recursive function to update sum[] array
// such that sum[i] stores the sum
// of all the elements at ith level
void calculateLevelSum(Node* node, int level, int sum[])
{
    if (node == NULL)
        return;

    // Add current node data to the sum
    // of the current node's level
    sum[level] += node->data;

    // Recursive call for left and right sub-tree
    calculateLevelSum(node->left, level + 1, sum);
    calculateLevelSum(node->right, level + 1, sum);
}

// Driver code
int main()
{
    // Create the binary tree
    Node* root = newNode(6);
    root->left = newNode(4);
    root->right = newNode(8);
    root->left->left = newNode(3);
    root->left->right = newNode(5);
    root->right->left = newNode(7);
    root->right->right = newNode(9);

    // Count of levels in the
    // given binary tree
    int levels = getHeight(root) + 1;

    // To store the sum at every level
    int sum[levels] = { 0 };
    calculateLevelSum(root, 0, sum);

    // Print the required sums
    printArr(sum, levels);

    return 0;
}







Clockwise Spiral Traversal of Binary Tree

// C++ program for Clockwise Spiral Traversal
// of Binary Tree

#include <bits/stdc++.h>
using namespace std;

// A Tree node
struct Node {
    int key;
    struct Node *left, *right;
};

// Utility function to create a new node
Node* newNode(int key)
{
    Node* temp = new Node;
    temp->key = key;
    temp->left = temp->right = NULL;
    return (temp);
}
//function to calculate the height of the tree
int findHeight(struct Node* node)
{
    //Base condition
    if(node == NULL) return 0;
    int leftHeight = findHeight(node->left);
    int rightHeight = findHeight(node->right);
    //return maximum of left or right subtree height addition with one
    return 1+(leftHeight > rightHeight ? leftHeight : rightHeight );
}
// Function to find the width of tree
void findWidth(struct Node* node, int& maxValue,
            int& minValue, int hd)
{
    if (node == NULL)
        return;

    if (hd > maxValue) {
        maxValue = hd;
    }

    if (hd < minValue) {
        minValue = hd;
    }

    findWidth(node->left, maxValue, minValue, hd - 1);
    findWidth(node->right, maxValue, minValue, hd + 1);
}

// Function to traverse the tree and
// store level order traversal in a matrix
void BFS(int** mtrx, struct Node* node)
{
    // Create queue for storing
    // the addresses of nodes
    queue<struct Node*> qu;

    qu.push(node);

    int i = -1, j = -1;

    struct Node* poped_node = NULL;

    while (!qu.empty()) {

        i++;

        int qsize = qu.size();

        while (qsize--) {
            j++;

            poped_node = qu.front();

            // Store data of node into the matrix
            mtrx[i][j] = poped_node->key;
            qu.pop();

            if (poped_node->left != NULL) {
                qu.push(poped_node->left);
            }

            if (poped_node->right != NULL) {
                qu.push(poped_node->right);
            }
        }

        j = -1;
    }
}

// Function for Clockwise Spiral Traversal
// of Binary Tree
void traverse_matrix(int** mtrx, int height, int width)
{
    int j = 0, k1 = 0, k2 = 0, k3 = height - 1;
    int k4 = width - 1;

    for (int round = 0; round < height / 2; round++) {
        for (j = k2; j < width; j++) {

            // only print those values which
            // are not MAX_INTEGER
            if (mtrx[k1][j] != INT_MAX) {
                cout << mtrx[k1][j] << ", ";
            }
        }

        k2 = 0;
        k1++;

        for (j = k4; j >= 0; j--) {

            // only print those values which are
            // not MAX_INTEGER
            if (mtrx[k3][j] != INT_MAX) {
                cout << mtrx[k3][j] << ", ";
            }
        }

        k4 = width - 1;
        k3--;
    }

    // condition (one row may be left traversing)
    // if number of rows in matrix are odd
    if (height % 2 != 0) {
        for (j = k2; j < width; j++) {

            // only print those values which are
            // not MAX_INTEGER
            if (mtrx[k1][j] != INT_MAX) {
                cout << mtrx[k1][j] << ", ";
            }
        }
    }
}

// A utility function to print clockwise
// spiral traversal of tree
void printPattern(struct Node* node)
{
    // max, min has taken for
    // calculating width of tree
    int max_value = INT_MIN;
    int min_value = INT_MAX;
    int hd = 0;

    // calculate the width of a tree
    findWidth(node, max_value, min_value, hd);
    int width = max_value + abs(min_value);

    //calculate the height of the tree
    int height = findHeight(node);

    // use double pointer to create 2D array
    int** mtrx = new int*[height];

    // initialize width for each row of matrix
    for (int i = 0; i < height; i++) {
        mtrx[i] = new int[width];
    }

    // initialize complete matrix with
    // MAX INTEGER(purpose garbage)
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            mtrx[i][j] = INT_MAX;
        }
    }

    // Store the BFS traversal of the tree
    // into the 2-D matrix
    BFS(mtrx, node);

    // Print the circular clockwise spiral
    // traversal of the tree
    traverse_matrix(mtrx, height, width);

    // release extra memory
    // allocated for matrix
    free(mtrx);
}

// Driver Code
int main()
{
    /*     10
        /     \
    12     13
        /     \
        14     15
        / \     / \
        21 22 23 24

    Let us create Binary Tree as shown
    in above example */

    Node* root = newNode(10);
    root->left = newNode(12);
    root->right = newNode(13);

    root->right->left = newNode(14);
    root->right->right = newNode(15);

    root->right->left->left = newNode(21);
    root->right->left->right = newNode(22);
    root->right->right->left = newNode(23);
    root->right->right->right = newNode(24);

    cout << "Circular Clockwise Spiral Traversal : \n";

    printPattern(root);

    return 0;
}







Flatten a binary tree into linked list | Set-2

Output : The Inorder traversal after flattening binary tree 1 2 3 4 5 6


// C++ program to flatten the linked
// list using stack | set-2
#include <iostream>
#include <stack>
using namespace std;

struct Node {
    int key;
    Node *left, *right;
};

/* utility that allocates a new Node
   with the given key  */
Node* newNode(int key)
{
    Node* node = new Node;
    node->key = key;
    node->left = node->right = NULL;
    return (node);
}

// To find the inorder traversal
void inorder(struct Node* root)
{
    // base condition
    if (root == NULL)
        return;
    inorder(root->left);
    cout << root->key << " ";
    inorder(root->right);
}

// Function to convert binary tree into
// linked list by altering the right node
// and making left node point to NULL
Node* solution(Node* A)
{

    // Declare a stack
    stack<Node*> st;
    Node* ans = A;

    // Iterate till the stack is not empty
    // and till root is Null
    while (A != NULL || st.size() != 0) {

        // Check for NULL
        if (A->right != NULL) {
            st.push(A->right);
        }

        // Make the Right Left and
        // left NULL
        A->right = A->left;
        A->left = NULL;

        // Check for NULL
        if (A->right == NULL && st.size() != 0) {
            A->right = st.top();
            st.pop();
        }

        // Iterate
        A = A->right;
    }
    return ans;
}

// Driver Code
int main()
{
    /*    1
        /   \
       2     5
      / \     \
     3   4     6 */

    // Build the tree
    Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(5);
    root->left->left = newNode(3);
    root->left->right = newNode(4);
    root->right->right = newNode(6);

    // Call the function to
    // flatten the tree
    root = solution(root);

    cout << "The Inorder traversal after "
            "flattening binary tree ";

    // call the function to print
    // inorder after flattening
    inorder(root);
    return 0;

    return 0;
}







Find maximum among all right nodes in Binary Tree


// CPP program to print maximum element
// among all right child nodes
#include <bits/stdc++.h>
using namespace std;

// A Binary Tree Node
struct Node {
    int data;
    struct Node *left, *right;
};

// Utility function to create a new tree node
Node* newNode(int data)
{
    Node* temp = new Node;
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

// Function to find maximum element
// among all right child nodes using
// Inorder Traversal
int maxOfRightElement(Node* root)
{
    // Temp variable
    int res = INT_MIN;

    // If tree is empty
    if (root == NULL)
        return -1;

    // If right child exists
    if (root->right != NULL)
        res = root->right->data;

    // Return maximum of three values
    // 1) Recursive max in right subtree
    // 2) Value in right child node
    // 3) Recursive max in left subtree
    return max({ maxOfRightElement(root->right),
                 res,
                 maxOfRightElement(root->left) });
}

// Driver Code
int main()
{
    // Create binary tree
    // as shown below

    /*   7
        / \
       6   5
      / \ / \
      4 3 2 1  */
    Node* root = newNode(7);
    root->left = newNode(6);
    root->right = newNode(5);
    root->left->left = newNode(4);
    root->left->right = newNode(3);
    root->right->left = newNode(2);
    root->right->right = newNode(1);

    cout << maxOfRightElement(root);

    return 0;
}







Zig-Zag traversal of a Binary Tree using Recursion

Output

20 22 8 4 12 11 14 10


// C++ Program to traverse a binary
// tree in zigzag manner.
#include <bits/stdc++.h>
using namespace std;

class Node {
    public:
        int data;
        Node *left;
        Node *right;
        Node(int x) {
            data = x;
            left = nullptr;
            right = nullptr;
        }
};

// Function to calculate height of tree
int treeHeight(Node *root){
    if(!root) return 0;
    int lHeight = treeHeight(root->left);
    int rHeight = treeHeight(root->right);
    return max(lHeight, rHeight) + 1;
}

// Function which prints from left to right
void leftToRightTrav(Node* root, int level, vector<int>&ans) {
    if (root == nullptr) return;

    if (level == 1) {
        ans.push_back(root->data);
    }
    else {
        leftToRightTrav(root->left, level-1, ans);
        leftToRightTrav(root->right, level-1, ans);
    }
}

// Function which prints from right to left
void rightToLeftTrav(Node* root, int level, vector<int>&ans) {
    if (root == nullptr) return;

    if (level == 1) {
        ans.push_back(root->data);
    }
    else {
        rightToLeftTrav(root->right, level-1, ans);
        rightToLeftTrav(root->left, level-1, ans);
    }
}

// Function to traverse tree in zig zag order
vector<int> zigZagTraversal(Node* root) {
    vector<int> ans;
    bool leftToRight = true;
    int height = treeHeight(root);

    // Traverse the tree by height
    for(int i = 1; i <= height; i++){
        if (leftToRight)
            leftToRightTrav(root, i, ans);
        else
            rightToLeftTrav(root, i, ans);

        // Flip the value of leftToRight
        leftToRight = !leftToRight;
    }

    return ans;
}

void printList(vector<int> v) {
    int n = v.size();
    for (int i=0; i<n; i++) {
        cout << v[i] << " ";
    }
    cout << endl;
}

int main() {

    // Create a hard coded tree.
    //         20
    //       /   \
    //      8     22
    //    /  \     \
    //   4   12    11
    //      /  \
    //     10   14
    Node* root = new Node(20);
    root->left = new Node(8);
    root->right = new Node(22);
    root->right->right = new Node(11);
    root->left->left = new Node(4);
    root->left->right = new Node(12);
    root->left->right->left = new Node(10);
    root->left->right->right = new Node(14);

    vector<int> ans = zigZagTraversal(root);
    printList(ans);

    return 0;
}







Sum of nodes at maximum depth of a Binary Tree | Set 2



// C++ Program to find sum of nodes at maximum
// Depth of the Binary Tree

#include <bits/stdc++.h>
using namespace std;

// Variables to store sum and
// maximum level
int sum = 0, max_level = INT_MIN;

// Binary Tree Node
struct Node {
    int data;
    Node* left;
    Node* right;
};

// Utility function to create and
// return a new Binary Tree Node
Node* createNode(int val)
{

    Node* node = new Node;

    node->data = val;
    node->left = NULL;
    node->right = NULL;

    return node;
}

// Function to find the sum of the node which
// are present at the maximum depth
void sumOfNodesAtMaxDepth(Node* root, int level)
{
    if (root == NULL)
        return;

    // If the current level exceeds the
    // maximum level, update the max_level
    // as current level.
    if (level > max_level) {
        sum = root->data;
        max_level = level;
    }

    // If the max level and current level
    // are same, add the root data to
    // current sum.
    else if (level == max_level) {
        sum = sum + root->data;
    }

    // Traverse the left and right subtrees
    sumOfNodesAtMaxDepth(root->left, level + 1);
    sumOfNodesAtMaxDepth(root->right, level + 1);
}

// Driver Code
int main()
{
    Node* root;
    root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->left = createNode(6);
    root->right->right = createNode(7);

    sumOfNodesAtMaxDepth(root, 0);

    cout << sum;

    return 0;
}




Iterative Boundary Traversal of Complete Binary tree  [Anti-Clockwise order starting from the root]


// C++ program to print boundary traversal
// of a complete binary tree.
#include <bits/stdc++.h>
using namespace std;

class Node {
  public:
    int data;
    Node *left;
    Node *right;
    Node(int x) {
        data = x;
        left = nullptr;
        right = nullptr;
    }
};

// Function to print the nodes of a complete
// binary tree in boundary traversal order
vector<int> boundaryTraversal(Node *root) {
    vector<int> ans;

    if (root == nullptr)
        return ans;

    // If there is only 1 node print it
    // and return
    if (!(root->left) && !(root->right)) {
        ans.push_back(root->data);
        return ans;
    }

    ans.push_back(root->data);

    // Traverse left boundary without root
    // and last node
    Node *l = root->left;
    while (l->left) {
        ans.push_back(l->data);
        l = l->left;
    }

    // BFS designed to only include
      // leaf nodes
    queue<Node *> q;
    q.push(root);
    while (!q.empty()) {
        Node *curr = q.front();
        q.pop();
        if (!(curr->left) && !(curr->right)) {
            ans.push_back(curr->data);
        }
        if (curr->left) {
            q.push(curr->left);
        }
        if (curr->right) {
            q.push(curr->right);
        }
    }

    // Traverse right boundary without root
    // and last node
    vector<int> list;
    Node *r = root->right;
    while (r->right)
    {
        list.push_back(r->data);
        r = r->right;
    }

    // Concatenate the ans and list
    for (int i = list.size() - 1; i >= 0; i--) {
        ans.push_back(list[i]);
    }

    return ans;
}

int main() {

    // Create a hard coded tree.
    //              18
    //           /     \
    //          15      30
    //         /  \     /  \
    //       40    50  100  20

    Node *root = new Node(18);
    root->left = new Node(15);
    root->right = new Node(30);
    root->left->left = new Node(40);
    root->left->right = new Node(50);
    root->right->left = new Node(100);
    root->right->right = new Node(20);

    vector<int> ans = boundaryTraversal(root);
    int n = ans.size();
    for (int i = 0; i < n; i++) {
        cout << ans[i] << " ";
    }
    return 0;
}
