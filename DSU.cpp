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
int par[mxn];
int size[mxn];
void make(int v)
{
	par[v]=v;
	size[v]=1;
}
int find(int v)
{
	if(v==par[v])return v;
	return par[v]=find(par[v]);
}
void Union(int a,int b)
{
	a=find(a);
	b=find(b);
	if(a!=b)
	{
		if(size[a]<size[b])swap(a,b);
		par[b]=a;
		size[a]+=size[b];
	}
}
signed main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int n,k;
    cin>n>>k;
    for(int i=1;i<=n;i++)make(i);
    while(k--)
    {
    	int u,v;
    	cin>>u>>v;
    	Union(u,v);
    } 

}

