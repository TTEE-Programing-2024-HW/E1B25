#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>

#define ROW 9
#define COL 9

char seats[ROW][COL];

// Function prototypes
void initializeSeats();
void displayMainMenu();
void displaySeats();
void arrangeSeats();
void chooseSeats();
int checkAvailability(int row, int col, int count);
int main() {
    int pass = 2024; // ���T���K�X
    int pw_input;    // �ϥΪ̿�J���K�X
    int attempt = 0; // ���զ���
    int choice;      // �ϥΪ̿��
    const int max_attempts = 3;  // ���\���̤j���զ���
    
    // �өʤƵe���P�K�X��J
  for(int i = 0; i < 20; i++) {
        printf("Hello!\n");
    }
 