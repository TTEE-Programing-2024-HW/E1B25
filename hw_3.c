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
 
     while (attempt < max_attempts) {
        if (pw_input == pass) { // ���T���K�X
            printf("�w��I�K�X���Ҧ��\�C\n");
              // ��l�Ʈy��
            initializeSeats();

            // ��ܥD���
            displayMainMenu();

            while (1) { // �D���j��
                printf("�п�J�z����� (a, b, c, or d)�G");
                choice = getch(); // ���èϥΪ̿�J

                switch (choice) {
                    case 'a':
                    case 'A':
                        system("cls");
                        displaySeats();
                        printf("�����N���^�D���C");
                        getch();
                        displayMainMenu();
                        break;
                    case 'b':
                    case 'B':
                        system("cls");
                        arrangeSeats();
                        displayMainMenu();
                        break;
                    case 'c':
                    case 'C':
                        system("cls");
                        chooseSeats();
                        displayMainMenu();
                        break;

            

           
                
        } else { // ���~���K�X
            attempt++;
            printf("�K�X���~�I�� %d �����աA�@ %d ���C�ЦA�դ@���C\n", attempt, max_attempts);
            if (attempt == max_attempts) {
                printf("�w�F��̤j���զ��ơC�{���h�X�C\n");
                return 1;
            }
            printf("�п�J�K�X�G");
            scanf("%d", &pw_input);
        }
    }
    
    return 0;
}