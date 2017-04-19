//
// Created by GianfrancoMS on 4/14/2017.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int>largeNumber(int number){

    vector<int>result;
    while(number>0){
        result.push_back(number%10);
        number/=10;
    }
    return result;
}

vector<int> add(vector<int> min,vector<int> max) {
    if (max.size() < min.size()) {
        max.swap(min);
    }

    vector<int> sum;
    int rest = 0;

    for (int i = 0; i < min.size(); ++i) {
        int c = min[i] + max[i] + rest;
        sum.push_back(c % 10);
        rest = c / 10;
    }

    for (int i = min.size(); i < max.size(); ++i) {
        int c = max[i] + rest;
        sum.push_back(c % 10);
        rest = c / 10;
    }

    while (rest > 0) {
        sum.push_back(rest % 10);
        rest /= 10;
    }

    return sum;
}

vector<int> multiply(vector<int> min, vector<int> max) {
    if (max.size() < min.size()) {
        max.swap(min);
    }

    vector<vector<int>> sums;
    vector<int> sum;

    for (int i = 0; i < min.size(); i++) {
        sum.resize(0);
        int n = i;

        while (n > 0) {
            sum.push_back(0);
            n--;
        }

        int rest = 0;

        for (int j = 0; j < max.size(); j++) {
            int c = max[j] * min[i] + rest;
            sum.push_back(c % 10);
            rest = c / 10;
        }

        while (rest > 0) {
            sum.push_back(rest % 10);
            rest /= 10;
        }
        sums.push_back(sum);
    }

    sum.resize(0);

    for (int i = 0; i < sums.size(); i++)
        sum = add(sum, sums[i]);

    return sum;
}

/*
int main(){
    vector<int>A=largeNumber(850);
    vector<int>B=largeNumber(150);

    for(auto element: A)
        cout<<element;
    cout<<endl;

    for(auto element: B)
        cout<<element;
    cout<<endl;

    auto result=multiply(A,B);

    reverse(result.begin(),result.end());

    for(auto element: result)
        cout<<element;

    cout<<endl;
    return 0;
}*/