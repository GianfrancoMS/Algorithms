//
// Created by GianfrancoMS on 4/13/2017.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//Passing by value because we want to modify the vector without changing the original
int secondMaxBySelecting(vector<int>numbers){
    nth_element(numbers.begin(),numbers.begin()+numbers.size()-2,numbers.end());
    int secondMax=numbers[numbers.size()-2];
    return secondMax;
}

//Passing by value because we want to modify the vector without changing the original
int secondMaxBySorting(vector<int>numbers){
    sort(numbers.begin(),numbers.end());
    int secondMax=numbers[numbers.size()-2];
    return secondMax;
}

/*
int main(){
    vector<int>numbers{1,2,3,4,5,5,6,7};
    cout<<secondMaxBySelecting(numbers)<<endl;
    cout<<secondMaxBySorting(numbers)<<endl;
    return 0;
}
*/
