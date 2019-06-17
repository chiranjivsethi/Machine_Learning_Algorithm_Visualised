#include <GL/glut.h>
#include <time.h>

void draw_line(int x1, int y1, int x2, int y2, int flag) {
  if (flag == 0) {
    glColor3f(0.0,0.0,0.0);                 //Black Color
  }
  if (flag == 1) {
    glColor3f(1.0,1.0,1.0);                 //White Color
  }
  if (flag == 2) {
    glColor3f(1.0,0.0,1.0);                 //Purble Color
  }
  glBegin(GL_LINES);                        //Draw Line
    glVertex2f(x1,y1);
    glVertex2f(x2,y2);
  glEnd();
  glFlush();
}

void draw_point(int x,int y, int c){
  glPointSize(7);
  if (c == -2){
    glColor3f(1.0,1.0,1.0);             // White Color
  }
  if (c == -1) {
    glColor3f(0.0,0.0,0.0);             // Black Color
  }
  if (c == 0){
    glColor3f(1.0,0.0,0.0);             // Red Color
  }
  if (c == 1) {
    glColor3f(0.0,1.0,0.0);             // Green Color     
  }
  if (c == 2) {
    glColor3f(0.0,0.0,1.0);             // Blue Color
  }
  if (c == 3) {
    glColor3f(1.0,1.0,0.0);             // Yellow Color
  }
  if (c == 4) {
    glColor3f(1.0,0.5,0.0);             // Orange Color
  }
    glPointSize(10.0);
    glEnable(GL_POINT_SMOOTH);
    glBegin(GL_POINTS);
      glVertex2f(x,y);                  //Draw Point
    glEnd();
    glFlush();
}

void draw_centroid(int x,int y, int c){
  glPointSize(10);
  if (c == -2){
    glColor3f(1.0,1.0,1.0);             // White Color
  }
  if (c == 0){
    glColor3f(1.0,0.0,0.0);             // Red Color
  }
  if (c == 1) {
    glColor3f(0.0,1.0,0.0);             // Green Color     
  }
  if (c == 2) {
    glColor3f(0.0,0.0,1.0);             // Blue Color
  }
  if (c == 3) {
    glColor3f(1.0,1.0,0.0);             // Yellow Color
  }
  if (c == 4) {
    glColor3f(1.0,0.5,0.0);             // Orange Color
  }
    glPointSize(10.0);
    glDisable(GL_POINT_SMOOTH);
    glBegin(GL_POINTS);
      glVertex2f(x,y);                  //Draw Centroid
    glEnd();
    glFlush();
}

void display(){
  glClearColor(1.0, 1.0, 1.0, 1.0);
  glClear(GL_COLOR_BUFFER_BIT);
}

void delay(int number_of_seconds){                   // Time Delay Function
  int milli_seconds = 1000 * number_of_seconds;
  clock_t start_time = clock();
  while (clock() < start_time + milli_seconds);
} 
