# Reaction Game Control Box

This Arduino sketch is designed for a reaction game control box consisting of 20 illuminated switches, each connected to 5V relay modules. The relay modules are controlled using two CD74HC4067 multiplexers, with 10 pins of each multiplexer utilized. Pins 4 to 13 are used in both multiplexers.

## Operation Overview
1. The sketch generates a random number between 1 and 20.
2. If the random number is less than or equal to 10, the respective pin of the first multiplexer is activated. Otherwise, the second multiplexer is activated. 
3. To select the appropriate output pin on the multiplexer, the random number is adjusted (adding 3) and then converted to binary. Each bit of the binary representation corresponds to a control pin on the multiplexer.
4. The digital pins connected to the multiplexer are set high or low based on the binary representation, thereby activating the corresponding illuminated switch.
5. The switch associated with the activated light is monitored for a press (connected to pin 12). Only the activated switch will trigger a signal when pressed.
6. Upon detecting the press, all multiplexer pins are turned off to ensure only one switch is active at a time, preventing unintended simultaneous activations.
7. A new random number is generated, and the process repeats.

## Pseudo-Random Number Generation
To ensure a more varied sequence of illuminated switches for each game session, the `randomSeed(analogRead(A0));` line is included. This utilizes the floating state of analog pin A0 to seed the random number generator, introducing additional randomness with each game session.

## Usage
1. Connect the control box hardware components according to the provided wiring instructions.
2. Upload the sketch to your Arduino board.
3. Play the reaction game by observing the illuminated switches and pressing the corresponding switch when lit.
4. Enjoy the randomized sequence of illuminated switches with each game session!

####

Its actually the code for a control box of a reaction game made of 20 illuminated switches, the switches are all connected to 5v relay modules. the relay modules are controlled using two CD74HC4067 multiplexers. 10 pin of each multiplexer is used. but the pins from 4 to 13 are used in both. first a random number between 1 and 20 is generated. then if its below 10, the respective pin of first multipxer is to be turned on, else the second one. but since random number 1 means 4th pin in multiplexer, we add 3 to the num, then its converted to binary. binary conversion is needed because the multiplexer works by taking inputs from 4 pins as high or low state to select the appropriate output pin. so the digital pins connected to the multiplexer is then turned high or low based on the binary representation of the selected pin. eg: if six is the random number, we addd 3 and get 9, 9 in binary is 1001, hence the digital pins connected to S0 and S3 of the multipplexer is pulled HIGH while pins connected to S1 and S2 are pulled LOW. 
Now the corresponding light switch will turn on. also its switch will be turned on, so when that switch is pressed, we get a reading in pin12. since only that switch is powered on, pressing other lights will not give a signal. so when we read the pressing of the switch we turn of all the pins. its because if the next generated random number is for second multipl\xer, the first multiplexer will stay turned on, hence having two lights in on condition, which is undesirable. so we turn off both the multiplexer (actually we could turn off by using the enable pin in the multiplexr, but in our case we are turninig on the 0th output pin, since its not connected to any lights, we will have all our lights turned off). So after turning off all the multipllexer a new random num is geenerated and the loop continues.
Another problem faced was that the generated randum number we actually the same pattern always (pseudo-random), so once we turn off and restart the game, the lights will turn on in the same order as every time, which will be boring for the user playing multiple games. So i solved it by adding this line of code '  randomSeed(analogRead(A0));' Since A0 is a floating pin, we will get some random value, hnce making the whole process actually random each time we play it. 
 
