#include "anagram.h"
#include <algorithm>
namespace anagram {
static std::string to_lower(const std::string& s) {
    std::string result = s;
    std::transform(result.begin(), result.end(), result.begin(),
                   [](unsigned char c) { return std::tolower(c); });
    return result;
}
// Constructor
anagram::anagram(const std::string& word) : base_word(word) {}
// Match Function
std::vector<std::string> anagram::matches(const std::vector<std::string>& candidates) const {
    std::vector<std::string> result;
    // compare base_word to each candidates
    for (const auto& i : candidates) {
        if( *this == i )
            result.push_back(i);
    }
    return result;
}
// Override Operator==
bool anagram::operator==(const std::string& other) const {
    std::string a = to_lower(base_word);
    std::string b = to_lower(other);
    if( a == b )
        return false;
    std::sort(a.begin(), a.end());
    std::sort(b.begin(), b.end());

    return a == b;
    
}

// Destructor
anagram::~anagram() = default;
    
}  // namespace anagram
