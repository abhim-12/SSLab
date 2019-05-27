%{
#include<stdio.h>
int id=0, com=0, oper=0;
%}
%%
\/\/.* {com++;}
"/*"[^"*/"]*"*/" {com++;}

%%
int yywrap(){return 1;
fclose(yyin);}
void main()
{
  yyin=fopen("input1.txt","r");
  yyout=fopen("nocomm.txt","w");
  yylex();
  printf("No. of comments=%d\n", com);
 
  }
