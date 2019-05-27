%{
#include <stdio.h>
int vc=0,cc=0,nc=0,sc=0,lc=0;
%}
%%
[ \t] ;
[aAeEiIoOuU] vc++;
[a-zA-Z] cc++;
[0-9] nc++;
. sc++;
\n lc++;
%%
int yywrap() {return 1;}
void main()
{
 yyin=fopen("input.txt","r");
 yylex();
 printf("\nNo.of vowels=%d \n No.of consonent=%d \n No.of number=%d\n no of special charater=%d\n no of lines=%d\n",vc,cc,nc,sc,lc);
}