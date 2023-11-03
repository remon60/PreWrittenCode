
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl '\n'
const int N=100001;
int arr[N+1];
vector<int>dp[4*N+1];
vector<ll>dpr[4*N+1];
void build(int node,int l,int r){
    if(l==r){
        dp[node].push_back(arr[l]);
        dpr[node].push_back(arr[l]);
        // cout<<arr[l]<<endl;
        // cout<<l<<" "<<r<<endl;
        // cout<<endl;
    }else{
        int mid=(l+r)/2;
       int left=2*node,right=2*node+1;
       build(left,l,mid);
       build(right,mid+1,r);
       int i=0,j=0;
       while(i<dp[left].size() && j<dp[right].size()){
        if(dp[left][i]<dp[right][j]){
            dp[node].push_back(dp[left][i]);
            ++i;
        }else{
            dp[node].push_back(dp[right][j]);
            ++j;
        }
       }
        while(j<dp[right].size()){
            dp[node].push_back(dp[right][j]);
            ++j;
        }

        while(i<dp[left].size()){
            dp[node].push_back(dp[left][i]);
            ++i;
       }
       dpr[node].push_back(dp[node][0]);
       for(int i=1;i<dp[node].size();i++){
         ll c=dp[node][i]+dpr[node][i-1];
         dpr[node].push_back(c);
       }
       
    }
}
ll ssearch(int node,int l,int r,int i,int j,ll value){
    if(l>j || r<i)return 0;
    if(l>=i && r<=j){
        ll ans=-1;
        int low=0,high=dp[node].size()-1;
        while(high>=low){
            int mid=(high+low)/2;
            if(dp[node][mid]<value){
                ans=mid;
                low=mid+1;
            }else high=mid-1;
        }
        if(ans==-1)return 0;
        else{
           return (value*(ans+1))-dpr[node][ans];
        }
    }else{
        int mid=(r+l)/2;
        return 1ll*(ssearch(2*node,l,mid,i,j,value)+ssearch(2*node+1,mid+1,r,i,j,value));
    }
}
int main()
{
   ios_base:: sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

int n,q;
cin>>n>>q;
for(int i=0;i<n;i++)cin>>arr[i];
build(1,0,n-1);
while(q--){
    ll value;
    int a,b;
    cin>>a>>b>>value;
cout<<ssearch(1,0,n-1,a-1,b-1,value)<<endl; }
