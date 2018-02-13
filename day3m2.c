#include<stdio.h> //standard input output
#include<stdlib.h> //library
#include<string.h> // string operations
#include<ctype.h>
#include<math.h>
int main ()
{
char word[5], line[100],atm_nm[4],x[9],y[9],z[9],slno[6],ch_id[20000],store_atm_nm[20000][4], store_res_nm[20000][4],res_nm[4],res_no[5];
FILE *f1,*f2; 
int i,j,c1=0,store_slno[20000],store_res_no[20000],P[20000],R[20000],p=0,r=0;
float store_x[20000],store_y[20000],store_z[20000],percent[5],distance=0.0;
f1 = fopen("1asy.pdb","r"); 
f2 = fopen ("output3_2.pdb","w");
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
		for(i=0;i<8;i++)
		x[i]=line[30+i];
		x[8]='\0';
		store_x[c1]=atof(x);
                for(i=0;i<8;i++)
                y[i]=line[38+i];
                y[8]='\0';
                store_y[c1]=atof(y);
		for(i=0;i<8;i++)
                z[i]=line[46+i];
                z[8]='\0';
                store_z[c1]=atof(z);
if(ch_id[c1]=='R')
{R[r]=c1;
r++;}
if(ch_id[c1]=='A')
{P[p]=c1;
p++;}
c1++;
}//end of if
}//end of while
fprintf(f2,"Protein atom Name,Atom number,name,res no------RNA atom name,atom number,res name,res number     distance\n");
//to calculate distance
for(i=0;i<p;i++)
{
for(j=0;j<r;j++)
{
distance=sqrtf ( (store_x[P[i]]-store_x[R[j]])*(store_x[P[i]]-store_x[R[j]])+(store_y[P[i]]-store_y[R[j]])*(store_y[P[i]]-store_y[R[j]])+(store_z[P[i]]-store_z[R[j]])*(store_z[P[i]]-store_z[R[j]]) );
if(distance<=4.5)
{fprintf(f2,"%s  %5d %s %4d ----- %s  %5d %s %4d     %8.3f \n",store_atm_nm[P[i]],store_slno[P[i]],store_res_nm[P[i]],store_res_no[P[i]],store_atm_nm[R[j]],store_slno[R[j]],store_res_nm[R[j]],store_res_no[R[j]],distance);}
}
}
fclose(f1);
return 0;
}
