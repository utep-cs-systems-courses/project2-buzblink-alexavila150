Project 2: Blinky-Buzzy Toy
Simon Game Edition

===========================



## Description:

This programed specially designed for the msp-430 is a simple replica of the
game simon in which the user has to follow a sequence of lights and every time
the user follows the sequence correctly then the machine will give the user
the same sequence but with one more extra step in order to make it a bit
harder. After 5 successful attemps a song will play meaning the player has won
the game.


## How to Compile and Run:

1. Clone the repo anywhere in your computer and open the the project folder

2. Plug in your msp-430 to your computer and type make. This will autematically
load your game into the msp-430

3. To clean the build files in the src folder use make clean



## Button Functions:

On the green board, there are four buttons. On top, you can see each button is

labeled S1-S4 and an extra button SW1 in the size that can be use as an extra feature.



- **S1**: If you want to hear the winning song of the same just press this
    button at any time. Notice the red led changes brigtness every 15 seconds
    while the song is playing
- **S2**: When is your turn to follow the sequence press this button when you
    think that green is the next in the sequence
- **S3**: Similarly, press this button if you think that red is the next led
    in the sequence
- **S4**: if you find the sequence a bit to hard then use this button and the
    sequence will start again from level 1

- **SW1**: if you want to go easy mode then press this botton and the next
    sequence will just play automatically
