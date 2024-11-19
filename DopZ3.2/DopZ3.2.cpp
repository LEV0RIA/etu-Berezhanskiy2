#include <locale.h>
#include "menu.h"

int main() {
    setlocale(LC_ALL, "");
    menu_loop(); // Запускаем главное меню
    return 0;
}
