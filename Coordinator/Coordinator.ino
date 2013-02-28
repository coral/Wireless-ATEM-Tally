/*****************
 * Wirless Tally for ATEM
 * This is the coordinator file which requires a Arduino Ethernet to recieve the packets from the ATEM.
 * In this file you defined the IP to the switcher
 * authors: coral
 * library and example: kasper skaarhoj
 */


#include <SPI.h>         // needed for Arduino versions later than 0018
#include <Ethernet.h>

int GREEN = 8;

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
int last_tally = 0;
int current_tally = 0;

int last_preview = 0;
int current_preview = 0;

void setup() { 

  // Start the Ethernet, Serial (debugging) and UDP:
  Ethernet.begin(mac);
  Serial.begin(9600);
  pinMode(GREEN, OUTPUT);   

  // Initialize a connection to the switcher:
  AtemSwitcher.begin(IPAddress(10, 200, 10, 15), 56417);    // <= SETUP!
  AtemSwitcher.serialOutput(false);
  AtemSwitcher.connect();
}

bool AtemOnline = false;
void loop() {

  // Check for packets, respond to them etc. Keeping the connection alive!
  AtemSwitcher.runLoop();

  // If connection is gone anyway, try to reconnect:
  if (AtemSwitcher.isConnectionTimedOut())  {
    digitalWrite(GREEN, LOW);
    AtemSwitcher.connect();

  } 
  digitalWrite(GREEN, HIGH);
  // Selecting output mode: Let only ONE of the functions below be run - the others must be commented out:
  //setTallyProgramOutputs();    // This will reflect inputs 1-8 Program tally on GPO 1-8
  setTallyPreviewProgramOutputs();    // This will reflect inputs 1-4 Program/Preview tally on GPO 1-8 (in pairs)

}


void setTallyPreviewProgramOutputs()  {

  for (uint8_t i=1;i<=3;i++)  {
    if (AtemSwitcher.getProgramTally(i))  {
      current_tally = i;
    } 

    if (AtemSwitcher.getPreviewTally(i))  {
      current_preview = i;
    } 
  }

  if (last_tally != current_tally)  {
    Serial.print(current_tally);
    delay(10);
    last_tally = current_tally;
  }

  if (last_preview != current_preview)  {
    int cp= current_preview + 3;
    Serial.print(cp);
    delay(10);
    last_preview = current_preview;
  }

}


