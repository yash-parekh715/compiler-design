%option noyywrap
%{
#include<stdio.h>
//Aim: Identify the keywords and identifiers using lex tool
%}

%%
int|float|double|char|bool|for		{ printf("%s is KW. ",yytext);  }
[a-zA-Z][a-zA-Z0-9_]*			    { printf("%s is ID. ",yytext); }
-?(([0-9]+)|([0-9]*\.[0-9]+)([eE][-+]?[0-9]+)?)  { printf("numbers\n");}
%%
int main()
{
	yylex();
	return 0;
}

