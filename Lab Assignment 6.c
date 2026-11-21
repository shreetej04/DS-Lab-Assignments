/*
Design and implement a C program that uses a Binary Search Tree (BST) to store student roll 
numbers. The system should support the following operations:
a. Insert: Add a new student roll number into the tree.
b. Delete: Remove a student record based on roll number.
c. Search: Search for a specific student.
d. Traversal: Display all student records using inorder, preorder, or postorder traversal.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Node {
 int rollNo;
 char name[50];
 struct Node *left;
 struct Node *right;
};
struct Node *createNode(int rollNo, const char *name) {
 struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
 if (newNode == NULL) {
 printf("Memory allocation failed!\n");
 exit(1);
 }
 newNode->rollNo = rollNo;
 snprintf(newNode->name, sizeof(newNode->name), "%s", name);
 newNode->left = NULL;
 newNode->right = NULL;
 return newNode;
}
struct Node *insert(struct Node *root, int rollNo, const char *name) {
 if (root == NULL)
 return createNode(rollNo, name);
 if (rollNo < root->rollNo)
 root->left = insert(root->left, rollNo, name);
 else if (rollNo > root->rollNo)
 root->right = insert(root->right, rollNo, name);
 else
 printf("Roll Number %d already exists!\n", rollNo);
 return root;
}
struct Node *findMin(struct Node *node) {
 while (node != NULL && node->left != NULL)
 node = node->left;
 return node;
}
struct Node *deleteNode(struct Node *root, int rollNo) {
 if (root == NULL)
 return NULL;
 if (rollNo < root->rollNo) {
 root->left = deleteNode(root->left, rollNo);
 } else if (rollNo > root->rollNo) {
 root->right = deleteNode(root->right, rollNo);
 } else {
 if (root->left == NULL) {
 struct Node *temp = root->right;
 free(root);
 return temp;
 } else if (root->right == NULL) {
 struct Node *temp = root->left;
 free(root);
 return temp; }
 struct Node *temp = findMin(root->right);
 root->rollNo = temp->rollNo;
 snprintf(root->name, sizeof(root->name), "%s", temp->name);
 root->right = deleteNode(root->right, temp->rollNo);
 }
 return root;
}
struct Node *search(struct Node *root, int rollNo) {
 if (root == NULL || root->rollNo == rollNo)
 return root;
 if (rollNo < root->rollNo)
 return search(root->left, rollNo);
 return search(root->right, rollNo);
}
void inorder(struct Node *root) {
 if (root != NULL) {
 inorder(root->left);
 printf("Roll No: %d | Name: %s\n", root->rollNo, root->name);
 inorder(root->right);
 }
}
void preorder(struct Node *root) {
 if (root != NULL) {
 printf("Roll No: %d | Name: %s\n", root->rollNo, root->name);
 preorder(root->left);
 preorder(root->right);
 }
}
void postorder(struct Node *root) {
 if (root != NULL) {
 postorder(root->left);
 postorder(root->right);
 printf("Roll No: %d | Name: %s\n", root->rollNo, root->name);
 }
}
void freeTree(struct Node *root) {
 if (root != NULL) {
 freeTree(root->left);
 freeTree(root->right);
 free(root);
 }
}
int main(void) {
 struct Node *root = NULL;
 int choice, rollNo;
 char name[50];
 while (1) {
 printf("\n--- Student BST Management System ---\n");
 printf("1. Add a new student record (Insert)\n");
 printf("2. Remove a student record (Delete)\n");
 printf("3. Search for a student record\n");
 printf("4. Display records (Inorder - Sorted)\n");
 printf("5. Display records (Preorder)\n");
 printf("6. Display records (Postorder)\n");
 printf("7. Exit\n");
 printf("Enter your choice: ");
 if (scanf("%d", &choice) != 1) break;
 switch (choice) {
 case 1:
 printf("Enter Roll Number: ");
 if (scanf("%d", &rollNo) != 1) {
 freeTree(root);
return 0;
 }
 printf("Enter Student Name (single word): ");
 if (scanf("%49s", name) != 1) {
 freeTree(root);
return 0;
 }
 root = insert(root, rollNo, name);
 break;
 case 2:
 printf("Enter Roll Number to remove: ");
 if (scanf("%d", &rollNo) != 1) {
 freeTree(root);
return 0;
 }
 if (search(root, rollNo) == NULL) {
 printf("Student with Roll No %d not found.\n", rollNo);
 } else {
 root = deleteNode(root, rollNo);
printf("Record removed successfully.\n");
 }
 break;
 case 3: {
 printf("Enter Roll Number to search: ");
 if (scanf("%d", &rollNo) != 1) {
 freeTree(root);
return 0;
 }
 struct Node *found = search(root, rollNo);
 if (found != NULL)
 printf("Student Found -> Roll No: %d | Name: %s\n",
 found->rollNo, found->name);
 else
 printf("Student with Roll No %d not found.\n", rollNo);
 break;
 }
 case 4:
 printf("\n--- Inorder Traversal ---\n");
 if (root == NULL) printf("Tree is empty.\n");
 else inorder(root);
 break;
 case 5:
 printf("\n--- Preorder Traversal ---\n");
 if (root == NULL) printf("Tree is empty.\n");
 else preorder(root);
 break;
 case 6:
 printf("\n--- Postorder Traversal ---\n");
 if (root == NULL) printf("Tree is empty.\n");
 else postorder(root);
 break;
 case 7:
 printf("Exiting program.\n");
 freeTree(root);
 return 0; default:
 printf("Invalid choice! Please try again.\n");
 }
 }
 freeTree(root);
 return 0;
}
/*
Output: 
--- Student BST Management System ---
1. Add a new student record (Insert)
2. Remove a student record (Delete)
3. Search for a student record
4. Display records (Inorder - Sorted)
5. Display records (Preorder)
6. Display records (Postorder)
7. Exit
Enter your choice: 1
Enter Roll Number: 30
Enter Student Name (single word): Asha
--- Student BST Management System ---
1. Add a new student record (Insert)
2. Remove a student record (Delete)
3. Search for a student record
4. Display records (Inorder - Sorted)
5. Display records (Preorder)
6. Display records (Postorder)
7. Exit
Enter your choice: 1
Enter Roll Number: 20
Enter Student Name (single word): Rahul
--- Student BST Management System ---
1. Add a new student record (Insert)
2. Remove a student record (Delete)
3. Search for a student record
4. Display records (Inorder - Sorted)
5. Display records (Preorder)
6. Display records (Postorder)
7. Exit
Enter your choice: 1
Enter Roll Number: 40
Enter Student Name (single word): Neha
--- Student BST Management System ---
1. Add a new student record (Insert)
2. Remove a student record (Delete)
3. Search for a student record
4. Display records (Inorder - Sorted)
5. Display records (Preorder)
6. Display records (Postorder)
7. Exit
Enter your choice: 4
--- Inorder Traversal ---
Roll No: 20 | Name: Rahul
Roll No: 30 | Name: Asha
Roll No: 40 | Name: Neha
--- Student BST Management System ---
1. Add a new student record (Insert)
2. Remove a student record (Delete)
3. Search for a student record
4. Display records (Inorder - Sorted)
5. Display records (Preorder)
6. Display records (Postorder)
7. Exit
Enter your choice: 5 Preorder Traversal ---
Roll No: 30 | Name: Asha
Roll No: 20 | Name: Rahul
Roll No: 40 | Name: Neha
--- Student BST Management System ---
1. Add a new student record (Insert)
2. Remove a student record (Delete)
3. Search for a student record
4. Display records (Inorder - Sorted)
5. Display records (Preorder)
6. Display records (Postorder)
7. Exit
Enter your choice: 6
--- Postorder Traversal ---
Roll No: 20 | Name: Rahul
Roll No: 40 | Name: Neha
Roll No: 30 | Name: Asha
--- Student BST Management System ---
1. Add a new student record (Insert)
2. Remove a student record (Delete)
3. Search for a student record
4. Display records (Inorder - Sorted)
5. Display records (Preorder)
6. Display records (Postorder)
7. Exit
Enter your choice: 3
Enter Roll Number to search: 20
Student Found -> Roll No: 20 | Name: Rahul
--- Student BST Management System ---
1. Add a new student record (Insert)
2. Remove a student record (Delete)
3. Search for a student record
4. Display records (Inorder - Sorted)
5. Display records (Preorder)
6. Display records (Postorder)
7. Exit
Enter your choice: 2
Enter Roll Number to remove: 20
Record removed successfully.
--- Student BST Management System ---
1. Add a new student record (Insert)
2. Remove a student record (Delete)
3. Search for a student record
4. Display records (Inorder - Sorted)
5. Display records (Preorder)
6. Display records (Postorder)
7. Exit
Enter your choice: 4
--- Inorder Traversal ---
Roll No: 30 | Name: Asha
Roll No: 40 | Name: Neha
--- Student BST Management System ---
1. Add a new student record (Insert)
2. Remove a student record (Delete)
3. Search for a student record
4. Display records (Inorder - Sorted)
5. Display records (Preorder)
6. Display records (Postorder)
7. Exit
Enter your choice: 7
Exiting program.
*/
