#ifndef stateMachine_included
#define stateMachine_included

char sequence[5];          //sequence of lights 0: no light 1: red light 2: green light
char sequence_running;     //tells if the light cycles is running or not
char rand_num;             //generates random 1 or 0 in the wdInterrupt cycle

void state_init();
void add_to_sequence();

#endif // included
