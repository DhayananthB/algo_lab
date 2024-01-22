//To find and output the maximum element in a given array using a brute-force technique.
#include<iostream>
using namespace std;
int maximum(int arr[] , int n){
    int max = INT_MIN;
    for(int i=0;i<n;i++ ){
        if(arr[i]>max){
            max =arr[i];
        }
    }
    return max;
}

int main(){
    int arr[] ={56,87,99,345,2};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << maximum(arr,n);

}