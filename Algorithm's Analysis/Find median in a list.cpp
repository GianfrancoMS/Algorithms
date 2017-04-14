//
// Created by GianfrancoMS on 4/13/2017.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//Passing by value because we want to modify the vector without changing the original vector
double medianBySelecting(vector<int>numbers){
    int n = numbers.size()/2;
    double median=0;
    nth_element(numbers.begin(), numbers.begin() + n  , numbers.end());
    int temp=numbers[n];
    if( numbers.size() % 2 == 1)
        median=temp;
    else{
        nth_element(numbers.begin(), numbers.begin() + n - 1, numbers.end());
        median= static_cast<double>( temp + numbers[n-1] ) / 2;
    }
    return median;
}

//Passing by value because we want to modify the vector without changing the original vector
double medianBySorting(vector<int>numbers){
    sort(numbers.begin(),numbers.end());
    int n=numbers.size() / 2;
    double median=0;
    if( numbers.size() % 2 == 1 )
        median= numbers[n];
    else
        median= static_cast<double>( numbers[n]+numbers[n - 1 ] ) / 2;
    return median;
}

/*
    int main(){
    vector<int>evenSize{1,4,2,3};
    vector<int>oddSize{1,5,2,4,3};
    cout<<medianBySelecting(evenSize)<<endl;
    cout<<medianBySelecting(oddSize)<<endl;
    cout<<medianBySorting(evenSize)<<endl;
    cout<<medianBySorting(oddSize)<<endl;
    return 0;
}
*/

