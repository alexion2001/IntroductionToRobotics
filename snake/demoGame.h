//random dot
int randomX = 0;
int randomY = 0;
const int minValue = 0;
const int maxValue = 8;

//blink time
int blinkTime = 300;
long lastBlinkTime;

//message delay
const int messageTime = 3000;


void generateFood() {

  //generate new pos
  randomX  = random(minValue, maxValue);
  randomY  = random(minValue, maxValue);
  //avoiding generating the player's position
  while (randomX == xPos && randomY == yPos){
    randomX  = random(minValue, maxValue);
    randomY  = random(minValue, maxValue);
  }
  //turn on new pos
  matrix[randomX][randomY] = 1;
  matrixChanged = true;
}

void blinkFood(){

  if (millis() - lastBlinkTime > blinkTime) {
  // game logic
      matrix[randomX][randomY] = !matrix[randomX][randomY];
      matrixChanged = true;

      lastBlinkTime = millis();
   }  
}

void gameFinishMessage(){
  gameOverMatrix();

  lcd.clear();
  lcd.setCursor(0, 0); 
  lcd.print("Well done!"); 
  lcd.setCursor(0, 1); 
  lcd.print("Your score: "); 
  lcd.print(score); 

  delay(messageTime);

  mainMenu();
}

void checkUpdate(){

  if(firstFood){
    randomSeed(analogRead(pinSw));
    generateFood();
    firstFood = false;
  }

  if (randomX == xPos && randomY == yPos){
    score ++;
    LcdGameUpdate();
    generateFood(); 
  }

  if (score == 10){//end game
    gameFinishMessage();
  }

  if (matrixChanged == true) {
    // matrix display logic
    updateMatrix();
    matrixChanged = false;
  }
}



