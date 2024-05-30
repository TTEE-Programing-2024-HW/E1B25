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
// 函數顯示主選單
void display_menu() {
    printf("------------[成績管理系統]----------\n");
    printf("|  a. 輸入學生成績         |\n");
    printf("|  b. 顯示學生成績         |\n");
    printf("|  c. 搜索學生成績         |\n");
    printf("|  d. 成績排名             |\n");
    printf("|  e. 退出系統             |\n");
    printf("------------------------------------\n");
}

// 函數輸入學生成績
void enter_student_grades(Student students[], int *student_count) {
    int n;

    clear_screen();
    printf("輸入學生數量 (5-10): ");
    
    // 驗證學生數量
    while (scanf("%d", &n) != 1 || n < MIN_STUDENTS || n > MAX_STUDENTS) {
        printf("輸入無效。請輸入5到10之間的數字: ");
        while (getchar() != '\n'); // 清除輸入緩衝區
    }

    // 循環輸入每個學生的詳細信息
    for (int i = 0; i < n; i++) {
        printf("輸入第 %d 個學生姓名: ", i + 1);
        scanf("%s", students[i].name);

        printf("輸入第 %d 個學生學號 (6位數字): ", i + 1);
        // 驗證學生學號
        while (scanf("%d", &students[i].student_id) != 1 || students[i].student_id < 100000 || students[i].student_id > 999999) {
            printf("學號無效。請輸入6位數字: ");
            while (getchar() != '\n'); // 清除輸入緩衝區
        }

        printf("輸入數學成績 (0-100): ");
        // 驗證數學成績
        while (scanf("%d", &students[i].math) != 1 || students[i].math < 0 || students[i].math > 100) {
            printf("成績無效。請輸入0到100之間的數字: ");
            while (getchar() != '\n'); // 清除輸入緩衝區
        }

        printf("輸入物理成績 (0-100): ");
        // 驗證物理成績
        while (scanf("%d", &students[i].physics) != 1 || students[i].physics < 0 || students[i].physics > 100) {
            printf("成績無效。請輸入0到100之間的數字: ");
            while (getchar() != '\n'); // 清除輸入緩衝區
        }

        printf("輸入英文成績 (0-100): ");
        // 驗證英文成績
        while (scanf("%d", &students[i].english) != 1 || students[i].english < 0 || students[i].english > 100) {
            printf("成績無效。請輸入0到100之間的數字: ");
            while (getchar() != '\n'); // 清除輸入緩衝區
        }

        // 計算平均成績
        students[i].average = (students[i].math + students[i].physics + students[i].english) / 3.0;
    }

    *student_count = n; // 更新學生數量
}