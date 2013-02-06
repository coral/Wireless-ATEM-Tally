/*****************
 * Wirless Tally for ATEM
 * This is the coordinator file which requires a Arduino Ethernet to recieve the packets from the ATEM.
 * In this file you defined the IP to the switcher
 * authors: coral
 * library and example: kasper skaarhoj
 */


#include <SPI.h>         // needed for Arduino versions later than 0018
#include <Ethernet.h>

int RED = 7;
int GREEN = 6;

// MAC address and IP address for this *particular* Ethernet Shield!
// MAC address is printed on the shield
// IP address is an available address you choose on your subnet where the switcher is also present:
byte mac[] = { 
  0x90, 0xA2, 0xDA, 0x00, 0x76, 0xB1 };      // <= SETUP!
IPAddress ip(10, 200, 10, 199);              // <= SETUP!


// Include ATEM library and make an instance:
#include <ATEM.h>

// Connect to an ATEM switcher on this address and using this local port:
// The port number is chosen randomly among high numbers.
ATEM AtemSwitcher;


void setup() { 

  // Start the Ethernet, Serial (debugging) and UDP:
  Ethernet.begin(mac,ip);
  Serial.begin(9600);
   pinMode(RED, OUTPUT);   
   pinMode(GREEN, OUTPUT);   

  // Initialize a connection to the switcher:
  AtemSwitcher.begin(IPAddress(10, 200, 10, 200), 56417);    // <= SETUP!
//  AtemSwitcher.serialOutput(true);
  AtemSwitcher.connect();
}

bool AtemOnline = false;
void loop() {

  // Check for packets, respond to them etc. Keeping the connection alive!
  AtemSwitcher.runLoop();

    // If connection is gone anyway, try to reconnect:
  if (AtemSwitcher.isConnectionTimedOut())  {
     Serial.println("Connection to ATEM Switcher has timed out - reconnecting!");
     AtemSwitcher.connect();
  } 

  // Selecting output mode: Let only ONE of the functions below be run - the others must be commented out:
  //setTallyProgramOutputs();    // This will reflect inputs 1-8 Program tally on GPO 1-8
  setTallyPreviewProgramOutputs();    // This will reflect inputs 1-4 Program/Preview tally on GPO 1-8 (in pairs)


  //checkGPI_setProgramBus();  // This will select the inputs 1-8 to be on the Program bus.
  //checkGPI_setVarious();  // This will call all sorts of switcher functions as a demonstration of how much crazy stuff can be done. See the function for more info.
}


void setTallyPreviewProgramOutputs()  {
   // Setting colors of input select buttons:
  for (uint8_t i=1;i<=4;i++)  {
    if (AtemSwitcher.getProgramTally(i))  {
      Serial.print(i + ",2,T");
    }  /*     
    else {
     digitalWrite(RED, LOW); 
    } */

    if (AtemSwitcher.getPreviewTally(i))  {
       Serial.print(i + ",1,T");
     } /*else {
       digitalWrite(GREEN, LOW); 
    }*/
  }
  
}

