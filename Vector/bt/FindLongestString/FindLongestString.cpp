#include "FindLongestString.h"



string findLongestString(vector<string>& stringList) {
    int max = 0;
    string longestString;
	for(string str: stringList) {
	    if(max < str.size() ) {
	        max = str.size();
	        longestString = str;
	    }
	}
	return longestString;
}