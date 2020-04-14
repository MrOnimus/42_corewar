#include "corewar.h"

void		put_error(int err_num)
{
	ft_putendl(g_error[err_num]);
	exit(0);
}
