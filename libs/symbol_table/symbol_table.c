#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define TABLE_MAX_SIZE 256
char **init_table(size_t table_size, size_t ID_max_length)
{
    char **value_table = (char **)malloc(table_size * sizeof(char *));
    for (size_t i = 0; i < table_size; i++)
    {
        value_table[i] = (char *)malloc(ID_max_length * sizeof(char));
        memset(value_table[i], '\0', ID_max_length);
    }
    return value_table;
}
size_t hash(const char *r)
{
    size_t n = 0;
    for (size_t i = 0; i < strlen(r); i++)
    {
        n = n * 3;
        n += r[i];
        n = n % TABLE_MAX_SIZE;
    }

    return n;
}
void insert(char **value_table, const char *value)
{
    size_t n = 0;
    if (value_table == NULL)
    {
        puts("Таблица значений отсутствует.");
        return;
    }

    strcpy(value_table[hash(value)], value);
}
/* Функция поиска в хеш таблице */
char *search(char **value_table, const char *value)
{
    size_t n = hash(value);
    if (value_table == NULL)
    {
        puts("Таблица значений отсутствует.");
        return NULL;
    }

    if (strcmp(value_table[n], "\0") == 0)
        return NULL;
    else
        return value_table[n];
}