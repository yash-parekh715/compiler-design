%option noyywrap
%{
#include<stdio.h>
// Aim: Identify the keywords and identifiers using lex tool
//  Aim 2-> find numbers
//  Aim 3-> display each word of a program with its length.
//  Aim 4-> count number of blanks, tabs and new lines.
//  Aim 5-> identify comments and discard them.
int blank_count = 0, tab_count = 0, newline_count = 0;
%}
let [a-zA-Z_]
d [0-9]

%%
int|float|double|char|bool|for		{ printf("%s is KW",yytext);  }
{let}({let}|{d})*			    { printf("%s is ID",yytext); }
{d} { printf("%s is Number\n",yytext); }
{let}({let}|{d})*	 {  printf("Word: %s, Length: %d\n", yytext, yyleng);}

" "   { blank_count++; }
"\t"  { tab_count++; }
"\n"  { newline_count++; }

%%
int main()
{
	yylex();
    printf("Number of blanks: %d\n", blank_count);
    printf("Number of tabs: %d\n", tab_count);
    printf("Number of newlines: %d\n", newline_count);
	return 0;
}
