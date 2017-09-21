#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include <pwd.h>

#include "shox.h"

int main (int argc, char *argv[]){
	
	welcome(getpid());

	runShox(); //calls shell


	return EXIT_SUCCESS;
}
