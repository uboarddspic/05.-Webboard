#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Include project Makefile
include Makefile

# Environment
MKDIR=mkdir -p
RM=rm -f 
CP=cp 

# Macros
CND_CONF=default
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
IMAGE_TYPE=debug
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/Web_board.X.${IMAGE_TYPE}.elf
else
IMAGE_TYPE=production
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/Web_board.X.${IMAGE_TYPE}.elf
endif

# Object Directory
OBJECTDIR=build/${CND_CONF}/${IMAGE_TYPE}

# Distribution Directory
DISTDIR=dist/${CND_CONF}/${IMAGE_TYPE}

# Object Files
OBJECTFILES=${OBJECTDIR}/_ext/1472/Delay.o ${OBJECTDIR}/_ext/1472/Main.o ${OBJECTDIR}/_ext/1472/Patterns.o ${OBJECTDIR}/_ext/1472/Peripherals.o ${OBJECTDIR}/_ext/1472/Socket.o ${OBJECTDIR}/_ext/1472/W5100.o


CFLAGS=
ASFLAGS=
LDLIBSOPTIONS=

# Path to java used to run MPLAB X when this makefile was created
MP_JAVA_PATH=C:\\Program\ Files\\Java\\jre6/bin/
OS_CURRENT="$(shell uname -s)"
############# Tool locations ##########################################
# If you copy a project from one host to another, the path where the  #
# compiler is installed may be different.                             #
# If you open this project with MPLAB X in the new host, this         #
# makefile will be regenerated and the paths will be corrected.       #
#######################################################################
MP_CC=C:\\Program\ Files\\Microchip\\MPLAB\ C30\\bin\\pic30-gcc.exe
# MP_BC is not defined
MP_AS=C:\\Program\ Files\\Microchip\\MPLAB\ C30\\bin\\pic30-as.exe
MP_LD=C:\\Program\ Files\\Microchip\\MPLAB\ C30\\bin\\pic30-ld.exe
MP_AR=C:\\Program\ Files\\Microchip\\MPLAB\ C30\\bin\\pic30-ar.exe
# MP_BC is not defined
MP_CC_DIR=C:\\Program\ Files\\Microchip\\MPLAB\ C30\\bin
# MP_BC_DIR is not defined
MP_AS_DIR=C:\\Program\ Files\\Microchip\\MPLAB\ C30\\bin
MP_LD_DIR=C:\\Program\ Files\\Microchip\\MPLAB\ C30\\bin
MP_AR_DIR=C:\\Program\ Files\\Microchip\\MPLAB\ C30\\bin
# MP_BC_DIR is not defined

.build-conf: ${BUILD_SUBPROJECTS}
	${MAKE}  -f nbproject/Makefile-default.mk dist/${CND_CONF}/${IMAGE_TYPE}/Web_board.X.${IMAGE_TYPE}.elf

MP_PROCESSOR_OPTION=33FJ64GP802
MP_LINKER_FILE_OPTION=,--script=../p33FJ64GP802.application.gld
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
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/_ext/1472/Delay.o: ../Delay.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1472 
	@${RM} ${OBJECTDIR}/_ext/1472/Delay.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/Delay.o.ok ${OBJECTDIR}/_ext/1472/Delay.o.err 
	@echo ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG  -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -Wall -I".." -MMD -MF ${OBJECTDIR}/_ext/1472/Delay.o.d -o ${OBJECTDIR}/_ext/1472/Delay.o ../Delay.c  
	@-${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG  -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -Wall -I".." -MMD -MF ${OBJECTDIR}/_ext/1472/Delay.o.d -o ${OBJECTDIR}/_ext/1472/Delay.o ../Delay.c   > ${OBJECTDIR}/_ext/1472/Delay.o.err 2>&1  ; if [ $$? -eq 0 ] ; then touch ${OBJECTDIR}/_ext/1472/Delay.o.ok ; fi 
ifneq (,$(findstring MINGW32,$(OS_CURRENT))) 
	@sed -e 's/\"//g' -e 's/\\$$/__EOL__/g' -e 's/\\ /__ESCAPED_SPACES__/g' -e 's/\\/\//g' -e 's/__ESCAPED_SPACES__/\\ /g' -e 's/__EOL__$$/\\/g' ${OBJECTDIR}/_ext/1472/Delay.o.d > ${OBJECTDIR}/_ext/1472/Delay.o.tmp
	@${RM} ${OBJECTDIR}/_ext/1472/Delay.o.d 
	@${CP} ${OBJECTDIR}/_ext/1472/Delay.o.tmp ${OBJECTDIR}/_ext/1472/Delay.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/Delay.o.tmp}
