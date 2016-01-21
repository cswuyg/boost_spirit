/*
* keyword : boost::spirit::qi::parse qi::unicode::char_ qi::lit
* cswuyg 
* 2016.01.21
* */
#ifndef _UNICODE_USER_H_
#define _UNICODE_USER_H_

#define BOOST_SPIRIT_UNICODE 
#include <boost/spirit/include/qi.hpp>
#include <boost/spirit/include/phoenix.hpp>
#include <boost/lexical_cast.hpp>
#include <boost/locale.hpp>
#include <boost/shared_ptr.hpp>

#include <string>
#include <iostream>

namespace rick {
    namespace qi = boost::spirit::qi;

    // action
    class Action {
        public:
            Action() {}
            ~Action() {}
            void num_func(std::wstring& ret, std::wstring const& match_item);
            void zero_func(std::wstring& ret, wchar_t ch);
    };

    // rule
    struct Interpreter: qi::grammar<std::wstring::iterator, std::wstring()> {
            Interpreter(); 
            qi::rule<std::wstring::iterator, std::wstring()> num, sign, nums;
        private:
            Action _action;
    };

    // export for user
    class Parser {
        public:
           ~Parser(){}
           static boost::shared_ptr<Parser> instance();
           std::string parse(const std::string input);  // utf8 input, utf8 output

        private:
           Parser(){}
            static boost::shared_ptr<Parser> _s_self; 
    };
}

#endif
