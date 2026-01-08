#pragma once
#include <ostream>   
#include <cstring>
#include <iosfwd>

class MyString
{
private:
    char* data;

    static char* allocAndCopy(const char* s) {
        if (!s) s = "";
        const size_t n = std::strlen(s);
        char* p = new char[n + 1];
        std::memcpy(p, s, n + 1);
        return p;
    }

public:
    MyString() : data(allocAndCopy("")) {}

    MyString(const char* s) : data(allocAndCopy(s)) {}

    MyString(const MyString& other) : data(allocAndCopy(other.data)) {}

    MyString& operator=(const MyString& other) {
        if (this == &other) return *this;
        char* p = allocAndCopy(other.data);
        delete[] data;
        data = p;
        return *this;
    }

    ~MyString() { delete[] data; }

    const char* c_str() const { return data; }

    void set(const char* s) {
        char* p = allocAndCopy(s);
        delete[] data;
        data = p;
    }

    friend std::ostream& operator<<(std::ostream& os, const MyString& s) {
        os << s.data;
        return os;
    }
};
