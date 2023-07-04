#include "Interrupt_managment.h"

static volatile uint8 flage_4=1;
static volatile uint8 flage_5=1;
static volatile uint8 flage_6=1;
static volatile uint8 flage_7=1;

#if INTERRUPT_PRIORITY_FEATURE == ENABLE_FEATURE

void __interrupt() InterruptManagmentHigh(void){
    if(INTCONbits.INT0IE==1 && INTCONbits.INT0IF==1){
        INT0_ISR();
}
     
    


}

void __interrupt(low_priority) InterruptManagmentLow(void)
{
     if(INTCON3bits.INT1IE==1 && INTCON3bits.INT1IF==1){
        INT1_ISR();
    }
     if(INTCON3bits.INT2IE==1 && INTCON3bits.INT2IF==1){
    INT2_ISR();
    }
     
     /*            onchange external interrupt*/
    if((INTCONbits.RBIE==1 && INTCONbits.RBIF==1)&& (PORTBbits.RB4==1)&&(flage_4==1)){
        flage_4=0;
    RB4_ISR(1);
    }
    if((INTCONbits.RBIE==1 && INTCONbits.RBIF==1)&& (PORTBbits.RB4==0)&&(flage_4==0)){
        flage_4=1;
    RB4_ISR(0);
    }

    

if((INTCONbits.RBIE==1 && INTCONbits.RBIF==1)&& (PORTBbits.RB6==1)&&(flage_6==1)){
        flage_6=0;
    RB6_ISR(1);
    }
    if((INTCONbits.RBIE==1 && INTCONbits.RBIF==1)&& (PORTBbits.RB6==0)&&(flage_6==0)){
        flage_6=1;
    RB6_ISR(0);
    }
     
     if((INTCONbits.RBIE==1 && INTCONbits.RBIF==1)&& (PORTBbits.RB5==1)&&(flage_5==1)){
        flage_5=0;
    RB5_ISR(1);
    }
    if((INTCONbits.RBIE==1 && INTCONbits.RBIF==1)&& (PORTBbits.RB5==0)&&(flage_5==0)){
        flage_5=1;
    RB5_ISR(0);
    }
     
     if((INTCONbits.RBIE==1 && INTCONbits.RBIF==1)&& (PORTBbits.RB7==1)&&(flage_7==1)){
        flage_7=0;
    RB7_ISR(1);
    }
    if((INTCONbits.RBIE==1 && INTCONbits.RBIF==1)&& (PORTBbits.RB7==0)&&(flage_7==0)){
        flage_7=1;
    RB7_ISR(0);
    }
}
#else
void __interrupt() InterruptManagmentHigh(void){
    
 
    
    
    
    
if(INTCONbits.INT0IE==1 && INTCONbits.INT0IF==1){
        INT0_ISR();
}
     if(INTCON3bits.INT1IE==1 && INTCON3bits.INT1IF==1){
        INT1_ISR();
    }
     if(INTCON3bits.INT2IE==1 && INTCON3bits.INT2IF==1){
    INT2_ISR();
    }
/*            onchange external interrupt*/
    if((INTCONbits.RBIE==1 && INTCONbits.RBIF==1)&& (PORTBbits.RB4==1)&&(flage_4==1)){
        flage_4=0;
    RB4_ISR(1);
    }
    if((INTCONbits.RBIE==1 && INTCONbits.RBIF==1)&& (PORTBbits.RB4==0)&&(flage_4==0)){
        flage_4=1;
    RB4_ISR(0);
    }

    if((INTCONbits.RBIE==1 && INTCONbits.RBIF==1)&& (PORTBbits.RB5==1)&&(flage_5==1)){
        flage_5=0;
    RB5_ISR(1);
    }
    if((INTCONbits.RBIE==1 && INTCONbits.RBIF==1)&& (PORTBbits.RB5==0)&&(flage_5==0)){
        flage_5=1;
    RB5_ISR(0);
    }

if((INTCONbits.RBIE==1 && INTCONbits.RBIF==1)&& (PORTBbits.RB6==1)&&(flage_6==1)){
        flage_6=0;
    RB6_ISR(1);
    }
    if((INTCONbits.RBIE==1 && INTCONbits.RBIF==1)&& (PORTBbits.RB6==0)&&(flage_6==0)){
        flage_6=1;
    RB6_ISR(0);
    }

if((INTCONbits.RBIE==1 && INTCONbits.RBIF==1)&& (PORTBbits.RB7==1)&&(flage_7==1)){
        flage_7=0;
    RB7_ISR(1);
    }
    if((INTCONbits.RBIE==1 && INTCONbits.RBIF==1)&& (PORTBbits.RB7==0)&&(flage_7==0)){
        flage_7=1;
    RB7_ISR(0);
    }
     /*ADC*/
    
    if((PIE1bits.ADIE==1) && (PIR1bits.ADIF==1)){
        ADC_ISR();
}
}
#endif
