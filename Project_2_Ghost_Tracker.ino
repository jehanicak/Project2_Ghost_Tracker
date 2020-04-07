#include <analogWrite.h>

// ----------------- FOR MY RGB -----------------------

// this is where my RGB LED is attached to on my board
int red = 12;
int green = 27;
int blue = 33;

// ----------------- FOR MY WHITE LIGHT ----------------
int white = 15;

// ----------------- FOR MY INTERACTIONS ---------------
//the BUTTON to communicate with spirits
int PressedButton = A1;

//the SENSOR to communicate with spirits
int SensorButton = A0;


//a counter for how many clicks you have done
int counter = 0;

int lastButtonState = 0;

// ------------------ FOR MY GHOST STRING ARRAY ---------

char *ghostNames[] = { "Andy Jimenez", "Teresa Blake",  "Lester Hines", "Rebecca Brown",
                       "Tanya Chapman", "Bessie Jefferson", "Rex Hughes", "Rene Myers", 
                       "Danny Alvarez", "Wesley Joseph","Bernard Bridges", "Muriel Goodwin", 
                       "Doyle Kennedy", "Angel Holt", "Douglas Harvey", "Toni Leonard", 
                       "Jordan Moore", "Santos Mack", "Sean Farmer","Casey Mcdaniel", 
                       "Joseph Fleming", "Tricia Valdez","Leonard Gonzales","Jody Hampton", 
                       "Ollie Howell"};

                   
// ------------------ FOR MY GHOST MOOD STRING ARRAY ------


char *Mood[] = { "Angry", "Upset",  "Happy", "Bashful", "Sad", "jealous", "Mischievous", 
                 "Vengeful", "Content", "Excited", "Confused"};


// ------------------ FOR MY GHOST RESPONCE STRING ARRAY ------

char *Responce[] = { "Food", "Lawn Mower", "I dont Understand", "Stop", "GET OUT", 
                     "please leave", "Never", "Yes", "Everywhere", "You", "Wait"};


void setup() {

Serial.begin(9600);

//declaring everything that I have being used or effected
pinMode(red, OUTPUT);
pinMode(green, OUTPUT);
pinMode(blue, OUTPUT);
pinMode(white, OUTPUT);

pinMode(PressedButton, INPUT);
pinMode(SensorButton, INPUT);
}

void loop() {

int sensorValue = analogRead(SensorButton);

int buttonState = digitalRead(PressedButton);

sensorValue = constrain(sensorValue, 500, 3700);

////to test my sensor
//Serial.println(sensorValue);
//delay(1); 

//------------ SENSOR PART -------------------

if(sensorValue > 3000){
  digitalWrite(red, LOW); 
  digitalWrite(blue, LOW);
  digitalWrite(green, LOW);
  
}

 else if(sensorValue > 1000 && sensorValue < 2500 ) {
    //this makes the button blink constantly
    digitalWrite(red, HIGH); 
    digitalWrite(blue, LOW);
    digitalWrite(green, LOW);
    delay(200);                       
    digitalWrite(red, LOW); 
    digitalWrite(blue, LOW);
    digitalWrite(green, LOW);   
    delay(200);      
   }
   
   else if(sensorValue >= 500 && sensorValue < 1000){
    //this turns the button off
     digitalWrite(green, HIGH);
     digitalWrite(red, LOW);
     digitalWrite(blue, LOW);
     
    } else{
     digitalWrite(green, LOW);
     digitalWrite(red, LOW);
     digitalWrite(blue, LOW);
      
    }

//------------ BUTTON PART -------------------

if(buttonState != lastButtonState){

  //starting the code / counting upon presses
  if(buttonState == HIGH){
    counter++;
    delay(100);
   }

   else if(counter == 1){
    digitalWrite(white, HIGH);

    //Pick a name from the ghost array at random
    Serial.println(" ");
    Serial.println("Name: ");
    Serial.print(ghostNames[random(0,25)]);
    
    Serial.println(" ");
    Serial.println(" ");

    //Pick an mood from the Ghost Mood array at random  
    Serial.println("Mood: ");
    Serial.print(Mood[random(0,11)]);

    Serial.println(" ");
    Serial.println(" ");

     //Pick an Answer from the Ghost Answer array at random  
    Serial.println("Response: ");
    Serial.print(Responce[random(0,11)]);

    Serial.println(" ");
    Serial.println(" ");

    //here I am getting a good pause to make it look like you are getting intellegent resonces
    delay(100);
   } 
   
   else {
    Serial.println(" ");
    Serial.println(" ");
    Serial.println("----------Contacting next spirit----------");
    Serial.println(" ");
    Serial.println(" ");
    digitalWrite(white, LOW);
    counter = 0;
   }
   
 }

    lastButtonState = buttonState;

}
