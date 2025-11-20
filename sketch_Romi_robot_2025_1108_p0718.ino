// Program: Robot initially off
// Pressing bumper switch BMP0 through BMP5 causes robot to backup and spin.
// Use reset to stop robot (program starts over)
// Note: pin 13 used for directionPinB and also built-in LED LED_BUILTIN

// Pins for Channel A connected to left motor (looking from rear of robot)
int directionPinA = 12;
int pwmPinA = 3;
int brakePinA = 9;

//Pins for Channel B connected to right motor (looking from rear of robot)
int directionPinB = 13;
int pwmPinB = 11;
int brakePinB = 8;

//Pins for right Bumper switches (looking from rear of robot)
int BMP0 = 5;
int BMP1 = 4;
int BMP2 = 2;

//Pins for left Bumper switches (looking from rear of robot)
int BMP3 = 6;
int BMP4 = 7;
int BMP5 = 10;

void setup() {
  
  //define pins
  pinMode(directionPinA, OUTPUT);
  pinMode(pwmPinA, OUTPUT);
  pinMode(brakePinA, OUTPUT);

  pinMode(directionPinB, OUTPUT);
  pinMode(pwmPinB, OUTPUT);
  pinMode(brakePinB, OUTPUT);

  // Bumper switches HIGH when open and LOW when closed. INPUT_PULLUP enables pull-up resistor in microcontroller

  pinMode(BMP0, INPUT_PULLUP);
  pinMode(BMP1, INPUT_PULLUP);
  pinMode(BMP2, INPUT_PULLUP);  
  pinMode(BMP3, INPUT_PULLUP);
  pinMode(BMP4, INPUT_PULLUP);
  pinMode(BMP5, INPUT_PULLUP);

  //Write a high state to the direction pins so ready to move forward (Romi wired so bumper switches in front)
  digitalWrite(directionPinA, HIGH);
  digitalWrite(directionPinB, HIGH);
  
  //Activate brakes
  digitalWrite(brakePinA, HIGH);
  digitalWrite(brakePinB, HIGH);

  //Set duty cycle for the motors to 0 (motors not turning) (duty cycle has range 0 to 255)
  analogWrite(pwmPinA, 0);
  analogWrite(pwmPinB, 0);

}

void loop() {

    //digitalWrite(LED_BUILTIN, LOW);   // turn the LED off by making the voltage LOW. Conflicts with pin 13 being used for direction?

  //if robots hits something on left side, BMP3 BMP4, or BMP5 will be closed:

  if((digitalRead(BMP0)==LOW)||(digitalRead(BMP1)==LOW)||(digitalRead(BMP2)==LOW)||(digitalRead(BMP3)==LOW)||(digitalRead(BMP4)==LOW)||(digitalRead(BMP5)==LOW))
  {
    //STOP

    //activate brakes
    digitalWrite(brakePinA, HIGH);
    digitalWrite(brakePinB, HIGH);

    //set work duty for the motor to 0 (motors not turning) (duty cycle has range 0 to 255)
    analogWrite(pwmPinA, 0);
    analogWrite(pwmPinB, 0);

    delay(1000); //Delay in milliseconds (ms). 1000 ms = 1 second

    //REVERSE

    //write a low state to the direction pins
    digitalWrite(directionPinA, LOW);
    digitalWrite(directionPinB, LOW);

    //release brakes
    digitalWrite(brakePinA, LOW);
    digitalWrite(brakePinB, LOW);

    //set duty cycle for the motor
    analogWrite(pwmPinA, 50);
    analogWrite(pwmPinB, 50);

    delay(500); //Delay in milliseconds (ms). 1000 ms = 1 second

    //STOP

    //activate brakes
    digitalWrite(brakePinA, HIGH);
    digitalWrite(brakePinB, HIGH);

    //set duty cycle for the motor to 0 (motors not turning) (duty cycle has range 0 to 255)
    analogWrite(pwmPinA, 0);
    analogWrite(pwmPinB, 0);

    delay(1000); //Delay in milliseconds (ms). 1000 ms = 1 second

    //SPIN CLOCKWISE

    //write a low to direction pin for right motor (reverse) and a high to direction pin for left motor (forward)
    digitalWrite(directionPinA, HIGH);
    digitalWrite(directionPinB, LOW);

    //release brakes
    digitalWrite(brakePinA, LOW);
    digitalWrite(brakePinB, LOW);

    //set duty cycle of 50 for the motor (duty cycle has range 0 to 255)
    analogWrite(pwmPinA, 50);
    analogWrite(pwmPinB, 50);

    delay(660); //Adjusted this experimentally

    //STOP

    //activate brakes
    digitalWrite(brakePinA, HIGH);
    digitalWrite(brakePinB, HIGH);

    //Set duty cycle for the motor to 0 (duty cycle has range 0 to 255)
    analogWrite(pwmPinA, 0);
    analogWrite(pwmPinB, 0);

    delay(1000); //Delay in milliseconds (ms). 1000 ms = 1 second

    //FORWARD

    //Set direction pins high to go forward
    digitalWrite(directionPinA, HIGH);
    digitalWrite(directionPinB, HIGH);
    //}

    //release brakes
    digitalWrite(brakePinA, LOW);
    digitalWrite(brakePinB, LOW);

    //set duty cycle to 50 for the motor (duty cycle has range 0 to 255)
    analogWrite(pwmPinA, 50);
    analogWrite(pwmPinB, 50);
  }

 }

