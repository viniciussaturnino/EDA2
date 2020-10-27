#include <stdio.h>
#include <stdlib.h>

typedef struct restaurant {
  int code;
  int grade;
} Restaurant;

int main() {
  int n, code, grade, day = 1;
  Restaurant restaurant;
  while(scanf("%d", &n) == 1) {
    for(int i=0; i<n; i++){
      scanf("%d %d", &code, &grade);
      if(i==0) {
        restaurant.code = code;
        restaurant.grade = grade;
      }
      if(grade > restaurant.grade) {
        restaurant.code = code;
        restaurant.grade = grade;
      }
      else if(grade == restaurant.grade) {
        if(code < restaurant.code) {
          restaurant.code = code;
          restaurant.grade = grade;
        }
      }
    }
    printf("Dia %d\n%d\n\n", day, restaurant.code);
    day++;
  }
  return 0;
}