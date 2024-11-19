#ifndef LEVORIA_H
#define LEVORIA_H

#include <stdio.h>

#define N 1024  // Размер буфера для чтения строки из info.txt

// Функция записи даты в файл
void record(FILE* log, int day, int month, int year, int success);

// Функция чтения информации из файла по ключу
void read(FILE* info, const char* arcanaName);

#endif