

HEADERS = SensorUtils.h

OBJS = SensorUtils.o

LIBNAME=sensorutils
LIBVERSION=3


LIBRARY=$(LIBNAME).so.$(LIBVERSION)
LIBS=-lm -ldl

MKDIR=mkdir
CP=cp -f
LN=ln -s
TAR=tar

LD=$(CC)

%.o: %.cpp
	$(CC) -c $(COPTS) $< -o $@

%.o: %.cc
	$(CC) -c $(COPTS) $< -o $@

$(LIBRARY): $(OBJS)
	$(LD) $(COPTS) $(LDOPTS) $^ $(LIBS) -o $(LIBRARY)

all: $(HEADERS) $(LIBRARY)

install::
	$(MKDIR) -p $(INSTDIR)/lib
	$(CP) $(LIBRARY) $(INSTDIR)/lib
	$(RM) $(INSTDIR)/lib/$(LIBNAME).so && $(LN) $(LIBRARY) $(INSTDIR)/lib/$(LIBNAME).so
	$(MKDIR) -p $(INSTDIR)/include/csm
	$(CP) $(HEADERS) $(INSTDIR)/include/csm

clean::
	$(RM) $(OBJS) $(LIBRARY) *~



