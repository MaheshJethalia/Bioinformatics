#include<stdio.h> //standard input output
#include<stdlib.h> //library
#include<string.h> // string operations
#include<ctype.h>
#include<math.h>
int main ()
{
char word[5], line[100],atm_nm[4],x[9],y[9],z[9],slno[6],ch_id[20000],store_atm_nm[20000][4], store_res_nm[20000][4],res_nm[4],res_no[5],bf[5];
FILE *f1,*f2; 
int i,j,c1=0,store_slno[20000],store_res_no[20000],P[20000],R[20000],count_main=0,count_side=0,max=0,min=0;
float store_b[20000],b_main=0,b_side=0;
f1 = fopen("1oj6.pdb","r"); 
f2 = fopen ("output4.pdb","w");
while(fgets(line,100,f1)!=NULL)
{
	for(i=0;i<4;i++)
	word[i] = line[i];
	word[4]='\0';
	if( strcmp(word,"ATOM")==0)
	{
		for(i=0;i<5;i++)
		slno[i]=line[6+i];
		slno[5]='\0';
		store_slno[c1]=atoi(slno);//store atom number
	for(i=0;i<3;i++)
	atm_nm[i]=line[13+i];
	atm_nm[3]='\0';
	strcpy(store_atm_nm[c1],atm_nm);//store atom name
		for(i=0;i<3;i++) 
		res_nm[i]=line[17+i];
		res_nm[3]='\0';
		strcpy(store_res_nm[c1],res_nm);//store residue name
		ch_id[c1]=line[21];//CHAIN IDENTIFIER
		for (i=0;i<4;i++)
		res_no[i]=line[22+i];
		store_res_no[c1] = atoi(res_no);//residue number
		for (i=0;i<=4;i++)
		res_no[i]=line[61+i];
       		store_b[c1] = atoi(res_no);// b factor		
c1++;
}//end of if
}//end of while
fprintf(f2,"B Factor\n");
//to calculate B Factor
for(i=0;i<c1;i++)
	{
	if(ch_id[i+1]==ch_id[i])
		{
		if(strcmp(store_atm_nm[i],"N  ")==0||strcmp(store_atm_nm[i],"C  ")==0||strcmp(store_atm_nm[i],"CA ")==0||strcmp(store_atm_nm[i],"O  ")==0)
			{
			b_main=b_main+store_b[i];
			count_main++;			
			}
		else
			{
			if(b_side>b_max)
			b_ma
			b_side += store_b[i];
			count_side++;			
			}
		}
if(ch_id[i+1]!=ch_id[i])
{
b_main=b_main/count_main;b_side=b_side/count_side;
fprintf(f2,"For %c chain :- avg B Factor Main :%8.3f avg B Factor Side: %8.3f \n",ch_id[i],b_main,b_side);
b_side=0;b_main=0,count_main=0,count_side=0;
}
}
fclose(f1);
return 0;
}
