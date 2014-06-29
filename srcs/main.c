#include <stdlib.h>
#include <stdio.h>
#include "toto.h"
#include "tata.h"

#undef T
#define T t_toto
#include "list.c"

#undef T
#define T t_tata
#include "list.c"

#undef T

static void	init_link(t_tata *l)
{
  static int i = 0;

  l->i = i++;
}

static void	print_list(T_LIST(t_tata) **l)
{
  if (*l)
  {
    printf("i : %d\n", (*l)->value.i);
    print_list(&(*l)->next);
  }
}

int	main()
{
  T_LIST(t_tata)	*la = NULL;
  unsigned int		i;

  for (i = 0 ; i < 20 ; ++i)
  {
    LIST_ADD_LAST(t_tata)(&la);
    init_link(LIST_GET_LAST(t_tata)(&la));
  }
  LIST_DEL_FIRST(t_tata)(&la);
  LIST_DEL_AT(t_tata)(&la, 9);
  LIST_DEL_LAST(t_tata)(&la);

  print_list(&la);
  LIST_DEL_ALL(t_tata)(&la);
  return (0);
}
