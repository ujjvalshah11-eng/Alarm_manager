#include<stdio.h>
#include<time.h>
#include<string.h>
int main(){
    // stores alarm using array
    int id[100];
    int hour[100];
    int minute[100];
    int enabled[100];
    int triggered[100]; // To specify the number of alarm ring
    char label[100][50];
    int choice ;
    // first screen menu
     printf("\n===== ALARM MANAGER =====\n");
        printf("1. Add Alarm\n");
        printf("2. View Alarms\n");
        printf("3. Delete Alarm\n");
        printf("4. Enable Alarm\n");
        printf("5. Disable Alarm\n");
        printf("6. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                // Call addAlarm()
                break;

            case 2:
                // Call viewAlarms()
                break;

            case 3:
                // Call deleteAlarm()
                break;

            case 4:
                // Call enableAlarm()
                break;

            case 5:
                // Call disableAlarm()
                break;

            case 6:
                printf("Exiting Alarm Manager...\n");
                break;

            default:
                printf("Invalid choice!\n");
        }

    
    return 0;
}
