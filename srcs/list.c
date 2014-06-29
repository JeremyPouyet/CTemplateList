/*
** list.c for list in /home/pouyet_j/perso/Template_List
**
** Made by Jérémy POUYET
** Login   <pouyet_j@epitech.net>
**
** Started on  Thu Jun 19 14:35:38 2014 Jérémy POUYET
** Last update Thu Jun 26 17:46:05 2014 Jérémy POUYET
*/

#include <stdlib.h>
#include "list.h"

static T_LIST(T)	*TEMPLATE(T, create_elem)(void)
{
  return (malloc(sizeof(T)));
}

/*
** add
*/

int		LIST_ADD_LAST(T)(T_LIST(T) **list)
{
  T_LIST(T)	*tmp;
  T_LIST(T)	*new;

  if (!(new = TEMPLATE(T, create_elem())))
    return (0);
  new->next = NULL;
  if (!(*list))
  {
    new->prev = NULL;
    *list = new;
  }
  else
  {
    tmp = *list;
    while (tmp->next)
      tmp = tmp->next;
    new->prev = tmp;
    tmp->next = new;
  }
  return (1);
}

int		LIST_ADD_FIRST(T)(T_LIST(T) **list)
{
  T_LIST(T)	*new;

  if (!(new = TEMPLATE(T, create_elem())))
    return (0);
  new->prev = NULL;
  new->next = *list;
  if (*list)
    (*list)->prev = new;
  *list = new;
  return (1);
}

int		LIST_ADD_AT(T)(T_LIST(T) **list, unsigned int i)
{
  T_LIST(T)	*new;
  T_LIST(T)	*tmp;

  if (i == 0 || !(*list))
    return (LIST_ADD_FIRST(T)(list));
  if (!(new = TEMPLATE(T, create_elem())))
    return (0);
  tmp = *list;
  while (i != 0 && tmp->next)
  {
    tmp = tmp->next;
    --i;
  }
  new->next = tmp;
  new->prev = tmp->prev;
  if (tmp->prev)
    tmp->prev->next = new;
  tmp->prev = new;
  return (1);
}

/*
** del
*/

void		LIST_DEL_AT(T)(T_LIST(T) **list, unsigned int i)
{
  T_LIST(T)	*tmp;

  if (!(*list))
    return ;
  tmp = *list;
  while (i != 0 && tmp->next)
  {
    tmp = tmp->next;
    --i;
  }
  if (tmp->prev)
    tmp->prev->next = tmp->next;
  if (tmp->next)
    tmp->next->prev = tmp->prev;
  free(tmp);
}

void		LIST_DEL_LAST(T)(T_LIST(T) **list)
{
  if (*list)
  {
    if ((*list)->next)
      LIST_DEL_LAST(T)(&(*list)->next);
    else
    {
      if ((*list)->prev)
	(*list)->prev->next = NULL;
      free(*list);
    }
    return ;
  }
}

void		LIST_DEL_FIRST(T)(T_LIST(T) **list)
{
  T_LIST(T)	*tmp;

  tmp = *list;
  if (*list)
  {
    *list = (*list)->next;
    if (*list)
      (*list)->prev = NULL;
    free(tmp);
  }
}

void		LIST_DEL_ALL(T)(T_LIST(T) **list)
{
  if (*list)
  {
    LIST_DEL_ALL(T)(&(*list)->next);
    free(*list);
  }
}

/*
** get
*/

T		*LIST_GET_LAST(T)(T_LIST(T) **list)
{
  if (*list)
  {
    if((*list)->next)
      return LIST_GET_LAST(T)(&(*list)->next);
    return (&(*list)->value);
  }
  return NULL;
}

T		*LIST_GET_FIRST(T)(T_LIST(T) **list)
{
  if (*list)
    return (&(*list)->value);
  return NULL;
}

T		*LIST_GET_AT(T)(T_LIST(T) **list, unsigned int i)
{
  (void)list;
  (void)i;
  return NULL;
}
