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
								str[0] = 0;  //'\0'
}
~StringValue(){
								delete[] str;
								ref_counter=0;
								size =0;
}

char *getStr() const {
								return str;
}
size_t getSize() const {
								return size;
}
int getRef_count() const {
								return ref_counter;
}
void incRef(){
								ref_counter++;
}
void decRef(){
								ref_counter--;
}
};



class MyString {

private:
StringValue * strvalue;
public:



//kiíráshoz
const char * getString() const {
								if(strvalue!=nullptr)
																return strvalue->getStr();
}
//üres konstruktor //új karaktertömb kell
MyString() : strvalue{new StringValue}{
}
//értékadó konstruktor //új karaktertömb kell
MyString(const char * chars){
								strvalue = new StringValue{chars};
}
//másoló konstruktor //refeneciaszám növelése
MyString(const MyString &otherms){
								this->strvalue = otherms.strvalue;
								strvalue->incRef();
}
//destruktor
~MyString(){
								this->decRef();
}

size_t size() const
{
								return strvalue->getSize();
}

void decRef(){
								if(strvalue==nullptr) return;
								strvalue->decRef();
								if(strvalue->getRef_count() == 0) {
																delete strvalue;
																strvalue = nullptr;
								}
}


char& operator[](int index){
								if(strvalue->getRef_count()<=1) {
																return strvalue->getStr()[index];
								}
								auto tempStr = getString();
								decRef();
								strvalue = new StringValue{tempStr};
								return strvalue->getStr()[index];
}

MyString& operator=(const MyString& ms){
								strvalue = ms.strvalue;
								strvalue->incRef();
								return *this;
}

MyString& operator+=(const MyString& other){
								char temp[size()+other.size()+1];
								strcpy (temp,getString() );
								strcat(temp,other.getString());
								decRef();
								strvalue = new StringValue{temp};

								return *this;


}

MyString operator+(const MyString& other){
								MyString temp{*this};
								temp+=other.strvalue->getStr();
								return temp;
}

};



std::ostream& operator<<(std::ostream& os, const MyString s){
								os << s.getString();
								return os;
}



#endif
