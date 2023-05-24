#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "header/list.h"

void init_list(list *l)
{
  *l = ((void *)0);
}

int is_empty_list(list l)
{
  if (l == NULL)
  {
    return 0;
  }
  return 1;
}

int found_in_list(list l, int x)
{
  int pos = 0;

  if (!is_empty_list(l))

    while (l != NULL)
    {
      if (l->val == x)
        return pos;
      l = l->next;
      pos++;
    }
  return -1;
}

list *go_to_list(list l, int x)
{
  while (l->next != NULL)
  {
    if (l->next->val == x)
      return &l->next;
    l = l->next;
  }
  return NULL;
}

void delete_list(list *l)
{
  list s;
  list t;

  s = *l;

  while (s)
  {
    t = s->next;
    free(s);
    s = t;
  }
  *l = NULL;
}

int modify_node(list l, int x, int y)
{
  if (!is_empty_list(l))
  {
    return 0;
  }
  while (l != NULL)
  {
    if (l->val == x)
    {
      l->val = y;
    }
    l = l->next;
  }
  return 1;
}

int insert_head(list *l, int x)
{
  list s;

  s = malloc(sizeof(node));
  if (s == NULL)
  {
    return 0;
  }

  s->val = x;
  s->next = *l;
  *l = s;
  return 1;
}

int insert_tail(list *l, int x)
{
  list s;

  if (*l == NULL)
  {
    insert_head(l, x);
    return 1;
  }

  s = *l;

  while (s->next != NULL)
    s = s->next;

  s->next = malloc(sizeof(node));
  s = s->next;

  s->val = x;
  s->next = NULL;
  return 1;
}

int insert_at(list *l, int x, int pos)
{
  list s;
  list r;
  int i;

  s = *l;
  i = 0;

  if (pos > count_node(*l) - 1)
  {
    return 0;
  }

  while (s->next != NULL && i < pos)
  {
    if (i == pos - 1)
    {
      r = s->next;

      s->next = malloc(sizeof(node));
      if (s->next == NULL)
      {
        return 0;
      }

      s->next->val = x;
      s->next->next = r;
    }
    i++;
    s = s->next;
  }
  return 1;
}

int is_sort_list(list l, int desc)
{
  if (!is_empty_list(l) && desc != 0 && desc != 1)
  {
    return -1;
  }
  if (desc == 0)
  {
    while (l->next != NULL)
    {
      if (l->val > l->next->val)
        return 0;
      l = l->next;
    }
  }
  else
  {
    while (l->next->next != NULL)
    {
      if (l->val < l->next->val)
        return 0;
      l = l->next;
    }
  }
  return 1;
}

void sort_list(list l)
{
  int swapped, i;
  list ptr1;
  list lptr = NULL;

  if (l == NULL)
    return;

  do
  {
    swapped = 0;
    ptr1 = l;

    while (ptr1->next != lptr)
    {
      if (ptr1->val > ptr1->next->val)
      {
        swap(ptr1, ptr1->next);
        swapped = 1;
      }
      ptr1 = ptr1->next;
    }
    lptr = ptr1;
  } while (swapped);
}

// use as a private method, used in sort_list()
void swap(list l, list s)
{
  int temp = l->val;
  l->val = s->val;
  s->val = temp;
}

int count_node(list l)
{
  int count = 0;
  if (!is_empty_list(l))
  {
    return 0;
  }

  while (l != NULL)
  {
    count++;
    l = l->next;
  }
  return count;
}

int delete_head(list *l)
{
  if (!is_empty_list(*l))
  {
    return -1;
  }

  list s;
  int x;

  s = *l;

  if (s != NULL)
  {
    *l = s->next;
    x = s->val;
    free(s);
    return x;
  }
}

int delete_tail(list *l)
{
  if (!is_empty_list(*l))
  {
    return -1;
  }

  list s;
  int x;

  s = *l;

  while (s->next->next != NULL)
    s = s->next;
  x = s->next->val;
  free(s->next);
  s->next = NULL;
  return x;
}

int delete_at(list *l, int pos)
{
  if (!is_empty_list(*l))
  {
    return -1;
  }

  list s;
  list r;
  int i = 0;
  int x;

  if ((*l)->next != NULL)
  {
    s = *l;

    if (pos == 0)
    {
      x = (*l)->val;
      delete_head(l);
      return x;
    }

    while (s->next != NULL && i < pos)
    {

      if (i == pos - 1)
      {
        r = s->next;
        s->next = s->next->next;
        x = r->val;
        free(r);
        return x;
      }
      else
      {
        s = s->next;
      }
      i++;
    }
  }
}

