#include <Arduino.h>
#include "RangeFinder.h"

float RangeFind() {
  float ir_volt[11] ={0,0,0,0,0,0,0,0,0,0,0};
  //// Select AtoD Channel (ADC0,PF0,pin97) ////
  ADMUX &= 0b11110000;
  ADMUX |= 0b00000000;

  //// Start AtoD Conversions (bit 6) ////
  ADCSRA |= 0b01000000;

  //// Wait until Conversion Complete Flag is set (bit 4) ////
  while(!(ADCSRA & 0b00010000));

  // Read High Register Data to Fill Pre-Sized Array //
  for(int num_readings = 0; num_readings <= 10; num_readings++){
    ir_volt[num_readings] = ADCH;
  }

 // Set the Value to be displayed on the LCD //
  float ir_volt_median = find_median(11,ir_volt);

   // Convert Voltage to cm with curve fit from Excel 175.95e-0.026x
  float measurement = (2772.8*pow(ir_volt_median/2, -1.2045))/2;


 // Print Value to the LCD //
  //lcd_display ("cm", measurement);

  //if(PINA&Button){
//    delay(200);
  //run_measure = !run_measure;
  return measurement;
}

float find_median(int n, float x[]) {
    int temp;
    int i, j;
    // the following two loops sort the array x in ascending order
    for(i=0; i<n-1; i++) {
        for(j=i+1; j<n; j++) {
            if(x[j] < x[i]) {
                // swap elements
                temp = x[i];
                x[i] = x[j];
                x[j] = temp;
            }
        }
    }

    if(n%2==0) {
        // if there is an even number of elements, return mean of the two elements in the middle
        return((x[n/2] + x[n/2 - 1]) / 2.0);
    } else {
        // else return the element in the middle
        return x[n/2];
    }
}
