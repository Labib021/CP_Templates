#include <bits/stdc++.h>
#define fastread() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define nl "\n"
#define int long long
#define all(x) x.begin(), x.end()
using namespace std;
const int M=1e9+7;

vector<int> segT;
vector<int> lazy;

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
void update_range(int node,int start,int end,int l,int r,int val)
{
	if(lazy[node]!=0)
	{
		/// if add--> segT[node]+=(end-start+1)*lazy[node]
		/// if update---> segT[node]=(end-start+1)*lazy[node]
		segT[node]+=(end-start+1)*lazy[node];
		if(start!=end)
		{
			lazy[node*2]+=lazy[node];
			lazy[node*2+1]+=lazy[node];
		}
		lazy[node]=0;
		
	}
	if(start>end || start>r || end<l )return;///completly outiside
	if(start>=l && end<=r)
	{
		segT[node]+=(end-start+1)*val;
		if(start!=end)
		{
			lazy[2*node]+=val;
			lazy[2*node+1]+=val;
		}
		return;
	}
	int mid=(start+end)/2;
	update_range(node*2,start,mid,l,r,val);
	update_range(node*2+1,mid+1,end,l,r,val);
	segT[node]=segT[2*node]+segT[(2*node)+1];
}

int query_range(int node,int start,int end,int l,int r)
{
	if(start>end || start>r || end<l)return 0;
	
	if(lazy[node]!=0)
	{
		/// if add--> segT[node]+=(end-start+1)*lazy[node]
		/// if update---> segT[node]=(end-start+1)*lazy[node]
		segT[node]+=(end-start+1)*lazy[node];
		if(start!=end)
		{
			lazy[node*2]+=lazy[node];
			lazy[node*2+1]+=lazy[node];
		}
		lazy[node]=0;
		
	}
	if(start>=l && end<=r)return segT[node];
	
	
	int mid=(start+end)/2;
	
	int lans=query_range( node*2,start,mid,l,r);
	int rans=query_range(node*2+1, mid+1,end,l,r);
	return lans+rans;
}
/// clear lazy and segT in every test case
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
    	lazy.resize(4*n+1);
    	//vector<int> arr(n);
    	int arr[n];
    	for(int i=0;i<n;i++)cin>>arr[i];
    	build(arr,0,n-1,1);
    	cout<<"SegTree: ";
    	for(auto i:segT)cout<<i<<" ";
    	cout<<nl;
    	
    	


    }


}

