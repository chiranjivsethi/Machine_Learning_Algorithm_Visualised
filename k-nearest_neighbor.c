#include <stdio.h>
#include <math.h>

struct Point{
    int catagory;     // Group of point
    double x_coordinate, y_coordinate;     // Co-ordinate of point
    double distance; // Distance from test point
};

int knn_classifier(struct Point points[], int size, int k,
  struct Point test_point, int number_of_catgory)
{
  int cat[number_of_catgory];
  for (int i = 0; i < number_of_catgory; i++) {
    cat[i] = 0;
  }

  // Calculating euclidian distance from test point and storing it
  for (int i = 0; i < size; i++)
      points[i].distance =
        sqrt((points[i].x_coordinate - test_point.x_coordinate) *
        (points[i].x_coordinate - test_point.x_coordinate) +
         (points[i].y_coordinate - test_point.y_coordinate) *
         (points[i].y_coordinate - test_point.y_coordinate));

  //sorting points according to distance (Bubble Sort)
  for (int m = 0; m < size-1; m++) {
    for (int n = 0; n < size-m-1; n++) {
      if (points[n].distance > points[n+1].distance) {
        struct Point temp;
        temp = points[n];
        points[n] = points[n+1];
        points[n+1] = temp;
      }
    }
  }

  for (int o = 0; o < k; o++){
    for (int p = 0; p < number_of_catgory; p++) {
      if (points[o].catagory == p) {
        cat[p] = cat[p] + 1;
        break;
      }
    }
  }

  int max_number,freq;
  max_number = cat[0];
  for (int i = 1; i < number_of_catgory; i++) {
    if (cat[i] > max_number) {
      max_number = cat[i];
      freq = i;
    }
  }
  return freq;
}

// Driver code
int main(int argc, char const *argv[])
{
    int n = 17; // Number of data points
    struct Point arr[n];
    int number_of_catgory = 2;

    arr[0].x_coordinate = 1;
    arr[0].y_coordinate = 12;
    arr[0].catagory = 0;

    arr[1].x_coordinate = 2;
    arr[1].y_coordinate = 5;
    arr[1].catagory = 0;

    arr[2].x_coordinate = 5;
    arr[2].y_coordinate = 3;
    arr[2].catagory = 1;

    arr[3].x_coordinate = 3;
    arr[3].y_coordinate = 2;
    arr[3].catagory = 1;

    arr[4].x_coordinate = 3;
    arr[4].y_coordinate = 6;
    arr[4].catagory = 0;

    arr[5].x_coordinate = 1.5;
    arr[5].y_coordinate = 9;
    arr[5].catagory = 1;

    arr[6].x_coordinate = 7;
    arr[6].y_coordinate = 2;
    arr[6].catagory = 1;

    arr[7].x_coordinate = 6;
    arr[7].y_coordinate = 1;
    arr[7].catagory = 1;

    arr[8].x_coordinate = 3.8;
    arr[8].y_coordinate = 3;
    arr[8].catagory = 1;

    arr[9].x_coordinate = 3;
    arr[9].y_coordinate = 10;
    arr[9].catagory = 0;

    arr[10].x_coordinate = 5.6;
    arr[10].y_coordinate = 4;
    arr[10].catagory = 1;

    arr[11].x_coordinate = 4;
    arr[11].y_coordinate = 2;
    arr[11].catagory = 1;

    arr[12].x_coordinate = 3.5;
    arr[12].y_coordinate = 8;
    arr[12].catagory = 0;

    arr[13].x_coordinate = 2;
    arr[13].y_coordinate = 11;
    arr[13].catagory = 0;

    arr[14].x_coordinate = 2;
    arr[14].y_coordinate = 5;
    arr[14].catagory = 1;

    arr[15].x_coordinate = 2;
    arr[15].y_coordinate = 9;
    arr[15].catagory = 0;

    arr[16].x_coordinate = 1;
    arr[16].y_coordinate = 7;
    arr[16].catagory = 0;

    /*Test Point*/
    struct Point p;
    p.x_coordinate = 2.5;
    p.y_coordinate = 7;

    int k = round(sqrt(n));

    printf ("The catagory classified of test point"
            " is %d.\n %d is used for value of k\n"
              , knn_classifier(arr, n, k, p, number_of_catgory)
                ,k);
    return 0;
}

// Created by Chiranjiv Sethi on 24/Aug/2018
