#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include "menu.h"
#include "levoria.h"
#include "time.h" // ��� �������� ��������� �������

void menu_loop() {
    int menu_position = 1;
    int key = 0;

    while (1) {
        system("cls");
        printf("�������� ����� ����:\n");

        if (menu_position == 1) {
            printf("--> 1. ������ ���� <--\n");
        }
        else {
            printf("    1. ������ ����\n");
        }

        if (menu_position == 2) {
            printf("--> 2. ������� log.txt <--\n");
        }
        else {
            printf("    2. ������� log.txt\n");
        }

        if (menu_position == 3) {
            printf("--> 3. ������� ����� ������ ��������� <--\n");
        }
        else {
            printf("    3. ������� ����� ������ ���������\n");
        }

        if (menu_position == 4) {
            printf("--> 4. ����� <--\n");
        }
        else {
            printf("    4. �����\n");
        }

        key = _getch();
        if (key == 80) {
            menu_position++;
            if (menu_position > 4) menu_position = 1;
        }
        else if (key == 72) {
            menu_position--;
            if (menu_position < 1) menu_position = 4;
        }
        else if (key == 13) {
            system("cls");

            if (menu_position == 1) {
                int day = 0, month = 0, year = 0;
                int sum = 0, arcana = 0;
                int success = 0;

                FILE* log;
                FILE* info;
                fopen_s(&log, "log.txt", "a+");
                fopen_s(&info, "info.txt", "r");

                // ���� ����
                while (success != 1 || day < 1 || day > 31) {
                    printf("������� ���� �������� (����� �� 1 �� 31): ");
                    success = scanf_s("%d", &day);
                    if (success != 1 || day < 1 || day > 31) {
                        printf("������: ������� ���������� ����.\n\n");
                        while (getchar() != '\n');
                    }
                }
                success = 0;
                while (success != 1 || month < 1 || month > 12) {
                    printf("������� ����� �������� (����� �� 1 �� 12): ");
                    success = scanf_s("%d", &month);
                    if (success != 1 || month < 1 || month > 12) {
                        printf("������: ������� ���������� �����.\n\n");
                        while (getchar() != '\n');
                    }
                }
                success = 0;
                while (success != 1 || year < 1800 || year > 2100) {
                    printf("������� ��� �������� (����� �� 1800 �� 2100): ");
                    success = scanf_s("%d", &year);
                    if (success != 1 || year < 1800 || year > 2100) {
                        printf("������: ������� ���������� ���.\n\n");
                        while (getchar() != '\n');
                    }
                }

                start_timer(); // ������ �������

                record(log, day, month, year, 1);

                // ������� ������
                sum = day + month + year;
                while (sum > 22) {
                    int tempSum = 0;
                    while (sum > 0) {
                        tempSum += sum % 10;
                        sum /= 10;
                    }
                    sum = tempSum;
                }
                arcana = sum;

                const char* result[] = {
                    "���", "���", "�����", "�����������", "���������", "��������", "����������",
                    "���������", "��������������", "���������", "������ �������", "����",
                    "����������", "������", "�����������", "������", "�����", "������",
                    "����", "������", "���", "���"
                };

                printf("\n��� ������ �����: %s\n", result[arcana]);
                read(info, result[arcana]);
                _getch();

                fclose(log);
                fclose(info);
            }
            else if (menu_position == 2) {
                // ����� �����
                FILE* log;
                fopen_s(&log, "log.txt", "r");
                char line[1024];
                while (fgets(line, 1024, log)) {
                    printf("%s", line);
                }
                fclose(log);
                printf("\n������� ����� ������� ��� �������� � ����...");
                _getch();
            }
            else if (menu_position == 3) {
                print_time(); // ����� �������
                _getch();
            }
            else if (menu_position == 4) {
                stop_timer(); // ������� �������
                break;
            }
        }
    }
}
