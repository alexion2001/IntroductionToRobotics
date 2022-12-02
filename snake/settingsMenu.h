
//pins
//const int contrastPin = 6;
const int brightnessPin = 3;



int levels[] = {0,50,120,170,210,255};
//              0  1  2   3   4   5



void enterSettingsOptions(int currentSetting){
  //enter in current selected option

  if (currentSetting == 0) // DIFFICULTY
      {

      }
  else if (currentSetting == 1)// contrast
      { 

      } 
  else if (currentSetting == 2)// lsc brightness
      { //move left and write to change
        Serial.print(brightnessLevel);    

        lcdBrightness(brightnessLevel); // ANIMATION ON THE LCD
        analogWrite(brightnessPin, levels[brightnessLevel]); // make change on lcd

        //update in EEPROM

        EEPROM.update(brightnessLevelAddress, brightnessLevel);
        brightnessLevel = EEPROM.read(brightnessLevelAddress);


        

     //   EEPROM.update(0, lcdContrast);
        
      } 
  else if (currentSetting == 3) // matrix brightnesss
      {
       
      }
  else if (currentSetting == 4) // sound
      {

      }
  else if (currentSetting == 5) // exit to main menu
      {
         mainMenu();
      }
}

void moveToRight(int currentSetting){
   //move the level bar to left
     //change the level I need
if (currentSetting == 0) // DIFFICULTY
      {
           difficultyLevel++;
      }
  else if (currentSetting == 1)// contrast
      { 
        contrastLevel++;

      } 
  else if (currentSetting == 2)// lsc brightness
      { 
        if (brightnessLevel < 5)
        {brightnessLevel ++; }
          
      } 
  else if (currentSetting == 3) // matrix brightnesss
      {
       matrixIntensityLevel ++;
      }
  else if (currentSetting == 4) // sound
      {

      }
      enterSettingsOptions(currentSetting);

}


void moveToLeft(int currentSetting){
   //move the level bar to left
   if (currentSetting < 5) {
     //change the level I need
if (currentSetting == 0) // DIFFICULTY
      {
           difficultyLevel--;
      }
  else if (currentSetting == 1)// contrast
      { 
        contrastLevel--;

      } 
  else if (currentSetting == 2)// lsc brightness
      { 
        if (brightnessLevel > 0)
        {brightnessLevel --; }   
      } 
  else if (currentSetting == 3) // matrix brightnesss
      {
       matrixIntensityLevel --;
      }
  else if (currentSetting == 4) // sound
      {

      }

      enterSettingsOptions(currentSetting);
    }

}

