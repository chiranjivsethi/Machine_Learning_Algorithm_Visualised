#include "graphics.h"
#include "data_handle.h"

void  kmeans_clustering(){
  set_value();
  
  do{
    int i,j;
    for (i = 0; i < point_counter; i++){
      for (j = 0; j < centroid_counter; j++){
        double distance = cal_euclidean_distance(i,j);
        if(distance < points[i].distance){
          points[i].distance = distance;
          points[i].category = point_centroid[j].category;
          points_in_category[points[i].category]++;
        }
      } 
    }

    for (i = 0; i < point_counter; i++){
      for(j = 0; j < centroid_counter; j++){
        if (point_centroid[j].category == points[i].category){
          point_centroid[j].x_sum = point_centroid[j].x_sum + points[i].x_coordinate;
          point_centroid[j].y_sum = point_centroid[j].y_sum + points[i].y_coordinate;
        }
      }
    }

    for (i = 0; i < centroid_counter; i++){
      point_centroid[i].x_mean = point_centroid[i].x_sum / points_in_category[i];
      point_centroid[i].y_mean = point_centroid[i].y_sum / points_in_category[i];
    }
    
    for (i = 0; i < centroid_counter; i++){
      if (point_centroid[i].x_coordinate == point_centroid[i].x_mean &&
        point_centroid[i].y_coordinate == point_centroid[i].y_mean){
        exit_loops++;
      }
      else{
        point_centroid[i].x_coordinate = point_centroid[i].x_mean;
        point_centroid[i].y_coordinate = point_centroid[i].y_mean;
      }
    }
    iteration_counter++;
    max_iteration--;
    if(max_iteration == 0){
      break;
    }
  }while (exit_loops != centroid_counter);
}

void keyboard(unsigned char Key, int x, int y){
  int category, xi, yi;
  switch(Key){
    case 'A':
        print_data();
      break;
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
          xi,yi,centroid_counter);
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
          xi,yi,centroid_counter);
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
          printf("Centroid Captured\n");
          printf("X-Coordinate: %d Y-Coordinate: %d category: Green\t\t\t\t\t[%d]\n",
          xi,yi,centroid_counter);
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
          xi,yi,centroid_counter);
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
          printf("Centroid Captured\n");
          printf("X-Coordinate: %d Y-Coordinate: %d category: Blue\t\t\t\t\t[%d]\n",
          xi,yi,centroid_counter);
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
          xi,yi,centroid_counter);
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
          printf("Centroid Captured\n");
          printf("X-Coordinate: %d Y-Coordinate: %d category: Yellow\t\t\t\t\t[%d]\n",
          xi,yi,centroid_counter);
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
          xi,yi,centroid_counter);
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
          printf("Centroid Captured\n");
          printf("X-Coordinate: %d Y-Coordinate: %d category: Orange\t\t\t\t\t[%d]\n",
          xi,yi,centroid_counter);
        }
        else{
          printf("If you want to recapture cenroid press \'Shift + o\' \n");
        }
        break;
      case 'O':
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
          printf("X-Coordinate: %d Y-Coordinate: %d category: Orange\t\t\t\t\t[%d]\n",
          xi,yi,centroid_counter);
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
        printf("X-Coordinate: %d Y-Coordinate: %d\t\t\t\t\t[%d]\n",
          xi,yi,point_counter);
        break; 
      case 13:
        printf("\n");
        printf("Applying KMC...\n");
        kmeans_clustering();
        printf("\nIterations: %d\n",iteration_counter);
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
  printf("Enter Maximum Number of iterations: \n");
  scanf("%d",&max_iteration);
  set_capture_flag();
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