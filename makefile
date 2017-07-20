#############################################################################
#
# Project Makefile
#
# (c) Wouter van Ooijen (www.voti.nl) 2016
#
# This file is in the public domain.
#
#############################################################################

# source files in this project (main.cpp is automatically assumed)
SOURCES := arm/calculations.cpp servo/servo.cpp arm/arm.cpp joystick/joystick.cpp

# header files in this project
HEADERS := arm/calculations.hpp servo/servo.hpp arm/arm.hpp joystick/joystick.hpp

# other places to look for files for this project
SEARCH  :=

# set RELATIVE to the next higher directory
# and defer to the appropriate Makefile.* there
RELATIVE := ..
include Makefile.due

test:
	cd test && make build && make run
	@echo "**** test completed succesfully"   
