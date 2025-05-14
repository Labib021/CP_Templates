// Problem: C - Array Transformer
// Contest: Virtual Judge - Marathon on Square Root Decomposition+Mo's Algo
// URL: https://vjudge.net/contest/659646#problem/C
// Memory Limit: 1024 MB
// Time Limit: 5000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

//Labib
#include <bits/stdc++.h>
#define fastread() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define nl "\n"
//#define int long long
#define ll long long
#define all(x) x.begin(), x.end()
using namespace std;
const int M=1e9+7;
const int mxn=3e5+10;
//const int inf=1e18;
//const 
int bucket=560;
vector<int> box[560];
int arr[mxn];
int n,q,u;

void build()
{
	int c=0;
	for(int i=0;i<n;i+=bucket)
	{
		for(int j=i;j<min(i+bucket,n);j++)
		{
			box[c].push_back(arr[j]);
		}
		sort(all(box[c]));
		c++;
	}
}

int query(int l,int r,int val)
{
	int st=(l+bucket-1)/bucket;
	int en=(r-bucket+1)/bucket;
	//cout<<st<<" "<<en<<nl;
	if(en<=st)
	{
		int c=0;
		//cout<<l<<" "<<r<<nl;
		for(int i=l;i<=r;i++)
		{
			if(arr[i]<val)c++;
		}
		return c;
	}
	int c=0;
	for(int i=st;i<=en;i++)
	{
		int x=lower_bound(all(box[i]),val)-box[i].begin();
		c+=x;
	}
	//cout<<c<<" "<<st<<" "<<en<<nl;
	for(int i=l;i<st*bucket;i++)
	{
		if(arr[i]<val)c++;
	}
	for(int i=(en*bucket)+bucket;i<=r;i++)
	{
		if(arr[i]<val)c++;
	}
	return c;
}
void update(int p,ll val)
{
	arr[p]=val;
	int in=p/bucket;
	int j=in*bucket;
	int c=0;
	for(int i=in*bucket;i<min(n,j+bucket);i++)
	{
		box[in][c]=arr[i];
		c++;
	}
	sort(all(box[in]));
}

signed main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    cin>>n>>q>>u;
    for(int i=0;i<n;i++)cin>>arr[i];
    int a=sqrt(n);
    bucket=max(1,a);
    build();
    while(q--)
    {
    	int l,r,v,p;
    	cin>>l>>r>>v>>p;
    	l--;
    	r--;
    	p--;
    	int len=r-l+1;
    	ll x=query(l,r,v);
    	ll val=x*u;
    	val/=len;
    	update(p,val);
    	
    }
    for(int i=0;i<n;i++)cout<<arr[i]<<nl;
}

