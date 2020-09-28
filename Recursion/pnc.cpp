#include<iostream>
#include<vector>
using namespace std;


int printPermutation(string str, int idx){
    if(0 == str.length())return 1;
    int count = 0;
    for(int i = 0; i<str.length(); i++){
        char ch = str[i];
        string roq = str.substr(0,i) + str.substr(i+1);
        count+=printPermutation(roq,idx+1);
    }
    return count;
}

int main(){
    cout<<printPermutation("abc", 0);
    return 0;
}