else 
	@sed -e 's/\"//g' ${OBJECTDIR}/_ext/1472/Delay.o.d > ${OBJECTDIR}/_ext/1472/Delay.o.tmp
	@${RM} ${OBJECTDIR}/_ext/1472/Delay.o.d 
	@${CP} ${OBJECTDIR}/_ext/1472/Delay.o.tmp ${OBJECTDIR}/_ext/1472/Delay.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/Delay.o.tmp
endif
	@if [ -f ${OBJECTDIR}/_ext/1472/Delay.o.ok ] ; then rm -f ${OBJECTDIR}/_ext/1472/Delay.o.ok; else cat ${OBJECTDIR}/_ext/1472/Delay.o.err; exit 1; fi
	
${OBJECTDIR}/_ext/1472/Socket.o: ../Socket.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1472 
	@${RM} ${OBJECTDIR}/_ext/1472/Socket.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/Socket.o.ok ${OBJECTDIR}/_ext/1472/Socket.o.err 
	@echo ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG  -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -Wall -I".." -MMD -MF ${OBJECTDIR}/_ext/1472/Socket.o.d -o ${OBJECTDIR}/_ext/1472/Socket.o ../Socket.c  
	@-${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG  -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -Wall -I".." -MMD -MF ${OBJECTDIR}/_ext/1472/Socket.o.d -o ${OBJECTDIR}/_ext/1472/Socket.o ../Socket.c   > ${OBJECTDIR}/_ext/1472/Socket.o.err 2>&1  ; if [ $$? -eq 0 ] ; then touch ${OBJECTDIR}/_ext/1472/Socket.o.ok ; fi 
ifneq (,$(findstring MINGW32,$(OS_CURRENT))) 
	@sed -e 's/\"//g' -e 's/\\$$/__EOL__/g' -e 's/\\ /__ESCAPED_SPACES__/g' -e 's/\\/\//g' -e 's/__ESCAPED_SPACES__/\\ /g' -e 's/__EOL__$$/\\/g' ${OBJECTDIR}/_ext/1472/Socket.o.d > ${OBJECTDIR}/_ext/1472/Socket.o.tmp
	@${RM} ${OBJECTDIR}/_ext/1472/Socket.o.d 
	@${CP} ${OBJECTDIR}/_ext/1472/Socket.o.tmp ${OBJECTDIR}/_ext/1472/Socket.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/Socket.o.tmp}
else 
	@sed -e 's/\"//g' ${OBJECTDIR}/_ext/1472/Socket.o.d > ${OBJECTDIR}/_ext/1472/Socket.o.tmp
	@${RM} ${OBJECTDIR}/_ext/1472/Socket.o.d 
	@${CP} ${OBJECTDIR}/_ext/1472/Socket.o.tmp ${OBJECTDIR}/_ext/1472/Socket.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/Socket.o.tmp
endif
	@if [ -f ${OBJECTDIR}/_ext/1472/Socket.o.ok ] ; then rm -f ${OBJECTDIR}/_ext/1472/Socket.o.ok; else cat ${OBJECTDIR}/_ext/1472/Socket.o.err; exit 1; fi
	
${OBJECTDIR}/_ext/1472/W5100.o: ../W5100.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1472 
	@${RM} ${OBJECTDIR}/_ext/1472/W5100.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/W5100.o.ok ${OBJECTDIR}/_ext/1472/W5100.o.err 
	@echo ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG  -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -Wall -I".." -MMD -MF ${OBJECTDIR}/_ext/1472/W5100.o.d -o ${OBJECTDIR}/_ext/1472/W5100.o ../W5100.c  
	@-${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG  -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -Wall -I".." -MMD -MF ${OBJECTDIR}/_ext/1472/W5100.o.d -o ${OBJECTDIR}/_ext/1472/W5100.o ../W5100.c   > ${OBJECTDIR}/_ext/1472/W5100.o.err 2>&1  ; if [ $$? -eq 0 ] ; then touch ${OBJECTDIR}/_ext/1472/W5100.o.ok ; fi 
ifneq (,$(findstring MINGW32,$(OS_CURRENT))) 
	@sed -e 's/\"//g' -e 's/\\$$/__EOL__/g' -e 's/\\ /__ESCAPED_SPACES__/g' -e 's/\\/\//g' -e 's/__ESCAPED_SPACES__/\\ /g' -e 's/__EOL__$$/\\/g' ${OBJECTDIR}/_ext/1472/W5100.o.d > ${OBJECTDIR}/_ext/1472/W5100.o.tmp
	@${RM} ${OBJECTDIR}/_ext/1472/W5100.o.d 
	@${CP} ${OBJECTDIR}/_ext/1472/W5100.o.tmp ${OBJECTDIR}/_ext/1472/W5100.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/W5100.o.tmp}
