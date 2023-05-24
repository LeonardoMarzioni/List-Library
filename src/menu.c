#include "header/menu.h"

void print_menu(
    char *title,
    char *sep,
    int count,
    ...)
{

    va_list list; // list of args ...
    char *label;  // temp value of current item in list

    va_start(list, count); // init list of args

    fprintf(stdout, "%s\n", title);

    // print the menu
    for (int i = 0; i < count; i++)
    {
        label = va_arg(list, char *);

        /*
         * check for not match betwween num of
         * item in list and count
         */
        if (!strcmp(label, END_MENU))
        {
            break;
        }

        fprintf(stdout, "%d%s%s\n", i, sep, label);
    }

    va_end(list);

    return;
}

int choose_menu(
    char *label,
    int min,
    int max,
    char *error_msg)
{
    char *s_input;
    int i_input; // cast int of s_input
    int max_len_of_i;
    max_len_of_i = 11; // max length of int [4 Byte]

    /**
     * @brief try alloc input string
     *
     */
    s_input = (char *)calloc(10, sizeof(char));

    if (s_input == NULL)
    {
        perror(error_msg);
        exit(-1);
    }

    /**
     * @brief sort min max
     *
     */
    if (min > max)
    {
        min = min + max;
        max = min - max;
        min = min - max;
    }

    /**
     * @brief try input while input is int in range [min, max]
     *
     */
    do
    {

        // init var
        *s_input = '\0';
        // printf("\ndopo init : %s\n", s_input);

        fflush(stdin);

        i_input = -1;

        // print the prompt
        fprintf(stdout, "%s", label);

        if (fgets(s_input, max_len_of_i, stdin))
        {
            s_input[max_len_of_i - 1] = '\0';
            // printf("\n%s\n", s_input);
            if (sscanf(s_input, "%d", &i_input) && !errno)
            {
                // is a number but not in range
                if ((i_input < min) || (i_input > max))
                    fprintf(stdout, "%s", error_msg);
            }
            else
            {
                // it's not a number
                puts("NaN");
                // printf("%d", errno);

                continue;
            }
        }
        // is a number, is it in the range?
    } while ((i_input < min) || (i_input > max));

    free(s_input);

    return i_input;
}