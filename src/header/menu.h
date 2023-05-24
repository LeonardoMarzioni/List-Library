/**
 * @file    menu.h
 * @author  Marzioni Leonardo
 * @brief   Menu handle utils
 * @version 0.2
 * @date    2023-04-12
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#pragma once

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdarg.h>
#include <errno.h>

#define END_MENU "\0"

/**
 * @brief           print menu like
 * 
 *                  Title
 *                  0 <sep> <item 1>
 *                  1 <sep> <item 2>
 *                  ...
 * 
 *                  Use END_MENU at the end of the label list;
 *                  any label after END_MENU will not
 *                  be displayed.  
 * 
 * 
 * @param title     title of the menu
 * @param sep       separator between index and item
 * @param count     number of item
 * @param ...       item
 */
void print_menu(char* title, char* sep, int count, ...);


/**
 * @brief input the user choose (int) the range
 *        [min, max]
 * 
 * @param label             // input prompt
 * @param min
 * @param max 
 * @param error_message     // error message if value is not in range 
 * @return int
 */
int choose_menu(char* label, int min, int max, char* error_message);