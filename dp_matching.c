#include <stdio.h>
#define MAP_HEIGHT 3 
#define MAP_WIDTH 4


void mat_print(int mat[MAP_HEIGHT][MAP_WIDTH]){ 
		
		for(int i=0;i<MAP_HEIGHT;i++){ 
				for(int j=0;j<MAP_WIDTH;j++){
						printf("%d\t",mat[i][j]);
				}
				printf("\n");
		}
}
	

int min(int a,int b,int c){
	int min = a;
	if(min > b)min = b;
	if(min > c)min = c;
	return min;
}


int main(){


	int map[MAP_HEIGHT][MAP_WIDTH] = { 
			{1,2,2,3},
			{3,2,3,9},
			{2,5,5,4}
	};

	printf("<map>\n");
	mat_print(map);


	int value[MAP_HEIGHT][MAP_WIDTH];

	value[0][0] = map[0][0];

	for(int i=1;i<MAP_HEIGHT;i++)value[i][0] = value[i-1][0] + map[i][0];
	for(int i=1;i<MAP_WIDTH;i++)value[0][i] = value[0][i-1] + map[0][i];

	printf("\n<value_preb>\n");
	mat_print(value);
	
	
	for(int i=1;i<MAP_HEIGHT;i++){
		for(int j=1;j<MAP_WIDTH;j++){

			int up = value[i][j-1] + map[i][j];
			int left = value[i-1][j] + map[i][j];
			int diagonal = value[i-1][j-1] + 2 * map[i][j];	

			value[i][j] = min(up,left,diagonal);

		}
	}

	printf("\n<value>\n");
	mat_print(value);
	
	
	return 0;
}