else 
	@sed -e 's/\"//g' ${OBJECTDIR}/_ext/1472/W5100.o.d > ${OBJECTDIR}/_ext/1472/W5100.o.tmp
	@${RM} ${OBJECTDIR}/_ext/1472/W5100.o.d 
	@${CP} ${OBJECTDIR}/_ext/1472/W5100.o.tmp ${OBJECTDIR}/_ext/1472/W5100.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/W5100.o.tmp
endif
	@if [ -f ${OBJECTDIR}/_ext/1472/W5100.o.ok ] ; then rm -f ${OBJECTDIR}/_ext/1472/W5100.o.ok; else cat ${OBJECTDIR}/_ext/1472/W5100.o.err; exit 1; fi
	
${OBJECTDIR}/_ext/1472/Peripherals.o: ../Peripherals.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1472 
	@${RM} ${OBJECTDIR}/_ext/1472/Peripherals.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/Peripherals.o.ok ${OBJECTDIR}/_ext/1472/Peripherals.o.err 
	@echo ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG  -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -Wall -I".." -MMD -MF ${OBJECTDIR}/_ext/1472/Peripherals.o.d -o ${OBJECTDIR}/_ext/1472/Peripherals.o ../Peripherals.c  
	@-${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG  -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -Wall -I".." -MMD -MF ${OBJECTDIR}/_ext/1472/Peripherals.o.d -o ${OBJECTDIR}/_ext/1472/Peripherals.o ../Peripherals.c   > ${OBJECTDIR}/_ext/1472/Peripherals.o.err 2>&1  ; if [ $$? -eq 0 ] ; then touch ${OBJECTDIR}/_ext/1472/Peripherals.o.ok ; fi 
ifneq (,$(findstring MINGW32,$(OS_CURRENT))) 
	@sed -e 's/\"//g' -e 's/\\$$/__EOL__/g' -e 's/\\ /__ESCAPED_SPACES__/g' -e 's/\\/\//g' -e 's/__ESCAPED_SPACES__/\\ /g' -e 's/__EOL__$$/\\/g' ${OBJECTDIR}/_ext/1472/Peripherals.o.d > ${OBJECTDIR}/_ext/1472/Peripherals.o.tmp
	@${RM} ${OBJECTDIR}/_ext/1472/Peripherals.o.d 
	@${CP} ${OBJECTDIR}/_ext/1472/Peripherals.o.tmp ${OBJECTDIR}/_ext/1472/Peripherals.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/Peripherals.o.tmp}
else 
	@sed -e 's/\"//g' ${OBJECTDIR}/_ext/1472/Peripherals.o.d > ${OBJECTDIR}/_ext/1472/Peripherals.o.tmp
	@${RM} ${OBJECTDIR}/_ext/1472/Peripherals.o.d 
	@${CP} ${OBJECTDIR}/_ext/1472/Peripherals.o.tmp ${OBJECTDIR}/_ext/1472/Peripherals.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/Peripherals.o.tmp
endif
	@if [ -f ${OBJECTDIR}/_ext/1472/Peripherals.o.ok ] ; then rm -f ${OBJECTDIR}/_ext/1472/Peripherals.o.ok; else cat ${OBJECTDIR}/_ext/1472/Peripherals.o.err; exit 1; fi
	
