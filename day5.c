#include<stdio.h> //standard input output
#include<stdlib.h> //library
#include<string.h> // string operations
#include<ctype.h>
#include<math.h>
int main ()
{
char word[5], line[100],line2[147],x[5],slno[8],res_nm[4],ch_id[20000],ch_id1[20000],atm_nm[4],store_atm_nm[20000][4],store_atm_nm1[20000][4],store_res_nm[20000][4],store_res_nm1[20000][4],x[9],y[9],z[9];
FILE *f1,*f2,*f3,*f4,*f5,*f6,*f7,*f8,*f9,*f10,*f11; 
int i,j,c1=0,c2=0,store_slno[20000],store_slno1[20000],store_slnoori[20000],co1=0,co2=0,co3=0,co4=0,co5=0,co6=0,co7=0,co8=0;
float store_sasa[20000],store_sasa1[20000],store_x[20000],store_y[20000],store_z[20000],store_ax[20000],store_ay[20000],store_az[20000],store_bx[20000],store_by[20000],store_bz[20000],store_cx[20000],store_cy[20000],store_cz[20000],store_dx[20000],store_dy[20000],store_dz[20000],store_ex[20000],store_ey[20000],store_ez[20000],store_fx[20000],store_fy[20000],store_fz[20000],store_gx[20000],store_gy[20000],store_gz[20000],store_hx[20000],store_hy[20000],store_hz[20000];
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
{
fprintf(f2,"%s\n",line);		
}
        if(line[21]=='B')
{
fprintf(f3,"%s\n",line);
}
        if(line[21]=='C')
{
fprintf(f4,"%s\n",line);
}
	if(line[21]=='D')
{fprintf(f5,"%s\n",line);
}
	if(line[21]=='E')
{fprintf(f6,"%s\n",line);
}
	if(line[21]=='F')
{fprintf(f7,"%s\n",line);
}
	if(line[21]=='G')
{fprintf(f8,"%s\n",line);}	
if(line[21]=='H')
{fprintf(f9,"%s\n",line);}
c1++;
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
f2 = fopen ("5un8-A.asa","r");
f3 = fopen ("5un8-B.asa","r");
f4 = fopen ("5un8-C.asa","r");
f5 = fopen ("5un8-D.asa","r");
f6 = fopen ("5un8-E.asa","r");
f7 = fopen ("5un8-F.asa","r");
f8 = fopen ("5un8-G.asa","r");
f9 = fopen ("5un8-H.asa","r");
f10 = fopen("outputday5.asa","w");
f11 = fopen("5un8.pdb","r"); 
while(fgets(line,146,f1)!=NULL)
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
	atm_nm[i]=line[10+i];
	atm_nm[3]='\0';
	strcpy(store_atm_nm[c1],atm_nm);//store atom name
for(i=0;i<3;i++) 
		res_nm[i]=line[14+i];
		res_nm[3]='\0';
		strcpy(store_res_nm[c1],res_nm);//store residue name
ch_id[c1]=line[18];//CHAIN IDENTIFIER
for(i=0;i<5;i++)
		x[i]=line[34+i];
		x[5]='\0';
		store_sasa[c1]=atof(x);//sasa
c1++;
}
while(fgets(line2,146,f2)!=NULL)
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
ch_id1[c1]=line2[18];//CHAIN IDENTIFIER
for(i=0;i<5;i++)
		x[i]=line2[34+i];
		x[5]='\0';
		store_sasa1[c2]=atof(x);//sasa
