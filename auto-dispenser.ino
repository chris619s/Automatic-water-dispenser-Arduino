#define trigger 5  //defining pins to the code
#define echo 4
#define Relay 6

float time = 0, distance = 0;

void setup()
{
  Serial.begin(9600); //how fast information will be sent to serial monitor

  pinMode(trigger, OUTPUT); //tells whether the pins are input or output
  pinMode(echo, INPUT);
  pinMode(Relay, OUTPUT);

  delay(2000); //wait for 2 seconds
}

void loop()
{
  measure_distance();

  if (distance < 5) //if the distance measured by the sensor is less then 5 run the code
  {
    digitalWrite(Relay, HIGH); //turns relay high
  }
  else
  {
    digitalWrite(Relay, LOW); //turns relay low if distance is more then 5 
  }

  delay(500); //wait haldf second
}

void measure_distance()
{
  digitalWrite(trigger, LOW); //emits sound at intervals
  delayMicroseconds(2);
  digitalWrite(trigger, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigger, LOW);
  delayMicroseconds(2);
  time = pulseIn(echo, HIGH); //echo receive reflected noise and work out the time since sound was emitted to receive

  distance = time * 200 / 20000;  //formula for calculating distance
}
