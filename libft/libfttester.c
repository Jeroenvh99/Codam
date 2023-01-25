#include"libft.h"
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<limits.h>
#include<fcntl.h>
#include<unistd.h>

char changec(unsigned int index, char c)
{
	return (c + index);
}

void print(unsigned int index, char *c)
{
	printf("%c", *c + index);
}

void *changechr(void *node){
	char newc[5] = "newc";
	((t_list *)node)->content = ((t_list *)node)->content;
	return (node);
}

void printlist(t_list *head){
	while (head){
		printf("%s\n", (char *)head->content);
		head = head->next;
	}
}

// void print(void *node){
// 	printf("%s\n", ((t_list *)node)->content);
// }

void	del(void *node)
{
	free(node);
	node = NULL;
}

void test_itoa(){
	printf("----test itoa----\n");
	int i = 45;
	char *sys;
	char *me;
	me = ft_itoa(i);
	if (!strncmp("45", me, 2))
		printf("\u2705");
	else
		printf("\u274C");
	printf("%s\n", ft_itoa(-67577));
	printf("%s\n", ft_itoa(-100));
	printf("%s\n", ft_itoa(-2147483648));
	printf("%s\n", ft_itoa(2147483647));
	printf("%s", ft_itoa(0));
}

void test_printf(){
	void	*v;
	printf("----test ft_printf----\n");
	ft_printf("%i\n", ft_printf("mine:   hello, this %i prints an integer\n", 24547767));
	printf("%i\n", printf("system: hello, this %i prints an integer\n", 24547767));
	ft_printf("%i\n", ft_printf("mine:   hello, this %p prints a pointer\n", v));
	printf("%i\n", printf("system: hello, this %p prints a pointer\n", v));
	ft_printf("%i\n", ft_printf("mine:   hello, this %x prints an integer in hex\n", INT_MIN));
	printf("%i\n", printf("system: hello, this %x prints an integer in hex\n", INT_MIN));
	ft_printf("%i\n", ft_printf("mine:   hello, this %X prints an integer in hex\n", INT_MAX));
	printf("%i\n", printf("system: hello, this %X prints an integer in hex\n", INT_MAX));
	ft_printf("%i\n", ft_printf("mine:   hello, this %p prints a pointer\n", LONG_MIN));
	printf("%i\n", printf("system: hello, this %p prints a pointer\n", LONG_MIN));
	ft_printf("%i\n", ft_printf("mine:   \001\002\007\v\010\f\r\n"));
	printf("%i\n", printf("system: \001\002\007\v\010\f\r\n"));

	ft_printf("%i\n", ft_printf("mine:   hello, this %p prints a pointer\n", NULL));
	printf("%i\n", printf("system: hello, this %p prints a pointer\n", NULL));

	ft_printf("%i\n", ft_printf("mine:   hello, this %-i prints an integer\n", 24547767));
	printf("%i\n", printf("system: hello, this %-i prints an integer\n", 24547767));
	ft_printf("%i\n", ft_printf("mine:   hello, this %-57.4i prints an integer\n", 24547767));
	printf("%i\n", printf("system: hello, this %-57.4i prints an integer\n", 24547767));
	ft_printf("%i\n", ft_printf("mine:   hello, this %#.57p prints a pointer\n", v));
	printf("%i\n", printf("system: hello, this %#.57p prints a pointer\n", v));
	ft_printf("%i\n", ft_printf("mine:   hello, this %+#9.x prints an integer in hex\n", INT_MIN));
	printf("%i\n", printf("system: hello, this %+#9.x prints an integer in hex\n", INT_MIN));
	ft_printf("%i\n", ft_printf("mine:   hello, this %0.8X prints an integer in hex\n", INT_MAX));
	printf("%i\n", printf("system: hello, this %0.8X prints an integer in hex\n", INT_MAX));
	ft_printf("%i\n", ft_printf("mine:   hello, this %-35.7p prints a pointer\n", LONG_MIN));
	printf("%i\n", printf("system: hello, this %-35.7p prints a pointer\n", LONG_MIN));
	ft_printf("%i\n", ft_printf("mine:   %08.5x\n", 34));
	printf("%i\n", printf("system: %08.5x\n", 34));
	ft_printf("%i\n", ft_printf("mine:   42%0#29x42\n", 0));
	printf("%i\n", printf("system: 42%0#29x42\n", 0));
	ft_printf("%i\n", ft_printf("mine:   %%%"));
	printf("%i\n", printf("system: %%%"));
	ft_printf("%i\n", ft_printf("mine:   %01.u\n, %01.u\n, %01.u\n, %01.u\n, %01.u\n, %01.u\n, %01.u\n, %01.u\n, %01.u\n, %01.u\n", 0, 5, -1, -10, 100, -1862, 0xABCDE, INT_MIN, INT_MAX, UINT_MAX));
	printf("%i\n", printf("system: %01.u\n, %01.u\n, %01.u\n, %01.u\n, %01.u\n, %01.u\n, %01.u\n, %01.u\n, %01.u\n, %01.u\n", 0, 5, -1, -10, 100, -1862, 0xABCDE, INT_MIN, INT_MAX, UINT_MAX));
	ft_printf("%i\n", ft_printf("mine:   hello\0my  \0name\0 is\Jeroen"));
	printf("%i\n", printf("system: hello\0my  \0name\0 is\Jeroen"));
	ft_printf("%i\n", ft_printf("mine:   %s", "hello\0my  \0name\0 is\Jeroen"));
	printf("%i\n", printf("system: %s", "hello\0my  \0name\0 is\Jeroen"));
	ft_printf("%i\n", ft_printf("mine:   \Jeroen"));
	printf("%i\n", printf("system: \Jeroen"));
	ft_printf("%i\n", ft_printf("mine:   %.x, %.x, %.x, %.x, %.x, %.x, %.x, %.x, %.x, %.x\n", 0, 5, -1, -10, 0x1234, -1862, 0xABCDE, INT_MIN, INT_MAX, UINT_MAX));
	printf("%i\n", printf("system: %.x, %.x, %.x, %.x, %.x, %.x, %.x, %.x, %.x, %.x", 0, 5, -1, -10, 0x1234, -1862, 0xABCDE, INT_MIN, INT_MAX, UINT_MAX));
}

