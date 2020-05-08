#include<bits/stdc++.h>
using namespace std;
int n,m ;
vector<int>v[100];
int book[100];
int  maxdepth=-1;
void dfs(int node,int depth){
if(v[node].size()==0){
        cout<<"depth "<<depth<<endl;
     book[depth]++;
        maxdepth = max(maxdepth, depth);
        return ;
}
for(int i=0;i<v[node].size();i++){
    dfs(v[node][i],depth+1);
}

}
int main()
{

    scanf("%d%d",&n,&m);
    for(int i=0; i<m; i++)
    {
        int node,k;
        scanf("%d%d",&node,&k);
        for(int j=0; j<k; j++)
        {
            int c;
            scanf("%d",&c);
            v[node].push_back(c);
        }
}
        dfs(1,0);

        for(int i=0; i<maxdepth; i++)
        {
            if(i!=0)
                printf(" %d",book[i]);
            else
            {
                printf("%d",book[i]);
            }
        
    }


}
