/*
 * Problem Statement:
 * 2. Roll Number Sorting System using Bubble Sort
 * Create a program to organize student roll numbers.
 * a. Accept roll numbers from the user.
 * b. Sort them in ascending order using Bubble Sort.
 * c. Display sorted roll numbers.
 * d. Display intermediate passes of sorting.
 *
 * Title : Roll Number Sorting System Using Bubble Sort
 * Roll No : CO2087
 */
#include <stdio.h>

int main()
{
    int n, i, j;
    int rollno[20];
    int temp;

    // Accept number of students
    printf("Enter number of students: ");
    scanf("%d", &n);

    // Accept roll numbers
    printf("Enter %d roll numbers:\n", n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &rollno[i]);
    }

    // Bubble Sort
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (rollno[j] > rollno[j + 1])
            {
                temp = rollno[j];
                rollno[j] = rollno[j + 1];
                rollno[j + 1] = temp;
            }
        }

        // Display intermediate pass
        printf("Pass %d: ", i + 1);
        for (j = 0; j < n; j++)
        {
            printf("%d ", rollno[j]);
        }
        printf("\n");
    }

    // Display sorted roll numbers
    printf("\nSorted Roll Numbers in Ascending Order:\n");
    for (i = 0; i < n; i++)
    {
        printf("%d \n", rollno[i]);
    }

    return 0;
}

/*
Output:
Enter number of students: 6
Enter 6 roll numbers:
45
65
32
12
33
46
Pass 1: 45 32 12 33 46 65
Pass 2: 32 12 33 45 46 65
Pass 3: 12 32 33 45 46 65
Pass 4: 12 32 33 45 46 65
Pass 5: 12 32 33 45 46 65

Sorted Roll Numbers in Ascending Order:
12
32
33
45
46
65
*/