${OBJECTDIR}/_ext/1472/Main.o: ../Main.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1472 
	@${RM} ${OBJECTDIR}/_ext/1472/Main.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/Main.o.ok ${OBJECTDIR}/_ext/1472/Main.o.err 
	@echo ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG  -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -Wall -I".." -MMD -MF ${OBJECTDIR}/_ext/1472/Main.o.d -o ${OBJECTDIR}/_ext/1472/Main.o ../Main.c  
	@-${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG  -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -Wall -I".." -MMD -MF ${OBJECTDIR}/_ext/1472/Main.o.d -o ${OBJECTDIR}/_ext/1472/Main.o ../Main.c   > ${OBJECTDIR}/_ext/1472/Main.o.err 2>&1  ; if [ $$? -eq 0 ] ; then touch ${OBJECTDIR}/_ext/1472/Main.o.ok ; fi 
ifneq (,$(findstring MINGW32,$(OS_CURRENT))) 
	@sed -e 's/\"//g' -e 's/\\$$/__EOL__/g' -e 's/\\ /__ESCAPED_SPACES__/g' -e 's/\\/\//g' -e 's/__ESCAPED_SPACES__/\\ /g' -e 's/__EOL__$$/\\/g' ${OBJECTDIR}/_ext/1472/Main.o.d > ${OBJECTDIR}/_ext/1472/Main.o.tmp
	@${RM} ${OBJECTDIR}/_ext/1472/Main.o.d 
	@${CP} ${OBJECTDIR}/_ext/1472/Main.o.tmp ${OBJECTDIR}/_ext/1472/Main.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/Main.o.tmp}
else 
	@sed -e 's/\"//g' ${OBJECTDIR}/_ext/1472/Main.o.d > ${OBJECTDIR}/_ext/1472/Main.o.tmp
	@${RM} ${OBJECTDIR}/_ext/1472/Main.o.d 
	@${CP} ${OBJECTDIR}/_ext/1472/Main.o.tmp ${OBJECTDIR}/_ext/1472/Main.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/Main.o.tmp
endif
	@if [ -f ${OBJECTDIR}/_ext/1472/Main.o.ok ] ; then rm -f ${OBJECTDIR}/_ext/1472/Main.o.ok; else cat ${OBJECTDIR}/_ext/1472/Main.o.err; exit 1; fi
	
${OBJECTDIR}/_ext/1472/Patterns.o: ../Patterns.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1472 
	@${RM} ${OBJECTDIR}/_ext/1472/Patterns.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/Patterns.o.ok ${OBJECTDIR}/_ext/1472/Patterns.o.err 
	@echo ${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG  -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -Wall -I".." -MMD -MF ${OBJECTDIR}/_ext/1472/Patterns.o.d -o ${OBJECTDIR}/_ext/1472/Patterns.o ../Patterns.c  
	@-${MP_CC} $(MP_EXTRA_CC_PRE) -g -D__DEBUG  -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -Wall -I".." -MMD -MF ${OBJECTDIR}/_ext/1472/Patterns.o.d -o ${OBJECTDIR}/_ext/1472/Patterns.o ../Patterns.c   > ${OBJECTDIR}/_ext/1472/Patterns.o.err 2>&1  ; if [ $$? -eq 0 ] ; then touch ${OBJECTDIR}/_ext/1472/Patterns.o.ok ; fi 
ifneq (,$(findstring MINGW32,$(OS_CURRENT))) 
	@sed -e 's/\"//g' -e 's/\\$$/__EOL__/g' -e 's/\\ /__ESCAPED_SPACES__/g' -e 's/\\/\//g' -e 's/__ESCAPED_SPACES__/\\ /g' -e 's/__EOL__$$/\\/g' ${OBJECTDIR}/_ext/1472/Patterns.o.d > ${OBJECTDIR}/_ext/1472/Patterns.o.tmp
	@${RM} ${OBJECTDIR}/_ext/1472/Patterns.o.d 
	@${CP} ${OBJECTDIR}/_ext/1472/Patterns.o.tmp ${OBJECTDIR}/_ext/1472/Patterns.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/Patterns.o.tmp}
else 
	@sed -e 's/\"//g' ${OBJECTDIR}/_ext/1472/Patterns.o.d > ${OBJECTDIR}/_ext/1472/Patterns.o.tmp
	@${RM} ${OBJECTDIR}/_ext/1472/Patterns.o.d 
	@${CP} ${OBJECTDIR}/_ext/1472/Patterns.o.tmp ${OBJECTDIR}/_ext/1472/Patterns.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/Patterns.o.tmp
