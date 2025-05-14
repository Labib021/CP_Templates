//Labib
#include <bits/stdc++.h>
#define fastread() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define nl "\n"
#define int long long
#define all(x) x.begin(), x.end()
using namespace std;
const int M=1e9+7;
const int mxn=3e5;
const int inf=1e18;
int sp[mxn][20];
void build(int arr[],int n)
{
	for(int i=0;i<n;i++)sp[i][0]=arr[i];
	for(int j=1;j<20;j++)
	{
		for(int i=0;i<n;i++)
		{
			if((i+(1<<(j))-1)>=n)continue;
			sp[i][j]=min(sp[i][j-1],sp[i+(1<<(j-1))][j-1]);
		}
	}
}
int query(int l,int r)
{
	int sz=r-l+1;
	int pw=31-__builtin_clz(sz);
	int res=min(sp[l][pw],sp[r-(1<<pw)+1][pw]);
	return res;
}

signed main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int t=1;
    //cin>>t;
    int tc=1;
    while (t--)
    {
    	int n;
    	cin>>n;
    	int arr[n];
    	for(int i=0;i<n;i++)cin>>arr[i];
    	build(arr,n);
    	int q;
    	cin>>q;
    	while(q--)
    	{
    		int a,b;
    		cin>>a>>b;
    		cout<<query(a,b)<<nl;
    		
    	}


    }


}

