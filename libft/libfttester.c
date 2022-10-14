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
		printf("OK: ft_isalpha returns %i for 'b'\n", ft_isalpha(c));
	else
		printf("FAIL: ft_isalpha returns %i for 'b'\n", ft_isalpha(c));
	c = '5';
	system = isalpha(c);
	own = ft_isalpha(c);
	printf("system: %i, own: %i\n", system, own);
	if (system == own)
		printf("OK: ft_isalpha returns %i for '5'\n", ft_isalpha(c));
	else
		printf("FAIL: ft_isalpha returns %i for '5'\n", ft_isalpha(c));
	c = -26;
	system = isalpha(c);
	own = ft_isalpha(c);
	printf("system: %i, own: %i\n", system, own);
	if (system == own)
		printf("OK: ft_isalpha returns %i for -26\n", ft_isalpha(c));
	else
		printf("FAIL: ft_isalpha returns %i for -26\n", ft_isalpha(c));
	printf("\n\n\n");
	
	printf("----test isdigit----\n");
	int c = 'b';
	int system;
	int own;
	system = isalpha(c);
	own = ft_isalpha(c);
	printf("system: %i, own: %i\n", system, own);
	if (system == own)
		printf("OK: ft_isalpha returns %i for 'b'\n", ft_isalpha(c));
	else
		printf("FAIL: ft_isalpha returns %i for 'b'\n", ft_isalpha(c));
	c = '5';
	system = isalpha(c);
	own = ft_isalpha(c);
	printf("system: %i, own: %i\n", system, own);
	if (system == own)
		printf("OK: ft_isalpha returns %i for '5'\n", ft_isalpha(c));
	else
		printf("FAIL: ft_isalpha returns %i for '5'\n", ft_isalpha(c));
	c = -26;
	system = isalpha(c);
	own = ft_isalpha(c);
	printf("system: %i, own: %i\n", system, own);
	if (system == own)
		printf("OK: ft_isalpha returns %i for -26\n", ft_isalpha(c));
	else
		printf("FAIL: ft_isalpha returns %i for -26\n", ft_isalpha(c));
	printf("\n\n\n");
	return 0;
}