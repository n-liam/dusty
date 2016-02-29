#include <stdio.h>

#include "../headers/instructions.h"
#include "../headers/memory.h"
#include "../midireader/decoder.h"


int main(int argc, char ** argv) {
    if(argc <2) { printf("Missing terminal argument.\n");exit(1); }
    
    
	initiateMemory();
    
    
    decode( argv[1] );
    
	return 0;
}
