#ifndef MYSTRING_H
#define MYSTRING_H
#include <iostream>
#include <cstring>

class StringValue {
private:
char * str;
size_t size;
int ref_counter;

public:
StringValue(const char * s) : size{strlen(s)}, ref_counter{1}{
								str = new char[size+1];
								strcpy(str,s);
}
StringValue() : size{0},ref_counter{1}{
								str = new char[1];
								str[0] = 0;//'\0'
}
~StringValue(){
								delete[] str;
								ref_counter=0;
								size =0;
}
char *writeString() const {
								return str;
}
};

//void operator=(){}

class MyString {

private:
StringValue * strvalue;
public:
const char * writeString() const {
								return strvalue->writeString();
}
MyString() : strvalue{new StringValue}{
}
MyString(const char * chars){
								strvalue = new StringValue{chars};
}

};

std::ostream& operator<<(std::ostream& os, const MyString s){
								os << s.writeString();
								return os;
}

#endif
