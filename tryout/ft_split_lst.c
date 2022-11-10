#include"libft.h"
#include<stdlib.h>
#include<stdio.h>

void	del(void *node)
{
	free(node);
	node = NULL;
}

void printlist(t_list *head)
{
	while (head)
	{
		printf("%s\n", (char *)head->content);
		head = head->next;
	}
}

static char	*getsplit(const char **s, char dlm)
{
	int		i;
	char	prevc;
	char	*split;

	i = 0;
	prevc = dlm;
	while (i == 0 || s[0][i - 1])
	{
		if ((s[0][i] == dlm && prevc != dlm) || (!(s[0][i])
			&& prevc != dlm))
		{
			split = ft_substr(s[0], 0, i);
			if (!split)
				return (NULL);
			s[0] += i;
			return (split);
		}
		prevc = s[0][i];
		++i;
	}
	return (NULL);
}

t_list	*ft_split_lst(char const *s, char c)
{
	t_list	*arr;
	t_list	*newnode;

	arr = NULL;
	if (!s)
		return (NULL);
	while (*s)
	{
		while (*s == c)
			++s;
		newnode = ft_lstnew(getsplit(&s, c));
		if (arr && !newnode)
		{
			ft_lstclear(&arr, del);
			return (NULL);
		}
		ft_lstadd_back(&arr, newnode);
	}
	return (arr);
}

int main(){
	t_list *splitarr;
	splitarr = ft_split_lst("      split       this for   me  !       hfhjutyk", ' ');
	printlist(splitarr);
	ft_lstclear(&splitarr, del);
	splitarr = NULL;
	splitarr = ft_split_lst(NULL, ' ');
	printlist(splitarr);
	ft_lstclear(&splitarr, del);
	splitarr = NULL;
	splitarr = ft_split_lst("vdfbnjfgbnghvbdfkergh", 'b');
	printlist(splitarr);
	ft_lstclear(&splitarr, del);
	splitarr = NULL;
	splitarr = ft_split_lst("Yay,   it works! !!??", ' ');
	printlist(splitarr);
	ft_lstclear(&splitarr, del);
	return 0;
}