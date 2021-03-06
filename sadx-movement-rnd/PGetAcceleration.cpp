#include <cmath>
#include <SADXModLoader.h>
#include "PGetAcceleration.h"

// ReSharper disable CppClangTidyCppcoreguidelinesAvoidGoto
// ReSharper disable CppClangTidyHicppAvoidGoto

// Standard functions

FunctionPointer(float, PGetAccelerationAuto, (EntityData1 *arg0, EntityData2_ *arg4, CharObj2_ *a3), 0x00447510);
FunctionPointer(float, PGetAccelerationStair, (EntityData1 *data1, EntityData2_ *data2_pp, CharObj2_ *data2), 0x447010);
FunctionPointer(void, PConvertVector_G2P, (EntityData1 *a1, NJS_VECTOR *vd), 0x43EC00);
FunctionPointer(void, PRotatedByGravity, (EntityData1 *a1, EntityData2_ *a2, CharObj2_ *a3), 0x4491E0);
FastcallFunctionPointer(double, njOuterProduct, (NJS_VECTOR *a1, NJS_VECTOR *a2, NJS_VECTOR *a3), 0x7889F0);
FunctionPointer(int, DiffAngle, (int a1, int a2), 0x004383B0);

// Usercall functions - definitions below PGetAcceleration

void PGetAccelerationTube(EntityData1* a1, CharObj2_* eax0, EntityData2_* arg_0);
void PRotatedByGravityS(EntityData1* a1, EntityData2_* a2, CharObj2_* a3);
void PAdjustAngleYQ(CharObj2_* a1, EntityData1* entity, EntityData2_* a3, int16_t bams);
void PAdjustAngleYS(EntityData1* a1, CharObj2_* a2, EntityData2_* a3, uint16_t a4);
void PAdjustAngleY(CharObj2_* charobj2, EntityData1* data1, EntityData2_* data2, int a4);

