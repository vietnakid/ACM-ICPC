#include <bits/stdc++.h>
using namespace std;

long long n,mod,F[20005][5][5][5];

bool Free[20005][5][5][5];
char s[20005];

const int base = 1000000000;
const int base_digits = 9; 

struct bigint {
    vector<int> a;

    bigint(long long v) {
	    *this = v;
    }

    void operator=(const bigint &v) {
	    a = v.a;
    }

    void operator=(long long v) {
	a.clear();
	for (; v > 0; v = v / base)
	    a.push_back(v % base);
    }
 
    bigint operator+(const bigint &v) const {
        bigint res = v;
        for (int i = 0, carry = 0; i < (int) max(a.size(), v.a.size()) || carry; ++i) {
        if (i == (int) res.a.size())
            res.a.push_back(0);
        res.a[i] += carry + (i < (int) a.size() ? a[i] : 0);
        carry = res.a[i] >= base;
        if (carry)
            res.a[i] -= base;
        }
        return res;
    }

    friend ostream& operator<<(ostream &stream, const bigint &v) {
	stream << (v.a.empty() ? 0 : v.a.back());
	for (int i = (int) v.a.size() - 2; i >= 0; --i)
	    stream << setw(base_digits) << setfill('0') << v.a[i];
	return stream;
    }
};

vector<vector<vector<vector<bigint> > > > FBigInt;

inline long long f(int i,int j,int mi,int ma)
{
	if(Free[i][j][mi][ma]==true)
		return F[i][j][mi][ma];
	Free[i][j][mi][ma]=true;
	if(ma-mi>2)
		return F[i][j][mi][ma]=0;
	if(i==n+1)
		return F[i][j][mi][ma]=1;
	if(j>0)
		F[i][j][mi][ma]=(F[i][j][mi][ma]+f(i+1,j-1,min(mi,j-1),ma))%mod;
	if(j<4)
		F[i][j][mi][ma]=(F[i][j][mi][ma]+f(i+1,j+1,mi,max(ma,j+1)))%mod;
	return F[i][j][mi][ma];
}

inline bigint fbigint(int i,int j,int mi,int ma)
{
	if(Free[i][j][mi][ma]==true)
		return FBigInt[i][j][mi][ma];
	Free[i][j][mi][ma]=true;
	if(ma-mi>2) {
        FBigInt[i][j][mi][ma] = 0;
        return FBigInt[i][j][mi][ma];
    }
		
	if(i==n+1) {
        FBigInt[i][j][mi][ma] = 1;
        return FBigInt[i][j][mi][ma];
    }
		
	if(j>0)
		FBigInt[i][j][mi][ma]=(FBigInt[i][j][mi][ma]+fbigint(i+1,j-1,min(mi,j-1),ma));
	if(j<4)
		FBigInt[i][j][mi][ma]=(FBigInt[i][j][mi][ma]+fbigint(i+1,j+1,mi,max(ma,j+1)));
	return FBigInt[i][j][mi][ma];
}

int main()
{
    ios_base::sync_with_stdio(false);
	cin.tie();
	freopen("/Users/macbook/Desktop/PREVOIDALAT2018/FANS/Test06/FANS.INP", "r", stdin);
	freopen("/Users/macbook/Desktop/PREVOIDALAT2018/FANS/Test06/FANS.OUT", "w", stdout);
    // freopen("FANS.INP", "r", stdin);
	// freopen("FANS.OUT", "w", stdout);
    int TC;
    cin >> TC;
    while (TC--) {
        memset(Free, 0, sizeof(Free));
        memset(F, 0, sizeof(F));
        cin>>n>>mod>>(s+1);
        if (mod != 0) {
            long long res=1,sum=2,minn=2,maxn=2;
            for(int i=1;i<=n;++i)
            {
                if(s[i]=='M')
                    sum--;
                else
                    sum++;
                if(s[i]=='V'&&sum>=2)
                    res=(res+f(i+1,sum-2,min(minn,sum-2),maxn))%mod;
                minn=min(minn,sum);
                maxn=max(maxn,sum);
            }
            cout<< res << endl;
        } else {
            // struct bigint FBigInt[20005][5][5][5];
            FBigInt = vector<vector<vector<vector<bigint> > > >(2005, vector<vector<vector<bigint > > >(5, vector<vector<bigint > >(5, vector<bigint>(5, 0))));
            memset(Free, 0, sizeof(Free));
            long long sum=2,minn=2,maxn=2;
            bigint res = 1;
            for(int i=1;i<=n;++i)
            {
                if(s[i]=='M')
                    sum--;
                else
                    sum++;
                if(s[i]=='V'&&sum>=2)
                    res=(res+fbigint(i+1,sum-2,min(minn,sum-2),maxn));
                minn=min(minn,sum);
                maxn=max(maxn,sum);
            }
            cout<< res << endl;
        }
        
    }
	
}
