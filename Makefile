cc=g++
obj=main.o create_sky.o draw.o play.o system_help.o
src=main.cpp create_sky.cpp draw.cpp play.cpp system_help.cpp
head=global.h data.h draw.h play.h system_help.h
exe=main
main: $(obj) $(head) $(src)
	$(cc) -o $(exe) $(obj)
main.o: main.cpp
	$(cc) -o main.o -c main.cpp
create_sky.o: create_sky.cpp
	$(cc) -o create_sky.o -c create_sky.cpp
draw.o: draw.cpp
	$(cc) -o draw.o -c draw.cpp
play.o: play.cpp
	$(cc) -o play.o -c play.cpp
system_help.o: system_help.cpp
	$(cc) -o system_help.o -c system_help.cpp
clean:
	rm $(exe) $(obj)
run:
	./$(exe)
