#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PASSWORD "2024"       // 定義正確的密碼
#define MAX_STUDENTS 10       // 最大學生數量
#define MIN_STUDENTS 5        // 最小學生數量

// 定義結構以存儲學生信息
typedef struct {
    char name[50];           // 學生姓名
    int student_id;          // 學生學號
    int math;                // 數學成績
    int physics;             // 物理成績
    int english;             // 英文成績
    float average;           // 平均成績
} Student;

// 函數清除屏幕，依平台不同
void clear_screen() {
    #ifdef _WIN32
        system("cls");       // Windows 清屏命令
    #else
        system("clear");     // Unix 清屏命令
    #endif
}

// 函數顯示歡迎畫面並驗證密碼
void welcome_screen() {
    int attempts = 0;       // 初始化嘗試次數
    char input[5];          // 用於存儲用戶輸入的數組
    
    for(int i=0;i<=20;i++)
 	{
 		printf("Hello\n");
	}
	system("PAUSE");
	fflush (stdin);
    // 循環允許最多3次密碼嘗試
    while (attempts < 3) {
        clear_screen();
        printf("**************************************\n");
        printf("* 歡迎使用學生成績管理系統 *\n");
        printf("**************************************\n");
        printf("請輸入4位數字密碼: ");
        scanf("%4s", input); // 讀取用戶輸入

        // 檢查輸入的密碼是否正確
        if (strcmp(input, PASSWORD) == 0) {
            printf("密碼正確！歡迎！\n");
            getchar(); // 清除輸入緩衝區
            return;
        } else {
            printf("密碼錯誤。請重試。\n");
            attempts++; // 增加嘗試次數
        }
    }

    // 如果嘗試次數過多，退出程序
    printf("嘗試次數過多。程序將退出。\n");
    exit(1);
}