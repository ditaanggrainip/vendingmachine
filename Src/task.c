#include "main.h"
#include "device.h"
#include "hardwareinit.h"
#include "uart.h"

unsigned char Button500(void);
unsigned char Button1000(void);
unsigned char Buttonproses(void);
unsigned char Buttoncancel(void);

#define lamalampu  	1000
#define lamalampu1  800
#define pas500		2
#define pas1000		1
#define maxcoin 	10
#define maxcoin1 	10
#define MerahON   HAL_GPIO_WritePin(led1_GPIO_Port,led1_Pin,GPIO_PIN_SET)
#define MerahOFF  HAL_GPIO_WritePin(led1_GPIO_Port,led1_Pin,GPIO_PIN_RESET)

#define KuningON	  HAL_GPIO_WritePin(led2_GPIO_Port,led2_Pin,GPIO_PIN_SET)
#define KuningOFF  HAL_GPIO_WritePin(led2_GPIO_Port,led2_Pin,GPIO_PIN_RESET)

#define HijauON  HAL_GPIO_WritePin(led3_GPIO_Port,led3_Pin,GPIO_PIN_SET)
#define HijauOFF HAL_GPIO_WritePin(led3_GPIO_Port,led3_Pin,GPIO_PIN_RESET)

#define PutihON  HAL_GPIO_WritePin(led_GPIO_Port,led_Pin,GPIO_PIN_SET)
#define PutihOFF HAL_GPIO_WritePin(led_GPIO_Port,led_Pin,GPIO_PIN_RESET)

#define kembaliON  HAL_GPIO_WritePin(led4_GPIO_Port,led4_Pin,GPIO_PIN_SET)
#define kembaliOFF HAL_GPIO_WritePin(led4_GPIO_Port,led4_Pin,GPIO_PIN_RESET)

#define buzzerON  HAL_GPIO_WritePin(buzzer_GPIO_Port,buzzer_Pin,GPIO_PIN_SET)
#define buzzerOFF HAL_GPIO_WritePin(buzzer_GPIO_Port,buzzer_Pin,GPIO_PIN_RESET)

_Bool delay=0;
_Bool delay_1=0;
_Bool delay_2=0;
_Bool delay1=0;
_Bool delay1_1=0;
_Bool delay2=0;
_Bool delay2_1=0;
_Bool delay3=0;
_Bool delay3_1=0;
_Bool kembali=0;
_Bool kembali_1=0;
_Bool kembali1=0;
_Bool kembali1_1=0;
_Bool selesai =0;
_Bool selesai1 =0;
_Bool selesai2 =0;
#define YES 1
#define NO 0

enum state{st0,st500,st1000,stproses,stcancel,stkembalian,stselesai} kondisi;

uint16_t lama_lampu=0;
unsigned int coin1=0;
unsigned int coin=0;
unsigned int jmlcoin=0;
unsigned int jmlkmbl=0;
unsigned int kmbl = 0;
unsigned int kmbl1 = 0;

unsigned char Button500(void){
	static unsigned char debounce=0xFF;
	unsigned char detectedFLag=0;
	if(HAL_GPIO_ReadPin(btn1_GPIO_Port,btn1_Pin)== GPIO_PIN_RESET){
		debounce=(debounce<<1);
	} else {
		debounce= (debounce<<1)|1;
	}
	if (debounce==0xF0) {
		//		printf("1-OK \n\r");
		//		print_UART2("1-OK",5);
		detectedFLag=1;
	}
	return detectedFLag;
}

unsigned char Button1000(void){
	static unsigned char debounce1=0xFF;
	unsigned char detectedFLag=0;
	if(HAL_GPIO_ReadPin(btn2_GPIO_Port,btn2_Pin)== GPIO_PIN_RESET){
		debounce1=(debounce1<<1);
	} else {
		debounce1= (debounce1<<1)|1;
	}
	if (debounce1==0xF0) {
		//		printf("1-OK \n\r");
		//		print_UART2("1-OK",5);
		detectedFLag=1;
	}
	return detectedFLag;
}

