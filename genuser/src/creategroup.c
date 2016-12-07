/**
 * @brief   Create group 
 * @version ver.1.0
 * @date    Sun May 15 21:57:33 CEST 2016
 * @company Frobas IT Department, www.frobas.com 2015
 * @author  Vladimir Roncevic <vladimir.roncevic@frobas.com>
 */ 
#include "userinfo.h"

/**
 * @brief   Create group 
 * @param   Value required userinfo
 * @retval  Success return 0, else 1
 */
int creategroup(userinfo * uinfo) {
	if(uinfo != NULL) {
		if(uinfo->gn != NULL) {
			char cmd[512];
			char gid2str[8];
			itos(uinfo->gid, gid2str, 8);
			memset(cmd, '\0', sizeof(512));
			sprintf(cmd, "/usr/sbin/groupadd -g %s %s", gid2str, uinfo->gn);
			int retval = system(cmd);
			if(retval == -1) {
				return NOT_SUCCESS;
			}
			return SUCCESS;
		}
	}
	return NOT_SUCCESS;
}

