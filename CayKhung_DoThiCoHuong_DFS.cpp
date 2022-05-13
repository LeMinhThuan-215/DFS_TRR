#include <bits/stdc++.h>

using namespace std;

int n,m;
vector<int>adj[105];
bool visit[105];

void inp()
{
    cin>>n>>m;
    while(m--)
    {
        char a,b;
        cin>>a>>b;
        int u = a - 'a' + 1;
        int v = b - 'a' + 1;
        adj[u].push_back(v);
    }
}
bool ok = true; /// cây khung chỉ có 1 đỉnh
void dfs(int u)
{
    visit[u] = true;
    ///adj[u] là vector chứa các đỉnh v
    ///(u,v) là cung
    for(int v:adj[u])
        if(!visit[v])
        {
            cout<<char(u-1 + 'a')<<' '<<char(v-1 + 'a')<<'\n';
            ok = false;
            dfs(v);
        }
}
int main()
{
    freopen("txt.inp","r",stdin);
    /// mn tạo file txt.inp
    /// nhập vào số đỉnh, số cung
    /// nhập các cung (vd a b là cung a b)

    freopen("txt.out","w",stdout);

    inp();
    for(int u=1; u<=n; ++u)
    {
        if(!visit[u])
        {
            ok=true;
            dfs(u);
            if(ok)
                cout<<char(u-1+'a');
            cout<<"\n\n";
        }
    }
    return 0;
}
