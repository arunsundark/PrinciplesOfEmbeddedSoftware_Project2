Aakash Kumar/ArunSundar

###Project 2 of ECEN-5813 Principles of embedded software 
This project results in the creation of a data processing application for KL25z and enables serial communication to it using UART peripheral. 
The repository also contains unit test code developed using Cmocka unit test framework.

##Make file usage
* Using the "make unittests" command will enable the test of unit tests for the functions from Project1 and Project2
* Using the "make PS=-DPROJECT2" command will enable the compile time switch for project2
* Using the "make PLATFORM=KL25Z"  will create the target executable to run on KL25Z
* Using the "make build" command will create the target executable to run on HOSTMACHINE





##Run instructions
* The data to be analyzed is transmitted through putty, via serial port, to KL25Z
* The KL25Z wais to recieve data and upon reception goes to the ISR
* The ISR handles the data reception in and stores the data in the circular buffer
* This removes the data from and circular buffer and sends it to the dataprocessing functions
* For sending the data, a transmit interrupt is enabled 
* Data is transmitted after the dump_statistics function is called
* This function sends the statistics table back to the serial port via putty



##Files in the directory
* include: contains the header files required for all the platform
* platfrom: contains the architecture specific required to compile certain targets
* src: contains the c-source files for the project
* unit_tests: contains the unit tests written to test all the c functions

##Project Work --  Aakash Kumar/ArunSundar 

##References

https://www.bysatish.in/3/

