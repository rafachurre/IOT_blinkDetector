/*
  blink detector
  darcy@inventorArtist.com
  http://inventorartist.com/blink-detector/ 

  uses LED to detect blinking
  just looks for rising edges
  

*/
int sensorPin  = 0;        // IR Sensor
int ledPin = 4;           // Visualization
int lastLevel = 0;         // Previous IR level
int lastChange = 0;        // Change in IR level
int changeThreshold = 35;  // How hard a rising edge do we need?

//visualization
int duration = 750;        // Length of visualization
float firstBlink = 0;       // Last start of visualization

bool state= true;
int timesBlink =0;

void setup() {
  Serial.begin(9600);      // Debug constructor
  pinMode(4, OUTPUT);     // Visualizatio constructor
}
 
void loop() {
  int sensorValue = analogRead(sensorPin);Serial.println(sensorValue);  // Read Data
  // look for rising edges
  lastChange = sensorValue - lastLevel;
  lastLevel = sensorValue;
  delay(50);
  if(millis()>=firstBlink+duration){
    timesBlink=0;
  }  
  if (lastChange >=changeThreshold){
    timesBlink = timesBlink+1;
    Serial.println("threshold");
    firstBlink = millis();
    if(timesBlink==2) {
      if(state){
        digitalWrite(ledPin, HIGH);
        //lastStart = millis();
        state = !state;
        Serial.println("LEDChangeON");
      }else{
        digitalWrite(ledPin, LOW);
        state = !state;
        Serial.println("LEDChangeOFF");
      }
      timesBlink = 0;
    }
  }
//  if (millis() >= lastStart + duration) {
//     digitalWrite(ledPin, LOW);
//  }
  
  
  //absolute approach
  //if (sensorValue >=205) {
  //  digitalWrite(13, HIGH);
  //}else{
  //  digitalWrite(13, LOW);
  //}
  //delay(100);
}
