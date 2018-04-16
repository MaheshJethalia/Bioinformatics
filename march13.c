#include<stdio.h>
#include<stdlib.h> 
#include<string.h> 
#include<ctype.h> 
#include<math.h> 
int main()
{
int match,mismatch,gap,i,j,l1=0,l2=0,score,c1,c2,c3,l3=0,l4=0;
char seq1[10],seq2[10];
char alnseq1[30],alnseq2[30];
printf("\nEnter Match Score:");
scanf("%d",&match);
printf("\nEnter MisMatch Score:");
scanf("%d",&mismatch);
printf("\nEnter GAP Score:");
scanf("%d",&gap);
printf("\nEnter First sequence:");
scanf("%s",seq1);
printf("\nEnter Second sequence:");
scanf("%s",seq2);
for(i=0;seq1[i]!='\0';i++)
{
l1++;
}
for(i=0;seq2[i]!='\0';i++)
{
l2++;
}
int a[l1+1][l2+1],b[l1+1][l2+1];
// initialize matix and ptr?
// Filling initially
for(i=0;i<l1+1;i++)
{
for(j=0;j<l2+1;j++)
{
if(i==0)
a[i][j]=gap*j;
else if(j==0)
a[i][j]=gap*i;
else
a[i][j]=0;
b[i][j]=9;
}
}
// matrix filling
for(i=1;i<l1+1;i++)
{
for(j=1;j<l2+1;j++)
{
if(seq1[i-1]==seq2[j-1])
score=match;
else
score=mismatch;
c1=a[i-1][j-1]+score;
c2=a[i-1][j]+gap;
c3=a[i][j-1]+gap;
if(c1>=c2 && c1>=c3)
{
a[i][j]=c1;
b[i][j]=0;
}
if(c2>=c1&&c2>=c3)
{
a[i][j]=c2;
b[i][j]=1;
}
if(c3>=c1 && c3>=c2)
{
a[i][j]=c3;
b[i][j]=-1;
}
}
}
printf("\n");
for(i=0;i<l1+1;i++)
{
for(j=0;j<l2+1;j++)
{
printf("%d ",a[i][j]);
}
printf("\n");
}
for(i=0;i<l1+1;i++)
{
for(j=0;j<l2+1;j++)
{
printf("%d ",b[i][j]);
}
printf("\n");
}
// traceback to get alignments.
printf("Aligned sequences are: \n");
i=l1;
j=l2;
while(i&&j)
{
if(b[i][j]==0)
{
alnseq1[l3]=seq1[i-1];
alnseq2[l4]=seq2[j-1];
i--;
j--;
}
if (b[i][j]==1)
{
alnseq1[l3]=seq1[i-1];
alnseq2[l4]='-';
i--;
}
if(b[i][j]==-1)
{
alnseq1[l3]='-';
alnseq2[l4]=seq2[j-1];
j--;
}
l3++;
l4++;
}
alnseq1[l3]='/0';
alnseq2[l4]='/0';
for(i=l3-1;i>=0;i--)
printf("%c",alnseq1[i]);
printf("\n");
for(i=l4-1;i>=0;i--)
printf("%c",alnseq2[i]);
printf("\n");
getch();
return 0;
}

