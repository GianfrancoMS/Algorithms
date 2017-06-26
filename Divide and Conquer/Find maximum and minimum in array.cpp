#include <iostream>
#include <vector>

using namespace std;

void minAndMax(const vector<int>&numbers, int i, int j, int&min, int&max){
    if(i<j-1){
        int med=(i+j)/2;
        int minUp,minLow,maxUp,maxLow=0;
        minAndMax(numbers,i,med,minLow,maxLow);
        minAndMax(numbers,med+1,j,minUp,maxUp);
        if(maxUp>maxLow)
            max=maxUp;
        else
            max=maxLow;
        if(minUp>minLow)
            min=minLow;
        else
            min=minUp;
    }
    else{
        if(i==j-1){
            if(numbers[i]>numbers[j]){
                max=numbers[i];
                min=numbers[j];
            }
            else{
                max=numbers[j];
                min=numbers[i];
            }
        }
        else
        {
            max=numbers[i];
            min=max;
        }
    }
}

/*
int main(){
    int min=0;
    int max=0;
    vector<int>numbers{4,4,2213,6112};
    minAndMax(numbers,0,numbers.size()-1,min,max);
    cout<<min<<endl;
    cout<<max<<endl;
    return 0;
}*/
