/*
  Author: MEHEDI ISLAM REMON
  AUST CSE 44th Batch
*/
#include<bits/stdc++.h>
#define ll      int
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

// Returns the maximum value that
// can be put in a knapsack of capacity W
int knapSack(int W, int wt[], int val[], int n)
{
    int i, w;
    vector<vector<int> > K(n + 1, vector<int>(W + 1));

    // Build table K[][] in bottom up manner
    for (i = 0; i <= n; i++)
    {
        for (w = 0; w <= W; w++)
        {
            if (i == 0 || w == 0)
                K[i][w] = 0;
            else if (wt[i - 1] <= w)
                K[i][w] = max(val[i - 1]
                              + K[i - 1][w - wt[i - 1]],
                              K[i - 1][w]);
            else
                K[i][w] = K[i - 1][w];
        }
    }
    return K[n][W];
}

int main()
{
    fast;


    ll n,x;
    cin>>n>>x;
    int wt[n],cost[n];
    for(ll i=0; i<n; i++)
    {
        cin>>wt[i];
    }
    for(ll i=0; i<n; i++)
    {
        cin>>cost[i];
    }
    cout<<knapSack(x,wt,cost,n)<<endl;


}
