/*
  Author: MEHEDI ISLAM REMON
  AUST CSE 44th Batch
*/
#include<bits/stdc++.h>
#define ll      long long int
#define nline   "\n"
#define fast    ios_base::sync_with_stdio(0);cin.tie(0);cin.tie(nullptr); cout.tie(nullptr);
#define pb      push_back
#define pi      acos(-1)
#define Mod     1000000007
#define sn      10000000011
#define MAX     intONG_MAX
#define F       first
#define S       second
using namespace std;

vector<ll> kPermutation(ll n, ll k,ll start)
{
    ll fact=1;
    vector<ll>numbers;
    ll p=1;
    for(ll i=start; i<n; i++)
    {
        fact=fact*p;
        numbers.push_back(i);
        p++;
    }
    numbers.push_back(n);
    vector<ll>ans;
    //k=k-1;
    while(1)
    {
        ans.push_back(numbers[k/fact]);
        numbers.erase(numbers.begin()+k/fact);
        if(numbers.size()==0)
        {
            break;
        }
        k=k%fact;
        fact=fact/numbers.size();
    }
    return ans;
}

int main()
{
    fast;

    ll n,k;
    cin>>n>>k;
    if(n<=20)
    {
        vector<ll> ans=kPermutation(n,k,1);
        for(ll i=0; i<n; i++)
        {
            cout<<ans[i]<<" ";
        }
        cout<<endl;
    }
    else
    {
        ll pos=n-20;
        for(ll i=1; i<=pos; i++)
        {
            cout<<i<<" ";
        }
        vector<ll> ans=kPermutation(n,k,pos+1);
        for(ll i=0; i<20; i++)
        {
            cout<<ans[i]<<" ";
        }
        cout<<endl;
    }
}
