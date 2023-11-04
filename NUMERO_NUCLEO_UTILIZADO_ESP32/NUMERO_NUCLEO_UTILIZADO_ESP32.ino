
void setup() {
  Serial.begin(115200);
}

void loop() {
 Serial.println("Proceso en core #: " + String(xPortGetCoreID () ) );
  delay(1000);
}