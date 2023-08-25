#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Include project Makefile
ifeq "${IGNORE_LOCAL}" "TRUE"
# do not include local makefile. User is passing all local related variables already
else
include Makefile
# Include makefile containing local settings
ifeq "$(wildcard nbproject/Makefile-local-default.mk)" "nbproject/Makefile-local-default.mk"
include nbproject/Makefile-local-default.mk
endif
endif

# Environment
MKDIR=gnumkdir -p
RM=rm -f 
MV=mv 
CP=cp 

# Macros
CND_CONF=default
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
IMAGE_TYPE=debug
OUTPUT_SUFFIX=elf
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=${DISTDIR}/PIC18f_lib.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=${DISTDIR}/PIC18f_lib.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
endif

ifeq ($(COMPARE_BUILD), true)
COMPARISON_BUILD=-mafrlcsj
else
COMPARISON_BUILD=
endif

# Object Directory
OBJECTDIR=build/${CND_CONF}/${IMAGE_TYPE}

# Distribution Directory
DISTDIR=dist/${CND_CONF}/${IMAGE_TYPE}

# Source Files Quoted if spaced
SOURCEFILES_QUOTED_IF_SPACED=ECU_Layer/button/button.c ECU_Layer/chr_lcd/chr_lcd.c ECU_Layer/dc_motor/dc_motor.c ECU_Layer/keypad/keypad.c ECU_Layer/LED/LED.c ECU_Layer/relay/relay.c ECU_Layer/seven_segment/seven_segment.c ECU_Layer/ecu_int.c MCAL_Layer/ADC/ADC.c MCAL_Layer/ccp1/ccp1.c MCAL_Layer/ccp2/ccp2.c MCAL_Layer/EUSART/eusart.c MCAL_Layer/GPIO/GPIO.c MCAL_Layer/I2C/I2C.c MCAL_Layer/Internal_EEPROM/Internal_EEPROM.c MCAL_Layer/Interrupt/Interrupt_managment.c MCAL_Layer/Interrupt/Interrupt_internal.c MCAL_Layer/Interrupt/Interrupt_external.c MCAL_Layer/Timer/timer0.c MCAL_Layer/Timer1/timer1.c MCAL_Layer/Timer2/timer2.c MCAL_Layer/Timer3/timer3.c MCAL_Layer/device_config.c Application.c MCAL_Layer/SPI/SPI.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/ECU_Layer/button/button.p1 ${OBJECTDIR}/ECU_Layer/chr_lcd/chr_lcd.p1 ${OBJECTDIR}/ECU_Layer/dc_motor/dc_motor.p1 ${OBJECTDIR}/ECU_Layer/keypad/keypad.p1 ${OBJECTDIR}/ECU_Layer/LED/LED.p1 ${OBJECTDIR}/ECU_Layer/relay/relay.p1 ${OBJECTDIR}/ECU_Layer/seven_segment/seven_segment.p1 ${OBJECTDIR}/ECU_Layer/ecu_int.p1 ${OBJECTDIR}/MCAL_Layer/ADC/ADC.p1 ${OBJECTDIR}/MCAL_Layer/ccp1/ccp1.p1 ${OBJECTDIR}/MCAL_Layer/ccp2/ccp2.p1 ${OBJECTDIR}/MCAL_Layer/EUSART/eusart.p1 ${OBJECTDIR}/MCAL_Layer/GPIO/GPIO.p1 ${OBJECTDIR}/MCAL_Layer/I2C/I2C.p1 ${OBJECTDIR}/MCAL_Layer/Internal_EEPROM/Internal_EEPROM.p1 ${OBJECTDIR}/MCAL_Layer/Interrupt/Interrupt_managment.p1 ${OBJECTDIR}/MCAL_Layer/Interrupt/Interrupt_internal.p1 ${OBJECTDIR}/MCAL_Layer/Interrupt/Interrupt_external.p1 ${OBJECTDIR}/MCAL_Layer/Timer/timer0.p1 ${OBJECTDIR}/MCAL_Layer/Timer1/timer1.p1 ${OBJECTDIR}/MCAL_Layer/Timer2/timer2.p1 ${OBJECTDIR}/MCAL_Layer/Timer3/timer3.p1 ${OBJECTDIR}/MCAL_Layer/device_config.p1 ${OBJECTDIR}/Application.p1 ${OBJECTDIR}/MCAL_Layer/SPI/SPI.p1
POSSIBLE_DEPFILES=${OBJECTDIR}/ECU_Layer/button/button.p1.d ${OBJECTDIR}/ECU_Layer/chr_lcd/chr_lcd.p1.d ${OBJECTDIR}/ECU_Layer/dc_motor/dc_motor.p1.d ${OBJECTDIR}/ECU_Layer/keypad/keypad.p1.d ${OBJECTDIR}/ECU_Layer/LED/LED.p1.d ${OBJECTDIR}/ECU_Layer/relay/relay.p1.d ${OBJECTDIR}/ECU_Layer/seven_segment/seven_segment.p1.d ${OBJECTDIR}/ECU_Layer/ecu_int.p1.d ${OBJECTDIR}/MCAL_Layer/ADC/ADC.p1.d ${OBJECTDIR}/MCAL_Layer/ccp1/ccp1.p1.d ${OBJECTDIR}/MCAL_Layer/ccp2/ccp2.p1.d ${OBJECTDIR}/MCAL_Layer/EUSART/eusart.p1.d ${OBJECTDIR}/MCAL_Layer/GPIO/GPIO.p1.d ${OBJECTDIR}/MCAL_Layer/I2C/I2C.p1.d ${OBJECTDIR}/MCAL_Layer/Internal_EEPROM/Internal_EEPROM.p1.d ${OBJECTDIR}/MCAL_Layer/Interrupt/Interrupt_managment.p1.d ${OBJECTDIR}/MCAL_Layer/Interrupt/Interrupt_internal.p1.d ${OBJECTDIR}/MCAL_Layer/Interrupt/Interrupt_external.p1.d ${OBJECTDIR}/MCAL_Layer/Timer/timer0.p1.d ${OBJECTDIR}/MCAL_Layer/Timer1/timer1.p1.d ${OBJECTDIR}/MCAL_Layer/Timer2/timer2.p1.d ${OBJECTDIR}/MCAL_Layer/Timer3/timer3.p1.d ${OBJECTDIR}/MCAL_Layer/device_config.p1.d ${OBJECTDIR}/Application.p1.d ${OBJECTDIR}/MCAL_Layer/SPI/SPI.p1.d

