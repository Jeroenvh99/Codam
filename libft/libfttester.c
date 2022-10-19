#include"libft.h"
#include<stdio.h>
#include<ctype.h>

int main(){
	printf("----test isalpha----\n");
	int c = 'b';
	int system;
	int own;
	system = isalpha(c);
	own = ft_isalpha(c);
	printf("system: %i, own: %i\n", system, own);
	if (system == own)
		printf("OK: ft_isalpha returns %i for 'b'\n", own);
	else
		printf("FAIL: ft_isalpha returns %i for 'b'\n", own);
	c = '5';
	system = isalpha(c);
	own = ft_isalpha(c);
	printf("system: %i, own: %i\n", system, own);
	if (system == own)
		printf("OK: ft_isalpha returns %i for '5'\n", own);
	else
		printf("FAIL: ft_isalpha returns %i for '5'\n", own);
	c = -26;
	system = isalpha(c);
	own = ft_isalpha(c);
	printf("system: %i, own: %i\n", system, own);
	if (system == own)
		printf("OK: ft_isalpha returns %i for -26\n", own);
	else
		printf("FAIL: ft_isalpha returns %i for -26\n", own);
	printf("\n\n\n");
	c = 0;
	
	printf("----test isdigit----\n");
	c = '6';
	system;
	own;
	system = isdigit(c);
	own = ft_isdigit(c);
	printf("system: %i, own: %i\n", system, own);
	if (system == own)
		printf("OK: ft_isdigit returns %i for '6'\n", own);
	else
		printf("FAIL: ft_isdigit returns %i for '6'\n", own);
	c = 'y';
	system = isdigit(c);
	own = ft_isdigit(c);
	printf("system: %i, own: %i\n", system, own);
	if (system == own)
		printf("OK: ft_isdigit returns %i for 'y'\n", own);
	else
		printf("FAIL: ft_isalpha returns %i for 'y'\n", own);
	c = -26;
	system = isdigit(c);
	own = ft_isdigit(c);
	printf("system: %i, own: %i\n", system, own);
	if (system == own)
		printf("OK: ft_isdigit returns %i for -26\n", own);
	else
		printf("FAIL: ft_isdigit returns %i for -26\n", own);
	printf("\n\n\n");
	c = 0;

	printf("----test isascii----\n");
	c = '6';
	system;
	own;
	system = isascii(c);
	own = ft_isascii(c);
	printf("system: %i, own: %i\n", system, own);
	if (system == own)
		printf("OK: ft_isascii returns %i for '6'\n", own);
	else
		printf("FAIL: ft_isascii returns %i for '6'\n", own);
	c = -26;
	system = isascii(c);
	own = ft_isascii(c);
	printf("system: %i, own: %i\n", system, own);
	if (system == own)
		printf("OK: ft_isascii returns %i for -26\n", own);
	else
		printf("FAIL: ft_isascii returns %i for -26\n", own);
	printf("\n\n\n");
	c = 0;

	return 0;
}