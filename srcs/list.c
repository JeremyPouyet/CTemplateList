#include <stdlib.h>
#include "list.h"

static T_LIST(T)	*TEMPLATE(T, create_elem)(void)
{
  return (malloc(sizeof(T)));
}

/*
** add
*/

T		*LIST_ADD_LAST(T)(T_LIST(T) **list)
{
  T_LIST(T)	*tmp;
  T_LIST(T)	*new;

  if (!(new = TEMPLATE(T, create_elem())))
    return NULL;
  new->next = NULL;
  if (*list)
  {
    tmp = *list;
    while (tmp->next)
      tmp = tmp->next;
    new->prev = tmp;
    tmp->next = new;
  }
  else
  {
    new->prev = NULL;
    *list = new;
  }
  return &new->value;
}

T		*LIST_ADD_FIRST(T)(T_LIST(T) **list)
{
  T_LIST(T)	*new;

  if (!(new = TEMPLATE(T, create_elem())))
    return NULL;
  new->prev = NULL;
  new->next = *list;
  if (*list)
    (*list)->prev = new;
  *list = new;
  return &new->value;
}

T		*LIST_ADD_AT(T)(T_LIST(T) **list, unsigned int i)
{
  T_LIST(T)	*new;
  T_LIST(T)	*tmp;

  if (i == 0 || !(*list))
    return (LIST_ADD_FIRST(T)(list));
  if (!(new = TEMPLATE(T, create_elem())))
    return NULL;
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
  return &new->value;
}

/*
** del
*/

void		LIST_DEL_AT(T)(T_LIST(T) **list, unsigned int i)
{
  T_LIST(T)	*tmp;

  if (*list)
  {
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
  if (*list)
  {
    if ((*list)->next)
    {
      *list = (*list)->next;
      free((*list)->prev);
      (*list)->prev = NULL;
    }
    else
    {
      free(*list);
      *list = NULL;
    }
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
    return &(*list)->value;
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
  if (*list)
  {
    if (i == 0)
      return &(*list)->value;
    return LIST_GET_AT(T)(&(*list)->next, --i);
  }
  return NULL;
}
