#include <bits/stdc++.h>

using namespace std;

int n,m,a,b,ans=0;
bool visited[1001];
vector <int> v[1001];
queue <int> q;

void bfs(int a)
{
    ans+=1;
    while(!q.empty())
    {
        a=q.front();
        q.pop();
        for(int i=0;i<v[a].size();i++)
        {
            if(visited[v[a][i]]==false)
            {
                q.push(v[a][i]);
                visited[v[a][i]]=true;
            }
        }
    }
}

int main()
{
    cin >> n >> m;
    for(int i=0;i<m;i++)
    {
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    for(int i=1;i<=n;i++)
    {
        if(visited[i]==false)
        {
            q.push(i);
            visited[i]=true;
            bfs(i);
        }
    }
    cout << ans;
}
