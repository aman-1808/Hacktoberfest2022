#include <bits/stdc++.h>

using namespace std;

const int N=1e5+7;
int t,T,n,m,i,z[N],l,r,k;
long long rez,d[N],D;
vector<pair<int, int>> a[N];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin>>T;
    for (t=0;t<T;++t)
    {
        rez=0;
        D=0;
        cin>>n>>m;
        for (i=0;i<n;++i) {cin>>z[i];}
        for (i=0;i<m;++i) {cin>>l>>r>>k; l--; r--; a[l].push_back(make_pair(r,k));}
        priority_queue<pair<int, int>> pq;
        for (i=0;i<n;++i)
        {
            for (auto j : a[i])
            {
                pq.push(j);
            }
            D-=d[i];
            z[i]-=D;
            while(z[i]>0)
            {
                if (pq.empty() || pq.top().first<i) {rez=-1; break;}
                pair<int, int> b=pq.top();
                int c=min(b.second,z[i]);
                pq.pop();
                D+=c;
                d[b.first+1]+=c;
                rez+=c;
                b.second-=c;
                if (b.second) {pq.push(make_pair(b.first,b.second));}
                z[i]-=c;
              }
            if (rez==-1) {break;}
        }
        if (rez==-1) {cout<<"NO\n";}
        else {cout<<"YES "<<rez<<"\n";}
        fill_n(a,N,vector<pair<int, int>>());
        fill_n(d,N,0LL);
    }
    return 0;
}
++
