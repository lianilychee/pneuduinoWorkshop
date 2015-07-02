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

void setup() {
  Serial.begin(9600);
  air.begin();  // start the pneuDuino library
  // your setup-code after this:
  
}

void loop() {
  air.update();  // update the pneuDuino library
  // your loop code after this:
  
  air.in(2, LEFT);
  delay(500);
  
  air.out(2, LEFT);
  delay(750);
  
  air.in(2, LEFT);
  delay(500);
  
  air.out(2, LEFT);
  delay(2000);
}
