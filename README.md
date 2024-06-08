# Reaction Game Control Box

This Arduino sketch is designed for a reaction game control box consisting of 20 illuminated switches, each connected to 5V relay modules. The relay modules are controlled using two [CD74HC4067 multiplexers](https://www.instructables.com/Arduino-Interfacing-With-CD74HC4067-16-channel-MUX/), with 10 pins (4 to 13) of each multiplexer utilized. multiplexers.

## Operation Overview
1. The sketch generates a random number between 1 and 20.
2. If the random number is less than or equal to 10, the respective pin of the first multiplexer is activated. Otherwise, the second multiplexer is activated. 
3. To select the appropriate output pin on the multiplexer, the random number is adjusted (adding 3 for 1 to 10 and subtracting 7 for 11 to 20) and then converted to binary. Each bit of the binary representation corresponds to a control pin on the multiplexer.
4. The digital pins connected to the multiplexer are set high or low based on the binary representation, thereby activating the corresponding illuminated switch.
5. The switch associated with the activated light is monitored for a press (connected to pin 12). Only the activated switch will trigger a signal when pressed.
6. Upon detecting the press, all multiplexer pins are turned off to ensure only one switch is active at a time, preventing unintended simultaneous activations.
7. A new random number is generated, and the process repeats.

## Pseudo-Random Number Generation
To ensure a more varied sequence of illuminated switches for each game session, the
`randomSeed(analogRead(A0));` 
line is included. This utilizes the floating state of analog pin A0 to seed the random number generator, introducing additional randomness with each game session.

## Usage
1. Connect the control box hardware components according to the provided wiring instructions.
2. Upload the sketch to your Arduino board.
3. Play the reaction game by observing the illuminated switches and pressing the corresponding switch when lit.
4. Enjoy the randomized sequence of illuminated switches with each game session!

 