c2++;
}
for(i=0;i<c1;i++)
{
 for(j=0;j<c2;j++)
 {
  if(store_slno[i]==store_slno1[j])
  {
   if((store_sasa[i]-store_sasa1[j])!=0)
   {
fprintf(f10,"%5d %s %s %c %4.2f\n",store_slno[i],store_atm_nm[i],store_res_nm[i],ch_id[i],store_sasa1[j]-store_sasa[i]);

while(fgets(line,100,f11)!=NULL)
{
		for(i=0;i<5;i++)
		slno[i]=line[6+i];
		slno[5]='\0';
		store_sla[co1]=atoi(slno);//store atom number
		if(store_sla[i]==store_slno1[co1])
		{
		for(i=0;i<8;i++)
		x[i]=line[30+i];
		x[8]='\0';
		store_ax[co1]=atof(x);
                for(i=0;i<8;i++)
                y[i]=line[38+i];
                y[8]='\0';
                store_ay[co1]=atof(y);
		for(i=0;i<8;i++)
                z[i]=line[46+i];
                z[8]='\0';
                store_az[co1]=atof(z);	
		co1++;
		}
}
  }
 }
}
}
c2=0;
while(fgets(line2,146,f3)!=NULL)
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
ch_id1[c1]=line2[18];//CHAIN IDENTIFIER
for(i=0;i<5;i++)
		x[i]=line2[34+i];
		x[5]='\0';
		store_x1[c2]=atof(x);//sasa
c2++;
}
for(i=0;i<c1;i++)
{
 for(j=0;j<c2;j++)
 {
  if(store_slno[i]==store_slno1[j])
  {
   if((store_x[i]-store_x1[j])!=0)
   {
fprintf(f10,"%5d %s %s %c %4.2f\n",store_slno[i],store_atm_nm[i],store_res_nm[i],ch_id[i],store_x1[j]-store_x[i]);

while(fgets(line,100,f11)!=NULL)
{
		for(i=0;i<5;i++)
		slno[i]=line[6+i];
		slno[5]='\0';
		store_slb[co2]=atoi(slno);//store atom number
		if(store_sl[i]==store_slno1[co1])
		{
		for(i=0;i<8;i++)
		x[i]=line[30+i];
		x[8]='\0';
		store_bx[co2]=atof(x);
                for(i=0;i<8;i++)
                y[i]=line[38+i];
                y[8]='\0';
                store_by[co1]=atof(y);
		for(i=0;i<8;i++)
                z[i]=line[46+i];
                z[8]='\0';
                store_bz[co2]=atof(z);
		co2++;	
		}
}
   }
  }
 }
}
c2=0;
while(fgets(line2,146,f4)!=NULL)
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
ch_id1[c1]=line2[18];//CHAIN IDENTIFIER
for(i=0;i<5;i++)
		x[i]=line2[34+i];
		x[5]='\0';
		store_x1[c2]=atof(x);//sasa
c2++;
}
for(i=0;i<c1;i++)
{
 for(j=0;j<c2;j++)
 {
  if(store_slno[i]==store_slno1[j])
  {
   if((store_x[i]-store_x1[j])!=0)
   {
fprintf(f10,"%5d %s %s %c %4.2f\n",store_slno[i],store_atm_nm[i],store_res_nm[i],ch_id[i],store_x1[j]-store_x[i]);

while(fgets(line,100,f11)!=NULL)
{
		for(i=0;i<5;i++)
		slno[i]=line[6+i];
		slno[5]='\0';
		store_slc[co3]=atoi(slno);//store atom number
		if(store_slc[i]==store_slno1[co1])
		{
		for(i=0;i<8;i++)
		x[i]=line[30+i];
		x[8]='\0';
		store_cx[co3]=atof(x);
                for(i=0;i<8;i++)
                y[i]=line[38+i];
                y[8]='\0';
                store_cy[co3]=atof(y);
		for(i=0;i<8;i++)
                z[i]=line[46+i];
                z[8]='\0';
                store_cz[co3]=atof(z);
		co3++;	
		}
}
   }
  }
 }
}
c2=0;
while(fgets(line2,146,f5)!=NULL)
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
ch_id1[c1]=line2[18];//CHAIN IDENTIFIER
for(i=0;i<5;i++)
		x[i]=line2[34+i];
		x[5]='\0';
		store_x1[c2]=atof(x);//sasa
