#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#include "header/list.h"
#include "header/menu.h"

int main()
{
    puts("LIST LIBRARY TEST\n");

    puts("INIT LIST [l, s, t]\n");

    list l;
    list s;
    list t;

    int menu_choice;
    int foo;
    char *file_path_bin;
    char *file_path_txt;

    init_list(&l);
    init_list(&s);
    init_list(&t);

    file_path_bin = "list.dat";
    file_path_txt = "list.txt";

    do
    {

        foo = 0;

        print_menu("\n\nList library test",
                   "-",
                   23,
                   "INIT",
                   "EMPTY",
                   "INSERT (AUTO)",
                   "COPY",
                   "PRINT ASC",
                   "PRINT DESC",
                   "CONCAT",
                   "COMPARE",
                   "FIND",
                   "GOTO",
                   "SUB LIST",
                   "DELETE LIST",
                   "DELETE HEAD",
                   "DELETE TAIL",
                   "DELETE AT",
                   "DELETE VAL",
                   "MODIFY NODE",
                   "SORT",
                   "IS SORT",
                   "COUNT",
                   "REVERSE",
                   "SAVE IN FILE",
                   "LOAD FROM FILE",
                   "EXIT",
                   END_MENU);

        menu_choice = choose_menu(">", 0, 23, "Value not in range.\n");

        printf("\e[1;1H\e[2J");

        switch (menu_choice)
        {
        case 0:
            /* INIT*/
            init_list(&l);
            init_list(&s);
            init_list(&t);
            puts("INITIALIZATED");
            break;

        case 1:
            /* EMPTY */
            puts("TESTING: is_empty_list ON l [0: empty | 1: not empty]");
            printf("RESULT: %d\n\n", is_empty_list(l));
            puts("TESTING: is_empty_list ON s [0: empty | 1: not empty]");
            printf("RESULT: %d\n\n", is_empty_list(s));
            puts("TESTING: is_empty_list ON t [0: empty | 1: not empty]");
            printf(">RESULT: %d\n\n", is_empty_list(t));
            break;

        case 2:
            /* INSERT */
            srand(time(0));

            puts("FILLING l");
            for (int i = 0; i < 10; i++)
            {
                int x = (rand() % (65536)) + 1;
                insert_tail(&l, x);
            }
            break;

        case 3:
            /* COPY */
            puts("COPYING l INTO s");
            copy_list(l, &s);
            break;

        case 4:
            /* PRINT ASC */
            print_list(&l, "PRINT ASC l");
            print_list(&s, "\nPRINT ASC s");
            print_list(&t, "\nPRINT ASC t");
            break;

        case 5:
            /* PRINT DESC */
            print_list_reverse(&l, "PRINT DESC l");
            print_list_reverse(&s, "\nPRINT DESC s");
            print_list_reverse(&t, "\nPRINT DESC t");
            break;

        case 6:
            /* CONCAT */
            puts("CONCAT l, s ON t");
            concat_list(&t, l, s);
            break;

        case 7:
            /* COMPARE */
            puts("COMPARING l, s [0: different | 1: equal]");
            printf("RESULT: %d\n\n", compare_list(l, s));
            puts("COMPARING l, t [0: different | 1: equal]");
            printf("RESULT: %d\n\n", compare_list(l, t));
            puts("COMPARING s, t [0: different | 1: equal]");
            printf("RESULT: %d\n\n", compare_list(s, t));
            break;

        case 8:
            /* FIND */
            if (rand() % 2 && l != NULL)
            {
                printf("SEARCHING FOR %d IN l [exptected: 0 -> first occurence position]\n", l->val);
                printf("RESULT: %d\n\n", found_in_list(l, l->val));
            }
            else
            {
                puts("SEARCHING FOR -1 IN l [exptected: -1 failed]");
                printf("RESULT: %d\n\n", found_in_list(l, -1));
            }
            break;

        case 9:
            /* GOTO */
            printf("GO TO %d POSITION", l->next->val);
            print_list(go_to_list(l, l->next->val), "New list from goto [expected: new list like l without head]");
            break;

        case 10:
            /* SUB LIST */
            printf("CREATING SUB LIST FROM l, STARTING FROM %d TO %d\n", 3, 8);
            sub_list(l, &t, 3, 8);
            print_list(&t, "sub list");
            break;

        case 11:
            /* DELETE LIST */
            puts("DELETING l");
            delete_list(&l);
            puts("DELETING s");
            delete_list(&s);
            puts("DELETING t");
            delete_list(&t);
            break;

        case 12:
            /* DELETE HEAD */
            puts("DELETING l HEAD");
            printf("RESULT: %d [expected: return head value]\n", delete_head(&l));
            puts("DELETING s HEAD");
            printf("RESULT: %d [expected: return head value]\n", delete_head(&s));
            puts("DELETING t HEAD");
            printf("RESULT: %d [expected: return head value]\n", delete_head(&t));
            break;

        case 13:
            /* DELETE TAIL */
            puts("DELETING l TAIL");
            printf("RESULT: %d [expected: return tail value]\n", delete_tail(&l));
            puts("DELETING s TAIL");
            printf("RESULT: %d [expected: return tail value]\n", delete_tail(&s));
            puts("DELETING t TAIL");
            printf("RESULT: %d [expected: return tail value]\n", delete_tail(&t));
            break;

        case 14:
            /* DELETE AT */
            foo = rand() % count_node(l) - 1;
            printf("DELETING l AT %d\n", foo);
            printf("RESULT: %d\n", delete_at(&l, foo));
            break;

        case 15:
            /* DELETE AT */
            if (rand() % 2 && l != NULL)
            {
                printf("DELETING l VAL %d\n", l->next->val);
                printf("RESULT: %d\n\n", delete_val(&l, l->next->val));
            }
            else
            {
                printf("DELETING l VAL %d\n", -1);
                printf("RESULT: %d\n\n", delete_val(&l, -1));
            }
            break;

        case 16:
            /* MODIFY NODE */
            break;

        case 17:
            /* SORT */
            puts("SORTING l");
            sort_list(l);
            break;

        case 18:
            /* IS SORT */
            if (rand() % 2)
            {
                sort_list(l);
                puts("SORTING l");
            }
            puts("IS SORT l [ -1: failed | 0: shuffled | 1: sorted ] \n");
            printf("RESULT ASC: %d\n\n", is_sort_list(l, ASC_LIST));
            puts("IS SORT l [ -1: failed | 0: shuffled | 1: sorted ] \n");
            printf("RESULT DESC: %d\n\n", is_sort_list(reverse(l), DESC_LIST));
            break;

        case 19:
            /* COUNT */
            puts("NODE IN l");
            printf("RESULT: %d\n\n", count_node(l));
            puts("NODE IN s");
            printf("RESULT: %d\n\n", count_node(s));
            puts("NODE IN t");
            printf("RESULT: %d\n\n", count_node(t));
            break;

        case 20:
            /* REVERSE */
            puts("REVERSING l INTO t");
            t = reverse(l);
            break;

        case 21:
            /* SAVE IN FILE */
            printf("SAVING l INTO BIN FILE AT %s [ -3: error while writing | -2: cannot create file | -1: invalid file type | 0: success ]\n", file_path_bin);
            printf("RESULT: %d\n\n", save_file_list(file_path_bin, BIN_FILE_LIST, l));
            printf("SAVING l INTO TEXT FILE AT %s [ -3: error while writing | -2: cannot create file | -1: invalid file type | 0: success ]\n", file_path_txt);
            printf("RESULT: %d\n\n", save_file_list(file_path_txt, TEXT_FILE_LIST, l));
            break;

        case 22:
            /* LOAD FROM FILE */
            printf("LOADING l DESC FROM BIN FILE AT %s [ -3: error while writing | -2: cannot create file | -1: invalid file type | 0: success ]\n", file_path_bin);
            printf("RESULT: %d\n\n", load_file_list(file_path_bin, BIN_FILE_LIST, &l, DESC_LIST));
            printf("SAVING s ASC FROM TEXT FILE AT %s [ -3: error while writing | -2: cannot create file | -1: invalid file type | 0: success ]\n", file_path_txt);
            printf("RESULT: %d\n\n", load_file_list(file_path_txt, TEXT_FILE_LIST, &s, ASC_LIST));
            break;

        case 23:
            /* EXIT */
            delete_list(&l);
            delete_list(&s);
            delete_list(&t);
            puts("Terminating TEST...");
            return 0;
            break;

        default:
            break;
        }
    } while (menu_choice >= 0 || menu_choice <= 23);
}