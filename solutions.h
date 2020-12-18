#pragma once

bool task1(int x); // Task 1
int task2(const int x, const int y, const unsigned int n); // Task 2
unsigned int task3(unsigned int x); // Task 3
void toUpperCase(char* string, unsigned int len); // Task 4 (1 part)
void toLowerCase(char* string, unsigned int len); // Task 4 (2 part)
struct String
{
    const char* const _symbols;
    const size_t _len;
};
bool operator== (String& s1, String& s2); // Task 5
bool operator< (const String& s1, const String& s2); // Task 6
unsigned int leng(const char* str); // Task 7
void less_task8(String** str_arr, unsigned int len); // Task 8
void task9_1(String** str_arr, unsigned int len); // Task 9 (1 part)
void task9_2(String** str_arr, unsigned int len); // Task 9 (2 part)
template <typename T> void task10(T* array, size_t len); // Task 10

//Testing
void t1();
void t2();
void t3();
void t4();
void t5();
void t6();
void t7();
void t8();
void t9();
void t10();