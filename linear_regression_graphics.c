#include "graphics.h"
#include <stdbool.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

struct Point{
    double x_coordinate, y_coordinate;
    int flag;
};

double predicted_y, b0 = 0, b1 = 0, learning_rate = 0.001, error;
int epoches = 1;

struct Point *points,test_point;
int point_counter = 0;

void capture_point(int x,int y){
    points[point_counter].x_coordinate = x;
    points[point_counter].y_coordinate = y;
    point_counter = point_counter + 1;
}

void capture_test_points(int x, int y){
  test_point.x_coordinate = x;
  test_point.y_coordinate = y;
  test_point.flag = 1;
  printf("\nTest Point :\n\tX-Coordinate: %d Y-Coordinate: %d\n",
  x,y);
}

void linear_reg(){
  predicted_y = b0 * points[0].x_coordinate + b1;
  draw_line(0,b1,640,b0 * 640 + b1,0);
  delay(200);
  draw_line(0,b1,640,b0 * 640 + b1,1);
  for(int e = 0; e < point_counter; e++){
    draw_point(points[e].x_coordinate,points[e].y_coordinate,1);
  }
  error = predicted_y - points[0].y_coordinate;
    for (int i = 0; i < epoches; i ++){
      for(int j=1 ; j<=point_counter ; j++){
        b0 = b0 - learning_rate * error;
        b1 = b1 - learning_rate * error * points[j].x_coordinate;
        predicted_y = b0 * points[j].x_coordinate + b1;
        error = predicted_y - points[j].y_coordinate;
        draw_line(0,b1,640,b0 * 640 + b1,0);
        delay(200);
        draw_line(0,b1,640,b0 * 640 + b1,1);
        for(int e = 0; e < point_counter; e++){
          draw_point(points[e].x_coordinate,points[e].y_coordinate,1);
        }
      }
    }
    delay(200);
    draw_line(0,b1,640,b0 * 640 + b1,2);
    printf("y = %gx + %g\n\n",b0,b1);
    double y_new = b0*test_point.x_coordinate + b1;
    printf("%g\n",y_new); 
    delay(200);
    draw_point(test_point.x_coordinate,test_point.y_coordinate,0);
    draw_line(test_point.x_coordinate,0,test_point.x_coordinate,480,3);
    draw_point(test_point.x_coordinate,y_new,2);
}

void keyboard(unsigned char Key, int x, int y){
  int category, xi, yi;
  switch(Key){
    case 't':
        xi = x;
        yi = (480-y);
        capture_point(xi,yi);
        draw_point(xi,yi,1);
        printf("X-Coordinate: %d Y-Coordinate: %d\t\t\t[%d]\n",
        xi,yi,point_counter);
        break;
      case 'b':
        xi = x;
        yi = (480-y);
        if(test_point.flag == 0){
          capture_test_points(xi,yi);
          draw_point(xi,yi,2);
          printf("\n");
          printf("Test Point:\n");
          printf("X-Coordinate: %d Y-Coordinate: %d\n",xi,yi);
        }
        break; 
      case 13:
        printf("Applying Linear Regression\n");
        linear_reg();
        break;
      case 27:
        printf("Exit...\n");
        glutDestroyWindow(1);
        break;
  }
}

int main(int argc, char** argv) {
  points = (struct Point*)malloc(100 * sizeof(struct Point));
  glutInit(&argc,argv);
  glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
  glutInitWindowSize(640,480);
  glutCreateWindow("K-Nearest Neighbor");
  glutDisplayFunc(display);
  glViewport(0,0,640.0,480.0);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluOrtho2D(0.0,640.0,0.0,480.0);
  glMatrixMode(GL_MODELVIEW);
  glPointSize(10);
  glutKeyboardFunc(keyboard);
  glutMainLoop();
  return 0;
}