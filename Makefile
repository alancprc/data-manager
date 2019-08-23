all : unittest run

TARGET=unittest
COMPILER_FLAG += -std=c++0x

${TARGET} : data-manager.h unittest.cpp
	g++ ${COMPILER_FLAG} $^ -o $@ -lgtest_main -lgtest

run : ${TARGET}
	./${TARGET}

clean :
	rm -f ${TARGET}
