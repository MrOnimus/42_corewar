#include "corewar.h"

int get_num_of_players(int argc, char **argv)
{
	int i;
	int res;

	i = 0;
	res = 0;
	while (++i < argc)
		if (!ft_strequ(argv[i], "-dump") && !ft_strequ(argv[i], "-n"))
			res++;
		else if (ft_strequ(argv[i], "-dump") && i + 1 < argc && ft_strisnumeric(argv[i + 1]))
			i++;
		else if (ft_strequ(argv[i], "-n") && i + 2 < argc && ft_strisnumeric(argv[i + 1]) &&
			!ft_strequ(argv[i + 2], "-dump") && !ft_strequ(argv[i + 2], "-n"))
			i++;
		else
			return (-1);//После флага ничего нет, либо не натуральное число или ноль		
	return res;
}

int valid_n_flags(int argc, char** argv, int n_pl)
{
	int i;
	int j;
	int cur_num;

	j = 0;
	while (++j < argc)
	{
		i = 0;
		if (ft_strequ(argv[j], "-n"))
		{
			cur_num = ft_atoi(argv[j + 1]);
			if (cur_num > n_pl || cur_num == 0)
				return 0;
			while (++i < argc)
				if (ft_strequ(argv[i], "-n") && j != i && ft_strequ(argv[j + 1], argv[i + 1]))
					return 0;
		}
	}
	return (1);
}

void fill_num(t_champion** champions, int num, char* str)
{
	champions[num - 1] = ft_memalloc(sizeof(t_champion));
	champions[num - 1]->number = num;
	champions[num - 1]->reg[1] = -num;
	champions[num - 1]->filename = str;
}
char *cnt_champ(int argc, char** argv, int cnt)
{
	int i;
	int j;

	j = 0;
	i = 0;
	while (j <= cnt && ++i < argc)
	{
		if (ft_strequ(argv[i], "-n"))
			i += 2;
		else
			j++;
	}
	return (argv[i]);
}

void fill_pl_wo_num(int argc, char** argv, t_champion** champions, int n_pl)
{
	int i;
	int cur_num;
	int flag;
	int cnt;

	i = 0;
	cnt = 0;
	while (++i <= n_pl)
	{
		cur_num = 0;
		flag = 0;
		while (++cur_num < argc)
		{
			if (ft_strequ(argv[cur_num], "-n") && i == ft_atoi(argv[cur_num + 1]))
			{
				flag = 1;
				break;
			}
		}
		if (!flag)
		{
			fill_num(champions, i, cnt_champ(argc, argv, cnt));
			cnt++;
		}
	}
}

int fill_number_players(int argc, char** argv, t_champion** champions, int n_pl)
{
	int i;
	int cur_num;

	i = 0;
	while (++i < argc)
	{
		if (ft_strequ(argv[i], "-n"))
		{
			cur_num = ft_atoi(argv[i + 1]);
			if (champions[cur_num - 1] != NULL)
				put_error(6);
			else
				fill_num(champions, cur_num, argv[i + 2]);
		}
	}
	fill_pl_wo_num(argc, argv, champions, n_pl);
	return (1);
}

