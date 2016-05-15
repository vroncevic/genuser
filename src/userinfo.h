/**
 * @brief   User informations
 * @version ver.1.0
 * @date    Sun May 15 19:19:18 CEST 2016
 * @company Frobas IT Department, www.frobas.com 2015
 * @author  Vladimir Roncevic <vladimir.roncevic@frobas.com>
 */ 
#ifndef __USERINFO_H
#define __USERINFO_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define SUCCESS 	0
#define NOT_SUCCESS 1

typedef struct {
	int uid;
	int gid;
	char * gn;
	char * un;
	char * pa;
	char * fn;
	char * sh;
} userinfo;

int createuser(userinfo * uinfo);
int creategroup(userinfo * uinfo);
void itos(int value, char* str, size_t size);

#endif

