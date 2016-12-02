#Readme:
	How to transplant coremark to stm32 platform?
	
1. Add hardware init code to function portable_init() in file core_portme.c
	eg. GPIO, USART, TIMER configurations and retargets printf()
2. Configure a timer , get an interrupt per millisecond
3. Modify macro GETMYTIME() in file core_portme.c, to get current time (in ms)
4. Modify macro EE_TICKS_PER_SEC to 1000, 1 ms interrupt means 1000Hz Ticks
5. Add macro ITERATIONS, usually define to 10000 ~20000
6. Modify macro COMPILER_VERSION and COMPILER_FLAGS in core_portme.h, 
	to indicate compiler version and flags, used for print out to user
	
	OK, it's done!