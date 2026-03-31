#include <stdio.h>

#define MAX_STUDENTS 5

typedef struct {
    int rollno;
    char name[50];
    int age;
} Student;

void inputStudents(Student students[], int n);
void displayStudentsAboveAge(Student students[], int n, int minAge);

int main() {
    Student students[MAX_STUDENTS];
    int totalStudents;

    printf("Enter total number of students: ");
    scanf("%d", &totalStudents);

    if (totalStudents > MAX_STUDENTS) {
        printf("Maximum %d students allowed!\n", MAX_STUDENTS);
        totalStudents = MAX_STUDENTS;
    }

    inputStudents(students, totalStudents);

    printf("\nStudents with age >= 20:\n");
    displayStudentsAboveAge(students, totalStudents, 20);

    return 0;
}

void inputStudents(Student students[], int n) {
    for (int i = 0; i < n; i++) {
        printf("\nStudent %d:\n", i + 1);
        printf("Roll no: ");
        scanf("%d", &students[i].rollno);
        printf("Name: ");
        scanf(" %[^\n]", students[i].name);
        printf("Age: ");
        scanf("%d", &students[i].age);
    }
}

void displayStudentsAboveAge(Student students[], int n, int minAge) {
    int found = 0;

    for (int i = 0; i < n; i++) {
        if (students[i].age >= minAge) {
            printf("\nRoll no: %d\n", students[i].rollno);
            printf("Name: %s\n", students[i].name);
            printf("Age: %d\n", students[i].age);
            found = 1;
        }
    }

    if (!found)
        printf("No students found with age >= %d\n", minAge);
}
