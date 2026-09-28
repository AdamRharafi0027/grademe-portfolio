#include <stddef.h>
char	*gm_strchr(const char *s, int c)
{
	(void)s;
	(void)c;

    size_t i;
    i = 0;
    while (s[i])
    {
        if (s[i] == c)
            return ((char *)&s[i]);
        i++;
    }
	if (c == '\0')
		return ((char *)&s[i]);
	return (NULL);
}