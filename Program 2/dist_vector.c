#include<stdio.h>

struct node
{
int d[20],s[20];
}r[10];

int main()
{
int cost[20][20],n,i,j,k,count=0;
printf("Enter the number of nodes\n");
scanf("%d",&n);
printf("Enter the cost matrix\n");
for(i=0;i<n;i++)
for(j=0;j<n;j++)
{
scanf("%d",&cost[i][j]);
cost[i][i]=0;

r[i].d[j]=cost[i][j];
r[i].s[j]=j;
}

do
{
count=0;
for(i=0;i<n;i++)
for(j=0;j<n;j++)
for(k=0;k<n;k++)
if(r[i].d[j]>cost[i][k]+r[k].d[j])
{
r[i].d[j]=r[i].d[k]+r[k].d[j];
r[i].s[j]=k;
count++;
}
}while(count!=0);
for(i=0;i<n;i++)
{
printf("\n For router %d\n",i+1);
for(j=0;j<n;j++)
printf("\tnode %d <-(via)%d distance %d\n",j+1,r[i].s[j]+1,r[i].d[j]);
}
return 0;
}

