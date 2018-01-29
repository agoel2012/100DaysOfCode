CC=g++
INCLUDE_PATH=../Day27/
SRC=CallCenter.cpp
OBJ=CallCenter.o
EMPLOYEE_H=Director.h Manager.h Respondent.h
PROCESSCALL_H=ProcessCall.h

all:call_center

call_center:	$(OBJ)
		$(CC) -o call_center $(OBJ)

OBJ:		$(SRC) $(EMPLOYEE_H) $(PROCESSCALL_H)
		$(CC) -c $(SRC) -I $(INCLUDE_PATH)

clean:
	rm -rf $(OBJ)
	rm -rf call_center
