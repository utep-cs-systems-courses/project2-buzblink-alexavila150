#ifndef stateMachine_included
#define stateMachine_included

char sequence[6];                 //sequence of lights 0: no light 1: red light 2: green light
char player_sequence[6];          //sequence of lights for the user
extern const int notes[42];       //list of notes to be play
extern const char duration[42];   //duration of every corresponding note

char sequence_running;     //tells if the light cycles is running or not
char song_playing;         //while true the song will play
unsigned char random_num;  //generates random number by add 1 every WD interrupt

char note_index;           //keeps track of the current note that is playing
char led_index;            //keeps track of the index pointing to a certain led
int blink_count;           //keeps track of the counts of wdInterrups
char turn;                 //how many times the user has been correct in a row

void state_init();
void reset_sequence();
void add_to_sequence();
void end_sequence();
void play_song();
void add_to_player_sequence(char led);
char compare_list();

#endif // included
