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
                        case 'd':
                    case 'D':
                        char exit_choice;
                        printf("\n�~��H (y/n)�G");
                        exit_choice = getch();
                        if (exit_choice == 'n' || exit_choice == 'N') {
                            printf("\n�{�������C��^�@�~�t�ΡC");
                            return 0;
                        } else if (exit_choice == 'y' || exit_choice == 'Y') {
                            system("cls");
                            displayMainMenu();
                        } else {
                            printf("\n�L�Ŀ�J�I�п�J y �� n�C\n");
                        }
                        break;
                    default:
                        printf("\n�L�Ŀﶵ�I\n");
                        break;
                }
            }    
  
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

// �H����l�Ʈy��
void initializeSeats() {
    srand(time(NULL));
    for (int i = 0; i < ROW; ++i) {
        for (int j = 0; j < COL; ++j) {
            seats[i][j] = '-';
        }
    }

    // �H���]�m 10 �Ӥw�w�q���y��
    for (int i = 0; i < 10; ++i) {
        int row, col;
        do {
            row = rand() % ROW;
            col = rand() % COL;
        } while (seats[row][col] == '*');
        seats[row][col] = '*';
    }
}

// ��ܥD���
void displayMainMenu() {
    system("cls");
    printf("----------[�w�q�t��]----------\n");
    printf("|  a. �i�ήy��                |\n");
    printf("|  b. �w�Ʈy��                |\n");
    printf("|  c. �ۿ�y��                |\n");
    printf("|  d. �h�X                    |\n");
    printf("----------------------------------\n");
}
// ��ܮy��
void displaySeats() {
    printf("  123456789\n");
    for (int i = 0; i < ROW; ++i) {
        printf("%d ", i + 1);
        for (int j = 0; j < COL; ++j) {
            printf("%c", seats[i][j]);
        }
        printf("\n");
    }
}

// �w�Ʈy��
void arrangeSeats() {
    int numSeats;
    printf("�п�J�һݮy��ơ]1-4�^�G");
    scanf("%d", &numSeats);
    if (numSeats < 1 || numSeats > 4) {
        printf("�L�Ŀ�J�I\n");
        return;
    }

    int row, col;
    int found = 0;
    int attempts = 0; // �l�ܹ��զ���
    while (!found && attempts < 100) { // ������զ��ƥH�קK�L���j��
        row = rand() % ROW;
        col = rand() % (COL - numSeats + 1); // �ץ��H�T�O���T�d��
        if (checkAvailability(row, col, numSeats)) {
            found = 1;
            break;
        }
        attempts++;
    }

    if (!found) {
        printf("�䤣�� %d �H�s��y��C\n", numSeats);
        return;
    }

    for (int i = 0; i < numSeats; ++i)
        seats[row][col + i] = '@';
    displaySeats();

    char choice;
    printf("�z�惡�w�ƺ��N�ܡH�]y/n�^�G");
    scanf(" %c", &choice);
    if (choice != 'y') {
        for (int i = 0; i < numSeats; ++i)
            seats[row][col + i] = '-';
        return;
    }
}

// ��ܮy��
void chooseSeats() {
    int row, col;
    printf("�п�J�渹�]1-9�^�G");
    scanf("%d", &row);
    printf("�п�J�C���]1-9�^�G");
    scanf("%d", &col);
    row--; // �վ㬰�}�C����
    col--; // �վ㬰�}�C����
    printf("Debug: row=%d, col=%d\n", row + 1, col + 1); // �����y�y
    if (row < 0 || row >= ROW || col < 0 || col >= COL) {
        printf("�L�Įy���ܡI\n");
        return;
    }
    if (seats[row][col] == '*') {
        printf("�Ӯy��w�w�q�I\n");
        return;
    }
    seats[row][col] = '@';
    printf("�y��w�q���\�I\n");
    displaySeats();
}

// �ˬd�y��O�_�i��
int checkAvailability(int row, int col, int count) {
    if (row < 0 || row >= ROW || col < 0 || col + count > COL) // �վ����
        return 0;
    for (int i = 0; i < count; ++i) {
        if (seats[row][col + i] == '*')
            return 0;
    }
    return 1;
}
//�o�����Ʀ�t�Χ�ı�o�ܦ���A���M�{���X�g�_�ӫ���,���bChatgpt�����U�U,�ڲש��\�వ�X�ӤF