int test_gnl(){
	char *str;
	int fd;
	
	fd = open("bible.txt", O_RDONLY);
	str = get_next_line(fd);
	while (str)
	{
		printf("%s\n", str);
		str = get_next_line(fd);
		free(str);
	}
	close(fd);
	return 0;
}

int main(){
	// printf("----test isalpha----\n");
	// int c = 'b';
	// int system;
	// int mine;
	// system = isalpha(c);
	// mine = ft_isalpha(c);
	// printf("system: %i, mine: %i\n", system, mine);
	// if (system == mine)
	// 	printf("OK: ft_isalpha returns %i for 'b'\n", mine);
	// else
	// 	printf("FAIL: ft_isalpha returns %i for 'b'\n", mine);
	// c = '5';
	// system = isalpha(c);
	// mine = ft_isalpha(c);
	// printf("system: %i, mine: %i\n", system, mine);
	// if (system == mine)
	// 	printf("OK: ft_isalpha returns %i for '5'\n", mine);
	// else
	// 	printf("FAIL: ft_isalpha returns %i for '5'\n", mine);
	// c = -26;
	// system = isalpha(c);
	// mine = ft_isalpha(c);
	// printf("system: %i, mine: %i\n", system, mine);
	// if (system == mine)
	// 	printf("OK: ft_isalpha returns %i for -26\n", mine);
	// else
	// 	printf("FAIL: ft_isalpha returns %i for -26\n", mine);
	// printf("\n\n\n");
	// c = 0;
	
	// printf("----test isdigit----\n");
	// c = '6';
	// system = isdigit(c);
	// mine = ft_isdigit(c);
	// printf("system: %i, mine: %i\n", system, mine);
	// if (system == mine)
	// 	printf("OK: ft_isdigit returns %i for '6'\n", mine);
	// else
	// 	printf("FAIL: ft_isdigit returns %i for '6'\n", mine);
	// c = 'y';
	// system = isdigit(c);
	// mine = ft_isdigit(c);
	// printf("system: %i, mine: %i\n", system, mine);
	// if (system == mine)
	// 	printf("OK: ft_isdigit returns %i for 'y'\n", mine);
	// else
	// 	printf("FAIL: ft_isalpha returns %i for 'y'\n", mine);
	// c = -26;
	// system = isdigit(c);
	// mine = ft_isdigit(c);
	// printf("system: %i, mine: %i\n", system, mine);
	// if (system == mine)
	// 	printf("OK: ft_isdigit returns %i for -26\n", mine);
	// else
	// 	printf("FAIL: ft_isdigit returns %i for -26\n", mine);
	// printf("\n\n\n");
	// c = 0;

	// printf("----test isascii----\n");
	// c = '6';
	// system = isascii(c);
	// mine = ft_isascii(c);
	// printf("system: %i, mine: %i\n", system, mine);
	// if (system == mine)
	// 	printf("OK: ft_isascii returns %i for '6'\n", mine);
	// else
	// 	printf("FAIL: ft_isascii returns %i for '6'\n", mine);
	// c = -26;
	// system = isascii(c);
	// mine = ft_isascii(c);
	// printf("system: %i, mine: %i\n", system, mine);
	// if (system == mine)
	// 	printf("OK: ft_isascii returns %i for -26\n", mine);
	// else
	// 	printf("FAIL: ft_isascii returns %i for -26\n", mine);
	// printf("\n\n\n");
	// c = 0;

	// // isprint
	// char c = '\0';
	// int n = 0;
	// while (c <= 127){
	// 	int i = ft_isprint(c);
	// 	printf("the character %c is %i printable\n", c, i);
	// 	++c;
	// 	if (i){
	// 		++n;
	// 	}
	// 	if (c == 1 && n > 1){
	// 		break;
	// 	}
	// }
	// if (n == 95){
	// 	printf("the correct number of printable characters is found");
	// }

	// // toupper
	// printf("'a' gives %c\n", (char)ft_toupper('a'));
	// printf("'8' gives %c\n", (char)ft_toupper('8'));

	// // tolower
	// printf("'A' gives %c\n", (char)ft_tolower('a'));
	// printf("'8' gives %c\n", (char)ft_tolower('8'));

	// // substr
	// char *str = "01234";
	// size_t size = 10;
	// char *ret = ft_substr("hola", 4294967295, 18446744073709551615);
	// printf("%s", ret);
	// char *ret2 = ft_substr("", 1, 1);
	// printf("%s", ret2);

	// // strtrim
	// char *s1 = "  \t \t \n   \n\n\n\t";
	// char *s2 = "";
	// char *ret = ft_strtrim(s1, " \n\t");
	// printf("%s", ret);

	// // strrchr
	// char s[15] = "adHd fdklHds";
	// printf("%s\n", ft_strrchr(s, 543));
	// printf("%s\n", ft_strrchr(s, 'g'));

	// // strnstr
	// char c[21] = "dfjoirfjrehgudfragtr";
	// char n0[7] = "";
	// char n1[7] = "udfr";
	// char n2[7] = "udcr";
	// printf("%s\n", ft_strnstr(c, n0, 16));
	// printf("%s\n", ft_strnstr(c, n1, 16));
	// printf("%s", ft_strnstr(c, n2, 16));

	// // strncmp
	// char s0[8] = "asbfgbfg";
	// char s1[8] = "asbfgbfg";
	// char s2[8] = "asbkubfg";
	// char s3[8] = "asbfgb";
	// printf("%i\n", (ft_strncmp(s0, s1, 0)));
	// printf("%i\n", (strncmp(s0, s1, 0)));
	// printf("%i\n", (ft_strncmp(s0, s3, 8)));
	// printf("%i\n", (ft_strncmp(s0, s1, 3)));
	// printf("%i\n", (ft_strncmp(s0, s2, 3)));
	// printf("%i\n", (ft_strncmp(s0, s3, 3)));
	// printf("%i\n", ft_strncmp("hello", "hel", 4));

	// // strmapi
	// printf("%s", ft_strmapi("Hello", changec));

	// // strlen
	// int n = ft_strlen("hithere");
	// if (n == 7){
	// 	printf("the length of the string is counted correctly\n");
	// }
	// else{
	// 	printf("the length of the string hithere isn't counted correctly");
	// 	return 1;
	// }
	// n = ft_strlen("");
	// if (n == 0){
	// 	printf("the length of the empty string is counted correctly\n");
	// }
	// else{
	// 	printf("the length of the empty string isn't counted correctly");
	// 	return 1;
	// }
	// printf("inputting NULL should give a segmentation fault");
	// n = ft_strlen(NULL);

	// // strlcpy

	// //strlcat
	// char *src = "aaa";
	// char dst2[20];
	// ft_strlcat(dst2, NULL, 20);

	// // strjoin
	// char s0[] = "hello";
	// char s1[] = " Bruno";
	// printf("%s", ft_strjoin(s0, s1));

	// // striteri
	// ft_striteri("Hello", print);

	// // strdup
	// char c[4] = "bfd";
	// char c1[2] = "";
	// printf("%s\n", ft_strdup(c));
	// printf("%s\n", ft_strdup(c1));

	// // strchr
	// char s[15] = "teste";
	// printf("%s\n", ft_strchr(s, 'e'));
	// printf("%s\n", ft_strchr(s, 'g'));

	// // putstr
	// ft_putstr_fd("this is a string that's printed to standard output", 1);

	// // split
	// int i = 0;
	// char **splitarr;
	// splitarr = ft_split("      split       this for   me  !       hfhjutyk", ' ');
	// while (splitarr[i]){
	// 	printf("%s\n", splitarr[i]);
	// 	++i;
	// }
	// i = 0;
	// splitarr = ft_split(NULL, ' ');
	// // while (splitarr[i]){
	// // 	printf("%s\n", splitarr[i]);
	// // 	++i;
	// // }
	// i = 0;
	// splitarr = ft_split("vdfbnjfgbnghvbdfkergh", 'b');
	// while (splitarr[i]){
	// 	printf("%s\n", splitarr[i]);
	// 	++i;
	// }

	// // putnbr
	// ft_putnbr_fd(INT_MAX, 1);
	// printf("\n");
	// ft_putnbr_fd(INT_MIN, 1);
	// printf("\nmin is %i, max is %i\n", INT_MIN, INT_MAX);
	// ft_putnbr_fd(10, 1);
	// printf("\n");
	// ft_putnbr_fd(100, 1);
	// printf("\n");
	// ft_putnbr_fd(5737, 1);
	// printf("\n");
	// ft_putnbr_fd(4656780, 1);

	// // putendl
	// ft_putendl_fd("string is on standard output followed by a newline", 1);

	// // putchar
	// printf("the following character is on the standard error:");
	// ft_putchar_fd('g', 1);
	// printf("\nthe following character is on the standard output:");
	// ft_putchar_fd('k', 1);
	// ft_putchar_fd('d', 1);

	// // memset
	// char c[6] = "hello";
	// printf("%s\n", c);
	// ft_memset(c, 5, 3);
	// printf("%s", c);

	// // memmove
	// char a[] = "hello";
	// char b[] = "hiagain";
	// ft_memmove(&a, &b, 2);
	// printf("The contents of string a are:%s\n", a);
	// printf("The contents of string b are:%s", b);

	// // memcpy
	// ft_memcpy(NULL, NULL, 5);

	// // memcmp

	// // memchr
	// char *mem = "9865478";
	// printf("%s", ft_memchr(mem, '6', 6));

	// lstsize
	// t_list *head = ft_lstnew("hello world!");
	// ft_lstadd_front(&head, ft_lstnew("hi again!"));
	// printf("%i", ft_lstsize(head));

	// // lstnew
	// t_list *node = ft_lstnew("hello world!");
	// printf("%s", (char *)node->content);

	// // lstmap
	// t_list *head = ft_lstnew("hello world!");
	// ft_lstadd_front(&head, ft_lstnew("hi again!"));
	// ft_lstadd_front(&head, ft_lstnew("hi once again!"));
	// printlist(head);
	// t_list *newlist = ft_lstmap(head, changechr, del);
	// printf("%s\n", (char *)newlist->content);
	// printlist(newlist);

	// // lstlast
	// t_list *head = ft_lstnew("hello world!");
	// ft_lstadd_front(&head, ft_lstnew("hi again!"));
	// ft_lstadd_front(&head, ft_lstnew("hi once again!"));
	// printf("%s\n", ft_lstlast(head)->content);
	// printlist(head);

	// // lstiter
	// t_list *head = ft_lstnew("hello world!");
	// ft_lstadd_front(&head, ft_lstnew("hi again!"));
	// ft_lstadd_front(&head, ft_lstnew("hi once again!"));
	// ft_lstiter(head, &print);

	// // lstdelone
	// t_list *head = ft_lstnew("hello world!");
	// ft_lstdelone(head, &del);

	// // lstclear
	// t_list *head = ft_lstnew("hello world!");
	// ft_lstadd_front(&head, ft_lstnew("hi again!"));
	// ft_lstadd_front(&head, ft_lstnew("hi once again!"));
	// printlist(head);
	// ft_lstclear(&head, &del);
	// printlist(head);

	// // lstadd_front
	// t_list *head = ft_lstnew("hello world!");
	// ft_lstadd_front(&head, ft_lstnew("hi again!"));
	// printlist(head);

	// // lstadd_back
	// t_list *head = ft_lstnew("hello world!");
	// ft_lstadd_back(&head, ft_lstnew("hi again!"));
	// printlist(head);

	// // calloc

	// // bzero
	// char c[9] = "testtest";
	// printf("%s\n", c);
	// ft_bzero(c, 0);
	// printf("when n is 0 the string is %s\n", c);
	// ft_bzero(c, 3);
	// char *d = c + 3;
	// printf("when n is 3 the string is %s\n", d);

	// // atoi
	// char *n = "\t\v\f\r\n \f-06050";
	// int i1 = atoi(n);
	// int i2 = ft_atoi(n);
	// printf("%i\n", i1);
	// printf("%i\n", i2);

	test_itoa();
	test_printf();
	return 0;
}