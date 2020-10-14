#ifndef stateMachine_included
#define stateMachine_included

void state_advance();
char toggle_red();
void red_turn_on();
void red_off();
void green_turn_on();
void green_off();
void red_dim();
void red_bright();
void incrementFrequency();
void decrementFrequency();

extern int hz;

#endif // included
