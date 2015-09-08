CC              = g++
CC_OBJ_FLAGS    = -c -fPIC
CC_Shared_FLAGS = -shared -Wl,-soname,libtcs.so
ROOT_CFLAGS     = $(shell root-config --cflags)
ROOT_LIBS       = $(shell root-config --libs)

toollibs:	Slice_Fitter.o SliceFitterDict.o
		rm -f toollibs.so* SliceFitterDict_rdict.pcm src/SliceFitterDict.cc
		$(CC) $(CC_Shared_FLAGS) -o $@.so.1.0.1 Slice_Fitter.o SliceFitterDict.o
		ln -s $@.so.1.0.1 $@.so.1; ln -s $@.so.1.0.1 $@.so
		ln -s src/SliceFitterDict_rdict.pcm .

Slice_Fitter.o: src/Slice_Fitter.cxx src/SliceFitterDict.cc
		$(CC) $(CC_OBJ_FLAGS) src/Slice_Fitter.cxx -o $@ $(ROOT_CFLAGS) -I./include

SliceFitterDict.o:	src/SliceFitterDict.cc
			$(CC) $(CC_OBJ_FLAGS) $? -o $@ $(ROOT_CFLAGS) -I./

src/SliceFitterDict.cc:	include/Slice_Fitter.h include/MyLinkDef.h
			rootcint -f $@ 	-c $?


clean:          
		rm -f *.so* *.o
