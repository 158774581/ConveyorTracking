#pragma once
/*
* profile.h
*
*  Created on: Nov 28, 2018
*      Author: root
*/

#ifndef ROBOT_CONTROL_ROBOT_MODULE_ROBOT_PROFILE_TRAJECTORY_GENERATOR_INCLUDE_ROBOT_PROFILE_H_
#define ROBOT_CONTROL_ROBOT_MODULE_ROBOT_PROFILE_TRAJECTORY_GENERATOR_INCLUDE_ROBOT_PROFILE_H_
//----------------------------------------------------------------------------
#include "type_def.h"
#include "robot_macro_def.h"
//----------------------------------------------------------------------------
// �㵽���˶����õķ�ʽ
//----------------------------------------------------------------------------
typedef enum
{
	P2P_JOINT_INTEPOLATE_METHOD = 0,								//�㵽����ùؽڲ岹��������ĩ���ߵ�·���Ƿ���ֱ�ߡ�
	P2P_CARTESIAN_INTEPOLATE_LINE_METHOD = 1									//�㵽����ÿռ�ֱ�߲岹
}P2P_STRAIGHT;
//----------------------------------------------------------------------------
// �˶���λ����
//----------------------------------------------------------------------------
typedef enum
{
	INRANGE_TYPE_NO_STOP = 0,								//��ֹͣ
	INRANGE_TYPE_STOP_CMD_REACHED = 1,								//����������λ���������
	INRANGE_TYPE_STOP_WITH_CONSTRAINT = 2								    //����λ���������
}INRANGE_TYPE;
//----------------------------------------------------------------------------
//blending������
//----------------------------------------------------------------------------
typedef enum
{
	BLENDING_TYPE_NONE = 0,														//û��blending
	BLENDING_TYPE_AUTO = 1,														//�Զ�blending����һ�εļ��ٶκ͵ڶ��εļ��ٶν���blending
	BLENDING_TYPE_TIME = 2,														//ʱ��blending�����ݸ�����ʱ�䣬
	BLENDING_TYPE_DISTANCE = 3,														//����blending�����ݸ����ľ���
	BLENDING_TYPE_ROUND_CORNER = 4															//Բ��blending�����ݸ������м�㵽blending·���������ľ���
}BLENDING_TYPE;

//----------------------------------------------------------------------------
//�ٶȣ����ٶȣ����ٶ�б��ʱ��ȿ���ͨ�������໥��ϣ��Զ��仯
//�ٷֱȱ仯����1---100��һ�㲻����100����ȻҲ���Գ�������������������
//��Щ��������Ĭ��ֵ
//ʹ��s�����߿��Լ��ٹ��񣬼����ȶ��ĵ���ʱ�䣬���ǻ������˶���ʱ�䣬��Ϊƽ�����ٶ�û�����δ�
//----------------------------------------------------------------------------
#pragma pack(4)
typedef struct PROFILE_PRM
{
	double vel; 						// vel, 			 % ,����ƽ���ٶȺ���ת�ٶȣ�����vel2��0��ʱ��
	double vel2; 						// vel for rotation, % ,������ת�ٶȣ�����vel2�������ʱ��һ��������һ���ȽϿ����ת���֣����Խ�vel2���õĵ�һЩ
	double acc; 						// acc, 			 %  ���ٶ�
	double accramp; 					// ���ٶ�б��ʱ��		 s  ��Ϊ0�����Σ���Ϊ0��s��
	double dec; 						// dec, 			 %  ���ٶ�
	double decramp; 					// ���ٶ�б��ʱ��       s  ��Ϊ0�����Σ���Ϊ0��s��
	Uint16 straight;					// ֱ�߱�־ 			 no unit�������߿ռ�ֱ�ߣ�����Ϊ1�������߹ؽڵĲ岹������PTP��Ĭ��false
	Uint16 inrange;						// ��λ��λ��������ã�  ������ʾ��ͣ��0 ��ʾָ������0��ʾ�յ�������Ʋ���Ϊ�ǵ�λ�� 100��ʾ�ϸ��������ƣ�С���ֱ�ʾ����ô�ϸ��������ƣ�
										// Ŀǰ�����������ƺ͸���ֵ�Ĺ�ϵ��
}profile_prm;
#pragma pack(0)
//----------------------------------------------------------------------------
//profile��ĳЩֵ������ֵ�����õĹ滮�����Щ����ֵ���бȽϣ����ܳ�����Щ����ֵ��Ĭ����100%
//----------------------------------------------------------------------------
#pragma pack(4)
typedef struct PROFILE_PRM_MAX
{
	double vel_max; 						// vel, 			 % ��������ٶȰٷֱȣ����Գ����ٷֱȣ�����ĳЩ���ص�����£��ǿ������ó���100%��
	double acc_max; 						// acc, 			 % ������Ƽ��ٶȰٷֱȣ�
	double dec_max; 						// dec,              % ������Ƽ��ٶȰٷֱȣ�
}profile_prm_max;
#pragma pack(0)

