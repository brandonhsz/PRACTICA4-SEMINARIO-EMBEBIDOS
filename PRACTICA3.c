/*
  SEMINARIO DE PROGRAMACION DE SISTEMAS EMBEBIDOS D15
  Prof. Jesus Ramos
  Alumnos: Hernandez Salinas Brandon Eduardo
  Codigo: 215509503
  Ejercicio: 4
  Fecha: 21/02/22
*/


#define HIGH 1
#define LOW 0
#define TIME 500

void configMicro();

void main() {
  const B = 0x7F, R = 0x31, A = 0x77, N = 0x37, D = 0x5E, O = 0x3F, U = 0x3E, H = 0x76, E = 0x79, Z = 0x5B, S = 0x6D, L = 0x38, I = 0x06;
  const space = 0x10;
  
  unsigned char DISPLAY[33] = {B,R,A,N,D,O,N,space,E,D,U,A,R,D,O,space,H,E,R,N,A,D,E,Z,space,S,A,L,I,N,A,S};
  int j = 0;
  
  configMicro();

  while(HIGH){
      if(PORTC.F7 == LOW){
        PORTC = DISPLAY[j];
        j++;
        Delay_ms(TIME);
        if(j >= 33) j = 0;
      }
  }
}

void configMicro() {

  ANSEL = LOW;
  ANSELH = LOW;
  C1ON_BIT = LOW;
  C2ON_BIT = LOW;
  
  TRISA = LOW;
  TRISB = LOW;
  TRISC = LOW;
  TRISD = LOW;
  TRISE = LOW;

  PORTA = LOW;
  PORTB = LOW;
  PORTC = LOW;
  PORTD = LOW;
  PORTE = LOW;

  TRISC.F7 = HIGH;
}