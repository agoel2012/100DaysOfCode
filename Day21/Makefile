CC=g++
INCLUDE_PATH=../Day21/
TS_TODAY_SRC=TS_Today.cpp
TS_TODAY_OBJ=TS_Today.o
TS_HELPER_H=TS_Helper.h
NEW_YEAR_H=New_Year.h

all:ts_today

ts_today:	$(TS_TODAY_OBJ)
		$(CC) -o ts_today $(TS_TODAY_OBJ)

TS_TODAY_OBJ:	$(TS_TODAY_SRC) $(TS_HELPER_H) $(NEW_YEAR_H)
		$(CC) -c $(TS_TODAY_SRC) -I $(INCLUDE_PATH)

clean:
	rm -rf $(TS_TODAY_OBJ)
	rm -rf ts_today
