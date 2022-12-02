int difficultyLevel;
int contrastLevel;
int brightnessLevel;
int matrixIntensityLevel;

const int difficultyLevelAddress = 0;
const int contrastLevelAddress = 1;
const int brightnessLevelAddress = 2;
const int matrixIntensityLevelAddress = 3;

int level;

#include <LiquidCrystal.h>
#include <LedControl.h> 
#include <EEPROM.h>

#include "MatrixAnimation.h"
#include "highscoreMenu.h"
#include "mainMenu.h"
#include "settingsMenu.h"
#include "subMenus.h"
#include "joystickMovements.h"


// EERPROM
//0-3 Levels
//4-7 player 1
//   456 - name letters numbers
//    7 - score
//8-11 player 2
//12-15 player 3
//16-19 player 4
//20-23 player 5


void setup() {

  lc.shutdown(0, false); // turn off power saving, enables display
  lc.setIntensity(0, matrixBrightness); // sets brightness (0~15 possible values)
  lc.clearDisplay(0);// clear screen

  analogWrite(brightnessPin, 255);

  pinMode(RS, OUTPUT);
  pinMode(xPin, INPUT);
  pinMode(yPin, INPUT);
  pinMode(pinSw, INPUT_PULLUP);

  // EEPROM.write(0, 1); 
  // EEPROM.write(1, 4);
  // EEPROM.write(2, 4);
  // EEPROM.write(3, 4);

  difficultyLevel = EEPROM.read(difficultyLevelAddress); 
  contrastLevel = EEPROM.read(contrastLevelAddress);
  brightnessLevel = EEPROM.read(brightnessLevelAddress);
  matrixIntensityLevel = EEPROM.read(matrixIntensityLevelAddress);

  analogWrite(brightnessPin, levels[brightnessLevel]);

  
  // int lastPos = 25 ;
  // for (int index = 4; index <= lastPos; index = index + 4){ // get de top 5 highscore
  //   EEPROM.write(index, 13);
  //   EEPROM.write(index + 1, 0);
  //   EEPROM.write(index + 2, 13);
  //   EEPROM.write(index + 3, 0);
  // }



  greetings();
  mainMenu();
  Serial.begin(9600);
  

}

void loop() {
  // put your main code here, to run repeatedly:
  readFromJoystick();
 
}