endif
	@if [ -f ${OBJECTDIR}/_ext/1472/Patterns.o.ok ] ; then rm -f ${OBJECTDIR}/_ext/1472/Patterns.o.ok; else cat ${OBJECTDIR}/_ext/1472/Patterns.o.err; exit 1; fi
	
else
${OBJECTDIR}/_ext/1472/Delay.o: ../Delay.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1472 
	@${RM} ${OBJECTDIR}/_ext/1472/Delay.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/Delay.o.ok ${OBJECTDIR}/_ext/1472/Delay.o.err 
	@echo ${MP_CC} $(MP_EXTRA_CC_PRE)  -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -Wall -I".." -MMD -MF ${OBJECTDIR}/_ext/1472/Delay.o.d -o ${OBJECTDIR}/_ext/1472/Delay.o ../Delay.c  
	@-${MP_CC} $(MP_EXTRA_CC_PRE)  -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -Wall -I".." -MMD -MF ${OBJECTDIR}/_ext/1472/Delay.o.d -o ${OBJECTDIR}/_ext/1472/Delay.o ../Delay.c   > ${OBJECTDIR}/_ext/1472/Delay.o.err 2>&1  ; if [ $$? -eq 0 ] ; then touch ${OBJECTDIR}/_ext/1472/Delay.o.ok ; fi 
ifneq (,$(findstring MINGW32,$(OS_CURRENT))) 
	@sed -e 's/\"//g' -e 's/\\$$/__EOL__/g' -e 's/\\ /__ESCAPED_SPACES__/g' -e 's/\\/\//g' -e 's/__ESCAPED_SPACES__/\\ /g' -e 's/__EOL__$$/\\/g' ${OBJECTDIR}/_ext/1472/Delay.o.d > ${OBJECTDIR}/_ext/1472/Delay.o.tmp
	@${RM} ${OBJECTDIR}/_ext/1472/Delay.o.d 
	@${CP} ${OBJECTDIR}/_ext/1472/Delay.o.tmp ${OBJECTDIR}/_ext/1472/Delay.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/Delay.o.tmp}
else 
	@sed -e 's/\"//g' ${OBJECTDIR}/_ext/1472/Delay.o.d > ${OBJECTDIR}/_ext/1472/Delay.o.tmp
	@${RM} ${OBJECTDIR}/_ext/1472/Delay.o.d 
	@${CP} ${OBJECTDIR}/_ext/1472/Delay.o.tmp ${OBJECTDIR}/_ext/1472/Delay.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/Delay.o.tmp
endif
	@if [ -f ${OBJECTDIR}/_ext/1472/Delay.o.ok ] ; then rm -f ${OBJECTDIR}/_ext/1472/Delay.o.ok; else cat ${OBJECTDIR}/_ext/1472/Delay.o.err; exit 1; fi
	
${OBJECTDIR}/_ext/1472/Socket.o: ../Socket.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1472 
	@${RM} ${OBJECTDIR}/_ext/1472/Socket.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/Socket.o.ok ${OBJECTDIR}/_ext/1472/Socket.o.err 
	@echo ${MP_CC} $(MP_EXTRA_CC_PRE)  -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -Wall -I".." -MMD -MF ${OBJECTDIR}/_ext/1472/Socket.o.d -o ${OBJECTDIR}/_ext/1472/Socket.o ../Socket.c  
	@-${MP_CC} $(MP_EXTRA_CC_PRE)  -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -Wall -I".." -MMD -MF ${OBJECTDIR}/_ext/1472/Socket.o.d -o ${OBJECTDIR}/_ext/1472/Socket.o ../Socket.c   > ${OBJECTDIR}/_ext/1472/Socket.o.err 2>&1  ; if [ $$? -eq 0 ] ; then touch ${OBJECTDIR}/_ext/1472/Socket.o.ok ; fi 
ifneq (,$(findstring MINGW32,$(OS_CURRENT))) 
	@sed -e 's/\"//g' -e 's/\\$$/__EOL__/g' -e 's/\\ /__ESCAPED_SPACES__/g' -e 's/\\/\//g' -e 's/__ESCAPED_SPACES__/\\ /g' -e 's/__EOL__$$/\\/g' ${OBJECTDIR}/_ext/1472/Socket.o.d > ${OBJECTDIR}/_ext/1472/Socket.o.tmp
	@${RM} ${OBJECTDIR}/_ext/1472/Socket.o.d 
	@${CP} ${OBJECTDIR}/_ext/1472/Socket.o.tmp ${OBJECTDIR}/_ext/1472/Socket.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/Socket.o.tmp}
