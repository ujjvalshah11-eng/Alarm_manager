#include<stdio.h>
#include<time.h>
#include<string.h>
void addAlarm(int id[],int hour[],int minute[],char label[][50],int* count){
    id[*count] = *count + 1;
    printf("Enter the hour in 24 hr format : ");
    scanf("%d",&hour[*count]);
    printf("Enter the minutes : ");
    scanf("%d",&minute[*count]);
    printf("Enter the label : ");
    scanf(" %[^\n]", label[*count]); 
    printf("\nAlarm ID: %d", id[*count]);
    printf("\nAlarm set for %02d : %02d  ",hour[*count],minute[*count]);// we use %02d so that it filled zero when empty or single digit
    printf("\nlabel : %s",label[*count]);
    (*count)++;
    return;
}
int main(){
     // stores alarm using array
    int id[100];
    int hour[100];
    int minute[100];
    int enabled[100];
    int triggered[100]; // To specify the number of alarm ring
    char label[100][50];
    int count = 0;
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
                addAlarm(id,hour,minute,label,&count);
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
