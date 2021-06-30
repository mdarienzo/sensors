//Based on code written by Nathan Seidle & Andrew England @ SparkFun Electronics, July 12th, 2017

#include "AS726X.h"
AS726X sensor;

//Set the gain to multiply by 16x and choose the measurement mode
byte GAIN = 2;
byte MEASUREMENT_MODE = 3;

//MEASUREMENT_MODE = 2 means continuously read all channels until stopped
//MEASUREMENT_MODE = 3 means measure all channels just once 

//Create variables for visible sensor data
float violet = 0;
float blue = 0;
float green = 0;
float yellow = 0;
float orange = 0;
float red = 0;

//Create variables for NIR sensor data
float r = 0;
float s = 0;
float t = 0;
float u = 0;
float v = 0;
float w = 0;

void setup() {
  sensor.begin(Wire, GAIN, MEASUREMENT_MODE);
}

void loop() {
  Wire.begin();
  Serial.begin(115200);
  sensor.disableIndicator();
    
  sensor.takeMeasurementsWithBulb();
  
  if (sensor.getVersion() == SENSORTYPE_AS7262)
  {
    //Take visible readings   
    violet = sensor.getCalibratedViolet();
    blue = sensor.getCalibratedBlue();
    green = sensor.getCalibratedGreen();
    yellow = sensor.getCalibratedYellow();
    orange = sensor.getCalibratedOrange();
    red = sensor.getCalibratedRed();

    //Write out the data for Python
    Serial.print("np.array([");
    Serial.print(violet, 2);
    Serial.print(", ");
    Serial.print(blue, 2);
    Serial.print(", ");
    Serial.print(green, 2);
    Serial.print(", ");
    Serial.print(yellow, 2);
    Serial.print(", ");
    Serial.print(orange, 2);
    Serial.print(", ");
    Serial.print(red, 2);
    Serial.println("])");

    //Write out the data for Mathematica
    Serial.print("{{450,");
    Serial.print(violet, 2);
    Serial.print("}, {500,");
    Serial.print(blue, 2);
    Serial.print("}, {550,");
    Serial.print(green, 2);
    Serial.print("}, {570,");
    Serial.print(yellow, 2);
    Serial.print("}, {600,");
    Serial.print(orange, 2);
    Serial.print("}, {650,");
    Serial.print(red, 2);
    Serial.println("}};");
    
    /*
    //Get measurements and write them out for Mathematica
    Serial.print("{{450,");
    Serial.print(sensor.getCalibratedViolet(), 2);
    Serial.print("}, {500,");
    Serial.print(sensor.getCalibratedBlue(), 2);
    Serial.print("}, {550,");
    Serial.print(sensor.getCalibratedGreen(), 2);
    Serial.print("}, {570,");
    Serial.print(sensor.getCalibratedYellow(), 2);
    Serial.print("}, {600,");
    Serial.print(sensor.getCalibratedOrange(), 2);
    Serial.print("}, {650,");
    Serial.print(sensor.getCalibratedRed(), 2);
    Serial.print("}}");
    */
  }
  else if (sensor.getVersion() == SENSORTYPE_AS7263)
  {
    //Take NIR readings
    r = sensor.getCalibratedR();
    s = sensor.getCalibratedS();
    t = sensor.getCalibratedT();
    u = sensor.getCalibratedU();
    v = sensor.getCalibratedV();
    w = sensor.getCalibratedW();
    
    //Write out the data for Python
    Serial.print("np.array([");
    Serial.print(r, 2);
    Serial.print(", ");
    Serial.print(s, 2);
    Serial.print(", ");
    Serial.print(t, 2);
    Serial.print(", ");
    Serial.print(u, 2);
    Serial.print(", ");
    Serial.print(v, 2);
    Serial.print(", ");
    Serial.print(w, 2);
    Serial.println("])");

    //Write out the data for Mathematica
    Serial.print("{{610,");
    Serial.print(r, 2);
    Serial.print("}, {680,");
    Serial.print(s, 2);
    Serial.print("}, {730,");
    Serial.print(t, 2);
    Serial.print("}, {760,");
    Serial.print(u, 2);
    Serial.print("}, {810,");
    Serial.print(v, 2);
    Serial.print("}, {860,");
    Serial.print(w, 2);
    Serial.println("}};");
    
    /*
    //Get measurements and write them out for Mathematica
    Serial.print("{{610,");
    Serial.print(sensor.getCalibratedR(), 2);
    Serial.print("}, {680,");
    Serial.print(sensor.getCalibratedS(), 2);
    Serial.print("}, {730,");
    Serial.print(sensor.getCalibratedT(), 2);
    Serial.print("}, {760,");
    Serial.print(sensor.getCalibratedU(), 2);
    Serial.print("}, {810,");
    Serial.print(sensor.getCalibratedV(), 2);
    Serial.print("}, {860,");
    Serial.print(sensor.getCalibratedW(), 2);
    Serial.print("}");
    */
  }

  Serial.print("{tempF,");
  Serial.print(sensor.getTemperatureF(), 1);
  Serial.print("}}");
}
