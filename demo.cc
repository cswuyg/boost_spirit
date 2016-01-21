/*
* keyword : boost::spirit::qi::parse qi::unicode::char_ qi::lit
* learn: http://www.boost.org/doc/libs/1_47_0/libs/spirit/example/qi/key_value_sequence.cpp
* cswuyg 
* 2016.01.21
* */

#include <string>
#include <iostream>

#include "unicode_user.h"

int main() {
    std::string input = "负零一零一";
    std::string output = rick::Parser::instance()->parse(input);
    std::cout << output << std::endl;
}

/*
gcc 3.4.5
./demo

负零一零一
zero_func
zero_func
match num:0101
expression:0101
result:-0101
-0101
 * */
