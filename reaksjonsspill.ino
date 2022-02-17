// rødt og grønt lys
int redLED = 10;
int greenLED = 9;

// spiller 1 og spiller 2 LED og knapp
int LED1 = 6;
int LED2 = 7;
int SW1 = 3;
int SW2 = 4;

// buzzer
int buzzerPin = 11;

// variabler for å regne tid
unsigned long now = 0;
unsigned long wait = 0;
unsigned long previous = 0;

void setup() {
  pinMode(greenLED, OUTPUT);
  pinMode(redLED, OUTPUT);
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
  pinMode(SW1, INPUT);
  pinMode(SW2, INPUT);
}

void loop() {
  // setter en tilfeldig tid mellom 3 og 6 sekunder
  // slår på rødt lys
  wait = random(3000, 6000);
  digitalWrite(redLED, HIGH);
  now = millis();
  previous = now;

  //vil kjøre når ingen knapper er trykket
  while (digitalRead(SW1) == HIGH && digitalRead(SW2) == HIGH) {
    now =  millis();

    // hvis riktig tid har gått vil grønt lys slå seg på
    if (now - previous >= wait) {
      digitalWrite(redLED, LOW);
      digitalWrite(greenLED, HIGH);
    }
  }

  // hvis grønt lys er på og knapp trykket
  if (digitalRead(greenLED) == HIGH) {
    win();
  }
  else {
    lose();
  }
}

// vinnerfunksjon
void win() {
  int f = 750;

  // hvis spiller 1
  if (digitalRead(SW1) == LOW) {

    // lys blink og lydendring
    for (int i = 0; i < 15; i++) {
      tone(buzzerPin, 750, 100);
      f += 20;
      digitalWrite(greenLED, HIGH);
      digitalWrite(LED1, HIGH);
      delay(50);
      digitalWrite(greenLED, LOW);
      digitalWrite(LED1, LOW);
      delay(50);
    }
  }

  // hvis spiller 2
  else if (digitalRead(SW2) == LOW) {

    // lys blink og lydendring
    for (int i = 0; i < 15; i++) {
      tone(buzzerPin, f, 100);
      f += 20;
      digitalWrite(greenLED, HIGH);
      digitalWrite(LED2, HIGH);
      delay(50);
      digitalWrite(greenLED, LOW);
      digitalWrite(LED2, LOW);
      delay(50);
    }
  }
}

// taperfunksjon
void lose() {
  // if player 1
  if (digitalRead(SW1) == LOW) {

    // lys blink og konstant lyd
    tone(buzzerPin, 400, 100);
    digitalWrite(redLED, HIGH);
    digitalWrite(LED1, HIGH);
    delay(50);
    digitalWrite(redLED, LOW);
    digitalWrite(LED1, LOW);
    delay(50);
  }

  // if player 2
  else if (digitalRead(SW2) == LOW) {

    // lys blink og konstant lyd
    tone(buzzerPin, 400, 100);
    digitalWrite(redLED, HIGH);
    digitalWrite(LED2, HIGH);
    delay(50);
    digitalWrite(redLED, LOW);
    digitalWrite(LED2, LOW);
    delay(50);
  }
}
