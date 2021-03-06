#include <stdio.h>
#define MAP_HEIGHT 4 
#define MAP_WIDTH 5


void mat_print(int mat[MAP_HEIGHT][MAP_WIDTH]){ 
		
		for(int i=0;i<MAP_HEIGHT;i++){ 
				for(int j=0;j<MAP_WIDTH;j++){
						printf("%d\t",mat[i][j]);
				}
				printf("\n");
		}
}
	

int min(int a,int b,int c,int *num){
	int min = a;
	*num = 1;
	if(min > b){min = b;*num = 2;}
	if(min > c){min = c;*num = 3;}
	return min;
}





int main(){


	int map[MAP_HEIGHT][MAP_WIDTH] = { 
			{1,10,2,3,1},
			{3,2,3,9,10},
			{2,5,5,4,1},
			{3,3,3,5,2}
	};

	printf("<map>\n");
	mat_print(map);


	int value[MAP_HEIGHT][MAP_WIDTH] = {};
	int route[MAP_HEIGHT][MAP_WIDTH] = {};//1:上 2:斜め 3:左

	value[0][0] = map[0][0];

	for(int i=1;i<MAP_HEIGHT;i++){value[i][0] = value[i-1][0] + map[i][0];route[i][0] = 1;}
	for(int i=1;i<MAP_WIDTH;i++){value[0][i] = value[0][i-1] + map[0][i];route[0][i] = 3;}

	printf("\n<value_preb>\n");
	mat_print(value);

	printf("\n<route_prev>\n");
	mat_print(route);
	
	
	for(int i=1;i<MAP_HEIGHT;i++){
		for(int j=1;j<MAP_WIDTH;j++){

			int up = value[i-1][j] + map[i][j];
			int diagonal = value[i-1][j-1] + 2 * map[i][j];	
			int left = value[i][j-1] + map[i][j];
			value[i][j] = min(up,diagonal,left, &route[i][j]);

		}
	}

	printf("\n<value>\n");
	mat_print(value);

	printf("\n<route>\n");
	mat_print(route);
	
	
	int route_image[MAP_HEIGHT][MAP_WIDTH] = {};
	int x,y,r;
	x = MAP_HEIGHT-1; 
	y = MAP_WIDTH-1;
	r = route[MAP_HEIGHT-1][MAP_WIDTH-1];

	while(r){
			r = route[x][y];
			route_image[x][y] = 1;
			if(r == 1)x--;
			if(r == 2){x--;y--;}
			if(r == 3)y--;
	} 

	printf("\n<route_image>\n");
	mat_print(route_image);

	return 0;
}



