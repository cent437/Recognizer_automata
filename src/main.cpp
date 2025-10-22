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
		push_back(this->edges, 0, "-+");		// переход в q3
		push_back(this->edges, 0, "123456789"); // переход в q1
		push_back(this->edges, 0, "0");			// переход в q2

		push_back(this->edges, 1, "h");			 // Переход в q5
		push_back(this->edges, 1, "l");			 // переход в q9
		push_back(this->edges, 1, "u");			 // переход в q8
		push_back(this->edges, 1, ";");			 // Переход в q7
		push_back(this->edges, 1, "0123456789"); // переход в q1

		push_back(this->edges, 2, "x"); // Переход в q4

		push_back(this->edges, 3, "0");		  // переход в q2
		push_back(this->edges, 3, "1234567"); // переход в q1

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
		push_back(this->edges, 12, ";");				// переход в q7

		push_back(this->edges, 7, "Accept."); // конечная вершина
	}
	/* Функция лексического анализа константы. */
	void analize(std::string constant)
	{
		std::string condition;
		list *current_stance = this->edges[0];
		vertex = 0;
		bool success = false;
		printf("q%llu ", vertex);
		while (current_stance)
		{
			condition = current_stance->data;
			if (constant.find(condition) == std::string::npos)
			{
				vertex = 3;
				printf("q%llu ", vertex);
				current_stance = this->edges[vertex];
				condition = current_stance->data;
				if (constant.find(condition) == std::string::npos)
				{
				}
			}

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
