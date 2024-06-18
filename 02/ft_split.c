#include <stdlib.h>
#include <stdio.h>

char *ft_strcpy(char *s1, char *s2, int n)
{
	int i;

	i = 0;
	while (n > 0 && s2[i])
	{
		s1[i] = s2[i];
		n--;
		i++; 
	}
	s1[i] = '\0';
	return(s1);
	
}


char	**ft_split(char *str)
{
	int i = 0;
	int j = 0;
	int k = 0;
	int wc = 0;

	while(str[i])
	{
		while(str[i] && (str[i] == '\t' || str[i] == '\n' || str[i] == ' '))
			i++;
		if (str[i])
			wc++;
		while(str[i] && (str[i] != '\t' && str[i] != '\n' && str[i] != ' '))
			i++;
	}

	char **out = (char **)malloc(sizeof(char *) * (wc + 1));
	if(out == NULL)
		return(NULL);
	
	i = 0;
	while(str[i])
	{
		while(str[i] && (str[i] == '\t' || str[i] == '\n' || str[i] == ' '))
			i++;
		j = i;
		while(str[i] && (str[i] != '\t' && str[i] != '\n' && str[i] != ' '))
			i++;
		if(i > j)
		{
			 out[k]= (char *) malloc(sizeof(char) * ((i - j) + 1));
			ft_strcpy(out[k], &str[j], (i - j));
			k++;
		}
	}
	out[k] = NULL;
	return(out);
}

int main()
{
    char str[] = "Hello world! This\tis a test\nstring.";
    char **result = ft_split(str);
    int i = 0;

    // 分割された文字列を出力
    while (result[i])
    {
        printf("Word %d: %s\n", i, result[i]);
        i++;
    }

    // メモリの解放はこの例では行わない
    // for (int j = 0; j < i; j++)
    // {
    //     free(result[j]);
    // }
    // free(result);

    return 0;
}