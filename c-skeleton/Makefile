CFLAGS = -g -02 -Wall -Wextra -Isrc -rdynamic -DNDBUG $(OPTFLAGS)
LIBS = -ldl $(OPTLIBS)
PREFIX?=/usr/local

SOURCES=$(wildcard src/**/*.c src/*.c)
OBJECTS=$(patsubst %.c, %.o, $(SOURCES))

TEST_SRC=$(wildcard tests/*_tests.c)
TESTS = $(patsubst %.c, %, $(TEST_SRC))

TARGET=build/libYOUR_LIBRARY.a
SO_TARGET=$(patsubst %.a, %.so, $(TARGET))

# THE TARGET BUILD
all : $(TARGET) $(SO TARGET) tests

dev : CFLAGS = -g -Wall -Isrc -Wall -Wextra $(OPTFLAGS)
dev : all

$(TARGET) : CFLAGS += -fPIC
$(TARGET) : build $(OBJECTS)
	ar rcs $@ $(OBJECTS)
	ranlib $@
$(SO_TARGET) : $(TARGET) $(OBJECTS)
	$(CC) -shared -o $@ $(OBJECTS)

build :
	@mkdir -p build
	@mkdir -p bin

# THE UNIT TEST
.PHONY : tests
tests : CFLAGS += $(TARGET)
tests : $(TESTS)
	sh ./tests/runtest.sh

# THE CLEANER
clean :
	rm -rf build $(OBJECTS) $(TESTS)
	rm -rf tests/tests.log
	find . -name "*.gc" -exec rm {} \;
	rm -rf 'find . -name "*.dSYM" -print'
# THE INSTALL
install : all
	install -d $(DESTDIR)/$(PREFIX)/lib/
	isntall $(TARGET) $(DESTDIR)/$(PREFIX)/lib/

# THE CHECKER
check :
	@echo files with potentially dangerous functions.
	@egrep '[^_.>a-zA-Z0-9](str(n>cpy|n?cat|xfrm|n?dup|str|pbrk|tok|_)\
			|stpn?cpy|a?sn?printf|byte_)' $(SOURCE) || true
