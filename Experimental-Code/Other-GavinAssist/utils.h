// -----------------------------------
// CSCI 340 - Operating Systems I
// Spring 2023 (Anthony Leclerc)
// utils.c implementation file
// Homework Assignment 1
//
// -----------------------------------

#define DEBUG 0	// 1 turns on debug printf(); 0 turns debugging off
/*
  To use in your implemention, you can do this:
  .
  . // compute stuff
  .
#if DEBUG == 1
  printf("some debugging information relevant to computation above\n");
#endif
  .
  .
  .
*/
// NOTE:  You can easily turn off ALL debugging by setting DEBUG to 1

// C data structure for representing a point
typedef struct {
    double x;
    double y;
} point_t;      // can now declare a point type variable like so:  point_t p;

// C data structure for representing a line
typedef struct {
    point_t p0;
    point_t p1;
} line_t;       // can now declare a line type variable like so:   line_t l;

// function prototype for reading a text file containg multiple line_t values
// (see assignment PDF for the format of this file)
int read_lines(char* filename, line_t* line_arr, int n);
// parameters: 	filename --- name of text file containing line_t values
//	      	line_arr --- pointer to 1st element of an array of line_t values
//              n        --- number of elements in line_arr
/*
  steps in order this function performs:

  *** NOTE: In the steps below, you CANNOT use fscanf() nor sscanf().
  Using either of these two functions in your solution will result in
  significant point loss! ***

  1. open the text file named, filename, for reading


  2. for each line_t defined in the text file, BUT NO MORE than n lines:

     a) read the line_t value consisting of two point values (ie 4
        doubles) into a string variable.  USE fgets() to read the line:
	https://stackoverflow.com/questions/3501338/c-read-file-line-by-line

     b) keep track of the number of lines you have read

     c) split (parse) the string using the comma character as the
        delimiter into 4 substring parts. NOTE: a string in C is a
        character pointer (ie. char*) which can also be treated as a
        character array.  For example filename[0] will return the char
        value of the string at index position 0

     d) convert each of the 4 string parts into doubles.  NOTE: you
        MUST use the atof() function.

     e) store each of the 4 double values into the correct point_t
        structures of the line AND at the correct index position in
        line_arr. NOTE: The position of the line in the text file
        matches the index position in line_arr.

  3. close the file

  4. return the number (int) of lines read by this function
*/

// function prototype that uses the point values of the line structure
// to compute the angle IN RADIANS formed by this line
double calc_direction(line_t* line_ptr);
// parameter: line_ptr --- points to a line_t structure
// formula:   given p0=(x0,y0) and p1=(x1,y1), dir=atan2(y1-y0,x1-x0)
// return:    double value representing the angle formed by this line

// function prototype that uses the point values of the line structure
// to compute the magnitude of the line (ie. length)
double calc_magnitude(line_t* line_ptr);
// parameter: line_ptr --- points to a line_t structure
// formula:   given p0=(x0,y0) and p1=(x1,y1), mag=sqrt((x1-x0)^2+(y1-y0)^2)
// return:    double value representing the magnitude of the line
