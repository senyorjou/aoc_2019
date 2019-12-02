#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int max(int a, int b){
  if (a >= b){
    return a;
  }
  else{
    return b;
  }
}


int compute_fuel(int mass){
  double rounded = floor(mass/3.0);
  return max((int)rounded - 2, 0);
}


int main(void){
  FILE * in_file  = fopen("day01exe01.input.txt", "r");
  char * line = NULL;
  size_t len = 0;

  if (in_file == NULL){
    printf("Error! Input file not found");
    exit(1);
  }

  long total_fuel = 0;

  while ((getline(&line, &len, in_file)) != -1){
    int mass = atoi(line);
    int fuel = compute_fuel(mass);
    total_fuel = total_fuel + fuel;
  }

  printf("TOTAL FUEL: %li", total_fuel);

  fclose(in_file);
  return 0;
}
