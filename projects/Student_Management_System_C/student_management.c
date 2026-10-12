#include <stdio.h>
#include <string.h>

#define MAX 100

typedef struct {
    int rollNo;
    char name[50];
    char course[50];
    float marks;
} Student;

Student students[MAX];
int count = 0;

void addStudent() {
    if (count >= MAX) {
        printf("Student limit reached.\n");
        return;
    }

    printf("Enter Roll No: ");
    scanf("%d", &students[count].rollNo);
    getchar();

    printf("Enter Name: ");
    fgets(students[count].name, sizeof(students[count].name), stdin);
    students[count].name[strcspn(students[count].name, "\n")] = '\0';

    printf("Enter Course: ");
    fgets(students[count].course, sizeof(students[count].course), stdin);
    students[count].course[strcspn(students[count].course, "\n")] = '\0';

    printf("Enter Marks: ");
    scanf("%f", &students[count].marks);

    count++;
    printf("Student added successfully!\n");
}

void displayStudents() {
    if (count == 0) {
        printf("No student records found.\n");
        return;
    }

    printf("\n--- Student Records ---\n");
    for (int i = 0; i < count; i++) {
        printf("Roll No: %d\n", students[i].rollNo);
        printf("Name: %s\n", students[i].name);
        printf("Course: %s\n", students[i].course);
        printf("Marks: %.2f\n", students[i].marks);
        printf("-----------------------\n");
    }
}

void searchStudent() {
    int roll, found = 0;
    printf("Enter Roll No to search: ");
    scanf("%d", &roll);

    for (int i = 0; i < count; i++) {
        if (students[i].rollNo == roll) {
            printf("\nStudent Found!\n");
            printf("Name: %s\nCourse: %s\nMarks: %.2f\n", students[i].name, students[i].course, students[i].marks);
            found = 1;
            break;
        }
    }

    if (!found) printf("Student not found.\n");
}

int main() {
    int choice;

    do {
        printf("\n===== Student Management System =====\n");
        printf("1. Add Student\n");
        printf("2. Display Students\n");
        printf("3. Search Student\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addStudent(); break;
            case 2: displayStudents(); break;
            case 3: searchStudent(); break;
            case 4: printf("Thank you!\n"); break;
            default: printf("Invalid choice. Try again.\n");
        }
    } while (choice != 4);

    return 0;
}
