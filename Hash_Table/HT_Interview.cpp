// #include <iostream>
// #include <vector>

// using namespace std;

// bool itemInCommon(vector<int> vect1, vector<int> vect2) {
//     for(auto i: vect1) {
//         for(auto j: vect2) {
//             if(i == j) return true;
//         }
//     }
//     return false;
// }

// int main() {
//     vector<int> vect1 {1, 3, 5};
//     vector<int> vect2 {2, 4, 5};
//     cout << itemInCommon(vect1, vect2);
// }
// this problem solve by array

// solve this problem by hash-table

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

bool itemInCommon(vector<int> vect1, vector<int> vect2){
    unordered_map <int, bool> myMap;
    
    for(auto i : vect1){
        myMap.insert({i, true});

    }

    for(auto j : vect2){
        if(myMap[j]) return true;
    }

    return false;
}

int main() {
    vector<int> vect1 {1, 3, 5};
    vector<int> vect2 {2, 4, 6};
    cout << itemInCommon(vect1, vect2);
}

// Both Insert and Lookup by key in a Hash Table is O(1);
// Since a Hash Table is O(1) for Insert and Lookup it is always better than a Binary Search Tree;
// Looking up a value in a Hash Table is O(1);