// This function is ported from the HexRays decompiler and had to be repaired. It has been cleaned up significantly.
// It is not expected that anyone will understand it. If you would like to try, please be my guest. -SF94
void __cdecl PGetAcceleration(EntityData1* entity, EntityData2_* a2, CharObj2_* charobj)
{
	float add_speed_z; // st7
	float v19; // st7
	float add_speed_x; // st6
	Angle rotation_y; // esi
	float v37; // st7
	float v38; // st7
	float analog_magnitude; // st7
	int angle_delta; // ecx
	float v52; // st7
	float v53; // st7
	float v54; // st7
	float v55; // st7
	float v56; // st7
	Angle analog_angle; // [esp+8h] [ebp-2Ch]
	NJS_VECTOR tnorm_cross_velocity; // [esp+28h] [ebp-Ch]
	float a1a; // [esp+38h] [ebp+4h]
	float a1b; // [esp+38h] [ebp+4h]
	float a1c; // [esp+38h] [ebp+4h]

	if (entity->Status & Status_DisableControl)
	{
		PGetAccelerationAuto(entity, a2, charobj);
		return;
	}

	// these are most definitely COL flags
	const int surface_flags = charobj->SurfaceFlags;

	// TODO: use COL flags enum
	if (surface_flags & 0x20000)
	{
		PGetAccelerationTube(entity, charobj, a2);
		return;
	}

	// TODO: use COL flags enum
	if (surface_flags & 0x4000)
	{
		PGetAccelerationStair(entity, a2, charobj);
		return;
	}

	NJS_VECTOR v64 {}; // [esp+1Ch] [ebp-18h]

	NJS_VECTOR add_speed = {
		(Gravity.x * charobj->PhysicsData.weight) + a2->SomeCollisionVector.x,
		(Gravity.y * charobj->PhysicsData.weight) + a2->SomeCollisionVector.y,
		(Gravity.z * charobj->PhysicsData.weight) + a2->SomeCollisionVector.z
	};

	PConvertVector_G2P(entity, &add_speed);

	// aka PCheckPower
	const bool have_analog = GetAnalog(entity, &analog_angle, &analog_magnitude);

	NJS_VECTOR* v17 = &charobj->array_1x132->njs_vector1C;
	njOuterProduct(v17, &a2->VelocityDirection, &tnorm_cross_velocity);

	// unstick from the ground using the weight as the unsticking force, nullify horizontal speed
	if (charobj->Up < 0.1f && fabs(tnorm_cross_velocity.y) > 0.60000002f && charobj->Speed.x > 1.16f)
	{
		add_speed_z = 0.0f;
		add_speed.x = 0.0f;
		add_speed.y = -charobj->PhysicsData.weight;
		goto LABEL_16;
	}

	// unstick from the ground
	if (charobj->Up < -0.40000001f && charobj->Speed.x > 1.16f)
	{
		v19 = charobj->PhysicsData.weight * 5.0f;

	what:
		add_speed.y = add_speed.y - v19;

	LABEL_15:
		add_speed_z = add_speed.z;
		goto LABEL_16;
	}

	// ditto, different weight multiplier
	if (charobj->Up < -0.30000001f && charobj->Speed.x > 1.16f)
	{
		v19 = charobj->PhysicsData.weight * 0.80000001f;
		goto what;
	}

	// ditto, different weight multiplier
	if (charobj->Up < -0.1f && charobj->Speed.x > 1.16f)
	{
		v19 = charobj->PhysicsData.weight * 0.40000001f;
		goto what;
	}

	if (charobj->Up >= 0.5f || std::abs(charobj->Speed.x) >= charobj->PhysicsData.run_speed)
	{
		if (charobj->Up >= 0.69999999f
		    || std::abs(charobj->Speed.x) >= charobj->PhysicsData.run_speed)
		{
			if (charobj->Up >= 0.87f
			    || std::abs(charobj->Speed.x) >= charobj->PhysicsData.jog_speed)
			{
				goto LABEL_15;
			}

			add_speed_z = add_speed.z * 1.4f;
		}
		else
		{
			add_speed_z = add_speed.z + add_speed.z;
		}
	}
	else
	{
		add_speed.x = add_speed.x * 4.2249999f;
		add_speed_z = add_speed.z * 4.2249999f;
	}

LABEL_16:
	if (have_analog)
	{
		if (charobj->Speed.x > charobj->PhysicsData.max_x_spd && charobj->Up > 0.95999998f)
		{
			add_speed_x = (charobj->Speed.x - charobj->PhysicsData.max_x_spd) * charobj->PhysicsData.air_resist * 1.7f;
			goto LABEL_43;
		}
	}
	else if (charobj->Speed.x > charobj->PhysicsData.run_speed)
	{
	LABEL_42:
		add_speed_x = charobj->PhysicsData.air_resist * charobj->Speed.x;
		goto LABEL_43;
	}

	//v21 = charobj->Speed.x;
	//v23 = charobj->PhysicsData.MaxAccel;

	// if (c0 | c3)
	if (charobj->Speed.x <= charobj->PhysicsData.max_x_spd)
	{
		if (charobj->Speed.x >= 0.0f)
		{
			goto LABEL_44;
		}

		goto LABEL_42;
	}

	add_speed_x = (charobj->Speed.x - charobj->PhysicsData.max_x_spd) * charobj->PhysicsData.air_resist;

LABEL_43:
	add_speed.x = add_speed_x + add_speed.x;

LABEL_44:
	add_speed.y = charobj->PhysicsData.air_resist_y * charobj->Speed.y + add_speed.y;
	add_speed.z = charobj->PhysicsData.air_resist_z * charobj->Speed.z + add_speed_z;

	if (have_analog)
	{
		if (entity->Status & Status_OnPath)
		{
			// aka PGetRotationYAlongThePath
			FollowSpline(reinterpret_cast<CharObj2*>(charobj), reinterpret_cast<EntityData2*>(a2), entity);
			rotation_y = a2->Forward.y;
			v64.y = -0.80000001f;
		}
		else
		{
			if (charobj->Up < 0.94f)
			{
				// TODO: use COL flags enum
				if (charobj->SurfaceFlags & 0x800000)
				{
					PRotatedByGravityS(entity, a2, charobj);
				}
			}

			rotation_y = analog_angle;
		}

		// if (c0 | c2)
		if (charobj->Speed.x < charobj->PhysicsData.max_x_spd)
		{
			if (charobj->Speed.x < charobj->PhysicsData.jog_speed)
			{
				if (analog_magnitude > 0.5f)
				{
				LABEL_67:
					v38 = analog_magnitude * charobj->PhysicsData.run_accel;
					goto SET_ANALOG_MAG_TO_V38;
				}

				v37 = charobj->PhysicsData.jog_speed * 0.40000001f;

			LABEL_66:
				if (v37 <= charobj->Speed.x)
				{
					analog_magnitude = 0.0;

				LABEL_78:
					angle_delta = DiffAngle(entity->Rotation.y, rotation_y);

					// if we're not moving and the delta of the stick angle and entity angle
					// is greater than 22.5 degrees, just rotate, don't move
					if (charobj->Speed.x == 0.0f && angle_delta > 4096) // 22.5 degrees
					{
						a2->Forward.y = rotation_y;
						analog_magnitude = 0.0f;
						PAdjustAngleYQ(charobj, entity, a2, rotation_y);

					SET_V64X_TO_STICK_MAG:
						a2->force = analog_magnitude;
						v64.x = analog_magnitude;
						goto LABEL_97;
					}

					if ((charobj->PhysicsData.run_speed + charobj->PhysicsData.jog_speed) * 0.5f > charobj->Speed.x || angle_delta <= 4096) // 22.5 degrees
					{
						if (charobj->Speed.x >= charobj->PhysicsData.jog_speed && angle_delta < 4096) // 22.5 degrees
						{
							a2->Forward.y = rotation_y;
							PAdjustAngleYS(entity, charobj, a2, rotation_y);
							goto SET_V64X_TO_STICK_MAG;
						}

						// TODO: use COL flags enum
						if (charobj->Speed.x >= charobj->PhysicsData.dash_speed && charobj->SurfaceFlags & 0x800000)
						{
							a2->Forward.y = rotation_y;
							PAdjustAngleYS(entity, charobj, a2, rotation_y);
							goto SET_V64X_TO_STICK_MAG;
						}

						if (charobj->Speed.x >= charobj->PhysicsData.jog_speed
						    && charobj->Speed.x <= charobj->PhysicsData.rush_speed
						    && angle_delta > 8192) // 45 degrees
						{
							analog_magnitude = analog_magnitude * 0.80000001f;
						}

						a2->Forward.y = rotation_y;
					}
					else
					{
						a2->Forward.y = rotation_y;
						analog_magnitude = charobj->PhysicsData.slow_down;
					}

					PAdjustAngleY(charobj, entity, a2, rotation_y);
					goto SET_V64X_TO_STICK_MAG;
				}
				goto LABEL_67;
			}

			if (charobj->Speed.x < charobj->PhysicsData.run_speed)
			{
				if (analog_magnitude > 0.69999999f)
				{
					v38 = analog_magnitude * charobj->PhysicsData.run_accel;

				SET_ANALOG_MAG_TO_V38:
					analog_magnitude = v38;
					goto LABEL_78;
				}

				v37 = (charobj->PhysicsData.run_speed + charobj->PhysicsData.run_speed) * 0.5f;
				goto LABEL_66;
			}

			//v39 = charobj->Speed.x;
			//v41 = charobj->PhysicsData.Run1;
			// if (c0 | c2)
			if (charobj->Speed.x < charobj->PhysicsData.rush_speed)
			{
				v38 = analog_magnitude * charobj->PhysicsData.run_accel;

				// fcomp 0.89999998
				// if (c0 | c3)
				if (analog_magnitude <= 0.89999998f)
				{
					v38 = v38 * 0.30000001f;
				}

				goto SET_ANALOG_MAG_TO_V38;
			}
		}
		else
		{
			if (charobj->Speed.x < charobj->PhysicsData.max_x_spd || charobj->Up >= 0.0f)
			{
				v38 = analog_magnitude * charobj->PhysicsData.run_accel * 0.40000001f;
				goto SET_ANALOG_MAG_TO_V38;
			}
		}

		v38 = analog_magnitude * charobj->PhysicsData.run_accel;
		goto SET_ANALOG_MAG_TO_V38;
	}

	if (charobj->Up >= 0.70999998f)
	{
		if (charobj->Speed.x <= 0.0f)
		{
			if (charobj->Speed.x < 0.0f)
			{
				v64.x = -charobj->PhysicsData.slow_down;
			}

			a2->force = 0.0f;
		}
		else
		{
			v64.x = charobj->PhysicsData.slow_down;
			a2->force = 0.0f;
		}
	}
	else
	{
		PRotatedByGravity(entity, a2, charobj);
		a2->force = 0.0f;
	}

LABEL_97:
	if (charobj->Up < 0.70999998f
	    && std::abs(charobj->Speed.x) < charobj->PhysicsData.jog_speed
	    && !have_analog)
	{
		add_speed.x = add_speed.x * 10.0f;
		add_speed.z = add_speed.z * 10.0f;
		goto LABEL_145;
	}

	if (charobj->Speed.x == 0.0f)
	{
		a1a = charobj->PhysicsData.lim_frict * a2->AccelerationMultiplier * add_speed.y;
		add_speed.x = add_speed.x + v64.x;

		if (!have_analog && (add_speed.x < a1a && -a1a < add_speed.x
		                     || std::abs(add_speed.x) < 0.050999999f))
		{
			add_speed.x = 0.0f;
		}

		goto LABEL_145;
	}

	if (v64.x < 0.0f)
	{
		// TODO: use COL flags enum
		if (!(charobj->SurfaceFlags & 4))
		{
			if (charobj->Speed.x <= 0.0f)
			{
				if (!have_analog
				    && charobj->Speed.x <= charobj->PhysicsData.jog_speed
				    && std::abs(add_speed.x) < 0.050999999f
				    || (v52 = charobj->PhysicsData.lim_frict * a2->AccelerationMultiplier * add_speed.y + v64.x, v52 >= 0.0f))
				{
					v52 = 0.0f;
				}
			}
			else
			{
				v52 = add_speed.x + v64.x;

				if (v64.x * v52 < 0.0f)
				{
					v52 = 0.0f;
				}
			}

			goto LABEL_144;
		}

		if (add_speed.y < 0.0f)
		{
			a1b = charobj->PhysicsData.grd_frict * a2->AccelerationMultiplier * add_speed.y;

			if (a1b > 0.0f && -v64.x > a1b)
			{
				v52 = add_speed.x + v64.x;

				if (v52 < 0.0f)
				{
					if (v52 < -a1b)
					{
						a2->field_38 = v52 - a1b;
						v52 = -a1b;
					LABEL_144:
						add_speed.x = v52;
						goto LABEL_145;
					}
				}

				if (v52 <= 0.0f)
				{
					goto LABEL_144;
				}

			LABEL_136:
				if (v52 > a1b)
				{
					a2->field_38 = v52 - a1b;
					v52 = a1b;
				}

				goto LABEL_144;
			}
		}

		goto LABEL_138;
	}

	a1b = charobj->PhysicsData.lim_frict * a2->AccelerationMultiplier * add_speed.y;

	if (charobj->Speed.x >= 0.0f || add_speed.x >= 0.050999999f || add_speed.x <= -0.050999999f)
	{
		if (a1b > 0.0f && a1b < v64.x)
		{
			v52 = add_speed.x + v64.x;
			goto LABEL_136;
		}

	LABEL_138:
		if (!have_analog
		    && charobj->Speed.x <= charobj->PhysicsData.jog_speed
		    && add_speed.x < 0.050999999f
		    && add_speed.x > -0.050999999f)
		{
			add_speed.x = 0.0f;
			goto LABEL_145;
		}

		v52 = add_speed.x + v64.x;
		goto LABEL_144;
	}

	v53 = add_speed.x + v64.x;
	add_speed.x = v53;

	if (v53 * v64.x < 0.0f)
	{
		add_speed.x = 0.0f;
	}

LABEL_145:
	if (charobj->Speed.z == 0.0f)
	{
		v54 = charobj->PhysicsData.lim_frict * a2->AccelerationMultiplier * add_speed.y;

		if (add_speed.z < v54 && -v54 < add_speed.z)
		{
			add_speed.z = 0.0f;
		}

		goto LABEL_169;
	}

	if (add_speed.y >= 0.0f)
	{
		a1c = 0.0f;
	}
	else
	{
		a1c = charobj->PhysicsData.grd_frict_z * a2->AccelerationMultiplier * add_speed.y;
	}

	v55 = add_speed.z;

	// TODO: use COL flags enum
	if (!(charobj->SurfaceFlags & 4))
	{
		if (v55 <= 0.0f)
		{
			if (add_speed.z < 0.0f)
			{
				v64.z = a1c;
			}
		}
		else
		{
			v64.z = -a1c;
		}

		v56 = add_speed.z + v64.z;

		if (add_speed.z != 0.0f && v64.z != 0.0f && add_speed.z * v56 < 0.0f)
		{
			v56 = 0.0f;
		}

		add_speed.z = v56;
		goto LABEL_169;
	}

	if (v55 <= 0.0f)
	{
		if (v55 < 0.0f)
		{
			v55 = v55 + a1c;

			if (v55 > 0.0f)
			{
				v55 = 0.0f;
			}
		}

		goto LABEL_159;
	}

	v55 = v55 - a1c;

	if (v55 >= 0.0f)
	{
	LABEL_159:
		add_speed.z = v55;
		goto LABEL_169;
	}

	add_speed.z = 0.0f;

LABEL_169:
	add_speed.y = add_speed.y + v64.y;

	NJS_POINT3* add_velocity = &charobj->AddVelocity;

	add_velocity->x = add_speed.x;
	add_velocity->y = add_speed.y;
	add_velocity->z = add_speed.z;
}

