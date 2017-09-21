#ifndef _SHOX_H
#define _SHOX_H


#define CMDBUF 1024
#define ARGBUF 64

void parse (char*, char**);
void welcome(pid_t);
void runShox();

#endif
