CC = g++
CFLAGS = -O
LDLIBS =  -lglut -lGL -lGLU -lm
HEADERS = includes.h structs.h globals.h constants.h prototypes.h
OBJS = init.o defineBox.o drawBox.o drawAxes.o reshape.o display.o keyboard.o menu.o

run :	main.o $(OBJS) 
	$(CC) $(CFLAGS) main.o $(OBJS) -o run $(LDLIBS)

main.o : main.cpp $(HEADERS)
	$(CC) $(CFLAGS) main.cpp -c

init.o : init.cpp $(HEADERS)
	$(CC) $(CFLAGS) init.cpp -c

defineBox.o : defineBox.cpp $(HEADERS)
	$(CC) $(CFLAGS) defineBox.cpp -c

drawBox.o : drawBox.cpp $(HEADERS)
	$(CC) $(CFLAGS) drawBox.cpp -c

drawAxes.o : drawAxes.cpp $(HEADERS)
	$(CC) $(CFLAGS) drawAxes.cpp -c

reshape.o : reshape.cpp $(HEADERS)
	$(CC) $(CFLAGS) reshape.cpp -c

display.o : display.cpp $(HEADERS)
	$(CC) $(CFLAGS) display.cpp -c

keyboard.o : keyboard.cpp $(HEADERS)
	$(CC) $(CFLAGS) keyboard.cpp -c

menu.o : menu.cpp $(HEADERS)
	$(CC) $(CFLAGS) menu.cpp -c
clean:
	rm *.o

pristine:
	rm *.o
	touch *


