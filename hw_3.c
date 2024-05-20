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
    int pass = 2024; // 正確的密碼
    int pw_input;    // 使用者輸入的密碼
    int attempt = 0; // 嘗試次數
    int choice;      // 使用者選擇
    const int max_attempts = 3;  // 允許的最大嘗試次數

    // 個性化畫面與密碼輸入
  for(int i = 0; i < 20; i++) {
        printf("Hello!\n");
    }
 
     while (attempt < max_attempts) {
        if (pw_input == pass) { // 正確的密碼
            printf("歡迎！密碼驗證成功。\n");
              // 初始化座位
            initializeSeats();

            // 顯示主選單
            displayMainMenu();

            while (1) { // 主選單迴圈
                printf("請輸入您的選擇 (a, b, c, or d)：");
                choice = getch(); // 隱藏使用者輸入

                switch (choice) {
                    case 'a':
                    case 'A':
                        system("cls");
                        displaySeats();
                        printf("按任意鍵返回主選單。");
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
                        printf("\n繼續？ (y/n)：");
                        exit_choice = getch();
                        if (exit_choice == 'n' || exit_choice == 'N') {
                            printf("\n程式結束。返回作業系統。");
                            return 0;
                        } else if (exit_choice == 'y' || exit_choice == 'Y') {
                            system("cls");
                            displayMainMenu();
                        } else {
                            printf("\n無效輸入！請輸入 y 或 n。\n");
                        }
                        break;
                    default:
                        printf("\n無效選項！\n");
                        break;
                }
            }    
  
        } else { // 錯誤的密碼
            attempt++;
            printf("密碼錯誤！第 %d 次嘗試，共 %d 次。請再試一次。\n", attempt, max_attempts);
            if (attempt == max_attempts) {
                printf("已達到最大嘗試次數。程式退出。\n");
                return 1;
            }
            printf("請輸入密碼：");
            scanf("%d", &pw_input);
        }
    }
    
    return 0;
}

// 隨機初始化座位
void initializeSeats() {
    srand(time(NULL));
    for (int i = 0; i < ROW; ++i) {
        for (int j = 0; j < COL; ++j) {
            seats[i][j] = '-';
        }
    }

    // 隨機設置 10 個已預訂的座位
    for (int i = 0; i < 10; ++i) {
        int row, col;
        do {
            row = rand() % ROW;
            col = rand() % COL;
        } while (seats[row][col] == '*');
        seats[row][col] = '*';
    }
}