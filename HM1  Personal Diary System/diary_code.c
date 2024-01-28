#include <stdio.h>

void createEntry();
void viewEntries();

int main() {
    int choice;

    do {
        printf("\nPersonal Diary System\n");
        printf("1. Create a new diary entry\n");
        printf("2. View all entries\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                createEntry();
                break;
            case 2:
                viewEntries();
                break;
            case 3:
                printf("Exiting the program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }

    } while (choice != 3);

    return 0;
}

void createEntry() {
    FILE *file;
    char date[20], content[500];

    file = fopen("diary_entries.txt", "a");
    if (file == NULL) {
        printf("Error opening the file!\n");
        return;
    }

    printf("Enter the date (MM/DD/YYYY): ");
    scanf("%s", date);

    printf("Enter the content of the diary entry:\n");
    scanf(" %[^\n]s", content);

    fprintf(file, "Date: %s\n%s\n\n", date, content);
    fclose(file);

    printf("Diary entry created successfully!\n");
}

void viewEntries() {
    FILE *file;
    char line[1000];

    file = fopen("diary_entries.txt", "r");
    if (file == NULL) {
        printf("No entries found.\n");
        return;
    }

    printf("\nAll Diary Entries:\n");
    while (fgets(line, sizeof(line), file) != NULL) {
        printf("%s", line);
    }

    fclose(file);
}
