ifeq ($(OS), win)
	TOOLCHAIN := x86_64-w64-mingw32.shared-
	TERMINAL := -mwindows
	APP := initialisation.exe
else
	TOOLCHAIN :=
	TERMINAL :=
	APP := initialisation
endif

CXX=$(TOOLCHAIN)g++
LD=$(TOOLCHAIN)ld
AR=$(TOOLCHAIN)ar
PKG_CONFIG=$(TOOLCHAIN)pkg-config

OBJS = main.o window.o preset_combobox.o origin_combobox.o destination_combobox.o
FLAGS = $(TERMINAL) -std=c++11 -MMD -ffunction-sections -fdata-sections	


$(APP): $(OBJS)
	$(CXX) $(FLAGS) `$(PKG_CONFIG) --cflags gtkmm-3.0` -o $(APP) $(OBJS) `$(PKG_CONFIG) --libs gtkmm-3.0` -Wl,-gc-sections

%.o : %.c++
	$(CXX) $(FLAGS) `$(PKG_CONFIG) --cflags gtkmm-3.0` -o $@ -c $< `$(PKG_CONFIG) --libs gtkmm-3.0`

clean:
	rm *.o
	rm -f *.d 

-include $(OBJS:.o=.d)

