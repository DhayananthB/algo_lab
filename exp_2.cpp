//Find the pattern in the text using the naive pattern searching algorithm
#include <iostream>
using namespace std;
void naive(string txt,string pat){
    int m = txt.size();
    int n = pat.size();
    int j=0;
    for(int i = 0 ;i <= m-n ;i++){
        int j;
        for(j=0;j<n;j++){
            if(txt[i+j]!=pat[j]){
                break;
            }
        }
        if(j==n){
            cout << "pattern found at "<< i << endl;
        }

    }
}
int main(){
    naive("abccc","cc");
}