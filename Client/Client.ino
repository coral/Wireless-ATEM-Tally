/*****************
 * Wirless Tally for ATEM
 * Client file
 * authors: coral
 * library and example: kasper skaarhoj
 */

//Define the LED pins
int RED = 7;
int GREEN = 6;
int CAMERA_NUMBER = 1;

char inData[20]; // Allocate some space for the string
char inChar; // Where to store the character read
byte index = 0; // Index into array; where to store the character

void setup() {
  pinMode(RED, OUTPUT);
  pinMode(GREEN, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
   while(Serial.available() > 0) // Don't read unless
                                                  // there you know there is data
   {
       if(index < 19) // One less than the size of the array
       {
           inChar = Serial.read(); // Read a character
           inData[index] = inChar; // Store it
           index++; // Increment where to write next
           inData[index] = '\0'; // Null terminate the string
       }
   }
   // Now do something with the string (but not using ==)
}
