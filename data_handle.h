#include <stdbool.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

struct Point{
  int category;                           // Group of point
  int x_coordinate, y_coordinate;         // Co-ordinate of point
  double distance;                        // Distance from test point
};

struct Cluster{
  int category;                           // Group of point
  int x_coordinate, y_coordinate;         // Co-ordinate of point
  int x_sum, y_sum;
  bool captured;
  double x_mean, y_mean;
};

struct Point *points;
struct Cluster *point_centroid;
int point_counter = 0;
int centroid_counter = 0;
int points_in_category[5];
int iteration_counter = 0;
int exit_loops;
int max_iteration;
int time_delay;
char category[10];

void capture_point(int c,int x,int y){
  points[point_counter].category = c;
  points[point_counter].x_coordinate = x;
  points[point_counter].y_coordinate = y;
  point_counter++;
}

void capture_centroid(int c,int x,int y){
  point_centroid[c].category = c;
  point_centroid[c].x_coordinate = x;
  point_centroid[c].y_coordinate = y;
  centroid_counter++;
}

double cal_euclidean_distance(int i,int j){
  double distance = sqrt((points[i].x_coordinate - point_centroid[j].x_coordinate) *
    (points[i].x_coordinate - point_centroid[j].x_coordinate) +
    (points[i].y_coordinate - point_centroid[j].y_coordinate) *
    (points[i].y_coordinate - point_centroid[j].y_coordinate));
  return distance;
}

void set_capture_flag(){
  for (int i = 0; i < centroid_counter; i++){
      point_centroid[i].captured = false;
    }
}

void set_value(){
  for (int i = 0; i < point_counter; i++){
      points[i].distance = 9999;
    }
    for (int i = 0; i < centroid_counter; i++){
      point_centroid[i].x_sum = 0;
      point_centroid[i].y_sum = 0;
      point_centroid[i].x_mean = 0;
      point_centroid[i].y_mean = 0;
      points_in_category[i] = 0; 
    }
}

void print_data(){
  printf("\nPoints:\n");
  for (int i = 0; i < point_counter; i++){
    printf("X-Coordinate: %d Y-Coordinate: %d Distance: %f Category: %d\t\t\t\t\t[%d]\n",
      points[i].x_coordinate,points[i].y_coordinate,points[i].distance,points[i].category,i+1);   
  }
  printf("\nCentroids\n");
  for (int i = 0; i < centroid_counter; i++){
    if(point_centroid[i].category == 0){
       printf("X-Coordinate: %d Y-Coordinate: %d category: Red\t\t\t\t\t[%d]\n",
          point_centroid[i].x_coordinate,point_centroid[i].y_coordinate,i+1);
    }
    if(point_centroid[i].category == 1){
      printf("X-Coordinate: %d Y-Coordinate: %d category: Green\t\t\t\t\t[%d]\n",
          point_centroid[i].x_coordinate,point_centroid[i].y_coordinate,i+1);
    }
    if(point_centroid[i].category == 2){
      printf("X-Coordinate: %d Y-Coordinate: %d category: Blue\t\t\t\t\t[%d]\n",
          point_centroid[i].x_coordinate,point_centroid[i].y_coordinate,i+1);
    }
    if(point_centroid[i].category == 3){
      printf("X-Coordinate: %d Y-Coordinate: %d category: Yellow\t\t\t\t\t[%d]\n",
          point_centroid[i].x_coordinate,point_centroid[i].y_coordinate,i+1);
    }
    if(point_centroid[i].category == 4){
      printf("X-Coordinate: %d Y-Coordinate: %d category: Orange\t\t\t\t\t[%d]\n",
          point_centroid[i].x_coordinate,point_centroid[i].y_coordinate,i+1);
    }
  }
}