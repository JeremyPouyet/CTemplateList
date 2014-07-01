B1;2802;0cCTemplateList
=============

Simple library which allow every structure to become a double link list.

The library is templated by metaprogramming.

Code Example :
--------------

1. Create your list in a my_list.h file :

```c
typedef struct	s_foo
{
   int		data1;
   char		*data2;
}		t_foo;
```
2. Then add your type in your main.c file :
```c
#include "my_list.h"

#define T t_foo
#include "list.c" /* include list.c : IMPORTANT */
#undef T
```
3. And finally use your list as following :
```c
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
```
See list.h to to know all the functions.

####Contact :

If you find bug or have optimization ideas, contact me at jeremy.pouyet@epitech.eu