else 
	@sed -e 's/\"//g' ${OBJECTDIR}/_ext/1472/Socket.o.d > ${OBJECTDIR}/_ext/1472/Socket.o.tmp
	@${RM} ${OBJECTDIR}/_ext/1472/Socket.o.d 
	@${CP} ${OBJECTDIR}/_ext/1472/Socket.o.tmp ${OBJECTDIR}/_ext/1472/Socket.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/Socket.o.tmp
endif
	@if [ -f ${OBJECTDIR}/_ext/1472/Socket.o.ok ] ; then rm -f ${OBJECTDIR}/_ext/1472/Socket.o.ok; else cat ${OBJECTDIR}/_ext/1472/Socket.o.err; exit 1; fi
	
${OBJECTDIR}/_ext/1472/W5100.o: ../W5100.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1472 
	@${RM} ${OBJECTDIR}/_ext/1472/W5100.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/W5100.o.ok ${OBJECTDIR}/_ext/1472/W5100.o.err 
	@echo ${MP_CC} $(MP_EXTRA_CC_PRE)  -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -Wall -I".." -MMD -MF ${OBJECTDIR}/_ext/1472/W5100.o.d -o ${OBJECTDIR}/_ext/1472/W5100.o ../W5100.c  
	@-${MP_CC} $(MP_EXTRA_CC_PRE)  -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -Wall -I".." -MMD -MF ${OBJECTDIR}/_ext/1472/W5100.o.d -o ${OBJECTDIR}/_ext/1472/W5100.o ../W5100.c   > ${OBJECTDIR}/_ext/1472/W5100.o.err 2>&1  ; if [ $$? -eq 0 ] ; then touch ${OBJECTDIR}/_ext/1472/W5100.o.ok ; fi 
ifneq (,$(findstring MINGW32,$(OS_CURRENT))) 
	@sed -e 's/\"//g' -e 's/\\$$/__EOL__/g' -e 's/\\ /__ESCAPED_SPACES__/g' -e 's/\\/\//g' -e 's/__ESCAPED_SPACES__/\\ /g' -e 's/__EOL__$$/\\/g' ${OBJECTDIR}/_ext/1472/W5100.o.d > ${OBJECTDIR}/_ext/1472/W5100.o.tmp
	@${RM} ${OBJECTDIR}/_ext/1472/W5100.o.d 
	@${CP} ${OBJECTDIR}/_ext/1472/W5100.o.tmp ${OBJECTDIR}/_ext/1472/W5100.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/W5100.o.tmp}
else 
	@sed -e 's/\"//g' ${OBJECTDIR}/_ext/1472/W5100.o.d > ${OBJECTDIR}/_ext/1472/W5100.o.tmp
	@${RM} ${OBJECTDIR}/_ext/1472/W5100.o.d 
	@${CP} ${OBJECTDIR}/_ext/1472/W5100.o.tmp ${OBJECTDIR}/_ext/1472/W5100.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/W5100.o.tmp
endif
	@if [ -f ${OBJECTDIR}/_ext/1472/W5100.o.ok ] ; then rm -f ${OBJECTDIR}/_ext/1472/W5100.o.ok; else cat ${OBJECTDIR}/_ext/1472/W5100.o.err; exit 1; fi
	
${OBJECTDIR}/_ext/1472/Peripherals.o: ../Peripherals.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1472 
	@${RM} ${OBJECTDIR}/_ext/1472/Peripherals.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/Peripherals.o.ok ${OBJECTDIR}/_ext/1472/Peripherals.o.err 
	@echo ${MP_CC} $(MP_EXTRA_CC_PRE)  -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -Wall -I".." -MMD -MF ${OBJECTDIR}/_ext/1472/Peripherals.o.d -o ${OBJECTDIR}/_ext/1472/Peripherals.o ../Peripherals.c  
	@-${MP_CC} $(MP_EXTRA_CC_PRE)  -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -Wall -I".." -MMD -MF ${OBJECTDIR}/_ext/1472/Peripherals.o.d -o ${OBJECTDIR}/_ext/1472/Peripherals.o ../Peripherals.c   > ${OBJECTDIR}/_ext/1472/Peripherals.o.err 2>&1  ; if [ $$? -eq 0 ] ; then touch ${OBJECTDIR}/_ext/1472/Peripherals.o.ok ; fi 
