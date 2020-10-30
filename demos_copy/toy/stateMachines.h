#ifndef stateMachine_included
#define stateMachine_included

char sequence[6];          //sequence of lights 0: no light 1: red light 2: green light
char player_sequence[6];   //sequence of lights for the user
extern const int notes[42];
extern const char duration[42];

char sequence_running;     //tells if the light cycles is running or not
char song_playing;
unsigned char random_num = 0;  //generates random number by add 1 every WD interrupt

char note_index;
char led_index;
int blink_count;
char turn;

void state_init();
void add_to_sequence();
void end_sequence();
void play_song();
void add_to_player_sequence(char led);
char compare_list();

#endif // included