c2++;
}
for(i=0;i<c1;i++)
{
 for(j=0;j<c2;j++)
 {
  if(store_slno[i]==store_slno1[j])
  {
   if((store_x[i]-store_x1[j])!=0)
   {
fprintf(f10,"%5d %s %s %c %4.2f\n",store_slno[i],store_atm_nm[i],store_res_nm[i],ch_id[i],store_x1[j]-store_x[i]);

while(fgets(line,100,f11)!=NULL)
{
		for(i=0;i<5;i++)
		slno[i]=line[6+i];
		slno[5]='\0';
		store_sld[co4]=atoi(slno);//store atom number
		if(store_sld[i]==store_slno1[co1])
		{
		for(i=0;i<8;i++)
		x[i]=line[30+i];
		x[8]='\0';
		store_dx[co4]=atof(x);
                for(i=0;i<8;i++)
                y[i]=line[38+i];
                y[8]='\0';
                store_dy[co4]=atof(y);
		for(i=0;i<8;i++)
                z[i]=line[46+i];
                z[8]='\0';
                store_dz[co4]=atof(z);
		co4++;	
		}
}
   }
  }
 }
}
c2=0;
while(fgets(line2,146,f6)!=NULL)
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
ch_id1[c1]=line2[18];//CHAIN IDENTIFIER
for(i=0;i<5;i++)
		x[i]=line2[34+i];
		x[5]='\0';
		store_x1[c2]=atof(x);//sasa
c2++;
}
for(i=0;i<c1;i++)
{
 for(j=0;j<c2;j++)
 {
  if(store_slno[i]==store_slno1[j])
  {
   if((store_x[i]-store_x1[j])!=0)
   {
fprintf(f10,"%5d %s %s %c %4.2f\n",store_slno[i],store_atm_nm[i],store_res_nm[i],ch_id[i],store_x1[j]-store_x[i]);

while(fgets(line,100,f11)!=NULL)
{
		for(i=0;i<5;i++)
		slno[i]=line[6+i];
		slno[5]='\0';
		store_sle[co5]=atoi(slno);//store atom number
		if(store_sle[i]==store_slno1[co1])
		{
		for(i=0;i<8;i++)
		x[i]=line[30+i];
		x[8]='\0';
		store_ex[co5]=atof(x);
                for(i=0;i<8;i++)
                y[i]=line[38+i];
                y[8]='\0';
                store_ey[co5]=atof(y);
		for(i=0;i<8;i++)
                z[i]=line[46+i];
                z[8]='\0';
                store_ez[co5]=atof(z);	
		}
}
   }
  }
 }
}
c2=0;while(fgets(line2,146,f7)!=NULL)
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
ch_id1[c1]=line2[18];//CHAIN IDENTIFIER
for(i=0;i<5;i++)
		x[i]=line2[34+i];
		x[5]='\0';
		store_x1[c2]=atof(x);//sasa
c2++;
}
for(i=0;i<c1;i++)
{
 for(j=0;j<c2;j++)
 {
  if(store_slno[i]==store_slno1[j])
  {
   if((store_x[i]-store_x1[j])!=0)
   {
fprintf(f10,"%5d %s %s %c %4.2f\n",store_slno[i],store_atm_nm[i],store_res_nm[i],ch_id[i],store_x1[j]-store_x[i]);

while(fgets(line,100,f11)!=NULL)
{
		for(i=0;i<5;i++)
		slno[i]=line[6+i];
		slno[5]='\0';
		store_slf[co6]=atoi(slno);//store atom number
		if(store_slf[i]==store_slno1[co1])
		{
		for(i=0;i<8;i++)
		x[i]=line[30+i];
		x[8]='\0';
		store_fx[co6]=atof(x);
                for(i=0;i<8;i++)
                y[i]=line[38+i];
                y[8]='\0';
                store_fy[co6]=atof(y);
		for(i=0;i<8;i++)
                z[i]=line[46+i];
                z[8]='\0';
                store_fz[co6]=atof(z);	
		}
}
   }
  }
 }
}
c2=0;
while(fgets(line2,146,f8)!=NULL)
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
ch_id1[c1]=line2[18];//CHAIN IDENTIFIER
for(i=0;i<5;i++)
		x[i]=line2[34+i];
		x[5]='\0';
		store_x1[c2]=atof(x);//sasa
