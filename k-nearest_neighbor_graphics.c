#include "graphics.h"
#include <stdbool.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

struct Point{
  int category;                           // Group of point
  int x_coordinate, y_coordinate;      // Co-ordinate of point
  double distance;                        // Distance from test point
};

struct Point *points,test_point;
int point_counter = 0;
int number_of_category = 5;
int test_point_flag = 0;
int frequency_of_category[5];

void capture_point(int c,int x,int y){
  points[point_counter].category = c;
  points[point_counter].x_coordinate = x;
  points[point_counter].y_coordinate = y;
  point_counter = point_counter + 1;
}

int knn_classifier(){

  //Calculating K value using formula k = sqrt(number of points)
  int k = round(sqrt( point_counter));
  printf("Value of K: %d\n", k);          

  for (int i = 0; i < number_of_category; i++) {
    frequency_of_category[i] = 0;
  }

  for (int i = 0; i <  point_counter; i++){
    draw_line(points[i].x_coordinate, points[i].y_coordinate,
    test_point.x_coordinate, test_point.y_coordinate,0);
      
    //Calculating Eculidian Distance
    points[i].distance = 
      sqrt((points[i].x_coordinate - test_point.x_coordinate) *
      (points[i].x_coordinate - test_point.x_coordinate) +
      (points[i].y_coordinate - test_point.y_coordinate) *
      (points[i].y_coordinate - test_point.y_coordinate));
  
    delay(100);

    draw_line(points[i].x_coordinate, points[i].y_coordinate,
      test_point.x_coordinate, test_point.y_coordinate,1);
    draw_point(test_point.x_coordinate, test_point.y_coordinate,
      test_point.category);

    for (int j = 0; j <  point_counter; j++) {
      draw_point(points[j].x_coordinate, points[j].y_coordinate,
      points[j].category);
    }
  }

  for (int i = 0; i <  point_counter; i++) {
    draw_point(points[i].x_coordinate, points[i].y_coordinate,
    points[i].category);
  }

  //sorting points according to distance (Bubble Sort)
  for (int i = 0; i <  point_counter-1; i++) {
    for (int j = 0; j <  point_counter-i-1; j++) {
      if (points[j].distance > points[j+1].distance) {
        struct Point temp;
        temp = points[j];
        points[j] = points[j+1];
        points[j+1] = temp;
      }
    }
  }

  for (int i = 0; i < k; i++){
    draw_line(points[i].x_coordinate, points[i].y_coordinate,
    test_point.x_coordinate, test_point.y_coordinate,2);
    
    delay(100);
    
    for (int j = 0; j < number_of_category; j++) {
      if (points[i].category == j) {
        frequency_of_category[j] = frequency_of_category[j] + 1;
        break;
      }
    }
  }

  //calculate class of object depending on top k object 
  int max_number,class;
  max_number = frequency_of_category[0];
  for (int i = 1; i < number_of_category; i++) {
    if (frequency_of_category[i] > max_number) {
      max_number = frequency_of_category[i];
      class = i;
    }
  }
  return class;
}

void keyboard(unsigned char Key, int x, int y){
  int category, xi, yi;
  switch(Key){
    case 'r':
        category=0;
        xi = x;
        yi = (480-y);
        capture_point(category,xi,yi);
        draw_point(xi,yi,category);
        printf("X-Coordinate: %d Y-Coordinate: %d category: Red\t\t\t\t\t[%d]\n",
        xi,yi,point_counter);
        break;
    case 'g':
        category=1;
        xi = x;
        yi = (480-y);
        capture_point(category,xi,yi);
        draw_point(xi,yi,category);
        printf("X-Coordinate: %d Y-Coordinate: %d category: Green\t\t\t\t\t[%d]\n",
        xi,yi,point_counter);
        break;
      case 'b':
        category=2;
        xi = x;
        yi = (480-y);
        capture_point(category,xi,yi);
        draw_point(xi,yi,category);
        printf("X-Coordinate: %d Y-Coordinate: %d category: Blue\t\t\t\t\t[%d]\n",
        xi,yi,point_counter);
        break;
      case 'y':
        category=3;
        xi = x;
        yi = (480-y);
        capture_point(category,xi,yi);
        draw_point(xi,yi,category);
        printf("X-Coordinate: %d Y-Coordinate: %d category: Yellow\t\t\t\t\t[%d]\n",
        xi,yi,point_counter);
        break;
      case 'o':
        category=4;
        xi = x;
        yi = (480-y);
        capture_point(category,xi,yi);
        draw_point(xi,yi,category);
        printf("X-Coordinate: %d Y-Coordinate: %d category: Orange\t\t\t\t\t[%d]\n",
        xi,yi,point_counter);
        break;
      case 't':
        if(test_point_flag == 0){
          category = -1;
          xi = x;
          yi = (480-y);
          test_point.x_coordinate = xi;
          test_point.y_coordinate = yi;
          test_point.category = category;
          draw_point(xi,yi,category);
          printf("\n");
          printf("Test Point:\n");
          printf("X-Coordinate: %d Y-Coordinate: %d\n",
          test_point.x_coordinate, test_point.y_coordinate);
          test_point_flag = 1;
          }
        break; 
      case 'L':
        points[point_counter].x_coordinate = test_point.x_coordinate;
        points[point_counter].y_coordinate = test_point.y_coordinate;
        points[point_counter].category = test_point.category;
        point_counter++;
        display();
        for (int i = 0; i < point_counter; i++ ){
          draw_point(points[i].x_coordinate,points[i].y_coordinate,points[i].category);
        }
        test_point_flag = 0;
        break;
      case 'R':
        display();
        for (int i = 0; i < point_counter; i++ ){
          draw_point(points[i].x_coordinate,points[i].y_coordinate,points[i].category);
        }
        test_point_flag = 0;
        break;
      case 'N':
        free(points);
        points = (struct Point*)malloc(100 * sizeof(struct Point));
        point_counter = 0;
        test_point_flag = 0;
        test_point.x_coordinate = 0;
        test_point.y_coordinate = 0;
        test_point.category = -2;
        display();
        draw_point(0,0,-2);
        break;

      case 13:
        printf("\n");
        printf("Applying KNN...\n");
        test_point.category = knn_classifier();
        printf("Test Point:\n");
        printf("X-Coordinate: %d Y-Coordinate: %d category: %d\n",
        test_point.x_coordinate,test_point.y_coordinate,
        test_point.category);
        draw_point(test_point.x_coordinate, test_point.y_coordinate,
        test_point.category);
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
// Created by Chiranjiv Sethi on 17/Sept/2018