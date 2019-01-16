#pragma once
/*
* robot_macro_def.h
*
*  Created on: Nov 28, 2018
*      Author: root
*/

#ifndef ROBOT_CONTROL_UTILITY_INCLUDE_ROBOT_MACRO_DEF_H_
#define ROBOT_CONTROL_UTILITY_INCLUDE_ROBOT_MACRO_DEF_H_


//-------------------------------------------------------------------

#define 		ROBOT_MAX_AXIS   									12								//һ����������������
#define 		ROBOT_MAX_CART   									ROBOT_MAX_AXIS - 2 				//һ�����������ĵѿ�������Ĭ�������������2��xyzƽ���˶�����һ��cartesian��ÿ��
#define			ROBOT_MAX_MOTOR										ROBOT_MAX_AXIS					//һ�������˵����������Ĭ�Ϻ�����һ�¡�

#define			LOCATION_CART_DIMENSION_MAX							9								//�ѿ����µ�λ���ά������������������ᣬһ����9
//-------------------------------------------------------------------

#define 		PRM_FROM_EX_MEM_EN  								ENABLE							//�������ⲿ�洢�豸���г�ʼ������ȡ�ⲿ�Ĳ����ļ�

//-------------------------------------------------------------------
#define 		MOTION_MODULE_CONSTANT_MIN_POSITIVE 				((double)1.0E-10)				//������С�������������С��Ϊ��0
//-------------------------------------------------------------------
#define 		TRAJECTORY_MODULE_DIMENSION_OF_XYZ_FRAME 			((Uint8) 3)						//�ѿ���λ�õ�ά��
#define 		TRAJECTORY_MODULE_DIMENSION_OF_ROT_FRAME 			((Uint8) 3)						//�ѿ�����̬��ά��
#endif /* ROBOT_CONTROL_UTILITY_INCLUDE_ROBOT_MACRO_DEF_H_ */
