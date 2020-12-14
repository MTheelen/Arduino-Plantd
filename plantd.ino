// Sensor pins
#define sensorPower 7
#define sensorPin A0
#define redPin 8
#define orangePin 9
#define greenPin 10

void setup() {
  //Initialize ports
  pinMode(sensorPower, OUTPUT);
  pinMode(redPin, OUTPUT);
  pinMode(orangePin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  
  //set all LEDs off
  digitalWrite(redPin, LOW);
  digitalWrite(orangePin, LOW);
  digitalWrite(greenPin, LOW);
  
  // Initially keep the sensor OFF
  digitalWrite(sensorPower, LOW);
  
  Serial.begin(9600);
}

void loop() {
  //get the reading from the function below and print it
  int wetness = readSensor();
  Serial.print("Analog output: ");
  Serial.println(wetness);

  if(wetness <= 340){
    digitalWrite(greenPin, HIGH);
  }else if(wetness > 340 && wetness < 680){
    digitalWrite(orangePin, HIGH);
  }else{
    digitalWrite(redPin, HIGH);
  }

  
  delay(1000);

  //reset LEDs
  digitalWrite(redPin, LOW);
  digitalWrite(orangePin, LOW);
  digitalWrite(greenPin, LOW);
}

//  This function returns the analog soil moisture measurement
int readSensor() {
  digitalWrite(sensorPower, HIGH);  // Turn the sensor ON
  delay(10);              // Allow power to settle
  int val = analogRead(sensorPin);  // Read the analog value form sensor
  digitalWrite(sensorPower, LOW);   // Turn the sensor OFF
  return val;             // Return analog moisture value
  
}
