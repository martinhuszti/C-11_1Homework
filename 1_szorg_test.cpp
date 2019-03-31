#include <iostream>
#include <cstring>

#include "mystring.h"

//1. szorgalmi teszt
int main(int argc, char const *argv[]) {

        MyString a = "hello";
        MyString b = a;
        std::cout << b[1];    /* e */

        a[1] = 'a';
        b[1] = b[4];
        std::cout << a << " " << b << '\n'; /* hallo hollo */

        MyString c = "helló világ";
        MyString d = "hellós világ";

        MyString e1 = "";
        MyString e2 = "";
        MyString e3 = "";
        MyString e4 = "";
        MyString e5 = "";

        MyString u1;
        MyString u2;
        MyString u3;


        std::cout<< e5.getCount();
        std::cout<< c.getCount();
        std::cout<< d.getCount();

        std::cout<< u1.getCount();
        std::cout<< u2.getCount();
        std::cout<< u3.getCount();





        std::cout << c << '\n';
        //std::cout << d << '\n';

        return 0;
}
