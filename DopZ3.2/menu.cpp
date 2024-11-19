#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include "menu.h"
#include "levoria.h"
#include "time.h" // Для проверки состояния таймера

void menu_loop() {
    int menu_position = 1;
    int key = 0;

    while (1) {
        system("cls");
        printf("Выберите пункт меню:\n");

        if (menu_position == 1) {
            printf("--> 1. Ввести дату <--\n");
        }
        else {
            printf("    1. Ввести дату\n");
        }

        if (menu_position == 2) {
            printf("--> 2. Вывести log.txt <--\n");
        }
        else {
            printf("    2. Вывести log.txt\n");
        }

        if (menu_position == 3) {
            printf("--> 3. Вывести время работы программы <--\n");
        }
        else {
            printf("    3. Вывести время работы программы\n");
        }

        if (menu_position == 4) {
            printf("--> 4. Выход <--\n");
        }
        else {
            printf("    4. Выход\n");
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

                // Ввод даты
                while (success != 1 || day < 1 || day > 31) {
                    printf("Введите день рождения (число от 1 до 31): ");
                    success = scanf_s("%d", &day);
                    if (success != 1 || day < 1 || day > 31) {
                        printf("Ошибка: Введите корректный день.\n\n");
                        while (getchar() != '\n');
                    }
                }
                success = 0;
                while (success != 1 || month < 1 || month > 12) {
                    printf("Введите месяц рождения (число от 1 до 12): ");
                    success = scanf_s("%d", &month);
                    if (success != 1 || month < 1 || month > 12) {
                        printf("Ошибка: Введите корректный месяц.\n\n");
                        while (getchar() != '\n');
                    }
                }
                success = 0;
                while (success != 1 || year < 1800 || year > 2100) {
                    printf("Введите год рождения (число от 1800 до 2100): ");
                    success = scanf_s("%d", &year);
                    if (success != 1 || year < 1800 || year > 2100) {
                        printf("Ошибка: Введите корректный год.\n\n");
                        while (getchar() != '\n');
                    }
                }

                start_timer(); // Запуск таймера

                record(log, day, month, year, 1);

                // Рассчёт аркана
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
                    "Шут", "Маг", "Жрица", "Императрица", "Император", "Иерофант", "Влюбленные",
                    "Колесница", "Справедливость", "Отшельник", "Колесо Фортуны", "Сила",
                    "Повешенный", "Смерть", "Умеренность", "Дьявол", "Башня", "Звезда",
                    "Луна", "Солнце", "Суд", "Мир"
                };

                printf("\nВаш высший аркан: %s\n", result[arcana]);
                read(info, result[arcana]);
                _getch();

                fclose(log);
                fclose(info);
            }
            else if (menu_position == 2) {
                // Вывод логов
                FILE* log;
                fopen_s(&log, "log.txt", "r");
                char line[1024];
                while (fgets(line, 1024, log)) {
                    printf("%s", line);
                }
                fclose(log);
                printf("\nНажмите любую клавишу для возврата в меню...");
                _getch();
            }
            else if (menu_position == 3) {
                print_time(); // Вывод времени
                _getch();
            }
            else if (menu_position == 4) {
                stop_timer(); // Останов таймера
                break;
            }
        }
    }
}
