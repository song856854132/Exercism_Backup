#include "nucleotide_count.h"
#include <stdexcept>
using namespace std;

namespace nucleotide_count {

map<char, int> count(const string& DNA_seq) {
    map<char, int> ACGT_counter{{'A', 0}, {'C', 0}, {'G', 0}, {'T', 0}};

    for( char i : DNA_seq){
        if(ACGT_counter.find(i) == ACGT_counter.end()){
            throw invalid_argument("Error");
        }
        ACGT_counter[i]++;
    }
    return ACGT_counter;
}

}  // namespace nucleotide_count
