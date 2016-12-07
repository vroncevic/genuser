/**
 * @brief   Convert integer to string
 * @version ver.1.0
 * @date    Sun May 15 19:19:18 CEST 2016
 * @company Frobas IT Department, www.frobas.com 2015
 * @author  Vladimir Roncevic <vladimir.roncevic@frobas.com>
 */ 
#include "userinfo.h"

/**
 * @brief   Convert integer to string
 * @params  Values required int value, string and size
 * @retval  Success return 0, else 1
 */
void itos(int value, char* str, size_t size) {
    snprintf(str, size, "%d", value);
}

