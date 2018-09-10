BUILD_FLAGS = -W -Wall -pedantic
CC = g++
RM = rm
OUT = *.out

all: a.out

a.out: Makefile Database.cpp Main.cpp Faculty.cpp Person.cpp Student.cpp
	$(CC) $(BUILD_FLAGS) Database.cpp Main.cpp Faculty.cpp Person.cpp Student.cpp -o a.out

clean:
	$(RM) $(OUT)
