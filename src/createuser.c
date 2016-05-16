/**
 * @brief   Create user 
 * @version ver.1.0
 * @date    Sun May 15 19:19:18 CEST 2016
 * @company Frobas IT Department, www.frobas.com 2015
 * @author  Vladimir Roncevic <vladimir.roncevic@frobas.com>
 */ 
#include "userinfo.h"

/**
 * @brief   Create user 
 * @param   Value required userinfo
 * @retval  Success return 0, else 1
 */
int createuser(userinfo * uinfo) {
	if(uinfo != NULL) {
		if((uinfo->uid >0) && (uinfo->gid > 0) && 
		   (uinfo->un != NULL) && (uinfo->pa != NULL) &&
		   (uinfo->fn != NULL) && (uinfo->sh != NULL)) {
			char uid2str[8];
			char gid2str[8];
			itos(uinfo->uid, uid2str, 8);
			itos(uinfo->gid, gid2str, 8);
			char useradd_cmd[512];
			char passwd_cmd[512];
			memset(useradd_cmd, '\0', sizeof(512));
			sprintf(useradd_cmd, 
				"/usr/sbin/useradd -s %s -m -d /home/%s -c \"%s\" "
				"-u %s -g 100 -G %s %s\n\n", 
				uinfo->sh, uinfo->un, uinfo->fn, uid2str, gid2str, uinfo->un);
			int retval = system(useradd_cmd);
			if(retval == -1) {
				return NOT_SUCCESS;
			}
			memset(passwd_cmd, '\0', sizeof(512));
			sprintf(passwd_cmd, "echo -e \"%s\\n%s\" | passwd %s",
				uinfo->pa, uinfo->pa, uinfo->un);
			retval = system(passwd_cmd);
			if(retval == -1) {
				return NOT_SUCCESS;
			}
			return SUCCESS;
		}
	}
	return NOT_SUCCESS;
}

