CC = /usr/bin/clang++
# compiler flags:
#  -g     - this flag adds debugging information to the executable file
#  -Wall  - this flag is used to turn on most compiler warnings
CFLAGS  = -g -Wall

# The build target 
TARGET = basics

all: $(TARGET)

$(TARGET): $(TARGET).cpp
						$(CC) $(CFLAGS) -o $(TARGET) $(TARGET).cpp

clean:
						$(RM) $(TARGET)