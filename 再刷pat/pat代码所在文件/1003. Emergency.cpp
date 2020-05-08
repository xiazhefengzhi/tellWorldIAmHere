
#include <bits/stdc++.h>
using namespace std;
int inf=99999999;
int main()
{
// 变量命名和值得输入
    int n,m,c1,c2;
    int dis[510],e[510][510],weight[510],w[510],num[510];
    bool visit[510]= {false};
    scanf("%d%d%d%d",&n,&m,&c1,&c2);
    for(int i=0; i<n; i++)
        scanf("%d",&weight[i]);
    fill(dis,dis+510,inf);
    fill(e[0],e[0]+510*510,inf);
    int a,b,c;
    for(int i=0; i<m; i++)
    {
        scanf("%d%d%d",&a,&b,&c);
        e[a][b]=e[b][a]=c;
    }

    dis[c1]=0;
    w[c1]=weight[c1];
    num[c1]=1;


    for(int i=0; i<n; i++)
    {
        int u=-1, minn=inf;
        for(int j=0; j<n; j++)
        {
            if(visit[j]==false && dis[j]<minn)
            {
                minn=dis[j];
                u=j;
            }
        }
    //  cout<<"visit "<<u <<"  "<<w[u]<<endl;
              visit[u]=true;
        for(int v=0; v<n; v++)
        {
            if(visit[v]==false&&e[u][v]!=inf){
             //  进行距离的判断
             if(dis[u]+e[u][v]<dis[v]){
                dis[v]=dis[u]+e[u][v];
                num[v]=num[u];
                w[v]=weight[v]+w[u];
             }
             else if(dis[u]+e[u][v]==dis[v]){
                if(weight[v]+w[u] >w[v]){
                    w[v]=weight[v]+w[u];
                }
                 num[v] = num[v] + num[u];

             }

            }

        }

    }
    printf("%d %d",num[c2],w[c2]);



    return 0;

}
