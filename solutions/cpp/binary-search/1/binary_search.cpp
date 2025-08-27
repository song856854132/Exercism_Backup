#include "binary_search.h"
#include <stdexcept>
using namespace std;

namespace binary_search {

std::size_t find(std::vector<int> arr, int target){
    int left=0, mid = 0;
    int right = arr.size() - 1;

    while(left <= right){
        mid = (left + right)/2;

        if(arr[mid] == target)
            return mid;
        else if(arr[mid] < target)
            left = mid+1;
        else
            right = mid-1;
    }
    throw domain_error("Value Not Found");
}

}  // namespace binary_search
