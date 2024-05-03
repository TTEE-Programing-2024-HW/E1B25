#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int main()
{
    int password = 2024;
    int input;
    int attempt = 0;
    int choice;
    const int max_attempts = 3;

    for (int i = 1; i < 20; i++)
    {
        printf("Hello\n");
    }
    system("pause");
    system("cls");
}
while (attempt < max_attempts)
{
    printf("請輸入四位數字的密碼：");
    fflush(stdin);
    scanf("%d", &pw_input);

    if (pw_input == pass)
    {
        while (1)
        {
            system("cls");
            printf(" -----------------------------------------\n");
            printf("|            a. 畫出直角三角形            |\n");
            printf("|                                         |\n");
            printf("|             b. 顯示乘法表               |\n");
            printf("|                                         |\n");
            printf("|                c. 結束                  |\n");
            printf(" -----------------------------------------\n");

            printf("輸入A、B、C以繼續，不分大小寫：");
            choice = getch();

             switch (choice)
                {
                    case 'a':
                    case 'A':
                        char character;
                        int height;
                        printf("\n請輸入一個字元（a 到 n）：");
                        fflush(stdin);
                        scanf(" %c", &character);
    
                        if (character < 'a' || character > 'n')
                        {
                            printf("\n錯誤的輸入！請重新輸入。");
                            getch();  
                            fflush(stdin); // 清空輸入緩衝區
                            break;
                        }
                        else
                        {
                            system("cls");
                            height = character - 'a' + 1;  
                        }
                        for (int row = 1; row <= height; row++)
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
                        break;
                }
        }
    }