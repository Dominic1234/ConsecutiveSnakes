################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../main.c \
../main_BACKUP_2621.c \
../main_BASE_2621.c \
../main_LOCAL_2621.c \
../main_REMOTE_2621.c 

OBJS += \
./main.o \
./main_BACKUP_2621.o \
./main_BASE_2621.o \
./main_LOCAL_2621.o \
./main_REMOTE_2621.o 

C_DEPS += \
./main.d \
./main_BACKUP_2621.d \
./main_BASE_2621.d \
./main_LOCAL_2621.d \
./main_REMOTE_2621.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross GCC Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


