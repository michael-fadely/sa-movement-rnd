#pragma once

#include <SADXStructs.h>

#pragma pack(push, 1)

struct charobj2_arraything
{
	float CollisionRadius;
	NJS_VECTOR PositionOffset;
	NJS_VECTOR njs_vector10;
	NJS_VECTOR njs_vector1C;
	int16_t SomeIndex1;
	int16_t SomeIndex2;
	int8_t gap2C[8];
	uint32_t RotationX;
	uint32_t RotationZ;
	NJS_VECTOR njs_vector3C;
	NJS_VECTOR SurfaceNormal;
	NJS_VECTOR njs_vector54;
	NJS_VECTOR njs_vector60;
	NJS_VECTOR njs_vector6C;
};

struct PhysicsData_
{
	int   jump2_timer;    // HangTime -> jump2_timer
	float pos_error;      // FloorGrip -> pos_error
	float lim_h_spd;      // HSpeedCap -> lim_h_spd
	float lim_v_spd;      // VSpeedCap -> lim_v_spd
	float max_x_spd;      // MaxAccel -> max_x_spd
	float max_psh_spd;    // max_psh_spd
	float jmp_y_spd;      // JumpSpeed -> jmp_y_spd
	float nocon_speed;    // SpringControl -> nocon_speed
	float slide_speed;    // slide_speed
	float jog_speed;      // RollCancel -> jog_speed
	float run_speed;      // RollEnd -> run_speed
	float rush_speed;     // Run1 -> rush_speed
	float crash_speed;    // Knockback -> crash_speed
	float dash_speed;     // Run2 -> dash_speed
	float jmp_addit;      // JumpAddSpeed -> jmp_addit
	float run_accel;      // GroundAccel -> run_accel
	float air_accel;      // AirAccel -> air_accel
	float slow_down;      // GroundDecel -> slow_down
	float run_break;      // Brake -> run_break
	float air_break;      // AirBrake -> air_break
	float air_resist_air; // AirDecel -> air_resist_air
	float air_resist;     // RollDecel -> air_resist
	float air_resist_y;   // GravityAdd -> air_resist_y
	float air_resist_z;   // HitSpeed -> air_resist_z
	float grd_frict;      // MinSpeed -> grd_frict
	float grd_frict_z;    // grd_frict_z
	float lim_frict;      // lim_frict
	float rat_bound;      // rat_bound
	float rad;            // RippleSize -> rad
	float height;         // CollisionSize -> height
	float weight;         // Gravity -> weight
	float eyes_height;    // CameraY -> eyes_height
	float center_height;  // YOff -> center_height
};

struct CharObj2_
{
	float SpindashSpeed;
	int16_t Upgrades;
	int16_t Powerups;
	int16_t JumpTime;
	int16_t field_A;
	int16_t UnderwaterTime;
	int16_t IdleTime;
	int16_t StatusBackup;
	int32_t field_12;
	int8_t gap16[2];
	float LoopDist;
	float Up;
	NJS_VECTOR SomeKindOfSpeedOffset;
	NJS_VECTOR AddVelocity;
	NJS_VECTOR Speed;
	NJS_VECTOR field_44;
	NJS_VECTOR SurfaceNormal;
	int32_t SurfaceFlags;
	int32_t SurfaceFlags_Old;
	charobj2_arraything* array_1x132;
	ObjectMaster* ObjectHeld;
	void* field_6C;
	void* SomePointer;
	int32_t field_74;
	void* array_15x32;
	int16_t SonicSpinTimeProbably;
	int16_t SonicSpinTimer;
	int16_t LightdashTime;
	int16_t LightdashTimer;
	int32_t field_84;
	NJS_VECTOR field_88;
	float SomeFrameNumberThing;
	float TailsFlightTime;
	PhysicsData_ PhysicsData;
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
	int32_t field_28;
	int32_t field_2C;
	int32_t field_30;
	float field_34;
	float field_38;
	float AccelerationMultiplier;
};
#pragma pack(pop)
