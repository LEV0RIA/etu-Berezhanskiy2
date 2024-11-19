#include "levoria.h"
#include <string.h>

void record(FILE* log, int day, int month, int year, int success) {
    if (success) {
        fprintf(log, "%02d.%02d.%04d\n", day, month, year);
    }
    else {
        fprintf(log, "Была введена некорректная дата\n");
    }
    fflush(log);
}

void read(FILE* info, const char* arcanaName) {
    fseek(info, 0, SEEK_SET);
    char arr[N];
    int found = 0;

    while (fgets(arr, N, info)) {
        if (strstr(arr, arcanaName)) {
            found = 1;
            printf("\n%s", arr);
            break;
        }
    }
}
