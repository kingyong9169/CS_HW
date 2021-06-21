%{
#include <string.h>
#include "cbu2.h"
#define MAXSYM	100
#define	MAXSYMLEN	20
char symtbl[MAXSYM][MAXSYMLEN];
int lineno=1;
int insertsym();
int maxsym=0;
char s[30];
int temp;

%}
sp		[' '''\t]
ws		{sp}+
nl		\n
eletter	[A-Za-z]
hletter	[\xb0-\xfe][\xa0-\xfe]
letter	({eletter}|{hletter})
digit	[0-9]
id		{letter}({letter}|{digit})*
%%
{ws}	{/* do nothing */}
{nl}	{lineno++; }
add		{return(ADD); }
sub		{return(SUB); }
mul		{return(MUL); }
div		{return(DIV); }
"("		{return(LPARA); }
")"		{return(RPARA); }
"{"		{return(LP); }
"}"		{return(RP); }
"-"		{return(MINUS); }
if		{return(IF_ST); }
">"		{return(GT); }
"<"		{return(LT); }
">="	{return(GE); }
"<="	{return(LE); }
"=="	{return(EE); }
"!="	{return(NE); }
:=		{return(ASSGN); }
;		{return(STMTEND); }
start		{return(START);}
end		{return(END);}
{id}	{strcpy(s, yytext); temp=insertsym(s); yylval=MakeNode(ID, temp); return(ID);}
{digit}+		{sscanf(yytext, "%d", &temp); yylval=MakeNode(NUM, temp); return(NUM);}
.		{printf("invalid token %s\n", yytext); }
%%

int insertsym(s)
char *s;
{
int i;

	for(i=0;i<maxsym; i++) {
		if(strcmp(s, symtbl[i])==0) return(i);
		}
	if (i<MAXSYM-1) {
		strcpy(symtbl[maxsym],s);
		maxsym++;
		return(maxsym-1);
		}
	else
		{printf("symbol table overflow\n");}
	return(0);
}

yywrap() {}