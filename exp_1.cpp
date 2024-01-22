//Write a program to count occurrences of a subing
#include<iostream>
using namespace std;
int count(string str,string sub){
    int count = 0;
    int m = str.size();
    int n = sub.size();
    for(int i=0;i<=m-n;i++){
        if(sub == str.substr(i,n)){
            count ++;
        }
    }
    return count ;
}
int main(){
    cout << count("hello","o")<<endl;
    cout << count("helllo","ll")<<endl;
    
}