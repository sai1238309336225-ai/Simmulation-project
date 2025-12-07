#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

struct Student {
    int roll;
    char name[50];
    char status[10];
};

int main() {
    struct Student s[MAX];
    int n = 0, choice, found, i;
    FILE *fp;
    char filename[] = "attendance.txt";
    fp = fopen(filename, "r");
    if (fp != NULL) {
        while (fscanf(fp, "%d %s %s", &s[n].roll, s[n].name, s[n].status) != EOF)
            n++;
        fclose(fp);
    }

    while (1) {
        printf("\n--- Attendance Portal ---\n");
        printf("1. Add Student\n");
        printf("2. Mark Attendance\n");
        printf("3. View Attendance\n");
        printf("4. Save & Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("Enter Roll No: ");
            scanf("%d", &s[n].roll);
            printf("Enter Name: ");
            scanf("%s", s[n].name);
            strcpy(s[n].status, "Absent");
            n++;
        } 
        else if (choice == 2) {
            int roll;
            found = 0;
            printf("Enter Roll No to mark Present: ");
            scanf("%d", &roll);
            for (i = 0; i < n; i++) {
                if (s[i].roll == roll) {
                    strcpy(s[i].status, "Present");
                    found = 1;
                    break;
                }
            }
            if (!found) printf("Student not found.\n");
        } 
        else if (choice == 3) {
            printf("\nRoll\tName\tStatus\n");
            for (i = 0; i < n; i++)
                printf("%d\t%s\t%s\n", s[i].roll, s[i].name, s[i].status);
        } 
        else if (choice == 4) {
            fp = fopen(filename, "w");
            for (i = 0; i < n; i++)
                fprintf(fp, "%d %s %s\n", s[i].roll, s[i].name, s[i].status);
            fclose(fp);
            printf("Data saved. Exiting...\n");
            break;
        } 
        else {
            printf("Invalid choice.\n");
        }
    }
    return 0;
}
