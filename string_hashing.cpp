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
int pw1[mxn+3];
int pw2[mxn+3];
int b1,b2,m1,m2;
int B1[15]={68749,23627,91621,613,3389,971,797,4339,5333,269,5821,1031,1583,1949,593};
int B2[15]={359,3719,6397,6211,5701,11743,677,1667,1759,947,733,5023,4547,4139,8831};
int M1[10]={131280223,132573641,172575217,175515731,125517299,121024213,121231897,121230377,151349167,151351111};
int M2[10]={111346687,141346033,101346859,131347813,191345867,161348821,171346753,151347593,181347541,161347471};
int binex(int a, int b,int m)
{                                         
    int ans=1;
    while (b)
    {
       if(b&1)ans=(ans*a)%m;
       b>>=1;
       a=(a*a)%m;
    }   
    return ans;
}
void pre()
{
	pw1[0]=pw2[0]=1;
	
	for(int i=1;i<mxn;i++)
	{
		pw1[i]=(pw1[i-1]*b1)%m1;
		pw2[i]=(pw2[i-1]*b2)%m2;
		
	}
}
int h1[mxn+2];
int h2[mxn+2];
void shash(string &s)
{
	int n=s.size();
	h1[0]=s[0]*pw1[0]%m1;
	h2[0]=s[0]*pw2[0]%m2;
	for(int i=1;i<n;i++)
	{
		h1[i]=((h1[i-1]*b1)%m1+s[i])%m1;
		h2[i]=((h2[i-1]*b2)%m2+s[i])%m2;
	}
	 
}
int get_hash(int l,int r)
{
	if(l==0)
	{
		int a=(h1[r]+m1)%m1;
		int b=(h2[r]+m2)%m2;
		return a<<32|b;
	}
	int x=(h1[r]-(h1[l-1]*pw1[r-l+1])%m1+m1)%m1;
	int y=(h2[r]-(h2[l-1]*pw2[r-l+1])%m2+m2)%m2;
	return x<<32|y;
}
/*
		srand(time(NULL));
		b1=B1[rand()%15];
		b2=B2[rand()%15];
		m1=M1[rand()%10];
		m2=M2[rand()%10];
		



*/

signed main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    srand(time(NULL));
    int t=1;
   // cin>>t;
    int tc=1;
    while (t--)
    {
    	
		b1=B1[rand()%15];
		b2=B2[rand()%15];
		m1=M1[rand()%10];
		m2=M2[rand()%10];
		


    }


}

