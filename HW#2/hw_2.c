#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int main()
{
    int pass = 2024; // �ŧi���T���K�X
    int pw_input;    // �Τ��J���K�X
    int attempt = 0; // ���զ���
    int choice;      // �Τ���
    const int max_attempts = 3;  // �̤j���զ���

   
    for(int i=0;i<20;i++) // �ӤH�Ƴ]�p
    {
         printf("Hello\n");
    }
    system("pause"); // �Ȱ��{��������A���ݥΤ���U���N���~��
    system("cls");   // �M�ű���x����X
   
    while (attempt < max_attempts) // ��J�K�X���j��
    {
        printf("�п�J�|��Ʀr���K�X�G");
        fflush(stdin); // �M�ſ�J�w�İϡA
        scanf("%d", &pw_input); // �Τ��J���K�X
        
        if (pw_input == pass) // �p�G�Τ��J���K�X���T
        {
            while (1) // �i�J�\���ܪ��L���j��
            {
                system("cls"); // �M�ű���x����X
                printf(" -----------------------------------------\n"); //�L�X��� 
                printf("|            a. �e�X�����T����            |\n");
                printf("|                                         |\n");
                printf("|             b. ��ܭ��k��               |\n");
                printf("|                                         |\n");
                printf("|                c. ����                  |\n");
                printf(" -----------------------------------------\n");
                
                printf("��JA�BB�BC�H�~��A�����j�p�g�G");
                choice = getch(); // Ū���Τ᪺��ܡA�����ÿ�J���r��

                switch (choice) // �ھڥΤ᪺��ܰ���������\��
                {
                    case 'a':
                    case 'A':
                        char character;
                        int height;
                        printf("\n�п�J�@�Ӧr���]a �� n�^�G"); // �L�X�п�J�@�Ӧr���]a �� n�^�G
                        fflush(stdin); // �M�ſ�J�w�İ�
                        scanf(" %c", &character); // Ū���Τ��J���r��
    
                        if (character < 'a' || character > 'n')
                        {
                            printf("\n���~����J�I�Э��s��J�C");
                            getch();  
                            fflush(stdin); // �M�ſ�J�w�İ�
                            break; // ����j��
                        }
                        else
                        {
                            system("cls");  // �M�ű���x����X
                            height = character - 'a' + 1;  
                        }
                        for (int row = 1; row <= height; row++) //�Q��for�j��L�X�����T����
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
                        break; // ����j��
                        
                    case 'b':
                    case 'B':
                        int num;
    
                        printf("\n�п�J�@�Ӿ�ơ]1��9�^�G");//�L�X�п�J�@�Ӿ�ơ]1��9�^�G
                        fflush(stdin);// �M�ſ�J�w�İ�
                        if (scanf("%d", &num) != 1 || num < 1 || num > 9)
                        {
                            printf("\n���~����J�I�п�J1��9��������ơC"); //�L�X���~����J�I�п�J1��9��������ơC
                            getch();  
                            fflush(stdin); // �M�ſ�J�w�İ�
                            break; // ����j��
                        }
    
                        system("cls");  // �M�ű���x����X
                        for (int i = 1; i <= num; i++)
                        {
                            for (int j = 1; j <= num; j++)
                            {
                                printf("%d��%d��%2d  ", j, i, i * j); // �L�X���k��
                            }
                            printf("\n");
                        }
    
                        getch();  
                        break; // ����j��
                        
                    case 'c':
                    case 'C':
                        char exit_choice;
    
                        printf("\nContinue�H�]y/n�^"); // �L�XContinue�H�]y/n�^
                        exit_choice = getch();
    
                        if (exit_choice == 'y' || exit_choice == 'Y')
                        {
                            break; // ����j��
                        }
                        else if (exit_choice == 'n' || exit_choice == 'N')
                        {
                            printf("\n�{�������A��^�@�~�t�ΡC"); //�L�X�{�������A��^�@�~�t�ΡC
                            return 0; // �{������
                        }
                        else
                        {
                            printf("\n���~����J�I�п�J y �� n�A���s��J�C"); // �L�X���~����J�I�п�J y �� n�A���s��J�C
                            getch();
                            fflush(stdin); // �M�ſ�J�w�İ�
                        }
                        break; // ����j��
                        
                    default:
                        printf("\n�L�Ī��ﶵ�I"); // �L�X�L�Ī��ﶵ�I
                        getch();
                        fflush(stdin); // �M�ſ�J�w�İ�
                        break; // ����j��
                }
            }
        }
        else // �p�G�Τ��J���K�X���~
        {
            attempt++; // ���զ��ƥ[�@
            printf("\n�K�X���~�I�o�O�� %d �����աA�ٳ� %d �����|�C\n", attempt, max_attempts - attempt); // �L�X���~���ơA�L�X�Ѿl���զ���
            
            if (attempt == max_attempts) // �p�G���զ��ƹF��W��
            {
                printf("\n�K�X���~���Ƥw�F�W���A�{���Y�N�����C"); // �L�X�K�X���~���Ƥw�F�W���A�{���Y�N�����C
                
                return 1; // �{����^�D�s�ȡA��ܥX�{���~
            }
        }
    }
    
    return 0; // �{������
}

//�߱o:�b�o�����@�~���A�ڳo���Q�ΤFchatgpt�����U�ګ�ҳo�����{���X�c�[�A�b�o���@�~����ı�o�������O�p��h�L�X�^��r�����T���ΡA���M�o�ӬO�Q��
//���������e�ҾǪ��h��for�j��U�h������C�L�A�ѩ�o�ӬO�ڤ����m���F��A�]���ڷQ���ӥX�ӫ�򰵡A�Ʊ���ǥѧ�o�����{���X�d���A�����ڪ��Q�k
//���F��