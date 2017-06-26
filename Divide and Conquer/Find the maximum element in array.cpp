#include <iostream>
#include <vector>

using namespace std;

int max(const vector<int>&numbers, int i, int j){
    if(i==j)
        return numbers[i];
    else{
        int med=(i+j)/2;
        int maxLow=max(numbers,i,med);
        int maxUp=max(numbers,med+1,j);
        if(maxLow > maxUp)
            return maxLow;
        else
            return maxUp;
    }
}

int _max(const vector<int>&numbers, int i, int j){
    return max(numbers,i,j);
}

/*
    int main(){
    vector<int>numbers{5,1253,51221,100000};
    int max=_max(numbers,0,numbers.size()-1);
    cout<<max<<endl;
    return 0;
}*/