int delete_val(list *l, int x)
{
  if (!is_empty_list(*l))
  {
    return 0;
  }

  list s;
  list r;
  int y;

  if ((*l)->next != NULL)
  {
    s = *l;
    if (s->val == x)
    {
      y = (*l)->val;
      delete_head(l);
      return y;
    }

    while (s->next != NULL)
    {
      if (s->next->val == x)
      {
        r = s->next;
        s->next = s->next->next;
        y = r->val;
        free(r);
        return y;
      }
      s = s->next;
    }
  }
  else
  {
    delete_head(l);
  }
}

void print_list(list *l, const char *label)
{
  if (strcmp(label, "") != 0)
  {
    printf("\n%s", label);
  }
  if (*l != NULL)
  {
    printf("\n | \n █─ %d", (*l)->val);
    print_list(&(*l)->next, "");
  }
}

void print_list_reverse(list *l, const char *label)
{
  if (strcmp(label, "") != 0)
  {
    printf("\n%s", label);
  }
  if (*l != NULL)
  {
    print_list_reverse(&(*l)->next, "");
    printf("\n | \n █─ %d", (*l)->val);
  }
}

int load_file_list(const char *path, int file_type, list *l, int ins_mode)
{
  if (file_type != BIN_FILE_LIST && file_type != TEXT_FILE_LIST && ins_mode != ASC_LIST && ins_mode != DESC_LIST)
  {
    return -1;
  }

  FILE *f;
  int val;

  f = fopen(path, (file_type == BIN_FILE_LIST) ? "rb" : "r");
  if (f == NULL)
  {
    fclose(f);
    return -2;
  }

  if (file_type == BIN_FILE_LIST)
  {
    if (ins_mode == ASC_LIST)
    {
      while (fread(&val, sizeof(int), 1, f) == 1)
      {
        insert_head(l, val);
      }
    }
    else
    {
      while (fread(&val, sizeof(int), 1, f) == 1)
      {
        insert_tail(l, val);
      }
    }
  }
  else
  {
    if (ins_mode == ASC_LIST)
    {
      while (!feof(f))
      {
        fscanf(f, "%d", &val);
        insert_head(l, val);
      }
    }
    else
    {
      while (!feof(f))
      {
        fscanf(f, "%d", &val);
        insert_tail(l, val);
      }
    }
  }
  return 0;
}

int save_file_list(const char *path, int file_type, list l)
{
  if (file_type != BIN_FILE_LIST && file_type != TEXT_FILE_LIST)
  {
    return -1;
  }

  FILE *f;

  f = fopen(path, (file_type == BIN_FILE_LIST) ? "wb+" : "w+");
  if (f == NULL)
  {
    fclose(f);
    return -2;
  }

  if (file_type == BIN_FILE_LIST)
  {
    while (l != NULL)
    {
      if (fwrite(&l->val, sizeof(int), 1, f) == 0)
      {
        fclose(f);
        return -3;
      }
      l = l->next;
    }
  }
  else
  {
    while (l != NULL)
    {
      if (fprintf(f, "%d\n", l->val) < 0)
      {
        fclose(f);
        return -3;
      }
      l = l->next;
    }
  }
  fclose(f);
  return 0;
}

void sub_list(list l, list *s, int start, int end)
{
  (*s) = ((void *)0);
  if (start < 0 || end < start || end > count_node(l) - 1)
  {
    return;
  }
  int i = 0;
  while (i < start && l != NULL)
  {
    l = l->next;
    i++;
  }
  while (start < end + 1 && l != NULL)
  {
    insert_tail(s, l->val);
    l = l->next;
    start++;
  }
}

void copy_list(list l, list *s)
{
  (*s) = NULL;
  while (l != NULL)
  {
    insert_tail(s, l->val);
    l = l->next;
  }
}

void concat_list(list *t, list l, list s)
{
  *t = ((void *)0);
  while (l != NULL)
  {
    insert_tail(t, l->val);
    l = l->next;
  }
  while (s != NULL)
  {
    insert_tail(t, s->val);
    s = s->next;
  }
  return;
}

int compare_list(list l, list s)
{
  if (count_node(l) != count_node(s))
  {
    return 0;
  }
  else
  {
    while (l != NULL)
    {
      if (l->val != s->val)
        return 0;
      l = l->next;
      s = s->next;
    }
    return 1;
  }
}

list reverse(list l)
{
  list s;
  s = ((void *)0);
  if (!is_empty_list(l))
  {
    return NULL;
  }
  // (*s)->next = NULL;
  while (l != NULL)
  {
    insert_head(&s, l->val);
    l = l->next;
  }
  return s;
}