c2++;
}
for(i=0;i<c1;i++)
{
 for(j=0;j<c2;j++)
 {
  if(store_slno[i]==store_slno1[j])
  {
   if((store_x[i]-store_x1[j])!=0)
   {
fprintf(f10,"%5d %s %s %c %4.2f\n",store_slno[i],store_atm_nm[i],store_res_nm[i],ch_id[i],store_x1[j]-store_x[i]);

while(fgets(line,100,f11)!=NULL)
{
		for(i=0;i<5;i++)
		slno[i]=line[6+i];
		slno[5]='\0';
		store_slg[co1]=atoi(slno);//store atom number
		if(store_slg[i]==store_slno1[co1])
		{
		for(i=0;i<8;i++)
		x[i]=line[30+i];
		x[8]='\0';
		store_gx[co7]=atof(x);
                for(i=0;i<8;i++)
                y[i]=line[38+i];
                y[8]='\0';
                store_gy[co7]=atof(y);
		for(i=0;i<8;i++)
                z[i]=line[46+i];
                z[8]='\0';
                store_gz[co7]=atof(z);	
		co7++;
		}
}
   }
  }
 }
}
c2=0;
while(fgets(line2,146,f9)!=NULL)
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
ch_id1[c1]=line2[18];//CHAIN IDENTIFIER
for(i=0;i<5;i++)
		x[i]=line2[34+i];
		x[5]='\0';
		store_x1[c2]=atof(x);//sasa
c2++;
}
for(i=0;i<c1;i++)
{
 for(j=0;j<c2;j++)
 {
  if(store_slno[i]==store_slno1[j])
  {
   if((store_x[i]-store_x1[j])!=0)
   {
fprintf(f10,"%5d %s %s %c %4.2f\n",store_slno[i],store_atm_nm[i],store_res_nm[i],ch_id[i],store_x1[j]-store_x[i]);

while(fgets(line,100,f11)!=NULL)
{
		for(i=0;i<5;i++)
		slno[i]=line[6+i];
		slno[5]='\0';
		store_slh[co8]=atoi(slno);//store atom number
		if(store_slh[i]==store_slno1[co1])
		{
		for(i=0;i<8;i++)
		x[i]=line[30+i];
		x[8]='\0';
		store_hx[co8]=atof(x);
                for(i=0;i<8;i++)
                y[i]=line[38+i];
                y[8]='\0';
                store_hy[co8]=atof(y);
		for(i=0;i<8;i++)
                z[i]=line[46+i];
                z[8]='\0';
                store_hz[co8]=atof(z);	
		co8++;
		}
}
   }
  }
 }
}
// for chain A
for(i=0;i<co1;i++)
{
for(j=0;j<co2;j++)
{
dist=sqrtf( (store_ax[i]-store_ax[j])*(store_ax[i]-store_ax[j])+(store_ay[i]-store_ay[j])*(store_ay[i]-store_ay[j])+(store_az[i]-store_az[j]));
if (dist <=6)
fprintf(f10,"%5d %8.3f\n")
for(k=0;i<co3;i++)
{
for(l=0;j<co4;j++)
{
for(m=0;i<co5;i++)
{
for(n=0;j<co6;j++)
{
for(o=0;i<co7;i++)
{
for(p=0;j<co8;j++)
{
dis =
}  
fprintf(f10,"%5d ",
fclose(f1);
fclose(f2);
fclose(f3);
fclose(f4);
fclose(f5);
fclose(f6);
fclose(f7);
fclose(f8);
fclose(f9);
fclose(f10);
return 0;
}
