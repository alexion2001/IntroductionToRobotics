//pins
const int xPin = A0;
const int yPin = A1;
const int pinSw = 2;

const int minThreshold = 200;
const int maxThreshold = 600;
int xValue = 0;
int yValue = 0;
bool swState = HIGH;

//debounce
long lastTime = 0;
long lastJoyTime = 0;
int interval = 50;
byte reading = LOW;
byte joyState = LOW;
byte lastReading = LOW;
byte joyReading = LOW;
byte lastJoyReading = HIGH;
bool joyMoved = false;



void readFromJoystick() {

//joystick button
  reading = digitalRead(pinSw);

  if (reading != lastReading){
    lastTime = millis();
  } 

  if (millis() - lastTime > interval){
    if (reading != swState){
      swState = reading;
      if (swState == LOW){
         if (inMainMenu){ //we are in main menu
            enterMainMenu();
           }
           else if (inSettings){
             //we are in setting menu
              enterSettingsOptions(currentSetting);
           }
           else if (inGame){
             //we are in game mode
           }


      }
    }
  } 
  lastReading = reading;

  
///joystick movements
  xValue = analogRead(xPin);
  yValue = analogRead(yPin);

  if ((xValue > minThreshold && xValue < maxThreshold) || (yValue > minThreshold && yValue < maxThreshold)) {
        joyReading = LOW;   
      }
  if((xValue < minThreshold || xValue > maxThreshold) || (yValue < minThreshold || yValue > maxThreshold)){
        joyReading = HIGH;   
      }

  if(joyReading != lastJoyReading){
        lastJoyTime = millis();
      }

  if(millis()-lastJoyTime > interval) 
    if(joyReading != joyState){ 
      joyState = joyReading;
      if(joyReading==HIGH)  
        joyMoved = false;
    }
  
  if (xValue > maxThreshold && joyMoved == false) { // in sus
        joyMoved = true;
        if (inMainMenu){ //we are in main menu
            if (currentOption < lastPosition) {
                currentOption ++;
                mainMenu();
           }
        }
           else if (inSettings){
             //we are in setting menu
            if (currentSetting < lastSettingsPosition) {
                currentSetting ++;
                enterSettings();
                
           }
           }
           else if (inGame){
             //we are in game mode
           } 
      } 
  if (xValue < minThreshold && joyMoved == false)  { //in jos
        joyMoved = true;
      if (inMainMenu){ //we are in main menu
            if (currentOption > firstPosition) {
                currentOption --;
                mainMenu();
           }
        }
      else if (inSettings){
             //we are in setting menu
            if (currentSetting > firstPosition) {
                currentSetting --;
                enterSettings();
           }
           }
           else if (inGame){
             //we are in game mode
           }
      }
  if (yValue > maxThreshold && joyMoved == false) { // in dreapta
        joyMoved = true;

        if (inSettings){
             //move the level bar to left
               moveToLeft(currentSetting);   
           }
        else if (inGame){
             //we are in game mode
           }
        
      } 
  if (yValue < minThreshold && joyMoved == false)  { //in stanga
        joyMoved = true;
        if (inSettings){
           moveToRight(currentSetting);
           }
        else if (inGame){
             //we are in game mode
           }
        
      }   
        
  lastJoyReading = joyReading;
}

