#pragma once

#define ASC_LIST 0
#define DESC_LIST 1
#define BIN_FILE_LIST 0
#define TEXT_FILE_LIST 1

typedef struct node_t
{
    int val;
    struct node_t *next;
} node;

typedef node *list;

void init_list(list *l);

int is_empty_list(list l);

void copy_list(list l, list *s);

void concat_list(list *t, list l, list s);

int compare_list(list l, list s);

int found_in_list(list l, int x);

list *go_to_list(list l, int x);

void sub_list(list l, list *s, int start, int end);

void delete_list(list *l);

int modify_node(list s, int x, int y);

int insert_head(list *l, int x);

int insert_at(list *l, int x, int pos);

int insert_tail(list *l, int x);

int is_sort_list(list l, int desc);

void sort_list(list l);

void swap(list l, list s);

int count_node(list l);

int delete_head(list *l);

int delete_tail(list *l);

int delete_at(list *l, int pos);

int delete_val(list *l, int x);

void print_list(list *l, const char*label);

void print_list_reverse(list *l, const char*label);

list reverse(list l);

int load_file_list(const char*path, int file_type, list *l, int ins_mode);

int save_file_list(const char*path, int file_type, list l);