ifneq (,$(findstring MINGW32,$(OS_CURRENT))) 
	@sed -e 's/\"//g' -e 's/\\$$/__EOL__/g' -e 's/\\ /__ESCAPED_SPACES__/g' -e 's/\\/\//g' -e 's/__ESCAPED_SPACES__/\\ /g' -e 's/__EOL__$$/\\/g' ${OBJECTDIR}/_ext/1472/Peripherals.o.d > ${OBJECTDIR}/_ext/1472/Peripherals.o.tmp
	@${RM} ${OBJECTDIR}/_ext/1472/Peripherals.o.d 
	@${CP} ${OBJECTDIR}/_ext/1472/Peripherals.o.tmp ${OBJECTDIR}/_ext/1472/Peripherals.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/Peripherals.o.tmp}
else 
	@sed -e 's/\"//g' ${OBJECTDIR}/_ext/1472/Peripherals.o.d > ${OBJECTDIR}/_ext/1472/Peripherals.o.tmp
	@${RM} ${OBJECTDIR}/_ext/1472/Peripherals.o.d 
	@${CP} ${OBJECTDIR}/_ext/1472/Peripherals.o.tmp ${OBJECTDIR}/_ext/1472/Peripherals.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/Peripherals.o.tmp
endif
	@if [ -f ${OBJECTDIR}/_ext/1472/Peripherals.o.ok ] ; then rm -f ${OBJECTDIR}/_ext/1472/Peripherals.o.ok; else cat ${OBJECTDIR}/_ext/1472/Peripherals.o.err; exit 1; fi
	
${OBJECTDIR}/_ext/1472/Main.o: ../Main.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1472 
	@${RM} ${OBJECTDIR}/_ext/1472/Main.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/Main.o.ok ${OBJECTDIR}/_ext/1472/Main.o.err 
	@echo ${MP_CC} $(MP_EXTRA_CC_PRE)  -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -Wall -I".." -MMD -MF ${OBJECTDIR}/_ext/1472/Main.o.d -o ${OBJECTDIR}/_ext/1472/Main.o ../Main.c  
	@-${MP_CC} $(MP_EXTRA_CC_PRE)  -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -Wall -I".." -MMD -MF ${OBJECTDIR}/_ext/1472/Main.o.d -o ${OBJECTDIR}/_ext/1472/Main.o ../Main.c   > ${OBJECTDIR}/_ext/1472/Main.o.err 2>&1  ; if [ $$? -eq 0 ] ; then touch ${OBJECTDIR}/_ext/1472/Main.o.ok ; fi 
ifneq (,$(findstring MINGW32,$(OS_CURRENT))) 
	@sed -e 's/\"//g' -e 's/\\$$/__EOL__/g' -e 's/\\ /__ESCAPED_SPACES__/g' -e 's/\\/\//g' -e 's/__ESCAPED_SPACES__/\\ /g' -e 's/__EOL__$$/\\/g' ${OBJECTDIR}/_ext/1472/Main.o.d > ${OBJECTDIR}/_ext/1472/Main.o.tmp
	@${RM} ${OBJECTDIR}/_ext/1472/Main.o.d 
	@${CP} ${OBJECTDIR}/_ext/1472/Main.o.tmp ${OBJECTDIR}/_ext/1472/Main.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/Main.o.tmp}
else 
	@sed -e 's/\"//g' ${OBJECTDIR}/_ext/1472/Main.o.d > ${OBJECTDIR}/_ext/1472/Main.o.tmp
	@${RM} ${OBJECTDIR}/_ext/1472/Main.o.d 
	@${CP} ${OBJECTDIR}/_ext/1472/Main.o.tmp ${OBJECTDIR}/_ext/1472/Main.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/Main.o.tmp
endif
	@if [ -f ${OBJECTDIR}/_ext/1472/Main.o.ok ] ; then rm -f ${OBJECTDIR}/_ext/1472/Main.o.ok; else cat ${OBJECTDIR}/_ext/1472/Main.o.err; exit 1; fi
	
