const int controlpin1 = 2;

const int controlpin2 = 3;

const int enablepin = 9;

const int directionswitchpin = 4;

const int onoffswitchstatepin = 5;

const int potpin = A0;
int onoffswitchstate = 0;
int previousonoffswitchstate = 0;
int directionswitchstate = 0;
int previousdirectionswitchstate = 0;

int motorenabled = 0;

int motorspeed = 0;

int motordirection = 1;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(directionswitchpin, INPUT);
  pinMode(onoffswitchstatepin, INPUT);
  pinMode(controlpin1, OUTPUT);
  pinMode(controlpin2, OUTPUT);
  pinMode(enablepin, OUTPUT);

  digitalWrite(enablepin, LOW);
}

void loop() {
  // put your main code here, to run repeatedly:
  onoffswitchstate = digitalRead(onoffswitchstatepin);

  delay(1);

  directionswitchstate = digitalRead(directionswitchpin);

  motorspeed = analogRead(potpin) / 4;

  if (onoffswitchstate != previousonoffswitchstate) {
    if (onoffswitchstate == HIGH) {
      motorenabled = !motorenabled;
    }
  }
  if (directionswitchstate != previousdirectionswitchstate) {
    if (directionswitchstate == HIGH) {
      motordirection = !motordirection;
    }
  }
  if (motordirection == 1) {
    digitalWrite(controlpin1, HIGH);
    digitalWrite(controlpin2, LOW);
  } else {
    digitalWrite(controlpin1, LOW);
    digitalWrite(controlpin2, HIGH);
  }

  if (motorenabled == 1) {
    analogWrite(enablepin, motorspeed);

  } else {
    analogWrite(enablepin, 0);
  }

  previousdirectionswitchstate = directionswitchstate;

  previousonoffswitchstate = onoffswitchstate;
  Serial.println(motordirection);
}
