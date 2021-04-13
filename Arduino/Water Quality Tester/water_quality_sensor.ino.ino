#include <SoftwareSerial.h>
#include <LiquidCrystal.h>

SoftwareSerial BTserial(3,2); 

//A0 is the water sample input
float reads;
int pin = A0;

//setting  voltage,resistance variables
float vOut = 0;
float vIn = 5;
float R1 = 1000;
float R2 = 0;
float buffer = 0;
float TDS;

//setting the variables for TDS formula
float R = 0;
float r = 0;
float L = 0.06;
double A = 0.000154;

//setting variables for the closs section of the water sample tube
float C = 0;
float Cm = 0;
int rPin = 9;
int bPin = 5;
int gPin = 6;
int rVal = 255;
int bVal = 255;
int gVal = 255;

//display ON
LiquidCrystal lcd(8,7,10,11,12,13);

//body of main code
void setup() 
{
  Serial.begin(9600);
  BTserial.begin(9600);
  lcd.begin(16, 2);

  pinMode(rPin,OUTPUT);
  pinMode(bPin,OUTPUT);
  pinMode(gPin,OUTPUT);
  pinMode(pin,INPUT);

  lcd.print("Conductivity: ");
}

//using the formula
void loop() 
{
  reads = analogRead(A0);
  
  vOut = reads*5/1023;
  Serial.println(reads);

  buffer = (vIn/vOut)-1;
  R2 = R1*buffer;
  Serial.println(R2);
  delay(500);
    r = R2*A/L;
    C = 1/r;
    Cm = C*10;
  
    TDS = Cm *700;
    lcd.setCursor(0,1);
    lcd.println(C);
    
//setting up the condition for the impurity in water
    if( reads < 600 )
  {
      if (reads <= 300){
        setColor( 255, 0, 255 ) ;
      }
      if (reads > 200){
        setColor( 200, 0, 255 ) ;
      }
  }
  else{
    if( reads <= 900 )
    {
      setColor( 0, 0, 255 ) ;
    }
    if( reads > 700 )
  {
    setColor( 0, 255, 255 ) ;
  }
    }

//LCD output
BTserial.print(C);
BTserial.print(",");
BTserial.print(TDS);
BTserial.print(";");
delay(500);
}

void setColor(int red, int green, int blue)
{
  analogWrite( rPin, 255 - red ) ;
  analogWrite( gPin, 255 - green ) ;
  analogWrite( bPin, 255 - blue ) ;  
}
