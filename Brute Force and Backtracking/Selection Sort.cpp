//
// Created by GianfrancoMS on 4/13/2017.
//

#include <iostream>
#include <vector>

using namespace std;

void selectionSort(vector<int>&numbers){
    for(int i=0;i<numbers.size()-1;++i){
        int min=i;
        for(int j=i+1;j<numbers.size();++j){
            if(numbers[min]>numbers[j])
                min=j;
        }
        swap(numbers[i],numbers[min]);
    }
}

/*
int main(){
    vector<int>numbers{1,5,3,7,3,2};
    selectionSort(numbers);
    for(auto element: numbers)
        cout<<element<<" ";
    cout<<endl;
    return 0;
}*/
