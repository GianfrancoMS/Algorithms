//
// Created by GianfrancoMS on 4/13/2017.
//
#include <iostream>
#include <vector>

using namespace std;

void averageElements(const vector<double>&A,vector<double>&B){
    for(int i=0;i<A.size();++i){
        double sum=0;
        for(int j=0;j<=i;++j)
            sum+=A[j];
        B[i]=sum/(i+1);
    }
}

/*int main(){
    vector<double >A{1,2,3,4,5,6,7,8,9,10};
    vector<double>B(10);
    averageElements(A,B);
    for(auto element: B)
        cout<<element<<endl;
    return 0;
}*/

