#include <stdio.h>

int ft_atoi(char *str){
    int i;
    int nb;
    int sign;
    int sign_counter;

    i = 0;
    nb = 0;
    sign = 1;
    sign_counter = 0;
    
    while(str[i] == ' ' || str[i] == '\t')
        i++;
    while(str[i] == '-' || str[i] == '+')
    {
        if(str[i] == '-')
            sign_counter++;
        i++;
    }
    if(sign_counter % 2 == 0)
        sign = 1;
    else
        sign = -1;
    while(str[i] >= '0' && str[i] <= '9')
    {
        nb = (nb * 10) + str[i] -  '0';
        i++;
    }
    return (nb * sign);
}

int main(void)
{
	int n = ft_atoi("   ---+--+1234ab567");

	printf("%d\n", n);
	return(0);
}
