#include<time.h>
#include <stdio.h>
#include <string.h>

void addAlarm(int id[], int hour[], int minute[],
              char label[][50], int *count, int enabled[])
{
    int choice;

    do {
        if (*count >= 100) {
            printf("Alarm limit reached!\n");
            return;
        }

        id[*count] = *count + 1;

        printf("Enter the hour in 24 hr format: ");
        scanf("%d", &hour[*count]);

        printf("Enter the minutes: ");
        scanf("%d", &minute[*count]);

        printf("Enter the label: ");
        scanf(" %49[^\n]", label[*count]);

        printf("\nChoose alarm status:\n");
        printf("1. Enabled\n");
        printf("0. Disabled\n");
        printf("Enter your choice: ");
        scanf("%d", &enabled[*count]);

        printf("\nAlarm ID: %d", id[*count]);
        printf("\nTime: %02d:%02d", hour[*count], minute[*count]);
        printf("\nLabel: %s", label[*count]);

        if (enabled[*count] == 1)
            printf("\nStatus: Enabled\n");
        else
            printf("\nStatus: Disabled\n");

        (*count)++;

        printf("\nAdd another alarm?\n");
        printf("1. Yes\n");
        printf("0. No (Main Menu)\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

    } while (choice == 1);
}

void viewAlarms(int id[], int hour[], int minute[],
                char label[][50], int count, int enabled[],int choice)
{
    if (count == 0) {
        printf("No alarms\n");
    }
    else {
        for (int i = 0; i < count; i++) {
            printf("\nID: %d", id[i]);
            printf("\nTime: %02d:%02d", hour[i], minute[i]);
            printf("\nLabel: %s", label[i]);

            if (enabled[i] == 1)
                printf("\nStatus: Enabled\n");
            else
                printf("\nStatus: Disabled\n");
       
                
        }
    }
     printf("Press 1 for main menu : \n");
        scanf("%d", &choice);
}

void deleteAlarm(int id[], int hour[], int minute[],
                 char label[][50], int *count, int enabled[],int choice)
{
    int searchid;
    int pos = -1;

    if(*count == 0)
    {
        printf("No alarms to delete!\n");
        return;
    }

    printf("Enter Alarm ID to delete: ");
    scanf("%d", &searchid);

    for(int i = 0; i < *count; i++)
    {
        if(id[i] == searchid)
        {
            pos = i;
            break;
        }
    }

    if(pos == -1)
    {
        printf("Alarm not found!\n");
        return;
    }

    for(int i = pos; i < *count - 1; i++)
    {
        id[i] = id[i+1];
        hour[i] = hour[i+1];
        minute[i] = minute[i+1];
        enabled[i] = enabled[i+1];
        strcpy(label[i], label[i+1]); // it will copy the string
    }

    (*count)--;

    printf("Alarm deleted successfully!\n");
    printf("Press 1 for main menu : \n");
    scanf("%d", &choice);
}

int main()
{
    int id[100];
    int hour[100];
    int minute[100];
    int enabled[100];
    int triggered[100];
    char label[100][50];

    int count = 0;
    int choice;

    while (1) {
        printf("\n===== ALARM MANAGER =====\n");
        printf("1. Add Alarm\n");
        printf("2. View Alarms\n");
        printf("3. Delete Alarm\n");
        printf("4. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addAlarm(id, hour, minute, label, &count, enabled);
                break;

            case 2:
                viewAlarms(id, hour, minute, label, count, enabled,choice);
                break;

            case 3:
              deleteAlarm(id, hour, minute, label, &count, enabled,choice);
                break;

            case 4:
                printf("Exiting Alarm Manager...\n");
                return 0;

            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}
