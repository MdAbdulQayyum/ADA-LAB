#include<stdio.h>

int q[10],r=0,f=0;
int a[10][10],visited[10];

void bfs(int v,int n){
    for(int i=0;i<n;i++)
        if(a[v][i] && !visited[i]){
            q[r++]=i;
            visited[i]=1;
        }
    if(f<=r)
        bfs(q[f++],n);
}

int main(){
    int n,k;
    printf("Enter no of vertices:");
    scanf("%d",&n);
    printf("Enter adjacency matrix:");
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            scanf("%d",&a[i][j]);
    printf("Enter starting vertex:");
  scanf("%d",&k);
    visited[k-1]=1;
    for(int i=0;i<n;i++)
        visited[i]=0;
    printf("Nodes visited from v is %d",k);
    bfs(k-1,n);
    for(int i=0;i<r;i++)
      printf(" v is %d",(q[i]+1));
}