# Object Files
OBJECTFILES=${OBJECTDIR}/ECU_Layer/button/button.p1 ${OBJECTDIR}/ECU_Layer/chr_lcd/chr_lcd.p1 ${OBJECTDIR}/ECU_Layer/dc_motor/dc_motor.p1 ${OBJECTDIR}/ECU_Layer/keypad/keypad.p1 ${OBJECTDIR}/ECU_Layer/LED/LED.p1 ${OBJECTDIR}/ECU_Layer/relay/relay.p1 ${OBJECTDIR}/ECU_Layer/seven_segment/seven_segment.p1 ${OBJECTDIR}/ECU_Layer/ecu_int.p1 ${OBJECTDIR}/MCAL_Layer/ADC/ADC.p1 ${OBJECTDIR}/MCAL_Layer/ccp1/ccp1.p1 ${OBJECTDIR}/MCAL_Layer/ccp2/ccp2.p1 ${OBJECTDIR}/MCAL_Layer/EUSART/eusart.p1 ${OBJECTDIR}/MCAL_Layer/GPIO/GPIO.p1 ${OBJECTDIR}/MCAL_Layer/I2C/I2C.p1 ${OBJECTDIR}/MCAL_Layer/Internal_EEPROM/Internal_EEPROM.p1 ${OBJECTDIR}/MCAL_Layer/Interrupt/Interrupt_managment.p1 ${OBJECTDIR}/MCAL_Layer/Interrupt/Interrupt_internal.p1 ${OBJECTDIR}/MCAL_Layer/Interrupt/Interrupt_external.p1 ${OBJECTDIR}/MCAL_Layer/Timer/timer0.p1 ${OBJECTDIR}/MCAL_Layer/Timer1/timer1.p1 ${OBJECTDIR}/MCAL_Layer/Timer2/timer2.p1 ${OBJECTDIR}/MCAL_Layer/Timer3/timer3.p1 ${OBJECTDIR}/MCAL_Layer/device_config.p1 ${OBJECTDIR}/Application.p1 ${OBJECTDIR}/MCAL_Layer/SPI/SPI.p1

# Source Files
SOURCEFILES=ECU_Layer/button/button.c ECU_Layer/chr_lcd/chr_lcd.c ECU_Layer/dc_motor/dc_motor.c ECU_Layer/keypad/keypad.c ECU_Layer/LED/LED.c ECU_Layer/relay/relay.c ECU_Layer/seven_segment/seven_segment.c ECU_Layer/ecu_int.c MCAL_Layer/ADC/ADC.c MCAL_Layer/ccp1/ccp1.c MCAL_Layer/ccp2/ccp2.c MCAL_Layer/EUSART/eusart.c MCAL_Layer/GPIO/GPIO.c MCAL_Layer/I2C/I2C.c MCAL_Layer/Internal_EEPROM/Internal_EEPROM.c MCAL_Layer/Interrupt/Interrupt_managment.c MCAL_Layer/Interrupt/Interrupt_internal.c MCAL_Layer/Interrupt/Interrupt_external.c MCAL_Layer/Timer/timer0.c MCAL_Layer/Timer1/timer1.c MCAL_Layer/Timer2/timer2.c MCAL_Layer/Timer3/timer3.c MCAL_Layer/device_config.c Application.c MCAL_Layer/SPI/SPI.c



CFLAGS=
ASFLAGS=
LDLIBSOPTIONS=

############# Tool locations ##########################################
# If you copy a project from one host to another, the path where the  #
# compiler is installed may be different.                             #
# If you open this project with MPLAB X in the new host, this         #
# makefile will be regenerated and the paths will be corrected.       #
#######################################################################
# fixDeps replaces a bunch of sed/cat/printf statements that slow down the build
FIXDEPS=fixDeps

.build-conf:  ${BUILD_SUBPROJECTS}
ifneq ($(INFORMATION_MESSAGE), )
	@echo $(INFORMATION_MESSAGE)
