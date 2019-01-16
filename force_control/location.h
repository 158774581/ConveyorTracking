#pragma once
/*
* location.h
*
*  Created on: Nov 29, 2018
*      Author: root
*/

#ifndef ROBOT_CONTROL_LOCATION_INCLUDE_LOCATION_H_
#define ROBOT_CONTROL_LOCATION_INCLUDE_LOCATION_H_
//----------------------------------------------------------------------------
#include "type_def.h"
#include "robot_macro_def.h"
//----------------------------------------------------------------------------

#define			CONFIGURE_RIGHT				0x01
#define			CONFIGURE_LEFT				0x02
#define			CONFIGURE_ABOVE				0x04
#define			CONFIGURE_BELOW				0x08
#define			CONFIGURE_FLIP				0x10
#define			CONFIGURE_NOFLIP			0x20
#define			CONFIGURE_SINGLE			0x1000			//ֻ������ڵѿ����˶��������ǺϷ��ġ�
//----------------------------------------------------------------------------
// �����λ�����ͣ�Ĭ���ǵѿ�����ʽ
//----------------------------------------------------------------------------
typedef enum
{
	LOCATION_TYPE_CARTESIAN = 0,								//�ѿ�������ϵ��λ�ú���̬
	LOCATION_TYPE_ANGLES = 1,								//�Ƕ�
}LOCATION_TYPE;
//----------------------------------------------------------------------------
// ת�������Ƿ��쳣���⣬���������໥ת���������ǵ������
//----------------------------------------------------------------------------
typedef enum
{
	CONVERT_MODE_EXCEPTION = 0,								//���Ϊ0������һ���쳣��Ĭ����0
	CONVERT_MODE_IGNORE = 1,								//���Ϊ1����ô����ת���ı���.
}CONVERT_MODE;

//----------------------------------------------------------------------------
// ����zclearance�ķ����Ǹ���world����ϵ��z�����ǹ�������ϵ��z��
//----------------------------------------------------------------------------
typedef enum
{
	ZCLEARANCE_TYPE_TOOL = 0,								//���ݹ�������ϵ��z�� ����z��
	ZCLEARANCE_TYPE_WORLD = 1,								//����world����ϵ��z
}ZCLEARANCE_TYPE;
//----------------------------------------------------------------------------
// ���廭��Բ��ʱ��ĩ�˵����̬��α仯���Ǳ��ֺ���ʼһ�£����Ǹ��ݸ�����1��Ϊĩ�˵�
//----------------------------------------------------------------------------
typedef enum
{
	CIRCLE_POSE_SAME = 0,								//����������̬���仯
	CIRCLE_POSE_AUX1 = 1,								//���ݸ�����1����̬��Ϊ���յ���̬
}CIRCLE_POSE_TYPE;

//----------------------------------------------------------------------------
// ����ѿ����µĵ�λ ����ÿ��ֵ��������ڲο�����ϵ��ֵ
// �̶��ǣ�pitch ��x�ᣬyaw ��y�ᣬroll��z�� �̶��ǣ����ǰ�˳����ݹ̶�������ϵ������ת��
// ����x������y������z
//----------------------------------------------------------------------------
#pragma pack(4)
typedef struct LOCATION_CART
{
	double									x;									// x mm
	double 									y;									// y mm
	double									z;									// x mm
	double 									pitch;								// rotate about x deg
	double									yaw;								// rotate about y deg
	double 									roll;								// rotate about z deg
	double									ext1;								// ������1 mm/deg
	double									ext2;								// ������2 mm/deg
	double									ext3;								// ������3 mm/deg
}location_cart;
#pragma pack(0)
//----------------------------------------------------------------------------
//����ѿ����µ������壬����ʹ������ķ�ʽ����ѭ����ֵ�����ҿ��Ե���ʹ�����е�ĳ��ֵ���ȽϷ���
//----------------------------------------------------------------------------
typedef union
{
	location_cart		single;
	double				array[LOCATION_CART_DIMENSION_MAX];
}location_union;

//----------------------------------------------------------------------------
// location POS �����ѿ��������angle,��Ϊ����������ֻ�Ķ�pos������Ӱ��location���������õ�Ҫ��
//----------------------------------------------------------------------------
#pragma pack(4)
typedef struct LOCATION_POS
{
	double 									axis[ROBOT_MAX_AXIS];				//������ĵ�λ�� mm ���� deg
	location_union							cart;								//����ѿ����µĵ�λ
}location_pos;
#pragma pack(0)
//-------------------------------------------------------------------------------------
//����config����ͬ�Ļ������в�ͬ�����ã���ͬ�����õ�����ͬһ���ռ�λ�����в�ͬ�ĹؽڽǶȿ��Զ�Ӧ
//-------------------------------------------------------------------------------------
typedef struct	LOCATION_CONFIG
{
	Uint32		RIGHT : 1;												// �Ҽ����� shoulder
	Uint32		LEFT : 1;												// �Ҽ����� shoulder
	Uint32		ABOVE : 1;												// ��������Ϸ� elbow above twist
	Uint32		BELOW : 1;												// ��������·�

	Uint32		FLIP : 1;												// �������� wrist
	Uint32		NOFLIP : 1;												// �������
	Uint32		SINGLE : 1;												// ����������������180��֮�䣬�����������˶���Χ��

	Uint32		rsvd : 25;												// rsvd
}location_config;


typedef	union
{
	Uint32					all;
	location_config			bit;
}loc_cfg;

//----------------------------------------------------------------------------
// �����λ ��ĵ�λ����ʵ�ʻ���������ʹ��
//----------------------------------------------------------------------------
#pragma pack(4)
typedef struct ROBOT_LOCATION
{
	LOCATION_TYPE 							type;								//��λ���ͱ���
	ZCLEARANCE_TYPE 						zWorld;								//����߶�����������ϵ
	CIRCLE_POSE_TYPE						cirPoseType;						//����Բʱ����յ���̬
	Uint16									kinesol;							//���ݸñ�־�ж���δ���1 ����������е�ת�����󣬱���ؽڳ��޵ȣ�0���������ͱ���
	loc_cfg									config;								//����
	double									zclearance;							//z���������� mm
	location_pos							loc_pos;							//location��Ϣ�������ѿ����͹ؽ�
	location_cart							ref_frame;							//�ѿ�������ϵ�µ�λ�Ĳο�����ϵ
}robot_location;
#pragma pack(0)
#endif /* ROBOT_CONTROL_LOCATION_INCLUDE_LOCATION_H_ */
