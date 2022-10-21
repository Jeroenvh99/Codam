void printlist(t_list *head)
{
	while (head)
	{
		printf("%s\n", (char *)head->content);
		head = head->next;
	}
}

int ft_split_lst(char const *s, char c)
{
	t_list	*splits;
	int		i;
	int		j;
	char	prevc;
	char	*split;

	j = 0;
	prevc = dlm;
	while (j == 0 || c[j - 1])
	{
		if ((s[j] == c && prevc != c) || (!s[j] && prevc != c))
		{
			i = 0;
			split = malloc(j);
			while (i < j)
			{
				split[i] = *s;
				++i;
				++s;
			}
			c[i] = '\0';
			j = 0;
			ft_lstadd_back(ft_lstnew(c));
		}
		prevc = c[j];
		if (s[j] == c)
			++j;
		else
			j = 0;
	}
	return (1);
}