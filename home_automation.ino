int LED1 = 8;
int LED2 = 9;

void setup() {
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);

  Serial.begin(9600);
  Serial.println("Home Automation Ready!");
  Serial.println("Type: ON1 / OFF1 / ON2 / OFF2 to control the lights");
}

void loop() {
  if (Serial.available()) {
    String cmd = Serial.readStringUntil('\n');
    cmd.trim();
    cmd.toUpperCase();

    if (cmd == "ON1") {
      digitalWrite(LED1, HIGH);
      Serial.println("Light 1 turned ON");
    } 
    else if (cmd == "OFF1") {
      digitalWrite(LED1, LOW);
      Serial.println("Light 1 turned OFF");
    } 
    else if (cmd == "ON2") {
      digitalWrite(LED2, HIGH);
      Serial.println("Light 2 turned ON");
    } 
    else if (cmd == "OFF2") {
      digitalWrite(LED2, LOW);
      Serial.println("Light 2 turned OFF");
    } 
    else {
      Serial.println("Unknown command! Try: ON1 / OFF1 / ON2 / OFF2");
    }
  }
}
