#include <stdio.h>
#include <stdlib.h>

int ft_strlen(char *s)
{
    int i;

    i = 0;
    while(s[i] != 0)
        i++;
    return (i);
}

char **split(char *s)
{
    char **new_str;
    int i;
    int j;
    int i2;

    if (!s)
        return (0);
    new_str = (char **)malloc(sizeof(char *) * (ft_strlen(s) + 1));
    i = 0;
    j = 0;
    while(s[i] != 0)
    {
        while(s[i] != 0 && (s[i] == ' ' || s[i] == '\t'))
            i++;
        new_str[j] = (char *)malloc(ft_strlen(s) + 1); 
        i2 = 0;
        while(s[i] != 0 && (s[i] != ' ' && s[i] != '\t'))
        {
            new_str[j][i2] = s[i];
            i++;
            i2++;
        }
        new_str[j][i2] = '\0';
        j++;
    }
    new_str[j] = NULL;
    return(new_str);
}
int main(int argc, char *argv[])
{
    char **splitted;
    int i;
    int i2;

    if (argc == 2)
    {
        splitted = split(argv[1]);
        i = -1;
        while(splitted[++i] != 0)
        {
            printf("%s\n", splitted[i]);
            free(splitted[i]);
        }
        free(splitted);
    }
    else 
        return(0);
}