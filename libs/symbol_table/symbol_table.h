#include <stdint.h>
#define TABLE_MAX_SIZE 256
#define ID_MAX_SIZE 50

/* Инициализация таблицы идентификаторов
@param table_size размер таблицы.
@param ID_max_length размер идентификатора в таблице.
*/
extern char **init_table(size_t table_size, size_t ID_max_length);

/* Хеш функция */
extern size_t hash(const char *r);

/* Функция вставки в хеш таблицу
@param value_table указатель на таблицу значений.
@param value значение для поиска. */
extern void insert(char **value_table, const char *value);

/* Функция поиска в хеш таблице
@param value_table указатель на строковый массив идентификаторов.
@param value значение для поиска.  */
extern char *search(char **value_table, const char *value);