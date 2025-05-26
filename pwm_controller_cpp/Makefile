CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++11 -pedantic

all: pwm_test

pwm_test: main.o PWMController.o
	$(CXX) $(CXXFLAGS) -o pwm_test main.o PWMController.o

main.o: main.cpp PWMController.hpp
PWMController.o: PWMController.cpp PWMController.hpp

clean:
	rm -f *.o pwm_test
