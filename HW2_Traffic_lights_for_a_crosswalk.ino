//declarare pini
const int buttonPin = 2;
const int passerRedLedPin = 6;
const int passerGreenLedPin = 5;
const int carsRedLedPin = 9;
const int carsYellowLedPin = 10;
const int carsGreenLedPin = 11;
const int buzzerPin = 3;

//declarare stari initiale
byte buttonState = LOW;
byte passerRedLedState = LOW;
byte passerGreenLedState = LOW;
byte carsRedLedState = LOW;
byte carsYellowLedState = LOW;
byte carsGreenLedState = LOW;
byte buzzerState = LOW;
int buzzerTone = 125;

//variabile citire buton
byte lastReading = LOW;
byte reading = LOW;

//variabile pentru timp
int lastDebounceTime = 0;
int debounceInterval = 50;
unsigned long trafficLightTime = 0; // variabila folosita pentru memorarea timpului de cand s-a trecut intr-o noua stare
unsigned long elapsedBlinkTime=0;
int secInMillis = 1000;

//stage duration
int stage1DurationAfterPress = 8; //8
int stage2Duration= 3; //3
int stage3Duration = 8; //8
int stage4Duration = 4;  //4
int blinkTime = 350;
int fasterBlinkTime = 200;

// variabile pentru stare
int currentStage = 1;
bool stageReset = 0;

void setup() {
  Serial.begin(9600);
  pinMode(buttonPin,INPUT_PULLUP);
  pinMode(passerRedLedPin,OUTPUT);
  pinMode(passerGreenLedPin,OUTPUT);
  pinMode(carsRedLedPin,OUTPUT);
  pinMode(carsYellowLedPin,OUTPUT);
  pinMode(carsGreenLedPin,OUTPUT);
}
void loop() {
  switch (currentStage){
    case 1: //State1(default): green light for cars, red light for people, no sound 
      carsGreenLedState = HIGH;
      carsRedLedState = LOW;
      passerRedLedState = HIGH;
      passerGreenLedState = LOW;

      digitalWrite(carsRedLedPin,carsRedLedState);     
      digitalWrite(carsGreenLedPin,carsGreenLedState);
      digitalWrite(passerRedLedPin,passerRedLedState);
      digitalWrite(passerGreenLedPin,passerGreenLedState);
      analogWrite(buzzerPin, 0);
     
     //debounce - citire buton si schimbare catre starea 2 daca este apasat
      reading = digitalRead(buttonPin);
      if (reading != lastReading){
        lastDebounceTime = millis();
      }
      if (millis() - lastDebounceTime > debounceInterval){ 
        if (reading != buttonState){
          buttonState = reading;
          if (buttonState == LOW){
            currentStage = 2;
            trafficLightTime = millis(); 
          }
        }
      }
      lastReading = reading;
      break;
    case 2: //State2(3s):the  light  should  be  yellow  for  cars,  red  for  people  and  no  sounds.
      //activez starea 2 doar daca au trecut 8 secunde de la apasarea butonului
      if(millis() - trafficLightTime >= stage1DurationAfterPress * secInMillis){ 
         trafficLightTime = millis();
         stageReset = 1;
         carsGreenLedState = LOW;
         carsYellowLedState = HIGH;
         
         digitalWrite(carsYellowLedPin,carsYellowLedState);
         digitalWrite(carsGreenLedPin,carsGreenLedState);
        }
      // dupa 4 secunde in starea 2 trec la starea 3
      if (stageReset == 1 && millis() - trafficLightTime >= stage2Duration * secInMillis){
        currentStage = 3;
        stageReset = 0;
        trafficLightTime = millis();
        elapsedBlinkTime = trafficLightTime;
        }
      break;
    case 3: //State3(8s):red for cars, green for people and a beeping sound from the buzzer at a constant interval
      if(millis() - trafficLightTime < stage3Duration * secInMillis){
        carsYellowLedState = LOW;
        carsRedLedState = HIGH;
        passerRedLedState = LOW;
        passerGreenLedState = HIGH;

        digitalWrite(carsYellowLedPin,carsYellowLedState);
        digitalWrite(carsRedLedPin,carsRedLedState);
        digitalWrite(passerRedLedPin,passerRedLedState);
        digitalWrite(passerGreenLedPin,passerGreenLedState);

        if(millis() - elapsedBlinkTime >= blinkTime){ // setare interval de intermitenta led verde pietoni si buzzer
          elapsedBlinkTime = millis();
          buzzerState = !buzzerState;
          if(buzzerState) // daca starea buzzer-ul este activ, setez tonalitatea
            analogWrite(buzzerPin, buzzerTone);
          else 
            analogWrite(buzzerPin, LOW);
          }
        }
      else{ // dupa timpul alocat starii 3 trec in starea 4
        currentStage = 4;
        trafficLightTime = millis();
        elapsedBlinkTime = trafficLightTime;
      }
      break;
    case 4: //State4(4s): red for cars,blinking green for people and a beeping sound from the buzzer,  at a constant interval,faster than the beeping in state 3.
      if(millis() - trafficLightTime < stage4Duration * secInMillis){
        if(millis() - elapsedBlinkTime >= fasterBlinkTime){ // setare interval de intermitenta led verde pietoni si buzzer
          elapsedBlinkTime = millis();
          passerGreenLedState = !passerGreenLedState; 
          buzzerState = !buzzerState;
          digitalWrite(passerGreenLedPin,passerGreenLedState);
          if(buzzerState) // daca starea buzzer-ul este activ, setez tonalitatea
            analogWrite(buzzerPin, buzzerTone);
          else 
            analogWrite(buzzerPin, LOW);
          }
        }
      else{ // dupa timpul alocat starii 4 ma intorc in starea 1
        currentStage = 1;
        trafficLightTime = millis();
        }
      break;
  }
}
