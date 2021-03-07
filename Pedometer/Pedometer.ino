#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 32 // OLED display height, in pixels

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
#define OLED_RESET     4 // Reset pin # (or -1 if sharing Arduino reset pin)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

#define LOGO_HEIGHT   16
#define LOGO_WIDTH    16

const int MPU=0x68, DELTA = 30;
int steps, delta, mag1, mag2 = 0;
int mag, aX,aY,aZ, threshold;

void setup(){
  Serial.begin(9600);
  //IMU setup
  Wire.begin();
  Wire.beginTransmission(MPU);
  Wire.write(0x6B); 
  Wire.write(0);    
  Wire.endTransmission(true);

  //OLED SET-UP
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C); // Address 0x3C for 128x32
  display.display();
  delay(1000);
  display.clearDisplay();
  display.display();
  display.setTextSize(2);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0,0);

  //initialize text for debugging
  display.print("Steps: ");
  display.println(steps);
  display.display();

}

void loop(){
  delta = getDelta();
  if ((abs(delta) > DELTA)){
    steps ++; //increase stepcount
    delay(400); //delay between steps to avoid overcounting.
    delta = 0; //just making sure nothing overflows :)
    updateDisplay();
  }

}

//Reading vectors from accelerometer and gyroscope.
void readIMU(){  
  Wire.beginTransmission(MPU);
  Wire.write(0x3B);  
  Wire.endTransmission(false);
  Wire.requestFrom(MPU,12,true); 
  
  // bitwise manipulations (shifting 4-bits to the left) MSB|LSB
  aX=Wire.read()<<4|Wire.read(); 
  aY=Wire.read()<<4|Wire.read();
  aZ=Wire.read()<<4|Wire.read();
  }

//get the change in accelerometer vector magnitude values to determine motion
int getDelta(){
  readIMU();
  mag1 = getMag(aX, aY, aZ); 
  delay(100);
  readIMU();
  mag2 = getMag(aX, aY, aZ);
  return mag2 - mag1;
}

//Getting vector magnitude
int getMag(int x, int y, int z){
  mag = sqrt(x^2 + y^2 + z^2);
  return mag;
}

//update value on display if step count changed
void updateDisplay(){
  display.clearDisplay();
  display.setCursor(0,0);
  display.print("Steps: ");
  display.print(steps);
  display.display();
}
