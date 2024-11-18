#include <Wire.h>
#include <Arduino.h>

int variable1=0;
int variable2=0;
int variable3=0;
int variable4=0;
int variable5;
String input;
int boundLow;
int boundHigh;
const char delimiter = ',';

void setup() {

  Serial1.setTX(0);
  Serial1.setRX(1);

  Serial.begin(19200);
  Serial1.begin(115200);
  delay(2000);

Serial.println("Pi Pico HC12 Receiver");

}

void loop() {
if(Serial1.available()) {
    Serial.println("Listening");
    input = Serial1.readStringUntil('\n');
    if (input.length() > 0) {
        Serial.println(input);
        boundLow = input.indexOf(delimiter);
        variable1 = input.substring(0, boundLow).toInt();
    
        boundHigh = input.indexOf(delimiter, boundLow+1);
        variable2 = input.substring(boundLow+1, boundHigh).toInt();

        boundLow = input.indexOf(delimiter);//you can add 2 variables, or 4... by adding these 4 lines 
        variable3 = input.substring(0, boundLow).toInt();//you can add 2 variables, or 4... by adding these 4 lines
    
        boundHigh = input.indexOf(delimiter, boundLow+1);//you can add 2 variables, or 4... by adding these 4 lines 
        variable4 = input.substring(boundLow+1, boundHigh).toInt();//     under this line
    
        variable5 = input.substring(boundHigh+1).toInt();//but before this one
//if you change the number of variables, follow instructions in comments above
//duplicating the lines as explained adds 2 variables, then you can duplicate them again, and then change the variable names so they are in the right order
delay(10);
      }//after this you can choose what to do with each variable, which will now have the same value as it's value on the transmitter end
  }

}
