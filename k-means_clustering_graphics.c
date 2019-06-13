#include "grap.h"

struct Point{
  int category;                           // Group of point
  int x_coordinate, y_coordinate;         // Co-ordinate of point
  double distance;                        // Distance from test point
};

struct Cluster{
  int category;                           // Group of point
  int x_coordinate, y_coordinate;         // Co-ordinate of point
  int x_sum, y_sum;
  double x_mean, y_mean;
};

struct Point *points;
struct Cluster *point_centroid;
int point_counter = 0;
int centroid_counter = 0;
int EXIT_LOOPS = 0;
int iteration_counter = 0;
int points_in_category[10];
double distance;

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
    
    EXIT_LOOPS = 0;
    for (int i = 0; i < centroid_counter; i++){
      if (point_centroid[i].x_mean == point_centroid[i].x_coordinate 
        && point_centroid[i].y_mean == point_centroid[i].y_coordinate){
          EXIT_LOOPS++;
      }
      else{
        point_centroid[i].x_coordinate = point_centroid[i].x_mean;
        point_centroid[i].y_coordinate = point_centroid[i].y_mean;
      }
    }

    if (EXIT_LOOPS == centroid_counter){
      break;
    }
    
    iteration_counter++;
  }
}

 
int main(){
  points = (struct Point*)malloc(100 * sizeof(struct Point));
  point_centroid = (struct Cluster*)malloc(10 * sizeof(struct Cluster));
  printf("Hello\n");
  free(points);
  free(point_centroid);
  return 0;
}