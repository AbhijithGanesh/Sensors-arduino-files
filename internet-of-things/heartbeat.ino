#define HEARTPIN A0

void setup() {
  pinMode(HEARTPIN, INPUT);
  Serial.begin(9600);
}

void loop() {
  long pulse = 0;
  long sum = 0;
  for(int i = 0; i < 20; i++){
    sum += analogRead(HEARTPIN);
    }
  pulse = sum/220;
  delay(1000);
  if(pulse < 70){
    pulse = 0;
   }
  Serial.print("The heartbeat is (bpm)");
  Serial.println(pulse);
}
