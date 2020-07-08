#include <stdio.h>

int n;
int k;
int A[100000];

int p(int x){
    int i, people, left;
    people = 1;
    left = x;
    for(i = 0; i < n; i++){
        if(left >= A[i]){
            left = left - A[i];
        }
        else{
            people = people + 1;
            left = x;
            if(left < A[i]) return 0;
            left = left - A[i];
        }
    }
    return (people <= k);
}

int main(){
  int i, lb, ub;
  scanf("%d%d", &n, &k);
  for(i = 0; i < n; i++){
    scanf("%d", &A[i]);
  }
  lb = 0;
  ub = 1000000000;
  while(ub - lb > 1){
      int mid = (lb + ub) / 2;
      if(p(mid)){
          ub = mid;
      }
      else{
          lb = mid;
      }
  }
  printf("%d\n", ub);

  return 0;
}
