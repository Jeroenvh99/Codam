#include"ft_printf.h"
#include<stdio.h>
#include<limits.h>

int main(){
	void	*v;
	ft_printf("%i\n", ft_printf("mine: hello, this %i prints an integer\n", 24547767));
	printf("%i\n", printf("system: hello, this %i prints an integer\n", 24547767));
	ft_printf("%i\n", ft_printf("mine: hello, this %p prints a pointer\n", v));
	printf("%i\n", printf("system: hello, this %p prints a pointer\n", v));
	ft_printf("%i\n", ft_printf("mine: hello, this %x prints an integer in hex\n", INT_MIN));
	printf("%i\n", printf("system: hello, this %x prints an integer in hex\n", INT_MIN));
	ft_printf("%i\n", ft_printf("mine: hello, this %X prints an integer in hex\n", INT_MAX));
	printf("%i\n", printf("system: hello, this %X prints an integer in hex\n", INT_MAX));
	ft_printf("%i\n", ft_printf("mine: hello, this %p prints a pointer\n", LONG_MIN));
	printf("%i\n", printf("system: hello, this %p prints a pointer\n", LONG_MIN));
	ft_printf("%i\n", ft_printf("mine: \001\002\007\v\010\f\r\n"));
	printf("%i\n", printf("system: \001\002\007\v\010\f\r\n"));

	ft_printf("%i\n", ft_printf("mine: hello, this %p prints a pointer\n", NULL));
	printf("%i\n", printf("system: hello, this %p prints a pointer\n", NULL));

	ft_printf("%i\n", ft_printf("mine: hello, this %-057.4365i prints an integer\n", 24547767));
	printf("%i\n", printf("system: hello, this %-057.4365i prints an integer\n", 24547767));
	ft_printf("%i\n", ft_printf("mine: hello, this %#.57p prints a pointer\n", v));
	printf("%i\n", printf("system: hello, this %#.57p prints a pointer\n", v));
	ft_printf("%i\n", ft_printf("mine: hello, this %+#9.x prints an integer in hex\n", INT_MIN));
	printf("%i\n", printf("system: hello, this %+#9.x prints an integer in hex\n", INT_MIN));
	ft_printf("%i\n", ft_printf("mine: hello, this %0.8X prints an integer in hex\n", INT_MAX));
	printf("%i\n", printf("system: hello, this %0.8X prints an integer in hex\n", INT_MAX));
	ft_printf("%i\n", ft_printf("mine: hello, this %-35.7p prints a pointer\n", LONG_MIN));
	printf("%i\n", printf("system: hello, this %-35.7p prints a pointer\n", LONG_MIN));
	printf("%i\n", ft_printf("%08.5x", 34));
	ft_printf("%i\n", ft_printf("42%0#29x42\n", 0));
	printf("%i\n", printf("42%0#29x42\n", 0));
	return 0;
}