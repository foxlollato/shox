#include <stdlib.h>
#include <unistd.h>
#include "shox.h"

int main (int argc, char *argv[]){
	
	welcome(getpid());

	runShox();


	return EXIT_SUCCESS;
}
