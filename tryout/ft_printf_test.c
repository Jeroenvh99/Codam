#include"libft.h"
#include<stdio.h>
#include<string.h>
#include<limits.h>
#include<assert.h>

static int	getformatlength(int count, t_padding *padinfo)
{
	if (padinfo->padc == '0' && padinfo->prec < 1 && padinfo->width > count)
	{
		padinfo->prec += (padinfo->width - count);
		count = padinfo->width;
	}
	if (count < padinfo->prec)
		count = padinfo->prec;
	return (count);
}

static int	getlength_itoa(long int n, t_padding *padinfo)
{
	int	count;

	count = 0;
	if (padinfo->prec > -1)
		padinfo->padc = ' ';
	if (padinfo->prec == 0 && n == 0)
		return (0);
	if (n < 0 || (n >= 0 && (padinfo->sign == '+' || padinfo->blank == 'y')))
	{
		++count;
		++padinfo->prec;
	}
	if (n < 0)
		n *= -1;
	while ((n / 10) > 0)
	{
		++count;
		n /= 10;
	}
	if (n < 10)
		++count;
	count = getformatlength(count, padinfo);
	return (count);
}

static void	getstr(long int n, int i, char *c, t_padding *padinfo)
{
	if (padinfo->sign == '+' && n >= 0)
		c[0] = '+';
	if (padinfo->blank == 'y' && n >= 0)
		c[0] = ' ';
	if (n < 0)
	{
		c[0] = '-';
		n *= -1;
	}
	--i;
	while (n > 9)
	{
		c[i] = (n % 10) + '0';
		n /= 10;
		--i;
	}
	c[i] = n + '0';
	--i;
	while (i >= 0 && !c[i])
	{
		c[i] = '0';
		--i;
	}
}

char	*ft_itoa_format(long int n, t_padding *padinfo)
{
	int		len;
	char	*c;

	len = getlength_itoa(n, padinfo);
	c = ft_calloc(len + 1, 1);
	if (!c)
		return (NULL);
	getstr(n, len, c, padinfo);
	return (c);
}

static int	getlength_uitoa(unsigned int n, t_padding *padinfo)
{
	int	count;

	count = 0;
	if (padinfo->prec > -1)
		padinfo->padc = ' ';
	if (padinfo->prec == 0 && n == 0)
		return (0);
	while ((n / 10) > 0)
	{
		++count;
		n /= 10;
	}
	if (n < 10)
		++count;
	if (count < padinfo->prec)
		count = padinfo->prec;
	if (padinfo->padc == '0' && padinfo->prec < 1 && padinfo->width > count)
	{
		padinfo->prec += (padinfo->width - count);
		count = padinfo->width;
	}
	return (count);
}

char	*ft_uitoa(unsigned int n, t_padding *padinfo)
{
	padinfo->sign = '-';
	padinfo->blank = 'n';
	// int		i;
	// char	*c;

	// i = getlength_uitoa(n, padinfo);
	// c = ft_calloc(i + 1, 1);
	// if (!c)
	// 	return (NULL);
	// --i;
	// while (n > 9)
	// {
	// 	c[i] = (n % 10) + '0';
	// 	n /= 10;
	// 	--i;
	// }
	// c[i] = n + '0';
	// while (i > 0)
	// {
	// 	--i;
	// 	c[i] = '0';
	// }
	return (ft_itoa_format(n, padinfo));
}

void test_int_min(t_padding *padinfo){
	char *itoa_res;
	char *itoa_orig;
	itoa_res = ft_itoa_format(INT_MIN, padinfo);
	itoa_orig = "-2147483648";
	assert(!strcmp(itoa_res, itoa_orig));
	printf("itoa:  %s, system itoa %s\n", itoa_res, itoa_orig);
}

void test_0(t_padding *padinfo){
	char *itoa_res;
	char *uitoa_res;
	itoa_res = ft_itoa_format(0, padinfo);
	uitoa_res = ft_uitoa(0, padinfo);
	assert(!strcmp(itoa_res, uitoa_res));
	printf("itoa:  %s, uitoa %s\n", itoa_res, uitoa_res);
}

void test_int_max(t_padding *padinfo){
	char *itoa_res;
	char *uitoa_res;
	itoa_res = ft_itoa_format(INT_MAX, padinfo);
	uitoa_res = ft_uitoa(INT_MAX, padinfo);
	assert(!strcmp(itoa_res, uitoa_res));
	printf("itoa:  %s, uitoa %s\n", itoa_res, uitoa_res);
}

void test_uint_max(t_padding *padinfo){
	char *itoa_res;
	char *uitoa_res;
	itoa_res = ft_itoa_format(UINT_MAX, padinfo);
	uitoa_res = ft_uitoa(UINT_MAX, padinfo);
	assert(!strcmp(itoa_res, uitoa_res));
	printf("itoa:  %s, uitoa %s\n", itoa_res, uitoa_res);
}

void test_plus(t_padding *padinfo){
	padinfo->sign = '+';
	char *itoa_res;
	char *uitoa_res;
	itoa_res = ft_itoa_format(INT_MAX, padinfo);
	uitoa_res = ft_uitoa(INT_MAX, padinfo);
	// assert(!strcmp(itoa_res, uitoa_res));
	printf("itoa:  %s, uitoa %s, system printf int : %+i, system printf uint % u\n", itoa_res, uitoa_res, INT_MAX, INT_MAX);
}

int main(){
	t_padding padinfo;
	padinfo.alt = 'n';
	padinfo.width = -1;
	padinfo.adj = 'r';
	padinfo.sign = '-';
	padinfo.padc = ' ';
	padinfo.blank = 'n';
	padinfo.prec = -1;
	test_int_min(&padinfo);
	test_0(&padinfo);
	test_int_max(&padinfo);
	test_uint_max(&padinfo);
	test_plus(&padinfo);
	return 0;
}
