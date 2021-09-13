# Resolución de ejercicio B4 de Guia de ejercitación de RTOS de CESE (2021)
Autor:
Fernando Prokopiuk <fernandoprokopiuk@gmail.com>

Implemente un sistema de 4 tareas:

Led B - Tarea A - Prioridad +4

Led 1 - Tarea B - Prioridad +2

Led 2 - Tarea C - Prioridad +2

Led 3 - Tarea D - Prioridad +1

Arrancando solamente la tarea A antes de comenzar el scheduler, genere la siguiente secuencia de encendido y apagado (500ms/500ms):

![image info](./pictures/patron.png)

El sistema deberá arrancar ejecutando la tarea de mayor prioridad solamente.

Las tareas B y C DEBEN tener un código fuente equivalente (salvando la parte en donde se accede al LED).

Ahora, configure en freertosconfig.h:
 #define configUSE_TIME_SLICING 0

¿Qué sucedió?

Proponga una manera de contrarrestar el efecto sin tocar la configuración mencionada (no utilice la Suspend/Resume para solucionarlo)

Respuesta: las tareas B y C son tareas de igual prioridad. Al desactivar el round robin el planificador no divide el tiempo de CPU entre estas tareas cuando ambas se encuentran listas para ser ejecutadas. Por lo tanto siguiendo la cola de ejecución, el planificador pone en ejecución primero tarea B y luego tarea C. Para resolver el problema se propone utilizar la función taskYIELD () para forzar el cambio de contexto a otra tarea, de manera que se dividan los tiempos de CPU.
