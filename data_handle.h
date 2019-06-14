#include <stdbool.h>
#include <math.h>

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

char str_category(int c){
  if(c == 0){
    char str[] = "Red";
    return str;
  }
  else if(c == 1){
    char str[] = "Green";
    return str;
  }
  else if(c == 2){
    char str[] = "Blue";
    return str;
  }
  else if(c == 3){
    char str[] = "Yellow";
    return str;
  }
  else if(c == 4){
    char str[] = "Orange";
    return str;
  }
}

void print_point(struct Cluster p){
  printf("Point:");
  printf("X-Coordinate: %d Y-Coordinate: %dcategory: %s\n\t\t\t\t[%d]",
        p.x_coordinate,p.y_coordinate, str_category(p.category),centroid_counter);
}

double cal_euclidean_distance(int i,int j){
  double distance = sqrt((points[i].x_coordinate - point_centroid[j].x_coordinate) *
    (points[i].x_coordinate - point_centroid[j].x_coordinate) +
    (points[i].y_coordinate - point_centroid[j].y_coordinate) *
    (points[i].y_coordinate - point_centroid[j].y_coordinate));
  return distance;
}