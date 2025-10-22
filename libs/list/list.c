#include "list.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

list *create_node(size_t data)
{
    list *p = NULL;
    if (NULL == (p = (list *)malloc(sizeof(list))))
    {
        perror("Ошибка выделения памяти.");
        return p;
    }
    p->data = data;
    p->next = NULL;
    p->prev = NULL;
    return p;
}
void push_back(list **list_array, unsigned head_index, size_t data)
{
    list *p = create_node(data);
    list *iter = list_array[head_index];
    if (list_array[head_index] == NULL && p != NULL)
    {
        list_array[head_index] = p;
        return;
    }
    else if (iter != NULL && p != NULL)
    {
        while (iter->next)
        {
            iter = iter->next;
        }
        iter->next = p;
        p->prev = iter;
        iter = p;
    }
}
void pop_back(list **list_array, unsigned head_index)
{
    list *iter = list_array[head_index];
    if (NULL == list_array[head_index])
    {
        puts("Список пуст.");
        return;
    }

    else if (NULL == list_array[head_index])
    {
        free(iter);
        list_array[head_index] = NULL;
        return;
    }
    else
    {
        while (iter->next)
        {
            iter = iter->next;
        }
        iter = iter->prev;
        free(iter->next);
        iter->next = NULL;
        return;
    }
}

void push_front(list **list_array, unsigned head_index, size_t data)
{
    list *p = create_node(data);
    if (list_array[head_index] == NULL && p != NULL)
    {
        list_array[head_index] = p;
        return;
    }
    else if (list_array[head_index] != NULL && p != NULL)
    {
        list_array[head_index]->prev = p;
        list_array[head_index]->prev->next = list_array[head_index];
        list_array[head_index] = list_array[head_index]->prev;
    }
}
void pop_front(list **list_array, unsigned head_index)
{
    list *p = list_array[head_index];
    if (NULL == list_array[head_index])
    {
        puts("Список пуст.");
        return;
    }
    else if (NULL == p->next)
    {
        free(p);
        list_array[head_index] = NULL;
        return;
    }
    else
    {
        list_array[head_index] = p->next;
        free(p);
        list_array[head_index]->prev = NULL;
    }
    return;
}