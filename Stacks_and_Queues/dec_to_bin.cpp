#include <iostream>
#include <stack>

using namespace std;

void dec_to_bin(int number){
    stack<int> result;
    while(number > 0){
        int x = number%2;
        result.push(x);
        number /= 2;
    }
    
    while(!result.empty()){
        int item = result.top();
        result.pop();
        cout << item;
    }
}

int main(){
    int num;
    cin >> num;
    dec_to_bin(num);
    return 0;
}

ctime(){};
~ctime(){};