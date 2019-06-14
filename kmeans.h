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
double distance;

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

void kmeans_clustering(){
  while (1){
      
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
    
    for (int i = 0; i < point_counter; i++){
      for (int j = 0; j < centroid_counter; j++){
       
        distance = sqrt((points[i].x_coordinate - point_centroid[j].x_coordinate) *
          (points[i].x_coordinate - point_centroid[j].x_coordinate) +
          (points[i].y_coordinate - point_centroid[j].y_coordinate) *
          (points[i].y_coordinate - point_centroid[j].y_coordinate));
       
        if(distance < points[i].distance){
          points[i].distance = distance;
          points[i].category = point_centroid[j].category;
          points_in_category[points[i].category]++;
          
        }
      } 
    }

    for (int i = 0; i < point_counter; i++){
      for(int j = 0; j < centroid_counter; j++){
        if (point_centroid[j].category == points[i].category){
          point_centroid[j].x_sum = point_centroid[j].x_sum + points[i].x_coordinate;
          point_centroid[j].y_sum = point_centroid[j].y_sum + points[i].y_coordinate;
        }
      }
    }

    for (int i = 0; i < centroid_counter; i++){
      point_centroid[i].x_mean = point_centroid[i].x_sum / points_in_category[i];
      point_centroid[i].y_mean = point_centroid[i].y_sum / points_in_category[i];
    }
    
    exit_loops = 0;
    for (int i = 0; i < centroid_counter; i++){
      if (point_centroid[i].x_coordinate == point_centroid[i].x_mean &&
      point_centroid[i].y_coordinate == point_centroid[i].y_mean){
        exit_loops++;
      }
      else{
        point_centroid[i].x_coordinate = point_centroid[i].x_mean;
        point_centroid[i].y_coordinate == point_centroid[i].y_mean;
      }
    }
    
    if (exit_loops == centroid_counter){
      break;
    }
    iteration_counter++;
  } 
}