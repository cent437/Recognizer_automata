typedef struct list
{
    struct list *next;
    struct list *prev;
    char data[100];
} list;
extern list *create_node(char *data);
extern void push_back(list **list_array, unsigned head_index, const char *data);
extern void pop_back(list **list_array, unsigned head_index);

extern void push_front(list **list_array, unsigned head_index, const char *data);
extern void pop_front(list **list_array, unsigned head_index);