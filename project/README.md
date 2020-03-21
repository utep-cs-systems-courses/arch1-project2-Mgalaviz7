# Lab 2: Blinky-Buzzy Toy Description

My toy consits of flashing of LEDS counting from 0 to 3 in a binary fashion
with two settings of brightness. Followed by the option to make the speed of the lights faster. Then finaly it will play Mary Had a
Little Lamb Lullybay. 

# How to compile

1. Go into the project Directory.

2. When in that directory type "make clean" to remove all .o and ~ files

3. After "make clean" type and run "make" to make the executable files.

4. After the executable files are created type and run "make load"

5. Now you are ready to use the toy. At the state 0 the green led will glow
for conformation that it has loaded.


# How to use

`Ideal (State 0)`
Can be seen as the ideal state which essentially
gives the user conformation that the program has loaded. State 0 is just the
green led turned on until a button is pushed to switch the state of the toy.

`Count-to-3 (State 1)`
By the push of button 1 from right to left it starts the first state. While in
this state it blinks the lights in a syncronus order from 0 to 3 in a binary
fashion.The glow of the red led repesenting the value of 1 and green led
repesenting the value of 2.

`Dim-Count-to-3 (State 2)`
Does what state two is described to do but dims the leds by repeatedaly
turning them off and on this occurs when button 3 is pushed.

`SPEED it Up (State 3)`
Increases the speed at which the leds blinks starting from the normal blink
speed to a rapid blink of leds. Once it reaches the fastes speed it updates
the speed back to normal and contiunes the processes until state is changed.

`Little Lamb (State 4)`
When Button 4 is pressed it will play the Little Lamb Lullaby as well as breafly interrupt the state it is currently on and plays the medlody and then
continues the state that was prior to pressing button4 after melody has finished.
