
CC = gcc
CFLAGS = -Wfatal-errors	-Wall -Werror 
LDFLAGS = 
OBJFILES = Starter.o Executor.o
TARGET = Starter

all:	$(TARGET)

$(TARGET): $(OBJFILES)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJFILES) $(LDFLAGS)
clean:
	rm -f $(OBJFILES) $(TARGET) *~
