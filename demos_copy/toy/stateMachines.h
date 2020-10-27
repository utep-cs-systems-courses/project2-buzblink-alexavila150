#ifndef stateMachine_included
#define stateMachine_included

char sequence[6];          //sequence of lights 0: no light 1: red light 2: green light
extern const int notes[42];
extern const char duration[42];

char sequence_running;     //tells if the light cycles is running or not
char song_playing;

char note_index;
char led_index;
int blink_count;

void state_init();
void add_to_sequence();
void play_song();

#endif // included
