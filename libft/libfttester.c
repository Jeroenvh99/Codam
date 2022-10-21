#include"libft.h"
#include<stdio.h>
#include<ctype.h>

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

void print(void *node){
	printf("%s\n", ((t_list *)node)->content);
}

void	del(void *node)
{
	free(node);
	node = NULL;
}

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

	// isprint
	char c = '\0';
	int n = 0;
	while (c <= 127){
		int i = ft_isprint(c);
		printf("the character %c is %i printable\n", c, i);
		++c;
		if (i){
			++n;
		}
		if (c == 1 && n > 1){
			break;
		}
	}
	if (n == 95){
		printf("the correct number of printable characters is found");
	}

	// toupper
	printf("'a' gives %c\n", (char)ft_toupper('a'));
	printf("'8' gives %c\n", (char)ft_toupper('8'));

	// tolower
	printf("'A' gives %c\n", (char)ft_tolower('a'));
	printf("'8' gives %c\n", (char)ft_tolower('8'));

	// substr
	char *str = "01234";
	size_t size = 10;
	char *ret = ft_substr("hola", 4294967295, 18446744073709551615);
	printf("%s", ret);
	char *ret2 = ft_substr("", 1, 1);
	printf("%s", ret2);

	// strtrim
	char *s1 = "  \t \t \n   \n\n\n\t";
	char *s2 = "";
	char *ret = ft_strtrim(s1, " \n\t");
	printf("%s", ret);

	// strrchr
	char s[15] = "adHd fdklHds";
	printf("%s\n", ft_strrchr(s, 543));
	printf("%s\n", ft_strrchr(s, 'g'));

	// strnstr
	char c[21] = "dfjoirfjrehgudfragtr";
	char n0[7] = "";
	char n1[7] = "udfr";
	char n2[7] = "udcr";
	printf("%s\n", ft_strnstr(c, n0, 16));
	printf("%s\n", ft_strnstr(c, n1, 16));
	printf("%s", ft_strnstr(c, n2, 16));

	// strncmp
	char s0[8] = "asbfgbfg";
	char s1[8] = "asbfgbfg";
	char s2[8] = "asbkubfg";
	char s3[8] = "asbfgb";
	printf("%i\n", (ft_strncmp(s0, s1, 0)));
	printf("%i\n", (strncmp(s0, s1, 0)));
	printf("%i\n", (ft_strncmp(s0, s3, 8)));
	printf("%i\n", (ft_strncmp(s0, s1, 3)));
	printf("%i\n", (ft_strncmp(s0, s2, 3)));
	printf("%i\n", (ft_strncmp(s0, s3, 3)));
	printf("%i\n", ft_strncmp("hello", "hel", 4));

	// strmapi
	printf("%s", ft_strmapi("Hello", changec));

	// strlen
	int n = ft_strlen("hithere");
	if (n == 7){
		printf("the length of the string is counted correctly\n");
	}
	else{
		printf("the length of the string hithere isn't counted correctly");
		return 1;
	}
	n = ft_strlen("");
	if (n == 0){
		printf("the length of the empty string is counted correctly\n");
	}
	else{
		printf("the length of the empty string isn't counted correctly");
		return 1;
	}
	printf("inputting NULL should give a segmentation fault");
	n = ft_strlen(NULL);

	// strlcpy

	//strlcat
	char *src = "aaa";
	char dst2[20];
	ft_strlcat(dst2, NULL, 20);

	// strjoin
	char s0[] = "hello";
	char s1[] = " Bruno";
	printf("%s", ft_strjoin(s0, s1));

	// striteri
	ft_striteri("Hello", print);

	// strdup
	char c[4] = "bfd";
	char c1[2] = "";
	printf("%s\n", ft_strdup(c));
	printf("%s\n", ft_strdup(c1));

	// strchr
	char s[15] = "teste";
	printf("%s\n", ft_strchr(s, 'e'));
	printf("%s\n", ft_strchr(s, 'g'));

	// putstr
	ft_putstr_fd("this is a string that's printed to standard output", 1);

	// putnbr
	ft_putnbr_fd(INT_MAX, 1);
	printf("\n");
	ft_putnbr_fd(INT_MIN, 1);
	printf("\nmin is %i, max is %i\n", INT_MIN, INT_MAX);
	ft_putnbr_fd(10, 1);
	printf("\n");
	ft_putnbr_fd(100, 1);
	printf("\n");
	ft_putnbr_fd(5737, 1);
	printf("\n");
	ft_putnbr_fd(4656780, 1);

	// putendl
	ft_putendl_fd("string is on standard output followed by a newline", 1);

	// putchar
	printf("the following character is on the standard error:");
	ft_putchar_fd('g', 1);
	printf("\nthe following character is on the standard output:");
	ft_putchar_fd('k', 1);
	ft_putchar_fd('d', 1);

	// memset
	char c[6] = "hello";
	printf("%s\n", c);
	ft_memset(c, 5, 3);
	printf("%s", c);

	// memmove
	char a[] = "hello";
	char b[] = "hiagain";
	ft_memmove(&a, &b, 2);
	printf("The contents of string a are:%s\n", a);
	printf("The contents of string b are:%s", b);

	// memcpy
	ft_memcpy(NULL, NULL, 5);

	// memcmp

	// memchr
	char *mem = "9865478";
	printf("%s", ft_memchr(mem, '6', 6));

	// lstsize
	t_list *head = ft_lstnew("hello world!");
	ft_lstadd_front(&head, ft_lstnew("hi again!"));
	printf("%i", ft_lstsize(head));

	// lstnew
	t_list *node = ft_lstnew("hello world!");
	printf("%s", (char *)node->content);

	// lstmap
	t_list *head = ft_lstnew("hello world!");
	ft_lstadd_front(&head, ft_lstnew("hi again!"));
	ft_lstadd_front(&head, ft_lstnew("hi once again!"));
	printlist(head);
	t_list *newlist = ft_lstmap(head, changechr, del);
	printlist(newlist);

	// lstlast
	t_list *head = ft_lstnew("hello world!");
	ft_lstadd_front(&head, ft_lstnew("hi again!"));
	ft_lstadd_front(&head, ft_lstnew("hi once again!"));
	printf("%s\n", ft_lstlast(head)->content);
	printlist(head);

	// lstiter
	t_list *head = ft_lstnew("hello world!");
	ft_lstadd_front(&head, ft_lstnew("hi again!"));
	ft_lstadd_front(&head, ft_lstnew("hi once again!"));
	ft_lstiter(head, &print);

	// lstdelone
	t_list *head = ft_lstnew("hello world!");
	ft_lstdelone(head, &del);

	// lstclear
	t_list *head = ft_lstnew("hello world!");
	ft_lstadd_front(&head, ft_lstnew("hi again!"));
	ft_lstadd_front(&head, ft_lstnew("hi once again!"));
	printlist(head);
	ft_lstclear(&head, &del);
	printlist(head);

	// lstadd_front
	t_list *head = ft_lstnew("hello world!");
	ft_lstadd_front(&head, ft_lstnew("hi again!"));
	printlist(head);

	// lstadd_back
	t_list *head = ft_lstnew("hello world!");
	ft_lstadd_back(&head, ft_lstnew("hi again!"));
	printlist(head);

	// itoa
	printf("%s\n", ft_itoa(-67577));
	printf("%s\n", ft_itoa(-100));
	printf("%s\n", ft_itoa(-2147483648));
	printf("%s\n", ft_itoa(2147483647));
	printf("%s", ft_itoa(0));

	// calloc

	// bzero
	char c[9] = "testtest";
	printf("%s\n", c);
	ft_bzero(c, 0);
	printf("when n is 0 the string is %s\n", c);
	ft_bzero(c, 3);
	char *d = c + 3;
	printf("when n is 3 the string is %s\n", d);

	// atoi
	char *n = "\t\v\f\r\n \f-06050";
	int i1 = atoi(n);
	int i2 = ft_atoi(n);
	printf("%i\n", i1);
	printf("%i\n", i2);
	return 0;
}