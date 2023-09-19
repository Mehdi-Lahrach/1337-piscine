#include <stdio.h>
#include <string.h>

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	len;

	i = 0;
	len = 0;
	while (src[len] != '\0')
	{
		len++;
	}
	while (i < size -1 && src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (len);
}


int main() {
    char src[] = "Hello, World!";
    char dest[20];

    unsigned int  len = ft_strlcpy(dest, src, sizeof(dest));
	printf("-------------------------------------\n");

	printf("copied string with ftstrlcpy %s\n", dest);
	printf("lenght of copied string with ftstrlcpy %u\n", len);
    return 0;
}
