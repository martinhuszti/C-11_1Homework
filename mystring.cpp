#include <iostream>
#include <cstring>
#include "mystring.h"

StringValue::StringValue(const char * s)
: size {strlen(s)}, ref_counter {1} {
    str = new char[size + 1];
    strcpy(str,s);
}
StringValue::StringValue()
: size {0}, ref_counter {1} {
    str = new char[1];
    str[0] = 0;
}
StringValue::~StringValue() {
    delete[] str;
}

char * StringValue::getStr() const {
    return str;
}
size_t StringValue::getSize() const {
    return size;
}
int StringValue::getRef_count() const {
    return ref_counter;
}
void StringValue::incRef() {
    ref_counter++;
}
void StringValue::decRef() {
    ref_counter--;
}

const size_t MyString::lenght() const {
    return strvalue -> getSize();
}

void MyString::decRef() {
    if (strvalue == nullptr) return;
    strvalue -> decRef();
    if (strvalue -> getRef_count() == 0) {
        delete strvalue;
        strvalue = nullptr;
    }
}

//kiíráshoz
const char * MyString::getString() const {
    return strvalue -> getStr();
}
//üres konstruktor
MyString::MyString(): strvalue { new StringValue } {
}
//értékadó konstruktor
MyString::MyString(const char *chars) {
	strvalue = new StringValue {chars};
}
//másoló konstruktor
MyString::MyString(const MyString & other) {
    this -> strvalue = other.strvalue;
    strvalue -> incRef();
}
//move konstruktor
MyString::MyString(MyString && other) noexcept {
    std::cout << "\nmove konsturktor meghivva\n";
    strvalue = other.strvalue;
    other.strvalue = nullptr;
}
//move értékadás
MyString & MyString::operator = (MyString && other) noexcept {
   if (this != &other){
    std::cout << "\nmove értékadás meghívva\n";
    decRef();
    this -> strvalue = other.strvalue;
    other.strvalue = nullptr;}
    return *this;
}
//destruktor
MyString::~MyString() {
    this -> decRef();
}
//indexelő operator
const char MyString::operator[](size_t index) const {
    if (index >= lenght()) throw std::out_of_range("rossz indexelés");

    return getString()[index];
}
//copy-on-write
char & MyString::operator[](size_t index) {
    if (index >= lenght()) throw std::out_of_range("rossz indexelés");

    if (strvalue -> getRef_count() <= 1) {
        return strvalue -> getStr()[index];
    }
    auto tempStr = getString();
    decRef();
    strvalue = new StringValue {
        tempStr
    };
    return strvalue -> getStr()[index];
}
//értékadó op string
MyString & MyString::operator = (const MyString & ms) {
    if (this == & ms) return *this;

    decRef();
    strvalue = ms.strvalue;
    strvalue -> incRef();
    return *this;
}
//összefűz stringgel
MyString & MyString::operator += (const MyString & other) {

    char * temp = new char[lenght() + other.lenght() + 1];
    strcpy(temp, getString());
    strcat(temp, other.getString());

    decRef();
    strvalue = new StringValue {temp};
    delete[] temp;
    return *this;

}
//összefűz chartömbbel
MyString & MyString::operator += (const char * other) {

    char * temp = new char[lenght() + strlen(other) + 1];
    strcpy(temp, getString());
    strcat(temp, other);

    decRef();
    strvalue = new StringValue {temp};
    delete[] temp;
    return *this;
}
//összead sztringel
MyString MyString::operator + (const MyString & other) {
    if (other.lenght() == 0) return {* this};

    MyString temp {* this};
    temp += other;

    return temp;
}
//összead charral
MyString MyString::operator + (const char * other) {
    if (strlen(other) == 0) return {* this};

    MyString temp;
    temp += other;

    return temp;
}
//kiír opertor
std::ostream & operator << (std::ostream & os, const MyString & s) {
    os << s.getString();
    return os;
}
//beolvas operator
std::istream & operator >> (std::istream & is, MyString & s) {
	char c;
	s = "";
	while (is.get(c)) { s+=&c; }

    return is;
}
