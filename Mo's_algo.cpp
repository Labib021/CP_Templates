
//Labib
#include <bits/stdc++.h>
#define fastread() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define nl "\n"
//#define int long long
#define all(x) x.begin(), x.end()
using namespace std;
const int M=1e9+7;
const int mxn=2e5+10;
 int n,q;
int box;
int arr[mxn];
int ans[mxn];
struct query
{
	int l,r,ind,k;
}qs[mxn];
int f[mxn];
int freq[mxn];
int mx=0;
void add(int ind)
{
	freq[f[arr[ind]]]--;
	
	if(freq[mx]<=0)mx--;
	f[arr[ind]]++;
	freq[f[arr[ind]]]++;
	if(freq[f[arr[ind]]])
	{
		mx=max(mx,f[arr[ind]]);
	}
}

void sub(int ind)
{
	freq[f[arr[ind]]]--;
	if(freq[mx]<=0)mx--;
	mx=max(0,mx);
	f[arr[ind]]--;
	f[arr[ind]]=max(0,f[arr[ind]]);
	freq[f[arr[ind]]]++;
	if(freq[f[arr[ind]]])
	{
		mx=max(mx,f[arr[ind]]);
	}
}
void sort_q()
{
	sort(qs,qs+q,[](query a,query b)
    {
    	if((a.l/box)!=(b.l/box)) return a.l<b.l;
    	return a.r<b.r;
    });
}

signed main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
   
    cin>>n>>q;
    int arr2[n];
    for(int i=0;i<n;i++)cin>>arr2[i];
    int c=1;
    map<int,int> mp;
    for(int i=0;i<n;i++)
    {
    	if(mp.find(arr2[i])==mp.end())
    	{
    		mp[arr2[i]]=c++;
    	}
    	arr[i]=mp[arr2[i]];
    }
    box=max((int)sqrt(n),1);
    
    for(int i=0;i<q;i++)
    {
    	int lq,rq,kq;
    	cin>>lq>>rq>>kq;
    	lq--;
    	rq--;
    	qs[i].l=lq;
    	qs[i].r=rq;
    	qs[i].k=kq;
    	qs[i].ind=i;
    }
    sort_q();
    
    int l=0;
    int r=0;
    for(int i=0;i<q;i++)
    {
    	while(r<=qs[i].r)add(r++);
    	while(r-1>qs[i].r)sub(--r);
    	while(l<qs[i].l)sub(l++);
    	while(l>qs[i].l)add(--l);
    	int len=qs[i].r-qs[i].l+1;
    	if((mx*qs[i].k)>=len)ans[qs[i].ind]=1;
    	else ans[qs[i].ind]=0;
    	
    	
    }
    for(int i=0;i<q;i++)
    {
    	if(ans[i])cout<<"YES"<<nl;
    	else cout<<"NO"<<nl;
    	//cout<<ans[i]<<nl;
    }
    


}

