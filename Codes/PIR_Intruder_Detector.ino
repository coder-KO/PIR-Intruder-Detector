
int Status = 14;  // Status LED will be high when motion is detected as long as motion is detected or as long as the time delay
int sensor = 13;
int flag;

void setup() {
  Serial.begin(115200);
  pinMode(sensor, INPUT);   // declare sensor as input
  pinMode(Status, OUTPUT);  // declare LED as output
}

void loop(){
  long state = digitalRead(sensor);
  delay(1000);
    if(state == HIGH){
      flag = 0;
      digitalWrite (Status, HIGH);
      Serial.println("Intruder Alert!");
    }
    else {
      digitalWrite (Status, LOW);
        flag++;
        delay(10000);
        if(flag >= 6){
          Serial.println("No motion has been detected for");
          Serial.print((flag*10)/60);
          Serial.print(" mins, lights can be shutdown.");
        }
      }
}
