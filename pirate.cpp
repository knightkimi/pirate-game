#include <stdlib.h>
#include <iostream>
using namespace std;

void indexsort(int n, int p[], int index[])
// bubble sort p[0..n-1]. p[] is unaltered. index[] is altered.
// p[index[0]] is the smallest of p[].
{
    int t;
    int newp[n]; //a copy of p[]
    for(int i=0;i<n;i++) newp[i]=p[i];
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(newp[j]>newp[j+1]){
                t=newp[j]; newp[j]=newp[j+1]; newp[j+1]=t;
                t=index[j]; index[j]=index[j+1]; index[j+1]=t;
            }
        }
    }
}

void cal(int n, int p[]){
// n pirates situation. return p[].
    for(int i=0;i<n;i++) p[i]=0;
    if(n==2){     // recursion initial value
        p[1]=100; p[0]=0;
    }
    else {
        cal(n-1, p);
        int give = (n-1)/2;  // the number of pirates out of n-1 who have to support the nth
        int sortedindex[n-1];
        for(int i=0;i<n-1;i++) sortedindex[i]=i;

        indexsort(n-1,p,sortedindex);

        for(int i=0;i<n-1;i++){
        // one more coin for give pirates . no coins for the others.
            if(i<give) p[sortedindex[i]]++;
            else p[sortedindex[i]]=0;
        }

        for(int i=0;i<n-1;i++) p[n-1]+=p[i];  // calculate how many is left.
        p[n-1]=100-p[n-1];
    }
}

int main()
{
    int number;
    cout<<"Number of pirates: ";
    cin>>number;
    int result[number];
    cal(number, result);
    for(int i=number-1;i>=0;i--) cout<<result[i]<<" ";
    int a;
    return 0;
}
