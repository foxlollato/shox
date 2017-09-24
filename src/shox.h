#ifndef _SHOX_H
#define _SHOX_H


#define CMDBUF 1024
#define ARGBUF 64

void parse (char*, char**);
void welcome(pid_t);
void runCommand(char*, char**);
void checkCommand(char*, char**);
void runIn(char*, char**, int);
void runOut(char*, char**, int);
//runPipe(command,args,i);
void runShox();

#endif
