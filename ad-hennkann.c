/*
 * ad_hennkann.c
 *
 * Created: 2012/06/19 14:17:31
 *  Author: Administrator
 */ 

#include <avr/io.h>
#include <avr/iom168.h>

int main( void )
{
	int i,ad1,ad2;

	DDRD=0b01100001;
	DDRB=0b00000010;
	DDRC=0b00000000;
	ADCSRA=0B10000110; //CK/64
	
	while(1){
		ADMUX=0B01100000; //AVCCが基準電圧Vref=2.56V Left Adjust ADC0(PC0)
//		for(i=0;i<100;i++)
//		;
		ADCSRA |= 1<<ADSC;  //AD start
		while(!(ADCSRA & (1<<ADIF))){} //ADCSRのビット4(ADIF)が1になるまで待つ
		ad1=ADCH;
		
		ADMUX=0B01100001; //AVCCが基準電圧Vref=2.56V Left Adjust ADC0(PC0)
//		for(i=0;i<100;i++)
//		;
		ADCSRA |= 1<<ADSC;  //AD start
		while(!(ADCSRA & (1<<ADIF))){} //ADCSRのビット4(ADIF)が1になるまで待つ
		ad2=ADCH;
	
		PORTD = 0b00000000;  //PD0セット
		PORTB = 0b00000000;
	
	//	for(i=0;i<256;i++){
			if((ad1<=255) && (ad1>200)){
				PORTD = 0b00100000;
			}
			else if ((ad1<55) && (ad1>=0)){
				PORTD = 0b01000000;
			}	
			if((ad2<=255) && (ad2>200)){
				PORTB = 0b00000010;
			}
			else if((ad2<55) && (ad2>=0)){
				PORTD = 0b01100000;
				PORTB = 0b00000010;
			}	
	//	}
	}
}
	
