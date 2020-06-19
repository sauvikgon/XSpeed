
%{
#include "linexp.tab.h"
%}

%%

[\n]					{
							return 0; 
						}

[+]						{
							return(PLUS); 
						}

[*]						{	
							return(MULT);
						}

[=]						{	
							return(EQ);
						}

"<="					{
							
							return(LEQ);
						}
">="					{
							
							return(GEQ);
						}

[ \t\r]+				{;}

[uU][0-9]*				{
							linexplval.token_str = strdup(linexptext);
							return(UVAR);
						}
						
[yY][0-9]*				{
							linexplval.token_str = strdup(linexptext);
							return(YVAR);
						}
						
[a-zA-Z_]+[0-9]* 		{
							linexplval.token_str = strdup(linexptext);
							return(VAR);
						}
				
[+-]?[0-9]+[.]?[0-9]*	{
							linexplval.const_val = atof(linexptext);
							return(CONST);
						}
[-]						{
							return(MINUS);
						}	
[()']					{;}	
%%

int yywrap()
{
	return 0;
}