endif
	${MAKE}  -f nbproject/Makefile-default.mk ${DISTDIR}/PIC18f_lib.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=18F4620
# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/ECU_Layer/button/button.p1: ECU_Layer/button/button.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECU_Layer/button" 
	@${RM} ${OBJECTDIR}/ECU_Layer/button/button.p1.d 
	@${RM} ${OBJECTDIR}/ECU_Layer/button/button.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECU_Layer/button/button.p1 ECU_Layer/button/button.c 
	@-${MV} ${OBJECTDIR}/ECU_Layer/button/button.d ${OBJECTDIR}/ECU_Layer/button/button.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECU_Layer/button/button.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ECU_Layer/chr_lcd/chr_lcd.p1: ECU_Layer/chr_lcd/chr_lcd.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECU_Layer/chr_lcd" 
	@${RM} ${OBJECTDIR}/ECU_Layer/chr_lcd/chr_lcd.p1.d 
	@${RM} ${OBJECTDIR}/ECU_Layer/chr_lcd/chr_lcd.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECU_Layer/chr_lcd/chr_lcd.p1 ECU_Layer/chr_lcd/chr_lcd.c 
	@-${MV} ${OBJECTDIR}/ECU_Layer/chr_lcd/chr_lcd.d ${OBJECTDIR}/ECU_Layer/chr_lcd/chr_lcd.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECU_Layer/chr_lcd/chr_lcd.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ECU_Layer/dc_motor/dc_motor.p1: ECU_Layer/dc_motor/dc_motor.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECU_Layer/dc_motor" 
	@${RM} ${OBJECTDIR}/ECU_Layer/dc_motor/dc_motor.p1.d 
	@${RM} ${OBJECTDIR}/ECU_Layer/dc_motor/dc_motor.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECU_Layer/dc_motor/dc_motor.p1 ECU_Layer/dc_motor/dc_motor.c 
	@-${MV} ${OBJECTDIR}/ECU_Layer/dc_motor/dc_motor.d ${OBJECTDIR}/ECU_Layer/dc_motor/dc_motor.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECU_Layer/dc_motor/dc_motor.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ECU_Layer/keypad/keypad.p1: ECU_Layer/keypad/keypad.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECU_Layer/keypad" 
	@${RM} ${OBJECTDIR}/ECU_Layer/keypad/keypad.p1.d 
	@${RM} ${OBJECTDIR}/ECU_Layer/keypad/keypad.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECU_Layer/keypad/keypad.p1 ECU_Layer/keypad/keypad.c 
	@-${MV} ${OBJECTDIR}/ECU_Layer/keypad/keypad.d ${OBJECTDIR}/ECU_Layer/keypad/keypad.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECU_Layer/keypad/keypad.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ECU_Layer/LED/LED.p1: ECU_Layer/LED/LED.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECU_Layer/LED" 
	@${RM} ${OBJECTDIR}/ECU_Layer/LED/LED.p1.d 
	@${RM} ${OBJECTDIR}/ECU_Layer/LED/LED.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECU_Layer/LED/LED.p1 ECU_Layer/LED/LED.c 
	@-${MV} ${OBJECTDIR}/ECU_Layer/LED/LED.d ${OBJECTDIR}/ECU_Layer/LED/LED.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECU_Layer/LED/LED.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ECU_Layer/relay/relay.p1: ECU_Layer/relay/relay.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECU_Layer/relay" 
	@${RM} ${OBJECTDIR}/ECU_Layer/relay/relay.p1.d 
	@${RM} ${OBJECTDIR}/ECU_Layer/relay/relay.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECU_Layer/relay/relay.p1 ECU_Layer/relay/relay.c 
	@-${MV} ${OBJECTDIR}/ECU_Layer/relay/relay.d ${OBJECTDIR}/ECU_Layer/relay/relay.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECU_Layer/relay/relay.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ECU_Layer/seven_segment/seven_segment.p1: ECU_Layer/seven_segment/seven_segment.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECU_Layer/seven_segment" 
	@${RM} ${OBJECTDIR}/ECU_Layer/seven_segment/seven_segment.p1.d 
	@${RM} ${OBJECTDIR}/ECU_Layer/seven_segment/seven_segment.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECU_Layer/seven_segment/seven_segment.p1 ECU_Layer/seven_segment/seven_segment.c 
	@-${MV} ${OBJECTDIR}/ECU_Layer/seven_segment/seven_segment.d ${OBJECTDIR}/ECU_Layer/seven_segment/seven_segment.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECU_Layer/seven_segment/seven_segment.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ECU_Layer/ecu_int.p1: ECU_Layer/ecu_int.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECU_Layer" 
	@${RM} ${OBJECTDIR}/ECU_Layer/ecu_int.p1.d 
	@${RM} ${OBJECTDIR}/ECU_Layer/ecu_int.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECU_Layer/ecu_int.p1 ECU_Layer/ecu_int.c 
	@-${MV} ${OBJECTDIR}/ECU_Layer/ecu_int.d ${OBJECTDIR}/ECU_Layer/ecu_int.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECU_Layer/ecu_int.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_Layer/ADC/ADC.p1: MCAL_Layer/ADC/ADC.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_Layer/ADC" 
	@${RM} ${OBJECTDIR}/MCAL_Layer/ADC/ADC.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_Layer/ADC/ADC.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL_Layer/ADC/ADC.p1 MCAL_Layer/ADC/ADC.c 
	@-${MV} ${OBJECTDIR}/MCAL_Layer/ADC/ADC.d ${OBJECTDIR}/MCAL_Layer/ADC/ADC.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_Layer/ADC/ADC.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_Layer/ccp1/ccp1.p1: MCAL_Layer/ccp1/ccp1.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_Layer/ccp1" 
	@${RM} ${OBJECTDIR}/MCAL_Layer/ccp1/ccp1.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_Layer/ccp1/ccp1.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL_Layer/ccp1/ccp1.p1 MCAL_Layer/ccp1/ccp1.c 
	@-${MV} ${OBJECTDIR}/MCAL_Layer/ccp1/ccp1.d ${OBJECTDIR}/MCAL_Layer/ccp1/ccp1.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_Layer/ccp1/ccp1.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_Layer/ccp2/ccp2.p1: MCAL_Layer/ccp2/ccp2.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_Layer/ccp2" 
	@${RM} ${OBJECTDIR}/MCAL_Layer/ccp2/ccp2.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_Layer/ccp2/ccp2.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL_Layer/ccp2/ccp2.p1 MCAL_Layer/ccp2/ccp2.c 
	@-${MV} ${OBJECTDIR}/MCAL_Layer/ccp2/ccp2.d ${OBJECTDIR}/MCAL_Layer/ccp2/ccp2.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_Layer/ccp2/ccp2.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_Layer/EUSART/eusart.p1: MCAL_Layer/EUSART/eusart.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_Layer/EUSART" 
	@${RM} ${OBJECTDIR}/MCAL_Layer/EUSART/eusart.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_Layer/EUSART/eusart.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL_Layer/EUSART/eusart.p1 MCAL_Layer/EUSART/eusart.c 
	@-${MV} ${OBJECTDIR}/MCAL_Layer/EUSART/eusart.d ${OBJECTDIR}/MCAL_Layer/EUSART/eusart.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_Layer/EUSART/eusart.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_Layer/GPIO/GPIO.p1: MCAL_Layer/GPIO/GPIO.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_Layer/GPIO" 
	@${RM} ${OBJECTDIR}/MCAL_Layer/GPIO/GPIO.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_Layer/GPIO/GPIO.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL_Layer/GPIO/GPIO.p1 MCAL_Layer/GPIO/GPIO.c 
	@-${MV} ${OBJECTDIR}/MCAL_Layer/GPIO/GPIO.d ${OBJECTDIR}/MCAL_Layer/GPIO/GPIO.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_Layer/GPIO/GPIO.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_Layer/I2C/I2C.p1: MCAL_Layer/I2C/I2C.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_Layer/I2C" 
	@${RM} ${OBJECTDIR}/MCAL_Layer/I2C/I2C.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_Layer/I2C/I2C.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL_Layer/I2C/I2C.p1 MCAL_Layer/I2C/I2C.c 
	@-${MV} ${OBJECTDIR}/MCAL_Layer/I2C/I2C.d ${OBJECTDIR}/MCAL_Layer/I2C/I2C.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_Layer/I2C/I2C.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_Layer/Internal_EEPROM/Internal_EEPROM.p1: MCAL_Layer/Internal_EEPROM/Internal_EEPROM.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_Layer/Internal_EEPROM" 
	@${RM} ${OBJECTDIR}/MCAL_Layer/Internal_EEPROM/Internal_EEPROM.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_Layer/Internal_EEPROM/Internal_EEPROM.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL_Layer/Internal_EEPROM/Internal_EEPROM.p1 MCAL_Layer/Internal_EEPROM/Internal_EEPROM.c 
	@-${MV} ${OBJECTDIR}/MCAL_Layer/Internal_EEPROM/Internal_EEPROM.d ${OBJECTDIR}/MCAL_Layer/Internal_EEPROM/Internal_EEPROM.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_Layer/Internal_EEPROM/Internal_EEPROM.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_Layer/Interrupt/Interrupt_managment.p1: MCAL_Layer/Interrupt/Interrupt_managment.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_Layer/Interrupt" 
	@${RM} ${OBJECTDIR}/MCAL_Layer/Interrupt/Interrupt_managment.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_Layer/Interrupt/Interrupt_managment.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL_Layer/Interrupt/Interrupt_managment.p1 MCAL_Layer/Interrupt/Interrupt_managment.c 
	@-${MV} ${OBJECTDIR}/MCAL_Layer/Interrupt/Interrupt_managment.d ${OBJECTDIR}/MCAL_Layer/Interrupt/Interrupt_managment.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_Layer/Interrupt/Interrupt_managment.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_Layer/Interrupt/Interrupt_internal.p1: MCAL_Layer/Interrupt/Interrupt_internal.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_Layer/Interrupt" 
	@${RM} ${OBJECTDIR}/MCAL_Layer/Interrupt/Interrupt_internal.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_Layer/Interrupt/Interrupt_internal.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL_Layer/Interrupt/Interrupt_internal.p1 MCAL_Layer/Interrupt/Interrupt_internal.c 
	@-${MV} ${OBJECTDIR}/MCAL_Layer/Interrupt/Interrupt_internal.d ${OBJECTDIR}/MCAL_Layer/Interrupt/Interrupt_internal.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_Layer/Interrupt/Interrupt_internal.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_Layer/Interrupt/Interrupt_external.p1: MCAL_Layer/Interrupt/Interrupt_external.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_Layer/Interrupt" 
	@${RM} ${OBJECTDIR}/MCAL_Layer/Interrupt/Interrupt_external.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_Layer/Interrupt/Interrupt_external.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL_Layer/Interrupt/Interrupt_external.p1 MCAL_Layer/Interrupt/Interrupt_external.c 
	@-${MV} ${OBJECTDIR}/MCAL_Layer/Interrupt/Interrupt_external.d ${OBJECTDIR}/MCAL_Layer/Interrupt/Interrupt_external.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_Layer/Interrupt/Interrupt_external.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_Layer/Timer/timer0.p1: MCAL_Layer/Timer/timer0.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_Layer/Timer" 
	@${RM} ${OBJECTDIR}/MCAL_Layer/Timer/timer0.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_Layer/Timer/timer0.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL_Layer/Timer/timer0.p1 MCAL_Layer/Timer/timer0.c 
	@-${MV} ${OBJECTDIR}/MCAL_Layer/Timer/timer0.d ${OBJECTDIR}/MCAL_Layer/Timer/timer0.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_Layer/Timer/timer0.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_Layer/Timer1/timer1.p1: MCAL_Layer/Timer1/timer1.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_Layer/Timer1" 
	@${RM} ${OBJECTDIR}/MCAL_Layer/Timer1/timer1.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_Layer/Timer1/timer1.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL_Layer/Timer1/timer1.p1 MCAL_Layer/Timer1/timer1.c 
	@-${MV} ${OBJECTDIR}/MCAL_Layer/Timer1/timer1.d ${OBJECTDIR}/MCAL_Layer/Timer1/timer1.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_Layer/Timer1/timer1.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_Layer/Timer2/timer2.p1: MCAL_Layer/Timer2/timer2.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_Layer/Timer2" 
	@${RM} ${OBJECTDIR}/MCAL_Layer/Timer2/timer2.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_Layer/Timer2/timer2.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL_Layer/Timer2/timer2.p1 MCAL_Layer/Timer2/timer2.c 
	@-${MV} ${OBJECTDIR}/MCAL_Layer/Timer2/timer2.d ${OBJECTDIR}/MCAL_Layer/Timer2/timer2.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_Layer/Timer2/timer2.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_Layer/Timer3/timer3.p1: MCAL_Layer/Timer3/timer3.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_Layer/Timer3" 
	@${RM} ${OBJECTDIR}/MCAL_Layer/Timer3/timer3.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_Layer/Timer3/timer3.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL_Layer/Timer3/timer3.p1 MCAL_Layer/Timer3/timer3.c 
	@-${MV} ${OBJECTDIR}/MCAL_Layer/Timer3/timer3.d ${OBJECTDIR}/MCAL_Layer/Timer3/timer3.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_Layer/Timer3/timer3.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_Layer/device_config.p1: MCAL_Layer/device_config.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_Layer" 
	@${RM} ${OBJECTDIR}/MCAL_Layer/device_config.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_Layer/device_config.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL_Layer/device_config.p1 MCAL_Layer/device_config.c 
	@-${MV} ${OBJECTDIR}/MCAL_Layer/device_config.d ${OBJECTDIR}/MCAL_Layer/device_config.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_Layer/device_config.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/Application.p1: Application.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/Application.p1.d 
	@${RM} ${OBJECTDIR}/Application.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/Application.p1 Application.c 
	@-${MV} ${OBJECTDIR}/Application.d ${OBJECTDIR}/Application.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/Application.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_Layer/SPI/SPI.p1: MCAL_Layer/SPI/SPI.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_Layer/SPI" 
	@${RM} ${OBJECTDIR}/MCAL_Layer/SPI/SPI.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_Layer/SPI/SPI.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL_Layer/SPI/SPI.p1 MCAL_Layer/SPI/SPI.c 
	@-${MV} ${OBJECTDIR}/MCAL_Layer/SPI/SPI.d ${OBJECTDIR}/MCAL_Layer/SPI/SPI.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_Layer/SPI/SPI.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
