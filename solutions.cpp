#include "solutions.h"
#include "cassert"
#include <cmath>
#include <iostream>
using namespace std;


// TASK 1
// after simplifying expression "int x = x = 0 ? 1 : 0"
// we get "x = 0"
bool task1(int x)
{
    #ifndef NDEBUG
    assert((x = x = 0 ? 1 : 0) == (x = 0));
    #endif // !NDEBUG
    return ((x = x = 0 ? 1 : 0) == (x = 0));
}



//TASK 2
// we have to fing recurency
// we will do it apart for x and y
// z(k) = x(k) * y(k)
// x(k) = x^2^(n - k)
// y(k) = x^2^k

// z(k+1) = x(k+1) * y(k+1)
// x(k+1) = x^2^(n - (k+1)) = x^2^(n - k - 1) = x^(2^(n - k) * 2^(-1)) =  x^(2^(n - k))^(1/2) = sqrt(x(k))
// y(k+1) = y^2^(k+1) = y^(2^k * 2^1) = (y^2^k)^ 2 = y(k)^2

// in array we keep the addendums of polynom
// in a loop we calculate values for x-parts and y-parts
// and multiplicate the neccesary addendums
// in the end we find sum and return it
int task2(const int x, const int y, const unsigned int n)
{
    int* a = new int[n + 1];
    for (int i = 0; i < n + 1; i++)
        a[i] = 1;
    int x_val = x;
    int y_val = y;
    a[0] *= y_val;
    a[n] *= x_val;
    for (int i = 1; i < n + 1; i++) {
        x_val = x_val * x_val;
        y_val = y_val * y_val;
        a[n - i] *= x_val;
        a[i] *= y_val;
    }
    int sum = 0;
    for (int i = 0; i < n + 1; i++)
        sum += a[i];
    delete[] a;
    return sum;
}



// TASK 3
// we use built-in function "~" to invert our number
// we use expression "x + (~x) + 1 = 0" to check our result
unsigned int task3(unsigned int x)
{
    #ifndef NDEBUG
    assert((x + (~x) + 1) == 0);
    #endif // !NDEBUG
    return (~x);
}


// TASK 4 (1)
// we are working with letters only,
// so we can add a 'distance' between lower and uppercase to ASCII code of symbol
// we calculate this 'distance' as  " -'a' + 'A' "
// but we check whether it is alredy Uppercase
void toUpperCase(char* string, unsigned int len)
{
    for (int i = 0; i < len; i++) {
        if (string[i] >= 'Z')
            string[i] = string[i] - 'a' + 'A';
    }
}

// TASK 4 (2)
// the same logic as in 4(1)
// we just have to subtract this 'distance'
void toLowerCase(char* string, unsigned int len)
{
    for (int i = 0; i < len; i++) {
        if (string[i] < 'a')
            string[i] = string[i] - 'A' + 'a';
    }
}


// Task 5
// we compare lengths first
// then in a loop we compare all the symbols
// if the function has not returned in a loop - strings are equal
bool operator== (const String& s1, const String& s2)
{
    if (s1._len != s2._len)
        return false;
    for (int i = 0; i < s1._len; ++i)
    {
        if (s1._symbols[i] != s2._symbols[i])
            return false;
    }
    return true;
}



// TASK 6
// in a loop we compare symbols
// if one string is a prefix if another one - return true
bool operator< (const String& s1, const String& s2)
{
    if (s1._len == 0)
        return true;
    if (s2._len == 0)
        return false;
    for (int i = 0; i < min(s1._len, s2._len); ++i)
    {
        if (s1._symbols[i] > s2._symbols[i])
            return false;
        if (s1._symbols[i] < s2._symbols[i])
            return true;
    }
    if (s1._len == min(s1._len, s2._len))
        return true;
    return false;
}



// TASK 7
// we create a variabe n, whick is tracking length
// in a loop we "move" pointer of an char array and increment n
unsigned int leng(const char* str)
{
    unsigned int n;
    for (n = 0; *str++; n++);
    return n;
}



// TASK 8
// we use bubble sort to solve
// we use function from task 7
// reverse order
void less_task8(String** str_arr, unsigned int len) {
    for (int i = 0; i < len; i++) {
        for (int j = 0; j < len - i- 1; j++) {
            if ((*str_arr[j+1])._len > ((*str_arr[j])._len)) {
                String* s = str_arr[j];
                str_arr[j] = str_arr[j + 1];
                str_arr[j + 1] = s;
            }
        }
    }
}


// TASK 9 (1)
// we use bubble sort and operator from task 6
void task9_1(String** str_arr, unsigned int len) {
    for (int i = 0; i < len; i++) {
        for (int j = 0; j < len - 1 - i; j++) {
            if ((*str_arr[j]) < (*str_arr[j + 1])) {
                String* s = str_arr[j];
                str_arr[j] = str_arr[j + 1];
                str_arr[j + 1] = s;
            }
        }
    }
}



// TASK 9 (2)
// we use bubble sort 
// straight order
void task9_2(String** str_arr, unsigned int len) {
    for (int i = 0; i < len; i++) {
        for (int j = 0; j < len - 1 - i; j++) {
            if ((*str_arr[j+1])._len < (*str_arr[j])._len) {
                String* s = str_arr[j];
                str_arr[j] = str_arr[j + 1];
                str_arr[j + 1] = s;
            }
        }
    }
}



