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

        return 0;
}
