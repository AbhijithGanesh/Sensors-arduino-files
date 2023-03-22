#define trigRight 5
#define trigLeft 6
#define trigFront 8
#define echoGenerator 7

// Define variables:
long duration;
int left_distance, right_distance, front_distance;

void setup() {
  // Define inputs and outputs
  pinMode(trigRight, OUTPUT);
  pinMode(trigLeft, OUTPUT);
  pinMode(trigFront, OUTPUT);
  pinMode(echoGenerator, INPUT);
  Serial.begin(9600);
}

void loop() {
  digitalWrite(trigFront, LOW);
  delayMicroseconds(2);
  digitalWrite(trigFront, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigFront, LOW);
  duration = pulseIn(echoGenerator, HIGH);
  front_distance = duration*0.034/2;
  Serial.print(front_distance);
  // if (front_distance != 0)
  // {
  //   Serial.print("Distance = ");
  //   Serial.print(front_distance);
  //   Serial.println(" cm");
  // }
  // else{
  //   Serial.print("Distance = 0\n"); 
  // } 
  // delayMicroseconds(10);
}
