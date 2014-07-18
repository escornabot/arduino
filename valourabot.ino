// vacalourabot.ino

#include <EEPROM.h>

// configuracion dos pins do driver dos motores
#define PIN_MOTOR_E_A 10
#define PIN_MOTOR_E_B 11
#define PIN_MOTOR_D_A 12
#define PIN_MOTOR_D_B 13

// configuracin dos pins dos botons
#define PIN_BOTON_ESQUERDA 3
#define PIN_BOTON_DEREITA 5
#define PIN_BOTON_ADIANTE 6
#define PIN_BOTON_ATRAS 7
#define PIN_BOTON_IR 8
#define PIN_BOTON_BORRAR 9

// milisegundos que dura o paso 
#define PASO_MS 1000

// cada un dous motores (D = dereita, E = esquerad)
#define MOTOR_D 0
#define MOTOR_E 1

// grado de xiro (calibrar o tempo que tarda en milisegundos segundo o tipo de motores)
#define ANGULO_90 500 // milisengundos para 90 graos

// capacidad da memoria en movementos (Arduino 1 ten 2 Kb de memoria SRAM total)
#define MOVEMENTOS_LIMITE 100

// de aqui en diante xa non deberia cambiarse nada ;)

// macros para os xiros a esquerda e dereita
#define XIRO_ESQUERDA (-ANGULO_90)
#define XIRO_DEREITA (ANGULO_90)

// macros para a direccion de avance
#define DIRECCION_ATRAS 0
#define DIRECCION_ADIANTE 1

// tipo de variable e valores que toman os movementos na memoria
#define MOVEMENTO byte
#define MOVEMENTO_DEREITA 1
#define MOVEMENTO_ESQUERDA 2
#define MOVEMENTO_ADIANTE 3
#define MOVEMENTO_ATRAS 4

// memoria para os movementos
MOVEMENTO memoria_movementos[MOVEMENTOS_LIMITE];

// punteiro para ir acumulando movementos na memoria
int memoria_punteiro;

// memoria para os estados dos botons
byte estado_boton_esquerda;
byte estado_boton_dereita;
byte estado_boton_adiante;
byte estado_boton_atras;
byte estado_boton_ir;
byte estado_boton_borrar;

void activarMotor(int motor, int direccion)
{
  if (motor == MOTOR_D)
  {
      // motor dereita
      digitalWrite(PIN_MOTOR_D_A, direccion ? HIGH : LOW);
      digitalWrite(PIN_MOTOR_D_B, direccion ? LOW : HIGH);
  }
  else
  {
      // motor esquerda
      digitalWrite(PIN_MOTOR_E_A, direccion ? HIGH : LOW);
      digitalWrite(PIN_MOTOR_E_B, direccion ? LOW : HIGH);
  }
}

void desactivarMotor(int motor)
{
  if (motor == MOTOR_D)
  {
      // motor dereita
      digitalWrite(PIN_MOTOR_D_A, LOW);
      digitalWrite(PIN_MOTOR_D_B, LOW);
  }
  else
  {
      // motor esquerda
      digitalWrite(PIN_MOTOR_E_A, LOW);
      digitalWrite(PIN_MOTOR_E_B, LOW);
  }
}

void avanzar(int unidades, int direccion)
{
    // activamos os dous motores
    activarMotor(MOTOR_D, direccion);
    activarMotor(MOTOR_E, direccion);
    
    delay(unidades * PASO_MS);
    
    // desactivamos os dous motores
    desactivarMotor(MOTOR_D);
    desactivarMotor(MOTOR_E);    
}

void xirar(int graos)
{
   if (graos > 0)
   {
      // xiro sentido reloxo
      activarMotor(MOTOR_E, DIRECCION_ADIANTE);            
      activarMotor(MOTOR_D, DIRECCION_ATRAS);            
   }
   else
   {
     // xiro sentido anti-reloxo
      activarMotor(MOTOR_D, DIRECCION_ADIANTE);            
      activarMotor(MOTOR_E, DIRECCION_ATRAS);            
   }

   delay(ANGULO_90);
   desactivarMotor(MOTOR_E);      
   desactivarMotor(MOTOR_D);      
}

void eepromGravar()
{
  // gardamos na EEPROM cando haxa movementos
  if (memoria_punteiro > 0)
  {
    // o primeiro dato é o número de movementos
    EEPROM.write(0, memoria_punteiro);

    // e de seguido os movementos almacenados
    for (int m = 0; m < memoria_punteiro; m++)
    {
      EEPROM.write(m + 1, memoria_movementos[m]);
    }
  }
}

