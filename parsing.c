#include "computor.h"

void	itoa_isnegative(int *n, int *neg)
{
	if (*n < 0){
		*n *= -1;
		*neg = 1;
	}
}



char	*ft_itoa(int n){
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

int      delim(char *str, char **delim)
{
        int count = 0;
        while(delim[count]){
                if (*str == *delim[count] || (*str >= '0' && *str <= '9')){
                        return (1);
                }
                count++;
        }
        return (0);
}

int      count_words(char *str, char **args)
{
        int     count;

        count = 0;
        while (*str && !delim(str, args))
                str++;
        while (*str)
        {
                while (*str && !delim(str, args))
                        str++;
                if (*str && delim(str, args))
                        count++;
                while (*str && delim(str, args))
                        str++;
        }
        return (count);
}

char     *malloc_word(char *str, char **args)
{
        int     i;
        char    *word;

        i = 0;
        while (str[i] && delim(str + i, args))
                i++;
        word = (char *)malloc(sizeof(char) * (i + 1));
        i = 0;
        while (str[i] && delim(str + i, args))
        {
                word[i] = str[i];
                i++;
        }
        word[i] = '\0';
        return (word);
}

char            **ft_split(char *str, char **args)
{
        int     i;
        int     words;
        char    **tab;

        i = -1;
        words = count_words(str, args);
        tab = (char **)malloc(sizeof(char *) * (words + 1));
        while (*str)
        {
                while (*str && !delim(str, args))
                        str++;
                if (*str && delim(str, args))
                        tab[++i] = malloc_word(str, args);
                while (*str && delim(str, args))
                        str++;
        }
        tab[++i] = NULL;
        return (tab);
}

int            str_len(char *strlen){
        int count = 0;

        while (strlen[count])
                count++;
        return count;
}

char            **half_split(char *str){
        int     count = 0;
        char    *tmp = str;

        while (*tmp){
                if (*tmp == '=')
                        break;
                count++;
                tmp++;
        }

        char *left = (char *)malloc(sizeof (char) * (count + 1));
        left[count] = '\0';

        for (int i = 0; i < count; i++)
                left[i] = str[i];

        char *right = (char *)malloc(sizeof (char) * (str_len(str) - count + 1));
        right[str_len(str) - count] = '\0';

        count = 0;
        while (*tmp){
                right[count] = *tmp;
                count++;
                tmp++;
        }

        char **terms = (char **)malloc(sizeof (char *) * 3);
        terms[2] = NULL;

        terms[0] = left;
        terms[1] = right;

        return terms;
}