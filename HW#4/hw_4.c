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