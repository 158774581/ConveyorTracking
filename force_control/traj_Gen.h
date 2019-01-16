#pragma once
/*
* traj_Gen.h
*
*  Created on: mar 15, 2018
*      Author: root
*/

#ifndef ROBOT_CONTROL_TRAJECTORY_GENERATOR_INCLUDE_TRAJECTORY_GENERATOR_H_1
#define ROBOT_CONTROL_TRAJECTORY_GENERATOR_INCLUDE_TRAJECTORY_GENERATOR_H_1
//--------------------------------------------------------------------------
#include "traj_profile.h"
#include "type_def.h"
#include "robot_macro_def.h"
#include "location.h"

//�����˶���ʱ��Ҫ���������
//---------------------------------------------------------------------------
#pragma pack(4)
typedef struct MB_INSERT
{
	//-------------------------------------------------------------------------------
	Uint8 		type;			//����ģ����˶�����
	//-------------------------------------------------------------------------------
	//�ö��˶��ͽ����㶨��
	//-------------------------------------------------------------------------------
	robot_location    		loc_end;
	//-------------------------------------------------------------------------------
	// �����㶨�壬����Բ������Բ
	//-------------------------------------------------------------------------------
	robot_location    		loc_aux;
	robot_location    		loc_aux1;
	//-------------------------------------------------------------------------------
	//�����˶��滮����������blending
	//-------------------------------------------------------------------------------
	profile_prm				prf;
	blend_prm				bld;
	double					start_vel[6];
	double					end_vel[6];
	//-------------------------------------------------------------------------------
	//ָ����ʼλ��
	//-------------------------------------------------------------------------------
	Uint8					pos_start_assigned;  
	robot_location    		loc_start;
}mb_insert;


#endif /* TRAJECTORY_GENERATOR_H_1_ */