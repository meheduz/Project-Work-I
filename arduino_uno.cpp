#define in1   3
#define in2   5
#define in3   6
#define in4   11

#define LEDF  9   // Front LED
#define LEDB  8   // Back LED
#define HORN  7   // Horn
#define LEDP  4   // Parking LED

int command;         // Store app command
int Speed = 204;     // Default speed (0 - 255)
int Speedsec;
int buttonState = 0;
int lastButtonState = 0;
int Turnradius = 0;  // Radius of turn, 0 - 255
int brakeTime = 45;  // Brake delay in ms
int brkonoff = 1;    // 1 = electronic braking ON, 0 = OFF

void setup() {
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);

  pinMode(LEDF, OUTPUT);
  pinMode(LEDB, OUTPUT);
  pinMode(HORN, OUTPUT);
  pinMode(LEDP, OUTPUT);

  Serial.begin(9600); // Baud rate for HC-05
}

void loop() {
  if (Serial.available() > 0) {
    command = Serial.read();
    Stop(); // Default = stop

    switch (command) {
      case 'F': forward(); break;
      case 'B': back(); break;
      case 'L': left(); break;
      case 'R': right(); break;

      case 'G': forwardleft(); break;
      case 'I': forwardright(); break;
      case 'H': backleft(); break;
      case 'J': backright(); break;

      case 'W': frontledon(); break;
      case 'w': frontledoff(); break;

      case 'U': backledon(); break;
      case 'u': backledoff(); break;

      case 'V': hornon(); break;
      case 'v': hornoff(); break;

      case 'X': parkledon(); break;
      case 'x': parkledoff(); break;

      case '0': Speed = 100; break;
      case '1': Speed = 140; break;
      case '2': Speed = 153; break;
      case '3': Speed = 165; break;
      case '4': Speed = 178; break;
      case '5': Speed = 191; break;
      case '6': Speed = 204; break;
      case '7': Speed = 216; break;
      case '8': Speed = 229; break;
      case '9': Speed = 242; break;
      case 'q': Speed = 255; break;
    }

    Speedsec = Turnradius;

    if (brkonoff == 1) {
      brakeOn();
    } else {
      brakeOff();
    }
  }
}

// --- Motor Control ---
void forward() {
  analogWrite(in1, Speed);
  analogWrite(in3, Speed);
}

void back() {
  analogWrite(in2, Speed);
  analogWrite(in4, Speed);
}

void left() {
  analogWrite(in3, Speed);
  analogWrite(in2, Speed);
}

void right() {
  analogWrite(in4, Speed);
  analogWrite(in1, Speed);
}

void forwardleft() {
  analogWrite(in1, Speedsec);
  analogWrite(in3, Speed);
}

void forwardright() {
  analogWrite(in1, Speed);
  analogWrite(in3, Speedsec);
}

void backright() {
  analogWrite(in2, Speed);
  analogWrite(in4, Speedsec);
}

void backleft() {
  analogWrite(in2, Speedsec);
  analogWrite(in4, Speed);
}

void Stop() {
  analogWrite(in1, 0);
  analogWrite(in2, 0);
  analogWrite(in3, 0);
  analogWrite(in4, 0);
}

// --- Lights & Horn ---
void frontledon() { digitalWrite(LEDF, HIGH); }
void frontledoff() { digitalWrite(LEDF, LOW); }

void backledon() { digitalWrite(LEDB, HIGH); }
void backledoff() { digitalWrite(LEDB, LOW); }

void hornon() { digitalWrite(HORN, HIGH); }
void hornoff() { digitalWrite(HORN, LOW); }

void parkledon() { digitalWrite(LEDP, HIGH); }
void parkledoff() { digitalWrite(LEDP, LOW); }

// --- Brake System ---
void brakeOn() {
  buttonState = command;
  if (buttonState != lastButtonState) {
    if (buttonState == 'S') {
      if (lastButtonState != buttonState) {
        digitalWrite(in1, HIGH);
        digitalWrite(in2, HIGH);
        digitalWrite(in3, HIGH);
        digitalWrite(in4, HIGH);
        delay(brakeTime);
        Stop();
      }
    }
    lastButtonState = buttonState;
  }
}

void brakeOff() {
  // Nothing here (no braking)
}
