#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PASSWORD "2024"       // Define the correct password
#define MAX_STUDENTS 10       // Maximum number of students
#define MIN_STUDENTS 5        // Minimum number of students

// Define a structure to store student information
typedef struct {
    char name[50];           // Student's name
    int student_id;          // Student's ID
    int math;                // Math grade
    int physics;             // Physics grade
    int english;             // English grade
    float average;           // Average grade
} Student;