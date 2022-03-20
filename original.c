#include<stdio.h> //standard input output
#include<stdlib.h> //library
#include<string.h> // string operations
#include<ctype.h>
#include<math.h>

int main ()
{
char word[5], line[100],atm_nm[4],x[9],y[9],z[9],slno[6],ch_id[20000],store_atm_nm[20000][4], store_res_nm[20000][4],res_nm[4],res_no[5];
FILE *f1,*f2; 
int i,j,c1=0,store_slno[20000],store_res_no[20000],B[20000],A[20000],C[20000],D[20000],E[20000],F[20000],b=0,a=0,c=0,d=0,e=0,f=0,count=0;
float store_x[20000],store_y[20000],store_z[20000],percent[5];
double distance=0.0;
f1 = fopen("Complex.pdb","r"); 
f2 = fopen ("Interacting_Residues.pdb","w");
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
                
		if(ch_id[c1]=='A')
		{
		A[a]=c1;
		a++;
		}
		if(ch_id[c1]=='B')
		{
		B[b]=c1;
		b++;
		}
		if(ch_id[c1]=='C')
		{
		C[c]=c1;
		c++;
		}
		if(ch_id[c1]=='D')
		{
		D[d]=c1;
		d++;
		}
		if(ch_id[c1]=='E')
		{
		E[e]=c1;
		e++;
		}
		if(ch_id[c1]=='F')
		{
		F[f]=c1;
		f++;
		}
		c1++;
}//end of if
}//end of while
fprintf(f2,"Protein atom Name,Atom number,name,res no------RNA atom name,atom number,res name,res number     distance\n");
//to calculate distance AB
for(i=0;i<a;i++)
{
for(j=0;j<b;j++)
{
distance=sqrtf(pow(store_x[A[i]]-store_x[B[j]],2)+pow(store_y[A[i]]-store_y[B[j]],2)+pow(store_z[A[i]]-store_z[B[j]],2));
if(distance<=4.5)
{
fprintf(f2,"%s  %5d %s %4d ----- %s  %5d %s %4d     %8.3f \n",store_atm_nm[A[i]],store_slno[A[i]],store_res_nm[A[i]],store_res_no[A[i]],store_atm_nm[B[j]],store_slno[B[j]],store_res_nm[B[j]],store_res_no[B[j]],distance);
count++;
}
}
}
//to calculate distance AC
for(i=0;i<a;i++)
{
for(j=0;j<c;j++)
{
distance=sqrtf(pow(store_x[A[i]]-store_x[C[j]],2)+pow(store_y[A[i]]-store_y[C[j]],2)+pow(store_z[A[i]]-store_z[C[j]],2));
if(distance<=4.5)
{
fprintf(f2,"%s  %5d %s %4d ----- %s  %5d %s %4d     %8.3f \n",store_atm_nm[A[i]],store_slno[A[i]],store_res_nm[A[i]],store_res_no[A[i]],store_atm_nm[C[j]],store_slno[C[j]],store_res_nm[C[j]],store_res_no[C[j]],distance);
count++;
}
}
}
//to calculate distance BC
for(i=0;i<b;i++)
{
for(j=0;j<c;j++)
{
distance=sqrtf(pow(store_x[B[i]]-store_x[C[j]],2)+pow(store_y[B[i]]-store_y[C[j]],2)+pow(store_z[B[i]]-store_z[C[j]],2));
if(distance<=4.5)
{
fprintf(f2,"%s  %5d %s %4d ----- %s  %5d %s %4d     %8.3f \n",store_atm_nm[B[i]],store_slno[B[i]],store_res_nm[B[i]],store_res_no[B[i]],store_atm_nm[C[j]],store_slno[C[j]],store_res_nm[C[j]],store_res_no[C[j]],distance);
count++;
}
}
}
//to calculate distance AD
for(i=0;i<a;i++)
{
for(j=0;j<d;j++)
{
distance=sqrtf(pow(store_x[A[i]]-store_x[D[j]],2)+pow(store_y[A[i]]-store_y[D[j]],2)+pow(store_z[A[i]]-store_z[D[j]],2));
if(distance<=4.5)
{
fprintf(f2,"%s  %5d %s %4d ----- %s  %5d %s %4d     %8.3f \n",store_atm_nm[A[i]],store_slno[A[i]],store_res_nm[A[i]],store_res_no[A[i]],store_atm_nm[D[j]],store_slno[D[j]],store_res_nm[D[j]],store_res_no[D[j]],distance);
count++;
}
}
}
//to calculate distance AE
for(i=0;i<a;i++)
{
for(j=0;j<e;j++)
{
distance=sqrtf(pow(store_x[A[i]]-store_x[E[j]],2)+pow(store_y[A[i]]-store_y[E[j]],2)+pow(store_z[A[i]]-store_z[E[j]],2));
if(distance<=4.5)
{
fprintf(f2,"%s  %5d %s %4d ----- %s  %5d %s %4d     %8.3f \n",store_atm_nm[A[i]],store_slno[A[i]],store_res_nm[A[i]],store_res_no[A[i]],store_atm_nm[E[j]],store_slno[E[j]],store_res_nm[E[j]],store_res_no[E[j]],distance);
count++;
}
}
}
//to calculate distance AF
for(i=0;i<a;i++)
{
for(j=0;j<f;j++)
{
distance=sqrtf(pow(store_x[A[i]]-store_x[F[j]],2)+pow(store_y[A[i]]-store_y[F[j]],2)+pow(store_z[A[i]]-store_z[F[j]],2));
if(distance<=4.5)
{
fprintf(f2,"%s  %5d %s %4d ----- %s  %5d %s %4d     %8.3f \n",store_atm_nm[A[i]],store_slno[A[i]],store_res_nm[A[i]],store_res_no[A[i]],store_atm_nm[F[j]],store_slno[F[j]],store_res_nm[F[j]],store_res_no[F[j]],distance);
count++;
}
}
}
//to calculate distance BD
for(i=0;i<b;i++)
{
for(j=0;j<d;j++)
{
distance=sqrtf(pow(store_x[B[i]]-store_x[D[j]],2)+pow(store_y[B[i]]-store_y[D[j]],2)+pow(store_z[B[i]]-store_z[D[j]],2));
if(distance<=4.5)
{
fprintf(f2,"%s  %5d %s %4d ----- %s  %5d %s %4d     %8.3f \n",store_atm_nm[B[i]],store_slno[B[i]],store_res_nm[B[i]],store_res_no[B[i]],store_atm_nm[D[j]],store_slno[D[j]],store_res_nm[D[j]],store_res_no[D[j]],distance);
count++;
}
}
}
//to calculate distance BE
for(i=0;i<b;i++)
{
for(j=0;j<e;j++)
{
distance=sqrtf(pow(store_x[B[i]]-store_x[E[j]],2)+pow(store_y[B[i]]-store_y[E[j]],2)+pow(store_z[B[i]]-store_z[E[j]],2));
if(distance<=4.5)
{
fprintf(f2,"%s  %5d %s %4d ----- %s  %5d %s %4d     %8.3f \n",store_atm_nm[B[i]],store_slno[B[i]],store_res_nm[B[i]],store_res_no[B[i]],store_atm_nm[E[j]],store_slno[E[j]],store_res_nm[E[j]],store_res_no[E[j]],distance);
count++;
}
}
}
//to calculate distance BF
for(i=0;i<b;i++)
{
for(j=0;j<f;j++)
{
distance=sqrtf(pow(store_x[B[i]]-store_x[F[j]],2)+pow(store_y[B[i]]-store_y[F[j]],2)+pow(store_z[B[i]]-store_z[F[j]],2));
if(distance<=4.5)
{
fprintf(f2,"%s  %5d %s %4d ----- %s  %5d %s %4d     %8.3f \n",store_atm_nm[B[i]],store_slno[B[i]],store_res_nm[B[i]],store_res_no[B[i]],store_atm_nm[F[j]],store_slno[F[j]],store_res_nm[F[j]],store_res_no[F[j]],distance);
count++;
}
}
}

