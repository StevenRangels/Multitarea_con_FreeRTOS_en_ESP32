TaskHandle_t Tarea0; // Definición de la variable que almacena el identificador de la tarea 0
//TaskHandle_t Tarea1;

const int led1 = 25, led2 = 32;

void setup() {
  xTaskCreatePinnedToCore (loop0,"tarea_0",1000,NULL,1,&Tarea0,0); 
  /* xTaskCreatePinnedToCore (loop0,"tarea_0",1000,NULL,1,&Tarea0,1); 
     loop0 nombre loop.
     El 1 primero es la prioridad de ejecución,se recomienda dejar en 1. 
     El ultimo numero es el numero de nucleo utilizado.
  */ 
  pinMode(led1,OUTPUT), pinMode(led2, OUTPUT);
}

void loop() {
  digitalWrite(led1, HIGH);
  delay(110);
  digitalWrite(led1, LOW);
  delay(110);

}

void loop0(void *parameter) { //tarea0

while(1==1) {
  digitalWrite(led2, HIGH);
  delay(220);
  digitalWrite(led2, LOW);
  delay(220);

}

} 

 


