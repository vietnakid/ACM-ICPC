 #include <bits/stdc++.h>

using namespace std;

int x[300],t[300],n, res = 0;
void khoitao()
{
      printf("\nNhap n = ");
      scanf("%d",&n);
      x[0]=1;
      t[0]=0;
}
void xuat(int k)
{
      printf("\n%d = ",n);
      for (int i=1;i<k;i++) printf(" %d + ",x[i]);
      printf(" %d",x[k]);
}
void phantich(int i)
{
      for(int j=x[i-1];j<=((n-t[i-1])/2);j++)
      {
            x[i]=j;
            t[i]=t[i-1]+j;
            phantich(i+1);
      }
      x[i]=n-t[i-1];
      res += 1;
}

int main()
{
      khoitao();
      phantich(1);
      cout << res;
}