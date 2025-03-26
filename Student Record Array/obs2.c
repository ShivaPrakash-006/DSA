#include <stdio.h>
#include <string.h>

typedef struct Student {
  int roll;
  char name[50];
  int age;
  char gender;
  int mark1;
  int mark2;
  int mark3;
  char grade[2];
} Student;

int dispOne(Student *arr, int n, int roll) {
  int found = 0;
  for (int i = 0; i < n; ++i)
    if (arr[i].roll == roll) {
      printf("%i %s %i %c %i %i %i %s\n", arr[i].roll, arr[i].name, arr[i].age,
             arr[i].gender, arr[i].mark1, arr[i].mark2, arr[i].mark3,
             arr[i].grade);
      found = 1;
    }
  return found;
}

void dispAll(Student *arr, int n) {
  for (int i = 0; i < n; ++i)
    printf("%i %s %i %c %i %i %i %s\n", arr[i].roll, arr[i].name, arr[i].age,
           arr[i].gender, arr[i].mark1, arr[i].mark2, arr[i].mark3,
           arr[i].grade);
}

void dispFail(Student *arr, int n) {
  for (int i = 0; i < n; ++i)
    if (strncmp(arr[i].grade, "F", 2) == 0)
      printf("%i %s %i %c %i %i %i %s\n", arr[i].roll, arr[i].name, arr[i].age,
             arr[i].gender, arr[i].mark1, arr[i].mark2, arr[i].mark3,
             arr[i].grade);
}

void dispPass(Student *arr, int n) {
  for (int i = 0; i < n; i++)
    if (strncmp(arr[i].grade, "F", 2) != 0)
      printf("%i %s %i %c %i %i %i %s\n", arr[i].roll, arr[i].name, arr[i].age,
             arr[i].gender, arr[i].mark1, arr[i].mark2, arr[i].mark3,
             arr[i].grade);
}

void insert(Student *arr, int *n) {
  if (*n == 99)
    return;

  Student student;
  printf("Roll No: ");
  scanf("%i", &student.roll);
  getchar();
  if (dispOne(arr, *n, student.roll))
    return;
  printf("Name: ");
  fgets(student.name, 50, stdin);
  student.name[strcspn(student.name, "\n")] = '\0';
  printf("Press Enter to Continue...");
  char c;
  while ((c = getchar()) != '\n' && c != EOF)
    ;
  printf("Age: ");
  scanf("%i", &student.age);
  getchar();
  printf("Gender (M/F): ");
  student.gender = getchar();
  if (student.gender != 'M' && student.gender != 'F')
    return;
  printf("Mark1 (0-100): ");
  scanf("%i", &student.mark1);
  printf("Mark2 (0-100): ");
  scanf("%i", &student.mark2);
  printf("Mark3 (0-100): ");
  scanf("%i", &student.mark3);
  if ((student.mark1 > 100 || student.mark1 < 0) &&
      (student.mark2 > 100 || student.mark2 < 0) &&
      (student.mark3 > 100 || student.mark3 < 0))
    return;

  if (student.mark1 < 50 || student.mark2 < 50 || student.mark3 < 50)
    strcpy(student.grade, "F");
  else {
    float avg = (student.mark1 + student.mark2 + student.mark3) / 3.f;
    if (avg < 50)
      strcpy(student.grade, "F");
    else if (50 <= avg && avg < 60)
      strcpy(student.grade, "B");
    else if (60 <= avg && avg < 70)
      strcpy(student.grade, "B+");
    else if (70 <= avg && avg < 80)
      strcpy(student.grade, "A");
    else if (80 <= avg && avg < 90)
      strcpy(student.grade, "A+");
    else
      strcpy(student.grade, "S");
  }

  for (int i = *n; i >= 0; i--) {
    if (i == 0)
      arr[i] = student;
    else {
      if (arr[i - 1].roll > student.roll)
        arr[i] = arr[i - 1];
      else {
        arr[i] = student;
        break;
      }
    }
  }
  (*n)++;
  dispAll(arr, *n);
}

void delete(Student *arr, int *n) {
  if (*n == 0)
    return;

  int keyRoll, found, pos;
  found = 0;
  printf("Roll No: ");
  scanf("%i", &keyRoll);
  for (int i = 0; i < *n; i++)
    if (arr[i].roll == keyRoll)
      pos = i;
  found = 1;

  if (found)
    for (int i = pos; i < *n; i++)
      arr[i] = arr[i + 1];
  else
    printf("Student Not Found!");
  (*n)--;
  dispAll(arr, *n);
}

int main() {
  Student students[100] = {};
  int n, roll, choice;
  n = 0;
  choice = 0;

  while (choice != 4) {
    printf("1.Display\n2.Insert\n3.Delete\n4.Exit\nEnter Your Choice: ");
    scanf("%i", &choice);

    switch (choice) {
    case 1:
      printf("1.All\n2.One\nEnter Your Choice: ");
      scanf("%i", &choice);

      switch (choice) {
      case 1:
        printf("1.All\n2.Passed\n3.Failed\nEnter Your Choice: ");
        scanf("%i", &choice);

        switch (choice) {
        case 1:
          dispAll(students, n);
          break;
        case 2:
          dispPass(students, n);
          break;
        case 3:
          dispFail(students, n);
          break;
        default:
          printf("Invalid Choice\n");
        }
        break;

      case 2:
        printf("Enter Roll No: ");
        scanf("%i", &roll);
        dispOne(students, n, roll);
        break;

      default:
        printf("Invalid Choice\n");
      }
      break;

    case 2:
      insert(students, &n);
      break;

    case 3:
      delete (students, &n);
      break;

    case 4:
      printf("Bye Bye!\n");
      break;

    default:
      printf("Invalid Input\n");
    }
  }
  return 0;
}
