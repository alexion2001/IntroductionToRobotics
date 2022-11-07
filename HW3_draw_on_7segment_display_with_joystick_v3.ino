// declarare pini segmente
const int pinA = 4;
const int pinB = 5;
const int pinC = 6;
const int pinD = 7;
const int pinE = 8;
const int pinF = 9;
const int pinG = 10;
const int pinDP = 11;

//declarare pini joystick
const int pinX = A0;
const int pinY = A1;
const int pinSW = 2;

//variabile de control pentru 7-Segment-Display
const int segSize = 8;
const int noOfDigits = 10;
int index = 0;
bool commonAnode = false;

//stari segmente
byte segmentState = LOW;
byte dpState = LOW;

//stari si valori pentru joystick
int xValue = 0;
int yValue = 0;
byte swState = LOW;

//debounce
long lastTime = 0;
long lastTimeLong = 0;
long lastJoyTime = 0;
int interval = 50;
int longInterval = 1000;
byte reading = LOW;
byte lastReading = LOW;
byte joyReading = LOW;
byte lastJoyReading = HIGH;
byte longPress = LOW;

int segments[segSize] = {
  pinA, pinB, pinC, pinD, pinE, pinF, pinG, pinDP
};
//ultimele valori ale segmentelor
int segmentsState[segSize] = {
  segmentState, segmentState, segmentState, segmentState, segmentState, segmentState, segmentState, segmentState
};

//variabile control joystick
const int minThreshold = 400;
const int maxThreshold = 600;
bool joyMoved = false;

//stari - true = stare 1, false = stare 2
bool currentState = true;
bool toState2 = false; 
int currentSegment = segSize - 1;
int lastSegment = segSize - 1;

//blink
unsigned long blinkTime = 300;
unsigned long lastBlinkTime = 0;

const int directions = 4;
int segmentsNeighbors[segSize][directions] = {
//   up down left right (-1 - None)
    {-1, 6, 5, 1},//a - 0
    { 0, 6, 5,-1},//b - 1
    { 6, 3, 4, 7},//c - 2
    { 6,-1, 4, 2},//d - 3
    { 6, 3,-1, 2},//e - 4
    { 0, 6,-1, 1},//f - 5
    { 0, 3,-1,-1},//g - 6
    {-1,-1, 2,-1}//dp - 7
};

const int up = 0;
const int down = 1;
const int left = 2;
const int right = 3;
int neighbor = 0;

void setup() {
  pinMode(pinSW, INPUT_PULLUP);

  if (commonAnode == true) {
    segmentState = !segmentState;
  }
  for (int i = 0; i < segSize; i++){
    pinMode(segments[i], OUTPUT);
  }
  resetSegments();
  Serial.begin(9600);
}

void loop() {
  reading = digitalRead(pinSW);
  if (reading != lastReading){
    lastTime = millis();
  } 
  if(millis()-lastTime > longInterval){
    if(reading != longPress){
      longPress = reading;
        if(longPress == LOW){
          Serial.println("long press");
          resetSegments();
        }
      }
  }
  else if (millis() - lastTime > interval){
    if (reading != swState){
      swState = reading;
      if (swState == LOW){
        currentState = !currentState;
        Serial.println("short press");
        toState2 = false; 
      }
    }
  } 
  lastReading = reading;
  if (currentState){ //state 1
      //clipire leg la selectie segment
      if (millis() - lastBlinkTime >= blinkTime){
        lastBlinkTime = millis();
        segmentState = !segmentState;
        digitalWrite(segments[currentSegment], segmentState);
      }    
      //citire valoare joystick
      xValue = analogRead(pinX);
      yValue = analogRead(pinY);
      if (xValue > maxThreshold && joyMoved == false) { // in sus
        joyMoved = true;
        moveToNeighbor(up);      
      } 
      if (xValue < minThreshold && joyMoved == false)  { //in jos
        joyMoved = true;
        moveToNeighbor(down);
      }
      if (yValue > maxThreshold && joyMoved == false) { // in dreapta
        joyMoved = true;
        moveToNeighbor(right);
      } 
      if (yValue < minThreshold && joyMoved == false)  { //in stanga
        joyMoved = true;
        moveToNeighbor(left);
      }      
      if ((xValue > minThreshold && xValue < maxThreshold) || (yValue > minThreshold && yValue < maxThreshold)) {
        joyReading = LOW;   
      }
      if((xValue < minThreshold || xValue > maxThreshold) || (yValue < minThreshold || yValue > maxThreshold)){
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
  else{ //state 2
    if (toState2 == false){
      toState2 = true;
      // opresc segmentul din clipit si il setez la starea lui de dinainte de selectie
      digitalWrite(segments[currentSegment], segmentsState[currentSegment]);    
    }  
    //schimbare pe axa x a state-ului segmentului selectat
    xValue = analogRead(pinX);
    if (xValue > maxThreshold && joyMoved == false) { // in sus
        joyMoved = true;
        segmentsState[currentSegment] = HIGH; //aprind daca dau in sus de joystick
        digitalWrite(segments[currentSegment],segmentsState[currentSegment]);       
      } 
    if (xValue < minThreshold && joyMoved == false)  { //in jos
        joyMoved = true;
        segmentsState[currentSegment] = LOW; //stingdaca dau in sus de joystick
        digitalWrite(segments[currentSegment],segmentsState[currentSegment]);        
      }
    if (xValue > minThreshold && xValue < maxThreshold) {
        joyMoved = false;
      }
  }
}

void resetSegments(){
  for (int i = 0; i < segSize; i++){
    digitalWrite(segments[i], LOW);
  }
  currentSegment = segSize - 1;
  currentState = true;
}

void moveToNeighbor(int direction){
  neighbor = segmentsNeighbors[currentSegment][direction];
  if (neighbor != -1){
    lastSegment = currentSegment;
    Serial.println("lastSegment");
    Serial.println(lastSegment);
     
    currentSegment = neighbor;
    Serial.println("currentSegment"); 
    Serial.println(currentSegment);  
    digitalWrite(segments[lastSegment],segmentsState[lastSegment]);
  }
}



