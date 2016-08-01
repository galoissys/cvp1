/*********************************************************/
/*  lrnproc.c                                            */
/*                                                       */
/*  �K�w�^�j���[���l�b�g�v���O����                       */
/*  �w�K�@                                               */
/*  ��ݍ��݂ƃv�[�����O����                             */
/*                                                       */
/*********************************************************/
#include "lrnproc.h"

int lrnproc(){
	
	/* �\���̂̃������m�� */
	
	// �w�K�f�[�^�\����
	Lrndata *plrndata;
	plrndata = (Lrndata *)malloc(sizeof(Lrndata));
	//initldata(plrndata);
	
	//  ��ݍ��݂ƃv�[�����O�����֘A�\����
	Filter *pflt;
	pflt = (Filter *)malloc(sizeof(Filter));
	
	Convout *pconv;
	pconv = (Convout *)malloc(sizeof(Convout));
	
	Poolout *ppool;
	ppool = (Poolout *)malloc(sizeof(Poolout));
	
	/* �\���̂̃������m�ۊ��� */
	
	
	// �w�K�f�[�^���Z�b�g
	setldata(plrndata);
	// debug_info
	getldata(plrndata);
	
	//  �t�B���^�[������
	init_filter(pflt);
	get_filter(pflt);
	
	
	// sleep(5);
	
	
	//  ��ݍ��݂̌v�Z
	conv(pflt, plrndata, pconv);
	get_convout(pconv);
	
	//  �v�[�����O�̌v�Z
	pool(pconv, ppool);
	get_poolout(ppool);
	
	
	// ���������
	free(plrndata);
	free(pflt);
	free(pconv);
	free(ppool);
	
	return 0;
	
}


