//
// Created by GianfrancoMS on 4/13/2017.
//

#include <iostream>
#include <cmath>

using namespace std;

int _pow(int number, int n){
    if(n==0)
        return 1;
    else if(n==1)
        return number;
    else if(n==2)
        return number*number;
    else{
        int pow=_pow(number, static_cast<int>( floor(n/2) ) );
        if(n%2==1)
            return pow*pow*number;
        else
            return pow*pow;
    }
}

/*
int _pow(int number, int n){
    if(n==0)    return 1;
    else if(n==1)   return number;
    else if(n==2)   return number*number;
    else{
        int pow=_pow(number, static_cast<int>( floor(n/2) ) );
        return n%2==1 ? return pow*pow*number : return pow*pow;
    }
}
*/

/*
    int main(){
    int number=2;
    int n=4;
    cout<<_pow(number,n);
    return 0;
}*/

