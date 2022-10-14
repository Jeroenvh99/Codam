#include"libft.h"
#include<stdio.h>

int main(){
	printf("----test isalpha----\n");
	int c = 'b';
	if (ft_isalpha(c) == isalpha(c))
		printf("OK: ft_isalpha returns %i for 'b'", ft_isalpha(c));
	else
		printf("FAIL: ft_isalpha returns %i for 'b'", ft_isalpha(c));
	c = '5';
	if (ft_isalpha(c) == isalpha(c))
		printf("OK: ft_isalpha returns %i for '5'", ft_isalpha(c));
	else
		printf("FAIL: ft_isalpha returns %i for '5'", ft_isalpha(c));
	c = -26;
	if (ft_isalpha(c) == isalpha(c))
		printf("OK: ft_isalpha returns %i for -26", ft_isalpha(c));
	else
		printf("FAIL: ft_isalpha returns %i for -26", ft_isalpha(c));
	printf("\n\n\n");
	printf("----test isdigit----");

	return 0;
}