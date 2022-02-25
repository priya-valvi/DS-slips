
#include<stdio.h>
#include<conio.h>
void main()
{
int edges,i,j,tail,head,gtype,adj[10][10],n;

printf("Enter number of nodes : ");
scanf("%d",&n);
for(i=1;i<=n;i++)
{
for(j=1;j<=n;j++)
{
adj[i][j]=0;  //Initialize the array of n*n size with 0
}
}
edges=n*(n-1);  //maximum no. of edges in directed
printf("\nEnter -1 -1 to exit\n\n");
for(i=1;i<=edges;i++)
{
printf("Edge %d : ",i);
scanf("%d %d",&tail,&head);
if(tail==-1||head==-1)
break;
if(tail>n||head>n||tail<=0||head<=0)
{
printf("Invalid edge!\n");
i--;
}
else
adj[tail][head]=1;
}
printf("\nAdjacency Matrix \n\n");
for(i=1;i<=n;i++)
{
for(j=1;j<=n;j++)
{
printf("\t%d",adj[i][j]);
}
printf("\n");
}
getch();
}
