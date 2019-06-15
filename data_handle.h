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
int iteration_counter;
int exit_loops;
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

void set_value(){
  for (int i = 0; i < point_counter; i++){
      points[i].distance = 9999;
    }
    for (int i = 0; i < centroid_counter; i++){
      point_centroid[i].x_sum = 0;
      point_centroid[i].y_sum = 0;
      point_centroid[i].x_mean = 0;
      point_centroid[i].y_mean = 0;
      point_centroid[i].captured = false;
      points_in_category[i] = 0; 
    }
}

void print_points(){
  for (int i = 0; i < point_counter; i++)
  {
    /* code */
  }
  
}