#include<unistd.h>
#include<stdio.h>

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while (i == 0 || (s1[i - 1] && s2[i - 1]))
	{
		if ((unsigned char)s1[i] != (unsigned char)s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		else
			++i;
	}
	return (0);
}

int checkduplicates(int argc, char **argv)
{
    char    *arg;
    int     i;
    int     j;

    i = 1;
    j = 1;
    while (i < argc)
    {
        arg = argv[i];
        while (j < argc)
        {
            if (j != i && ft_strcmp(arg, argv[j]) == 0)
                return (0);
            ++j;
        }
        ++i;
    }
    return (1);
}

int main(int argc, char **argv)
{
    t_list  *a;
    t_list  *b;
    if (argc > 1)
    {
        if (checkduplicates(argc, argv) == 0)
        {
            write(2, "error\n", 6);
        }
    }
    return (0);
}