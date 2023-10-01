#include <RN.h>
#include "HUSKYLENS.h"
#include "SoftwareSerial.h"

const int S0 = 3;
const int S1 = 2;
const int S2 = 5;
const int S3 = 6;
const int sensorOut = 7;
RN colorSensor(S0, S1, S2, S3, sensorOut);


RN motor(8, 9, 12); // create a new instance of the RN class


RN sensor(20, 19);
RN sensor_left (18, 17);
RN sensor_right (16, 15);


const int servoPin = 4;
RN servoController(servoPin);
float distance ; 
float distance_left ; 
float distance_right ; 
int cam;
unsigned int redValue;

HUSKYLENS huskylens;
SoftwareSerial mySerial(10, 11); // RX, TX
//HUSKYLENS green line >> Pin 10; blue line >> Pin 11
void printResult(HUSKYLENSResult result);

void setup() {
  // do nothing
   colorSensor.begin();
      servoController.Servobegin();
 servoController.setServoPosition(60); 
   servoController.setServoSpeed(10); 
    unsigned int redValue = colorSensor.getIntensityR();
    motor.setMotorSpeed(180); 
 distance = sensor.getDistance(); 
 distance_left = sensor_left.getDistance(); 
 distance_right = sensor_right.getDistance();
  Serial.begin(9600);
Serial.begin(115200);
    mySerial.begin(9600);
    while (!huskylens.begin(mySerial))
    {
        Serial.println(F("Begin failed!"));
        Serial.println(F("1.Please recheck the \"Protocol Type\" in HUSKYLENS (General Settings>>Protocol Type>>Serial 9600)"));
        Serial.println(F("2.Please recheck the connection."));
        delay(200);
    }

f1();
  delay(10); 
color();
  delay(10); 
 after_coloer();
  delay(10); 
f3();
  
}

void loop() {
 
}





void color(){
 redValue = colorSensor.getIntensityR();

 while (!( redValue > 190 && redValue < 600)){
 redValue = colorSensor.getIntensityR();
distance = sensor.getDistance(); 


 if (distance <= 15){

 motor.stopMotor();
 motor.setMotorDirection(1);
 servoController.setServoPosition(15);  
  motor.setMotorSpeed(180);   
 delay(300);

 }

servoController.setServoPosition(62);
  motor.setMotorDirection(1); // rotate the motor in one direction
  motor.setMotorSpeed(180); // set the motor speed to maximum
  delay(10);


}


servoController.setServoPosition(35);

  motor.setMotorDirection(1); // rotate the motor in one direction
  motor.setMotorSpeed(180); // set the motor speed to maximum
  delay(500); 

 motor.stopMotor(); 
  motor.setMotorDirection(-1); 
  servoController.setServoPosition(90);
  motor.setMotorSpeed(200); // set the motor speed to maximum
  delay(550);

 motor.stopMotor(); 
  motor.setMotorDirection(-1); 
  servoController.setServoPosition(62);
  motor.setMotorSpeed(180); // set the motor speed to maximum
  delay(500);
}

void f1(){
 while (!( distance <= 110)){
  



 servoController.setServoPosition(62);

distance = sensor.getDistance(); 
 
  motor.setMotorDirection(1); // rotate the motor in one direction
  motor.setMotorSpeed(180); // set the motor speed to maximum
  delay(10); // wait for one second
distance = sensor.getDistance(); 


}}


void after_coloer(){
   redValue = colorSensor.getIntensityR();

 while (!( redValue > 190 && redValue < 600)){
  redValue = colorSensor.getIntensityR();

 if (!huskylens.request()) Serial.println(F("Fail to request data from HUSKYLENS, recheck the connection!"));
    else if(!huskylens.isLearned()) Serial.println(F("Nothing learned, press learn button on HUSKYLENS to learn one!"));
    else if(!huskylens.available()) {
      Serial.println(F("No block or arrow appears on the screen!"));
      cam = 0;
  servoController.setServoPosition(57); 
  motor.setMotorDirection(1); // rotate the motor in one direction
  motor.setMotorSpeed(180); // set the motor speed to maximum
  delay(10); 
    
    }
    
    else
    {
       
        while (huskylens.available())
        {

            HUSKYLENSResult result = huskylens.read();
            cam = result.ID;
            if (cam == 2){
       motor.stopMotor();
   
 motor.setMotorDirection(1);
 servoController.setServoPosition(90);  
  motor.setMotorSpeed(200);   
distance = sensor.getDistance();
distance_right = sensor_right.getDistance();
  delay(600); 

      delay(100); 
motor.setMotorDirection(1);
     motor.setMotorSpeed(200);
     servoController.setServoPosition(15);  
      delay(200); 
      motor.setMotorDirection(1);
     motor.setMotorSpeed(180);
     servoController.setServoPosition(63);  
      delay(100); 
            }
else {}
 
    }}
    
    redValue = colorSensor.getIntensityR();
     } 


}

void f3(){
 motor.stopMotor(); // stop the motor

  delay(1000);
}