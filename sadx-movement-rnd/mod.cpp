// ReSharper disable CppClangTidyCppcoreguidelinesAvoidGoto
// ReSharper disable CppClangTidyHicppAvoidGoto
// 
#include <SADXModLoader.h>
#include <cmath>

#pragma pack(push, 1)
struct charobj2_arraything
{
	float CollisionRadius;
	NJS_VECTOR PositionOffset;
	NJS_VECTOR njs_vector10;
	NJS_VECTOR njs_vector1C;
	__int16 SomeIndex1;
	short SomeIndex2;
	char gap2C[8];
	_DWORD RotationX;
	_DWORD RotationZ;
	NJS_VECTOR njs_vector3C;
	NJS_VECTOR SurfaceNormal;
	NJS_VECTOR njs_vector54;
	NJS_VECTOR njs_vector60;
	NJS_VECTOR njs_vector6C;
};

struct CharObj2_
{
	float SpindashSpeed;
	__int16 Upgrades;
	__int16 Powerups;
	__int16 JumpTime;
	__int16 field_A;
	__int16 UnderwaterTime;
	__int16 IdleTime;
	__int16 StatusBackup;
	int field_12;
	char gap16[2];
	float LoopDist;
	float Up;
	NJS_VECTOR SomeKindOfSpeedOffset;
	NJS_VECTOR AddVelocity;
	NJS_VECTOR Speed;
	NJS_VECTOR field_44;
	NJS_VECTOR SurfaceNormal;
	int SurfaceFlags;
	int SurfaceFlags_Old;
	charobj2_arraything* array_1x132;
	ObjectMaster* ObjectHeld;
	void* field_6C;
	void* SomePointer;
	int field_74;
	void* array_15x32;
	__int16 SonicSpinTimeProbably;
	__int16 SonicSpinTimer;
	__int16 LightdashTime;
	__int16 LightdashTimer;
	int field_84;
	NJS_VECTOR field_88;
	float SomeFrameNumberThing;
	float TailsFlightTime;
	PhysicsData PhysicsData;
	AnimThing AnimationThing;
	NJS_VECTOR SoManyVectors[12];
	struct_a3 _struct_a3;
};

struct __declspec(align(4)) EntityData2_
{
	CharObj2* CharacterData;
	NJS_VECTOR VelocityDirection;
	NJS_VECTOR SomeCollisionVector;
	Rotation3 Forward;
	int field_28;
	int field_2C;
	int field_30;
	float field_34;
	float field_38;
	float AccelerationMultiplier;
};
#pragma pack(pop)

FunctionPointer(float, sub_447510, (EntityData1 *arg0, EntityData2_ *arg4, CharObj2_ *a3), 0x00447510);
FunctionPointer(float, sub_447010, (EntityData1 *data1, EntityData2_ *data2_pp, CharObj2_ *data2), 0x447010);
FunctionPointer(void, sub_43EC00, (EntityData1 *a1, NJS_VECTOR *vd), 0x43EC00);
FunctionPointer(void, sub_4491E0, (EntityData1 *a1, EntityData2_ *a2, CharObj2_ *a3), 0x4491E0);
FastcallFunctionPointer(double, sub_7889F0, (NJS_VECTOR *a1, NJS_VECTOR *a2, NJS_VECTOR *a3), 0x7889F0);

void sub_44B0E0(EntityData1* a1, CharObj2_* eax0, EntityData2_* arg_0)
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

void sub_449380(EntityData1* a1, EntityData2_* a2, CharObj2_* a3)
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

void sub_443DF0(CharObj2_* a1, EntityData1* entity, EntityData2_* a3, __int16 bams)
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

void sub_443E60(EntityData1 *a1, CharObj2_ *a2, EntityData2_ *a3, unsigned __int16 a4)
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

void sub_443C50(CharObj2_ *charobj2, EntityData1 *data1, EntityData2_ *data2, int a4)
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


