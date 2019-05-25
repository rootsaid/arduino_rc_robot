//Receiver
//Demo - https://youtu.be/g2GTyx-DxdI
//visit www.rootsaid.com for full tutorial
//For Video Demo and tutorials Visit www.youtube.com/c/rootsaid

#include <SoftwareSerial.h>
#include <Wire.h>

#define MOTOR_A1_PIN 13
#define MOTOR_B1_PIN 12
#define PWM_MOTOR_1 3

#define MOTOR_A2_PIN 8
#define MOTOR_B2_PIN 7
#define PWM_MOTOR_2 5
              
SoftwareSerial HC12(10, 11);

int lr,x,y;
int bf, motor1_speed, motor2_speed;
int mode;
String input;
int boundLow;
int boundHigh;
const char delimiter = ',';

void setup() {

pinMode(MOTOR_A1_PIN, OUTPUT);
pinMode(MOTOR_B1_PIN, OUTPUT);
pinMode(PWM_MOTOR_1, OUTPUT);
pinMode(MOTOR_A2_PIN, OUTPUT);
pinMode(MOTOR_B2_PIN, OUTPUT);
pinMode(PWM_MOTOR_1, OUTPUT);
    
Serial.begin(9600);
HC12.begin(9600);

pinMode (2, OUTPUT);
pinMode (3, OUTPUT);
pinMode (4, OUTPUT);
pinMode (5, OUTPUT);
pinMode (6, OUTPUT);
pinMode (7, OUTPUT);
}

void loop() {

  if(HC12.available())
  {
  input = HC12.readStringUntil('\n');
  if (input.length() > 0)
      {
        Serial.println(input);
       
       boundLow = input.indexOf(delimiter);
        x = input.substring(0, boundLow).toInt();
    
        boundHigh = input.indexOf(delimiter, boundLow+1);
        y = input.substring(boundLow+1, boundHigh).toInt();
    
        boundLow = input.indexOf(delimiter, boundHigh+1);
        bf = input.substring(boundHigh+1, boundLow).toInt();

        boundHigh = input.indexOf(delimiter, boundLow+1);
        lr = input.substring(boundLow+1, boundHigh).toInt();
    
        mode = input.substring(boundHigh+1).toInt();
  
delay(10);   
}
//Robot Movement
low_speed(); //Comment this line and uncomment the next line for high speed
//high_speed(); 
}
}

void forward()
{
motor1_speed=100;
motor2_speed=100;
analogWrite(PWM_MOTOR_1, motor1_speed);
analogWrite(PWM_MOTOR_2, motor2_speed);
digitalWrite(MOTOR_A1_PIN, HIGH); 
digitalWrite(MOTOR_B1_PIN, LOW);
digitalWrite(MOTOR_A2_PIN, HIGH); 
digitalWrite(MOTOR_B2_PIN, LOW);
Serial.println("Moving Forward");
}

void backward()
{
motor1_speed=100;
motor2_speed=100;
analogWrite(PWM_MOTOR_1, motor1_speed);
analogWrite(PWM_MOTOR_2, motor2_speed);
digitalWrite(MOTOR_A1_PIN, LOW); 
digitalWrite(MOTOR_B1_PIN, HIGH);
digitalWrite(MOTOR_A2_PIN, LOW); 
digitalWrite(MOTOR_B2_PIN, HIGH);
Serial.println("Moving Forward");
}

void fforward()
{
motor1_speed=255;
motor2_speed=255;
analogWrite(PWM_MOTOR_1, motor1_speed);
analogWrite(PWM_MOTOR_2, motor2_speed);
digitalWrite(MOTOR_A1_PIN, HIGH); 
digitalWrite(MOTOR_B1_PIN, LOW);
digitalWrite(MOTOR_A2_PIN, HIGH); 
digitalWrite(MOTOR_B2_PIN, LOW);
Serial.println("Moving Forward");
}

void fbackward()
{
motor1_speed=255;
motor2_speed=255;
analogWrite(PWM_MOTOR_1, motor1_speed);
analogWrite(PWM_MOTOR_2, motor2_speed);
digitalWrite(MOTOR_A1_PIN, LOW); 
digitalWrite(MOTOR_B1_PIN, HIGH);
digitalWrite(MOTOR_A2_PIN, LOW); 
digitalWrite(MOTOR_B2_PIN, HIGH);
Serial.println("Moving Backward");
}

