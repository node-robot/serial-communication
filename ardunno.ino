
int p7 = 7;
char buffer[100];

void setup(){
  pinMode(p7, OUTPUT);
  Serial.begin(9600);
}

void loop(){
  if(Serial.available()){
    int b = Serial.readBytesUntil('\n', buffer, 100);
    Serial.print("Found: ");
    Serial.println(b);
    Serial.print("Chars: ");
    Serial.println(buffer);

    int compare = strcmp(buffer, "on");

    if(compare == 0){
      digitalWrite(p7, HIGH);
    }else{
      digitalWrite(p7, LOW);
    }

    memset(buffer, 0, sizeof(buffer));
  }

  delay(10);
}
