
const byte dinPin = 12;
const byte clockPin = 11;
const byte loadPin = 10;
const byte matrixSize = 8;

const int delayMainMenuAnimation = 300;

LedControl lc = LedControl(dinPin, clockPin, loadPin, 1); //DIN, CLK, LOAD, No. DRIVER

byte matrixBrightness = 2;

const byte SNAKE[][8] = {
{
  B01111000,
  B11001100,
  B11100000,
  B01110000,
  B00011100,
  B11001100,
  B01111000,
  B00000000
},{
  B11000110,
  B11100110,
  B11110110,
  B11011110,
  B11001110,
  B11000110,
  B11000110,
  B00000000
},{
  B00110000,
  B01111000,
  B11001100,
  B11001100,
  B11111100,
  B11001100,
  B11001100,
  B00000000
},{
  0b11100110,
  0b01100110,
  0b01101100,
  0b01111000,
  0b01101100,
  0b01100110,
  0b11100110,
  0b00000000
},{
  0b11111110,
  0b01100010,
  0b01101000,
  0b01111000,
  0b01101000,
  0b01100010,
  0b11111110,
  0b00000000
}};

const int snakeSize = 5;

const byte smiley[8] = {
  0b00111100,
  0b01000010,
  0b10100101,
  0b10000001,
  0b10100101,
  0b10011001,
  0b01000010,
  0b00111100
};

void greetingsMatrix() {
  lc.clearDisplay(0);
  for (int letter = 0; letter < snakeSize; letter++){
    for (int row = 0; row < matrixSize; row++) {
    lc.setRow(0, row, SNAKE[letter][row]);
  }
  delay(delayMainMenuAnimation);
  }
  
}

void menuMatrix() {
  lc.clearDisplay(0);
  for (int row = 0; row < matrixSize; row++) {
  lc.setRow(0, row, smiley[row]);
  }
  
  
  
}
 
 