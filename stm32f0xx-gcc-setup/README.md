STM32L0XX
==========

This is a template to use the STM32F0xx with GCC and Makefiles.

It currently only runs on linux, and flashes programs with the JLink Segger programmer over SWD.

To use this code:

1. Download the STM [Standard Peripheral Library](http://www.st.com/web/catalog/tools/FM147/CL1794/SC961/SS1743/LN1939)
for the STML0xx. Place it in a persistent location.

2. Download and install the [JLink tools](https://www.segger.com/jlink-software.html)
for your platform. Make sure that the binaries are added to your path.

3. Edit the application Makefile to specify:

    - your specfic STM32F0xx device
    - the location of the Standard Peripheral Library
    - the location of the makefile template above (if not cloned recursively)
    - any source files that you use

4. Use the supported commands to program and debug the chip:

    - `make`: Compile
    - `make flash`: Program the chip
    - `make debug`: Run gdb
    - `make erase-all`: Full erase of the chip
    - `make startdebug`


