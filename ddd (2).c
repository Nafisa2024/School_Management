
#include <stdio.h>

#include <stdlib.h>

#include <string.h>

#define USERNAME "nafisa"

#define PASSWORD "password123"


struct student {

    int id;
    char name[50];
    char className[50];

} s;

struct teacher {

    int id;
    char name[50];
    char subject[50];

} t;

int main() {

    int ch;
    char usernameInput[50];
    char passwordInput[50];


    while (1) {

        system("cls");
        printf("<== School Management System ==>\n");

        printf("Enter your username: ");
        fflush(stdin);
        gets(usernameInput);

        printf("Enter your password: ");
        fflush(stdin);
        gets(passwordInput);

        if (strcmp(usernameInput, USERNAME) == 0 && strcmp(passwordInput, PASSWORD) == 0) {
            printf("Access granted!\n");


    while (1) {

        system("cls");

        printf("<== School Management System ==>\n");
        printf("1. Add Student\n");
        printf("2. Student List\n");
        printf("3. Delete Student\n");
        printf("4. Search Student\n");
        printf("5. Add Teacher\n");
        printf("6. Teacher List\n");
        printf("7. Delete Teacher\n");
        printf("8. Search Teacher\n");
        printf("0. Exit\n\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch (ch) {

            case 0:
                exit(0);

            case 1:
                addStudent();
                break;

            case 2:
                studentList();
                break;

            case 3:
                deleteStudent();
                break;

            case 4:
                searchStudent();
                break;

            case 5:
                addTeacher();
                break;

            case 6:
                teacherList();
                break;

            case 7:
                deleteTeacher();
                break;

            case 8:
                searchTeacher();
                break;

            default:
                printf("Invalid Choice...\n\n");

        }

        printf("Press Any Key To Continue...");
        getch();

    }

}

     else {

            printf("Access denied! Incorrect username or password.\n");
            printf("Press Any Key To Continue...");
            getch();

     }

    }

       return 0;

}



FILE *fp;

void addStudent() {

    fp = fopen("students.txt", "ab");

    printf("Enter student id: ");
    scanf("%d", &s.id);

    printf("Enter student name: ");
    fflush(stdin);
    gets(s.name);

    printf("Enter student class name: ");
    fflush(stdin);
    gets(s.className);

    printf("Student Added Successfully\n");

    fwrite(&s, sizeof(s), 1, fp);
    fclose(fp);

}

void studentList() {

    system("cls");

    printf("<== Student List ==>\n\n");
    printf("%-30s %-20s %-10s\n\n", "Student id", "Name", "Class Name");

    fp = fopen("students.txt", "rb");
    while (fread(&s, sizeof(s), 1, fp) == 1) {

        printf("%-30d %-20s %-10s\n", s.id, s.name, s.className);

    }

    fclose(fp);

}

void deleteStudent() {

    int id, found = 0;
    FILE *ft;

    printf("Enter student id to delete: ");
    scanf("%d", &id);

    fp = fopen("students.txt", "rb");
    ft = fopen("temp.txt", "wb");

    while (fread(&s, sizeof(s), 1, fp) == 1) {

        if (id == s.id) {

            found = 1;

        }

        else {

            fwrite(&s, sizeof(s), 1, ft);

        }

    }

    fclose(fp);
    fclose(ft);

    if (found) {

        printf("Student deleted successfully.\n");
        remove("students.txt");
        rename("temp.txt", "students.txt");

    }

    else {

        printf("Student not found.\n");
        remove("temp.txt");
    }

}

void searchStudent() {

    int id, found = 0;

    printf("Enter student id to search: ");
    scanf("%d", &id);

    fp = fopen("students.txt", "rb");
    while (fread(&s, sizeof(s), 1, fp) == 1) {

        if (id == s.id) {

            found = 1;
            printf("Student Found\n");
            printf("Student id: %d\n", s.id);
            printf("Name: %s\n", s.name);
            printf("Class Name: %s\n", s.className);
            break;

        }
    }

    fclose(fp);

    if (!found) {

        printf("Student not found.\n");

    }
}

void addTeacher() {

    fp = fopen("teachers.txt", "ab");

    printf("Enter teacher id: ");
    scanf("%d", &t.id);

    printf("Enter teacher name: ");
    fflush(stdin);
    gets(t.name);

    printf("Enter teacher subject: ");
    fflush(stdin);
    gets(t.subject);

    printf("Teacher Added Successfully\n");

    fwrite(&t, sizeof(t), 1, fp);
    fclose(fp);

}

void teacherList() {

    system("cls");
    printf("<== Teacher List ==>\n\n");
    printf("%-30s %-20s %-10s\n\n", "Teacher id", "Name", "Subject");

    fp = fopen("teachers.txt", "rb");
    while (fread(&t, sizeof(t), 1, fp) == 1) {

        printf("%-30d %-20s %-10s\n", t.id, t.name, t.subject);

    }

    fclose(fp);
}

void deleteTeacher() {

    int id, found = 0;
    FILE *ft;

    printf("Enter teacher id to delete: ");
    scanf("%d", &id);

    fp = fopen("teachers.txt", "rb");
    ft = fopen("temp.txt", "wb");

    while (fread(&t, sizeof(t), 1, fp) == 1) {

        if (id == t.id) {

            found = 1;
        }

    else {

            fwrite(&t, sizeof(t), 1, ft);
        }
    }

    fclose(fp);
    fclose(ft);

    if (found) {

        printf("Teacher deleted successfully.\n");
        remove("teachers.txt");
        rename("temp.txt", "teachers.txt");

    }
     else {

        printf("Teacher not found.\n");
        remove("temp.txt");
    }

}

void searchTeacher() {

    int id, found = 0;

    printf("Enter teacher id to search: ");
    scanf("%d", &id);

    fp = fopen("teachers.txt", "rb");
    while (fread(&t, sizeof(t), 1, fp) == 1) {

        if (id == t.id) {
            found = 1;
            printf("Teacher Found\n");
            printf("Teacher id: %d\n", t.id);
            printf("Name: %s\n", t.name);
            printf("Subject: %s\n", t.subject);
            break;

        }
    }

    fclose(fp);

    if (!found) {

        printf("Teacher not found.\n");

    }

}

