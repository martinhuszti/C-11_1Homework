#ifndef MYSTRING_H
#define MYSTRING_H
#include <iostream>

class MyString {
public:
MyString();
MyString(const char *);
MyString(MyString const &m);

void operator=(const MyString);
void operator=(const char*);
MyString& operator[](int m);
MyString operator[](int m) const;

};

#endif
