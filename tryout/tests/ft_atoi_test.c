#include<stdio.h>

int	ft_atoi(char *str)
{
	long int	nb;
	int			i;
	int			multiplier;

	nb = 0;
	i = 0;
	multiplier = 1;
	while (str[i] && (str[i] == ' ' || str[i] == '	'))
		i++;
	while (str[i] && (str[i] == '-' || str[i] == '+'))
	{
		if (str[i] == '-')
			multiplier *= -1;
		i++;
	}
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		nb = nb * 10 + (str[i] - '0');
		i++;
	}
	if (multiplier < 1)
		nb *= multiplier;
	return (nb);
}

void NULL_should_give_0(){
    int number;
    number = ft_atoi(NULL);
    if (number == 0){
        printf("a NULL input gave the result 0\n");
        return;
    }
    printf("a NULL input didn't give the result 0 but instead resulted in: %i\n", number);
    return;
}

void eight_should_give_8(){
    char word[5] = "8";
    int number;
    number = ft_atoi(word);
    if (number == 8){
        printf("an input of eight gave the result 8\n");
        return;
    }
    printf("an input of eight didn't give the result 8 but instead resulted in: %i\n", number);
    return;
}

int main(){
    eight_should_give_8();
    return 0;
}