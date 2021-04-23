#include <main.h>
#include <lcd.c>
#use standard_io(a)
#use standard_io(b)
void main(){
   lcd_init();
   set_tris_a(0b11110000);
   set_tris_b(0b00010000);
   int steps[4]={0b00000001,0b00000010,0b00000100,0b00001000};
   while(TRUE){
      if (input(PIN_A4)==1){
         lcd_gotoxy(1,1);
         printf(lcd_putc,"Motor encendido");
         lcd_gotoxy(1,2);
         printf(lcd_putc,"Giro a la derecha");
         for (int i=0; i<4; i++){
            output_a(steps[i]);
            delay_ms(10);
         }
      }
      else if (input(PIN_B3)==1){
         lcd_gotoxy(1,1);
         printf(lcd_putc,"Motor encendido");
         lcd_gotoxy(1,2);
         printf(lcd_putc,"Giro a la izquierda");
         for (int j=4; j>=1; j--){
            output_a(steps[j-1]);
            delay_ms(10);
         }
      } 
      else{
         lcd_gotoxy(1,1);
         printf(lcd_putc,"\fMotor apagado");
         delay_ms(200);
      }
   }
}
