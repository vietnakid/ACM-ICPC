#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define MAXN 100005
using namespace std;
vector < ll > survivalList(ll id,ll n){
    ll i ,firstOccur , p , q,Occur;
    vector < ll > vec;

    if( ( id & 1 )==0 )  return vec;

    for( i = 1 ; ; i ++ ){
        if(  ( ( 1LL<<i ) - 1 ) >= id){
            p = i - 1;
            q = ( 1LL << i) - 1 ;
            break;
        }
    }
    firstOccur = (q) - ( q - id ) / 2;
    Occur = firstOccur ;
    while(Occur <= n){
        vec.pb( Occur );
        Occur += (1LL<<p);
        p++;
    }
    return vec;
}

inline ll GCD(ll a, ll b) {while (b != 0) {ll c = a % b; a = b; b = c;} return a;};

int main(int argc , char *args[])
{
    ios_base::sync_with_stdio(false);
	cin.tie();
	freopen("/Users/macbook/Desktop/MyCPPLibrary/input", "r", stdin);
	freopen("/Users/macbook/Desktop/MyCPPLibrary/output", "w", stdout);
    int tc,cs=0;
    scanf("%d",&tc);
    while(tc--){
        long long x, l, n,ans_event=0,total_event=0;
        scanf("%lld %lld %lld",&x,&l,&n);
        total_event = n-l+1;
        ans_event = max(0LL, x - l );
        auto vec = survivalList(x,n);
        for(auto  v : vec){
            if( v >=l  and  v<= n) ans_event ++;
        }
        long long gcd = GCD(ans_event,total_event);
        ans_event/= gcd;
        total_event/=gcd;
        printf("Case %d: %lld/%lld\n",++cs,ans_event,total_event);
    }
    return 0;
}