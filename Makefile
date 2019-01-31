#
# TODO: Move `libmongoclient.a` to /usr/local/lib so this can work on production servers
#

#CC := g++ # This is the main compiler
CC := clang++ # and comment out the linker last line for sanity
SRCDIR := src
BUILDDIR := build
TARGETDIR := bin

# Targets
EXECUTABLE := rip_sim
TARGET := $(TARGETDIR)/$(EXECUTABLE)

# Code Lists
SRCEXT := cpp
SOURCES := $(shell find $(SRCDIR) -type f -name *.$(SRCEXT))
OBJECTS := $(patsubst $(SRCDIR)/%,$(BUILDDIR)/%,$(SOURCES:.$(SRCEXT)=.o))

# Folder Lists
# Note: Intentionally excludes the root of the include folder so the lists are clean
INCDIRS := $(shell find include/**/* -name '*.h' -exec dirname {} \; | sort | uniq)
INCLIST := $(patsubst include/%,-I include/%,$(INCDIRS))
BUILDLIST := $(patsubst include/%,$(BUILDDIR)/%,$(INCDIRS))

# Shared Compiler Flags
CFLAGS := -c -std=gnu++11 -O2 # -Wall
INC := -I include $(INCLIST)
LIB := 

$(TARGET): $(OBJECTS)
	@mkdir -p $(TARGETDIR)
	@echo " Linking..."
	@echo "  Linking $(TARGET)"; $(CC) $^ -o $(TARGET) $(LIB)

$(BUILDDIR)/%.o: $(SRCDIR)/%.$(SRCEXT)
	@mkdir -p $(BUILDDIR)
	@echo "Compiling $<..."; $(CC) $(CFLAGS) $(INC) -c -o $@ $<

clean:
	@echo "Cleaning $(TARGET)..."; $(RM) -r $(BUILDDIR) $(TARGET)

distclean:
	@echo "Removing $(EXECUTABLE)"; rm $(INSTALLBINDIR)/$(EXECUTABLE)

# Tests
tester:
	$(CC) $(CFLAGS) test/tester.cpp $(INC) $(LIB) -o bin/tester

# Spikes
ticket:
	$(CC) $(CFLAGS) spikes/ticket.cpp $(INC) $(LIB) -o bin/ticket

.PHONY: clean
