CXX=g++
CXXFLAGS=-g

SRCS=main.cpp NonprofessionalEmployee.cpp ProfessionalEmployee.cpp Employee.cpp
OBJS=$(subst .cpp,.o,$(SRCS))

all: linked-list

linked-list: $(OBJS)
	$(CXX) $(CXXFLAGS) -o linked-list $(OBJS)

main.o: main.cpp llist.hpp

Employee.o: Employee.hpp Employee.cpp

NonprofessionalEmployee.o: Employee.o NonprofessionalEmployee.hpp NonprofessionalEmployee.cpp

ProfessionalEmployee.o: Employee.o ProfessionalEmployee.hpp ProfessionalEmployee.cpp

clean:
	rm -f $(OBJS)

distclean: clean
	rm linked-list
