#include "mystring.h"
#include <iostream>

int main(int argc, char const *argv[]) {
        MyString ures; std::cout << "Üres String létrehozva" << std::endl;
        MyString inicalizalt("init me pls"); std::cout << "Inicalizalt String létrehozva" << std::endl;
        std::cout<<inicalizalt <<std::endl << "-----------------------------";

        MyString x = "hello";
        MyString y = x;
        std::cout << y;

}
