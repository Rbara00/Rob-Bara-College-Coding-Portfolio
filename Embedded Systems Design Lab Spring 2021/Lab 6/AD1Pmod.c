//AD1Pmod.c  PmodAD1 ADC example  ECE3622  c2019 Dennis Silage

#include "xparameters.h"
#include "xil_io.h"
#include <stdio.h>
#include "platform.h"
#include "xil_printf.h"
#include <sleep.h>

//AD1Pmod from Address Editor in Vivado
#define AD1acq 	0x43C00000	//AD1 acquisition
#define AD1dav 	0x43C00004	//AD1 data available
#define AD1dat1	0x43C00008	//AD1 channel 1 data
#define AD1dat2	0x43C0000C	//AD1 channel 2 data

int main(void)
{
	int adcdav;				//ADC data available
	int adcdat1;			//ADC channel 1 data
	int	adcdat2;			//ADC channel 2 data


	xil_printf("\n\rStarting AD1 Pmod demo test...\n");
	Xil_Out32(AD1acq,0);
	sleep(5);

	while (1)
	{
		Xil_Out32(AD1acq,0);			//ADC stop acquire
		adcdav=Xil_In32(AD1dav);		//ADC available?
		while(adcdav==1)
				adcdav=Xil_In32(AD1dav);

		while(1)
			{
				Xil_Out32(AD1acq,1); 	//ADC acquire
				while(adcdav==0)
					adcdav=Xil_In32(AD1dav); //ADC data?
				Xil_Out32(AD1acq,0);	//ADC stop acquire
				adcdat1=Xil_In32(AD1dat1);
				adcdat2=Xil_In32(AD1dat2);
				while(adcdav==1)
					adcdav=Xil_In32(AD1dav); //ADC reset?
				xil_printf("%d  Ch1  %d, Ch2  %d\n", adcdat1, adcdat2);
				sleep(1);
				}
	}
}

