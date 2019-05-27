%{
int l=0, c=0, w=0, s=0;
%}
%%
[ ] {s++;w++;c++;}
[\n] {l++;w++;}
. {c++;}
%%

int yywrap(void){
return 1;
}

int main(int argc, char*argv[])
{
    yyin=fopen(argv[1], "r");
    yylex();
    printf("Lines: %d\nSpaces: %d\nWords: %d\nCharacters: %d\n", l, s, w, c); 
    return 0;
}