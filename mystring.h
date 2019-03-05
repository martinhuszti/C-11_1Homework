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


operator +(MyString s1, MyString s2){
}
operator +=(MyString s, char c){
}
std::ostream& operator<<(std::ostream& os, MyString& s){
        return os;
}
std::istream& operator>>(std::istream& is, MyString& s){
        return is;
}

#endif
