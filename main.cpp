#include <iostream>
#include "infix2postfix.h"
#include <typeinfo>

int main() {

    Infix2Postfix *postfix = new Infix2Postfix("6+4/7*5/4-10");
    std::cout << postfix->result;
    return 0;
}