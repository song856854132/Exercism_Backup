#include <string>
#include <vector>
namespace anagram {
class anagram {
public:
    // Constructor: store the base word
    explicit anagram(const std::string& word);

    // Destructor
    ~anagram();

    // Function
    std::vector<std::string> matches(const std::vector<std::string>& candidates) const;
    bool operator==(const std::string& other) const;
private:
    std::string base_word;
};
}  // namespace anagram