// usercall declaration:
// void __usercall sub_44B0E0(EntityData1 *a1@<ecx>, CharObj2 *eax0@<eax>, EntityData2 *arg_0)
void PGetAccelerationTube(EntityData1* a1, CharObj2_* eax0, EntityData2_* arg_0)
{
	// ReSharper disable once CppDeclaratorNeverUsed
	auto func = reinterpret_cast<void*>(0x44B0E0);

	__asm
	{
		push arg_0
		mov eax, eax0
		mov ecx, a1

		call func

		add esp, 4
	}
}

// usercall declaration:
// void __usercall sub_449380(EntityData1 *a1@<eax>, EntityData2 *a2@<esi>, CharObj2 *a3)
void PRotatedByGravityS(EntityData1* a1, EntityData2_* a2, CharObj2_* a3)
{
	// ReSharper disable once CppDeclaratorNeverUsed
	auto func = reinterpret_cast<void*>(0x449380);

	__asm
	{
		mov eax, a1
		mov esi, a2
		push a3

		call func
		add esp, 4
	}
}

// usercall declaration:
// void __usercall sub_443DF0(CharObj2 *a1@<eax>, EntityData1 *entity@<edi>, EntityData2 *a3, __int16 bams)
void PAdjustAngleYQ(CharObj2_* a1, EntityData1* entity, EntityData2_* a3, __int16 bams)
{
	// ReSharper disable once CppDeclaratorNeverUsed
	auto func = reinterpret_cast<void*>(0x443DF0);

	__asm
	{
		mov eax, a1
		mov edi, entity
		push dword ptr [bams]
		push a3

		call func
		add esp, 8
	}
}

// usercall declaration:
// void __usercall sub_443E60(EntityData1 *a1@<ebx>, CharObj2 *a2@<esi>, EntityData2 *a3, unsigned __int16 a4)
void PAdjustAngleYS(EntityData1* a1, CharObj2_* a2, EntityData2_* a3, unsigned __int16 a4)
{
	// ReSharper disable once CppDeclaratorNeverUsed
	auto func = reinterpret_cast<void*>(0x443E60);

	__asm
	{
		mov ebx, a1
		mov esi, a2
		push dword ptr [a4]
		push a3

		call func
		add esp, 8
	}
}

// usercall declaration:
// void __usercall RotateTowards(CharObj2 *charobj2@<edi>, EntityData1 *data1@<esi>, EntityData2 *data2, int target_angle)
void PAdjustAngleY(CharObj2_* charobj2, EntityData1* data1, EntityData2_* data2, int a4)
{
	// ReSharper disable once CppDeclaratorNeverUsed
	auto func = reinterpret_cast<void*>(0x443C50);

	__asm
	{
		mov edi, charobj2
		mov esi, data1
		push a4
		push data2

		call func
		add esp, 8
	}
}
