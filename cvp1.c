/*********************************************************/
/*  cvp1.c                                               */
/*                                                       */
/*  Deep Learning                                        */
/*  畳み込みとプーリング処理                             */
/*                                                       */
/*********************************************************/
#include "cvp1.h"

/*********************************************************/
/*  畳み込みとプーリング処理 関数                        */
/*********************************************************/

/*********************************************************/
/*  init_filter関数: フィルターの初期化                  */
/*********************************************************/
void init_filter(Filter *flt){
	
	/*  縦フィルター   */
	flt->filter[0][0] = 0;
	flt->filter[0][1] = 1;
	flt->filter[0][2] = 0;
	flt->filter[1][0] = 0;
	flt->filter[1][1] = 1;
	flt->filter[1][2] = 0;
	flt->filter[2][0] = 0;
	flt->filter[2][1] = 1;
	flt->filter[2][2] = 0;
	
	/*  横フィルター   */
	/*
	flt->filter[0][0] = 0;
	flt->filter[0][1] = 0;
	flt->filter[0][2] = 0;
	flt->filter[1][0] = 1;
	flt->filter[1][1] = 1;
	flt->filter[1][2] = 1;
	flt->filter[2][0] = 0;
	flt->filter[2][1] = 0;
	flt->filter[2][2] = 0;
	*/
	
}


/*********************************************************/
/*  get_filter関数: フィルター出力                       */
/*********************************************************/
void get_filter(Filter *flt){
	
	int i=0, j=0;
	
	printf("*** Filter ( %d x %d ) ***\n", FILTERSIZE, FILTERSIZE);
	for(i=0; i < FILTERSIZE; ++i){
		for(j=0; j < FILTERSIZE; ++j){
			printf("%lf\t", flt->filter[i][j]);
		}
		printf("\n");
	}
	
}


/*********************************************************/
/*  conv関数: 畳み込みの計算                             */
/*********************************************************/
void conv(Filter *flt, Lrndata *lrndata, Convout *cvout){
	
	int i=0, j=0;
	int startpoint = FILTERSIZE / 2;    //  畳み込み範囲の下限
	
	// debug_info
	// printf("startpoint = %d\n", startpoint);
	
	for(i = startpoint; i < INPUTSIZE - startpoint; ++i){
		for(j = startpoint; j < INPUTSIZE - startpoint; ++j){
			cvout->convout[i][j] = calcconv(flt, lrndata, i, j);
		}
	}
	
}


/*********************************************************/
/*  calcconv関数: フィルタの適用                         */
/*********************************************************/
double calcconv(Filter *flt, Lrndata *lrndata, int i, int j){
	
	int m=0, n=0;
	double sum = 0;
	
	for(m=0; m < FILTERSIZE; ++m){
		for(n=0; n < FILTERSIZE; ++n){
			sum += lrndata->ldata[i - FILTERSIZE / 2 + m][j - FILTERSIZE / 2 + n] * flt->filter[m][n];
		}
	}
	
	return sum;
}


/*********************************************************/
/*  get_convout関数: 畳み込み処理結果出力                */
/*********************************************************/
void get_convout(Convout *cvout){
	
	int i=0, j=0;
	
	printf("*** Convout ( %d x %d ) ***\n", INPUTSIZE - 2, INPUTSIZE - 2);
	for(i = 1; i < INPUTSIZE - 1; ++i){
		for(j = 1; j < INPUTSIZE - 1; ++j){
			printf("%.3lf ", cvout->convout[i][j]);
		}
		printf("\n");
	}
	
}


/*********************************************************/
/*  pool関数: プーリングの計算                           */
/*********************************************************/
void pool(Convout *cvout, Poolout *plout){
	
	int i=0, j=0;
	
	for(i=0; i < POOLOUTSIZE; ++i){
		for(j=0; j < POOLOUTSIZE; ++j){
			plout->poolout[i][j] = maxpooling(cvout, i, j);
		}
	}
}


/*********************************************************/
/*  maxpooling関数: プーリングの計算                     */
/*********************************************************/
double maxpooling(Convout *cvout, int i, int j){
	
	int m=0, n=0;
	double max;
	int halfpool = POOLSIZE / 2;   //  プーリングのサイズの1/2
	
	max = cvout->convout[i * POOLOUTSIZE + 1 + halfpool][j * POOLOUTSIZE + 1 + halfpool];
	
	for(m = POOLOUTSIZE * i + 1; m <= POOLOUTSIZE * i + 1 + (POOLSIZE - halfpool); ++m){
		for(n = POOLOUTSIZE * j + 1; n <= POOLOUTSIZE * j + 1 + (POOLSIZE - halfpool); ++n){
			if(max < cvout->convout[m][n]) max = cvout->convout[m][n];
		}
	}
	
	return max;
}


/*********************************************************/
/*  get_poolout関数: プーリング処理結果出力              */
/*********************************************************/
void get_poolout(Poolout *plout){
	
	int i=0, j=0;
	
	printf("*** Poolout ( %d x %d ) ***\n", POOLOUTSIZE, POOLOUTSIZE);
	for(i=0; i < POOLOUTSIZE; ++i){
		for(j=0; j < POOLOUTSIZE; ++j){
			printf("%.3lf ", plout->poolout[i][j]);
		}
		printf("\n");
	}
	
}


