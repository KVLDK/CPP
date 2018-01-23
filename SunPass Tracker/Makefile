#
# Makefile for SunPass Tracker
# 10/09/15
# Created by Professor Chris Lacher (FSU)
#

cflags = -I.
CC     = clang++ -std=c++11

AREA51  = /home/courses/cop3330p/LIB/area51

standard: tester.x tracker.x
assess:   testerStudent.x trackerHybrid1.x trackerHybrid2.x trackerStudent.x testerCorrect.x trackerCorrect.x
all:      standard assess

tester.x: tester.o shapes.o vehicles.o
        $(CC) -otester.x tester.o shapes.o vehicles.o

tracker.x: tracker.o vehicles.o shapes.o
        $(CC) -otracker.x tracker.o vehicles.o shapes.o

tracker.o: shapes.h vehicles.h tracker.cpp
        $(CC) $(cflags) -c tracker.cpp

tester.o: shapes.h vehicles.h tester.cpp
        $(CC) $(cflags) -c tester.cpp

shapes.o: shapes.h shapes.cpp
        $(CC) $(cflags) -c shapes.cpp

vehicles.o: shapes.h vehicles.h vehicles.cpp
        $(CC) $(cflags) -c vehicles.cpp

testerStudent.x: tester.o shapes.o vehicles.o
        $(CC) -otesterStudent.x tester.o shapes.o vehicles.o

testerCorrect.x: $(AREA51)/tester_i.x
        cp $(AREA51)/tester_i.x testerCorrect.x
        chmod 700 testerCorrect.x

trackerHybrid1.x: $(AREA51)/tracker_i.o vehicles.o shapes.o
        $(CC) -otrackerHybrid1.x $(AREA51)/tracker_i.o vehicles.o shapes.o

trackerHybrid2.x: tracker.o $(AREA51)/vehicles_i.o $(AREA51)/shapes_i.o
        $(CC) -otrackerHybrid2.x tracker.o $(AREA51)/vehicles_i.o $(AREA51)/shapes_i.o

trackerCorrect.x: $(AREA51)/tracker_i.x
        cp $(AREA51)/tracker_i.x trackerCorrect.x
        chmod 700 trackerCorrect.x

trackerStudent.x: tracker.o vehicles.o shapes.o
        $(CC) -otrackerStudent.x tracker.o vehicles.o shapes.o
