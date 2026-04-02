int noisePin = A0;

int red = 8;
int yellow = 9;
int green = 10;

int noiseLimit = 80;

bool ambulance = false;

void setup()
{
  Serial.begin(9600);

  pinMode(red, OUTPUT);
  pinMode(yellow, OUTPUT);
  pinMode(green, OUTPUT);
}

void loop()
{
  int penalty = 0;

  // -------- GREEN --------
  digitalWrite(green, HIGH);
  digitalWrite(red, LOW);
  digitalWrite(yellow, LOW);

  for(int t = 5; t >= 0; t--)
  {
    sendData("G", t, penalty);
    delay(1000);
  }

  // -------- YELLOW --------
  digitalWrite(green, LOW);
  digitalWrite(yellow, HIGH);

  for(int t = 3; t >= 0; t--)
  {
    sendData("Y", t, penalty);
    delay(1000);
  }

  digitalWrite(yellow, LOW);

  // -------- RED --------
  ambulance = false;   // reset every cycle

  digitalWrite(red, HIGH);

  int redTime = 6;
  int penaltyGiven = 0;
  int ambulanceHandled = 0;

  for(int t = redTime; t >= 0; t--)
  {
    checkAmbulance();

    int noise = analogRead(noisePin);
    int db = map(noise,0,1023,30,120);

    // Ambulance priority
    if(ambulance && ambulanceHandled == 0)
    {
      t = t / 2;
      ambulanceHandled = 1;
    }

    // Honking penalty
    if(db > noiseLimit && penaltyGiven == 0 && ambulance == false)
    {
      t = t + 10;
      penalty = 1;
      penaltyGiven = 1;
    }

    Serial.print("R,");
    Serial.print(t);
    Serial.print(",");
    Serial.print(db);
    Serial.print(",");
    Serial.println(penalty);

    delay(1000);
  }

  digitalWrite(red, LOW);
}

void sendData(String signal, int t, int penalty)
{
  int noise = analogRead(noisePin);
  int db = map(noise,0,1023,30,120);

  Serial.print(signal);
  Serial.print(",");
  Serial.print(t);
  Serial.print(",");
  Serial.print(db);
  Serial.print(",");
  Serial.println(penalty);
}

void checkAmbulance()
{
  if(Serial.available())
  {
    char c = Serial.read();

    if(c == 'A')
    {
      ambulance = true;
    }
  }
}
