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

// Usercall functions - definitions below PGetAcceleration

void PGetAccelerationTube(EntityData1* a1, CharObj2_* eax0, EntityData2_* arg_0);
void PRotatedByGravityS(EntityData1* a1, EntityData2_* a2, CharObj2_* a3);
void PAdjustAngleYQ(CharObj2_* a1, EntityData1* entity, EntityData2_* a3, __int16 bams);
void PAdjustAngleYS(EntityData1* a1, CharObj2_* a2, EntityData2_* a3, unsigned __int16 a4);
void PAdjustAngleY(CharObj2_* charobj2, EntityData1* data1, EntityData2_* data2, int a4);

// This function is ported from the HexRays decompiler and had to be repaired. It has been cleaned up significantly.
// It is not expected that anyone will understand it. If you would like to try, please be my guest. -SF94
void __cdecl PGetAcceleration(EntityData1* entity, EntityData2_* a2, CharObj2_* charobj)
{
	float new_speed_z; // st7
	float v19; // st7
	float new_speed_x; // st6
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
	Angle angle; // [esp+8h] [ebp-2Ch]
	NJS_VECTOR v67; // [esp+28h] [ebp-Ch]
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

	NJS_VECTOR new_speed = {
		(Gravity.x * charobj->PhysicsData.weight) + a2->SomeCollisionVector.x,
		(Gravity.y * charobj->PhysicsData.weight) + a2->SomeCollisionVector.y,
		(Gravity.z * charobj->PhysicsData.weight) + a2->SomeCollisionVector.z
	};

	PConvertVector_G2P(entity, &new_speed);

	// aka PCheckPower
	const bool have_analog = GetAnalog(entity, &angle, &analog_magnitude);

	NJS_VECTOR* v17 = &charobj->array_1x132->njs_vector1C;
	njOuterProduct(v17, &a2->VelocityDirection, &v67);

	// unstick from the ground using the weight as the unsticking force, nullify horizontal speed
	if (charobj->Up < 0.1f && fabs(v67.y) > 0.60000002f && charobj->Speed.x > 1.16f)
	{
		new_speed_z = 0.0f;
		new_speed.x = 0.0f;
		new_speed.y = -charobj->PhysicsData.weight;
		goto LABEL_16;
	}

	// unstick from the ground
	if (charobj->Up < -0.40000001f && charobj->Speed.x > 1.16f)
	{
		v19 = charobj->PhysicsData.weight * 5.0f;

	what:
		new_speed.y = new_speed.y - v19;

	LABEL_15:
		new_speed_z = new_speed.z;
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

	if (charobj->Up >= 0.5f || charobj->Speed.x >= (float)charobj->PhysicsData.run_speed || -charobj->PhysicsData.run_speed >= charobj->Speed.x)
	{
		if (charobj->Up >= 0.69999999f
		    || charobj->Speed.x >= (float)charobj->PhysicsData.run_speed
		    || -charobj->PhysicsData.run_speed >= charobj->Speed.x)
		{
			if (charobj->Up >= 0.87f
			    || charobj->Speed.x >= (float)charobj->PhysicsData.jog_speed
			    || -charobj->PhysicsData.run_speed >= charobj->Speed.x)
			{
				goto LABEL_15;
			}

			new_speed_z = new_speed.z * 1.4f;
		}
		else
		{
			new_speed_z = new_speed.z + new_speed.z;
		}
	}
	else
	{
		new_speed.x = new_speed.x * 4.2249999f;
		new_speed_z = new_speed.z * 4.2249999f;
	}

LABEL_16:
	if (have_analog)
	{
		if (charobj->Speed.x > charobj->PhysicsData.max_x_spd && charobj->Up > 0.95999998f)
		{
			new_speed_x = (charobj->Speed.x - charobj->PhysicsData.max_x_spd) * charobj->PhysicsData.air_resist * 1.7f;
			goto LABEL_43;
		}
	}
	else if (charobj->Speed.x > charobj->PhysicsData.run_speed)
	{
	LABEL_42:
		new_speed_x = charobj->PhysicsData.air_resist * charobj->Speed.x;
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

	new_speed_x = (charobj->Speed.x - charobj->PhysicsData.max_x_spd) * charobj->PhysicsData.air_resist;

LABEL_43:
	new_speed.x = new_speed_x + new_speed.x;

LABEL_44:
	new_speed.y = charobj->PhysicsData.air_resist_y * charobj->Speed.y + new_speed.y;
	new_speed.z = charobj->PhysicsData.air_resist_z * charobj->Speed.z + new_speed_z;

	if (have_analog)
	{
		if (entity->Status & Status_OnPath)
		{
			// aka PGetRotationYAlongThePath
			FollowSpline((CharObj2*)charobj, (EntityData2*)a2, entity);
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

			rotation_y = angle;
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
					angle_delta = BAMS_Subtract(entity->Rotation.y, rotation_y);

					// if we're not moving and the delta of the stick angle and entity angle
					// is greater than 22.5 degrees, just rotate, don't move
					if (charobj->Speed.x == 0.0f && angle_delta > 4096) // 22.5 degrees
					{
						a2->Forward.y = rotation_y;
						analog_magnitude = 0.0f;
						PAdjustAngleYQ(charobj, entity, a2, rotation_y);

					SET_V64X_TO_STICK_MAG:
						a2->field_34 = analog_magnitude;
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

			a2->field_34 = 0.0f;
		}
		else
		{
			v64.x = charobj->PhysicsData.slow_down;
			a2->field_34 = 0.0f;
		}
	}
	else
	{
		PRotatedByGravity(entity, a2, charobj);
		a2->field_34 = 0.0f;
	}

LABEL_97:
	if (charobj->Up < 0.70999998f
	    && charobj->Speed.x < (float)charobj->PhysicsData.jog_speed
	    && -charobj->PhysicsData.jog_speed < charobj->Speed.x
	    && !have_analog)
	{
		new_speed.x = new_speed.x * 10.0f;
		new_speed.z = new_speed.z * 10.0f;
		goto LABEL_145;
	}

	if (charobj->Speed.x == 0.0f)
	{
		a1a = charobj->PhysicsData.lim_frict * a2->AccelerationMultiplier * new_speed.y;
		new_speed.x = new_speed.x + v64.x;

		if (!have_analog && (new_speed.x < (float)a1a && -a1a < new_speed.x
		                     || new_speed.x < 0.050999999f && new_speed.x > -0.050999999f))
		{
			new_speed.x = 0.0f;
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
				    && charobj->Speed.x <= (float)charobj->PhysicsData.jog_speed
				    && new_speed.x < 0.050999999f
				    && new_speed.x > -0.050999999f
				    || (v52 = charobj->PhysicsData.lim_frict * a2->AccelerationMultiplier * new_speed.y + v64.x, v52 >= 0.0f))
				{
					v52 = 0.0f;
				}
			}
			else
			{
				v52 = new_speed.x + v64.x;

				if (v64.x * v52 < 0.0f)
				{
					v52 = 0.0f;
				}
			}

			goto LABEL_144;
		}

		if (new_speed.y < 0.0f)
		{
			a1b = charobj->PhysicsData.grd_frict * a2->AccelerationMultiplier * new_speed.y;

			if (a1b > 0.0f && -v64.x > a1b)
			{
				v52 = new_speed.x + v64.x;

				if (v52 < 0.0f)
				{
					if (v52 < -a1b)
					{
						a2->field_38 = v52 - a1b;
						v52 = -a1b;
					LABEL_144:
						new_speed.x = v52;
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

	a1b = charobj->PhysicsData.lim_frict * a2->AccelerationMultiplier * new_speed.y;

	if (charobj->Speed.x >= 0.0f || new_speed.x >= 0.050999999f || new_speed.x <= -0.050999999f)
	{
		if (a1b > 0.0f && a1b < v64.x)
		{
			v52 = new_speed.x + v64.x;
			goto LABEL_136;
		}

	LABEL_138:
		if (!have_analog
		    && charobj->Speed.x <= charobj->PhysicsData.jog_speed
		    && new_speed.x < 0.050999999f
		    && new_speed.x > -0.050999999f)
		{
			new_speed.x = 0.0f;
			goto LABEL_145;
		}

		v52 = new_speed.x + v64.x;
		goto LABEL_144;
	}

	v53 = new_speed.x + v64.x;
	new_speed.x = v53;

	if (v53 * v64.x < 0.0f)
	{
		new_speed.x = 0.0f;
	}

LABEL_145:
	if (charobj->Speed.z == 0.0f)
	{
		v54 = charobj->PhysicsData.lim_frict * a2->AccelerationMultiplier * new_speed.y;

		if (new_speed.z < v54 && -v54 < new_speed.z)
		{
			new_speed.z = 0.0f;
		}

		goto LABEL_169;
	}

	if (new_speed.y >= 0.0f)
	{
		a1c = 0.0f;
	}
	else
	{
		a1c = charobj->PhysicsData.grd_frict_z * a2->AccelerationMultiplier * new_speed.y;
	}

	v55 = new_speed.z;

	// TODO: use COL flags enum
	if (!(charobj->SurfaceFlags & 4))
	{
		if (v55 <= 0.0f)
		{
			if (new_speed.z < 0.0f)
			{
				v64.z = a1c;
			}
		}
		else
		{
			v64.z = -a1c;
		}

		v56 = new_speed.z + v64.z;

		if (new_speed.z != 0.0f && v64.z != 0.0f && new_speed.z * v56 < 0.0f)
		{
			v56 = 0.0f;
		}

		new_speed.z = v56;
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
		new_speed.z = v55;
		goto LABEL_169;
	}

	new_speed.z = 0.0f;

LABEL_169:
	new_speed.y = new_speed.y + v64.y;

	auto add_velocity = &charobj->AddVelocity;

	add_velocity->x = new_speed.x;
	add_velocity->y = new_speed.y;
	add_velocity->z = new_speed.z;
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
