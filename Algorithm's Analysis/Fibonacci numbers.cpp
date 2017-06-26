#include <iostream>
#include <vector>

using namespace std;

int classicFibonacci(int position){
    if(position==0||position==1)
        return 1;
    return classicFibonacci(position-2)+classicFibonacci(position-1);
}

int iterativeFibonacci(int position){
    if(position==0||position==1)
        return 1;
    int n0=1;
    int n1=1;
    int n2=0;
    for(int i=2;i<=position;++i){
        n2=n1+n0;
        n0=n1;
        n1=n2;
    }
    return n2;
}

//Dynamic Programming
int topDownFibonacci(int position, vector<int>&fibonnaci){
    if(position==0||position==1)
        return 1;
    else if(fibonnaci[position]!=0)
        return fibonnaci[position];
    else{
        fibonnaci[position]=topDownFibonacci(position-2,fibonnaci)+
                            topDownFibonacci(position-1,fibonnaci);
        return fibonnaci[position];
    }
}

//Dynamic Programming
int bottomUpFibonacci(int position){
    if(position==0||position==1)
        return 1;
    vector<int>fibonacci(position+1,1);
    for(int i=2; i<=position;++i){
        fibonacci[i]=fibonacci[i-2]+fibonacci[i-1];
    }
    return fibonacci[position];
}

/*
int main(){
    int position=0;
    cin>>position;
    vector<int>fibonacci(position+1,0);
    cout<<"1: "<<classicFibonacci(position)<<endl;
    cout<<"2: "<<iterativeFibonacci(position)<<endl;
    cout<<"3: "<<topDownFibonacci(position,fibonacci)<<endl;
    cout<<"4: "<<bottomUpFibonacci(position)<<endl;
    return 0;
}*/
