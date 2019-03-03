#include <18f4550.h>
#DEVICE ADC=8

#fuses NOWDT, NOPROTECT, NOLVP, NODEBUG, HSPLL, PLL5, CPUDIV1
#fuses NOMCLR, VREGEN, USBDIV
#use delay(clock=48000000)
#use rs232(baud=9600, xmit=PIN_C6)

#include <pic18_usb.h>
#include <Descriptor_easyHID.h>
#include <USB.c>

const int8 NDT = 20;

int16 Tmr0_inic;
int8 datos[NDT];
int8 num_dat=0;

#int_rtcc

void ovFlw_Tmr0(){
	set_timer0(Tmr0_inic);
	output_high(PIN_D2);
	datos[num_dat] = read_adc();
	if (num_dat == NDT-1){
		usb_put_packet(1, datos, NDT, USB_DTS_TOGGLE);
		num_dat=0;
	}
	else
		num_dat++;
	output_low(PIN_D2);
}
	
void main(){
	delay_ms(20);
	putc(124); putc(128 + 0); //Backlight
	putc(254);putc(1);
	
	setup_adc(ADC_CLOCK_INTERNAL);
	setup_adc_ports(AN0);
	set_adc_channel(0);
	
	usb_init_cs();
	
	Tmr0_inic = 53584; //mbiando valor original 53536 (Muestras: 996) a 53750(Muestras: 1000)
	setup_timer_0(RTCC_DIV_1);
	set_timer0(Tmr0_inic);
	enable_interrupts(GLOBAL);
	
	while(TRUE){
		usb_task();
		if(usb_enumerated()){
			output_high(PIN_D3);
			enable_interrupts(INT_RTCC);
		}
	}
}