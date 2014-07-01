#include "templates.h"

/*
** T_LIST is just a define to make the code proper.
** You can declare a TEMPLATE(foo, list) bar;
** Or a T_LIST(foo) bar;x
*/

# define T_LIST(type) TEMPLATE(type, list)
# define T_NODE(type) T_LIST(type)

/*
** link generated during compilation time :
** ----------------------------------------
**
** For T = foo, it's create a foo_list type containing :
** - a foo (the value)
** - the next and prev foo_list pointers
*/

typedef struct			T_LIST(T)
{
  T				value;
  struct T_LIST(T)		*prev;
  struct T_LIST(T)		*next;
}				T_LIST(T);

/*
** Real functions prototypes :
** ---------------------------
**
** For example, int TEMPLATE(T, add_last)(T_LIST(T) **list);
** For T = foo,
** will generates the following prototy :
** int foo_add_last(foo_list **list);
*/

T	*TEMPLATE(T, add_last)(T_LIST(T) **list);
T	*TEMPLATE(T, add_first)(T_LIST(T) **list);
T	*TEMPLATE(T, add_at)(T_LIST(T) **list, unsigned int i);

void	TEMPLATE(T, del_at)(T_LIST(T) **list, unsigned int i);
void	TEMPLATE(T, del_last)(T_LIST(T) **list);
void	TEMPLATE(T, del_first)(T_LIST(T) **list);
void	TEMPLATE(T, del_all)(T_LIST(T) **list);

T	*TEMPLATE(T, get_last)(T_LIST(T) **list);
T	*TEMPLATE(T, get_first)(T_LIST(T) **list);
T	*TEMPLATE(T, get_at)(T_LIST(T) **list, unsigned int i);

/*
** Macro prototype to use :
** ------------------------
**
** To use the list, prefere the wollowing syntaxe
** You'll prefere to write :
** LIST_ADD_LAST(foo)(&my_list);
** than
** TEMPLATE(foo, add_last)(&my_list);
*/

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
