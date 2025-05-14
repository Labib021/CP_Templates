#include <bits/stdc++.h>
#define fastread() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define nl "\n"
#define int long long
#define all(x) x.begin(), x.end()
using namespace std;
const int M=1e9+7;

vector<int> segT;

void build(int arr[],int start,int end,int node)
{
	if(start==end)
	{
		segT[node]=arr[start];
		return;
	}
	int mid=(start+end)/2;
	int l=2*node;
	int r=(2*node)+1;
	build(arr,start,mid,l);
	build(arr,mid+1,end,r);
	segT[node]=segT[l]+segT[r];
}
void update(int arr[],int start,int end,int node,int pos,int val)
{
	if(start==end)
	{
		arr[pos]=val;
		segT[node]=val;
		return;
	}
	int mid=(start+end)/2;
	if(mid>=pos)update(arr,start,mid,2*node,pos,val);
	else update(arr,mid+1,end,(2*node)+1,pos,val);
	segT[node]=segT[2*node]+segT[(2*node)+1];
}

int query(int start,int end,int node,int l,int r)
{
	if(start>=l && end<=r)return segT[node];
	if(l>end || r<start)return 0;
	
	int mid=(start+end)/2;
	int left=node*2;
	int right=(node*2)+1;
	if(r<=mid)return query(start,mid,left,l,r);
	else if(l>mid)return query(mid+1,end,right,l,r);
	else
	{
		int lans=query(start,mid,left,l,mid);
		int rans=query(mid+1,end,right,mid+1,r);
		return lans+rans;
	}
	
}

signed main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int t=1;
    cin>>t;
    while (t--)
    {
    	int n;
    	cin>>n;
    	segT.resize(4*n+1);
    	//vector<int> arr(n);
    	int arr[n];
    	for(int i=0;i<n;i++)cin>>arr[i];
    	build(arr,0,n-1,1);
    	cout<<"SegTree: ";
    	for(auto i:segT)cout<<i<<" ";
    	cout<<nl;
    	cout<<query(0,n-1,1,0,2)<<nl;
    	update(arr,0,n-1,1,1,3);
    	cout<<"SegTree: ";
    	for(auto i:segT)cout<<i<<" ";
    	cout<<nl;
    	cout<<query(0,n-1,1,0,2)<<nl;
    	
    	


    }


}

