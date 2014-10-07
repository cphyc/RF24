# compiler
$CC = g++

# location of the Python header files
PYTHON_VERSION = 2.7
PYTHON_INCLUDE = /usr/include/python$(PYTHON_VERSION)

# location of the Boost Python include files and library

BOOST_INC = /usr/include
BOOST_LIB = /usr/lib

# compile mesh classes
TARGET = RF24_py.so
SOURCES =  RF24.cpp RF24_py.cpp
OBJECTS = $(SOURCES:.cpp=.o)

$(TARGET): $(OBJECTS)
	$(CC) -shared -Wl,--export-dynamic $(OBJECT) -L$(BOOST_LIB) -lboost_python -L/usr/lib/python$(PYTHON_VERSION)/config -lpython$(PYTHON_VERSION) -o $(TARGET)

.cpp.o: 
	$(CC) -I$(PYTHON_INCLUDE) -I$(BOOST_INC) -fPIC -c $< -o $@

clean: 
	rm $(OBJECTS) $(TARGET)
