#include <iostream>
#include <cstring>

#include "mystring.h"

//1. szorgalmi teszt - elfogadva
int main(int argc, char const *argv[]) {

        MyString a = "hello";
        MyString b = a;
        std::cout << b[1];    /* e */

        a[1] = 'a';
        b[1] = b[4];
        std::cout << a << " " << b << '\n'; /* hallo hollo */

        MyString c = "helló világ";
        MyString d = "helló világ";

        MyString e1 = "";
        MyString e2 = "";
        MyString e3 = "";
        MyString e4 = "";
        MyString e5 = "";

        char helloka[] = "helloka";

MyString s1 = helloka;
MyString s2 = helloka;
std::cout<<" Helloka darabszam:"<< s2.getCount();

std::cout <<" ures string darabszam:" << e5.getCount();
        //std::cout << c << '\n';
        //std::cout << d << '\n';

        return 0;
}
