#include <iostream>
#include <vector>
using namespace std;
int longestCommonSubsequence(string a , string b){
    int m = a.length();
    int n = b.length();
    vector<vector<int>> d(m+1,vector<int>(n+1,0));
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(a[i]==b[j]){
                d[i+1][j+1]= 1+ d[i][j];
            }
            else{
                d[i+1][j+1] = max(d[i][j+1],d[i+1][j]);
            }
        }
    }
    return d[m][n];
}
int main(){
    cout << longestCommonSubsequence("abcdef","axcd");
}