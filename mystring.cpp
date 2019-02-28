#include "mystring.h"
#include <iostream>

MyString::MyString(){
}
MyString::MyString(const * char){
}
MyString(MyString const &m){}

MyString& MyString::operator[](int m){}
MyString MyString::operator[](int m) const{}

void operator=(const MyString s){
}
void operator=(const char* c){
}


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
