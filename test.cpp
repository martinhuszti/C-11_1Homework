#include "mystring.h"
#include <iostream>

int szamlalo= 1;

void testBegin(const MyString& s){
        std::cout<<">>" << szamlalo <<". teszteset: ";
        std::cout << s <<"<<" << std::endl;
}
void testEnd(){
        std::cout << std::endl<<szamlalo++ <<". teszt vége" << std::endl
                  << "----------------------------" << std::endl<<std::endl;
}
int main(int argc, char const *argv[]) {
        testBegin("String Létrehozása üresen");
        MyString ures;
        std::cout<< ures;
        testEnd();

        testBegin("String létrehozása karaktertömbből");
        MyString inited("Én vagyok az inicializat String");
        std::cout << inited;
        testEnd();

        testBegin("Két String összefűzése +-al");
        MyString egy("egy+++"); MyString ketto("+++ketto");
        MyString osszefuzve = egy + ketto;
        std::cout <<osszefuzve;
        testEnd();

        testBegin("Két String összefűzése +=-vel");
        egy="egy+++"; ketto="===ketto";
        osszefuzve = egy + ketto;
        std::cout <<osszefuzve;
        testEnd();

        testBegin("Stringhez karakter összefűzése +-al");
        egy="ehhez fűzöm hozzá +";
        osszefuzve = egy + "ezt";
        std::cout << osszefuzve;
        testEnd();

        testBegin("Stringhez karakter összefűzése +=-vel");
        egy="+= ehhez fűzöm hozzá +=";
        egy += "ezt";
        std::cout <<egy;
        testEnd();

        std::cout << "\n\nTeszteknek vége";

}
