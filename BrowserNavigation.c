/*
 * Lab Assignment No: 4
 * Title: Browser Navigation System Using Stack
 * Roll No: CO2057
 * Problem Statement:
 * Implement a real-time browser navigation system using two stacks to simulate
 * Back and Forward navigation supporting Visit New Page, Back Navigation,
 * Forward Navigation, and Display Current Page.
 */

#include <stdio.h>
#include <string.h>

#define max 100
#define size 200

int main()
{
    char forwardstack[max][size];
    char backstack[max][size];
    char current[size] = "Home";
    char newpage[size];
    int backTop = -1;
    int forwardTop = -1;
    int choice;
    do
    {
        printf("\n---MENU ---");
        printf("\n1. Visit New Page\n2. Back Navigation\n3. Forward Navigation\n4. Display Current Page\n5. EXIT");

        printf("\nEnter Your Choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1: // Visit new page
                printf("\nEnter new page: ");
                scanf("%199s", newpage);
                if (backTop == max - 1)
                {
                    printf("Back Stack Overflow!\n");
                }
                else
                {
                    // Push current page into Back Stack
                    backTop++;
                    strcpy(backstack[backTop], current);
                    // Make new page current
                    strcpy(current, newpage);
                    // Clear Forward Stack
                    forwardTop = -1;
                    printf("Visited: %s\n", current);
                }
                break;

            case 2: // Back navigation
                if (backTop == -1)
                {
                    printf("No previous page available.\n");
                }
                else
                {
                    if (forwardTop == max - 1)
                    {
                        printf("Forward Stack Overflow!\n");
                    }
                    else
                    {
                        // Push current page into Forward Stack
                        forwardTop++;
                        strcpy(forwardstack[forwardTop], current);
                        // Pop page from Back Stack
                        strcpy(current, backstack[backTop]);
                        backTop--;
                        printf("Back to: %s\n", current);
                    }
                }
                break;

            case 3: // Forward navigation
                if (forwardTop == -1)
                {
                    printf("No forward page available.\n");
                }
                else
                {
                    // Check Back Stack overflow
                    if (backTop == max - 1)
                    {
                        printf("Back Stack Overflow!\n");
                    }
                    else
                    {
                        // Push current page into Back Stack
                        backTop++;
                        strcpy(backstack[backTop], current);
                        // Pop page from Forward Stack
                        strcpy(current, forwardstack[forwardTop]);
                        forwardTop--;
                        printf("Forward to: %s\n", current);
                    }
                }
                break;

            case 4: // Display current page
                printf("Current Page: %s\n", current);
                break;

            case 5: // Exiting program
                printf("EXIT\n");
                break;

            default:
                printf("Invalid Choice!\n");
        }
    } while (choice != 5);

    return 0;
}
