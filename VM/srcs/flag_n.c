#include "corewar.h"

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
			create_player(champions, i, cnt_champ(argc, argv, cnt));
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
				create_player(champions, cur_num, argv[i + 2]);
		}
	}
	fill_pl_wo_num(argc, argv, champions, n_pl);
	return (1);
}

