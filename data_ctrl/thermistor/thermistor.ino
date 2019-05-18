#include <math.h>
// which analog pin to connect
#define THERMISTORPIN A0         
// resistance at 25 degrees C
#define THERMISTORNOMINAL 100000      
// temp. for nominal resistance (almost always 25 C)
#define TEMPERATURENOMINAL 25   
// how many samples to take and average, more takes longer
// but is more 'smooth'
#define NUMSAMPLES 5

//Steinhart-Hart Equation Coefficients
//The A Coefficient
#define A 0.0004316052382  
//The B Coefficient
#define B 0.0002581936673
//The C Coefficient
#define C -0.00000003910705935

// The beta coefficient of the thermistor (usually 3000-4000)
#define BCOEFFICIENT 3950
// the value of the 'other' resistor
#define SERIESRESISTOR 10000 
void setup(void) {
  Serial.begin(9600);
}
 
void loop(void) {
  double reading;
 
  reading = analogRead(THERMISTORPIN);
 
  Serial.print("Analog reading "); 
  Serial.println(reading);
 
  // convert the value to resistance
  reading = (1023 / reading)  - 1;     // (1023/ADC - 1) 
  reading = SERIESRESISTOR / reading;  // 10K / (1023/ADC - 1)
  Serial.print("Thermistor resistance "); 
  Serial.println(reading);

  double steinhart;
  double part2 = B*log(reading);
  double part3 = C*(pow(log(reading), 3));
  steinhart = A + part2 + part3;
  steinhart = 1.0/steinhart;
  steinhart -= 273.15;                   //Convert to C
  Serial.print(steinhart);
  Serial.println(" *C");
  //Error compensation of about +/- degree Celsius, temps/resistance seem to be off about 1C according to chart
  steinhart -= steinhart - 1;
  steinhart = (1.8*steinhart) + 32;    //Convert to F
  Serial.print("Temperature "); 
  Serial.print(steinhart);
  Serial.println(" *F");
  

 /* FIND A BETTER RESISTANCE TO TEMPERATURE CONVERSION FOR 100K THERMISTOR (data sheet below)
  *  
  *  https://www.makeralot.com/download/Reprap-Hotend-Thermistor-NTC-3950-100K.pdf
  *  
  float steinhart;
  steinhart = reading / THERMISTORNOMINAL;     // (R/Ro)
  steinhart = log(steinhart);                  // ln(R/Ro)
  steinhart /= BCOEFFICIENT;                   // 1/B * ln(R/Ro)
  steinhart += 1.0 / (TEMPERATURENOMINAL + 273.15); // + (1/To)
  steinhart = 1.0 / steinhart;                 // Invert
  steinhart -= 273.15;                         // convert to C
  steinhart = ((9/5)*steinhart) + 32;
  Serial.print("Temperature "); 
  Serial.print(steinhart);
  Serial.println(" *F");
  */
 
}
