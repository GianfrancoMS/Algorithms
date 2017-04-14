//
// Created by GianfrancoMS on 4/13/2017.
//
#include <iostream>
#include <cmath>

using namespace std;

bool isPrime(int number){
    int sqrtNumber=sqrt(number);
    for(int i=0;i<=sqrtNumber;++i){
        if(number % sqrtNumber==0)
            return true;
    }
    return false;
}

/*
int main(){
    int number=0;
    cin>>number;
    if(isPrime(number))
        cout<<"Number is prime"<<endl;
    else
        cout<<"Number is not prime"<<endl;
    return 0;
}
*/


