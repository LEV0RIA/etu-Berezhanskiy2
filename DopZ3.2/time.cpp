#include <chrono>
#include <stdio.h>
#include "time.h"

using namespace std::chrono;

static high_resolution_clock::time_point start;
static bool timer_started = false;

void start_timer() {
    if (!timer_started) {
        start = high_resolution_clock::now();
        timer_started = true;
    }
}

void stop_timer() {
    if (timer_started) {
        auto end = high_resolution_clock::now();
        auto duration = duration_cast<milliseconds>(end - start);
        printf("Итоговое время работы программы: %d миллисекунд\n", (int)duration.count());
    }
}

void print_time() {
    if (timer_started) {
        auto end = high_resolution_clock::now();
        auto duration = duration_cast<milliseconds>(end - start);
        printf("Время работы программы: %d миллисекунд\n", (int)duration.count());
    }
    else {
        printf("Таймер не был запущен.\n");
    }
}
