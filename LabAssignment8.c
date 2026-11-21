/*
  Library Book Indexing uring Hashing
Develop a program to manage book IDs in a library using a hash Table
a.  Insert book IDs using a hash function 
b. Search for a specific book id
c. Handle Collisions using open addressing.
(linear probing)
*/

#include <stdio.h>
#define TABLE_SIZE 10
// Declare the hash table
int hashTable[TABLE_SIZE];
// Function to initialize the hash table
void initialize()
{
 for (int i = 0; i < TABLE_SIZE; i++)
 {
 hashTable[i] = -1; // -1 means the position is empty
 }
}
// Function to insert a book ID using linear probing
void insertBook(int key)
{
 int index = key % TABLE_SIZE;
 // Check each position using linear probing
 for (int i = 0; i < TABLE_SIZE; i++)
 {
 int pos = (index + i) % TABLE_SIZE;
 if (hashTable[pos] == key)
 {
 printf("Book ID already exists.\n");
 return;
 }
 if (hashTable[pos] == -1)
 {
 hashTable[pos] = key;
 printf("Book ID inserted successfully.\n");
 return;
 }
 } // Display message if no empty position is available
 printf("Hash table is full.\n");
}
// Function to search for a book ID
void searchBook(int key)
{
 int index = key % TABLE_SIZE;
 // Search using linear probing
 for (int i = 0; i < TABLE_SIZE; i++)
 {
 int pos = (index + i) % TABLE_SIZE;
 if (hashTable[pos] == -1)
 {
 printf("Book ID not found.\n");
 return;
 }
 if (hashTable[pos] == key)
 {
 printf("Book ID found at index %d.\n", pos);
 return;
 }
 }
 printf("Book ID not found.\n");
}
// Function to display the hash table
void display()
{
 printf("\nHash Table:\n");
 for (int i = 0; i < TABLE_SIZE; i++)
 {
 if (hashTable[i] == -1)
 printf("Index %d : EMPTY\n", i);
 else
 printf("Index %d : %d\n", i, hashTable[i]);
 }
} // Main function
int main()
{
 int choice, key;
 initialize();
 // Display menu until the user exits
 do
 {
 printf("\n--- Library Book Indexing ---\n");
 printf("1. Insert Book ID\n");
 printf("2. Search Book ID\n");
 printf("3. Display Hash Table\n");
 printf("4. Exit\n");
 printf("Enter your choice: ");
 scanf("%d", &choice);
 switch (choice)
 {
 case 1:
 printf("Enter Book ID: ");
 scanf("%d", &key);
 insertBook(key);
 break;
 case 2:
 printf("Enter Book ID to search: ");
 scanf("%d", &key);
 searchBook(key);
 break;
 case 3:
 display();
 break;
 case 4:
 printf("Exiting program.\n");
 break;
 default:
 printf("Invalid choice.\n");
 } } while (choice != 4);
 return 0;
}
/*
output:
--- Library Book Indexing ---
1. Insert Book ID
2. Search Book ID
3. Display Hash Table
4. Exit
Enter your choice: 1
Enter Book ID: 11
Book ID inserted successfully.
--- Library Book Indexing ---
1. Insert Book ID
2. Search Book ID
3. Display Hash Table
4. Exit
Enter your choice: 1
Enter Book ID: 12
Book ID inserted successfully.
--- Library Book Indexing ---
1. Insert Book ID
2. Search Book ID
3. Display Hash Table
4. Exit
Enter your choice: 2
Enter Book ID to search: 12
Book ID found at index 2.
--- Library Book Indexing ---
1. Insert Book ID
2. Search Book ID
3. Display Hash Table
4. Exit
Enter your choice: 3
Hash Table:
Index 0 : EMPTY Index 1 : 11
Index 2 : 12
Index 3 : EMPTY
Index 4 : EMPTY
Index 5 : EMPTY
Index 6 : EMPTY
Index 7 : EMPTY
Index 8 : EMPTY
Index 9 : EMPTY
--- Library Book Indexing ---
1. Insert Book ID
2. Search Book ID
3. Display Hash Table
4. Exit
Enter your choice: 4
Exiting program.
  */
