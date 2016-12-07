/**
 * @brief   Main entry point
 * @version ver.1.0
 * @date    Sun May 15 19:19:18 CEST 2016
 * @company Frobas IT Department, www.frobas.com 2015
 * @author  Vladimir Roncevic <vladimir.roncevic@frobas.com>
 */ 
#include "userinfo.h"

/**
 * @brief   Main function
 * @param   None
 * @exitval Tool genuser exit with integer value
 * 			0   - success operation 
 *  		127 - run as root user
 */
int main(void) {

	extern const char *__progname;
	char * version = "ver.1.0";
	time_t rawtime;
	struct tm * timeinfo;
	userinfo * user_point;
	userinfo users[3] = {
		{1012, 503, "new1", "newuser1", "password1", "New User 1", "/bin/bash"},
		{1013, 504, "new2", "newuser2", "password2", "New user 2", "/bin/bash"},
		{1014, 505, "new3", "newuser3", "password3", "New User 3", "/bin/bash"}
	};
	short i;
	short num_users = sizeof(users)/sizeof(userinfo);

	time (&rawtime);
	timeinfo = localtime (&rawtime);
	printf("\n%s %s\n%s", __progname, version, asctime(timeinfo));
	printf("\n[%s] Check permissions ", __progname);
	if(geteuid() != 0) {
		printf("[not ok]\n");
		printf("Run [%s] as root user\n\n", __progname);
		exit(127);
	}
	printf("[ok]\n");
	for(i = 0; i < num_users; i++) {
		user_point = & users[i];
		creategroup(user_point);
		int status = createuser(user_point);
		if(status == SUCCESS) {
			printf("[%s] Creation success [%s]\n", __progname, user_point->un);
		} else if(status == NOT_SUCCESS) {
			printf("[%s] Creation failed [%s]\n", __progname, user_point->un);
		}
	}
	printf("[%s] Done\n\n", __progname);
	exit(0);
}

