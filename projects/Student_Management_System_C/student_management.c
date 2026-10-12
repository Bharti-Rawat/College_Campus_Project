#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 100

typedef struct {
    int roll_no;
    char name[50];
    char course[50];
    float marks;
} Student;

Student students[MAX_STUDENTS];
int student_count = 0;

void add_student(void) {
    if (student_count >= MAX_STUDENTS) {
        printf("\nStudent limit reached.\n");
        return;
    }

    printf("\nEnter Roll Number: ");
    scanf("%d", &students[student_count].roll_no);
    getchar();

    printf("Enter Student Name: ");
    fgets(students[student_count].name, sizeof(students[student_count].name), stdin);
    students[student_count].name[strcspn(students[student_count].name, "\n")] = '\0';

    printf("Enter Course: ");
    fgets(students[student_count].course, sizeof(students[student_count].course), stdin);
    students[student_count].course[strcspn(students[student_count].course, "\n")] = '\0';

    printf("Enter Marks: ");
    scanf("%f", &students[student_count].marks);

    student_count++;
    printf("\nStudent added successfully!\n");
}

void display_students(void) {
    if (student_count == 0) {
        printf("\nNo student records available.\n");
        return;
    }

    printf("\n================ STUDENT RECORDS ================\n");
    printf("%-10s %-25s %-20s %-10s\n", "Roll No", "Name", "Course", "Marks");
    printf("--------------------------------------------------\n");

    for (int i = 0; i < student_count; i++) {
        printf("%-10d %-25s %-20s %-10.2f\n",
               students[i].roll_no,
               students[i].name,
               students[i].course,
               students[i].marks);
    }
}

void search_student(void) {
    int roll_no;
    int found = 0;

    printf("\nEnter Roll Number to Search: ");
    scanf("%d", &roll_no);

    for (int i = 0; i < student_count; i++) {
        if (students[i].roll_no == roll_no) {
            printf("\nStudent Found!\n");
            printf("Roll Number : %d\n", students[i].roll_no);
            printf("Name        : %s\n", students[i].name);
            printf("Course      : %s\n", students[i].course);
            printf("Marks       : %.2f\n", students[i].marks);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("\nStudent with Roll Number %d was not found.\n", roll_no);
    }
}

void show_menu(void) {
    printf("\n==============================================\n");
    printf("       STUDENT MANAGEMENT SYSTEM\n");
    printf("==============================================\n");
    printf("1. Add Student\n");
    printf("2. Display All Students\n");
    printf("3. Search Student\n");
    printf("4. Exit\n");
    printf("==============================================\n");
}

int main(void) {
    int choice;

    do {
        show_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: add_student(); break;
            case 2: display_students(); break;
            case 3: search_student(); break;
            case 4: printf("\nThank you for using Student Management System!\n"); break;
            default: printf("\nInvalid choice. Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}
