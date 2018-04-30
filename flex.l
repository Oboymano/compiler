%option noyywrap

%{
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

#define YYSTYPE double

#include "bison.tab.h"

float calIndex(char);
%}

digits      [0-9]
rn          (0|[1-9]+{digits}*)\.?{digits}*
hexa        [0][x][0-9a-fA-F]*
val 		[A-Z]
print       [p][r][i][n][t]
println 	[p][r][i][n][t][l][n]
cond		[c][o][n][d]
else		[e][l][s][e]
loop		[l][o][o][p]
hex  		[h][e][x]
str 		[A-Za-z0-9]*
exit        [e][x][i][t]
ws          [ \t]+ 


%%
{rn}   	{ yylval = atof(yytext); return T_NUM; }
{hexa}  { yylval = strtol(yytext, NULL, 16); return T_NUM; }
{exit}  {return T_EXIT; }
"+"     { return T_PLUS; }
"-"     { return T_MINUS; }
"*"     { return T_MULTIPLY; }
"/"     { return T_DIVIDE; }
"%"     { return T_MOD; }
"("     { return T_LEFT; }
")"     { return T_RIGHT; }
"^"     { return T_POW; }
","		{ return T_COMMA; }
">"		{ return T_GRATHER; }
"<"		{ return T_LESS; }
">="	{ return T_GE; }
"<="	{ return T_LE; }
"!="  	{ return T_NE; }
"!"		{ return T_NOT; }
"="	    { return T_EQUAL; }
":"     { return T_COLON; }
"'"	    { return T_QUOTE; }
\n      { return T_LINE; }

{cond}		{ return T_COND; }
{else}		{ return T_ELSE; }
{loop}		{ return T_LOOP; }
{val} 		{ yylval = calIndex(yytext[0]); return T_VAL; }
{hex}		{ return T_HEX; }
{print}		{ return T_PRINT; }
{println}   { return T_PRINTLN; }
{str}		{ return T_STR; }
{ws}   /* eats up white spaces */
.       { return yytext[0]; }

%%
float calIndex(char yytext){
    double index;
    yytext=toupper(yytext);
    index=yytext-'A';
    return (int)index;
}
