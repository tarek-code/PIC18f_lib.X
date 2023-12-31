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

        /*TIMER0*/
    
    if((INTCONbits.TMR0IE==1) && (INTCONbits.TMR0IF==1)){
        TIMER0_ISR();
        }

    /*TIMER1*/
    
    if((PIE1bits.TMR1IE==1) && (PIR1bits.TMR1IF==1)){
        TIMER1_ISR();
        }

/*TIMER2*/
    
    if((PIE1bits.TMR2IE==1) && (PIR1bits.TMR2IF==1)){
        TIMER2_ISR();
        }

/*TIMER3*/
    
    if((PIE2bits.TMR3IE==1) && (PIR2bits.TMR3IF==1)){
        TIMER3_ISR();
        }
/*CCP1*/
    
    if((PIE1bits.CCP1IE==1) && (PIR1bits.CCP1IF==1)){
        CCP1_ISR();
        }
/*CCP2*/
    
    if((PIE2bits.CCP2IE==1) && (PIR2bits.CCP2IF==1)){
        CCP2_ISR();
        }

            /*eusart_tx*/
    
    if((PIE1bits.TXIE==1) && (PIR1bits.TXIF==1)){
        EUSART_TX_ISR();
        }
 /*eusart_rx*/
    
    if((PIE1bits.RCIE==1) && (PIR1bits.RCIF==1)){
        EUSART_RX_ISR();
        }
 /*eusart_slave*/
    
  //  if((PIE1bits.PSPIE==1) && (PIR1bits.PSPIF==1)){
      //  EUSART_SLAVE_ISR();
   //     }
 /*eusart_master*/
    
   // if((PIE1bits.SSPIE==1) && (PIR1bits.SSPIF==1)){
      //  EUSART_MASTER_ISR();
     //   }

 /*mssp*/
if((PIE1bits.SSPIE==1) && (PIR1bits.SSPIF==1)){
      MSSP_ISR();
        }
if((PIE2bits.BCLIE==1) && (PIR2bits.BCLIF==1)){
      MSSP_BC_ISR();
        }
}
#endif
