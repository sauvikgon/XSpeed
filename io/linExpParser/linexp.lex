
%{
#include "linexp.tab.h"
%}

%%

[\n]							{//printf("EOL token\n");
										return 0; 
									}

[+]								{//printf("PLUS token\n"); 
										return(PLUS); 
									}

[*]								{//printf("MULT token\n");
										return(MULT);
									}

[=]								{//printf("EQ token\n");
										return(EQ);
									}

"<="							{
										//printf("LEQ token\n");
										return(LEQ);
									}
">="							{
										//printf("GEQ token\n");
										return(GEQ);
									}

[ \t\r]+					{;}

[uU][0-9]*				{
										//printf("UVAR token\n");
										linexplval.token_str = strdup(linexptext);
										return(UVAR);
									}

[a-zA-Z]+[0-9]* 	{
										//printf("VAR token\n");
										linexplval.token_str = strdup(linexptext);
										return(VAR);
									}
				
[+-]?[0-9]+[.]?[0-9]*				{
															//printf("CONST token\n");
															linexplval.const_val = atof(linexptext);
															return(CONST);
														}
		
%%

int yywrap()
{
	return 0;
}
