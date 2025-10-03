#include <string>
#include <vector>
extern "C"
{
#include "../libs/list/list.h"
}
class Recognizer
{
private:
	list **edges;

public:
	Recognizer(unsigned edges_count)
	{
		list **heads = new list *[edges_count];
		push_back(edges, 0, "123456789"); // переход в q1
		push_back(edges, 0, "0");		  // переход в q2
		push_back(edges, 0, "-+");		  // переход в q3
		push_back(edges, 1, "0123456789");
		push_back(edges, 1, "0123456789");
	}
};
int main()
{
	std::system("chcp 65001");
	Recognizer avto(13);

	return 0;
}
