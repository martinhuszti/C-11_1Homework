#include "mystring.h"
#include <iostream>
#include <cstring>



int szamlalo= 1;

void testBegin(const MyString& s){
        std::cout <<"--------------"<< szamlalo <<". teszt start-----------\n";
        std::cout <<"*Teszt neve:\t"<< s <<"\n\n";
}
void testEnd(){
        std::cout << "\n\n--------------" <<
                szamlalo++ <<". teszt vége" <<"------------\n\n\n\n";

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
        osszefuzve = egy + ketto;
        std::cout <<osszefuzve;
        testEnd();

        //karakter start
        testBegin("Stringhez karakter összefűzése +=-vel");
        egy="+= ehhez fűzöm hozzá +=";
        egy += "ezt";
        std::cout <<egy;
        testEnd();

        testBegin("Stringhez karakter összefűzése +-al");
        osszefuzve =  std::move(egy);
        std::cout << osszefuzve;
        testEnd();
        //karakter vege

        testBegin("Move konstruktor");
        std::cout << (MyString("xxxhelloxxx"));
        testEnd();

        testBegin("Move értékadás");
        osszefuzve =MyString("hi");
        testEnd();

        testBegin("Beolvasás és kiírás");
        std::cout<< "Adj meg egy stringet:";
        MyString olvas;
        std::cin >> olvas;
        std::cout << olvas << '\n';
        testEnd();

        testBegin("[] operátor copy-on-write");
        egy="Ezt írom at\n";
        std::cout << egy;
        egy[0] = 'z';
        egy[2] = 'z';
        std::cout << egy;
        testEnd();

        testBegin("[] operátor const");
        egy="Ezt írom at\n";
        std::cout << egy[2];
        testEnd();

        testBegin("Hossz lekérdezése");
        egy="Ezt írom atd";
        std::cout << strlen("Ezt írom atd");
        std::cout << " = ";
        std::cout << egy.lenght();
        testEnd();


        std::cout << "\n\nMinden teszt sikeresen lefutott";
        return 0;

}
