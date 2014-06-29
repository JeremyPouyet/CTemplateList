CTemplateList
=============

Simple library which allow every structure to become a double link list.

The library is templated by metaprogramming.

Code Example :
--------------

Create your list in a my_list.h file :

typedef struct	s_foo
{
   int		data1;
   char		*data2;
}		t_foo;

Then add your type in your main.c file :

#include "my_list.h"

#define T t_foo
#undef T
#include "list.c" /* include list.c : IMPORTANT */

And finally use your list as following :

int	main()
{
   T_LIST(t_foo) *my_list = NULL;

   LIST_ADD_FIRST(t_foo)(&my_list);
   LIST_ADD_LAST(t_foo)(&my_list);
   LIST_ADD_AT(t_foo)(&my_list, 1);

   LIST_DEL_FIRST(t_foo)(&my_list);
   LIST_DEL_LAST(t_foo)(&my_list);
   LIST_DEL_AT(t_foo)(&my_list, 0);
}

See list.h to to know all the functions.