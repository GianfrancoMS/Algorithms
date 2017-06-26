#include <iostream>
#include <vector>

using namespace std;

void insertionSort(vector<int>&numbers){
    for(int i=1;i<numbers.size()-1;++i){
        int temp=numbers[i];
        int k=i-1;
        while(k>=0 && numbers[k] > temp) {
            numbers[k+1]=numbers[k];
            --k;
        }
        numbers[k+1]=temp;
    }
}

/*
int main(){
    vector<int>numbers{1,3,4,-2,1,0};
    insertionSort(numbers);
    for(auto element: numbers)
        cout<<element<<" ";
    cout<<endl;
    return 0;
}*/
