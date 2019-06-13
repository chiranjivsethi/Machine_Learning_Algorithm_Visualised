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

void kmeans_clustering(){
  while (1){
    for (int i = 0; i < point_counter; i++){
      
    }
    
  }
  
}
 
int main(){
  points = (struct Point*)malloc(100 * sizeof(struct Point));
  point_centroid = (struct Cluster*)malloc(100 * sizeof(struct Cluster));
  printf("Hello\n");
  free(points);
  free(point_centroid);
  return 0;
}