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