#include <bits/stdc++.h>
using namespace std;
//ifstream fi("weight.inp");
//ofstream fo("weight.out");
int n,m;
long long a,b,c,par[100005],cost[100005],ans;
char s;
long long anc(long long p)
{
    if(par[p]==p)
        return p;
    else
    {
        long long tmp=anc(par[p]);
        cost[p]+=cost[par[p]];
        return par[p]=tmp;
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("/Users/macbook/Desktop/MyCPPLibrary/input", "r", stdin);
	freopen("/Users/macbook/Desktop/MyCPPLibrary/output", "w", stdout);
    freopen("/Users/macbook/Desktop/MyCPPLibrary/error", "w", stderr);
    while(cin>>n>>m)
    {
        if(n==0 && m==0)
            return 0;
        for(int i=1; i<=n; i++)
            par[i]=i,cost[i]=0;
        for(int i=1; i<=m; i++)
        {
            cin>>s;
            if(s=='!')
            {
                cin>>a>>b>>c;
                long long x=anc(a),y=anc(b);
                long long z=c+cost[a]-cost[b];
                par[x]=y;
                cost[x]=-z;
            }
            else
            {
                cin>>a>>b;
                if(anc(a)!=anc(b))
                    cout<<"UNKNOWN\n";
                else
                {
                    ans=cost[b]-cost[a];
                    cout<<ans<<"\n";
                }
            }
        }
    }
}
