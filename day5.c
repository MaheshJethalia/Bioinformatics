#include<stdio.h> //standard input output
#include<stdlib.h> //library
#include<string.h> // string operations
#include<ctype.h>
#include<math.h>
int main ()
{
char word[5], line[100],line2[147],x[5],slno[8],res_nm[4],ch_id[20000],ch_id1[20000],atm_nm[4],store_atm_nm[20000][4],store_atm_nm1[20000][4],store_res_nm[20000][4],store_res_nm1[20000][4];
FILE *f1,*f2,*f3,*f4,*f5,*f6,*f7,*f8,*f9; 
int i,c1=0,c2=0,store_slno[20000],store_slno1[20000];
float store_x[20000],store_x1[20000];
f1 = fopen("5un8.pdb","r"); 
f2 = fopen ("5un8-A.pdb","w");
f3 = fopen ("5un8-B.pdb","w");
f4 = fopen ("5un8-C.pdb","w");
f5 = fopen ("5un8-D.pdb","w");
f6 = fopen ("5un8-E.pdb","w");
f7 = fopen ("5un8-F.pdb","w");
f8 = fopen ("5un8-G.pdb","w");
f9 = fopen ("5un8-H.pdb","w");
while(fgets(line,100,f1)!=NULL)
{
	for(i=0;i<4;i++)
	word[i] = line[i];
	word[4]='\0';
	if( strcmp(word,"ATOM")==0)
	{
        if(line[21]=='A')
fprintf(f2,"%s\n",line);
        if(line[21]=='B')
fprintf(f3,"%s\n",line);
        if(line[21]=='C')
fprintf(f4,"%s\n",line);
	if(line[21]=='D')
fprintf(f5,"%s\n",line);
	if(line[21]=='E')
fprintf(f6,"%s\n",line);
	if(line[21]=='F')
fprintf(f7,"%s\n",line);
	if(line[21]=='G')
fprintf(f8,"%s\n",line);	
if(line[21]=='H')
fprintf(f9,"%s\n",line);
}
}
fclose(f1);
fclose(f2);
fclose(f3);
fclose(f4);
fclose(f5);
fclose(f6);
fclose(f7);
fclose(f8);
fclose(f9);
f1 = fopen("5un8.asa","r"); 
f2 = fopen("5un8-A.asa","r"); 
f3 = fopen("outputday5.asa","w");
while(fgets(line,147,f1)!=NULL)
{
for(i=0;i<4;i++)
	word[i] = line[i];
	word[4]='\0';
	if( strcmp(word,"Atom")==0)
	continue;
for(i=0;i<8;i++)
		slno[i]=line[i];
		slno[8]='\0';
		store_slno[c1]=atoi(slno);//store atom number
for(i=0;i<3;i++)
	atm_nm[i]=line[18+i];
	atm_nm[3]='\0';
	strcpy(store_atm_nm[c1],atm_nm);//store atom name
for(i=0;i<3;i++) 
		res_nm[i]=line[25+i];
		res_nm[3]='\0';
		strcpy(store_res_nm[c1],res_nm);//store residue name
ch_id[c1]=line[33];//CHAIN IDENTIFIER
for(i=0;i<5;i++)
		x[i]=line[62+i];
		x[5]='\0';
		store_x[c1]=atof(x);//sasa
c1++;
}
while(fgets(line2,147,f2)!=NULL)
{
for(i=0;i<4;i++)
	word[i] = line[i];
	word[4]='\0';
	if( strcmp(word,"Atom")==0)
	continue;
for(i=0;i<8;i++)
		slno[i]=line2[i];
		slno[8]='\0';
		store_slno1[c2]=atoi(slno);//store atom number
ch_id1[c1]=line2[33];//CHAIN IDENTIFIER
for(i=0;i<5;i++)
		x[i]=line2[62+i];
		x[5]='\0';
		store_x1[c2]=atof(x);//sasa
c2++;
}
for(i=0;i<c2;i++)
{
fprintf(f3,"%5d %s %s %c %4.2f\n",store_slno[i],store_atm_nm[i],store_res_nm[i],ch_id[i],store_x1[i]-store_x[i]);
fprintf(f3,"%5d %s %s %c %4.2f\n",store_slno1[i],store_atm_nm1[i],store_res_nm[i],ch_id[i],store_x1[i]-store_x[i]);
if(store_slno[i]==store_slno1[i])
{
fprintf(f3,"%5d %s %s %c %4.2f\n",store_slno[i],store_atm_nm[i],store_res_nm[i],ch_id[i],store_x1[i]-store_x[i]);
if((store_x[i]-store_x1[i])!=0)
{
fprintf(f3,"%5d %s %s %c %4.2f\n",store_slno[i],store_atm_nm[i],store_res_nm[i],ch_id[i],store_x1[i]-store_x[i]);
}
}
}
fclose(f1);
return 0;
}
