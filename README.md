# Multitarea_con_FreeRTOS_en_ESP32
Ejemplo que muestra la implementación de multitarea en un microcontrolador ESP32 utilizando el sistema operativo en tiempo real FreeRTOS.

## Descripción del Código.

El código de ejemplo tiene como objetivo demostrar la creación de dos tareas concurrentes en un ESP32, donde cada tarea parpadea un LED en un patrón diferente. El código se ejecuta en dos núcleos de procesador diferentes (núcleo 0 y núcleo 1), lo que permite que las tareas se ejecuten de manera independiente.

## Descripción del Contenido.

- En la carpeta (NUMERO_NÚCLEO_UTILIZADO_ESP32), se encuentra el código para identificar el núcleo (núcleo 0 y núcleo 1) donde se ejecuta el loop() principal por defecto del ESP32. Para su programación posterior correcta, se recomienda ejecutar este código primero e identificar el núcleo por defecto.

- En la carpeta (MULTITAREA_ESP32), se encuentra el código base, donde se ejecuta de forma básica dos tareas de manera independiente. 

## Variables y Configuraciones Iniciales.

### TaskHandle_t Tarea0;

Esta línea declara una variable de tipo TaskHandle_t llamada Tarea0, que se utilizará para almacenar el identificador de la tarea creada.

### const int led1 = 25, led2 = 32;

Se definen constantes para los pines que controlarán los LEDs. El pin 25 (led1) se utiliza en el bucle principal, y el pin 32 (led2) se utiliza en la tarea secundaria.

## Función setup()

### xTaskCreatePinnedToCore (loop0, "tarea_0", 1000, NULL, 1, &Tarea0, 0);

En esta línea se crea la tarea principal llamada "tarea_0". La función xTaskCreatePinnedToCore se utiliza para crear la tarea. la función loop0 se ejecutará como tarea, un nombre descriptivo, el tamaño de la pila, un parámetro (en este caso, NULL), la prioridad (1), una variable para almacenar el identificador de la tarea (&Tarea0), y se especifica que la tarea se ejecutará en el núcleo 0.

### pinMode(led1, OUTPUT), pinMode(led2, OUTPUT);

En esta parte, se configuran los pines led1 y led2 como salidas para controlar los LEDs.

## Función loop()

En el bucle principal (loop()), se parpadea el LED conectado al pin led1.

## Función loop0()

La función loop0 es la tarea que se ejecuta en el núcleo 0. Parpadea el LED conectado al pin led2. El ciclo de parpadeo se repite indefinidamente, lo que demuestra la ejecución de una tarea en paralelo con el bucle principal.

## Ejecución del Código.

Cuando este código se carga en un ESP32, se crean dos tareas en paralelo: una en el bucle principal y otra en el núcleo 0. Cada tarea controla un LED y parpadea con patrones de tiempo diferentes.