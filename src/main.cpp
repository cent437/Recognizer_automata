
#include <iostream>
#include <string.h>
extern "C"
{
#include "../libs/symbol_table/symbol_table.h"
}
static char **values;

int main()
{
	system("chcp 65001");
	system("cls");
	size_t ui_index = -1;
	char symbol[ID_MAX_SIZE], *id;
	values = init_table(TABLE_MAX_SIZE, ID_MAX_SIZE);
	while (ui_index)
	{
		puts("1. Запись в таблицу.\n2. Поиск в таблице.\n0. Выход.");
		scanf("%llu", &ui_index);
		switch (ui_index)
		{
		case 1:
			printf("Введите идентификатор: ");
			scanf_s("%s", symbol, ID_MAX_SIZE);
			rewind(stdin);
			insert(values, symbol);
			break;
		case 2:
			printf("Введите идентификатор: ");
			scanf_s("%s", symbol, ID_MAX_SIZE);
			rewind(stdin);
			id = search(values, symbol);
			if (id == NULL)
			{
				puts("Идентификатор не найден.\nДобавление нового идентификатора.");
				insert(values, symbol);
				break;
			}
			else
				printf("Идентификатор %s расположен по адресу %llu.\n", id, hash(id));
			break;
		}
	}

	return 0;
}
