#include<bits/stdc++.h>
using namespace std; 
#define ll long long
#define pb push_back
const int M=1e9;
const int N=1e6;
long long RAND(long long l,long long r)
{
    long long tmp=r-l+1;
    return l+rand()*1ll*rand()*1ll%tmp*rand()*1ll%tmp*rand()%tmp;
}
void gene(){
    srand(time(NULL));
    fstream fo;
    ll pre;
    for(int i=1;i<=10;i++){
        fo.open("C:\\Users\\Dell\\Desktop\\data\\test"+to_string(i)+".txt",ios::out);
        vector<ll> v(N);
        for(int j=0;j<N;j++)
            v[j]=RAND(-M,M);
        if(i==1)    sort(v.begin(),v.end());
        if(i==2)    sort(v.begin(),v.end(),greater<ll>());
        for(auto x:v)   fo<<x<<' ';
        fo.close();
    }
}