void __cdecl HandleFloorVelocity(EntityData1* entity, EntityData2_* a2, CharObj2_* charobj)
{
	float new_speed_z; // st7
	float v19; // st7
	float new_speed_x; // st6
	Angle rotation_y; // esi
	float v37; // st7
	float v38; // st7
	float analog_magnitude; // st7
	int v48; // ecx
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
		sub_447510(entity, a2, charobj);
		return;
	}

	int surface_flags = charobj->SurfaceFlags;

	if (surface_flags & 0x20000)
	{
		sub_44B0E0(entity, charobj, a2);
		return;
	}

	if (surface_flags & 0x4000)
	{
		sub_447010(entity, a2, charobj);
		return;
	}

	NJS_VECTOR v64 {}; // [esp+1Ch] [ebp-18h]

	NJS_VECTOR new_speed = {
		(Gravity.x * charobj->PhysicsData.Gravity) + a2->SomeCollisionVector.x,
		(Gravity.y * charobj->PhysicsData.Gravity) + a2->SomeCollisionVector.y,
		(Gravity.z * charobj->PhysicsData.Gravity) + a2->SomeCollisionVector.z
	};

	sub_43EC00(entity, &new_speed);

	const bool have_analog = GetAnalog(entity, &angle, &analog_magnitude);

	NJS_VECTOR* v17 = &charobj->array_1x132->njs_vector1C;
	sub_7889F0(v17, &a2->VelocityDirection, &v67);

	if (charobj->Up < 0.1f && fabs(v67.y) > 0.60000002f && charobj->Speed.x > 1.16f)
	{
		new_speed_z = 0.0f;
		new_speed.x = 0.0f;
		new_speed.y = -charobj->PhysicsData.Gravity;
		goto LABEL_16;
	}

	if (charobj->Up < -0.40000001f && charobj->Speed.x > 1.16f)
	{
		v19 = charobj->PhysicsData.Gravity * 5.0f;

	what:
		new_speed.y = new_speed.y - v19;

	LABEL_15:
		new_speed_z = new_speed.z;
		goto LABEL_16;
	}

	if (charobj->Up < -0.30000001f && charobj->Speed.x > 1.16f)
	{
		v19 = charobj->PhysicsData.Gravity * 0.80000001f;
		goto what;
	}

	if (charobj->Up < -0.1f && charobj->Speed.x > 1.16f)
	{
		v19 = charobj->PhysicsData.Gravity * 0.40000001f;
		goto what;
	}

	if (charobj->Up >= 0.5f || charobj->Speed.x >= (float)charobj->PhysicsData.RollEnd || -charobj->PhysicsData.RollEnd >= charobj->Speed.x)
	{
		if (charobj->Up >= 0.69999999f
		    || charobj->Speed.x >= (float)charobj->PhysicsData.RollEnd
		    || -charobj->PhysicsData.RollEnd >= charobj->Speed.x)
		{
			if (charobj->Up >= 0.87f
			    || charobj->Speed.x >= (float)charobj->PhysicsData.RollCancel
			    || -charobj->PhysicsData.RollEnd >= charobj->Speed.x)
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
		if (charobj->Speed.x > charobj->PhysicsData.MaxAccel && charobj->Up > 0.95999998f)
		{
			new_speed_x = (charobj->Speed.x - charobj->PhysicsData.MaxAccel) * charobj->PhysicsData.RollDecel * 1.7f;
			goto LABEL_43;
		}
	}
	else if (charobj->Speed.x > charobj->PhysicsData.RollEnd)
	{
	LABEL_42:
		new_speed_x = charobj->PhysicsData.RollDecel * charobj->Speed.x;
		goto LABEL_43;
	}

	//v21 = charobj->Speed.x;
	//v23 = charobj->PhysicsData.MaxAccel;

	// if (c0 | c3)
	if (charobj->Speed.x <= charobj->PhysicsData.MaxAccel)
	{
		if (charobj->Speed.x >= 0.0f)
		{
			goto LABEL_44;
		}

		goto LABEL_42;
	}

	new_speed_x = (charobj->Speed.x - charobj->PhysicsData.MaxAccel) * charobj->PhysicsData.RollDecel;

LABEL_43:
	new_speed.x = new_speed_x + new_speed.x;

LABEL_44:
	new_speed.y = charobj->PhysicsData.GravityAdd * charobj->Speed.y + new_speed.y;
	new_speed.z = charobj->PhysicsData.HitSpeed * charobj->Speed.z + new_speed_z;

	if (have_analog)
	{
		if (entity->Status & Status_OnPath)
		{
			FollowSpline((CharObj2*)charobj, (EntityData2*)a2, entity);
			rotation_y = a2->Forward.y;
			v64.y = -0.80000001f;
		}
		else
		{
			if (charobj->Up < 0.94f)
			{
				if (charobj->SurfaceFlags & 0x800000)
				{
					sub_449380(entity, a2, charobj);
				}
			}

			rotation_y = angle;
		}

		// if (c0 | c2)
		if (charobj->Speed.x < charobj->PhysicsData.MaxAccel)
		{
			if (charobj->Speed.x < charobj->PhysicsData.RollCancel)
			{
				if (analog_magnitude > 0.5f)
				{
				LABEL_67:
					v38 = analog_magnitude * charobj->PhysicsData.GroundAccel;
					goto LABEL_77;
				}

				v37 = charobj->PhysicsData.RollCancel * 0.40000001f;

			LABEL_66:
				if (v37 <= charobj->Speed.x)
				{
					analog_magnitude = 0.0;

				LABEL_78:
					v48 = BAMS_Subtract(entity->Rotation.y, rotation_y);

					if (charobj->Speed.x == 0.0f && v48 > 4096)
					{
						a2->Forward.y = rotation_y;
						analog_magnitude = 0.0f;
						sub_443DF0(charobj, entity, a2, rotation_y);

					LABEL_96:
						a2->field_34 = analog_magnitude;
						v64.x = analog_magnitude;
						goto LABEL_97;
					}

					if ((charobj->PhysicsData.RollEnd + charobj->PhysicsData.RollCancel) * 0.5f > charobj->Speed.x || v48 <= 4096)
					{
						if (charobj->Speed.x >= charobj->PhysicsData.RollCancel && v48 < 4096)
						{
							a2->Forward.y = rotation_y;
							sub_443E60(entity, charobj, a2, rotation_y);
							goto LABEL_96;
						}

						if (charobj->Speed.x >= charobj->PhysicsData.Run2 && charobj->SurfaceFlags & 0x800000)
						{
							a2->Forward.y = rotation_y;
							sub_443E60(entity, charobj, a2, rotation_y);
							goto LABEL_96;
						}

						if (charobj->Speed.x >= charobj->PhysicsData.RollCancel
							&& charobj->Speed.x <= charobj->PhysicsData.Run1
							&& v48 > 0x2000)
						{
							analog_magnitude = analog_magnitude * 0.80000001f;
						}

						a2->Forward.y = rotation_y;
					}
					else
					{
						a2->Forward.y = rotation_y;
						analog_magnitude = charobj->PhysicsData.GroundDecel;
					}

					sub_443C50(charobj, entity, a2, rotation_y);
					goto LABEL_96;
				}
				goto LABEL_67;
			}

			if (charobj->Speed.x < charobj->PhysicsData.RollEnd)
			{
				if (analog_magnitude > 0.69999999f)
				{
					v38 = analog_magnitude * charobj->PhysicsData.GroundAccel;

				LABEL_77:
					analog_magnitude = v38;
					goto LABEL_78;
				}

				v37 = (charobj->PhysicsData.RollEnd + charobj->PhysicsData.RollEnd) * 0.5f;
				goto LABEL_66;
			}

			//v39 = charobj->Speed.x;
			//v41 = charobj->PhysicsData.Run1;
			// if (c0 | c2)
			if (charobj->Speed.x < charobj->PhysicsData.Run1)
			{
				v38 = analog_magnitude * charobj->PhysicsData.GroundAccel;

				// fcomp 0.89999998
				// if (c0 | c3)
				if (analog_magnitude <= 0.89999998f)
				{
					v38 = v38 * 0.30000001f;
				}

				goto LABEL_77;
			}
		}
		else
		{
			if (charobj->Speed.x < charobj->PhysicsData.MaxAccel || charobj->Up >= 0.0f)
			{
				v38 = analog_magnitude * charobj->PhysicsData.GroundAccel * 0.40000001f;
				goto LABEL_77;
			}
		}

		v38 = analog_magnitude * charobj->PhysicsData.GroundAccel;
		goto LABEL_77;
	}

	if (charobj->Up >= 0.70999998f)
	{
		if (charobj->Speed.x <= 0.0f)
		{
			if (charobj->Speed.x < 0.0f)
			{
				v64.x = -charobj->PhysicsData.GroundDecel;
			}

			a2->field_34 = 0.0f;
		}
		else
		{
			v64.x = charobj->PhysicsData.GroundDecel;
			a2->field_34 = 0.0f;
		}
	}
	else
	{
		sub_4491E0(entity, a2, charobj);
		a2->field_34 = 0.0f;
	}

LABEL_97:
	if (charobj->Up < 0.70999998f
	    && charobj->Speed.x < (float)charobj->PhysicsData.RollCancel
	    && -charobj->PhysicsData.RollCancel < charobj->Speed.x
	    && !have_analog)
	{
		new_speed.x = new_speed.x * 10.0f;
		new_speed.z = new_speed.z * 10.0f;
		goto LABEL_145;
	}

	if (charobj->Speed.x == 0.0f)
	{
		a1a = charobj->PhysicsData.field_68 * a2->AccelerationMultiplier * new_speed.y;
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
		if (!(charobj->SurfaceFlags & 4))
		{
			if (charobj->Speed.x <= 0.0f)
			{
				if (!have_analog
				    && charobj->Speed.x <= (float)charobj->PhysicsData.RollCancel
				    && new_speed.x < 0.050999999f
				    && new_speed.x > -0.050999999f
				    || (v52 = charobj->PhysicsData.field_68 * a2->AccelerationMultiplier * new_speed.y + v64.x, v52 >= 0.0f))
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
			a1b = charobj->PhysicsData.MinSpeed * a2->AccelerationMultiplier * new_speed.y;

			if (a1b > 0.0f && -v64.x > a1b)
			{
				v52 = new_speed.x + v64.x;

				if (v52 < 0.0f)
				{
					*(float*)&angle = -a1b;

					if (v52 < *(float*)&angle)
					{
						a2->field_38 = v52 - a1b;
						v52 = *(float*)&angle;
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

	a1b = charobj->PhysicsData.field_68 * a2->AccelerationMultiplier * new_speed.y;

	if (charobj->Speed.x >= 0.0f || new_speed.x >= 0.050999999f || new_speed.x <= -0.050999999f)
	{
		if (a1b > 0.0f && a1b < v64.x)
		{
			v52 = new_speed.x + v64.x;
			goto LABEL_136;
		}

	LABEL_138:
		if (!have_analog
		    && charobj->Speed.x <= charobj->PhysicsData.RollCancel
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
		v54 = charobj->PhysicsData.field_68 * a2->AccelerationMultiplier * new_speed.y;

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
		a1c = charobj->PhysicsData.field_64 * a2->AccelerationMultiplier * new_speed.y;
	}

	v55 = new_speed.z;

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

extern "C"
{
	__declspec(dllexport) ModInfo SADXModInfo = { ModLoaderVer, nullptr, nullptr, 0, nullptr, 0, nullptr, 0, nullptr, 0 };
	__declspec(dllexport) void __cdecl Init(const char* /*path*/, const HelperFunctions& /*helperFunctions*/)
	{
		WriteJump(reinterpret_cast<void*>(0x0044C270), HandleFloorVelocity);
	}
}
