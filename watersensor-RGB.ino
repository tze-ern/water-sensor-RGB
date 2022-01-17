// Sensor pins
#define sensorPower 7
#define sensorPin A0

// Value for storing water level
int val = 0;
int r = val/2;
int g = 1/r;

void setup() {
  // Set D7 as an OUTPUT
  pinMode(sensorPower, OUTPUT);
  
  // Set to LOW so no power flows through the sensor
  digitalWrite(sensorPower, LOW);

  // Set 11, 10 ,9 as RGB
  pinMode(11, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(9, OUTPUT);
  
  Serial.begin(9600);
}

//This is a function used to get the reading
int readSensor() {
  digitalWrite(sensorPower, HIGH);  // Turn the sensor ON
  delay(10);              // wait 10 milliseconds
  val = analogRead(sensorPin);    // Read the analog value form sensor
  digitalWrite(sensorPower, LOW);   // Turn the sensor OFF
  return val;             // send current reading
}

//This is a function that makes the RGB change its color
void rgbcolor() {
  digitalWrite(11, r);
  digitalWrite(10, g);
  digitalWrite(9, LOW);
}

void loop() {
  //get the reading from the function below and print it
  int level = readSensor();
  
  Serial.print("Water level: ");
  Serial.println(level);
  
  delay(1000);
  
  rgbcolor();
}



