/*
Implement Array Operations and Searching Write a program to store marks of students using an array
a. Insert marks of students.
b. Delete a mark from a given position.
c. Display all marks.
d. Search a mark using Linear Search. 
e. Sort the array and search using Binary Search
*/
#include <stdio.h>

int main()
{
    int a[100], n = 0, i, j, temp;
    int choice, pos, key;
    int low, high, mid, found;

    do
    {
        printf("\n--- Menu ---\n");
        printf("1. Insert Element\n");
        printf("2. Delete\n");
        printf("3. Display\n");
        printf("4. Linear Search\n");
        printf("5. Binary Search\n");
        printf("6. Exit\n");

        printf("Enter your Choice : ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                printf("Enter the size of Array : ");
                scanf("%d", &n);

                if(n <= 0 || n > 100)
                {
                    printf("Invalid size!\n");
                    n = 0;
                    break;
                }

                printf("Enter the marks : ");
                for(i = 0; i < n; i++)
                {
                    scanf("%d", &a[i]);
                }
                break;

            case 2:
                if(n == 0)
                {
                    printf("Array is empty!\n");
                    break;
                }

                printf("Enter Position: ");
                scanf("%d", &pos);

                if(pos < 1 || pos > n)
                {
                    printf("Invalid Position!\n");
                }
                else
                {
                    for(i = pos - 1; i < n - 1; i++)
                    {
                        a[i] = a[i + 1];
                    }

                    n--;
                    printf("Deleted Successfully\n");
                }
                break;

            case 3:
                if(n == 0)
                {
                    printf("Array is empty!\n");
                }
                else
                {
                    printf("The Elements of Array are :\n");

                    for(i = 0; i < n; i++)
                    {
                        printf("%d\n", a[i]);
                    }
                }
                break;

            case 4:
                if(n == 0)
                {
                    printf("Array is empty!\n");
                    break;
                }

                printf("Enter element to search: ");
                scanf("%d", &key);

                found = 0;

                for(i = 0; i < n; i++)
                {
                    if(a[i] == key)
                    {
                        printf("Element %d found at position %d, (index %d)\n",
                               key, i + 1, i);
                        found = 1;
                        break;
                    }
                }

                if(found == 0)
                {
                    printf("Element Not Found\n");
                }
                break;

            case 5:
                if(n == 0)
                {
                    printf("Array is empty!\n");
                    break;
                }

                // Bubble Sort
                for(i = 0; i < n - 1; i++)
                {
                    for(j = 0; j < n - i - 1; j++)
                    {
                        if(a[j] > a[j + 1])
                        {
                            temp = a[j];
                            a[j] = a[j + 1];
                            a[j + 1] = temp;
                        }
                    }
                }

                printf("Sorted Array : ");
                for(i = 0; i < n; i++)
                {
                    printf("%d ", a[i]);
                }

                printf("\nEnter element to search: ");
                scanf("%d", &key);

                // Binary Search
                low = 0;
                high = n - 1;
                found = 0;

                while(low <= high)
                {
                    mid = (low + high) / 2;

                    if(a[mid] == key)
                    {
                        printf("Element %d found at position %d, (index %d)\n",
                               key, mid + 1, mid);
                        found = 1;
                        break;
                    }
                    else if(key > a[mid])
                    {
                        low = mid + 1;
                    }
                    else
                    {
                        high = mid - 1;
                    }
                }

                if(found == 0)
                {
                    printf("Element Not Found\n");
                }
                break;

            case 6:
                printf("Exiting Program...\n");
                break;

            default:
                printf("Invalid Choice!\n");
        }

    } while(choice != 6);

    return 0;
}

/*
--- Menu ---
1. Insert Element
2. Delete
3. Display
4. Linear Search
5. Binary Search
6. Exit
Enter your Choice : 1
Enter the size of Array : 6
Enter the marks : 40 50 60 70 80 90

--- Menu ---
1. Insert Element
2. Delete
3. Display
4. Linear Search
5. Binary Search
6. Exit
Enter your Choice : 2
Enter Position: 3
Deleted Successfully

--- Menu ---
1. Insert Element
2. Delete
3. Display
4. Linear Search
5. Binary Search
6. Exit
Enter your Choice : 3
The Elements of Array are :
40
50
70
80
90

--- Menu ---
1. Insert Element
2. Delete
3. Display
4. Linear Search
5. Binary Search
6. Exit
Enter your Choice : 4
Enter element to search: 70
Element 70 found at position 3, (index 2)

--- Menu ---
1. Insert Element
2. Delete
3. Display
4. Linear Search
5. Binary Search
6. Exit
Enter your Choice : 5
Sorted Array : 40 50 70 80 90 
Enter element to search: 50
Element 50 found at position 2, (index 1)

--- Menu ---
1. Insert Element
2. Delete
3. Display
4. Linear Search
5. Binary Search
6. Exit
Enter your Choice : 6
Exiting Program...
*/
