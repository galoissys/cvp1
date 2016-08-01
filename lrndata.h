/*********************************************************/
/*  lrndata.h                                            */
/*                                                       */
/*  �K�w�^�j���[���l�b�g�v���O����                       */
/*  �w�K�f�[�^�Z�b�g                                     */
/*                                                       */
/*********************************************************/
#ifndef _LRNDATA_H_
#define _LRNDATA_H_

#include <stdio.h>
#include <string.h>
#include "lcommon.h"

/*  �w�K�f�[�^�Z�b�g �f�[�^�\��                          */

typedef struct{
	double ldata[INPUTSIZE][INPUTSIZE];  //  ���̓f�[�^
} Lrndata;

/*  �w�K�f�[�^�Z�b�g �֐�                                */
void initldata(Lrndata *lrndata);
void setldata(Lrndata *lrndata);
void getldata(Lrndata *lrndata);


#endif

