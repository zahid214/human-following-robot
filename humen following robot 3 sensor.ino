//Arduino Human Following Robot
//include the library code:
#include<NewPing.h>           
#include<Servo.h>             
#include<AFMotor.h>           

#define TRIGGER_PIN1 A0        // Trigger pin connected to analog pin A1 of Arduino Uno:
#define ECHO_PIN1 A1           // Echo pin connected to analog pin A0 of Arduino Uno:
#define TRIGGER_PIN2 A2        // Trigger pin connected to analog pin A1 of Arduino Uno:
#define ECHO_PIN2 A3           // Echo pin connected to analog pin A0 of Arduino Uno:
#define TRIGGER_PIN3 A4        // Trigger pin connected to analog pin A1 of Arduino Uno:
#define ECHO_PIN3 A5           // Echo pin connected to analog pin A0 of Arduino Uno:
#define MAX_DISTANCE 200      // Maximum ping distance:

unsigned int distance1 = 0;    //Variable to store ultrasonic sensor distance:
unsigned int distance2 = 0; //Variable to store Right IR sensor value:
unsigned int distance3 = 0;  //Variable to store Left IR sensor value:
unsigned int motorspeed = 130; //Variable to store motor speed value:  

NewPing sonar1(TRIGGER_PIN1, ECHO_PIN1, MAX_DISTANCE);  //NewPing setup of pins and maximum distance:
NewPing sonar2(TRIGGER_PIN2, ECHO_PIN2, MAX_DISTANCE);  //NewPing setup of pins and maximum distance:
NewPing sonar3(TRIGGER_PIN3, ECHO_PIN3, MAX_DISTANCE);  //NewPing setup of pins and maximum distance:

//create motor objects
AF_DCMotor Motor1(1,MOTOR12_1KHZ);
AF_DCMotor Motor2(2,MOTOR12_1KHZ);
AF_DCMotor Motor3(3,MOTOR34_1KHZ);
AF_DCMotor Motor4(4,MOTOR34_1KHZ);

 Servo myservo; //create servo object to control the servo:
 int pos=0;     //variable to store the servo position:

void setup() { // the setup function runs only once when power on the board or reset the board:
  
   Serial.begin(9600); //initailize serial communication at 9600 bits per second:
   myservo.attach(10); // servo attached to pin 10 of Arduino UNO
{
for(pos = 90; pos <= 180; pos += 1){    // goes from 90 degrees to 180 degrees:
  myservo.write(pos);                   //tell servo to move according to the value of 'pos' variable:
  delay(15);                            //wait 15ms for the servo to reach the position:
  } 
for(pos = 180; pos >= 0; pos-= 1) {     // goes from 180 degrees to 0 degrees:
  myservo.write(pos);                   //tell servo to move according to the value of 'pos' variable:
  delay(15);                            //wait 15ms for the servo to reach the position:
  }
for(pos = 0; pos<=90; pos += 1) {       //goes from 180 degrees to 0 degrees:
  myservo.write(pos);                   //tell servo to move according to the value of 'pos' variable:
  delay(15);                            //wait 15ms for the servo to reach the position:
  }
}
}

// the lope function runs forever
void loop() {                               
delay(50);                                        //wait 50ms between pings:
distance1 = sonar1.ping_cm();                       //send ping, get distance in cm and store it in 'distance' variable:
Serial.print("distance1");                   
Serial.println(distance1);                         // print the distance in serial monitor:
distance2 = sonar2.ping_cm();                       //send ping, get distance in cm and store it in 'distance' variable:
Serial.print("distance2");                   
Serial.println(distance2);                         // print the distance in serial monitor:
distance3 = sonar3.ping_cm();                       //send ping, get distance in cm and store it in 'distance' variable:
Serial.print("distance3");                   
Serial.println(distance3);                         // print the distance in serial monitor:
if(distance2<100 & distance2>25)
{
  TLeft();
}
else if(distance1<35 & distance1>20)
{
  MBack();
}
else if(distance1<100 & distance1>40)
{
  MForward();
}
else if(distance3<100 & distance3>25)
{
  TRight();
}
else
{
  Stop();
}
}
  void MForward(){
  Motor1.setSpeed(motorspeed);  //define motor1 speed:
  Motor1.run(FORWARD);          //rotate motor1 clockwise:
  Motor2.setSpeed(motorspeed);  //define motor2 speed:
  Motor2.run(FORWARD);          //rotate motor2 clockwise:
  Motor3.setSpeed(motorspeed);  //define motor3 speed:
  Motor3.run(FORWARD);          //rotate motor3 clockwise:
  Motor4.setSpeed(motorspeed);  //define motor4 speed:
  Motor4.run(FORWARD);          //rotate motor4 clockwise:
  }
  void MBack(){
  Motor1.setSpeed(motorspeed);   //define motor1 speed:
  Motor1.run(BACKWARD);          //rotate motor1 clockwise:
  Motor2.setSpeed(motorspeed);   //define motor2 speed:
  Motor2.run(BACKWARD);          //rotate motor2 clockwise:
  Motor3.setSpeed(motorspeed);   //define motor3 speed:
  Motor3.run(BACKWARD);          //rotate motor3 clockwise:
  Motor4.setSpeed(motorspeed);   //define motor4 speed:
  Motor4.run(BACKWARD);          //rotate motor4 clockwise:
  }  
  void TLeft(){                                                
  Motor1.setSpeed(motorspeed);  //define motor1 speed:
  Motor1.run(FORWARD);          //rotate motor1 cloclwise:
  Motor2.setSpeed(motorspeed);  //define motor2 speed:
  Motor2.run(FORWARD);          //rotate motor2 clockwise:
  Motor3.setSpeed(motorspeed);  //define motor3 speed:
  Motor3.run(BACKWARD);         //rotate motor3 anticlockwise:
  Motor4.setSpeed(motorspeed);  //define motor4 speed:
  Motor4.run(BACKWARD);         //rotate motor4 anticlockwise:
  delay(150); 
  }
  void TRight(){
  Motor1.setSpeed(motorspeed);  //define motor1 speed:
  Motor1.run(BACKWARD);         //rotate motor1 anticlockwise:
  Motor2.setSpeed(motorspeed);  //define motor2 speed:
  Motor2.run(BACKWARD);         //rotate motor2 anticlockwise:
  Motor3.setSpeed(motorspeed);  //define motor3 speed:
  Motor3.run(FORWARD);          //rotate motor3 clockwise:
  Motor4.setSpeed(motorspeed);  //define motor4 speed:
  Motor4.run(FORWARD);          //rotate motor4 clockwise:
  delay(150);
  }
  void Stop(){
  Motor1.setSpeed(0);    //define motor1 speed:
  Motor1.run(RELEASE);   //stop motor1:
  Motor2.setSpeed(0);    //define motor2 speed:
  Motor2.run(RELEASE);   //stop motor2:
  Motor3.setSpeed(0);    //define motor3 speed:
  Motor3.run(RELEASE);   //stop motor3:
  Motor4.setSpeed(0);    //define motor4 speed:
  Motor4.run(RELEASE);   //stop motor4:
  delay(150);  
  }  
