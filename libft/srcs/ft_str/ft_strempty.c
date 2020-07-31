#include "libft.h"

int     ft_strempty(const char *s)  // FIXME: Norminette!!!
{
	int i;

	i = -1;
	while (++i < (int)ft_strlen(s) + 1)
		if (*(s + i) != 0)
			return (0);
	return (1);
}
