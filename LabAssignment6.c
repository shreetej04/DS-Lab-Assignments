
// HOSPITAL PATIENT REGISTRATION SYSTEM
// Lab Assignment 5
// CO2087

/*
PROBLEM STATEMENT:

A hospital receives patients for consultation. Each patient
is assigned a unique Patient ID and an Arrival Time.

Patients are attended in the order in which they arrive.

Implement a Queue-based system that supports:

1. addPatient() - Add a patient at the rear of the queue.
2. attendPatient() - Remove and attend the front patient.
3. viewPatients() - Display all waiting patients.
4. isQueueEmpty() - Check whether the queue is empty.
*/

#include <stdio.h>

#define MAX 5

// Structure for Patient
struct Patient
{
    int patientID;
    char arrivalTime[20];
};

// Queue declaration
struct Patient queue[MAX];

int front = -1, rear = -1;

// 1. Add Patient
void addPatient(int patientID, char arrivalTime[])
{
    if (rear == MAX - 1)
    {
        printf("Queue Overflow! Queue is full.\n");
        return;
    }

    if (front == -1)
    {
        front = 0;
    }

    rear++;

    queue[rear].patientID = patientID;

    int i = 0;

    while (arrivalTime[i] != '\0')
    {
        queue[rear].arrivalTime[i] = arrivalTime[i];
        i++;
    }

    queue[rear].arrivalTime[i] = '\0';

    printf("Patient added successfully.\n");
}

// 2. Attend Patient
void attendPatient()
{
    if (front == -1)
    {
        printf("Queue Underflow! No patients waiting.\n");
        return;
    }

    printf("\nAttending Patient ID: %d\n",
           queue[front].patientID);

    printf("Arrival Time: %s\n",
           queue[front].arrivalTime);

    if (front == rear)
    {
        front = rear = -1;
    }
    else
    {
        front++;
    }
}

// 3. View Patients
void viewPatients()
{
    if (front == -1)
    {
        printf("No patients waiting.\n");
        return;
    }

    printf("\nPatients Waiting:\n");
    printf("Patient ID\tArrival Time\n");

    for (int i = front; i <= rear; i++)
    {
        printf("%d\t\t%s\n",
               queue[i].patientID,
               queue[i].arrivalTime);
    }
}

// 4. Check Queue Empty
void isQueueEmpty()
{
    if (front == -1)
    {
        printf("Queue is empty.\n");
    }
    else
    {
        printf("Queue is not empty.\n");
    }
}

// Main Function
int main()
{
    int choice, patientID;
    char arrivalTime[20];

    do
    {
        printf("\n--- Hospital Patient Registration System ---\n");
        printf("1. Add Patient\n");
        printf("2. Attend Patient\n");
        printf("3. View Patients\n");
        printf("4. Check Queue Empty\n");
        printf("5. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("Enter Patient ID: ");
                scanf("%d", &patientID);

                printf("Enter Arrival Time (e.g. 10:30AM): ");
                scanf("%19s", arrivalTime);

                addPatient(patientID, arrivalTime);
                break;

            case 2:
                attendPatient();
                break;

            case 3:
                viewPatients();
                break;

            case 4:
                isQueueEmpty();
                break;

            case 5:
                printf("Exiting program.\n");
                break;

            default:
                printf("Invalid choice! Try again.\n");
        }

    } while (choice != 5);

    return 0;
}

/*
SAMPLE OUTPUT:

--- Hospital Patient Registration System ---
1. Add Patient
2. Attend Patient
3. View Patients
4. Check Queue Empty
5. Exit

Enter your choice: 1
Enter Patient ID: 101
Enter Arrival Time (e.g. 10:30AM): 9:15PM
Patient added successfully.

Enter your choice: 1
Enter Patient ID: 102
Enter Arrival Time (e.g. 10:30AM): 9:30PM
Patient added successfully.

Enter your choice: 3

Patients Waiting:
Patient ID      Arrival Time
101             9:15PM
102             9:30PM

Enter your choice: 2

Attending Patient ID: 101
Arrival Time: 9:15PM

Enter your choice: 4
Queue is not empty.

Enter your choice: 5
Exiting program.

*/
