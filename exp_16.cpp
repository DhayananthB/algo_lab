// To reduce the number of required multiplications, leading to faster multiplication for large numbers compared to the standard long multiplication method
#include <iostream>
#include <algorithm>
#include<cmath>
using namespace std;

int len_of_num(long long n){
    int l=0;
    while(n){
        l++;
        n/=10;
    }
    return l;
}

long long karatsuba(long long  x,long long  y){ // x=123456 y=987654
    if(x<10 || y<10){
        return x*y;
    }
    int size = max(len_of_num(x),len_of_num(y)); //6

    size = size/2 + size %2; //3
    long long  mul = pow(10,size); //1000

    long long a = x/mul; //123
    long long b = x - (a*mul); // 456

    long long c = y/mul; //987
    long long d = y-(c*mul); //654

    long long ac = karatsuba(a,c); // 123*987
    long long bd = karatsuba(b,d); // 456*654
    long long abcd = karatsuba(a+b,c+d)-ac-bd;

    return bd + (abcd * mul) + (ac *(long long)pow(10,2*size));


}


int main(){
    cout << karatsuba(123456,987654);
    

}
