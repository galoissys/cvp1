/*********************************************************/
/*  lrndata.c                                            */
/*                                                       */
/*********************************************************/
#include "lrndata.h"

/*********************************************************/
/*  initldata�֐�                                         */
/*********************************************************/
void initldata(Lrndata *lrndata){
	
	int i=0, j=0;
	
	memset(lrndata, 0, sizeof(Lrndata));
	
	for(i=0; i < INPUTSIZE; ++i){
		for(j=0; j < INPUTSIZE; ++j){
			lrndata->ldata[i][j] = 0.0;
		}
	}
	
	
}


/*********************************************************/
/*  setldata�֐�                                         */
/*********************************************************/
void setldata(Lrndata *lrndata){
	
	int i=0, j=0;
	
	while( scanf("%lf", &lrndata->ldata[i][j]) != EOF){
		++j;
		if(j >= INPUTSIZE){  //  ���̃f�[�^
			j = 0;
			++i;
			if(i >= INPUTSIZE) break;  //  ���͏I��
		}
	}
	
	/*
	for(i=0; i < R_MAX; ++i){
		for(j=0; j < IN_NUM + OUT_NUM; ++j){
			scanf("%lf", &lrndata->ldata[i][j]);
		}
	}
	*/
	
}


/*********************************************************/
/*  getldata�֐�                                         */
/*********************************************************/
void getldata(Lrndata *lrndata){
	
	int i=0, j=0;
	
	printf("*** INPUT Data Set ( %d x %d ) ***\n", INPUTSIZE, INPUTSIZE);
	
	for(i=0; i < INPUTSIZE; ++i){
		for(j=0; j < INPUTSIZE; ++j){
			printf("%lf ", lrndata->ldata[i][j]);
		}
		printf("\n");
	}
	
}