void eepromCargar()
{
  // o primeiro dato é o número de movementos
  memoria_punteiro = EEPROM.read(0);

  if (memoria_punteiro > MOVEMENTOS_LIMITE)
  {
    return;
  }

  // e de seguido os movementos
  for (int m = 0; m < memoria_punteiro; m++)
  {
    memoria_movementos[m] = EEPROM.read(m + 1);
  }
}

void ir()
{
  // só imos se hai movementos programados
  if (memoria_punteiro > 0)
  {
    // gardamos o programa de movementos na EEPROM
    eepromGravar();

    // por cada un dos movementos
    for (int m = 0; m < memoria_punteiro; m++)
    {
      // evalúa o tipo e procede
      switch (memoria_movementos[m])
      {
        case MOVEMENTO_DEREITA:
          xirar(XIRO_DEREITA);
          break;
        case MOVEMENTO_ESQUERDA:
          xirar(XIRO_ESQUERDA);
          break;
        case MOVEMENTO_ADIANTE:
          avanzar(1, DIRECCION_ADIANTE);
          break;
        case MOVEMENTO_ATRAS:
          avanzar(1, DIRECCION_ATRAS);
          break;
      }    
    }
  }
}

void memoria_borrar()
{
  memoria_punteiro = 0;
}


void memorizar(int movemento)
{
  if (memoria_punteiro < MOVEMENTOS_LIMITE)
  {
    memoria_movementos[memoria_punteiro] = movemento;
    memoria_punteiro++;
  }
  else
  {
    ir();  
  }
}

void setup()
{
    // configurar motores
    pinMode(PIN_MOTOR_E_A, OUTPUT);
    pinMode(PIN_MOTOR_E_B, OUTPUT);
    pinMode(PIN_MOTOR_D_A, OUTPUT);
    pinMode(PIN_MOTOR_D_B, OUTPUT);
    
    // configurar botons
    pinMode(PIN_BOTON_ESQUERDA, INPUT);
    pinMode(PIN_BOTON_DEREITA, INPUT);
    pinMode(PIN_BOTON_ADIANTE, INPUT);
    pinMode(PIN_BOTON_ATRAS, INPUT);
    pinMode(PIN_BOTON_IR, INPUT);
    pinMode(PIN_BOTON_BORRAR, INPUT);
    
    // inicializar os estados dos botons
    estado_boton_esquerda = LOW;
    estado_boton_dereita = LOW;
    estado_boton_adiante = LOW;
    estado_boton_atras = LOW;
    estado_boton_ir = LOW;
    estado_boton_borrar = LOW;
    
    // inicializar memoria
    memoria_borrar();

    // carga os movementos logo dun apagado
    eepromCargar();
}



void loop(){

  // leer os botons  
  if (digitalRead(PIN_BOTON_ESQUERDA) ^ estado_boton_esquerda)
  {
    estado_boton_esquerda = !estado_boton_esquerda;
    if (estado_boton_esquerda == HIGH)
    {
      memorizar(MOVEMENTO_ESQUERDA);
    }
  }

  if (digitalRead(PIN_BOTON_DEREITA) ^ estado_boton_dereita)
  {
    estado_boton_dereita = !estado_boton_dereita;
    if (estado_boton_dereita == HIGH)
    {
      memorizar(MOVEMENTO_DEREITA);
    }
  }

  if (digitalRead(PIN_BOTON_ADIANTE) ^ estado_boton_adiante)
  {
    estado_boton_adiante = !estado_boton_adiante;
    if (estado_boton_adiante == HIGH)
    {
      memorizar(MOVEMENTO_ADIANTE);
    }
  }

  if (digitalRead(PIN_BOTON_ATRAS) ^ estado_boton_atras)
  {
    estado_boton_atras = !estado_boton_atras;
    if (estado_boton_atras == HIGH)
    {
      memorizar(MOVEMENTO_ATRAS);
    }
  }

  if (digitalRead(PIN_BOTON_BORRAR) ^ estado_boton_borrar)
  {
    estado_boton_borrar = !estado_boton_borrar;
    if (estado_boton_borrar == HIGH)
    {
      memoria_borrar();      
    }
  }

  if (digitalRead(PIN_BOTON_IR) ^ estado_boton_ir)
  {
    estado_boton_ir = !estado_boton_ir;
    if (estado_boton_ir == HIGH)
    {
      // espera antes de comezar a que solten o botón
      delay(500);
      
      ir();      
    }
  }

}