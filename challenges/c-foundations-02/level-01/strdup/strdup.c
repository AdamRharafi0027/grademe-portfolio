#include <stdio.h>
#include <stdlib.h>

size_t gm_strlen(const char *str)
{
    size_t i;
    i = 0;
    while (str[i])
        i++;
    return (i);
}

char *gm_strdup(const char *src)
{
    
    int i = 0;
    char *dest;
    dest = malloc(sizeof(char) * (gm_strlen(src)+1));
    if (dest == NULL)
        return (NULL);
    while (src[i])
        {
            dest[i] = src[i];
            i++;
        }
    dest[i] = '\0';
    return (dest);
}