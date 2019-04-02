#ifndef MYSTRING_H
#define MYSTRING_H
#include <cstdlib>
#include <iostream>
#include <map>
#include <string_view>




class Proxy;

class StringValue {
private:
char * str;
size_t size;
int ref_counter;

public:
StringValue(const char * );

StringValue();

~StringValue();

char * getStr() const;

size_t getSize() const;

int getRef_count() const;

void incRef();

void decRef();

};

class MyString {
private:
StringValue *strvalue;
static std::map<std::string_view, StringValue*> StringKeresoFa;

void decRef();

public:
//Szorgalmi 2 teszteléshez
int getCount();

void checkString(const char *chars);

const size_t length() const;

//kiíráshoz
char * getString() const;

//üres konstruktor
MyString();

//értékadó konstruktor
MyString(const char * );

//másoló konstruktor
MyString(const MyString & );

//move konstruktor
MyString(MyString && ) noexcept;

//move értékadás
MyString & operator = (MyString && ) noexcept;

//destruktor
~MyString();

Proxy operator[](size_t);

void set_char_at(size_t index,const char c);

const char get_char_at(size_t index) const;


//indexelő operator
const char operator[](size_t) const;

/* //old
    //copy-on-write
    char & operator[](size_t);*/

//értékadó op string
MyString & operator = (const MyString & );

//összefűz stringgel
MyString & operator += (const MyString & );

//összefűz karakterrel
MyString & operator += (const char );

//összefűz chartömbbel
MyString & operator += (const char * );

//összead sztringel
MyString operator + (const MyString & );

//összead charral
MyString operator + (const char * );

};




//1. szorgalmi
class Proxy {
private:
MyString* ms;
size_t index;

public:
Proxy(MyString*, size_t );

MyString& operator=(const char);

operator const char() const;

void operator=(const Proxy &p);

};




//kiír opertor
std::ostream & operator << (std::ostream &, const MyString & );
//beolvas operator
std::istream & operator >> (std::istream &, MyString & );

#endif
