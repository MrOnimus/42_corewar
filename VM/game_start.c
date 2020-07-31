#include "corewar.h"

void cycles_to_die_check()
{
	printf("штука выпоняющаяся во время проверки");
}

void exec_operation()
{
	//Учитываем цикл запуска операции
	//Если больше ноля, то минусуем количество, если равно нулю, то как-то считаем
	//если ноль, также выполняем операцию, если операция есть. для этого парсим тип, валидируем все, и наверное перемещаем каретку
	printf("выполняется операция");
}

void		cycle_routine(t_vm *vm)
{
	t_cursor *current;

	vm->cycle++;
	vm->cycles_after_check++;
	current = vm->cursors;
	while (current)
	{
		exec_operation();//current, vm);
		current = current->next;
	}
}

void	execute(t_vm *vm)
{
	while (vm->cursor_num)
	{
		if (vm->dump == vm->cycle)
		{
			//print_field(vm);
			exit(0);
		}
		cycle_routine(vm);
		if (vm->cycles_to_die == vm->cycles_after_check
			|| vm->cycles_to_die <= 0)
			cycles_to_die_check();//vm);//то, что происходит, когда идет проверка 
	}
}