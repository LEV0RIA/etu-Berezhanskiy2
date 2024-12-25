#include "pch.h"
#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include <stdio.h>
#include <stdlib.h>

int isChislo(const char* str) {
    if (*str == '-' || *str == '+') str++; // ���� ����� ������
    while (*str) {
        if (!isdigit(*str)) return 0;
        str++;
    }
    return 1;
}

int writeLog(const char* filename, const char* data) {
    FILE* file = NULL;
    errno_t err = fopen_s(&file, filename, "w");

    if (err != 0 || file == NULL) {
        return 0;
    }
    fprintf(file, "%s", data);
    fclose(file);
    return 1;
}

int summa(int a, int b) {
    return a + b;
}

int razn(int a, int b) {
    return a - b;
}

// ���� 1: �������� ������������ ��������� ���������� �������� �����
TEST_CASE("������ ������� ��������") {
    const char* valid_int = "12345"; // ���������� ������ � ����� ������
    const char* valid_int_sign = "-12345";

    // ���������, ��� ������ � ����� ������ ��������� ����������
    REQUIRE(isChislo(valid_int) == 1);
    REQUIRE(isChislo(valid_int_sign) == 1);

    // ���������, ��� �������� ���� ����� �������� ���������
    int result = summa(10, 5);
    REQUIRE(result == 15);
}
// ���� 2: �������� ��������� ��� ������������ ���������
TEST_CASE("�������� ������� ��������") {
    const char* invalid_int = "12a34";  // ������������ ������ � ������
    const char* invalid_int_spaces = " 123 ";  // ������ � ���������

    REQUIRE(isChislo(invalid_int) == 0);
    REQUIRE(isChislo(invalid_int_spaces) == 0);

    int result = summa(10, -5);
    REQUIRE(result == 5);
}
// ���� 3: �������� ��������� �������� ���������
TEST_CASE("��������� �������� �������������� ���������") {
    int min_int = INT_MIN;
    int max_int = INT_MAX;

    REQUIRE(min_int == -2147483648);
    REQUIRE(max_int == 2147483647);

    REQUIRE(summa(min_int, 1) == -2147483647);
    REQUIRE(summa(max_int, -1) == 2147483646);
}
// ���� 4: �������� ������������ �������� � ����������� �� ������� ������
TEST_CASE("���������� ���������� �� ������ ������� ��������") {

    int result_summa = summa(10, 5);
    int result_razn = razn(10, 5);

    REQUIRE(result_summa == 15);
    REQUIRE(result_razn == 5);

    REQUIRE(summa(-10, 5) == -5);
    REQUIRE(razn(-10, 5) == -15);
}
// ���� 5. �������� �� ������ � ����
TEST_CASE("������ � log.txt") {
    const char* filename = "log.txt";
    const char* text = "��� �������� ������";

    REQUIRE(writeLog(filename, text) == 1);
    // ������ ������ �� �����
    FILE* file = nullptr;
    char content[256];

    errno_t err = fopen_s(&file, filename, "r");
    if (err == 0 && file) {
        fgets(content, sizeof(content), file);
        fclose(file);
    }
    // ���������, ��� ���������� ����� ��������� � ���������
    REQUIRE(strcmp(content, text) == 0);
}