${OBJECTDIR}/_ext/1472/Patterns.o: ../Patterns.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/_ext/1472 
	@${RM} ${OBJECTDIR}/_ext/1472/Patterns.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/Patterns.o.ok ${OBJECTDIR}/_ext/1472/Patterns.o.err 
	@echo ${MP_CC} $(MP_EXTRA_CC_PRE)  -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -Wall -I".." -MMD -MF ${OBJECTDIR}/_ext/1472/Patterns.o.d -o ${OBJECTDIR}/_ext/1472/Patterns.o ../Patterns.c  
	@-${MP_CC} $(MP_EXTRA_CC_PRE)  -omf=elf -x c -c -mcpu=$(MP_PROCESSOR_OPTION) -Wall -I".." -MMD -MF ${OBJECTDIR}/_ext/1472/Patterns.o.d -o ${OBJECTDIR}/_ext/1472/Patterns.o ../Patterns.c   > ${OBJECTDIR}/_ext/1472/Patterns.o.err 2>&1  ; if [ $$? -eq 0 ] ; then touch ${OBJECTDIR}/_ext/1472/Patterns.o.ok ; fi 
ifneq (,$(findstring MINGW32,$(OS_CURRENT))) 
	@sed -e 's/\"//g' -e 's/\\$$/__EOL__/g' -e 's/\\ /__ESCAPED_SPACES__/g' -e 's/\\/\//g' -e 's/__ESCAPED_SPACES__/\\ /g' -e 's/__EOL__$$/\\/g' ${OBJECTDIR}/_ext/1472/Patterns.o.d > ${OBJECTDIR}/_ext/1472/Patterns.o.tmp
	@${RM} ${OBJECTDIR}/_ext/1472/Patterns.o.d 
	@${CP} ${OBJECTDIR}/_ext/1472/Patterns.o.tmp ${OBJECTDIR}/_ext/1472/Patterns.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/Patterns.o.tmp}
else 
	@sed -e 's/\"//g' ${OBJECTDIR}/_ext/1472/Patterns.o.d > ${OBJECTDIR}/_ext/1472/Patterns.o.tmp
	@${RM} ${OBJECTDIR}/_ext/1472/Patterns.o.d 
	@${CP} ${OBJECTDIR}/_ext/1472/Patterns.o.tmp ${OBJECTDIR}/_ext/1472/Patterns.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/Patterns.o.tmp
endif
	@if [ -f ${OBJECTDIR}/_ext/1472/Patterns.o.ok ] ; then rm -f ${OBJECTDIR}/_ext/1472/Patterns.o.ok; else cat ${OBJECTDIR}/_ext/1472/Patterns.o.err; exit 1; fi
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
dist/${CND_CONF}/${IMAGE_TYPE}/Web_board.X.${IMAGE_TYPE}.elf: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -omf=elf  -mcpu=$(MP_PROCESSOR_OPTION)  -D__DEBUG  -o dist/${CND_CONF}/${IMAGE_TYPE}/Web_board.X.${IMAGE_TYPE}.elf ${OBJECTFILES}        -Wl,--defsym=__MPLAB_BUILD=1,-L"..",-Map="${DISTDIR}/Web_board.X.${IMAGE_TYPE}.map",--report-mem,--report-mem$(MP_EXTRA_LD_POST)$(MP_LINKER_FILE_OPTION),--defsym=__MPLAB_DEBUG=1,--defsym=__ICD2RAM=1,--defsym=__DEBUG=1
else
dist/${CND_CONF}/${IMAGE_TYPE}/Web_board.X.${IMAGE_TYPE}.elf: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -omf=elf  -mcpu=$(MP_PROCESSOR_OPTION)  -o dist/${CND_CONF}/${IMAGE_TYPE}/Web_board.X.${IMAGE_TYPE}.elf ${OBJECTFILES}        -Wl,--defsym=__MPLAB_BUILD=1,-L"..",-Map="${DISTDIR}/Web_board.X.${IMAGE_TYPE}.map",--report-mem,--report-mem$(MP_EXTRA_LD_POST)$(MP_LINKER_FILE_OPTION)
	${MP_CC_DIR}\\pic30-bin2hex dist/${CND_CONF}/${IMAGE_TYPE}/Web_board.X.${IMAGE_TYPE}.elf -omf=elf
endif


# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf:
	${RM} -r build/default
	${RM} -r dist/default

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
