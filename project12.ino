#include <Servo.h>

Servo myservo;

const int piezo = A0;

const int switchpin = 2;

const int yellowled = 3;

const int greenled = 4;

const int redled = 5;

int knockval;

int switchval;

int quietknock = 10;

int loudknock = 100;

bool locked = false;

int numberofknocks = 0;
void setup() {
  // put your setup code here, to run once:
  myservo.attach(9);
  pinMode(yellowled,OUTPUT);
  pinMode(redled,OUTPUT);
  pinMode(greenled,OUTPUT);
  pinMode(switchpin,INPUT);

  Serial.begin(9600);

  digitalWrite(greenled,HIGH);
  myservo.write(0);

  Serial.println("box unlocked");
}


void loop() {
  // put your main code here, to run repeatedly:
  if(locked ==false){
    switchval = digitalRead(switchpin);
  
    if(switchval ==HIGH){
      locked =true;
      digitalWrite(greenled,LOW);
      digitalWrite(redled,HIGH);
      myservo.write(90);
      Serial.println("box is locked");
      delay(1000);
    }
  
  }

  if(locked ==true){
    knockval = analogRead(piezo);
    if(numberofknocks<3 && knockval>0){
      if(checkforknock(knockval)){
        numberofknocks++;
      }
      Serial.println(3-numberofknocks);
      Serial.println(" more knocks to go");
    }

    if(numberofknocks>=3){
      locked = false;
      myservo.write(0);
      delay(20);
      digitalWrite(greenled,HIGH);
      digitalWrite(redled,LOW);
      Serial.println("box is unlocked");
      numberofknocks = 0;
    }
  }
}

bool checkforknock(int value){
  if(value > quietknock && value < loudknock){
    digitalWrite(yellowled,HIGH);
    delay(50);
    digitalWrite(yellowled,LOW);
    Serial.println("valid knock of value: ");
    Serial.println(value);
    return true;
  }else{
    Serial.print("bad knock value ");
    Serial.println(value);
    return false;
  }
}
