#include <stdlib.h>
#include <stdio.h>
#include "list_exemple_a.h"
#include "list_exemple_b.h"

/*
** Includes .c file containing the list for each possibilities
*/

#undef T
#define T t_a
#include "list.c"

#undef T
#define T t_b
#include "list.c"

#undef T

/*
** two simple fnuctions for my example
*/

static void	init_link(t_a *l)
{
  static int i = 0;

  l->i = i++;
}

static void	print_list(T_LIST(t_a) **l)
{
  if (*l)
  {
    printf("i : %d\n", (*l)->value.i);
    print_list(&(*l)->next);
  }
}

/*
** Here, I create a list of 20 nodes
** Then, I delete some node
** FInally, I display my list and I delete it
*/

int	main()
{
  T_LIST(t_a)	*la = NULL;
  unsigned int		i;

  for (i = 0 ; i < 20 ; ++i)
  {
    LIST_ADD_LAST(t_a)(&la);
    init_link(LIST_GET_LAST(t_a)(&la));
  }
  LIST_DEL_FIRST(t_a)(&la);
  LIST_DEL_AT(t_a)(&la, 9);
  LIST_DEL_LAST(t_a)(&la);

  print_list(&la);
  LIST_DEL_ALL(t_a)(&la);
  return (0);
}
