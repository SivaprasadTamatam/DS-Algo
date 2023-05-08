/*
    Basic understanding of time complexity calculation.
*/

#include<iostream>
using namespace std;

int LinearFunction(int n){
    int res = 0;

    for(int i = 1; i<= n; i++){
        res += 1;
    }
    return res;
}

int QuadFunction(int n){
    int res = 0;
    for(int i= 1; i<=n; i++){
        for(int j=1; j<=n; j++){
            res +=1;
        }
    }

    return res;
}


int main(){
    static const int N = 10;
    int n = LinearFunction(N);

    if (n == N){
        cout<<"LinearFunction TC is big O(N)"<<endl;
    }

    int m = QuadFunction(N);
    cout<<m<<endl;
    if( m == N * N){
         cout<<"QuadFunction TC is big O(N^2)"<<endl;
    }

}