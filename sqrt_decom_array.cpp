// Problem: E - Give Away
// Contest: Virtual Judge - Marathon on Square Root Decomposition+Mo's Algo
// URL: https://vjudge.net/contest/659646#problem/E
// Memory Limit: 1536 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

//Labib
#include <bits/stdc++.h>
#define nl "\n"
#define ll long long
#define all(x) x.begin(), x.end()
using namespace std;
const int M=1e9+7;
const int mxn=3e5;
const ll inf=1e18;
int n,q;
int arr[mxn];
int bucket;
int box[mxn];
void build()
{
	for(int i=0;i<n;i+=bucket)
	{
		for(int j=i;j<min(n,i+bucket);j++)
		{
			box[j]=arr[j];
		}
		sort(box+i,box+min(n,i+bucket));
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
			if(arr[i]>val)c++;
		}
		return c;
	}
	int c=0;
	for(int i=st*bucket;i<=en*bucket;i+=bucket)
	{
		int x=bucket-(upper_bound(box+i,box+min(n,i+bucket),val)-(box+i));
		c+=x;
	}
	//cout<<c<<" "<<st<<" "<<en<<nl;
	for(int i=l;i<st*bucket;i++)
	{
		if(arr[i]>val)c++;
	}
	for(int i=(en*bucket)+bucket;i<=r;i++)
	{
		if(arr[i]>val)c++;
	}
	return c;
}
void update(int p,ll val)
{
	arr[p]=val;
	int in=p/bucket;
	
	//cout<<in<<nl;
	//cout<<box[in].size()<<nl;
	for(int i=in*bucket;i<min(n,(in+1)*bucket);i++)
	{
		//box[in][c]=arr[i];
		//cout<<c<<" ";
		box[i]=arr[i];
		
	}
	//sort(all(box[in]));
	 sort(box+in*bucket,box+min(n,(in+1)*bucket));
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    
    cin>>n;
    for(int i=0;i<n;i++)cin>>arr[i];
    cin>>q;
    bucket=max(1,(int)sqrt(n));
    build();
    while(q--)
    {
    	int t;
    	cin>>t;
    	if(t==0)
    	{
    		int l,r,val;
    		cin>>l>>r>>val;
    		l--;
    		r--;
    		cout<<query(l,r,val)<<nl;
    	}
    	else
    	{
    		int p,val;
    		cin>>p>>val;
    		p--;
    		//cout<<p<<" "<<val<<nl;
    		update(p,val);
    	}
    }

}

