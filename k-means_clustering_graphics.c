#include "grap.h"
#include <stdbool.h>

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

void keyboard(unsigned char Key, int x, int y){
  int category, xi, yi;
  switch(Key){
    case 'r':
        category=0;
        xi = x;
        yi = (480-y);
        if(point_centroid[category].captured == false){
          point_centroid[category].captured = true;
          capture_centroid(category,xi,yi);
          draw_centroid(xi,yi,category);
          printf("Centroid Captured\n");
          printf("X-Coordinate: %d Y-Coordinate: %d category: Red\t\t\t\t\t[%d]\n",
          xi,yi,point_counter);
        }
        else{
          printf("If you want to recapture cenroid press \'Shift + r\' \n");
        }
        break;
    case 'R':
        category=0;
        xi = x;
        yi = (480-y);
        draw_centroid(point_centroid[category].x_coordinate,point_centroid[category].y_coordinate
          ,-2);
        point_centroid[category].captured = false;
        centroid_counter--;
        if(point_centroid[category].captured == false){
          point_centroid[category].captured = true;
          capture_centroid(category,xi,yi);
          draw_centroid(xi,yi,category);
          printf("Centroid Recaptured\n");
          printf("X-Coordinate: %d Y-Coordinate: %d category: Red\t\t\t\t\t[%d]\n",
          xi,yi,point_counter);
        }
        break;
    case 'g':
        category=1;
        xi = x;
        yi = (480-y);
        if(point_centroid[category].captured == false){
          point_centroid[category].captured = true;
          capture_centroid(category,xi,yi);
          draw_centroid(xi,yi,category);
          printf("X-Coordinate: %d Y-Coordinate: %d category: Green\t\t\t\t\t[%d]\n",
          xi,yi,point_counter);
        }
        else{
          printf("If you want to recapture cenroid press \'Shift + g\' \n");
        }
        break;
      case 'G':
        category=1;
        xi = x;
        yi = (480-y);
        draw_centroid(point_centroid[category].x_coordinate,point_centroid[category].y_coordinate
          ,-2);
        point_centroid[category].captured = false;
        centroid_counter--;
        if(point_centroid[category].captured == false){
          point_centroid[category].captured = true;
          capture_centroid(category,xi,yi);
          draw_centroid(xi,yi,category);
          printf("Centroid Recaptured\n");
          printf("X-Coordinate: %d Y-Coordinate: %d category: Green\t\t\t\t\t[%d]\n",
          xi,yi,point_counter);
        }
        break;
      case 'b':
        category=2;
        xi = x;
        yi = (480-y);
        if(point_centroid[category].captured == false){
          point_centroid[category].captured = true;
          capture_centroid(category,xi,yi);
          draw_centroid(xi,yi,category);
          printf("X-Coordinate: %d Y-Coordinate: %d category: Blue\t\t\t\t\t[%d]\n",
          xi,yi,point_counter);
        }
        else{
          printf("If you want to recapture cenroid press \'Shift + b\' \n");
        }
        break;
      case 'B':
        category=2;
        xi = x;
        yi = (480-y);
        draw_centroid(point_centroid[category].x_coordinate,point_centroid[category].y_coordinate
          ,-2);
        point_centroid[category].captured = false;
        centroid_counter--;
        if(point_centroid[category].captured == false){
          point_centroid[category].captured = true;
          capture_centroid(category,xi,yi);
          draw_centroid(xi,yi,category);
          printf("Centroid Recaptured\n");
          printf("X-Coordinate: %d Y-Coordinate: %d category: Blue\t\t\t\t\t[%d]\n",
          xi,yi,point_counter);
        }
        break;
      case 'y':
        category=3;
        xi = x;
        yi = (480-y);
        if(point_centroid[category].captured == false){
          point_centroid[category].captured = true;
          capture_centroid(category,xi,yi);
          draw_centroid(xi,yi,category);
          printf("X-Coordinate: %d Y-Coordinate: %d category: Yellow\t\t\t\t\t[%d]\n",
          xi,yi,point_counter);
        }
        else{
          printf("If you want to recapture cenroid press \'Shift + y\' \n");
        }
        break;
      case 'Y':
        category=3;
        xi = x;
        yi = (480-y);
        draw_centroid(point_centroid[category].x_coordinate,point_centroid[category].y_coordinate
          ,-2);
        point_centroid[category].captured = false;
        centroid_counter--;
        if(point_centroid[category].captured == false){
          point_centroid[category].captured = true;
          capture_centroid(category,xi,yi);
          draw_centroid(xi,yi,category);
          printf("Centroid Recaptured\n");
          printf("X-Coordinate: %d Y-Coordinate: %d category: Yellow\t\t\t\t\t[%d]\n",
          xi,yi,point_counter);
        }
        break;
      case 'o':
        category=4;
        xi = x;
        yi = (480-y);
        if(point_centroid[category].captured == false){
          point_centroid[category].captured = true;
          capture_centroid(category,xi,yi);
          draw_centroid(xi,yi,category);
          printf("X-Coordinate: %d Y-Coordinate: %d category: Orange\t\t\t\t\t[%d]\n",
          xi,yi,point_counter);
        }
        else{
          printf("If you want to recapture cenroid press \'Shift + o\' \n");
        }
        break;
      case 'O':
        category=4;
        xi = x;
        yi = (480-y);
        draw_centroid(point_centroid[category].x_coordinate,point_centroid[category].y_coordinate
          ,-2);
        point_centroid[category].captured = false;
        centroid_counter--;
        if(point_centroid[category].captured == false){
          point_centroid[category].captured = true;
          capture_centroid(category,xi,yi);
          draw_centroid(xi,yi,category);
          printf("Centroid Recaptured\n");
          printf("X-Coordinate: %d Y-Coordinate: %d category: Orange\t\t\t\t\t[%d]\n",
          xi,yi,point_counter);
        }
        break;
      case 't':
        category = -1;
        xi = x;
        yi = (480-y);
        capture_point(category,xi,yi);
        draw_point(xi,yi,category);
        printf("\n");
        printf("Point:\n");
        printf("X-Coordinate: %d Y-Coordinate: %d\n",
        xi,yi);
        break; 
      case 13:
        printf("\n");
        printf("Applying KMC...\n");
        kmeans_clustering();
        break;
      case 27:
        printf("Exit...\n");
        glutDestroyWindow(1);
        break;
  }
}
 
int main(int argc, char** argv){
  points = (struct Point*)malloc(100 * sizeof(struct Point));
  point_centroid = (struct Cluster*)malloc(10 * sizeof(struct Cluster));
  for (int i = 0; i < 5; i++){
    point_centroid[i].captured = false;
  }
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
  free(points);
  free(point_centroid);
  return 0;
}