// Task 10
// we use a template
// for using function operagor '<' must be defined
// to use it for sorting array if strings we will use operator from Task 6
template <typename T>
void task10(T* array, size_t len)
{
    for (int i = 0; i < len - 1; i++) {
        for (int j = 0; j < len - i - 1; j++) {
            if (*array[j + 1] < *array[j]) {
                T t;
                t = array[j + 1];
                array[j + 1] = array[j];
                array[j] = t;
            }
        }
    }
}


// TESTING FUNCTIONS

void t1() {
    cout << "TASK 1: " << endl;
    cout << "Are expressions (int x = x = 0 ? 1 : 0) and (x = 0) equal? " << endl;
    cout << "for x = 0: ";
    if (task1(0))
        cout << "true";
    else
        cout << "false";
    cout << endl << "for x = 1: ";
    if (task1(1))
        cout << "true";
    else
        cout << "false";
    cout << endl << "for x = 7: ";
    if (task1(7))
        cout << "true";
    else
        cout << "false";

}

void t2() {
    cout << endl << endl << endl << "TASK 2: " << endl;
    int x = 3;
    int y = 2;
    int n = 3;
    cout << "for x = " << x << "; y = " << y << "; n = " << n << ": " << endl << "Z = " << task2(x, y, n);
}

void t3() {
    cout << endl << endl << "TASK 3: " << endl;
    int n = 21;
    cout << "for n = " << n << ": " << endl << "result = " << task3(n);
}

void t4() {
    cout << endl << endl << endl << "TASK 4: " << endl;
    char c[] = { 'a', 'b', 'c', 'D', 'D', 'e', 'c', 'X', 'K', 'l', 'e' };
    char* t = c;
    int n = 11;
    cout << "default string: ";
    for (int i = 0; i < n; i++) {
        cout << t[i];
    }
    cout << endl;
    cout << "to upper case: ";
    toUpperCase(t, n);
    for (int i = 0; i < n; i++) {
        cout << t[i];
    }
    cout << endl;
    char w[] = { 'a', 'b', 'c', 'D', 'D', 'e', 'c', 'X', 'K', 'l', 'e' };
    t = w;
    cout << "to lower case: ";
    toLowerCase(t, 11);
    for (int i = 0; i < n; i++) {
        cout << t[i];
    }
}

void t5() {
    const String s1 = String{ "abcd", 4 };
    const String s2 = String{ "abcd", 4 };
    cout << endl << endl << endl << "TASK 5: " << endl;
    cout << "string 1: " << s1._symbols << endl << "string 2: " << s2._symbols << endl;
    cout << "are equal: ";
    if (s1 == s2)
        cout << "true";
    else
        cout << "false";
    const String s3 = String{ "abce", 4 };
    cout <<endl << endl << "string 1: " << s1._symbols << endl << "string 2: " << s3._symbols << endl;
    cout << "are equal: ";
    if (s1 == s3)
        cout << "true";
    else
        cout << "false";
}


void t6() {
    const String s1 = String{ "abcde", 5 };
    const String s2 = String{ "abcd", 4 };
    cout << endl << endl << endl << "TASK 6: " << endl;
    cout << "string 1: " << s1._symbols << endl << "string 2: " << s2._symbols << endl;
    cout << "string 1 is less: ";
    if (s1 < s2)
        cout << "true";
    else
        cout << "false";
    const String s3 = String{ "abbb", 4 };
    cout << endl << endl << "string 1: " << s3._symbols << endl << "string 2: " << s1._symbols << endl;
    cout << "string 1 is less: ";
    if (s3 < s1)
        cout << "true";
    else
        cout << "false";
}

void t7() {
    const char* t = { "abcdef" };
    cout << endl << endl << endl << "TASK 7: " << endl;
    cout << "String: " << t << endl;
    cout << "length: " << leng(t);

}


void t8() {
    String* str[3];
    str[0] = new String{ "1234", 4 };
    str[1] = new String{ "12345", 5 };
    str[2] = new String{ "125", 3 };
    cout << endl << endl << endl << "TASK 8: " << endl;
    cout << "before sorting: " << endl;
    for (int i = 0; i < 3; i++) {
        cout << str[i]->_symbols << endl;
    }
    cout << "after sorting: " << endl;
    less_task8(str, 3);
    for (int i = 0; i < 3; i++) {
        cout << str[i]->_symbols << endl;
    }
}


void t9() {
    String* str[3];
    str[0] = new String{ "1234", 4 };
    str[1] = new String{ "12345", 5 };
    str[2] = new String{ "125",3  };
    cout << endl << endl << endl << "TASK 9: " << endl;
    cout << "before sorting: " << endl;
    for (int i = 0; i < 3; i++) {
        cout << str[i]->_symbols << endl;
    }
    cout << "after lexigographic sorting: " << endl;
    task9_1(str, 3);
    for (int i = 0; i < 3; i++) {
        cout << str[i]->_symbols << endl;
    }
    cout << "after lengths sorting: " << endl;
    task9_2(str, 3);
    for (int i = 0; i < 3; i++) {
        cout << str[i]->_symbols << endl;
    }
}

void t10() {
    String* str[3];
    str[0] = new String{ "efgh", 4 };
    str[1] = new String{ "abb", 3 };
    str[2] = new String{ "abcdef", 6 };
    cout << endl << endl << endl << "TASK 10: " << endl;
    cout << "before sorting: " << endl;
    for (int i = 0; i < 3; i++) {
        cout << str[i]->_symbols << endl;
    }
    cout << "after sorting: " << endl;
    task10(str, 3);
    for (int i = 0; i < 3; i++) {
        cout << str[i]->_symbols << endl;
    }
}


















