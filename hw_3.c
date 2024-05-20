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
 