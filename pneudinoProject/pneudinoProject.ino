/*************************************************************************

    ____  ____     ___  __ __  ___    __ __  ____  ____    ___  
   |    \|    \   /  _]|  |  ||   \  |  |  ||    ||    \  /   \ 
   |  o  )  _  | /  [_ |  |  ||    \ |  |  | |  | |  _  ||     |
   |   _/|  |  ||    _]|  |  ||  D  ||  |  | |  | |  |  ||  O  |
   |  |  |  |  ||   [_ |  :  ||     ||  :  | |  | |  |  ||     |
   |  |  |  |  ||     ||     ||     ||     | |  | |  |  ||     |
   |__|  |__|__||_____| \__,_||_____| \__,_||____||__|__| \___/ 

   PneuDuino is a Toolkit for controlling inflatable actuators
   and prototyping interactions with shape-changing systems.

   Functions:

   begin() - should be called in setup()
   update() - should be called in loop()

   void in(address) - inflates bag of board with defined address
   void out(address) - deflates bag of board with defined address
   void hold(address) - holds air in bag of board with defined address
   void clear(address) - opens valves of boards with defined address
   void inflate(0-255, address) - inflates the airbag to a certain value

   int readPressure(address) - returns pressure of bag at defined address

*****************************************************************************/


#include <Wire.h>
#include <PneuDuino.h>

PneuDuino air = PneuDuino();

int pressureCal = 0;

void setup() {
  Serial.begin(9600);
  air.begin();  // start the pneuDuino library  
}

void loop() {
  air.update();  // update the pneuDuino library
  
  if(pressureCal == 0){
    air.out(11, LEFT);
    delay(2000);
    pressureCal = air.readPressure(11);
  }
  
  
  Serial.println(abs(air.readPressure(11) - pressureCal));
  
  if (abs(air.readPressure(11) - pressureCal) >= 20 ){
    air.out(11, RIGHT);
    delay(500);
    air.in(11, RIGHT);
    delay(300);
     air.out(11, RIGHT);
    delay(200);
    air.in(11, RIGHT);
    delay(100);
  }
  
  
  
      
/*  air.out(11, RIGHT);
  delay(500);
 /* while(millis() < 500){
    Serial.println("before");
    Serial.println(air.readPressure(11)); 
  }*/
/*  air.in(11, RIGHT);
  delay(2000);
 /* while(millis() < 2000){
    Serial.println("after");
    Serial.println(air.readPressure(11)); 
  }*/
 
 
  
}
