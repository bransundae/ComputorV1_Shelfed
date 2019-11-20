#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static void	itoa_isnegative(int *n, int *neg)
{
	if (*n < 0){
		*n *= -1;
		*neg = 1;
	}
}

static char	*ft_itoa(int n){
	int tmp;
	int len;
	int neg;
	char *str;

	tmp = n;
	len = 2;
	neg = 0;
	itoa_isnegative(&n, &neg);
	while (tmp /= 10)
		len++;
	len += neg;
	if ((str = (char *)malloc(sizeof(char)* len)) == NULL)
		return (NULL);
	str[--len] = '\0';
	while (len --)
	{
		str[len] = n % 10 + '0';
		n = n/10;
	}
	if (neg)
		str[0] = '-';
	return (str);
}

static int      delim(char *str)
{
        if (*str == '*' || *str == '+' || *str == '-' || *str == '/' || *str == ' ' || *str == '=' || *str == '\n' || *str == '\0')
                return (1);
	if(*str == ' ')
	{
		str++;
		if (*str <= '9' && *str >= '0')
			return(1);
		str-=2;
		if (*str == ',' || (*str <= '9' && *str >= '0'))
			return (1);
	}
        return (0);
}

static int      count_words(char *str)
{
        int     count;

        count = 0;
        while (*str && delim(str))
                str++;
        while (*str)
        {
                while (*str && delim(str))
                        str++;
                if (*str && !delim(str))
                        count++;
                while (*str && !delim(str))
                        str++;
        }
        return (count);
}

static char     *malloc_word(char *str)
{
        int     i;
        char    *word;

        i = 0;
        while (str[i] && !delim(str + i))
                i++;
        word = (char *)malloc(sizeof(char) * (i + 1));
        i = 0;
        while (str[i] && !delim(str + i))
        {
                word[i] = str[i];
                i++;
        }
        word[i] = '\0';
        return (word);
}

char            **ft_split(char *str)
{
        int     i;
        int     words;
        char    **tab;

        i = -1;
        words = count_words(str);
        tab = (char **)malloc(sizeof(char *) * (words + 1));
        while (*str)
        {
                while (*str && delim(str))
                        str++;
                if (*str && !delim(str))
                        tab[++i] = malloc_word(str);
                while (*str && !delim(str))
                        str++;
        }
        tab[++i] = NULL;
        return (tab);
}

int main(int argc, char **argv){
    
    char **terms;

    if (argc == 2){
        terms = ft_split(argv[1]);
        for (int i = 0; terms[i] != NULL; i++){
            printf("%s %d %s %s\n", "VALUE ", i+1, ":", terms[i]);
        }
    }
}