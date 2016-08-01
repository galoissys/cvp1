/*********************************************************/
/*  lrnproc.c                                            */
/*                                                       */
/*  階層型ニューロネットプログラム                       */
/*  学習機                                               */
/*  畳み込みとプーリング処理                             */
/*                                                       */
/*********************************************************/
#include "lrnproc.h"

int lrnproc(){
	
	/* 構造体のメモリ確保 */
	
	// 学習データ構造体
	Lrndata *plrndata;
	plrndata = (Lrndata *)malloc(sizeof(Lrndata));
	//initldata(plrndata);
	
	//  畳み込みとプーリング処理関連構造体
	Filter *pflt;
	pflt = (Filter *)malloc(sizeof(Filter));
	
	Convout *pconv;
	pconv = (Convout *)malloc(sizeof(Convout));
	
	Poolout *ppool;
	ppool = (Poolout *)malloc(sizeof(Poolout));
	
	/* 構造体のメモリ確保完了 */
	
	
	// 学習データをセット
	setldata(plrndata);
	// debug_info
	getldata(plrndata);
	
	//  フィルター初期化
	init_filter(pflt);
	get_filter(pflt);
	
	
	// sleep(5);
	
	
	//  畳み込みの計算
	conv(pflt, plrndata, pconv);
	get_convout(pconv);
	
	//  プーリングの計算
	pool(pconv, ppool);
	get_poolout(ppool);
	
	
	// メモリ解放
	free(plrndata);
	free(pflt);
	free(pconv);
	free(ppool);
	
	return 0;
	
}


