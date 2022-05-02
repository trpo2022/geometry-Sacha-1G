CC = gcc
CFLAGS = -I src/ -Wall -Wextra -Werror -g -O0
CPPFLAGS = -MMD
TARGET = bin/geometry

$(TARGET) : ./obj/src/main.o ./obj/src/geom.a
	$(CC) $(CFLAGS) $(CPPFLAGS) $^ -o $@

./obj/src/geom.a : ./obj/src/geometry.o
	ar rcs $@ $^

./obj/src/geometry.o : ./src/geometry/geometry.c
	$(CC) -c $(CFLAGS) $(CPPFLAGS) -o $@ $< 

./obj/src/main.o : ./src/main.c
	$(CC) -c $(CFLAGS) $(CPPFLAGS) -o $@ $<

run :
	./$(TARGET)

clean :
	rm ./obj/src/*.d ./obj/src/*.o ./obj/src/*.a $(TARGET)

-include obj/src/main.d