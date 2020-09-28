#include<iostream>
#include<vector>
using namespace std;


void printInc(int a, int b){
    if(a==b+1)    return;
    cout<<a<<" ";
    printInc(a+1,b);
}

int fact(int n){
    return n<=1 ? 1 : fact(n-1)*n;
}

int minimum(vector<int > & arr, int i){
    if(i == arr.size()-1)   return arr[i];
    return min(arr[i],minimum(arr,i+1));
}

bool find(vector<int > & arr, int i, int data){
    if(i == arr.size()) return false;
    if(arr[i] == data)  return data;
    return find(arr, i+1,data);
}


int main(){
    // printInc(0,7);
    // cout<<fact(5);

    vector<int > arr = {2,7,5,1,6,-19,21,3,5,8};
    // cout<<minimum(arr,0);
    cout<<find(arr,0, 221);
    return 0;
}