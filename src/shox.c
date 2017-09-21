#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include <pwd.h>

#include "shox.h"

void  parse(char *command, char **args) //parse command line string into a strings vector **args. This step is required to properly use of EXECV()
{
	while (*command != '\0') {//whie not end of command line
		while (*command == ' ' || *command == '\t' || *command == '\n'){ //check for spaces, \t and \n
			*command++ = '\0'; //then broke characters sequence 
		}
		*args++ = command; //and store it at vector position

		while (*command != '\0' && *command != ' ' && *command != '\t' && *command != '\n'){//go ahead with command line verification, looking for any duplicated verification condition
			command++;
		}
	}
	*--args = '\0';		/* backward last position of vector because FGETS() insert a new char after the end of read command -> \0
				   then terminate the args vector */
}
void welcome(pid_t thisPid){	//welcome messages could be set here
	
	printf("Welcome to shox, the shell of a fox. My pid is %d.\nEnter any command here.\n", thisPid);

}

void runCommand(char* command, char**args){
  pid_t  childPid;
  int status=1;
  if((childPid = fork())< 0){// Check if fork created the child pid
				fprintf(stderr,"Not possible to create child process\n");
				exit(EXIT_FAILURE);
			}
			else if(childPid==0){	//Then, check if Im the child. Now im able to run commands.
				printf("Child process PID is %d\n", getpid()); //if yes, return child PID

				if(execvp(command, args) < 0){ // if im a child, and im able to run the command
					fprintf(stderr,"Not possible to execute %s\n", command); //if something run bad, print errors.
					perror("[ERROR]");
					exit(EXIT_FAILURE); // then, kill the child. (Yes, i am mean.)
				}
			}else if (childPid < 0){
				fprintf(stderr,"Not possible to fork\n");
			}else{
				while(wait(&status) != childPid); //and finally, wait for the child quits playing.
			}
  
}

void checkCommand(char*command, char **args){
  int i=0;
  while(args[i]!=NULL){
    
    if(strcmp(args[i],"<")==0){
      printf("<\n");
	//runInCommand(command,args,i);    
    }
    if(strcmp(args[i],">")==0){
      printf(">\n");
	//runOutCommand(command,args,i);      
    }
    if(strcmp(args[i],"|")==0){
      printf("|\n");
	//runPipeCommand(command,args,i);
    }
      i++;
  }
  printf("runOk\n");
  runCommand(command,args);
}
void runShox(){

	char *command = malloc(sizeof(char)*CMDBUF);
	char **args = malloc(sizeof(char*)*ARGBUF);	

	struct passwd *pw=getpwuid(getuid());//get home directory path to implement cd
	char *homedir=pw->pw_dir;

	for(;;){ //for ever :P

		printf("\ncmd> ");

		fgets(command,CMDBUF,stdin); //listening to input
		parse(command,args); //parse command into strings vector


		

		if(strcmp(args[0],"exit")==0){ //check if desire to give up,then, give up and exit.
			free(command);
			free(args);
			printf("See you soon!\n");
			exit(EXIT_SUCCESS);
		}

		//cd - change directory implementation
		if(strcmp(args[0],"cd")==0){
			if(args[1]==NULL){ //if directory not indicated, head to home directory
				chdir(homedir);

			}else{
				if(chdir(args[1])!=0){ //head to directory
					perror("[ERROR]");
				}
			}
		}else{
			checkCommand(command,args);
			
		}
	}
}