//to calculate distance CD
for(i=0;i<c;i++)
{
for(j=0;j<d;j++)
{
distance=sqrtf(pow(store_x[C[i]]-store_x[D[j]],2)+pow(store_y[C[i]]-store_y[D[j]],2)+pow(store_z[C[i]]-store_z[D[j]],2));
if(distance<=4.5)
{
fprintf(f2,"%s  %5d %s %4d ----- %s  %5d %s %4d     %8.3f \n",store_atm_nm[C[i]],store_slno[C[i]],store_res_nm[C[i]],store_res_no[C[i]],store_atm_nm[D[j]],store_slno[D[j]],store_res_nm[D[j]],store_res_no[D[j]],distance);
count++;
}
}
}
//to calculate distance CE
for(i=0;i<c;i++)
{
for(j=0;j<e;j++)
{
distance=sqrtf(pow(store_x[C[i]]-store_x[E[j]],2)+pow(store_y[C[i]]-store_y[E[j]],2)+pow(store_z[C[i]]-store_z[E[j]],2));
if(distance<=4.5)
{
fprintf(f2,"%s  %5d %s %4d ----- %s  %5d %s %4d     %8.3f \n",store_atm_nm[C[i]],store_slno[C[i]],store_res_nm[C[i]],store_res_no[C[i]],store_atm_nm[E[j]],store_slno[E[j]],store_res_nm[E[j]],store_res_no[E[j]],distance);
count++;
}
}
}
//to calculate distance CF
for(i=0;i<c;i++)
{
for(j=0;j<f;j++)
{
distance=sqrtf(pow(store_x[C[i]]-store_x[F[j]],2)+pow(store_y[C[i]]-store_y[F[j]],2)+pow(store_z[C[i]]-store_z[F[j]],2));
if(distance<=4.5)
{
fprintf(f2,"%s  %5d %s %4d ----- %s  %5d %s %4d     %8.3f \n",store_atm_nm[C[i]],store_slno[C[i]],store_res_nm[C[i]],store_res_no[C[i]],store_atm_nm[F[j]],store_slno[F[j]],store_res_nm[F[j]],store_res_no[F[j]],distance);
count++;
}
}
}
//to calculate distance DE
for(i=0;i<d;i++)
{
for(j=0;j<e;j++)
{
distance=sqrtf(pow(store_x[D[i]]-store_x[E[j]],2)+pow(store_y[D[i]]-store_y[E[j]],2)+pow(store_z[D[i]]-store_z[E[j]],2));
if(distance<=4.5)
{
fprintf(f2,"%s  %5d %s %4d ----- %s  %5d %s %4d     %8.3f \n",store_atm_nm[D[i]],store_slno[D[i]],store_res_nm[D[i]],store_res_no[D[i]],store_atm_nm[E[j]],store_slno[E[j]],store_res_nm[E[j]],store_res_no[E[j]],distance);
count++;
}
}
}
//to calculate distance DF
for(i=0;i<d;i++)
{
for(j=0;j<f;j++)
{
distance=sqrtf(pow(store_x[D[i]]-store_x[F[j]],2)+pow(store_y[D[i]]-store_y[F[j]],2)+pow(store_z[D[i]]-store_z[F[j]],2));
if(distance<=4.5)
{
fprintf(f2,"%s  %5d %s %4d ----- %s  %5d %s %4d     %8.3f \n",store_atm_nm[D[i]],store_slno[D[i]],store_res_nm[D[i]],store_res_no[D[i]],store_atm_nm[F[j]],store_slno[F[j]],store_res_nm[F[j]],store_res_no[F[j]],distance);
count++;
}
}
}
//to calculate distance EF
for(i=0;i<e;i++)
{
for(j=0;j<f;j++)
{
distance=sqrtf(pow(store_x[E[i]]-store_x[F[j]],2)+pow(store_y[E[i]]-store_y[F[j]],2)+pow(store_z[E[i]]-store_z[F[j]],2));
if(distance<=4.5)
{
fprintf(f2,"%s  %5d %s %4d ----- %s  %5d %s %4d     %8.3f \n",store_atm_nm[E[i]],store_slno[E[i]],store_res_nm[E[i]],store_res_no[E[i]],store_atm_nm[F[j]],store_slno[F[j]],store_res_nm[F[j]],store_res_no[F[j]],distance);
count++;
}
}
}

fprintf(f2,"Total number of Interactions:%d \n",count);

fclose(f1);
fclose(f2);
return 0;
}