#include "FindMaxMin.h"


vector<int> findMaxMin(vector<int>& myList) {

    int max, min;
    
	max = myList[0];
    min = myList[0];
	for(int num: myList) {
	    if(max < num) {
	        max = num;
	    }
	    if(min > num) {
	        min = num;
	    }
	}
	
	
	return vector<int> {max, min};
}