unsigned char Buttonproses(void){
	unsigned char detectedFLag=0;
	static unsigned char debounce2=0xFF;
	if(HAL_GPIO_ReadPin(btn3_GPIO_Port,btn3_Pin)== GPIO_PIN_RESET){
		debounce2=(debounce2<<1);
	} else {
		debounce2= (debounce2<<1)|1;
	}
	if (debounce2==0xF0) {
		//		printf("1-OK \n\r");
		//		print_UART2("1-OK",5);
		detectedFLag=1;
	}
	return detectedFLag;
}

unsigned char Buttoncancel(void){
	static unsigned char debounce3=0xFF;
	unsigned char detectedFLag=0;
	if(HAL_GPIO_ReadPin(btn4_GPIO_Port,btn4_Pin)== GPIO_PIN_RESET){
		debounce3=(debounce3<<1);
	} else {
		debounce3= (debounce3<<1)|1;
	}
	if (debounce3==0xF0) {
		//		printf("1-OK \n\r");
		//				print_UART2("1-OK",5);
		detectedFLag=1;
	}
	return detectedFLag;
}

void task_init(void){
	kondisi=st0;
}

void task_run(void){
	switch(kondisi)
	{
	case st0:
	{
		coin=0;
		coin1=0;
		jmlcoin=0;
		jmlkmbl=0;
		kmbl=0;
		kmbl1=0;
		kondisi=st500;
		break;
	}
	case st500:
	{
		if(Button500()){
//			MerahON;
			delay=1;
			coin=coin+5;
			jmlcoin=coin+coin1;
			myUART_Print("Uang Koin Rp 500");myUART_Print("=	");myUART_Print("Jumlah coin : ");myUART_PrintNum(jmlcoin);myUART_Print("00");myUART_Print("\n");
		}
		if(delay){
			if(++lama_lampu>lamalampu)
			{
//				MerahOFF;
				kondisi=st1000;
				delay=0;
				lama_lampu=0;
			}
		}
		else if(Button1000()){
//			KuningON;
			delay1=1;
			coin1=coin1+10;
			jmlcoin=coin+coin1;
			myUART_Print("Uang Koin Rp 1000");myUART_Print("=	");myUART_Print("Jumlah koin : ");myUART_PrintNum(jmlcoin);myUART_Print("00");myUART_Print("\n");
		}
		if(delay1){
			if(++lama_lampu>lamalampu){
//				KuningOFF;
				kondisi=stproses;
				delay1=0;
				lama_lampu=0;
			}
		}
		break;
	}
	case st1000:
	{
		if(Button500()){
//			MerahON;
			delay=1;
			coin=coin+5;
			jmlcoin=coin+coin1;
			myUART_Print("Uang Koin Rp 500");myUART_Print("=	");myUART_Print("Jumlah koin : ");myUART_PrintNum(jmlcoin);myUART_Print("00");myUART_Print("\n");
		}
		if(delay){
			if(++lama_lampu>lamalampu)
			{
//				MerahOFF;
				kondisi=stproses;
				delay=0;
				kembali=1;
				lama_lampu=0;
			}
		}
		else if(Button1000()){
//			KuningON;
			delay1=1;
			coin1=coin1+10;
			jmlcoin=coin+coin1;
			myUART_Print("Uang Koin Rp 1000");myUART_Print("=	");myUART_Print("Jumlah koin : ");myUART_PrintNum(jmlcoin);myUART_Print("00");myUART_Print("\n");
		}
		if(delay1){
			if(++lama_lampu>lamalampu){
//				KuningOFF;
				kondisi=stkembalian;
				delay1=0;
				kembali=1;
				lama_lampu=0;
			}
		}
		else if(Buttonproses()){
			HijauON;
			delay2=1;
			myUART_Println("Uang Anda Belum Cukup");
		}
		if(delay2){
			if(++lama_lampu>lamalampu){
				HijauOFF;
				kondisi=st1000;
				delay2=0;
			}
		}
		else if(Buttoncancel()){
			MerahON;
			delay3=1;
			myUART_Println("Membatalkan Pesanan Anda");
		}
		if(delay3){
			if(++lama_lampu>lamalampu){
				MerahOFF;
				kondisi=st0;
				delay3=0;
				lama_lampu=0;
			}
		}
		break;
	}
	case stproses:
	{
		if(Button500()){
//			MerahON;
			delay=1;
			coin=coin+5;
			jmlcoin=coin+coin1;
			myUART_Print("Uang Koin Rp 500");myUART_Print("=	");myUART_Print("Jumlah koin : ");myUART_PrintNum(jmlcoin);myUART_Print("00");myUART_Print("\n");
		}
		if(delay){
			if(++lama_lampu>lamalampu)
			{
//				MerahOFF;
				kondisi=stkembalian;
				delay=0;
				kembali=1;
				lama_lampu=0;
			}
		}
		else if(Button1000()){
//			KuningON;
			delay1=1;
			kembali=0;
			coin1=coin1+10;
			jmlcoin=coin+coin1;
			myUART_Print("Uang Koin Rp 1000");myUART_Print("=	");myUART_Print("Jumlah koin : ");myUART_PrintNum(jmlcoin);myUART_Print("00");myUART_Print("\n");
		}
		if(delay1){
			if(++lama_lampu>lamalampu){
//				KuningOFF;
				kondisi=stkembalian;
				delay1=0;
				kembali1=1;
				lama_lampu=0;
			}
		}
		if(Buttonproses()){
			HijauON;
			delay2=1;
			myUART_Println("Memproses Pesanan Anda");
		}
		if(delay2){
			if(++lama_lampu>lamalampu){
				HijauOFF;
				kondisi=stselesai;
				delay2=0;
				selesai=1;
				lama_lampu=0;
			}
		}

		else if(Buttoncancel()){
			KuningON;
			delay3=1;
			myUART_Println("Membatalkan Pesanan Anda");
		}
		if(delay3){
			if(++lama_lampu>lamalampu){
				KuningOFF;
				kondisi=st0;
				delay3=0;
				lama_lampu=0;
			}
		}
		break;
	}
	case stkembalian:
	{
		if(kembali){
			if(++lama_lampu>lamalampu1){
				MerahON;
				delay_1=1;
				kembali=0;
				kmbl=kmbl+5;
				lama_lampu=0;
			}
		}
		if(delay_1){
			if(++lama_lampu>lamalampu){
				MerahOFF;
				delay_1=0;
				lama_lampu=0;
				kondisi=stproses;
			}
		}
		else if(kembali1){
			if(++lama_lampu>lamalampu1){
				KuningON;
				delay2_1=1;
				kembali1=0;
				kmbl1=kmbl1+10;
				lama_lampu=0;
			}
		}
		if(delay2_1){
			if(++lama_lampu>lamalampu){
				KuningOFF;
				delay2_1=0;
				lama_lampu=0;
				kondisi=stproses;
			}
		}
		break;
	}
	case stselesai:
	{
		if(selesai){
			jmlkmbl=kmbl+kmbl1;
			myUART_Print("Jumlah Kembalian Anda = ");myUART_PrintNum(jmlkmbl);myUART_Print("00");myUART_Print("\n");
			myUART_Println("Silahkan Mengambil Pesanan Anda");
			buzzerON;
			kembaliON;
			selesai1=1;
			selesai=0;
		}
		if(selesai1){
			if(++lama_lampu>1000){
				buzzerOFF;
				kembaliOFF;
				selesai1=0;
				lama_lampu=0;
				coin=0;
				coin1=0;
				jmlcoin=0;
				jmlkmbl=0;
				kmbl=0;
				kmbl1=0;
				kondisi=st0;
			}
		}

		break;
	}
	}
}



