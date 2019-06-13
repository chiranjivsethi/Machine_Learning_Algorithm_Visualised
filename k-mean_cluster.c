#include <stdio.h>
#include <math.h>

struct point{
      int catagory;     // Catagory of point (closest cluster catagory)
      double x_coordinate, y_coordinate; // Co-ordinate of point
      double distance; // Distance from closest cluster_point
  };

void kmean_cluster(struct point points[],
   struct point cluster_points[],
   int number_points, int number_cluster) {
     double distance0,distance1;
     double x_mean_cluster0;
     double y_mean_cluster0;
     double x_mean_cluster1;
     double y_mean_cluster1;
     double x_sum0, y_sum0;
     double x_sum1, y_sum1;
     int cat0_counter, cat1_counter;
     int itration_counter = 0;

     printf("\n");
     printf("Points :\n");
     printf("Sno. \tX-Coordinate \tY-Coodinate \n");
     for (int i = 0; i < number_points; i++) {
       printf("%d \t%lf \t%lf \n",i+1,points[i].x_coordinate,
       points[i].y_coordinate);
     }

     printf("\n");
     printf("Cluster :\n");
     printf("Sno. \tX-Coordinate \tY-Coodinate \tCatagory \n");
     for (int i = 0; i < number_cluster; i++) {
       printf("%d \t%lf \t%lf \t %d\n",i+1,cluster_points[i].x_coordinate,
       cluster_points[i].y_coordinate,cluster_points[i].catagory);
     }

     while (1) {
       for (int i = 0; i < number_points; i++) {
         distance0 = sqrt((cluster_points[0].x_coordinate - points[i].x_coordinate) *
         (cluster_points[0].x_coordinate - points[i].x_coordinate) +
         (cluster_points[0].y_coordinate - points[i].y_coordinate) *
         (cluster_points[0].y_coordinate - points[i].y_coordinate));

         distance1 = sqrt((cluster_points[1].x_coordinate - points[i].x_coordinate) *
         (cluster_points[1].x_coordinate - points[i].x_coordinate) +
         (cluster_points[1].y_coordinate - points[i].y_coordinate) *
         (cluster_points[1].y_coordinate - points[i].y_coordinate));

         if (distance0 < distance1) {
           points[i].distance = distance0;
           points[i].catagory = cluster_points[0].catagory;
         }
         else{
           points[i].distance = distance1;
           points[i].catagory = cluster_points[1].catagory;
         }
       }

       //
       x_sum0 = 0;
       y_sum0 = 0;
       x_sum1 = 0;
       y_sum1 = 0;
       cat0_counter = 0;
       cat1_counter = 0;
       for (int i = 0; i < number_points; i++) {
         if (points[i].catagory == 0){
           cat0_counter++;
           x_sum0 = x_sum0 + points[i].x_coordinate;
           y_sum0 = y_sum0 + points[i].y_coordinate;
         }
         if (points[i].catagory == 1){
           x_sum1 = x_sum1 + points[i].x_coordinate;
           y_sum1 = y_sum1 + points[i].y_coordinate;
           cat1_counter++;
         }
       }
       x_mean_cluster0 = x_sum0/cat0_counter;
       y_mean_cluster0 = y_sum0/cat0_counter;
       x_mean_cluster1 = x_sum1/cat1_counter;
       y_mean_cluster1 = y_sum1/cat1_counter;

       if (cluster_points[0].x_coordinate == x_mean_cluster0 &&
            cluster_points[0].y_coordinate == y_mean_cluster0 &&
            cluster_points[1].x_coordinate == x_mean_cluster1 &&
            cluster_points[1].y_coordinate == y_mean_cluster1) {
         break;
       }
       else{
         cluster_points[0].x_coordinate = x_mean_cluster0;
         cluster_points[0].y_coordinate = y_mean_cluster0;
         cluster_points[1].x_coordinate = x_mean_cluster1;
         cluster_points[1].y_coordinate = y_mean_cluster1;
       }

       itration_counter++;
     }

     printf("\nCluster :\n");
     printf("Sno. \tX-Coordinate \tY-Coodinate \tCatagory \n");
     for (int i = 0; i < number_cluster; i++) {
       printf("%d \t%lf \t%lf \t %d\n",i+1,cluster_points[i].x_coordinate,
       cluster_points[i].y_coordinate,cluster_points[i].catagory);
     }
     printf("\n");

     printf("Points :\n");
     printf("Sno. \tX-Coordinate \tY-Coodinate \tCatagory\n");
     for (int i = 0; i < number_points; i++) {
       printf("%d \t%lf \t%lf \t%d \n",i+1,points[i].x_coordinate,
       points[i].y_coordinate,points[i].catagory);
     }

     printf("\n No of Itraions : %d\n\ns",itration_counter);
}

int main(int argc, char const *argv[]) {
  int n = 18;
  int k = 2;
  struct point points[n];
  struct point cluster_points[k];

  // Initializing cluster_points
    cluster_points[0].x_coordinate = 1;
    cluster_points[0].y_coordinate = 4;
    cluster_points[1].x_coordinate = 6;
    cluster_points[1].y_coordinate = 0;
    cluster_points[0].catagory = 0;
    cluster_points[1].catagory = 1;

  // Initializing points
    points[0].x_coordinate = 0.5;
    points[0].y_coordinate = 12;

    points[1].x_coordinate = 0.75;
    points[1].y_coordinate = 13;

    points[2].x_coordinate = 0.65;
    points[2].y_coordinate = 10.5;

    points[3].x_coordinate = 1;
    points[3].y_coordinate = 11;

    points[4].x_coordinate = 1.5;
    points[4].y_coordinate = 13.5;

    points[5].x_coordinate = 1.5;
    points[5].y_coordinate = 9;

    points[6].x_coordinate = 1.75;
    points[6].y_coordinate = 8.5;

    points[7].x_coordinate = 0.25;
    points[7].y_coordinate = 10;

    points[8].x_coordinate = 1.65;
    points[8].y_coordinate = 11.95;

    points[9].x_coordinate = 5.5;
    points[9].y_coordinate = 2.5;

    points[10].x_coordinate = 5.75;
    points[10].y_coordinate = 2.75;

    points[11].x_coordinate = 5.25;
    points[11].y_coordinate = 6;

    points[12].x_coordinate = 5;
    points[12].y_coordinate = 5.2;

    points[13].x_coordinate = 4.75;
    points[13].y_coordinate = 4;

    points[14].x_coordinate = 6.125;
    points[14].y_coordinate = 4.2;

    points[15].x_coordinate = 5.25;
    points[15].y_coordinate = 4.2;

    points[16].x_coordinate = 5.5;
    points[16].y_coordinate = 5.79;

    points[17].x_coordinate = 6.25;
    points[17].y_coordinate = 7;

    kmean_cluster(points, cluster_points, n, k);

  return 0;
}

//Created by Chiranjiv Sethi on 4/sept/2018