void stop()
{
motor1_speed=0;
motor2_speed=0;
analogWrite(PWM_MOTOR_1, motor1_speed);
analogWrite(PWM_MOTOR_2, motor2_speed);
digitalWrite(MOTOR_A1_PIN, LOW); 
digitalWrite(MOTOR_B1_PIN, LOW);
digitalWrite(MOTOR_A2_PIN, LOW); 
digitalWrite(MOTOR_B2_PIN, LOW);
Serial.println("Stop");
}

void ffrontright()
{
motor1_speed=255;
motor2_speed=50;
analogWrite(PWM_MOTOR_1, motor1_speed);
analogWrite(PWM_MOTOR_2, motor2_speed);
digitalWrite(MOTOR_A1_PIN, HIGH); 
digitalWrite(MOTOR_B1_PIN, LOW);
digitalWrite(MOTOR_A2_PIN, HIGH); 
digitalWrite(MOTOR_B2_PIN, HIGH);
Serial.println("Front Right");
}

void ffrontleft()
{
motor1_speed=50;
motor2_speed=255;
analogWrite(PWM_MOTOR_1, motor1_speed);
analogWrite(PWM_MOTOR_2, motor2_speed);
digitalWrite(MOTOR_A1_PIN, HIGH); 
digitalWrite(MOTOR_B1_PIN, HIGH);
digitalWrite(MOTOR_A2_PIN, HIGH); 
digitalWrite(MOTOR_B2_PIN, LOW);
Serial.println("Front Left");
}

void frontright()
{
motor1_speed=150;
motor2_speed=50;
analogWrite(PWM_MOTOR_1, motor1_speed);
analogWrite(PWM_MOTOR_2, motor2_speed);
digitalWrite(MOTOR_A1_PIN, HIGH); 
digitalWrite(MOTOR_B1_PIN, LOW);
digitalWrite(MOTOR_A2_PIN, HIGH); 
digitalWrite(MOTOR_B2_PIN, HIGH);
Serial.println("Front Right");
}

void frontleft()
{
motor1_speed=50;
motor2_speed=150;
analogWrite(PWM_MOTOR_1, motor1_speed);
analogWrite(PWM_MOTOR_2, motor2_speed);
digitalWrite(MOTOR_A1_PIN, HIGH); 
digitalWrite(MOTOR_B1_PIN, HIGH);
digitalWrite(MOTOR_A2_PIN, HIGH); 
digitalWrite(MOTOR_B2_PIN, LOW);
Serial.println("Front Left");
}

void left()
{
motor1_speed=100;
motor2_speed=100;
analogWrite(PWM_MOTOR_1, motor1_speed);
analogWrite(PWM_MOTOR_2, motor2_speed);
digitalWrite(MOTOR_A1_PIN, HIGH); 
digitalWrite(MOTOR_B1_PIN, LOW);
digitalWrite(MOTOR_A2_PIN, LOW); 
digitalWrite(MOTOR_B2_PIN, HIGH);
Serial.println("Moving Left");
}


void right()
{
motor1_speed=100;
motor2_speed=100;
analogWrite(PWM_MOTOR_1, motor1_speed);
analogWrite(PWM_MOTOR_2, motor2_speed);
digitalWrite(MOTOR_A1_PIN, LOW); 
digitalWrite(MOTOR_B1_PIN, HIGH);
digitalWrite(MOTOR_A2_PIN, HIGH); 
digitalWrite(MOTOR_B2_PIN, LOW);
Serial.println("Moving Right");
}


void low_speed()
{
 
  if ((bf <= 100) && (lr > 100) && (lr < 700))
{
backward();
}
 
else if ((bf >= 700) && (lr > 100) && (lr < 700))
{
forward();
}

else if ((lr <= 100) && (bf > 100) && (bf < 700))
{
right();
}
 
else if ((lr >= 700) && (bf > 100) && (bf < 700))
{
left();
}

else if ((lr <= 100) && (bf >= 700))
{
frontleft();
}
 
else if ((lr >= 700) && (bf >= 700))
{
frontright();
}
 
}



void high_speed()
{
 
if ((bf <= 100) && (lr > 100) && (lr < 700))
{
fbackward();
}
 
else if ((bf >= 700) && (lr > 100) && (lr < 700))
{
fforward();
}


else if ((lr <= 100) && (bf > 100) && (bf < 700))
{
right();
}
 
else if ((lr >= 700) && (bf > 100) && (bf < 700))
{
left();
}


else if ((lr <= 100) && (bf >= 700))
{
ffrontleft();
}
 
else if ((lr >= 700) && (bf >= 700))
{
ffrontright();
}
 
else
{
stop();
}
}

