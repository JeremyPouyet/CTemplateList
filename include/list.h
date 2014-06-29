/*
** list.h for list in /home/pouyet_j/perso
**
** Made by Jérémy POUYET
** Login   <pouyet_j@epitech.net>
**
** Started on  Wed Jun 18 13:58:12 2014 Jérémy POUYET
** Last update Thu Jun 26 17:02:44 2014 Jérémy POUYET
*/

#include "templates.h"

# define T_LIST(type) TEMPLATE(type, list)

typedef struct			T_LIST(T)
{
  T				value;
  struct T_LIST(T)		*prev;
  struct T_LIST(T)		*next;
}				T_LIST(T);

int	TEMPLATE(T, add_last)(T_LIST(T) **list);
int	TEMPLATE(T, add_first)(T_LIST(T) **list);
int	TEMPLATE(T, add_at)(T_LIST(T) **list, unsigned int i);

void	TEMPLATE(T, del_at)(T_LIST(T) **list, unsigned int i);
void	TEMPLATE(T, del_last)(T_LIST(T) **list);
void	TEMPLATE(T, del_first)(T_LIST(T) **list);
void	TEMPLATE(T, del_all)(T_LIST(T) **list);

T	*TEMPLATE(T, get_last)(T_LIST(T) **list);
T	*TEMPLATE(T, get_first)(T_LIST(T) **list);
T	*TEMPLATE(T, get_at)(T_LIST(T) **list, unsigned int i);

# define LIST_ADD_LAST(type) TEMPLATE(type, add_last)
# define LIST_ADD_FIRST(type) TEMPLATE(type, add_first)
# define LIST_ADD_AT(type) TEMPLATE(type, add_at)

# define LIST_DEL_AT(type) TEMPLATE(type, del_at)
# define LIST_DEL_LAST(type) TEMPLATE(type, del_last)
# define LIST_DEL_FIRST(type) TEMPLATE(type, del_first)
# define LIST_DEL_ALL(type) TEMPLATE(type, dell_all)

# define LIST_GET_LAST(type) TEMPLATE(type, get_last)
# define LIST_GET_FIRST(type) TEMPLATE(type, get_first)
# define LIST_GET_AT(type) TEMPLATE(type, get_at)
