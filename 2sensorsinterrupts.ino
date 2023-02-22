int led1 = 13;                // the pin that the LED1 is attached to
int led2 = 8;                 // the pin that the LED2 is attached to
int sensor1 = 2;              // the pin that the sensor1 is attached to
int sensor2 = 3;              // the pin that the sensor2 is attached to

// by default, no motion detected
volatile int state1 = LOW;    
volatile int state2 = LOW;

void setup() {
  // initialized LED1 and LED2 as an output
  pinMode(led1, OUTPUT);      
  pinMode(led2, OUTPUT);
  
  // Also, initialized sensor1 and sensor2 as an input
  pinMode(sensor1, INPUT);    
  pinMode(sensor2, INPUT);

  // attach interrupt to sensor pin, trigger on rising edge (HIGH)
  attachInterrupt(digitalPinToInterrupt(sensor1), motionDetected1, HIGH);
  attachInterrupt(digitalPinToInterrupt(sensor2), motionDetected2, HIGH);
 
  Serial.begin(9600);        // initialize serial
}

void loop(){
  // do other stuff here, if needed
}

void motionDetected1() {
  digitalWrite(led1, !state1);   // toggle LED
  state1 = !state1;              // update variable state
  if (state1 == HIGH) {
    Serial.println("Motion 1 detected!"); //Will print on the serial monitor
  } 
  else {
    Serial.println("Motion 1 stopped!");
  }
}
void motionDetected2() {
  digitalWrite(led2, !state2);   // toggle LED
  state2 = !state2;              // update variable state
  if (state2 == HIGH) {
    Serial.println("Motion 2 detected!");   //Will print on the senior monitor
  } 
  else {
    Serial.println("Motion 2 stopped!");
  }
}
