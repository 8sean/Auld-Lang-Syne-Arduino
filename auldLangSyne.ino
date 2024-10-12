// Auld Lang Syne
// Estimated Runtime: 80 seconds
// Credit to @robsoncouto for the "for" loop. Credit to Piano Tutorials for Beginners for the notes in the song: https://www.youtube.com/watch?v=tzTFwVTDg2I
// Created by Sean Pan, Class of 2028
// Happy Arduinoing!

// Defining the frequencies of each note taken from <pitches.h>
#define REST 0
#define NOTE_G3  196
#define NOTE_A3  220
#define NOTE_B3  247
#define NOTE_C4  262
#define NOTE_D4  294
#define NOTE_E4  330
#define NOTE_G4  392
#define NOTE_A4  440

// Defining the piezo pin, this number must be changed if not set at pin 8
const int piezoPin = 8;

// Notes in UVA's Good Ole Song
int melody[] = {
  NOTE_G3, NOTE_C4, NOTE_B3, NOTE_C4, NOTE_E4, NOTE_D4, NOTE_C4, NOTE_D4,
  NOTE_E4, NOTE_D4, NOTE_C4, NOTE_C4, NOTE_E4, NOTE_G4, NOTE_A4, NOTE_A4,
  NOTE_G4, NOTE_E4, NOTE_E4, NOTE_C4, NOTE_D4, NOTE_C4, NOTE_D4, NOTE_E4,
  NOTE_D4, NOTE_C4, NOTE_A3, NOTE_A3, NOTE_G3, NOTE_C4, NOTE_A4, NOTE_G4, 
  NOTE_E4, NOTE_E4, NOTE_C4, NOTE_D4, NOTE_C4, NOTE_D4, NOTE_A4, NOTE_G4,
  NOTE_E4, NOTE_E4, NOTE_G4, NOTE_A4, NOTE_A4, NOTE_G4, NOTE_E4, NOTE_E4,
  NOTE_C4, NOTE_D4, NOTE_C4, NOTE_D4, NOTE_E4, NOTE_D4, NOTE_C4, NOTE_A3,
  NOTE_A3, NOTE_G3, NOTE_C4, NOTE_G3, NOTE_C4, NOTE_B3, NOTE_C4, NOTE_E4, 
  NOTE_D4, NOTE_C4, NOTE_D4, NOTE_E4, NOTE_D4, NOTE_C4, NOTE_C4, NOTE_E4,
  NOTE_G4, NOTE_A4, NOTE_A4, NOTE_G4, NOTE_E4, NOTE_E4, NOTE_C4, NOTE_D4, 
  NOTE_C4, NOTE_D4, NOTE_E4, NOTE_D4, NOTE_C4, NOTE_A3, NOTE_A3, NOTE_G3,
  NOTE_C4, NOTE_A4, NOTE_G4, NOTE_E4, NOTE_E4, NOTE_C4, NOTE_D4, NOTE_C4, 
  NOTE_D4, NOTE_A4, NOTE_G4, NOTE_E4, NOTE_E4, NOTE_G4, NOTE_A4, NOTE_A4, 
  NOTE_G4, NOTE_E4, NOTE_E4, NOTE_C4, NOTE_D4, NOTE_C4, NOTE_D4, NOTE_E4, 
  NOTE_D4, NOTE_C4, NOTE_A3, NOTE_A3, NOTE_G3, NOTE_C4, REST
};

// Note durations 
int noteDurations[] = {
 4, 2, 8, 4, 4, 2, 8, 4,
 8, 8, 2, 8, 4, 4, 1, 4,
 2, 8, 4, 4, 2, 8, 4, 8,
 8, 4, 8, 4, 4, 1, 4, 2,
 8, 4, 4, 2, 8, 4, 4, 4, 
 8, 4, 4, 1, 4, 2, 8, 4,
 4, 2, 8, 4, 8, 8, 2, 8,
 4, 4, 1, 4, 2, 8, 4, 4, 
 2, 8, 4, 8, 8, 2, 8, 4, 
 4, 1, 4, 2, 8, 4, 4, 4,
 8, 4, 8, 8, 2, 8, 4, 4, 
 1, 4, 2, 8, 4, 4, 2, 8,
 4, 4, 2, 8, 4, 4, 1, 4, 
 2, 8, 4, 4, 2, 8, 4, 8, 
 8, 2, 8, 4, 4, 2, 1
};

// Note duration is set to 1500 here; however lower it to make it slower, and raise it to make it quicker.
// For more dramatic (or less dramatic) pauses, change the 1.50 in pauseBetweenNotes
void setup() {
  for (int thisNote = 0; thisNote < sizeof(melody)/sizeof(melody[0]); thisNote++) {
    int noteDuration = 1500 / noteDurations[thisNote];
    tone(piezoPin, melody[thisNote], noteDuration);
    int pauseBetweenNotes = noteDuration * 1.50;
    delay(pauseBetweenNotes);
    noTone(piezoPin);
  }
}

void loop() {
  // Nothing here to loop
}
