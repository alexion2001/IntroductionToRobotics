const int latchPin = 11; // STCP to 12 on Shift Register
const int clockPin = 10; // SHCP to 11 on Shift Register
const int dataPin = 12; // DS to 14 on Shift Register

const int segD1 = 7;
const int segD2 = 6;
const int segD3 = 5;
const int segD4 = 4;

const byte regSize = 8; // 1 byte aka 8 bits

int displayDigits[] = {
  segD1, segD2, segD3, segD4
};
const int displayCount = 4;
const int encodingsNumber = 16;

//declarare pini joystick
const int pinX = A0;
const int pinY = A1;
const int pinSW = 2;

int byteEncodings[encodingsNumber] = {
//A B C D E F G DP 
  B11111100, // 0 
  B01100000, // 1
  B11011010, // 2
  B11110010, // 3
  B01100110, // 4
  B10110110, // 5
  B10111110, // 6
  B11100000, // 7
  B11111110, // 8
  B11110110, // 9
  B11101110, // A
  B00111110, // b
  B10011100, // C
  B01111010, // d
  B10011110, // E
  B10001110  // F
};

//valorile curente
int digitsOfDisplay[displayCount] = { 
//0  1  2  3
  0, 0, 0, 0
};

//stari si valori pentru joystick
int xValue = 0;
int yValue = 0;
byte swState = LOW;

//debounce
long lastTime = 0;
int interval = 50;
int longInterval = 1000;
byte reading = LOW;
byte lastReading = LOW;
byte joyReading = LOW;
byte lastJoyReading = HIGH;
byte longPress = LOW;

//variabile control joystick
const int minThreshold = 400;
const int maxThreshold = 600;
bool joyMoved = false;

//stari - true = stare 1, false = stare 2
bool currentState = true;
bool toState2 = false; 
int currentDisplay = 0; 
int currentCharacterIndex = 0; 

//blink
unsigned long blinkTime = 300;
unsigned long lastBlinkTime = 0;
bool blink = false;

void setup() {
  pinMode(pinSW, INPUT_PULLUP);

  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);

  for (int i = 0; i < displayCount; i++) {
    pinMode(displayDigits[i], OUTPUT);
  }  
  resetDisplay();
  Serial.begin(9600);
}

void loop() {
  reading = digitalRead(pinSW);
  if (reading != lastReading){
    lastTime = millis();
  } 
  if(millis()-lastTime > longInterval){ //long press - resetare
    if(reading != longPress){
      longPress = reading;
        if(longPress == LOW){
          if (currentState == false){
              resetDisplay();            
          }
        }
      }
  }
  else if (millis() - lastTime > interval){ //short press
    if (reading != swState){
      swState = reading;
      if (swState == LOW){
        currentState = !currentState; // schimb din starea 1 in 2 si invers
        toState2 = false; 
      }
    }
  } 
  lastReading = reading;

  if (currentState){ //state 1
      //clipire led-ul digit-ului curent
      if (millis() - lastBlinkTime >= blinkTime){
        lastBlinkTime = millis();
        blink = !blink;
      }
      joystickMovementsState1(); 
  }
  else{ //state 2
    if (toState2 == false){
      toState2 = true;
    }  
   joystickMovementsState2();
   blink = true;
  }
  chracterWrite(blink);
}


void joystickMovementsState1(){
  //citire valoare joystick
      yValue = analogRead(pinY);
      if (yValue > maxThreshold && joyMoved == false) { // in stanga
        joyMoved = true;
        if (currentDisplay > 0){
            currentDisplay --;
        }
        Serial.println(currentDisplay);
      } 
      if (yValue < minThreshold && joyMoved == false)  { //in dreapta
        joyMoved = true;  
        if (currentDisplay < displayCount - 1){
            currentDisplay ++;
        }    
        Serial.println(currentDisplay);
      }  
      if ((yValue > minThreshold && yValue < maxThreshold)) {
        joyReading = LOW;   
      }
      if((yValue < minThreshold || yValue > maxThreshold)){
        joyReading = HIGH;   
      }
      if(joyReading != lastJoyReading){
        lastTime = millis();
      }
        if(joyReading != lastJoyReading)
           if(joyReading==HIGH)
              joyMoved=false;
      lastJoyReading = joyReading;
      
}

void joystickMovementsState2(){
   //schimbare pe axa x a state-ului segmentului selectat
    xValue = analogRead(pinX);
    if (xValue > maxThreshold && joyMoved == false) { // in sus
        joyMoved = true;
        if (currentCharacterIndex < encodingsNumber - 1){
            currentCharacterIndex ++;
            digitsOfDisplay[currentDisplay] = currentCharacterIndex; // actualizare afisaj
            
        }
        Serial.println(currentCharacterIndex);
          
      } 
    if (xValue < minThreshold && joyMoved == false)  { //in jos
        joyMoved = true;
        
        if (currentCharacterIndex > 0){
            currentCharacterIndex --;
            digitsOfDisplay[currentDisplay] = currentCharacterIndex; // actualizare afisaj
            
        }  
        Serial.println(currentCharacterIndex);
             
      }
    if (xValue > minThreshold && xValue < maxThreshold) {
        joyMoved = false;
      }
}


void resetDisplay(){
  for (int i = 0; i < displayCount; i++) {
    digitsOfDisplay[i] = 0;
  } 
  currentDisplay = 0;
  currentState = true; //starea 1
}


void activateDisplay(byte displayNumber) {
  for (int i = 0; i < displayCount; i++) {
    digitalWrite(displayDigits[i], HIGH); //opreste toate digit-urile
  }
  digitalWrite(displayDigits[displayNumber], LOW);  // activare display-ul curent
}

void writeReg(byte encoding) {
    digitalWrite(latchPin, LOW);
    shiftOut(dataPin, clockPin, MSBFIRST, encoding);
    digitalWrite(latchPin, HIGH);
}

void chracterWrite(bool blink){ // blink = 0 - no blink, 1 - blink on, 2 - blink off
  int chrIndex;
  byte encoding;
  for(int i = 0; i <displayCount; i++) {
    activateDisplay(i);
    chrIndex = digitsOfDisplay[i];
    encoding = byteEncodings[chrIndex];
    if (blink == true){
      if (i == currentDisplay){
          encoding = encoding + 1;
      }
    }
    writeReg(encoding);
    delay(5);
  }
}


