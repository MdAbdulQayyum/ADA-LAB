#include<stdio.h>

int s[10],top=0;
int visited[10],a[10][10];

void dfs(int v,int n){
    s[top++]=v;
    visited[v]=1;
    for(int i=0;i<n;i++){
        if(a[v][i] && !visited[i])
            dfs(i,n);
    }
}

int main(){
    int n,k;
    printf("Enter no of vertices: ");
    scanf("%d",&n);
    printf("Enter adjacency matrix:");
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            scanf("%d",&a[i][j]);
    printf("Enter starting vertex:");
    scanf("%d",&k);
    for(int i=0;i<n;i++)
        visited[i]=0;
    visited[k-1]=1;
    dfs(k-1,n);
    printf("Vertices from v is %d",k);
    for(int i=1;i<top;i++)
        printf(" v is %d",(s[i]+1));
    
    for(int i=0;i<n;i++)
        if(!visited[i]){
            printf("Graph is not connected");
            return 0;
        }
    printf("Graph is connected");
}