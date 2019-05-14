#include <stdio.h>
#define MAP_HEIGHT 3 
#define MAP_WIDTH 3


void mat_print(int mat[MAP_HEIGHT][MAP_WIDTH]){ 
		
		for(int i=0;i<MAP_HEIGHT;i++){ 
				for(int j=0;j<MAP_WIDTH;j++){
						printf("%d\t",mat[i][j]);
				}
				printf("\n");
		}
}
	

int main(){

	int map[MAP_HEIGHT][MAP_WIDTH] = { 
			{1,2,2},
			{3,2,3},
			{2,5,5}
	};


	int value[MAP_HEIGHT][MAP_WIDTH];

	value[0][0] = map[0][0];

	for(int i=1;i<MAP_HEIGHT;i++)value[i][0] = value[i-1][0] + map[i][0];
	for(int i=1;i<MAP_WIDTH;i++)value[0][i] = value[0][i-1] + map[0][i];
	

		
	mat_print(value);
	
	
	return 0;
}



