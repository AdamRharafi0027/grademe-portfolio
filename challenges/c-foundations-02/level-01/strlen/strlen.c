#include <stddef.h>

size_t	strlen(const char *s)
{
	int s_len = 0;

	while(s[s_len])
		s_len++;
	return s_len;
}
