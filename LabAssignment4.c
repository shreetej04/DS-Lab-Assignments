/*
Title: Dynamic Contact List Management Using Linked List
Roll No: C02087

Problem Statement:
Design and implement a contact management system using a singly linked list. 
Each contact should contain:
- Name
- Phone Number

The system should provide the following operations:
a. Insert a new contact at the beginning of the list.
b. Insert a new contact at the end of the list.
c. Delete a contact using the name.
d. Search for a contact using the name.
e. Display all contacts.
f. Demonstrate proper dynamic memory allocation and deallocation.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct contact
{
    char name[30];
    long int phone;
    struct contact *next;
};

int main()
{
    struct contact *head = NULL;
    struct contact *newnode, *temp, *prev;
    char name[30];
    int choice;

    do
    {
        printf("\n==== MENU ====");
        printf("\n1.Insert New Contact \n2.Insert New Contact At End \n3.Delete a Contact Using Name \n4.Search Contact \n5.Display All Contacts \n6.Exit");
        printf("\nEnter Your Choice : ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1: // Insert at beginning
            newnode = (struct contact *)malloc(sizeof(struct contact));
            printf("Enter name: ");
            scanf("%s", newnode->name);
            printf("Enter phone: ");
            scanf("%ld", &newnode->phone);
            newnode->next = head;
            head = newnode;
            break;

        case 2: // Insert New Contact At End
            newnode = (struct contact *)malloc(sizeof(struct contact));
            printf("Enter name: ");
            scanf("%s", newnode->name);
            printf("Enter phone: ");
            scanf("%ld", &newnode->phone);
            newnode->next = NULL;
            if (head == NULL)
            {
                head = newnode;
            }
            else
            {
                temp = head;
                while (temp->next != NULL)
                {
                    temp = temp->next;
                }
                temp->next = newnode;
            }
            break;

        case 3: // Delete a Contact Using Name
            printf("Enter name to delete: ");
            scanf("%s", name);
            temp = head;
            prev = NULL;
            while (temp != NULL && strcmp(temp->name, name) != 0)
            {
                prev = temp;
                temp = temp->next;
            }
            if (temp == NULL)
            {
                printf("Contact not found.\n");
            }
            else
            {
                if (prev == NULL)
                {
                    head = temp->next;
                }
                else
                {
                    prev->next = temp->next;
                }
                free(temp);
                printf("Contact deleted successfully.\n");
            }
            break;

        case 4: // Search Contact
            printf("Enter name to search: ");
            scanf("%s", name);
            temp = head;
            while (temp != NULL)
            {
                if (strcmp(temp->name, name) == 0)
                {
                    printf("Contact Found\n");
                    printf("Name:%s\n", temp->name);
                    printf("Phone:%ld\n", temp->phone);
                    break;
                }
                temp = temp->next;
            }
            break;

        case 5: // Display Contacts
            temp = head;
            while (temp != NULL)
            {
                printf("Name:%s\n", temp->name);
                printf("Phone:%ld\n", temp->phone);
                temp = temp->next;
            }
            break;

        case 6: // Exiting Program
            printf("Exit\n");
            break;
        }
    } while (choice != 6);

    return 0;
}
