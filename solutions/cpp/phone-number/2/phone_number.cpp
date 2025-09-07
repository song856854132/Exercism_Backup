#include "phone_number.h"
#include "regex"


using namespace std;

namespace phone_number {

phone_number::phone_number(const string& input){
    // pre-process
    string temp = input;
    string pop_char = regex_replace(input, regex("[^0-9]"), "");

    // determin NANP
    // Handle 11-digit numbers starting with '1'
    if (pop_char.size() == 11 && pop_char[0] == '1') {
        pop_char.erase(0, 1);  // remove leading '1'
    }

    // Must now be exactly 10 digits
    if (pop_char.size() != 10) {
        throw domain_error("Invalid NANP");
    }

    // NANP rules: area code (first digit) and exchange code (fourth digit) must not be 0 or 1
    if (pop_char[0] == '0' || pop_char[0] == '1' || pop_char[3] == '0' || pop_char[3] == '1') {
        throw domain_error("Invalid NANP");
    }

    digits = pop_char;  
}

string phone_number::number() const {
    return digits;
}

}  // namespace phone_number