else
${OBJECTDIR}/ECU_Layer/button/button.p1: ECU_Layer/button/button.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECU_Layer/button" 
	@${RM} ${OBJECTDIR}/ECU_Layer/button/button.p1.d 
	@${RM} ${OBJECTDIR}/ECU_Layer/button/button.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECU_Layer/button/button.p1 ECU_Layer/button/button.c 
	@-${MV} ${OBJECTDIR}/ECU_Layer/button/button.d ${OBJECTDIR}/ECU_Layer/button/button.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECU_Layer/button/button.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ECU_Layer/chr_lcd/chr_lcd.p1: ECU_Layer/chr_lcd/chr_lcd.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECU_Layer/chr_lcd" 
	@${RM} ${OBJECTDIR}/ECU_Layer/chr_lcd/chr_lcd.p1.d 
	@${RM} ${OBJECTDIR}/ECU_Layer/chr_lcd/chr_lcd.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECU_Layer/chr_lcd/chr_lcd.p1 ECU_Layer/chr_lcd/chr_lcd.c 
	@-${MV} ${OBJECTDIR}/ECU_Layer/chr_lcd/chr_lcd.d ${OBJECTDIR}/ECU_Layer/chr_lcd/chr_lcd.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECU_Layer/chr_lcd/chr_lcd.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ECU_Layer/dc_motor/dc_motor.p1: ECU_Layer/dc_motor/dc_motor.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECU_Layer/dc_motor" 
	@${RM} ${OBJECTDIR}/ECU_Layer/dc_motor/dc_motor.p1.d 
	@${RM} ${OBJECTDIR}/ECU_Layer/dc_motor/dc_motor.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECU_Layer/dc_motor/dc_motor.p1 ECU_Layer/dc_motor/dc_motor.c 
	@-${MV} ${OBJECTDIR}/ECU_Layer/dc_motor/dc_motor.d ${OBJECTDIR}/ECU_Layer/dc_motor/dc_motor.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECU_Layer/dc_motor/dc_motor.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ECU_Layer/keypad/keypad.p1: ECU_Layer/keypad/keypad.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECU_Layer/keypad" 
	@${RM} ${OBJECTDIR}/ECU_Layer/keypad/keypad.p1.d 
	@${RM} ${OBJECTDIR}/ECU_Layer/keypad/keypad.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECU_Layer/keypad/keypad.p1 ECU_Layer/keypad/keypad.c 
	@-${MV} ${OBJECTDIR}/ECU_Layer/keypad/keypad.d ${OBJECTDIR}/ECU_Layer/keypad/keypad.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECU_Layer/keypad/keypad.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ECU_Layer/LED/LED.p1: ECU_Layer/LED/LED.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECU_Layer/LED" 
	@${RM} ${OBJECTDIR}/ECU_Layer/LED/LED.p1.d 
	@${RM} ${OBJECTDIR}/ECU_Layer/LED/LED.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECU_Layer/LED/LED.p1 ECU_Layer/LED/LED.c 
	@-${MV} ${OBJECTDIR}/ECU_Layer/LED/LED.d ${OBJECTDIR}/ECU_Layer/LED/LED.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECU_Layer/LED/LED.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ECU_Layer/relay/relay.p1: ECU_Layer/relay/relay.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECU_Layer/relay" 
	@${RM} ${OBJECTDIR}/ECU_Layer/relay/relay.p1.d 
	@${RM} ${OBJECTDIR}/ECU_Layer/relay/relay.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECU_Layer/relay/relay.p1 ECU_Layer/relay/relay.c 
	@-${MV} ${OBJECTDIR}/ECU_Layer/relay/relay.d ${OBJECTDIR}/ECU_Layer/relay/relay.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECU_Layer/relay/relay.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ECU_Layer/seven_segment/seven_segment.p1: ECU_Layer/seven_segment/seven_segment.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECU_Layer/seven_segment" 
	@${RM} ${OBJECTDIR}/ECU_Layer/seven_segment/seven_segment.p1.d 
	@${RM} ${OBJECTDIR}/ECU_Layer/seven_segment/seven_segment.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECU_Layer/seven_segment/seven_segment.p1 ECU_Layer/seven_segment/seven_segment.c 
	@-${MV} ${OBJECTDIR}/ECU_Layer/seven_segment/seven_segment.d ${OBJECTDIR}/ECU_Layer/seven_segment/seven_segment.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECU_Layer/seven_segment/seven_segment.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ECU_Layer/ecu_int.p1: ECU_Layer/ecu_int.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECU_Layer" 
	@${RM} ${OBJECTDIR}/ECU_Layer/ecu_int.p1.d 
	@${RM} ${OBJECTDIR}/ECU_Layer/ecu_int.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/ECU_Layer/ecu_int.p1 ECU_Layer/ecu_int.c 
	@-${MV} ${OBJECTDIR}/ECU_Layer/ecu_int.d ${OBJECTDIR}/ECU_Layer/ecu_int.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECU_Layer/ecu_int.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_Layer/ADC/ADC.p1: MCAL_Layer/ADC/ADC.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_Layer/ADC" 
	@${RM} ${OBJECTDIR}/MCAL_Layer/ADC/ADC.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_Layer/ADC/ADC.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL_Layer/ADC/ADC.p1 MCAL_Layer/ADC/ADC.c 
	@-${MV} ${OBJECTDIR}/MCAL_Layer/ADC/ADC.d ${OBJECTDIR}/MCAL_Layer/ADC/ADC.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_Layer/ADC/ADC.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_Layer/ccp1/ccp1.p1: MCAL_Layer/ccp1/ccp1.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_Layer/ccp1" 
	@${RM} ${OBJECTDIR}/MCAL_Layer/ccp1/ccp1.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_Layer/ccp1/ccp1.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL_Layer/ccp1/ccp1.p1 MCAL_Layer/ccp1/ccp1.c 
	@-${MV} ${OBJECTDIR}/MCAL_Layer/ccp1/ccp1.d ${OBJECTDIR}/MCAL_Layer/ccp1/ccp1.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_Layer/ccp1/ccp1.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_Layer/ccp2/ccp2.p1: MCAL_Layer/ccp2/ccp2.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_Layer/ccp2" 
	@${RM} ${OBJECTDIR}/MCAL_Layer/ccp2/ccp2.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_Layer/ccp2/ccp2.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL_Layer/ccp2/ccp2.p1 MCAL_Layer/ccp2/ccp2.c 
	@-${MV} ${OBJECTDIR}/MCAL_Layer/ccp2/ccp2.d ${OBJECTDIR}/MCAL_Layer/ccp2/ccp2.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_Layer/ccp2/ccp2.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_Layer/EUSART/eusart.p1: MCAL_Layer/EUSART/eusart.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_Layer/EUSART" 
	@${RM} ${OBJECTDIR}/MCAL_Layer/EUSART/eusart.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_Layer/EUSART/eusart.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL_Layer/EUSART/eusart.p1 MCAL_Layer/EUSART/eusart.c 
	@-${MV} ${OBJECTDIR}/MCAL_Layer/EUSART/eusart.d ${OBJECTDIR}/MCAL_Layer/EUSART/eusart.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_Layer/EUSART/eusart.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_Layer/GPIO/GPIO.p1: MCAL_Layer/GPIO/GPIO.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_Layer/GPIO" 
	@${RM} ${OBJECTDIR}/MCAL_Layer/GPIO/GPIO.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_Layer/GPIO/GPIO.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL_Layer/GPIO/GPIO.p1 MCAL_Layer/GPIO/GPIO.c 
	@-${MV} ${OBJECTDIR}/MCAL_Layer/GPIO/GPIO.d ${OBJECTDIR}/MCAL_Layer/GPIO/GPIO.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_Layer/GPIO/GPIO.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_Layer/I2C/I2C.p1: MCAL_Layer/I2C/I2C.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_Layer/I2C" 
	@${RM} ${OBJECTDIR}/MCAL_Layer/I2C/I2C.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_Layer/I2C/I2C.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL_Layer/I2C/I2C.p1 MCAL_Layer/I2C/I2C.c 
	@-${MV} ${OBJECTDIR}/MCAL_Layer/I2C/I2C.d ${OBJECTDIR}/MCAL_Layer/I2C/I2C.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_Layer/I2C/I2C.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_Layer/Internal_EEPROM/Internal_EEPROM.p1: MCAL_Layer/Internal_EEPROM/Internal_EEPROM.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_Layer/Internal_EEPROM" 
	@${RM} ${OBJECTDIR}/MCAL_Layer/Internal_EEPROM/Internal_EEPROM.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_Layer/Internal_EEPROM/Internal_EEPROM.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL_Layer/Internal_EEPROM/Internal_EEPROM.p1 MCAL_Layer/Internal_EEPROM/Internal_EEPROM.c 
	@-${MV} ${OBJECTDIR}/MCAL_Layer/Internal_EEPROM/Internal_EEPROM.d ${OBJECTDIR}/MCAL_Layer/Internal_EEPROM/Internal_EEPROM.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_Layer/Internal_EEPROM/Internal_EEPROM.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_Layer/Interrupt/Interrupt_managment.p1: MCAL_Layer/Interrupt/Interrupt_managment.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_Layer/Interrupt" 
	@${RM} ${OBJECTDIR}/MCAL_Layer/Interrupt/Interrupt_managment.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_Layer/Interrupt/Interrupt_managment.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL_Layer/Interrupt/Interrupt_managment.p1 MCAL_Layer/Interrupt/Interrupt_managment.c 
	@-${MV} ${OBJECTDIR}/MCAL_Layer/Interrupt/Interrupt_managment.d ${OBJECTDIR}/MCAL_Layer/Interrupt/Interrupt_managment.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_Layer/Interrupt/Interrupt_managment.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_Layer/Interrupt/Interrupt_internal.p1: MCAL_Layer/Interrupt/Interrupt_internal.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_Layer/Interrupt" 
	@${RM} ${OBJECTDIR}/MCAL_Layer/Interrupt/Interrupt_internal.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_Layer/Interrupt/Interrupt_internal.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL_Layer/Interrupt/Interrupt_internal.p1 MCAL_Layer/Interrupt/Interrupt_internal.c 
	@-${MV} ${OBJECTDIR}/MCAL_Layer/Interrupt/Interrupt_internal.d ${OBJECTDIR}/MCAL_Layer/Interrupt/Interrupt_internal.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_Layer/Interrupt/Interrupt_internal.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_Layer/Interrupt/Interrupt_external.p1: MCAL_Layer/Interrupt/Interrupt_external.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_Layer/Interrupt" 
	@${RM} ${OBJECTDIR}/MCAL_Layer/Interrupt/Interrupt_external.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_Layer/Interrupt/Interrupt_external.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL_Layer/Interrupt/Interrupt_external.p1 MCAL_Layer/Interrupt/Interrupt_external.c 
	@-${MV} ${OBJECTDIR}/MCAL_Layer/Interrupt/Interrupt_external.d ${OBJECTDIR}/MCAL_Layer/Interrupt/Interrupt_external.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_Layer/Interrupt/Interrupt_external.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_Layer/Timer/timer0.p1: MCAL_Layer/Timer/timer0.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_Layer/Timer" 
	@${RM} ${OBJECTDIR}/MCAL_Layer/Timer/timer0.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_Layer/Timer/timer0.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL_Layer/Timer/timer0.p1 MCAL_Layer/Timer/timer0.c 
	@-${MV} ${OBJECTDIR}/MCAL_Layer/Timer/timer0.d ${OBJECTDIR}/MCAL_Layer/Timer/timer0.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_Layer/Timer/timer0.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_Layer/Timer1/timer1.p1: MCAL_Layer/Timer1/timer1.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_Layer/Timer1" 
	@${RM} ${OBJECTDIR}/MCAL_Layer/Timer1/timer1.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_Layer/Timer1/timer1.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL_Layer/Timer1/timer1.p1 MCAL_Layer/Timer1/timer1.c 
	@-${MV} ${OBJECTDIR}/MCAL_Layer/Timer1/timer1.d ${OBJECTDIR}/MCAL_Layer/Timer1/timer1.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_Layer/Timer1/timer1.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_Layer/Timer2/timer2.p1: MCAL_Layer/Timer2/timer2.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_Layer/Timer2" 
	@${RM} ${OBJECTDIR}/MCAL_Layer/Timer2/timer2.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_Layer/Timer2/timer2.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL_Layer/Timer2/timer2.p1 MCAL_Layer/Timer2/timer2.c 
	@-${MV} ${OBJECTDIR}/MCAL_Layer/Timer2/timer2.d ${OBJECTDIR}/MCAL_Layer/Timer2/timer2.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_Layer/Timer2/timer2.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_Layer/Timer3/timer3.p1: MCAL_Layer/Timer3/timer3.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_Layer/Timer3" 
	@${RM} ${OBJECTDIR}/MCAL_Layer/Timer3/timer3.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_Layer/Timer3/timer3.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL_Layer/Timer3/timer3.p1 MCAL_Layer/Timer3/timer3.c 
	@-${MV} ${OBJECTDIR}/MCAL_Layer/Timer3/timer3.d ${OBJECTDIR}/MCAL_Layer/Timer3/timer3.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_Layer/Timer3/timer3.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_Layer/device_config.p1: MCAL_Layer/device_config.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_Layer" 
	@${RM} ${OBJECTDIR}/MCAL_Layer/device_config.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_Layer/device_config.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL_Layer/device_config.p1 MCAL_Layer/device_config.c 
	@-${MV} ${OBJECTDIR}/MCAL_Layer/device_config.d ${OBJECTDIR}/MCAL_Layer/device_config.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_Layer/device_config.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/Application.p1: Application.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/Application.p1.d 
	@${RM} ${OBJECTDIR}/Application.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/Application.p1 Application.c 
	@-${MV} ${OBJECTDIR}/Application.d ${OBJECTDIR}/Application.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/Application.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_Layer/SPI/SPI.p1: MCAL_Layer/SPI/SPI.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_Layer/SPI" 
	@${RM} ${OBJECTDIR}/MCAL_Layer/SPI/SPI.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_Layer/SPI/SPI.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto:auto     -o ${OBJECTDIR}/MCAL_Layer/SPI/SPI.p1 MCAL_Layer/SPI/SPI.c 
	@-${MV} ${OBJECTDIR}/MCAL_Layer/SPI/SPI.d ${OBJECTDIR}/MCAL_Layer/SPI/SPI.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_Layer/SPI/SPI.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assemble
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assembleWithPreprocess
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${DISTDIR}/PIC18f_lib.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    
	@${MKDIR} ${DISTDIR} 
	${MP_CC} $(MP_EXTRA_LD_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -Wl,-Map=${DISTDIR}/PIC18f_lib.X.${IMAGE_TYPE}.map  -D__DEBUG=1  -mdebugger=none  -DXPRJ_default=$(CND_CONF)  -Wl,--defsym=__MPLAB_BUILD=1   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits -std=c99 -gcoff -mstack=compiled:auto:auto:auto        $(COMPARISON_BUILD) -Wl,--memorysummary,${DISTDIR}/memoryfile.xml -o ${DISTDIR}/PIC18f_lib.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}     
	@${RM} ${DISTDIR}/PIC18f_lib.X.${IMAGE_TYPE}.hex 
	
else
${DISTDIR}/PIC18f_lib.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   
	@${MKDIR} ${DISTDIR} 
	${MP_CC} $(MP_EXTRA_LD_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -Wl,-Map=${DISTDIR}/PIC18f_lib.X.${IMAGE_TYPE}.map  -DXPRJ_default=$(CND_CONF)  -Wl,--defsym=__MPLAB_BUILD=1   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -memi=wordwrite -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-download -mdefault-config-bits -std=c99 -gcoff -mstack=compiled:auto:auto:auto     $(COMPARISON_BUILD) -Wl,--memorysummary,${DISTDIR}/memoryfile.xml -o ${DISTDIR}/PIC18f_lib.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}     
	
endif


# Subprojects
.build-subprojects:


# Subprojects
.clean-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${OBJECTDIR}
	${RM} -r ${DISTDIR}

# Enable dependency checking
.dep.inc: .depcheck-impl

DEPFILES=$(shell mplabwildcard ${POSSIBLE_DEPFILES})
ifneq (${DEPFILES},)
include ${DEPFILES}
endif
