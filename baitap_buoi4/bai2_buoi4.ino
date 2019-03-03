#define led1 3
#define led2 5
#define led3 6
#define nut1 7
#define nut2 8
int i;
int a;
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  a=0;
  if (digitalRead(nut1)==HIGH) {
    for (i=0;i<255;i++) {
      analogWrite(led1,i);
      analogWrite(led2,i);
      analogWrite(led3,i);
      delay(25);
    }
    for (i=255;i>=0;i--) {
      analogWrite(led1,i);
      analogWrite(led2,i);
      analogWrite(led3,i);
      delay(25);
    }
  }
    if (digitalRead(nut2)==HIGH) {
      for (i=0;i<255;i++) {
      analogWrite(led1,i);
      delay(25);
    }
     for (i=0;i<255;i++) {
      analogWrite(led2,i);
      delay(25);
    }
     for (i=0;i<255;i++) {
      analogWrite(led3,i);
      delay(25);
    }
    digitalWrite(led1,LOW);
    delay(500);
    digitalWrite(led2,LOW);
    delay(500);
    digitalWrite(led3,LOW);
    }
}
