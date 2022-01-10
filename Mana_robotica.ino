#include <Servo.h>

Servo servouri[5];  //creare multime servouri
int butoane[5] = {2, 3, 4, 7, 12};
int stare_but[5];

int pin_servo[5] = {5, 6, 9, 10, 11}; //pinii pe care trebuie conectati servourile

void setup() {
  Serial.begin(9600);
  for (int i = 0; i < 5; i++)   servouri[i].attach(pin_servo[i]); //setare pini drept control servo
  for (int i = 0; i < 5; i++)   pinMode(butoane[i], INPUT_PULLUP); //setare pini ca input
}
void loop() {
  int citire[5];
  for(int i = 0 ; i < 5 ; i ++){
    citire[i]=digitalRead(butoane[i]); 
    stare_but[i]= (stare_but[i]!=citire[i])? HIGH : LOW ; //scheme dubioase, daca conditia e adevarata alege HIGH, altfel pune low;
    Serial.print(citire[i]),Serial.print(' ');
  }
  Serial.println();
  delay(100);

}
