#include "LedControl.h" //  need the library
const int dinPin = 12;
const int clockPin = 11;
const int loadPin = 10;

const int xPin = A0;
const int yPin = A1;

LedControl lc = LedControl(dinPin, clockPin, loadPin, 1); // DIN, CLK, LOAD, No. DRIVER

byte matrixBrightness = 2;

byte xPos = 0;
byte yPos = 0;
byte xLastPos = 0;
byte yLastPos = 0;

const int minThreshold = 200;
const int maxThreshold = 600;

const byte moveInterval = 100;
unsigned long long lastMoved = 0;

const byte matrixSize = 8;
bool matrixChanged = true;

byte matrix[matrixSize][matrixSize] = {
  {0, 0, 0, 0, 0, 0, 0, 0}, //0
  {0, 0, 0, 0, 0, 0, 0, 0}, //1
  {0, 0, 0, 0, 0, 0, 0, 0}, //2
  {0, 0, 0, 0, 0, 0, 0, 0}, //3
  {0, 0, 0, 0, 0, 0, 0, 0}, //4
  {0, 0, 0, 0, 0, 0, 0, 0}, //5
  {0, 0, 0, 0, 0, 0, 0, 0}, //6
  {0, 0, 0, 0, 0, 0, 0, 0}  //7
};

byte matrixByte[matrixSize] = {
  B00000000,
  B01000100,
  B00101000,
  B00010000,
  B00010000,
  B00010000,
  B00000000,
  B00000000
};

//random dot
int randomX = 0;
int randomY = 0;
const int minValue = 0;
const int maxValue = 8;

//score
int score = 0;

//blink time
int blinkTime = 300;
long lastBlinkTime;

void setup() {
  Serial.begin(9600);
  // the zero refers to the MAX7219 number, it is zero for 1 chip
  lc.shutdown(0, false); // turn off power saving, enables display
  lc.setIntensity(0, matrixBrightness); // sets brightness (0~15 possible values)
  lc.clearDisplay(0);// clear screen
  generateFood();  
  matrix[xPos][yPos] = 1;
}
void loop() {
  
  if (millis() - lastMoved > moveInterval) {
  // game logic
    updatePositions();
    lastMoved = millis();
  }
  if (millis() - lastBlinkTime > blinkTime) {
  // game logic
    blinkFood();
    lastBlinkTime = millis();
  }
  if (matrixChanged == true) {
    // matrix display logic
    updateMatrix();
    matrixChanged = false;
  }
  if (randomX == xPos && randomY == yPos){
    score ++;
    Serial.println(score);
    generateFood(); 
  }
} 
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
  matrix[randomX][randomY] = !matrix[randomX][randomY];
  matrixChanged = true;
}

void updateByteMatrix() {
  for (int row = 0; row < matrixSize; row++) {
    lc.setRow(0, row, matrixByte[row]);
  }
}
void updateMatrix() {
  for (int row = 0; row < matrixSize; row++) {
    for (int col = 0; col < matrixSize; col++) {
      lc.setLed(0, row, col, matrix[row][col]);
    }
  }
}

void updatePositions() {
  int xValue = analogRead(xPin);
  int yValue = analogRead(yPin);
  
  xLastPos = xPos;
  yLastPos = yPos;
  if (xValue < minThreshold) {
    if (xPos < matrixSize - 1) {
      xPos++;
    } 
    else {
      xPos = 0;
    }
  }
  if (xValue > maxThreshold) {
    if (xPos > 0) {
      xPos--;
    }
    else {
      xPos = matrixSize - 1;
    }
  }

  if (yValue > maxThreshold) {
    if (yPos < matrixSize - 1) {
      yPos++;
    } 
    else {
      yPos = 0;
    }
  }

  if (yValue < minThreshold) {
    if (yPos > 0) {
      yPos--;
    }
    else {
      yPos = matrixSize - 1;
    }
  }
  if (xPos != xLastPos || yPos != yLastPos) {
    matrixChanged = true;
    matrix[xLastPos][yLastPos] = 0;
    matrix[xPos][yPos] = 1;
  }  
} 