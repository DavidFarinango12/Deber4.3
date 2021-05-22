/*
 * CAPITULO IV: PERIFERICOS ESPECIALES
 * DEBER 4.3: USO DE TIMER 2 CON LCD 20X4
 * OBJETIVO: REALIZAR UN RELOJ CON ESTE TIMER
 * NOMBRE: RAFAEL FARINANGO
 */


#include <MsTimer2.h>
#include <LiquidCrystal.h>

LiquidCrystal lcd(13,12,11,10,9,8);

int segundos = 0;
int minutos = 0;
int horas = 0;


void setup() {
  lcd.begin(20,4);
  MsTimer2::set(1000,reloj);
  MsTimer2::start();
  lcd.setCursor(0,0);
  lcd.print(" SISTEMAS EMBEBIDOS");
  lcd.setCursor(0,1);
  lcd.print("  RAFAEL FARINANGO");
  lcd.setCursor(0,2);
  lcd.print("    hora:min:seg");
}


void loop() {
  // put your main code here, to run repeatedly:

}


void reloj(){
  if(segundos < 59){
    segundos++;
  }
  else{
    segundos = 0;
    if(minutos < 59){
      minutos++;
    }
    else{
      minutos = 0;
       if(horas < 223)
          horas++;
       else
          horas = 0;
    }
  }
  //lcd.clear();
  lcd.setCursor(7,3);
  lcd.print(String(horas)+String(": ")+String(minutos)+String(" :")+String(segundos));
}
