#include "Number.h"
#include <cstdio>
#include <cstring>
#include <stdexcept>
using namespace std;

int pow(int a, int p) {
    int cop = 1;
    for (int i = 1; i <= p; i++)
        cop = cop * a;
    return cop;
}

int charToInt(char c) {
    if (c >= '0' && c <= '9') {
        return c - '0';
    }
    else if (c >= 'a' && c <= 'f') {
        return c - 'a' + 10;
    }
    else if (c >= 'A' && c <= 'F') {
        return c - 'A' + 10;
    }
    throw invalid_argument("Invalid character in input.");
}

int convertToBase10(const char* m, int b) {
    if (b < 2 || b > 16) {
        throw invalid_argument("Base must be between 2 and 16.");
    }

    int result = 0;
    int power = 0;
    for (int i = strlen(m) - 1; i >= 0; --i) {
        char c = m[i];
        int digit = charToInt(c);
        if (digit >= b) {
            throw invalid_argument("Invalid digit for the given base.");
        }
        result += digit * pow(b, power);
        ++power;
    }
    return result;
}

void Number::setValue(const char* newValue) {
    size_t len = strlen(newValue);
    value = new char[len + 1];  // Allocate space for the string plus the null terminator
    strcpy_s(value, len + 1, newValue);  // Use strcpy_s safely
}

Number::Number(const char* v, int b) : base(b) {
    if (base < 2 || base > 16) {
        throw invalid_argument("Base must be between 2 and 16.");
    }
    setValue(v);
}

Number::~Number() {
    delete[] value;
}

// Copy constructor
Number::Number(const Number& a) : base(a.base) {
    setValue(a.value);
}

// Move constructor
Number::Number(Number&& a) noexcept : value(a.value), base(a.base) {
    a.value = nullptr;
    a.base = 0;
}

// Copy assignment operator
Number& Number::operator=(const Number& a) {
    if (this != &a) {
        delete[] value;
        base = a.base;
        setValue(a.value);
    }
    return *this;
}

// Move assignment operator
Number& Number::operator=(Number&& a) noexcept {
    if (this != &a) {
        delete[] value;
        base = a.base;
        value = a.value;
        a.value = nullptr;
        a.base = 0;
    }
    return *this;
}

Number operator+(const Number& n1, const Number& n2) {
    int maxBase = std::max(n1.base, n2.base);

    int num1 = convertToBase10(n1.value, n1.base);
    int num2 = convertToBase10(n2.value, n2.base);

    int result = num1 + num2;

    char buffer[33];
    int i = 0;
    while (result > 0) {
        int remainder = result % maxBase;
        buffer[i++] = (remainder < 10) ? (remainder + '0') : (remainder - 10 + 'A');
        result /= maxBase;
    }
    buffer[i] = '\0';

    for (int j = 0; j < i / 2; ++j) {
        char temp = buffer[j];
        buffer[j] = buffer[i - j - 1];
        buffer[i - j - 1] = temp;
    }

    return Number(buffer, maxBase);
}

Number operator-(const Number& n1, const Number& n2) {
    int maxBase = max(n1.base, n2.base);

    int num1 = convertToBase10(n1.value, n1.base);
    int num2 = convertToBase10(n2.value, n2.base);

    int result = num1 - num2;

    if (result == 0) {
        return Number("0", maxBase);
    }

    char buffer[33];
    int i = 0;
    while (result > 0) {
        int remainder = result % maxBase;
        buffer[i++] = (remainder < 10) ? (remainder + '0') : (remainder - 10 + 'A');
        result /= maxBase;
    }
    buffer[i] = '\0';

    
    for (int j = 0; j < i / 2; ++j) {
        char temp = buffer[j];
        buffer[j] = buffer[i - j - 1];
        buffer[i - j - 1] = temp;
    }

    return Number(buffer, maxBase);
}

bool Number::operator>(const Number& a) const {
    int num1 = convertToBase10(value, base);
    int num2 = convertToBase10(a.value, a.base);
    return num1 > num2;
}

bool Number::operator<(const Number& a) const {
    int num1 = convertToBase10(value, base);
    int num2 = convertToBase10(a.value, a.base);
    return num1 < num2;
}

bool Number::operator>=(const Number& a) const {
    int num1 = convertToBase10(value, base);
    int num2 = convertToBase10(a.value, a.base);
    return num1 >= num2;
}

bool Number::operator<=(const Number& a) const {
    int num1 = convertToBase10(value, base);
    int num2 = convertToBase10(a.value, a.base);
    return num1 <= num2;
}

bool Number::operator==(const Number& a) const {
    int num1 = convertToBase10(value, base);
    int num2 = convertToBase10(a.value, a.base);
    return num1 == num2;
}

char Number::operator[](int ind) const {
    if (ind < 0 || ind >= strlen(value)) {
        throw out_of_range("Index out of bounds");
    }
    return value[ind];
}

Number& Number::operator--() {
    int len = strlen(value);
    if (len > 1) {
        char* newValue = new char[len];
        strcpy_s(newValue, len, value + 1);
        delete[] value;
        value = newValue;
    }
    else {
        delete[] value;
        value = new char[2];
        value[0] = '0';
        value[1] = '\0';
    }
    return *this;
}

Number Number::operator--(int) {
    Number temp(*this);
    int len = strlen(value);
    if (len > 1) {
        char* newValue = new char[len];
        strncpy_s(newValue, len, value, len - 1);
        newValue[len - 1] = '\0';
        delete[] value;
        value = newValue;
    }
    else {
        delete[] value;
        value = new char[2];
        value[0] = '0';
        value[1] = '\0';
    }
    return temp;
}

void Number::SwitchBase(int newBase) {
    if (newBase < 2 || newBase > 16) {
        throw invalid_argument("Base must be between 2 and 16.");
    }

    int num = convertToBase10(value, base);
    base = newBase;

    char buffer[33];
    int i = 0;
    while (num > 0) {
        int remainder = num % base;
        buffer[i++] = (remainder < 10) ? (remainder + '0') : (remainder - 10 + 'A');
        num /= base;
    }
    buffer[i] = '\0';

    for (int j = 0; j < i / 2; ++j) {
        char temp = buffer[j];
        buffer[j] = buffer[i - j - 1];
        buffer[i - j - 1] = temp;
    }

    delete[] value;
    setValue(buffer);
}

void Number::Print() const {
    printf("%s (Base %d)\n", value, base);
}

int Number::GetDigitCount() const {
    return strlen(value);
}

int Number::GetBase() const {
    return base;
}
