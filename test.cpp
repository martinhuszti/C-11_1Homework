#include "mystring.h"
#include <iostream>

int szamlalo= 1;

void testBegin(const MyString& s){
        std::cout<<">>" << szamlalo <<". teszteset: ";
        std::cout << s <<"<<\n\n";
}
void testEnd(){
        std::cout  << "\n\n----------------------------" <<
         std::endl<< szamlalo++ <<". teszt vége" << std::endl;
                 
}
int main(int argc, char const *argv[]) {
	
		MyString egy("egy+++"); MyString ketto("+++ketto");
        MyString osszefuzve;
        
        testBegin("String Létrehozása üresen");
        MyString ures;
        std::cout<< ures;
        testEnd();

        testBegin("String létrehozása karaktertömbből");
        MyString inited("Én vagyok az inicializat String");
        std::cout << inited;
        testEnd();
        
        testBegin("Két String összefűzése +=-al");
        egy += ketto;
        std::cout <<egy;
        testEnd();
        
        testBegin("Két String összefűzése +-al");
        egy + ketto;
        std::cout <<osszefuzve;
        testEnd();

        //karakter start
		testBegin("Stringhez karakter összefűzése +-al");
        osszefuzve =  std::move(egy);
        std::cout << osszefuzve;
        testEnd();
        
        testBegin("Stringhez karakter összefűzése +=-vel");
        egy="+= ehhez fűzöm hozzá +=";
        egy += "ezt";
        std::cout <<egy;
        testEnd();
        //karakter vege

        testBegin("Move konstruktor");
        std::cout << (MyString("xxxhelloxxx"));
        testEnd();


        std::cout << "\n\nTeszteknek vége";

}
