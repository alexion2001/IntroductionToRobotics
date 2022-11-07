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


### :computer: Code: [see my amazing code here :blush:]()

### :movie_camera: How it works: [see my youtube video here :video_camera:]() 
### :electric_plug: Electronic scheme:

![schema](https://user-images.githubusercontent.com/96074975/200335401-3505d5c8-398f-4574-b88e-a5c170e3b8db.jpg)


![WhatsApp Image 2022-11-07 at 16 33 52](https://user-images.githubusercontent.com/96074975/200336120-2211b6f5-5cd5-4aa7-8f0a-778480e44e30.jpg)





</details>


<details>
<summary><h2>Homework 4: :x: unknown :x: </h2> </summary>
<br>

### Task: 

### :computer: Code: [see my amazing code here :blush:]()

### :movie_camera: How it works: [see my youtube video here :video_camera:]() 
### :electric_plug: Electronic scheme:




</details>





