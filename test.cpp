#include "mystring.h"

int main(int argc, char const *argv[]) {
        MyString x = "hello";
        MyString y = x;
        y[0] = 'c';
        std::cout << x; /* hello */
        std::cout << y; /* cello */
        return 0;
}
