//declarare pini potentiometre
const int bluePotPin = A0;
const int greenPotPin = A1;
const int redPotPin = A2;

//declarare pini RGB
const int greenPin = 11;
const int bluePin = 10;
const int redPin = 9;

//declarare valoare potentiometre
int greenPotValue = 0;
int bluePotValue = 0;
int redPotValue = 0;

//declarare valori pentru culorile RGB
int greenPinValue = 0;
int bluePinValue = 0;
int redPinValue = 0;

const int splitValue = 4;

void setup() {
	Serial.begin(9600);
}

void loop() {
  
  //citirea valorilor potentiometrelor
  greenPotValue = analogRead(greenPotPin);
  bluePotValue = analogRead(bluePotPin);
  redPotValue = analogRead(redPotPin); 

  //calculare valoare analog pentru led
  greenPinValue = greenPotValue / splitValue;
  bluePinValue = bluePotValue / splitValue;
  redPinValue = redPotValue / splitValue;
  
  // setam culorile RGB in functie de valorile potentiometrelor
  analogWrite(redPin, redPinValue); 
  analogWrite(greenPin, greenPinValue);
  analogWrite(bluePin, bluePinValue);

  Serial.println(redPinValue);
  
}

