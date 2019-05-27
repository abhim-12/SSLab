//object pgm
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void main()
{
FILE *f4,*f5;
char label[20],opcode[20],operand[20];
int textlen=0,len;
	char textrec[80],saddress[20],objcode[20],temp[80],startaddr[20];
	printf("\nObject Program:-\n\n");
	f4=fopen("outputt.dat","r");
	f5=fopen("length.txt","r");
	fscanf(f5,"%d",&len);
	fscanf(f4,"%s %s %s %s %s",saddress,label,opcode,operand,objcode);
	strcpy(startaddr,saddress);	

	printf("H %s  00%s %06X\n",label,saddress,len);

	fscanf(f4,"%s %s %s %s %s",saddress,label,opcode,operand,objcode);
	
	strcpy(temp,"");
	strcpy(textrec,"T 00");
	strcat(textrec,saddress);	
	while(strcmp(opcode,"END")!=0)
	{
		if((textlen==30)||(strcmp(opcode,"RESW")==0)||(strcmp(opcode,"RESB")==0)||(((strlen(objcode)/2)+textlen)>30))
		{
			printf("%s %02X %s\n",textrec,textlen,temp);
			textlen=0;
			strcpy(temp,"");
			strcpy(textrec,"T 00");
			fscanf(f4,"%s %s %s %s %s",saddress,label,opcode,operand,objcode);
			if(strcmp(objcode,"-")!=0)
			{
				strcat(textrec,saddress);
				strcat(temp,objcode);
				strcat(temp," ");
				textlen=textlen+(strlen(objcode)/2);	
			}
		}
		else
		{
			textlen=textlen+(strlen(objcode)/2);
			strcat(temp,objcode);
			strcat(temp," ");
		}
		fscanf(f4,"%s %s %s %s %s",saddress,label,opcode,operand,objcode);
	}
	if(textlen!=0)
		printf("%s %x %s\n",textrec,textlen,temp);

	printf("E 00%s\n\n",startaddr);
	fclose(f4);
}
//input:

2000	**	START	2000	-
2000	**	LDA	FIVE	002013
2003	**	STA	ALPHA	0C2016
2006	**	LDCH	CHARZ	50200F
2009	**	STCH	C1	543016
200C	**	LDT	C1	743016
200F	CHARZ	BYTE	C'xyZ1'	78795A31
2013	FIVE	WORD	5	000005
2016	ALPHA	RESB	4096	-
3016	C1	RESB	1	-
3017	**	END	**

Object Program:-

H **  002000 000000
T 002000 16 002013 0C2016 50200F 543016 743016 78795A31 000005 
E 002000

