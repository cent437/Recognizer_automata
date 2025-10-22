
typedef struct list
{
    struct list *next;
    struct list *prev;
    unsigned long long data;
} list;
extern list *create_node(unsigned long long data);
extern void push_back(list **list_array, unsigned head_index, unsigned long long data);
extern void pop_back(list **list_array, unsigned head_index);

extern void push_front(list **list_array, unsigned head_index, unsigned long long data);
extern void pop_front(list **list_array, unsigned head_index);