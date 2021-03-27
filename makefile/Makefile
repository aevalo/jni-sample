SCALA_LIBS_HOME = $(HOME)/.sdkman/candidates/scala/current/lib
SCALA_CP = $(SCALA_LIBS_HOME)/scala-library.jar
CC = g++
CFLAGS = -Wall -Werror -fpic -I./out/generated/header -I$(JAVA_HOME)/include  -I$(JAVA_HOME)/include/linux

all: out-dir Sample1.java Sample1.scala Sample1.scala.h Sample1.o Sample1.so

out-dir:
	@echo "Creating output directories"
	@mkdir -p ./out/classes/java
	@mkdir -p ./out/classes/scala
	@mkdir -p ./out/generated/header
	@mkdir -p ./out/native/build
	@mkdir -p ./out/lib

Sample1.java: out-dir
	@echo "Compiling Java classes with header generation"
	@javac -d ./out/classes/java -h ./out/generated/header src/main/java/Sample1.java

Sample1.scala: out-dir
	@echo "Compiling Scala classes"
	@scalac -d ./out/classes/scala ./src/main/scala/Sample1.scala

Sample1.scala.h: Sample1.scala
	@echo "Creating JNI header from Scala class"
	@javah -cp $(SCALA_CP):./out/classes/scala -d ./out/generated/header Sample1

Sample1.o:
	@echo "Compiling JNI module"
	@$(CC) -c $(CFLAGS) -o ./out/native/build/Sample1.o ./src/main/cpp/Sample1.cpp

Sample1.so: Sample1.o
	@echo "Linking JNI module"
	@$(CC) -shared -o ./out/lib/libSample1.so ./out/native/build/Sample1.o

run-java: Sample1.java Sample1.so
	@echo "Running Java JNI"
	@java -cp ./out/classes/java -Djava.library.path=./out/lib Sample1

run-scala: Sample1.scala Sample1.scala.h Sample1.so
	@echo "Running Scala JNI"
	@scala -cp ./out/classes/scala -Djava.library.path=./out/lib Sample1

.PHONY: clean

clean:
	@if [ -e ./out ]; then echo "Cleaning up"; rm -r out; fi;
