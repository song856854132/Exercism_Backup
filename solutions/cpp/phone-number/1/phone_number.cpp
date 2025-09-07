#include "phone_number.h"
#include "regex"


using namespace std;

namespace phone_number {

phone_number::phone_number(const string& input){
    // pre-process
    string temp = input;
    string pop_char = regex_replace(input, regex("[^0-9]"), "");

    // determin NANP
    if (pop_char.size() == 10){
        if (pop_char[0] == '0' || pop_char[0] == '1')
            throw domain_error("Invalid NANP");
        else if (pop_char[3] == '0' || pop_char[3] == '1')
            throw domain_error("Invalid NANP");
        else
            digits = pop_char;
    }
    else if  (pop_char.size() == 11 && pop_char[0] == '1'){
        pop_char.erase(0,1);
        if (pop_char[0] == '0' || pop_char[0] == '1')
            throw domain_error("Invalid NANP");
        else if (pop_char[3] == '0' || pop_char[3] == '1')
            throw domain_error("Invalid NANP");
        else
            digits = pop_char;
    }
    else
        throw domain_error("Invalid NANP");    
}

string phone_number::number() const {
    return digits;
}

}  // namespace phone_number
