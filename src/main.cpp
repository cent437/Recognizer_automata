#include <string>
#include <vector>
#include <iostream>
#include <bitset>
#include <ciso646>
extern "C"
{
#include "../libs/list/list.h"
}
class Recognizer
{
private:
	list **edges;
	size_t edges_count, vertex;
	std::bitset<8> mask; // [sign][oct][hex][digit] 00 [base] [end];

public:
	Recognizer()
	{
		edges_count = 13;
		vertex = 0;
		mask = 0;
		this->edges = new list *[edges_count];
		for (size_t i = 0; i < edges_count; i++)
			edges[i] = NULL;

		push_back(this->edges, 0, "123456789"); // переход в q1
		push_back(this->edges, 0, "0");			 // переход в q2
		push_back(this->edges, 0, "-+");			 // переход в q3

		push_back(this->edges, 1, "0123456789"); // переход в q1
		push_back(this->edges, 1, "h");			  // Переход в q5
		push_back(this->edges, 1, "l");			  // переход в q9
		push_back(this->edges, 1, "u");			  // переход в q8
		push_back(this->edges, 1, ";");			  // Переход в q7

		push_back(this->edges, 2, "x"); // Переход в q4

		push_back(this->edges, 3, "1234567"); // переход в q1
		push_back(this->edges, 3, "0");		  // переход в q2

		push_back(this->edges, 4, "0123456789abcdef"); // переход в q12

		push_back(this->edges, 5, "u"); // переход в q6
		push_back(this->edges, 5, "l"); // переход в q10

		push_back(this->edges, 6, ";"); // переход в q7

		push_back(this->edges, 8, "l"); // переход в q10
		push_back(this->edges, 8, "h"); // переход в q11

		push_back(this->edges, 9, "u"); // переход в q6
		push_back(this->edges, 9, "h"); // переход в q11

		push_back(this->edges, 10, ";"); // переход в q7

		push_back(this->edges, 11, ";"); // переход в q7

		push_back(this->edges, 12, "0123456789abcdef"); // переход в q12
		push_back(this->edges, 12, ";");						// переход в q7

		push_back(this->edges, 7, "Accept."); // конечная вершина
	}
	/* Функция лексического анализа константы. */
	void analize(std::string constant)
	{
		std::string condition;
		list *current_stance = this->edges[0];
		bool success = false;
		while (current_stance->next)
		{
			condition = current_stance->data;
			/* Проверка на знак. */
			if ((constant[0] == '-' or constant[0] == '+') and mask[0] == false)
			{
				vertex = 3;
				current_stance = this->edges[vertex];
				printf("q%llu ", vertex);
				mask[0] = true;
			}

			/* Проверка недесятичной константы. */
			else if ((constant[1] == 'x' or constant[0] == '0') and (mask[6] == false))
			{
				if (constant[1] == 'x' and mask[2] == false)
				{
					mask[2] = true;
					mask[6] = true;
					vertex = 4;
					printf("q%llu ", vertex);
					current_stance = this->edges[vertex];
				}
				if (constant[1] == ';')
				{
					success = true;
					vertex = 7;
					printf("q%llu ", vertex);
					current_stance = this->edges[vertex];
				}
				else if (constant[0] == '0' and mask[1] == false)
				{
					mask[1] = true;
					mask[6] = true;
					vertex = 3;
					printf("q%llu ", vertex);
					current_stance = this->edges[vertex];
				}
			}
			/* Поиск цифр в зависимости от системы счисления. */
			else if (constant.find_first_of(current_stance->data) != std::string::npos and mask[4] == false)
			{
				vertex = 1;
				mask[4] = true;
				printf("q%llu ", vertex);
				current_stance = this->edges[vertex];
			}
			/* Поиск ";" в конце константы. */
			else if (constant.find_first_of(current_stance->data) != std::string::npos and mask[7] == false)
			{
				vertex = 7;
				mask[7] = true;
				success = true;
				printf("q%llu ", vertex);
				current_stance = this->edges[vertex];
			}
			else
				current_stance = current_stance->next;
		}
		if (success)
			std::cout << current_stance->data;

		else
			std::cout << "Reject.";
	}
	void print()
	{
		list *iter = NULL;
		for (size_t i = 0; i < edges_count; i++)
		{
			iter = edges[i];
			printf("q%llu: ", i);
			while (iter)
			{
				std::cout << iter->data << "\t";
				iter = iter->next;
			}
			putchar('\n');
		}
	}
};
int main()
{
	std::system("chcp 65001");
	Recognizer rec;
	std::string input;
	std::cout << "Введите константу: ";
	std::cin >> input;
	rec.analize(input);
	putchar('\n');
	return 0;
}
