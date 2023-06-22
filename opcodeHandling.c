#include <opcodeHandling.h>

void unimplementedInstruction(State8080* state){
    printf("Error: One of the instructions was not implemented\n");
    exit(1);
}

int emulate8080Op(State8080* state){
    unsigned char *opcode = &state->memory[state->pc];

    switch(*opcode)
    {
        case 0x00: unimplementedInstruction(state); break;
    }
    state->pc+=1;
}