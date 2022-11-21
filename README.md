# Introduction to Robotics (2022 - 2023)

* Introduction to Robotics laboratory homeworks

* 3rd year course at the Faculty of Mathematics and Computer Science, University of Bucharest. 

# Homeworks

<details>
<summary> <h2>Homework 1: RGB led control with 3 potentiometers :bulb: </h2> </summary>
<br>

### Task: Use a separat potentiometer in controlling each of the color of the RGB led (Red,Green and Blue).  The control must be done with digital electronics.
### :computer: Code: [see my amazing code here :blush:](https://github.com/alexion2001/IntroductionToRobotics/blob/0c940aba00a10b9daafc6054ab52af2926e724e8/HW1_controlling_RBG_with_3_Potentiometers.ino)
  
### :movie_camera: How it works: [see my youtube video here :video_camera:](https://www.youtube.com/shorts/Zp5al3GsAVY)
  
  
### :electric_plug: Electronic scheme:
![Stunning Hango (1)](https://user-images.githubusercontent.com/96074975/197201247-bc62abe6-ff1e-4158-9682-723ed64c8442.png)


![poza_setup](https://user-images.githubusercontent.com/96074975/197208523-eb2c5e17-1bdc-4892-8c30-98eb6ff12097.jpg)



</details>

<details>
<summary><h2>Homework 2: Crosswalk simulator :vertical_traffic_light: :car: :walking: </h2> </summary>
<br>

### Task: Building the traffic lights for a crosswalk. 
### Components: 
- 2 LEDs to represent the traffic lights for people (red and green) + buzzer + button
- 3 LEDs to represent the traffic lights for cars (red, yellow and green).
### The system has the following states:
1. State 1 (default, reinstated after state 4 ends): green light for cars,
red light for people, no sounds. Duration: indefinite, changed by
pressing the button.
2. State 2 (initiated by counting down 8 seconds after a button press):
the light should be yellow for cars, red for people and no sounds.
Duration: 3 seconds.
3. State 3 (initiated after state 2 ends): red for cars, green for people
and a beeping sound from the buzzer at a constant interval. Duration:
8 seconds.
4. State 4 (initiated after state 3 ends): red for cars, blinking green
for people and a beeping sound from the buzzer, at a constant interval,
faster than the beeping in state 3. This state should last 4
seconds.

### :computer: Code: [see my amazing code here :blush:](https://github.com/alexion2001/IntroductionToRobotics/blob/be40cee61b02a843b62377ace9d2fb2a10df98b7/HW2_Traffic_lights_for_a_crosswalk.ino)

### :movie_camera: How it works: [see my youtube video here :video_camera:](https://youtube.com/shorts/tib97UyPijg?feature=share) [and here](https://youtube.com/shorts/E9VyncBOSJI?feature=share)

### :electric_plug: Electronic scheme:

![Cool Crift-Maimu (1)](https://user-images.githubusercontent.com/96074975/199217055-e26f37f7-5463-436d-8ba3-7d6c80b57f6e.png)




![project_photo](https://user-images.githubusercontent.com/96074975/199219840-b409768b-400e-4cae-bbeb-df57a603a941.jpg)


</details>


<details>
<summary><h2>Homework 3: Draw on the display with a joystick :video_game: :pencil2: </h2> </summary>
<br>

### Task: The joystick will be used to control the position of the segment for drawing on the display. 
### Components:
- one 7-segment display

- one joystick
### The system has the following states:
1. State 1 (default, but also initiated after a button press in State 2): Current position blinking. Can use the joystick to move from one position to neighbors. 
Short pressing the button toggles state 2. Long pressing the button in state 1 resets the entire display by turning all the segments OFF and moving the current position to the decimal point.
2. State 2 (initiated after a button press in State 1): The current segment stops blinking, adopting the state of the segment before selection (ON or OFF). Toggling the X axis should change the segment state from ON to OFF or from OFF to ON. Clicking the joystick should save the segment state and exit back to state 1.
### Neighbors allowed:
![image](https://user-images.githubusercontent.com/96074975/200335178-c9aedea2-093e-4e96-8423-12af63b4a919.png)


### :computer: Code: [see my amazing code here :blush:](https://github.com/alexion2001/IntroductionToRobotics/blob/d50501e777d2a494ebe838c1f340180c2da6f32e/HW3_draw_on_7segment_display_with_joystick_v3.ino)

### :movie_camera: How it works: [see my youtube video here :video_camera:](https://youtube.com/shorts/bfYbtOD8xuo?feature=share) 
### :electric_plug: Electronic scheme:

![schema](https://user-images.githubusercontent.com/96074975/200335401-3505d5c8-398f-4574-b88e-a5c170e3b8db.jpg)


![WhatsApp Image 2022-11-07 at 16 33 52](https://user-images.githubusercontent.com/96074975/200336120-2211b6f5-5cd5-4aa7-8f0a-778480e44e30.jpg)





</details>


<details>
<summary><h2>Homework 4: Changing the digit on a 4 digit 7 segment displays with a joystick :video_game: :bulb: :clock130: </h2> </summary>
<br>

### Task: The joystick will be used to move through the 4 digit 7segment displays digits (x axis) . Pressing the button will lock in on the current digit and  the other axis (y axis) will increment or decrement the number.  Pressing the button will reset all the digit values and the current position to the first digit in the first state.
### The system has the following states:
  1.First state: you can use a joystick axis to cycle through the 4 digits;using the other axis does nothing.  A blinking decimal point showsthe current digit position.  When pressing the button, you lock in on the selected digit and enter the second state.
  
  2.Second state: in this state, the decimal point stays always on, no longer blinking and you can no longer use the axis to cycle throughthe  4  digits.   Instead,  using  the  other  axis,  you  can  increment  ondecrement  the  number  on  the  current  digit  IN  HEX  (aka  from  0to F, as in the lab).  Pressing the button again returns you to the previous state.  
  3.Reset:  toggled by long pressing the buttononly in the first state. When resetting, all the digits go back to 0 and the current positionis set to the first (rightmost) digit, in the first state.
### Components:
  - a  joystick
  - a  4  digit  7-segment  display
  - a  74hc595  shiftregister

### :computer: Code: [see my amazing code here :blush:](https://github.com/alexion2001/IntroductionToRobotics/blob/c05333a9fb359a7cdcd145e13eef413b874e9d50/HW4_Changing_the_digi_on_4digit_7segment_displays.ino)

### :movie_camera: How it works: [see my youtube video here :video_camera:](https://youtube.com/shorts/OA8VCIf7ygU) 
### :electric_plug: Electronic scheme:
  ![schema_HW4](https://user-images.githubusercontent.com/96074975/201720648-a5c968f3-4aa0-44c3-a686-1a34a7297b64.PNG)

![WhatsApp Image 2022-11-14 at 22 13 52](https://user-images.githubusercontent.com/96074975/201756539-03be0507-d8c4-4caa-87e4-110d3ba466cb.jpg)




</details>



# Matrix Project Preparation  

- mini useful tasks tried before the matrix game


<details>
<summary><h2>Task 1: Dots battle </h2> </summary>
<br>

### Task: A joystick controlled dot that eats another randomly generated blinking dot. When the player passes over the "food", it disappears and the score increases by 1, and will be generated in another place.

### :computer: Code: [see my amazing code here :blush:](https://github.com/alexion2001/IntroductionToRobotics/blob/8a9a53583245250c2e3a8a1810426a490a0144b2/EatTheDotGame.ino)

### :movie_camera: How it works: [see my youtube video here :video_camera:](https://youtube.com/shorts/YY9iftQlURI?feature=share) 
### :electric_plug: Electronic tables:
![image](https://user-images.githubusercontent.com/96074975/203067022-dad49cc5-8ae0-4a7f-a200-9694e8e05168.png)

### - Matrix to Driver Connections Table

![image](https://user-images.githubusercontent.com/96074975/203066931-a6ceeff2-e593-482d-9d34-42d677148a10.png)

### - Connecting the driver to Arduino
![image](https://user-images.githubusercontent.com/96074975/203067154-8d8f29b0-b82a-47f1-b42e-0aa755d4e978.png)


</details>






