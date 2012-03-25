#
# refind/Makefile
# Build control file for the rEFInd boot menu
#

SRCDIR = .

VPATH = $(SRCDIR)

ifeq ($(ARCH),ia32)
  LIBEG = build32
endif

ifeq ($(ARCH),x86_64)
  LIBEG = build64
endif

LOCAL_CPPFLAGS  = -I$(SRCDIR) -I$(SRCDIR)/../include -I$(SRCDIR)/../libeg -DDEBIAN_VERSION="L\"$(DEBVER)\""
LOCAL_LDFLAGS   = -L$(SRCDIR)/../libeg/$(LIBEG)
LOCAL_LIBS      = -leg

OBJS            = main.o config.o menu.o screen.o icns.o lib.o
TARGET          = refind.efi

all: $(TARGET)

include $(SRCDIR)/../Make.common

# EOF
# DO NOT DELETE
