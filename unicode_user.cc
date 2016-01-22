/*
* keyword : boost::spirit::qi::parse qi::unicode::char_ qi::lit
* cswuyg 
* 2016.01.21
* */
#include "unicode_user.h"

namespace rick {
    boost::shared_ptr<Parser> Parser::_s_self; 
    boost::shared_ptr<Parser> Parser::instance() {
        if (_s_self) {
            return _s_self;
        } else {
            _s_self = boost::shared_ptr<Parser>(new Parser());
            return _s_self;
        }
    }
    
    std::string Parser::parse(const std::string input) {
        std::cout << input << std::endl;
        std::wstring unicode_input = boost::locale::conv::utf_to_utf<wchar_t>(input.c_str());

        Interpreter interpreter;
        std::wstring ret;
        std::wstring::iterator begin = unicode_input.begin();
        std::wstring::iterator end = unicode_input.end();
        bool result = qi::parse(begin, end, interpreter, ret);   // returns true if successful

        if (result && begin == end) {
            std::string utf_ret = boost::locale::conv::utf_to_utf<char>(ret.c_str());
            std::cout << "result:" << utf_ret << std::endl;
            return utf_ret;
        } else {
           std::wstring rest(begin, end);
           std::string utf8_rest = boost::locale::conv::utf_to_utf<char>(rest.c_str());
           std::cout << "rest:" << gbk_ret << std::endl;
        }
        std::cout << "parse fail:" << std::endl;
        return "";
    }

    Interpreter::Interpreter() : 
        Interpreter::base_type(nums) { // nums is final expression
        using boost::phoenix::bind;
        using boost::spirit::_1;
        using boost::spirit::_2;
        using boost::spirit::_val;

        nums = (sign >> num[bind(&Action::num_func, &_action, _val, _1)])[_val=_1+_2];  //test _val and _1 and _2
        num = *(qi::unicode::char_(L"零")[bind(&Action::zero_func, &_action, _val, _1)] | qi::unicode::char_(L"一")[_val+=L"1"]); // test bind
        sign = qi::unicode::char_(L"负")[_val=L"-"] | qi::lit(L"正")[_val=L"+"];  // test action
    }

    void Action::zero_func(std::wstring& ret, wchar_t ch) {
        std::cout << __func__ << std::endl;
        ret += L"0";
    }

    void Action::num_func(std::wstring& ret, std::wstring const& match_item) {
        std::string log = boost::locale::conv::utf_to_utf<char>(match_item.c_str());
        std::cout << "match num:" << log << std::endl;
        ret += match_item;
        log = boost::locale::conv::utf_to_utf<char>(ret.c_str());
        std::cout << "expression:" << log << std::endl;
    }
}
