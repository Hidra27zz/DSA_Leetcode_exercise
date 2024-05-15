#include "GroupAnagrams.h"


vector<vector<string>> groupAnagrams(const vector<string>& strings) {
    unordered_map <string, vector<string>> anagramGroups;
    for(const string& str: strings){
        string canonical = str;
        sort(canonical.begin(), canonical.end());
        anagramGroups[canonical].push_back(str);
    }
    
    vector<vector<string>> result;
    for(const auto& group : anagramGroups) {
        result.push_back(group.second);
    }   
    return result;
    
	//   +=====================================================+
	//   |                 WRITE YOUR CODE HERE                |
	//   | Description:                                        |
	//   | - This function groups anagrams from a given vector |
	//   |   of strings.                                       |
	//   | - It uses an unordered_map for organization.        |
	//   | - It sorts each string to form a canonical version. |
	//   | - Groups strings with the same canonical form.      |
	//   |                                                     |
	//   | Return type: vector<vector<string>>                 |
	//   |                                                     |
	//   | Tips:                                               |
	//   | - 'anagramGroups' maps canonical strings to groups. |
	//   | - 'canonical' is a sorted version of each string.   |
	//   | - 'result' holds the final groups of anagrams.      |
	//   | - Check output from Test.cpp in "User logs".        |
	//   +=====================================================+
}