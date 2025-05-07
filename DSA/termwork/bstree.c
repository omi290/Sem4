#include <stdio.h>
#include <stdlib.h>

// Definition of a Node in the BST
typedef struct Node {
    int info;               
    struct Node *left;      
    struct Node *right;     
} node;

// Function to create a new node
node* createNode(int val) {
    node* temp = (node*)malloc(sizeof(node));
    temp->info = val;       
    temp->left = NULL;      
    temp->right = NULL;     
    return temp;
}

// Function to insert a value into the BST
void insert(node** root, int key) {
    if (*root == NULL) {
        *root = createNode(key);
        return;
    }
    if ((*root)->info == key) return; 
    if ((*root)->info > key) 
        insert(&((*root)->left), key); 
    else 
        insert(&((*root)->right), key); 
}

// Function to find the smallest node in the BST
node* findSmallest(node* root) {
    if (root->left == NULL) return root; // The leftmost node is the smallest
    return findSmallest(root->left);
}

// Function to find the maximum value in the left subtree
int findMaxInLeftSubtree(node* root) {
    while (root->right != NULL) { // Keep moving right to find the maximum
        root = root->right;
    }
    return root->info;
}

// Function to delete a node from the BST
node* deleteNode(node* root, int key) {
    if (root == NULL) return root; // Base case: tree is empty

    // Traverse the tree to find the node to delete
    if (key < root->info) 
        root->left = deleteNode(root->left, key); 
    else if (key > root->info) 
        root->right = deleteNode(root->right, key); 
    else { // Node to be deleted is found
        // Case 1: Node has no children
        if (root->left == NULL && root->right == NULL) {
            free(root);
            return NULL;
        }
        // Case 2: Node has one child
        if (root->left != NULL && root->right == NULL) {
            node* temp = root->left;
            free(root);
            return temp;
        }
        if (root->left == NULL && root->right != NULL) {
            node* temp = root->right;
            free(root);
            return temp;
        }
        // Case 3: Node has two children
        int max = findMaxInLeftSubtree(root->left); 
        root->info = max; 
        root->left = deleteNode(root->left, max); 
    }
    return root;
}

// Function to calculate the height of the BST
int height(node* root) {
    if (root == NULL) return 0; // Base case: height of an empty tree is 0
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
}

// Inorder traversal of the BST (Left, Root, Right)
void inorder(node* root) {
    if (root == NULL) return;
    inorder(root->left);
    printf("%d ", root->info); // Visit the root
    inorder(root->right);
}

// Function to count nodes in the right subtree of the root
int countRightNode(node* root) {
    if (root == NULL) return 0;
    int count = 0;
    if (root->right != NULL) count++; // Increment count if a right child exists
    count += countRightNode(root->right);
    count += countRightNode(root->left);
    return count;
}

// Function to count nodes having both children (common parent)
int countNodesWithParent(node* root) {
    if (root == NULL) return 0;
    int count = 0;
    if (root->left != NULL && root->right != NULL) count++; // Check if both children exist
    count += countNodesWithParent(root->left);
    count += countNodesWithParent(root->right);
    return count;
}

// Function to free the memory allocated for the BST
void freeTree(node* root) {
    if (root == NULL) return;
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

// Main function
int main() {
    node* root = NULL;
    int n, ch = 0;

    // Input: Number of nodes and their values
    printf("Enter Number of Nodes: ");
    scanf("%d", &n);
    printf("Enter Values: ");
    for (int i = 0; i < n; i++) {
        int val;
        scanf("%d", &val);
        insert(&root, val); // Insert each value into the BST
    }

    // Menu-driven program
    printf("1. Insert\n2. Find smallest data\n3. Delete node\n");
    printf("4. Count nodes with common parents\n5. Height of BST\n");
    printf("6. Count nodes in right subtree\n7. Display (inorder traversal)\n8. Exit\n");

    do {
        printf("Enter Your Choice: ");
        scanf("%d", &ch);
        switch (ch) {
        case 1: {
            int val;
            printf("Enter Value: ");
            scanf("%d", &val);
            insert(&root, val); // Insert a new value
            break;
        }
        case 2: {
            node* sNode = findSmallest(root); 
            printf("Node having smallest data = %d\n", sNode->info);
            break;
        }
        case 3: {
            int key;
            printf("Enter value to delete: ");
            scanf("%d", &key);
            root = deleteNode(root, key); 
            break;
        }
        case 4: {
            int cnt = countNodesWithParent(root); 
            printf("Total number of nodes having a common parent: %d\n", cnt);
            break;
        }
        case 5: {
            int h = height(root); 
            printf("Height of the tree is %d\n", h);
            break;
        }
        case 6: {
            int cnt = countRightNode(root); 
            printf("Count of nodes in the right subtree: %d\n", cnt);
            break;
        }
        case 7: {
            printf("Inorder Traversal: ");
            inorder(root); // Perform inorder traversal
            printf("\n");
            break;
        }
        case 8: {
            printf("Exiting...\n");
            freeTree(root); // Free the memory allocated for the BST
            break;
        }
        default:
            printf("Enter valid choice!\n");
        }
    } while (ch != 8);

    return 0;
}
