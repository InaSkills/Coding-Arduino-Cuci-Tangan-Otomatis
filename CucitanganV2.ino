#include <NewPing.h>

#define motor 4
#define TRIGGER_PIN 3
#define ECHO_PIN 2
#define MAX_DISTANCE 50
#define motorOn digitalWrite(motor, 0)
#define motorOff digitalWrite(motor, 1)
int kondisiMotor=0;

// NewPing setup of pins and maximum distance
NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE); 
 
void setup() {
  pinMode(motor,OUTPUT);
  Serial.begin(9600);
  Serial.println("Start");
}
 
void loop() {
   delay(50);
   unsigned int distance = sonar.ping_cm();
   Serial.print(distance);
   Serial.print("cm");
   Serial.println(kondisiMotor);

   if (distance>=3 && distance <=19){
    motorOn;
    kondisiMotor=1;
    Serial.print(distance);
    Serial.print("cm");
    Serial.println(kondisiMotor);
    delay(1500);
   }

    if (distance>19 || distance==0){
    motorOff;
    kondisiMotor=0;
   
    Serial.print(distance);
    Serial.print("cm");
    Serial.println(kondisiMotor);
   }
   
}
