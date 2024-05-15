#include "HasUniqueChars.h"
#include <string>
#include <unordered_set>

using namespace std;


bool hasUniqueChars(const string& str) {
    unordered_set<char> charSet;
    for(char ch: str) {
        if(charSet.find(ch) != charSet.end()){
            return false;
        }
        charSet.insert(ch);
    }
    return true;
    //   +=====================================================+
    //   |                 WRITE YOUR CODE HERE                |
    //   | Description:                                        |
    //   | - This function checks if a string 'str' has unique |
    //   |   characters.                                       |
    //   | - It uses an unordered_set for quick look-up.       |
    //   | - It returns a boolean value.                       |
    //   |                                                     |
    //   | Return type: bool                                   |
    //   |                                                     |
    //   | Tips:                                               |
    //   | - 'charSet' stores characters we've seen.           |
    //   | - Loop through 'str' to populate 'charSet'.         |
    //   | - Use 'find' method for quick look-up in set.       |
    //   | - If a duplicate is found, return false.            |
    //   | - Check output from Test.cpp in "User logs".        |
    //   +=====================================================+
}