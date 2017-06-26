#include <iostream>

using namespace std;

int iterativeFactorial(int number){
    if(number==0||number==1)
        return 1;
    else if(number==2)
        return 2;
    else{
        int factorial=2;
        for(int i=3;i<=number;++i)
            factorial=factorial*i;
        return factorial;
    }
}

int recursiveFactorial(int number){
    if(number==0||number==1)
        return 1;
    return recursiveFactorial(number-1)*number;
}

/*
int main(){
    int number=0;
    cin>>number;
    cout<<iterativeFactorial(number)<<endl;
    cout<<recursiveFactorial(number)<<endl;
    return 0;
}*/
