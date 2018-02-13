#include<stdio.h> //standard input output
#include<stdlib.h> //library
#include<string.h> // string operations
#include<ctype.h>
int main ()
{
char word[5], line[100],atm_nm[4],x[9],y[9],z[9],slno[6],ch_id[20000],store_atm_nm[20000][4], store_res_nm[20000][4],res_nm[4],res_no[5];
FILE *f1,*f2; 
int i,c1=0,c2=0,store_slno[20000],store_res_no[20000],s0=0,s1=0,s2=0,s3=0,s4=0;
float store_x[20000],store_y[20000],store_z[20000],percent[5];
f1 = fopen("3fe0.pdb","r"); 
f2 = fopen ("output3.pdb","w");
/* download the lysosyme structure from PDb file.
Read the atomic coordinates from Pdb file
Store the coordinate in an array
Write into a new file the coordinates in PDb file.
Calculate the c.m.
Display the structure with c.m. in PyMoL. 
*/
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

c1++;
}//end of if
}//end of while
for(i=0;i<c1;i++)
fprintf(f2,"ATOM  %5d  %s %s %c%4d    %8.3f%8.3f%8.3f\n",store_slno[i],store_atm_nm[i],store_res_nm[i],ch_id[i],store_res_no[i],store_x[i],store_y[i],store_z[i]);
//to calculate score
s0=1;
for(i=1;i<c1;i++)
{if(store_res_no[i]>store_res_no[i-1])
	{
	if(strcmp(store_res_nm[i],"LYS")==0||strcmp(store_res_nm[i],"ARG")==0)
	{s0++;}
	else if(strcmp(store_res_nm[i],"ASP")==0||strcmp(store_res_nm[i],"GLU")==0)
	{s1++;}
	else if(strcmp(store_res_nm[i],"TYR")==0||strcmp(store_res_nm[i],"TRP")==0||strcmp(store_res_nm[i],"PHE")==0)
	{s2++;}
	else if(strcmp(store_res_nm[i],"SER")==0||strcmp(store_res_nm[i],"THR")==0||strcmp(store_res_nm[i],"HIS")==0||strcmp(store_res_nm[i],"ASN")==0||strcmp(store_res_nm[i],"GLN")==0||strcmp(store_res_nm[i],"MET")==0||strcmp(store_res_nm[i],"CYS")==0)
	{s3++;}
	else
	{s4++;}
	}
}

percent[0]=(float)s0*100/(s0+s1+s2+s3+s4);
percent[1]=(float)s1*100/(s0+s1+s2+s3+s4);
percent[2]=(float)s2*100/(s0+s1+s2+s3+s4);
percent[3]=(float)s3*100/(s0+s1+s2+s3+s4);
percent[4]=(float)s4*100/(s0+s1+s2+s3+s4);
  
fprintf(f2,"ATOM   9999  Zn  Zn  Z 9999   %d   %d   %d   %d   %d\n",s0,s1,s2,s3,s4);  
fprintf(f2,"ATOM   9999  Zn  Zn  Z 9999   %8.3f%8.3f%8.3f%8.3f%8.3f\n",percent[0],percent[1],percent[2],percent[3],percent[4]);
fclose(f1);
return 0;
}
