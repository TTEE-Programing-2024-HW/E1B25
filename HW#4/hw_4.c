#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PASSWORD "2024"       // �w�q���T���K�X
#define MAX_STUDENTS 10       // �̤j�ǥͼƶq
#define MIN_STUDENTS 5        // �̤p�ǥͼƶq

// �w�q���c�H�s�x�ǥͫH��
typedef struct {
    char name[50];           // �ǥͩm�W
    int student_id;          // �ǥ;Ǹ�
    int math;                // �ƾǦ��Z
    int physics;             // ���z���Z
    int english;             // �^�妨�Z
    float average;           // �������Z
} Student;

// ��ƲM���̹��A�̥��x���P
void clear_screen() {
    #ifdef _WIN32
        system("cls");       // Windows �M�̩R�O
    #else
        system("clear");     // Unix �M�̩R�O
    #endif
}

// �������w��e�������ұK�X
void welcome_screen() {
    int attempts = 0;       // ��l�ƹ��զ���
    char input[5];          // �Ω�s�x�Τ��J���Ʋ�
    
    for(int i=0;i<=20;i++)
 	{
 		printf("Hello\n");
	}
	system("PAUSE");
	fflush (stdin);
    // �`�����\�̦h3���K�X����
    while (attempts < 3) {
        clear_screen();
        printf("**************************************\n");
        printf("* �w��ϥξǥͦ��Z�޲z�t�� *\n");
        printf("**************************************\n");
        printf("�п�J4��Ʀr�K�X: ");
        scanf("%4s", input); // Ū���Τ��J

        // �ˬd��J���K�X�O�_���T
        if (strcmp(input, PASSWORD) == 0) {
            printf("�K�X���T�I�w��I\n");
            getchar(); // �M����J�w�İ�
            return;
        } else {
            printf("�K�X���~�C�Э��աC\n");
            attempts++; // �W�[���զ���
        }
    }

    // �p�G���զ��ƹL�h�A�h�X�{��
    printf("���զ��ƹL�h�C�{�ǱN�h�X�C\n");
    exit(1);
}
// �����ܥD���
void display_menu() {
    printf("------------[���Z�޲z�t��]----------\n");
    printf("|  a. ��J�ǥͦ��Z         |\n");
    printf("|  b. ��ܾǥͦ��Z         |\n");
    printf("|  c. �j���ǥͦ��Z         |\n");
    printf("|  d. ���Z�ƦW             |\n");
    printf("|  e. �h�X�t��             |\n");
    printf("------------------------------------\n");
}

// ��ƿ�J�ǥͦ��Z
void enter_student_grades(Student students[], int *student_count) {
    int n;

    clear_screen();
    printf("��J�ǥͼƶq (5-10): ");
    
    // ���Ҿǥͼƶq
    while (scanf("%d", &n) != 1 || n < MIN_STUDENTS || n > MAX_STUDENTS) {
        printf("��J�L�ġC�п�J5��10�������Ʀr: ");
        while (getchar() != '\n'); // �M����J�w�İ�
    }

    // �`����J�C�Ӿǥͪ��ԲӫH��
    for (int i = 0; i < n; i++) {
        printf("��J�� %d �Ӿǥͩm�W: ", i + 1);
        scanf("%s", students[i].name);

        printf("��J�� %d �Ӿǥ;Ǹ� (6��Ʀr): ", i + 1);
        // ���Ҿǥ;Ǹ�
        while (scanf("%d", &students[i].student_id) != 1 || students[i].student_id < 100000 || students[i].student_id > 999999) {
            printf("�Ǹ��L�ġC�п�J6��Ʀr: ");
            while (getchar() != '\n'); // �M����J�w�İ�
        }

        printf("��J�ƾǦ��Z (0-100): ");
        // ���ҼƾǦ��Z
        while (scanf("%d", &students[i].math) != 1 || students[i].math < 0 || students[i].math > 100) {
            printf("���Z�L�ġC�п�J0��100�������Ʀr: ");
            while (getchar() != '\n'); // �M����J�w�İ�
        }

        printf("��J���z���Z (0-100): ");
        // ���Ҫ��z���Z
        while (scanf("%d", &students[i].physics) != 1 || students[i].physics < 0 || students[i].physics > 100) {
            printf("���Z�L�ġC�п�J0��100�������Ʀr: ");
            while (getchar() != '\n'); // �M����J�w�İ�
        }

        printf("��J�^�妨�Z (0-100): ");
        // ���ҭ^�妨�Z
        while (scanf("%d", &students[i].english) != 1 || students[i].english < 0 || students[i].english > 100) {
            printf("���Z�L�ġC�п�J0��100�������Ʀr: ");
            while (getchar() != '\n'); // �M����J�w�İ�
        }

        // �p�⥭�����Z
        students[i].average = (students[i].math + students[i].physics + students[i].english) / 3.0;
    }

    *student_count = n; // ��s�ǥͼƶq
}