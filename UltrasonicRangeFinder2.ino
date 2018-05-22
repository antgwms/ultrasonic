#include <LiquidCrystal.h> //because we're using an LCD screen

//to start, define PINs used by the sensor
#define trigPin 4 //define arduino pin to trig
#define echoPin 5 //define arduino pin for echo

//and the PINs used by the LCD
LiquidCrystal lcd(7, 8, 9, 10, 11, 12);

void setup() {
  // setup code here, runs once:
 
  pinMode(trigPin, OUTPUT); //set pin2 assigned to trigPin to OUTPUT communication, because trigPin triggers the pulse
  pinMode(echoPin, INPUT); //set Pin3 assigned to receive echo of pulsh to INPUT 

  lcd.begin(16, 2); //size of lcd screen
  lcd.setCursor(0, 0); //where cursor starts
  lcd.println("Testing, Testing"); //to make sure it works
  
  delay(1000); //wait ... second
  lcd.clear(); //clear the LCD screen at end of set up  
  Serial.begin(9600); //set serial communication and Baud rate
  //delayMicroseconds(1000); //wait an ickle bit
}

void loop() {
  // distance = speed x time. So we need 3 variables, but we know the time it takes for sound to travel. In average humidity (20-50) the speed of sound is 344.02m/s or 3.44cm/s
  //so we only need to assign 2 new variables
  
  long distance, duration;
    //echo duration goes to object and back so we half it; 
  
  digitalWrite(trigPin, LOW); //we make sure the pin is set to OFF
  delayMicroseconds(10); //we'll delay an ickle bit before we switch pin ON  

  digitalWrite(trigPin, HIGH); //we switch the pin ON to trigger a signal
  delayMicroseconds(10); //a pulse must be 10 microseconds
  digitalWrite(trigPin, LOW); //we switch pin10 OFF after the pulse
  //now we need to switch the echo pin ON to receive the pulse back
  duration = pulseIn(echoPin, HIGH); //pulseIn function means pin goes ON to receive the pulse
  distance = ((duration / 2) * 3.44);
  
  if (distance <2 || distance > 400){ //set the range of the sensor
    //lcd.println("Distance = ");
    lcd.println("Out of range//"); //go to a new line after you print 
    delay(500); //a delay before we switch off
  }
  else {
    Serial.begin(9600); //set serial communication and Baud rate
    Serial.print("Distance = "); //if using the serial cable
    Serial.print(distance);
    //lcd.setCursor(0, 0);  //commented for testing
    lcd.print("Distance = ");
    lcd.print(distance);
    lcd.println(" cm ");
    delay(500); //another delay before we switch off
    //delayMicroseconds(500); //another delay before we switch off
    lcd.clear(); //clear the LCD screen at end of loop  
  }
}

