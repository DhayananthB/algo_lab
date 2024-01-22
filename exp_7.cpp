//To demonstrate the divide and conquer technique by implementing the binary search algorithm.
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int binary_search(vector<int> & arr, int target){
    int l=0,r= arr.size()-1;
    while(l<=r){
        int mid = (l+r)/2;
        if(arr[mid]==target){
            return mid;
        }
        if(target > mid){
            l=mid+1;
        }
        else{
            r=mid-1;
        }
    }
    return -1;
}

int main(){
    vector<int> a = {2,4,55,88,90};
    sort(a.begin(),a.end());
    cout << binary_search(a,56) << " " << binary_search(a,90);

}