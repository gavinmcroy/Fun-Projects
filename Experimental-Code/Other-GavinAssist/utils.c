//
// Created by Gavin T McRoy on 1/31/2023.
//
// -----------------------------------
// CSCI 340 - Operating Systems I
// Spring 2023 (Anthony Leclerc)
// utils.c implementation file
// Homework Assignment 1
//
// -----------------------------------

// these are the ONLY library header files that can be used. Under no
// circumstances can additional library header files be included.  In
// particular, this restriction means you CANNOT USE any function
// declared in <string.h>, which includes functions such as: strtok(),
// strchr(), strstr(), strlen(), index(), and others.

// NOTE: when you compile, DO NOT IGNORE WARNINGS!  These warnings are
// likely indicating you are doing something wrong, such as using a
// library function that you are not allowed to use or passing the
// wrong type of argument into a function.

#include <stdio.h>    // standard I/O functions
#include <stdlib.h>    // atof()
#include <math.h>    // math functions
#include <string.h>

#include "utils.h"    // user defined functions

// see utils.h for the required function prototypes and specifications

// NOTE: you may add any "helper" functions you need to get the job done.
//       for example, if you need to determine the length of a string.

// put your IMPLEMENTATION of the function prototypes below:
int read_lines(char *filename, line_t *line_arr, int n) {
    //Reading in the file
    FILE *myFile;
    myFile = fopen(filename, "r");
    char myArray[128];
    int lineNumber = 0;

    while (fgets(myArray, 80, myFile)) {
        char buffer[128];
        int bufferIterator = 0;
        int lineCounter = 0;
        point_t p0;
        point_t p1;
        line_t line;

        double values[4];
        int valueIterator = 0;
        while (myArray[lineCounter] != '\0') {
            if (myArray[lineCounter] == ',' || myArray[lineCounter] == '\n') {
                buffer[bufferIterator + 1] = '\0';
                values[valueIterator] = atof(buffer);
                memset(buffer, 0, 128);
                //printf("%lf ", values[valueIterator]);
                bufferIterator = 0;
                valueIterator++;
            } else {
                buffer[bufferIterator] = myArray[lineCounter];
                bufferIterator++;
            }
            lineCounter++;
        }

        p0.x = values[0];
        p0.y = values[1];
        p1.x = values[2];
        p1.y = values[3];
        line.p0 = p0;
        line.p1 = p1;
        line_arr[lineNumber] = line;
        lineNumber++;
    }
    return lineNumber;
}


double calc_direction(line_t *line_ptr) {

    double angle = 0;

    //int y1 =
    //int y0 =
    //int x1 =
    //int x0 =


    //angle = aTanZ(y1 - y0, x1 - x0);

    return angle;
}

double calc_magnitude(line_t *line_ptr) {

    double magnitude = 0;

    //int y1 =
    //int y0 =
    //int x1 =
    //int x0 =


    //magnitude = sqrt((x1 - x0)^2 + (y1 - y0)^2);

    return magnitude;
}
