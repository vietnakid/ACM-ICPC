#include <stdio.h>
#include <queue>
using namespace std;

#define X first
#define Y second
typedef pair<int, int> ii;
vector<ii> a[230997];
int n, m;

int d[230997];
bool inqueue[230997];

void bellman(int u){
    int i, v, uv;
    queue<int> qu;

    for (i=1; i<=n; i++) d[i]=1000111000;
    d[u]=0;
    qu.push(u); inqueue[u]=true;

    while (qu.size()){
        u=qu.front(); inqueue[u]=false;
        qu.pop();

        for (i=0; v=a[u][i].Y; i++){
            uv=a[u][i].X;
            if (d[v]>d[u]+uv){
                d[v]=d[u]+uv;
                if (!inqueue[v]){
                    qu.push(v);
                    inqueue[v]=true;
                }
            }
        }
    }
}

main(){
    int p, q, w, i, u, v;
    scanf("%d%d%d%d", &n, &m, &u, &v);
    u++; v++;
    while (m--) {
        scanf("%d%d%d", &p, &q, &w);
        p++; q++;
        a[p].push_back(ii(w, q));
        a[q].push_back(ii(w, p));
    }
    for (i=1; i<=n; i++) a[i].push_back(ii(0,0));
    bellman(u);
    printf("%d\n", d[v]);
}
