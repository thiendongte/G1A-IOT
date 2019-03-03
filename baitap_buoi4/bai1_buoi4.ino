int i,x;
#define led 3
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  for (i=0;i<255;i++) {
    analogWrite(led,i);
    delay(50);
  }
  for (i=255;i>0;i--) {
    analogWrite(led,i);
    delay(50);
  }
  Serial.println(i);
  }
