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
								str[0]=0;
								strcat(str,s);
}
StringValue() : size{0},ref_counter{1}{
								str = new char[1];
								str[0] = 0;  //'\0'
}
~StringValue(){
								delete[] str;
								str = nullptr;
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
size_t lenght() const
{
								return strvalue->getSize();
}

void decRef(){
	if(strvalue == nullptr) return;
								strvalue->decRef();
								if(strvalue->getRef_count() == 0) {
																delete strvalue;
																strvalue = nullptr;
								}
}

//kiíráshoz
const char * getString() const {

								return strvalue->getStr();
}
//üres konstruktor
MyString() : strvalue{new StringValue}{
}
//értékadó konstruktor
MyString(const char * chars){
								strvalue = new StringValue{chars};
}
//másoló konstruktor
MyString(const MyString &other){
								this->strvalue = other.strvalue;
								strvalue->incRef();
}
//move konstruktor
MyString( MyString &&other){
	std::cout<<"\nmove konsturktor meghivva\n";
	strvalue = other.strvalue;
	other.strvalue=nullptr;
}
//move értékadás
MyString& operator=(MyString &&other){
	std::cout<<"\nmove értékadás meghívva\n";
	decRef();
	this->strvalue = other.strvalue;
	other.strvalue= nullptr;
	return *this;
	}
//destruktor
~MyString(){
								this->decRef();
}

//indexelő opertor
char& operator[](size_t index){
								if(index>lenght()-1) throw std::out_of_range("rossz indexelés");
								if(strvalue->getRef_count()<=1) {
																return strvalue->getStr()[index];
								}
								auto tempStr = getString();
								decRef();
								strvalue = new StringValue{tempStr};
								return strvalue->getStr()[index];
}

//értékadó op string
MyString& operator=(const MyString& ms){
								if(this == &ms) return *this;
								decRef();
								strvalue = ms.strvalue;
								strvalue->incRef();
								return *this;
}

//érkékadó op chartömbbel
MyString& operator=(const char * other){
	
								decRef();
								strvalue = new StringValue(other);
								return *this;
}

//összefűz stringgel
MyString& operator+=(const MyString& other){
								if(other.lenght() == 0) return *this;

								char temp[lenght()+other.lenght()+1];
								temp[0]=0; //strcat miatt
								strcat (temp,getString() );
								strcat (temp,other.getString());

								decRef();
								strvalue = new StringValue{temp};
								return *this;

}

//összefűz chartömbbel
MyString& operator+=(const char* other){
								if(strlen(other)==0) return *this;

								char temp[lenght()+strlen(other)];
								temp[0]=0; //strcat miatt
								strcat (temp,getString() );
								strcat (temp,other);

								decRef();
								strvalue = new StringValue{temp};

								return *this;

}

//összead sztringel
MyString operator+(const MyString& other){
								MyString temp{*this};
								temp+=other;
								return std::move(temp);
}
//összead charral
MyString operator+(const char* other){
								if(strlen(other)==0) return {*this};

								char temp[lenght()+strlen(other) +1];
								temp[0]=0; //strcat miatt
								strcat (temp,getString() );
								strcat (temp,other);

								return {temp};
}

};


//kiír opertor
std::ostream& operator<<(std::ostream& os, const MyString s){
								os << s.getString();
								return os;
}



#endif