//----------------------------------------------------------------------------
//profile�Ļ�׼ֵ��������λ��ֵ�������İٷֱ��ǻ�����Щֵ�ģ����ڵѿ�����˵��index=0 ��ʾƽ�ƣ�index=1��ʾ��ת
//----------------------------------------------------------------------------
#pragma pack(4)
typedef struct PROFILE_PRM_BASE
{
	double joint_vel_base[ROBOT_MAX_AXIS]; 					// �ؽڻ�׼�ٶ�, Ҳ����100%��Ӧ���ٶ�	        mm/s or degree/s
	double cart_vel_base[ROBOT_MAX_CART]; 					// �ѿ�����׼�ٶ�, Ҳ����100%��Ӧ���ٶ�		mm/s or degree/s
															// ��һ��������ƽ���˶��ĵѿ����ٶȣ�	�ӵڶ�������ʼ�Ǹ��ݾ�����˶�ѧģ�Ͳ�ͬ����ͬ��һ��ڶ�����������ת���ٶ�
	double joint_acc_base[ROBOT_MAX_AXIS]; 					// �ؽڻ�׼���ٶ�, Ҳ����100%��Ӧ�ļ��ٶ�	    mm/s^2 or degree/s^2
	double joint_dec_base[ROBOT_MAX_AXIS]; 					// �ؽڻ�׼���ٶ�, Ҳ����100%��Ӧ�ļ��ٶ�	    mm/s^2 or degree/s^2
	double cart_acc_base[ROBOT_MAX_CART]; 					// �ѿ�����׼���ٶ�, Ҳ����100%��Ӧ�ļ��ٶ�		mm/s^2 or degree/s^2
															// ��һ��������ƽ���˶��ĵѿ������ٶȣ�	�ӵڶ�������ʼ�Ǹ��ݾ�����˶�ѧģ�Ͳ�ͬ����ͬ��һ��ڶ�����������ת�ļ��ٶ�
	double cart_dec_base[ROBOT_MAX_CART]; 					// �ѿ�����׼���ٶ�, Ҳ����100%��Ӧ�ļ��ٶ�	mm/s^2 or degree/s^2
															// ��һ��������ƽ���˶��ĵѿ������ٶȣ�	�ӵڶ�������ʼ�Ǹ��ݾ�����˶�ѧģ�Ͳ�ͬ����ͬ��һ��ڶ�����������ת�ļ��ٶ�
}profile_prm_base;
#pragma pack(0)

//---------------------------------------------------------------------------
//����blending������������,ʹ�ò�ͬ���͵�ʱ�򣬶�Ӧ����Ĳ�����ͬ���е����Ͳ���Ҫ�������������auto
//---------------------------------------------------------------------------
typedef union
{
	double	 			time_per;							//ʱ��ٷֱ�			%
	double	 			distance;							//����    			mm
	double				corner_distance;					//Բ�Ǿ��� 			mm
}blend_prm_union;
//---------------------------------------------------------------------------
//����blending����
//---------------------------------------------------------------------------
#pragma pack(4)
typedef struct	BLEND_PRM
{
	BLENDING_TYPE 		type;								//����
	blend_prm_union		value;
}blend_prm;
#pragma pack()
//---------------------------------------------------------------------------
#pragma pack(4)
typedef struct PROFILE_BLENDING
{
	//-----------------------------------------------------------------------
	blend_prm			prm;								//blending����
															//-----------------------------------------------------------------------
	Uint16 				needed_flag;						//��Ҫblending��־
	Uint16				ready_flag;							//׼���ñ�־
	Uint16				force_close_flag;					//ĳЩ�������Ҫǿ�ƹر�blending
															//-----------------------------------------------------------------------
	Uint32 				start_t;							//blending��ʼʱ��
	Uint32 				length_t;							//blendingʱ�䳤��
	double 				length_t_inv;						//ʱ�䵹��

}profile_blending;
#pragma pack()
//----------------------------------------------------------------------------
#pragma pack(4)
typedef struct ROBOT_PROFILE
{
	profile_prm_max     max;						//���ٷֱ�
	profile_prm     	def;						//Ĭ�ϰٷֱ�
	profile_prm_base    base;						//��׼ֵ��������
	INRANGE_TYPE 		inrange_type;				//��λ����
	Uint16 				couple_spd_flag;			//�ٶ���ϱ�־
	double				couple_spd_per;				//�ٶ���ϰٷֱ� % ����Ϊ0������ϣ�����Ϊ100%���߸�����Ϊ����ΪС��100%��������⣬�ٶȱ�󣬼��ٶȣ����ٶȣ�б��ʱ�䶼��Ӧ��С��
													//�⿴��������֡�����Ϊ200%���ٶ�����һ����ʱ��������double���ٶȼ�Сһ���ʱ��������Ҳ��Ϊһ��
	double		     	r_spd_percent;				//�������ٶȰٷֱȣ�ϵͳ�ٶȰٷֱȣ��������ٶȰٷֱȣ��˶���ٷֱȣ�
													//-------------------------------------------------------------------------------------------------
													// function pointer define
													//-------------------------------------------------------------------------------------------------
	int16(*pfInitRobotProfile)(struct ROBOT_PROFILE * m_prf, Uint8 id);	// robot profile path initialization
}robot_profile;
#pragma pack(0)


int16 InitRobotProfile(robot_profile* m_prf, Uint8 id);

void calculate_acceleration_from_profile(double t, double jerk, double acc_init, double* acc_t);
void calculate_velocity_from_profile(double t, double jerk, double acc_init, double vel_init, double* vel_t);
void calculate_position_from_profile(double t, double jerk, double acc_init, double vel_init, double pos_init, double* pos_t);

void ProfileCheckLimit(profile_prm_max* max, profile_prm* prf);

//----------------------------------------------------------------------------
#endif /* ROBOT_CONTROL_ROBOT_MODULE_ROBOT_PROFILE_TRAJECTORY_GENERATOR_INCLUDE_ROBOT_PROFILE_H_ */
