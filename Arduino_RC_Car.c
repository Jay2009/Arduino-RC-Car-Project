
/*
#include<Servo.h>
Servo Motor ;
int input1 = 7 ;
int input2 = 4;
int Speed = 250;
int servopin = 10;


void setup()
{
 Serial.begin(9600);
  pinMode(input1, OUTPUT);
  pinMode(input2, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(10, OUTPUT);
  Motor.attach(servopin);
 Motor.write(180);

  Serial.println(" 8 or 2 = for direction, 7 and 9 = booster, 4 = turn left, 6 turn right, anyother key to stop");

}

void loop()
{if (Serial.available () )
{ char Number = Serial.read();
  switch(Number) {
  case '8':
    Serial.print("forward lower \n");
    digitalWrite(input1, HIGH);
    digitalWrite(input2, LOW);
    analogWrite(6,Speed-100);
;
   
    break;
  case '2':
    Serial.print("backward lower\n");
    digitalWrite(input1, LOW);
    digitalWrite(input2, HIGH);
    analogWrite(6,Speed-100);
   
    break;  
  case '7':
    Serial.print("booster \n");
    analogWrite(6,Speed);

    break;
  case '9':
    Serial.print("normal speed \n");
    analogWrite(6,Speed-70);
 
    break;
   case '4':
    Serial.print("turn left \n");
    Motor.write(100);
    delay(50);
    return Motor.write(55);
    break;
   case '6':
    Serial.print("turn right \n");
    Motor.write(-100);
    delay(50);
    return Motor.write(55);
    break;
   case '5':
    Serial.print("stop \n");
    digitalWrite(input1, LOW);
    digitalWrite(input2, LOW);
    break;
  }
  }
} 
*/

#include<SoftwareSerial.h>
#include<Servo.h>
Servo Motor ;
SoftwareSerial jaySerial(2,3); // RX , TX
int Tx= 3;
int Rx= 2;
int input1 = 7 ;
int input2 = 4;
int Speed = 250;
int servopin = 10;
bool mworking = false;
int Speed2 = 0;

void setup()
{

 jaySerial.begin(9600);
  pinMode(input1, OUTPUT);
  pinMode(input2, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(10, OUTPUT);
  Motor.attach(servopin);
  Motor.write(90);
  delay(100);
}

void loop()
{if (jaySerial.available () )
{ char Number = jaySerial.read();
  switch(Number) {
    
  case '8':
  if(!mworking) 
  {
    digitalWrite(input1, HIGH);
    digitalWrite(input2, LOW); 
    mworking=true;
  }
  else if(Speed2!=Speed-120)
  ;
  else
  {
    digitalWrite(input1, LOW);
    digitalWrite(input2, LOW);
    Speed2=0;
    mworking=false;
  }
  
    analogWrite(6,Speed-120);
    Speed2=Speed-120;
    break; 
    
  case '2':
    digitalWrite(input1, LOW);
    digitalWrite(input2, HIGH);
    analogWrite(6,Speed-120);
   
    break;  
  case '7':
    if(!mworking) 
  {
    digitalWrite(input1, HIGH);
    digitalWrite(input2, LOW); 
    mworking=true;
  }else if(Speed2!=Speed-70)
  ;else
  {
    digitalWrite(input1, LOW);
    digitalWrite(input2, LOW);
    Speed2=0;
    mworking=false;
  }
    analogWrite(6,Speed-70);
    Speed2=Speed-70;
    break;
  case '9':
    if(!mworking) 
  {
    digitalWrite(input1, HIGH);
    digitalWrite(input2, LOW); 
    mworking=true;
  }else if(Speed2!=Speed)
  ;else
  {
    digitalWrite(input1, LOW);
    digitalWrite(input2, LOW);
    Speed2=0;
    mworking=false;
  }
    analogWrite(6,Speed);
    Speed2=Speed;
    break;
   case '4':
    Motor.write(180);
   
    break;
    
   case '6':
    Motor.write(0);
    break;
 
   case '5':

    digitalWrite(input1, LOW);
    digitalWrite(input2, LOW);
    break;

    case '1':
    Motor.write(90);
    break;
    default:
    Motor.write(Number);
  }
  }
} 

/*
#include <SoftwareSerial.h>
SoftwareSerial mySerial(2, 3); 

void setup(){
  Serial.begin(9600);
  mySerial.begin(38400);
}

void loop(){
  if (mySerial.available()){
    Serial.write(mySerial.read());
  }
  if (Serial.available()){
    mySerial.write(Serial.read());
  }
}
*/
/*
#include <SoftwareSerial.h>

SoftwareSerial HC05(2,3);

void setup() {
  pinMode(4, OUTPUT);
  digitalWrite, (4, HIGH);
  Serial.begin(9600);
  HC05.begin(38400);

  Serial.println("Bluetooth module setup mode");
  Serial.println("Select [both NL & CR]");
}

void loop()  {

  if (Serial.available()) HC05.write(Serial.read());
  if (HC05.available()) Serial.write(HC05.read());
}
*/
