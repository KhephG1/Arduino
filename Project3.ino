const int greenLED = 11;
const int redLED  = 9;
const int blueLED=10;
const int redSensor = A2;
const int greenSensor = A1;
const int blueSensor = A0;

int redval, blueval, greenval = 0;

int redSensorval,greenSensorval, blueSensorval = 0;

nhhhhh
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(greenLED,OUTPUT);
  pinMode(blueLED, OUTPUT);
  pinMode(greenLED,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  redSensorval = analogRead(redSensor);
  delay(1);
  blueSensorval = analogRead(blueSensor);
  delay(1);
  greenSensorval = analogRead(greenSensor);
  delay(1);

  Serial.print("Raw Sensor values \t red:");
  Serial.print(redSensorval);
  Serial.print("\t green: ");
  Serial.print(greenSensorval);
  Serial.print("\t blue");
  Serial.println(blueSensorval);

  redval = redSensorval /  4;
  greenval = greenSensorval/4;
  blueval = blueSensorval / 4;
  Serial.print("\t Mapped Sensor values: \t red: ");
  Serial.print(redval);
  Serial.print("\t green: ");
  Serial.print(greenval);
  Serial.print("\t blue");
  Serial.print(blueval);

  analogWrite(redLED, redval);
  analogWrite(greenLED, greenval);
  analogWrite(blueLED, blueval);
}
