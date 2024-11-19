#include <locale.h>
#include "menu.h"
#ifndef MENU_H
#error "Файл не найден"
#endif

int main() {
    setlocale(LC_ALL, "");
    menu_loop(); // Запускаем главное меню
    return 0;
}
