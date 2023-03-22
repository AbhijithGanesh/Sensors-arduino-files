#define trigPin 2
#define echoFront 3
#define echoLeft 4
#define echoRight 5

// Define variables:
long duration_f, duration_l, duration_r;
int distance_f, distance_r, distance_l;

void setup() {
  // Define inputs and outputs
  pinMode(trigPin, OUTPUT);
  pinMode(echoFront, INPUT);
  pinMode(echoLeft, INPUT);
  pinMode(echoRight, INPUT);
  Serial.begin(115200);
}

void loop() {
  // Clear the trigPin by setting it LOW:
  digitalWrite(trigPin, LOW);
  
  delayMicroseconds(5);

 // Trigger the sensor by setting the trigPin high for 10 microseconds:
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  // Read the echoPin. pulseIn() returns the duration (length of the pulse) in microseconds:
  duration_f = pulseIn(echoFront, HIGH);
  duration_l = pulseIn(echoLeft, HIGH);
  duration_r = pulseIn(echoRight, HIGH);
  
  // Calculate the distance:
  distance_f = duration_f*0.034/2;
  distance_l = duration_l*0.034/2;
  distance_r = duration_r*0.034/2;
  
  // Print the distance on the Serial Monitor (Ctrl+Shift+M):
  Serial.print("Distance Left is = ");
  Serial.print(distance_f);
  Serial.println(" cm");

  Serial.print("Distance Front is = ");
  Serial.print(distance_l);
  Serial.println(" cm");

  Serial.print("Distance Right is = ");
  Serial.print(distance_r);
  Serial.println(" cm");
  
  delayMicroseconds(10000);
}
