#include <iostream>
#include <vector>

using namespace std;

int newMaxInOrderedArray(const vector<int>&numbers){
    return numbers.front() > numbers.back() ? numbers.front() : numbers.back();
}

int classicMaxInOrderedArray(const vector<int>&numbers){
    int first=numbers[0];
    int last=numbers[numbers.size()-1];
    if(first>last)
        return first;
    return last;
}

/*
int main(){
    vector<int>numbers{1,2,3,4,5,6};
    cout<<newMaxInOrderedArray(numbers)<<endl;
    cout<<classicMaxInOrderedArray(numbers)<<endl;
    return 0;
}*/
