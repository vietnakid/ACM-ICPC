#include <bits/stdc++.h>
using namespace std;

#define int64_t long long

struct data
{
    int64_t u,v,w,type;
};

int64_t m,n,P,Q,MOD,A[100005],B[100005];
data Edge[600005];


int64_t Mul(int64_t a,int64_t b)
{
    int64_t rs=0;
    while(a>0)
    {
        if(a%2==1)
            rs=(rs+b)%MOD;
        a/=2;
        b=b*2LL%MOD;
    }
    return rs;
}

bool cmp(data x1,data x2)
{
    return x1.w<x2.w;
}

int64_t FindA(int64_t u)
{
    if(A[u]==u)
        return u;
    return A[u]=FindA(A[u]);
}

int64_t FindB(int64_t u)
{
    if(B[u]==u)
        return u;
    return B[u]=FindB(B[u]);
}

void UnionA(int64_t u,int64_t v)
{
    if(u>v)
        A[u]=v;
    else
        A[v]=u;
}

void UnionB(int64_t u,int64_t v)
{
    if(u>v)
        B[u]=v;
    else
        B[v]=u;
}

int main()
{
    ios_base::sync_with_stdio(false);
    //for(int64_t test=1; test<=40; test++)
    {
        //string file="";
        //file+=char(test/10+'0');
        //file+=char(test%10+'0');
        //freopen((file+".inp").c_str(),"r",stdin);
        //freopen((file+".out").c_str(),"w",stdout);
        // freopen("CONNECT.inp","r",stdin);
        //freopen("CONNECT.out","w",stdout);
        freopen("/Users/macbook/Desktop/MyCPPLibrary/input", "r", stdin);
	    freopen("/Users/macbook/Desktop/MyCPPLibrary/output", "w", stdout);
        freopen("/Users/macbook/Desktop/MyCPPLibrary/error", "w", stderr);
        cin>>m>>n>>P>>Q>>MOD;
        int64_t res=0;
        for(int64_t i=1; i<=P; i++)
        {
            cin>>Edge[i].u>>Edge[i].v>>Edge[i].w;
            //Edge[i].w%=MOD;
            Edge[i].type=0;
            res=(res+Mul(Edge[i].w,m))%MOD;
        }
        for(int64_t i=P+1; i<=P+Q; i++)
        {
            cin>>Edge[i].u>>Edge[i].v>>Edge[i].w;
            //Edge[i].w%=MOD;
            Edge[i].type=1;
            res=(res+Mul(Edge[i].w,n))%MOD;
        }
        sort(Edge+1,Edge+P+Q+1,cmp);
        for(int64_t i=1; i<=max(m,n); i++)
            A[i]=B[i]=i;
        int64_t tmpm=0,tmpn=0, cnt = 0;
        for(int64_t i=1; i<=P+Q; i++) {
            // cerr << Edge[i].u << " " << Edge[i].v << " " << Edge[i].w << endl;
            if(Edge[i].type==0)
            {
                if(FindA(Edge[i].u)!=FindA(Edge[i].v))
                {
                    cerr << "mulmod " << Edge[i].w << " " << m-tmpm << " " << Mul(Edge[i].w,(m-tmpm)) << endl;
                    // cerr << cnt << " 1 " << Mul(Edge[i].w,(m-tmpm)) << endl;
                    res=(res-Mul(Edge[i].w,(m-tmpm))+MOD)%MOD;
                    cnt = (cnt + Mul(Edge[i].w,(m-tmpm))) % MOD;
                    UnionA(FindA(Edge[i].u),FindA(Edge[i].v));
                    tmpn++;
                    // cerr << cnt << " 2 " << Mul(Edge[i].w,(m-tmpm)) << endl;å
                }
                
            }
            else
            {
                if(FindB(Edge[i].u)!=FindB(Edge[i].v))
                {
                    cerr << "mulmod " << Edge[i].w << " " << n-tmpn << " " << Mul(Edge[i].w,(n-tmpn)) << endl;
                    // cerr << cnt << " 1 " << Mul(Edge[i].w,(n-tmpn)) << endl;
                    res=(res-Mul(Edge[i].w,(n-tmpn))+MOD)%MOD;
                    cnt = (cnt + Mul(Edge[i].w,(n-tmpn))) % MOD;
                    UnionB(FindB(Edge[i].u),FindB(Edge[i].v));
                    tmpm++;
                    // cerr << cnt << " 2 " << Mul(Edge[i].w,(n-tmpn)) << endl;
                }
                
            }
        
    }
    cout<<res << endl;
    }
}
