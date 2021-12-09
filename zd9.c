#include <stdio.h>
#include <stdlib.h>


int main(void) {
  int i,j,n,m,k, x,y,t,cells,a=0;
  scanf("%d%d", &m,&n);
  scanf("%d", &k);
  int *matrix;
  matrix = (int*)calloc(n*m,sizeof(int));
  for (t = 0; t<k; t++) {
    scanf("%d%d",&x,&y);
    *(matrix+(x-1)*m+y-1) = 1;
  }
  cells = n*m-k;
  
  while (cells) {
    a++;
    for (i = 0; i<n; i++)
      for (j = 0; j<m; j++) 
        if (*(matrix+i*m+j)==a) {
          if (j+1<m && *(matrix+i*m+j+1)==0) {
            *(matrix+i*m+j+1)=a+1;
            cells--;
          }
          if (i>0 && *(matrix+(i-1)*m+j)==0 ) {
            *(matrix+(i-1)*m+j)=a+1;
            cells--;
          }
          if (i+1<n && *(matrix+(i+1)*m+j)==0) {
            *(matrix+(i+1)*m+j)=a+1;
            cells--;
          }
          if (j>0 && *(matrix+i*m+j-1)==0) {
            *(matrix+i*m+j-1)=a+1;
            cells--;
          }
        }
  }
  printf("%d\n", a);
  return 0;
}
