int sensorval;
int sensorLow = 1023;
int sensorHigh = 0;

const int LEDpin = 13;
//note: this is th eonboard LED



void setup() {
  // put your setup code here, to run once:
pinMode(LEDpin, OUTPUT);
digitalWrite(LEDpin, HIGH);
//calibrate the sensor
  while(millis() < 5000){
    sensorval = analogRead(A0);
    if(sensorval > sensorHigh){
      sensorHigh = sensorval;
    }
    if(sensorval < sensorLow){
      sensorLow = sensorval;
    }
  }
  digitalWrite(LEDpin, LOW);
}

void loop() {
  // put your main code here, to run repeatedly:
  sensorval = analogRead(A0);
  int pitch = map(sensorval, sensorLow, sensorHigh, 50,1000);
  tone(8,pitch,100);
  delay(10);

}
