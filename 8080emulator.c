#include "opcodeHandling.h"

State8080* initializeState(){
    State8080* state = (State8080*)malloc(sizeof(State8080));
    state->memory = (uint8_t*)malloc(0x10000);
    return state;
}

void readFileIntoState(State8080** state, char *argv){

    FILE *fp;
    long length; 
    fp = fopen(argv,"r");
    if(fp==NULL){ 
        printf("ERROR! Could not open file!");
    }
    fseek(fp,0,SEEK_END); 
    length = ftell(fp); 
    fseek(fp,0,SEEK_SET); 
    fread((*state)->memory,1,length,fp);
    fclose(fp);
}

void freeMemory(State8080** state){
    free((*state)->memory);
    free((*state));
}

int main(int argc, char *argv[])
{
    if(argc==2){
        State8080* state = initializeState();
        readFileIntoState(&state, argv[1]);
        freeMemory(&state);
    }
    else{
        printf("Invalid Number of Arguments");
    }
  
    return 0;
}