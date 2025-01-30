#include <stdio.h>  // Standard input/output library
#include <stdlib.h> // Standard library for memory allocation and other utilities
#include <ctype.h>  // Library for character handling functions like isdigit()

// Define a structure for a Node in the stack
struct Node {
    int data;           // Data part of the node
    struct Node* next;  // Pointer to the next node in the stack
};

// Define a structure for the Stack itself
struct Stack {
    struct Node* top; // Pointer to the top node of the stack
    int length;       // To keep track of the number of elements in the stack
};

// Function to initialize the stack
void Under_Stack(struct Stack* s) {
    s->top = NULL;  // Initially, the stack is empty
    s->length = 0;  // Length is set to 0
}

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node)); // Allocate memory for new node
    if (!newNode) { // Check if memory allocation failed
        return NULL;
    }
    newNode->data = data; // Assign data
    newNode->next = NULL; // Initialize next as NULL
    return newNode;
}

// Function to push an element onto the stack
void push(struct Stack* s, int value) {
    struct Node* newNode = createNode(value); // Create a new node with the given value
    if (!newNode) return; // If memory allocation failed, return

    newNode->next = s->top; // Point new node's next to the current top node
    s->top = newNode;       // Update the top to the new node
    s->length++;            // Increase stack length
}

// Function to pop an element from the stack
int pop(struct Stack* s) {
    if (s->top == NULL) { // Check if stack is empty
        printf("Stack underflow\n");
        return -1; // Return -1 to indicate stack underflow
    }

    struct Node* temp = s->top; // Store the top node in temp
    int a = temp->data;         // Retrieve the data from the top node
    s->top = temp->next;        // Move the top pointer to the next node
    free(temp);                 // Free memory of the popped node
    s->length--;                // Decrease stack length
    return a;                   // Return the popped value
}

// Function to get the current length of the stack
int getLength(struct Stack* s) {
    return s->length;
}

// Main function
int main() {
    struct Stack s;       // Declare a stack structure
    Under_Stack(&s);      // Initialize the stack

    char value[10000];    // Array to store user input
    fgets(value, sizeof(value), stdin); // Read input from user

    int j = 0;

    // Remove spaces and newline characters from input
    for (int i = 0; value[i] != '\0'; i++) {
        if (value[i] != ' ' && value[i] != '\n') {
            value[j++] = value[i]; // Shift characters to remove spaces
        }
    }
    value[j] = '\0'; // Null terminate the cleaned-up string

    // Process the expression (assuming Reverse Polish Notation - RPN)
    for (int i = 0; value[i] != '\0'; i++) {
        if (isdigit(value[i])) { // If character is a digit
            push(&s, value[i] - '0'); // Convert char to int and push onto stack
        } else { // If it's an operator
            int op2 = pop(&s); // Pop the second operand
            int op1 = pop(&s); // Pop the first operand

            // Perform the operation based on the operator
            switch (value[i]) {
                case '+':
                    push(&s, op1 + op2); // Push result of addition
                    break;
                case '-':
                    push(&s, op1 - op2); // Push result of subtraction
                    break;
                case '*':
                    push(&s, op1 * op2); // Push result of multiplication
                    break;
                case '/':
                    push(&s, op1 / op2); // Push result of division
                    break;
                default:
                    printf("Invalid operator: %c\n", value[i]); // Handle invalid operator
                    return 1; // Exit with error
            }
        }
    }

    // If only one element remains in the stack, it's the result
    if (getLength(&s) == 1) {
        printf("%d\n", pop(&s)); // Print the result
    } else {
        printf("Invalid expression\n"); // If stack isn't empty, input was incorrect
    }

    return 0; // Exit program successfully
}



















#include <iostream>  // Standard input-output library
#include <queue>     // Queue library to use queue data structure
#include <string>    // String library for handling customer names

using namespace std; // Use the standard namespace to avoid std:: prefix

const int Max = 1000; // Define a constant for the maximum number of customers allowed in the queue

int main()
{
    queue<string> Q; // Create a queue to store customer names
    int choice;      // Variable to store user's menu choice

    // Infinite loop to continuously display the menu until the shop is closed
    while (true)
    {
        // Display menu options
        cout << "1. Add new customer" << endl;
        cout << "2. Give biryani to customer" << endl;
        cout << "3. Total customers in line" << endl;
        cout << "4. Close shop" << endl;
        cout << "Enter your choice:" << endl;

        cin >> choice; // Take user input for menu selection

        // Switch case to handle user choice
        switch (choice)
        {
            // Case 1: Add a new customer to the queue
            case 1:
            {
                if (Q.size() < Max) // Check if the queue has space
                {
                    string name;
                    cout << "Enter your customer name:" << endl;
                    cin.ignore(); // Clear the input buffer to avoid getline() issues
                    getline(cin, name); // Get the full name (including spaces) from user input
                    Q.push(name); // Add the customer name to the queue
                    cout << name << " is added to the list!" << endl;
                }
                else // If the queue is full
                {
                    cout << "No more customers can be added!" << endl;
                }
                break;
            }

            // Case 2: Serve biryani to the first customer in the queue
            case 2:
            {
                if (!Q.empty()) // Check if there are customers in the queue
                {
                    cout << "Given biryani to " << Q.front() << "!" << endl; // Serve the first customer
                    Q.pop(); // Remove the served customer from the queue
                }
                else // If no customers are in line
                {
                    cout << "No customer in line!" << endl;
                }
                break;
            }

            // Case 3: Display total number of customers waiting in the queue
            case 3:
            {
                cout << "Total " << Q.size() << " customers in line" << endl;
                break;
            }

            // Case 4: Close the shop and exit the loop
            case 4:
            {
                cout << "Close shop" << endl;
                return 0; // Exit the program
            }

            // Default case: Handle invalid input
            default:
            {
                cout << "Invalid choice, please try again." << endl;
                break;
            }
        }
    }

    return 0; // Return 0 to indicate successful program execution
}
















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




