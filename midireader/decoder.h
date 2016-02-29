#ifndef DECODER_H
#define DECODER_H

int ticks_per_beat;

void decode( char * file) {
    
    FILE * fptr;
    fptr = fopen( file, "r"); 
    
    unsigned char header_chunk[14];
    unsigned char * track_1;
    unsigned char * track_2;
    
    int i;
    for( i=0; i<14; i++) {
        header_chunk[i] = fgetc(fptr);
    }
    if( !( header_chunk[0]=='M' && header_chunk[1]=='T' && header_chunk[2]=='h' && header_chunk[3]=='d') ) {
        printf("Not a midi\n"); 
        exit(1);
    }
    if( header_chunk[9]!=0x01 ) {
        printf("Your midi is type %d. It should be type 1: multiple track file format\n", header_chunk[9]);
        exit(1);
    }
    if( header_chunk[11]!=2 ) {
        printf("Your midi has %d tracks. It should have exactly 2.(?)\n", header_chunk[11]);
        //exit(1);
    }
    ticks_per_beat = 256*header_chunk[12] + header_chunk[13];
    if( header_chunk[12] && 128 ) {
        printf("bad ticks per beat. first bit should be zero.\n");
        exit(1);
    }
    
    
    
    
    
    
}


#endif
