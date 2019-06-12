#include "grap.h"

struct Point{
  int category;                           // Group of point
  int x_coordinate, y_coordinate;         // Co-ordinate of point
  double distance;                        // Distance from test point
};

struct Point *points, cluster_centroid;

void kmeans_clustering(){

}

void keyboard(unsigned char Key, int x, int y){
int category, xi, yi;
  switch(Key){
      case ''
  }
}

int main(int argc, char** argv){
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