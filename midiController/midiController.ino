//MidiNote Mapping
#define NOTE 0x24
#define MIDI_CHANNEL 1

// variables will change:
byte digitalInput;
byte tempInputState;
byte noteOffset;

#define DIGITAL_PINS_NUM 16

#define DIGITAL_PINS 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 14, 15, 16, 17, 18

byte digitalPinMap[DIGITAL_PINS_NUM] = {DIGITAL_PINS};

byte digitalInputState[DIGITAL_PINS_NUM];
byte tempDigitalInput;

byte i = 0;

void setup() {
  Serial.begin(115200);

  for (i = 0; i < DIGITAL_PINS_NUM; i++) {
    pinMode(digitalPinMap[i], INPUT);  
    digitalInputState[i] = digitalRead(digitalPinMap[i]);
    digitalWrite(digitalPinMap[i], HIGH);
  }
}

void loop() {
  for (i = 0; i < DIGITAL_PINS_NUM; i++) {
    noteOffset = i;    

    tempDigitalInput = digitalRead(digitalPinMap[i]);

    if (digitalInputState[i] != tempDigitalInput) {
      delay(2);
      if (tempDigitalInput == digitalRead(digitalPinMap[i])) {
          digitalInputState[i] = tempDigitalInput;

        if (digitalInputState[i] == 0) {
          midiNoteOn(MIDI_CHANNEL, NOTE + noteOffset, 0x7F);
          // Serial.println("noteOn");
        } else {
          midiNoteOff(MIDI_CHANNEL, NOTE + noteOffset);
          // Serial.println("noteOff");
        }  
      }  
    }
  
  }
}

void midiNoteOn(byte channel, byte pitch, byte velocity) {
  channel += 0x90 - 1;

  if (channel >= 0x90 && channel <= 0x9F) {
    Serial.write(channel);
    Serial.write(pitch);  
    Serial.write(velocity);  
  }
}

void midiNoteOff(byte channel, byte pitch) {
  channel += 0x80 - 1;

  if (channel >= 0x80 && channel <= 0x8F) {
    Serial.write(channel);
    Serial.write(pitch);
    Serial.write((byte)0x00);  
  }
}
