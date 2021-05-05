//AD1DA2PmodPT Example  ECE3622  c2021 Dennis Silage

#include "xparameters.h"
#include "xil_io.h"
#include <stdio.h>
#include "platform.h"
#include "xil_printf.h"
#include "sleep.h"

//AD1Pmod from Address Editor in Vivado, first IP
#define AD1acq 	0x43C00000	//AD1 acquisition    - output
#define AD1dav 	0x43C00004	//AD1 data available - input
#define AD1dat1	0x43C00008	//AD1 channel 1 data - input 
#define AD1dat2	0x43C0000C	//AD1 channel 2 data - input

//DAC2Pmod from Address Editor in Vivado, second IP
#define DA2acq  0x43C10000   	//DA2 acquisition    - output
#define DA2dav	0x43C10004	//DA2 data available - input
#define DA2dat1	0x43C10008   	//DA2 channel 1 data - output
#define DA2dat2 0x43C1000C	//DA2 channel 2 data - output

int main(void)
{
	int adcdav;		//ADC data available
	int adcdata1;		//ADC channel 1 data
	int	adcdata2;	//ADC channel 2 data

	int dacdata1;		//DAC channel 1 data
	int dacdata2;		//DAC channel 2 data
	int dacdav;		//DAC data available

	xil_printf("\n\rStarting AD1-DA2 Pmod demo test...\n");
	Xil_Out32(AD1acq, 0);		//ADC stop acquire
	adcdav = Xil_In32(AD1dav);	//ADC available?
	while (adcdav == 1)
		adcdav = Xil_In32(AD1dav);
	Xil_Out32(DA2acq, 0);		//DAC stop acquire
	dacdav = Xil_In32(DA2dav);	//DAC available?
	while (dacdav == 1)
		dacdav = Xil_In32(DA2dav);

	while (1)
	{
		//ADC
		Xil_Out32(AD1acq, 1); 		//ADC acquire
		while (adcdav == 0)		//ADC data available?
			adcdav = Xil_In32(AD1dav);
		Xil_Out32(AD1acq, 0);		//ADC stop acquire
		adcdata1 = Xil_In32(AD1dat1);	//input ADC data
		adcdata2 = Xil_In32(AD1dat2);
		while (adcdav == 1)		//wait for reset
			adcdav = Xil_In32(AD1dav);

		dacdata1 = adcdata1;		//ADC -> DAC pass through
		dacdata2 = adcdata2;

		//DAC
		Xil_Out32(DA2dat1, dacdata1);	//output DAC data
		Xil_Out32(DA2dat2, dacdata2);
		Xil_Out32(DA2acq, 1);		//DAC acquire
		while (dacdav == 0)		//DAC data output?
			dacdav = Xil_In32(DA2dav);
		Xil_Out32(DA2acq, 0);		//stop DAC acquire
		while (dacdav == 1)		//wait for reset
			dacdav = Xil_In32(DA2dav);
	}
}