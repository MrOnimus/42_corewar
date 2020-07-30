#include "corewar.h"

t_cursor	*init_cursor(t_champion *champ, int place)
{
	t_cursor		*cursor;
	static int	cursor_id;

	if (!(cursor = (t_cursor *)ft_memalloc(sizeof(t_cursor))))
		put_error(6);
	cursor->id = ++cursor_id;
	cursor->carry = 0;
	cursor->op_code = 0;//last code?
	cursor->last_live = 0;
	cursor->cycles_to_exec = 0;
	cursor->place = place;
	cursor->next = NULL;
	cursor->reg[0] = -(champ->number);
	cursor->champion = champ;
	return (cursor);
}


int main (int argc, char** argv)
{
	int				num;
	t_champion		**champions;
	t_vm			field;

	num = get_num_of_players(argc, argv);
	
	if (num > MAX_PLAYERS)
		put_error(0);
	else if (num == 0)
		put_error(1);
	else if (num == -1)
		put_error(2);
	else
		printf("Number of Players: %d.\n", num);
	
	if ((champions = ft_memalloc(sizeof(t_champion*) * num)) == NULL)
		put_error(3);
	if (!valid_n_flags(argc, argv, num))
		put_error(4);
	if (!fill_number_players(argc, argv, champions, num))
		put_error(5);
	field.dump = get_dump(argc, argv);
	printf("Dump: %d.\n", field.dump);
	//here we get player struct with name of files, reg1 and num of player
	set_parameters(&field, champions, num);
	//TODO: Help function
	//TODO: field->last_alive
	//TODO: Загнать в минус или зафолсить флаги, которые не будут использоваться (будут ли другие флаги, кроме дампа и номера?)
	print_logo();
	// Инициализация кареток по структуре
	//in a loop
	init_cursor(NULL, 0);//1 champion, place - расположение в памяти. Этой функцией инициализируем все каретки

	//TODO: функция для печати арены в каждый момент времени


	//Игра продолжается до тех пор пока все каретки не умрут, либо пока количество циклов не достигнет максимума, либо dump
	intro(champions, num);
	execute(&field);
	print_players(champions, num);
	//печатаем последнгего выжившего
	//очищаем память
	return (0);
}
