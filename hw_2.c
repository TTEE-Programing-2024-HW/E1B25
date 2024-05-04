#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int main()
{
    int pass = 2024; // 宣告正確的密碼
    int pw_input;    // 用戶輸入的密碼
    int attempt = 0; // 嘗試次數
    int choice;      // 用戶選擇
    const int max_attempts = 3;  // 最大嘗試次數

   
    for(int i=0;i<20;i++) // 個人化設計
    {
         printf("Hello\n");
    }
    system("pause"); // 暫停程式的執行，等待用戶按下任意鍵繼續
    system("cls");   // 清空控制台的輸出
   
    while (attempt < max_attempts) // 輸入密碼的迴圈
    {
        printf("請輸入四位數字的密碼：");
        fflush(stdin); // 清空輸入緩衝區，
        scanf("%d", &pw_input); // 用戶輸入的密碼
        
        if (pw_input == pass) // 如果用戶輸入的密碼正確
        {
            while (1) // 進入功能選擇的無限迴圈
            {
                system("cls"); // 清空控制台的輸出
                printf(" -----------------------------------------\n"); //印出表格 
                printf("|            a. 畫出直角三角形            |\n");
                printf("|                                         |\n");
                printf("|             b. 顯示乘法表               |\n");
                printf("|                                         |\n");
                printf("|                c. 結束                  |\n");
                printf(" -----------------------------------------\n");
                
                printf("輸入A、B、C以繼續，不分大小寫：");
                choice = getch(); // 讀取用戶的選擇，並隱藏輸入的字符

                switch (choice) // 根據用戶的選擇執行相應的功能
                {
                    case 'a':
                    case 'A':
                        char character;
                        int height;
                        printf("\n請輸入一個字元（a 到 n）："); // 印出請輸入一個字元（a 到 n）：
                        fflush(stdin); // 清空輸入緩衝區
                        scanf(" %c", &character); // 讀取用戶輸入的字符
    
                        if (character < 'a' || character > 'n')
                        {
                            printf("\n錯誤的輸入！請重新輸入。");
                            getch();  
                            fflush(stdin); // 清空輸入緩衝區
                            break; // 跳脫迴圈
                        }
                        else
                        {
                            system("cls");  // 清空控制台的輸出
                            height = character - 'a' + 1;  
                        }
                        for (int row = 1; row <= height; row++) //利用for迴圈印出直角三角形
                        {
                            for (int space = 1; space <= height - row; space++)
                            {
                                printf(" ");
                            }
                            for (char col = character - row + 1; col <= character; col++)
                            {
                                printf("%c", col);
                            }
                            printf("\n");
                        }
    
                        getch();  
                        break; // 跳脫迴圈
                        
                    case 'b':
                    case 'B':
                        int num;
    
                        printf("\n請輸入一個整數（1至9）：");//印出請輸入一個整數（1至9）：
                        fflush(stdin);// 清空輸入緩衝區
                        if (scanf("%d", &num) != 1 || num < 1 || num > 9)
                        {
                            printf("\n錯誤的輸入！請輸入1至9之間的整數。"); //印出錯誤的輸入！請輸入1至9之間的整數。
                            getch();  
                            fflush(stdin); // 清空輸入緩衝區
                            break; // 跳脫迴圈
                        }
    
                        system("cls");  // 清空控制台的輸出
                        for (int i = 1; i <= num; i++)
                        {
                            for (int j = 1; j <= num; j++)
                            {
                                printf("%d＊%d＝%2d  ", j, i, i * j); // 印出乘法表
                            }
                            printf("\n");
                        }
    
                        getch();  
                        break; // 跳脫迴圈
                        
                    case 'c':
                    case 'C':
                        char exit_choice;
    
                        printf("\nContinue？（y/n）"); // 印出Continue？（y/n）
                        exit_choice = getch();
    
                        if (exit_choice == 'y' || exit_choice == 'Y')
                        {
                            break; // 跳脫迴圈
                        }
                        else if (exit_choice == 'n' || exit_choice == 'N')
                        {
                            printf("\n程式結束，返回作業系統。"); //印出程式結束，返回作業系統。
                            return 0; // 程式結束
                        }
                        else
                        {
                            printf("\n錯誤的輸入！請輸入 y 或 n，重新輸入。"); // 印出錯誤的輸入！請輸入 y 或 n，重新輸入。
                            getch();
                            fflush(stdin); // 清空輸入緩衝區
                        }
                        break; // 跳脫迴圈
                        
                    default:
                        printf("\n無效的選項！"); // 印出無效的選項！
                        getch();
                        fflush(stdin); // 清空輸入緩衝區
                        break; // 跳脫迴圈
                }
            }
        }
        else // 如果用戶輸入的密碼錯誤
        {
            attempt++; // 嘗試次數加一
            printf("\n密碼錯誤！這是第 %d 次嘗試，還剩 %d 次機會。\n", attempt, max_attempts - attempt); // 印出錯誤次數，印出剩餘嘗試次數
            
            if (attempt == max_attempts) // 如果嘗試次數達到上限
            {
                printf("\n密碼錯誤次數已達上限，程式即將結束。"); // 印出密碼錯誤次數已達上限，程式即將結束。
                
                return 1; // 程式返回非零值，表示出現錯誤
            }
        }
    }
    
    return 0; // 程式結束
}