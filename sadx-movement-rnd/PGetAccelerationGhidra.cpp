// ReSharper disable CommentTypo
// ReSharper disable CppClangTidyClangDiagnosticDollarInIdentifierExtension
// ReSharper disable CppClangTidyClangDiagnosticOldStyleCast
// ReSharper disable CppCStyleCast
// ReSharper disable CppClangTidyHicppAvoidGoto
// ReSharper disable CppClangTidyCppcoreguidelinesAvoidGoto
// ReSharper disable CppInconsistentNaming
// ReSharper disable CppClangTidyClangDiagnosticFloatEqual
// ReSharper disable CppClangTidyClangDiagnosticComma
// ReSharper disable IdentifierTypo
#include <cstdint>
#include <algorithm>

union NJS_COLOR;
struct NJS_MESHSET;
struct NJS_MATERIAL;
struct NJS_MODEL;
struct obj;
struct NJS_MOTION;
struct NJS_TEXNAME;
struct NJS_TEXLIST;
struct CCL_INFO;
struct task;
struct _OBJ_EDITENTRY;
struct _OBJ_SLEEPCON;
struct OBJ_CONDITION;
struct motionwk;
struct forcewk;
struct anywk;
struct colliwk;
struct EVENT_ACTION_LIST;
struct epathtbl;
struct EPATHTAG;
struct EVENT_PATH_LIST;
struct FACETBL;
struct eventwk;
struct PL_JOIN_VERTEX;
struct PL_ACTION;
struct PL_FACE;
struct PL_LANDPOSI;
struct csts;

/* 10603 */
union $4A79D92F31C24460F2689F28FD93027A
{
	char b[4];
	uint16_t w[2];
	unsigned int l;
	float f;
	void* ptr;
};

/* 10604 */
union $20A60C9037C3BEBF64D11B94833DF168
{
	char b[4];
	int16_t w[2];
	int l;
	float f;
	void* ptr;
};

/* 10605 */
struct Angle3
{
	int x;
	int y;
	int z;
};

/* 10478 */
struct NJS_POINT3
{
	float x;
	float y;
	float z;
};

/* 10607 */
struct taskwk
{
	char mode;
	char smode;
	char id;
	char btimer;
	int16_t flag;
	uint16_t wtimer;
	$4A79D92F31C24460F2689F28FD93027A counter;
	$20A60C9037C3BEBF64D11B94833DF168 timer;
	$20A60C9037C3BEBF64D11B94833DF168 value;
	Angle3 ang;
	NJS_POINT3 pos;
	NJS_POINT3 scl;
	colliwk* cwp;
	eventwk* ewp;
};

/* 10608 */
struct c_colli_hit_info
{
	char my_num;
	char hit_num;
	uint16_t flag;
	taskwk* hit_twp;
};

/* 10618 */
struct colliwk
{
	uint16_t id;
	int16_t nbHit;
	uint16_t flag;
	uint16_t nbInfo;
	float colli_range;
	CCL_INFO* info;
	c_colli_hit_info hit_info[16];
	NJS_POINT3 normal;
	task* mytask;
	int16_t my_num;
	int16_t hit_num;
	colliwk* hit_cwp;
};

/* 10619 */
struct $643A7C20D12739A43D9729E2E0FDD90D
{
	char mode;
	Angle3 ang;
	NJS_POINT3 pos;
	task* obj;
};

/* 10620 */
union $FBDCA854D7056C2482A98052A9E67B21
{
	NJS_POINT3 pos;
	NJS_POINT3 spd;
	NJS_POINT3 acc;
	Angle3 ang;
};

/* 10621 */
struct $FDEA35F9183C3745A70BF5C7F19A2ACF
{
	char mode;
	$FBDCA854D7056C2482A98052A9E67B21 param;
	float run_speed;
	float run_accel;
};

/* 10623 */
struct $A8E0DE194AE0B03676C0E4AC0E67EDDE
{
	float timer;
	EVENT_ACTION_LIST* list;
	EVENT_ACTION_LIST* old;
};

/* 10628 */
struct $5D0BECAD10ABAF0BCD2EFFB8D6908267
{
	float timer;
	EVENT_PATH_LIST* list;
	NJS_POINT3 pos;
};

/* 10630 */
struct facewk
{
	char old;
	char __new;
	int16_t nbFrame;
	int16_t frame;
	char* dataPtr;
	FACETBL* tablePtr;
};

/* 10631 */
struct eventwk
{
	char mode;
	char command;
	$643A7C20D12739A43D9729E2E0FDD90D look;
	$FDEA35F9183C3745A70BF5C7F19A2ACF move;
	$A8E0DE194AE0B03676C0E4AC0E67EDDE action;
	$5D0BECAD10ABAF0BCD2EFFB8D6908267 path;
	facewk face;
	NJS_POINT3 posofs;
	float shadowSize;
};

/* 10606 */
struct CCL_INFO
{
	char kind;
	char form;
	char push;
	char damage;
	unsigned int attr;
	NJS_POINT3 center;
	float a;
	float b;
	float c;
	float d;
	int angx;
	int angy;
	int angz;
};

/* 10609 */
struct task
{
	task* next;
	task* last;
	task* ptp;
	task* ctp;
	void (__cdecl* exec)(task*);
	void (__cdecl* disp)(task*);
	void (__cdecl* dest)(task*);
	OBJ_CONDITION* ocp;
	taskwk* twp;
	motionwk* mwp;
	forcewk* fwp;
	anywk* awp;
	void* thp;
};

/* 10490 */
struct NJS_ACTION
{
	obj* object;
	NJS_MOTION* motion;
};

/* 10622 */
struct EVENT_ACTION_LIST
{
	char mode;
	char linkframe;
	NJS_ACTION action;
	NJS_TEXLIST* texlist;
	EVENT_ACTION_LIST* next;
	float speed;
};

/* 10627 */
struct EVENT_PATH_LIST
{
	char mode;
	EPATHTAG* path;
	float speed;
	EVENT_PATH_LIST* next;
};

/* 10629 */
struct FACETBL
{
	char nbFrame;
	char faceNo;
};

/* 10612 */
union _UNION_STATUS
{
	float fRangeOut;
	_OBJ_SLEEPCON* pObjSleepCondition;
};

/* 10613 */
struct OBJ_CONDITION
{
	char scCount;
	char scUserFlag;
	int16_t ssCondition;
	task* pTask;
	_OBJ_EDITENTRY* pObjEditEntry;
	_UNION_STATUS unionStatus;
};

/* 10614 */
struct motionwk
{
	$20A60C9037C3BEBF64D11B94833DF168 work;
	NJS_POINT3 spd;
	NJS_POINT3 acc;
	Angle3 ang_aim;
	Angle3 ang_spd;
	float rad;
	float height;
	float weight;
};

/* 10615 */
struct forcewk
{
	void (__cdecl* call_back)(task*, taskwk*, forcewk*);
	Angle3 ang_spd;
	NJS_POINT3 pos_spd;
};

/* 10616 */
union $04C8403BBC56FFCFA636CE281666B813
{
	char ub[16];
	char sb[16];
	uint16_t uw[8];
	int16_t sw[8];
	unsigned int ul[4];
	int sl[4];
	float f[4];
	void* ptr[4];
};

/* 10617 */
struct anywk
{
	$04C8403BBC56FFCFA636CE281666B813 work;
};

/* 10488 */
struct obj
{
	unsigned int evalflags;
	NJS_MODEL* model;
	float pos[3];
	int ang[3];
	float scl[3];
	obj* child;
	obj* sibling;
};

/* 10489 */
struct NJS_MOTION
{
	void* mdata;
	unsigned int nbFrame;
	uint16_t type;
	uint16_t inp_fn;
};

/* 10498 */
struct NJS_TEXLIST
{
	NJS_TEXNAME* textures;
	unsigned int nbTexture;
};

/* 10626 */
struct EPATHTAG
{
	int points;
	epathtbl* tblhead;
};

/* 10610 */
struct _OBJ_EDITENTRY
{
	uint16_t usID;
	int16_t rotx;
	int16_t roty;
	int16_t rotz;
	float xpos;
	float ypos;
	float zpos;
	float xscl;
	float yscl;
	float zscl;
};

/* 10611 */
struct _OBJ_SLEEPCON
{
	Angle3 ang;
	NJS_POINT3 pos;
	NJS_POINT3 scl;
};

/* 10487 */
struct NJS_MODEL
{
	NJS_POINT3* points;
	NJS_POINT3* normals;
	int nbPoint;
	NJS_MESHSET* meshsets;
	NJS_MATERIAL* mats;
	uint16_t nbMeshset;
	uint16_t nbMat;
	NJS_POINT3 center;
	float r;
	void* res;
};

/* 10497 */
struct NJS_TEXNAME
{
	void* filename;
	unsigned int attr;
	unsigned int texaddr;
};

/* 10624 */
struct epathang3
{
	char x;
	char y;
	char z;
};

/* 10625 */
struct epathtbl
{
	epathang3 ang;
	NJS_POINT3 pos;
};

/* 10485 */
struct NJS_MESHSET
{
	uint16_t type_matId;
	uint16_t nbMesh;
	int16_t* meshes;
	unsigned int* attrs;
	NJS_POINT3* normals;
	NJS_COLOR* vertcolor;
	NJS_COLOR* vertuv;
	void* ext;
};

/* 10479 */
struct NJS_TEX
{
	int16_t v;
	int16_t u;
};

/* 10480 */
struct NJS_BGRA
{
	char a;
	char r;
	char g;
	char b;
};

/* 10481 */
union NJS_COLOR
{
	unsigned int color;
	NJS_TEX tex;
	NJS_BGRA argb;
};

/* 10486 */
struct NJS_MATERIAL
{
	NJS_COLOR diffuse;
	NJS_COLOR specular;
	float exponent;
	unsigned int attr_texId;
	unsigned int attrflags;
};

/* 10695 */
union $A1C9BBF4FFD96A19B46198CCB9146414
{
	char sb[32];
	char ub[32];
	int16_t sw[16];
	uint16_t uw[16];
	int sl[8];
	unsigned int ul[8];
	float f[8];
	void* ptr[8];
};

/* 10692 */
struct player_parameter
{
	int jump2_timer;
	float pos_error;
	float lim_h_spd;
	float lim_v_spd;
	float max_x_spd;
	float max_psh_spd;
	float jmp_y_spd;
	float nocon_speed;
	float slide_speed;
	float jog_speed;
	float run_speed;
	float rush_speed;
	float crash_speed;
	float dash_speed;
	float jmp_addit;
	float run_accel;
	float air_accel;
	float slow_down;
	float run_break;
	float air_break;
	float air_resist_air;
	float air_resist;
	float air_resist_y;
	float air_resist_z;
	float grd_frict;
	float grd_frict_z;
	float lim_frict;
	float rat_bound;
	float rad;
	float height;
	float weight;
	float eyes_height;
	float center_height;
};

/* 10691 */
struct mtnjvwk
{
	int16_t mtnmode;
	int16_t jvmode;
	uint16_t reqaction;
	uint16_t action;
	uint16_t lastaction;
	uint16_t nextaction;
	uint16_t acttimer;
	int16_t flag;
	float nframe;
	float start_frame;
	float* spdp;
	float* workp;
	PL_ACTION* plactptr;
	PL_JOIN_VERTEX* pljvptr;
	NJS_ACTION* actwkptr;
};

/* 10696 */
struct shadowwk
{
	int angx;
	int angz;
	unsigned int Attr_top;
	unsigned int Attr_bottom;
	float y_top;
	float y_bottom;
	unsigned int _Attr_top;
	unsigned int _Attr_bottom;
	float scl;
};

/* 10697 */
struct playerwk
{
	$20A60C9037C3BEBF64D11B94833DF168 work;
	int16_t equipment;
	int16_t item;
	int16_t jumptimer;
	int16_t nocontimer;
	int16_t breathtimer;
	int16_t waittimer;
	int16_t flag;
	int16_t island_num;
	int16_t path_point;
	float hpos;
	float dotp;
	NJS_POINT3 eff;
	NJS_POINT3 acc;
	NJS_POINT3 spd;
	NJS_POINT3 wall_normal;
	NJS_POINT3 floor_normal;
	unsigned int attr;
	unsigned int last_attr;
	csts* cstsp;
	task* htp;
	task* ttp;
	PL_FACE* pfp;
	obj* lclop;
	PL_LANDPOSI* island_list;
	$A1C9BBF4FFD96A19B46198CCB9146414 free;
	player_parameter p;
	mtnjvwk mj;
	NJS_POINT3 righthand_pos;
	NJS_POINT3 lefthand_pos;
	NJS_POINT3 rightfoot_pos;
	NJS_POINT3 leftfoot_pos;
	NJS_POINT3 user0_pos;
	NJS_POINT3 user1_pos;
	NJS_POINT3 righthand_vec;
	NJS_POINT3 lefthand_vec;
	NJS_POINT3 rightfoot_vec;
	NJS_POINT3 leftfoot_vec;
	NJS_POINT3 user0_vec;
	NJS_POINT3 user1_vec;
	shadowwk shadow;
};

/* 10694 */
struct csts
{
	float radius;
	NJS_POINT3 pos;
	NJS_POINT3 spd;
	NJS_POINT3 tnorm;
	uint16_t find_count;
	uint16_t selected_nmb;
	float yt;
	float yb;
	int angx;
	int angz;
	NJS_POINT3 normal;
	NJS_POINT3 normal2;
	NJS_POINT3 onpoly;
	NJS_POINT3 pshbk;
	NJS_POINT3 anaspdh;
	NJS_POINT3 anaspdv;
};

/* 10689 */
struct PL_FACE
{
	char lastface;
	char face;
	char reqface;
	char tblpoint;
	float frame;
	float framespeed;
	FACETBL* tbl;
	obj* sibling;
	obj* faceorg;
	obj* facebuf;
	NJS_MOTION* facetypes;
};

/* 10693 */
struct PL_LANDPOSI
{
	float x;
	float y;
	float z;
	float r;
	float d;
	float h;
	int angy_dif;
	int angy_aim;
};

/* 10688 */
struct PL_ACTION
{
	NJS_ACTION* actptr;
	char objnum;
	char mtnmode;
	uint16_t next;
	float frame;
	float racio;
};

/* 10642 */
struct PL_JOIN_VERTEX
{
	obj* objptr;
	obj* srcobj;
	obj* dstobj;
	char numVertex;
	char inpmode;
	char srcdepth;
	char dstdepth;
	NJS_POINT3* org;
	uint16_t* pnum;
};

/* 10765 */
struct motionwk2
{
	$20A60C9037C3BEBF64D11B94833DF168 work;
	NJS_POINT3 spd;
	NJS_POINT3 acc;
	Angle3 ang_aim;
	Angle3 ang_spd;
	float force;
	float accel;
	float frict;
};

NJS_POINT3 vG {};

using undefined8 = uint8_t;
using longlong = int64_t;

void PGetAccelerationAuto(taskwk* taskwk, motionwk2* motionwk2, playerwk* playerwk) {}

void PGetAccelerationTube(taskwk* taskwk, motionwk2* motionwk2, playerwk* playerwk) {}

void PConvertVector_G2P(taskwk* taskwk, NJS_POINT3* local_a8) {}

int32_t PCheckPower(taskwk* taskwk, int32_t* angle, float* power) { return 0; }

void njOuterProduct(NJS_POINT3* tnorm, NJS_POINT3* spd, NJS_POINT3* local_98) {}

void PGetAccelerationStair(taskwk* taskwk, motionwk2* motionwk2, playerwk* playerwk) {}

void PRotatedByGravity(taskwk* taskwk, motionwk2* motionwk2, playerwk* playerwk) {}

void PRotatedByGravityS(taskwk* taskwk, motionwk2* motionwk2, playerwk* playerwk) {}

void PGetRotationYAlongThePath(taskwk* taskwk, motionwk2* motionwk2, playerwk* playerwk) {}

int32_t DiffAngle(int i, long target_angle) { return 0; }

void PAdjustAngleYQ(taskwk* taskwk, playerwk* playerwk, long target_angle) {}

void PAdjustAngleYS(taskwk* taskw, playerwk* playerwk, long target_angle) {}

void PAdjustAngleY(taskwk* taskwk, motionwk* motionwk, playerwk* playerwk, long target_angle) {}

void PGetAcceleration(taskwk* const task_wk, motionwk2* const motion_wk2, playerwk* const player_wk)
{
	if ((task_wk->flag & 0x4000U) != 0)
	{
		PGetAccelerationAuto(task_wk, motion_wk2, player_wk);
		return;
	}

	if ((player_wk->attr & 0x20000) != 0)
	{
		PGetAccelerationTube(task_wk, motion_wk2, player_wk);
		return;
	}

	if ((player_wk->attr & 0x4000) != 0)
	{
		PGetAccelerationStair(task_wk, motion_wk2, player_wk);
		return;
	}

	NJS_POINT3 final_acc {};

	final_acc.y = player_wk->p.weight * vG.y + motion_wk2->acc.y;
	final_acc.x = player_wk->p.weight * vG.x + motion_wk2->acc.x;
	final_acc.z = player_wk->p.weight * vG.z + motion_wk2->acc.z;
	PConvertVector_G2P(task_wk, &final_acc);

	const float zero = 0.00000000f;

	float dVar15 = zero;
	float dVar16 = zero;

	int32_t target_angle;
	float stick_power;
	const int32_t have_analog = PCheckPower(task_wk, &target_angle, &stick_power);

	NJS_POINT3 tnorm_cross_velocity{};
	njOuterProduct(&player_wk->cstsp->tnorm, &motion_wk2->spd, &tnorm_cross_velocity);

	float dVar18 = 0.50000000f;
	float dVar22 = 0.40000001f;
	float dVar17 = 0.80000001f;

	float dVar14;
	float dVar12;

	const float dotp = player_wk->dotp;

	if (0.10000000f <= dotp || std::abs(tnorm_cross_velocity.y) <= 0.60000002f || player_wk->spd.x <= 1.15999997f)
	{
		if (-0.40000001f <= dotp || player_wk->spd.x <= 1.15999997f)
		{
			if (dotp < -0.30000001f && 1.15999997f < player_wk->spd.x)
			{
				final_acc.y = -(player_wk->p.weight * 0.80000001f - final_acc.y);
				goto LAB_8228731c;
			}

			if (dotp < -0.10000000f && 1.15999997f < player_wk->spd.x)
			{
				final_acc.y = -(player_wk->p.weight * 0.40000001f - final_acc.y);
				goto LAB_8228731c;
			}

			if (dotp < 0.50000000f)
			{
				//const float spd_x = player_wk->spd.x;
				//const float run_speed = player_wk->p.run_speed;
				//if ((spd_x < run_speed) && (-run_speed < spd_x))
				if (std::abs(player_wk->spd.x) < player_wk->p.run_speed)
				{
					final_acc.x = final_acc.x * 4.22499990f;
					dVar14 = final_acc.x;
					dVar12 = final_acc.z * 4.22499990f;
					goto LAB_82287324;
				}
			}

			if (0.69999999f <= dotp)
			{
				//fVar3 = player_wk->spd.x;
			LAB_822872d0:
				if (0.87000000f <= dotp ||
				    //((player_wk->p.jog_speed <= fVar3 || (fVar3 <= -player_wk->p.run_speed))))
				    player_wk->p.jog_speed <= std::abs(player_wk->spd.x))
					goto LAB_8228731c;
				dVar12 = final_acc.z * 1.39999998f;
			}
			else
			{
				//fVar3 = player_wk->spd.x;
				//const float run_speed = player_wk->p.run_speed;
				//if ((run_speed <= fVar3) || (fVar3 <= -run_speed))
				if (std::abs(player_wk->spd.x) > player_wk->p.run_speed)
					goto LAB_822872d0;
				dVar12 = final_acc.z * 2.00000000f;
			}
		}
		else
		{
			final_acc.y = -(player_wk->p.weight * 5.00000000f - final_acc.y);
		LAB_8228731c:
			dVar12 = final_acc.z;
		}
		dVar14 = final_acc.x;
	}
	else
	{
		final_acc.x = zero;
		final_acc.y = -player_wk->p.weight;
		dVar12 = zero;
		dVar14 = zero;
	}

LAB_82287324:
	const float spd_x = player_wk->spd.x;
	const float max_x_spd = player_wk->p.max_x_spd;

	if (have_analog == 0)
	{
		if (player_wk->p.run_speed < spd_x)
		{
		LAB_82287398:
			dVar14 = player_wk->p.air_resist * spd_x + dVar14;
			goto set_final_acc_x_to_dVar14_LAB_822873a0;
		}

	LAB_8228733c:
		if (max_x_spd < spd_x)
		{
			dVar14 = (spd_x - max_x_spd) * player_wk->p.air_resist + dVar14;
			goto set_final_acc_x_to_dVar14_LAB_822873a0;
		}

		if (spd_x < zero)
			goto LAB_82287398;
	}
	else
	{
		if (spd_x <= max_x_spd || dotp <= 0.95999998f)
			goto LAB_8228733c;
		dVar14 = (spd_x - max_x_spd) * player_wk->p.air_resist * 1.70000005f + dVar14;
	set_final_acc_x_to_dVar14_LAB_822873a0:
		final_acc.x = dVar14;
	}

	// this will either be 0 as initialized, or -0.8 (see else clause below)
	float acc_y_add = 0.00000000f;

	final_acc.y = player_wk->p.air_resist_y * player_wk->spd.y + final_acc.y;
	float final_acc_y = final_acc.y;
	final_acc.z = player_wk->p.air_resist_z * player_wk->spd.z + dVar12;
	dVar12 = final_acc.z;

	float fVar1 = dotp;

	if (have_analog == 0)
	{
		if (0.70999998f <= dotp)
		{
			if (spd_x <= zero)
			{
				if (spd_x < zero)
				{
					dVar16 = -player_wk->p.slow_down;
				}
				motion_wk2->force = zero;
			}
			else
			{
				dVar16 = player_wk->p.slow_down;
				motion_wk2->force = zero;
			}
		}
		else
		{
			PRotatedByGravity(task_wk, motion_wk2, player_wk);
			dVar12 = final_acc.z;
			//final_acc_y = final_acc.y;
			dVar14 = final_acc.x;
			motion_wk2->force = zero;
		}
	}
	else
	{
		if ((task_wk->flag & 0x2000U) == 0)
		{
			if (dotp < 0.94000000f && (player_wk->attr & 0x800000) != 0)
			{
				PRotatedByGravityS(task_wk, motion_wk2, player_wk);
			}
		}
		else
		{
			PGetRotationYAlongThePath(task_wk, motion_wk2, player_wk);
			acc_y_add = -0.80000001f;
			target_angle = motion_wk2->ang_aim.y;
		}

		dVar12 = player_wk->spd.x;
		//dVar16 = player_wk->p.max_x_spd;
		//if (dVar16 <= dVar12)
		if (player_wk->p.max_x_spd <= player_wk->spd.x)
		{
			if (dVar12 < player_wk->p.max_x_spd || zero <= player_wk->dotp)
			{
				dVar16 = player_wk->p.run_accel * stick_power * dVar22;
			}
			else
			{
			set_dVar16_run_accel_x_stick_power_LAB_82287578:
				dVar16 = player_wk->p.run_accel * stick_power;
			}
		}
		else
		{
			dVar14 = player_wk->p.jog_speed;
			//dVar16 = zero;
			if (player_wk->p.jog_speed <= dVar12)
			{
				dVar22 = player_wk->p.run_speed;
				if (dVar22 <= dVar12)
				{
					if (player_wk->p.rush_speed <= dVar12)
						goto set_dVar16_run_accel_x_stick_power_LAB_82287578;
					fVar1 = player_wk->p.run_accel;
					if (stick_power <= 0.89999998f)
					{
						dVar16 = fVar1 * stick_power * 0.30000001f;
					}
					else
					{
						dVar16 = fVar1 * stick_power;
					}
				}
				else
				{
					dVar14 = stick_power;
					if (stick_power <= 0.69999999f)
					{
						if (dVar12 < dVar22 * 2.00000000f * dVar18)
						{
							dVar16 = player_wk->p.run_accel * stick_power;
						}
					}
					else
					{
						dVar16 = player_wk->p.run_accel * stick_power;
					}
				}
			}
			else
			{
				if (stick_power <= dVar18)
				{
					if (dVar12 < dVar14 * dVar22)
					{
						dVar16 = player_wk->p.run_accel * stick_power;
					}
				}
				else
				{
					dVar16 = player_wk->p.run_accel * stick_power;
				}
			}
		}
		
		const auto diff_angle = DiffAngle(task_wk->ang.y, target_angle);
		const float forward_speed = player_wk->spd.x;

		if (forward_speed == zero && diff_angle > 0x1000)
		{
			motion_wk2->ang_aim.y = target_angle;
			dVar16 = zero;
			PAdjustAngleYQ(task_wk, player_wk, target_angle);
		}
		else
		{
			const float jog_speed = player_wk->p.jog_speed;
			if (forward_speed < (player_wk->p.run_speed + jog_speed) * dVar18 ||
			    diff_angle <= 0x1000)
			{
				if (forward_speed < jog_speed || diff_angle > 0xfff)
				{
					if (forward_speed < player_wk->p.dash_speed || (player_wk->attr & 0x800000) == 0)
					{
						if (jog_speed <= forward_speed && forward_speed <= player_wk->p.rush_speed && 0x2000 < diff_angle)
						{
							dVar16 = dVar16 * dVar17;
						}

						motion_wk2->ang_aim.y = target_angle;
						goto standard_angle_adjust_LAB_82287680;
					}

					motion_wk2->ang_aim.y = target_angle;
					PAdjustAngleYS(task_wk, player_wk, target_angle);
				}
				else
				{
					motion_wk2->ang_aim.y = target_angle;
					PAdjustAngleYS(task_wk, player_wk, target_angle);
				}
			}
			else
			{
				motion_wk2->ang_aim.y = target_angle;
				dVar16 = player_wk->p.slow_down;

			standard_angle_adjust_LAB_82287680:
				PAdjustAngleY(task_wk, (motionwk*)motion_wk2, player_wk, target_angle);
			}
		}
		dVar12 = final_acc.z;
		final_acc_y = final_acc.y;
		dVar14 = final_acc.x;
		motion_wk2->force = dVar16;
	}

	if (player_wk->dotp < 0.70999998f)
	{
		fVar1 = player_wk->spd.x;
		if (player_wk->p.jog_speed <= fVar1 || fVar1 <= -player_wk->p.jog_speed || have_analog != 0)
			goto LAB_822876ec;
		final_acc.z = dVar12 * 10.00000000f;
		dVar12 = final_acc.z;
		dVar17 = dVar14 * 10.00000000f;
	set_final_acc_x_to_dVar17_LAB_82287938:
		final_acc.x = dVar17;
	}
	else
	{
	LAB_822876ec:
		dVar17 = player_wk->spd.x;
		if (dVar17 != zero)
		{
			if (zero <= dVar16)
			{
				dVar18 = player_wk->p.lim_frict * motion_wk2->frict * final_acc_y;
				if (dVar17 < zero && dVar14 < 0.05100000f && -0.05100000f < dVar14)
				{
					final_acc.x = dVar14 + dVar16;

					if (final_acc.x * dVar16 < zero)
					{
						final_acc.x = zero;
					}

					goto LAB_8228793c;
				}

				if (dVar18 <= zero || dVar16 <= dVar18)
				{
					if (have_analog == 0)
					{
						fVar1 = player_wk->p.jog_speed;
						goto joined_r0x82287918;
					}
					goto LAB_82287934;
				}

				dVar17 = dVar14 + dVar16;
				if (dVar18 < dVar17)
				{
					motion_wk2->accel = dVar17 - dVar18;
					dVar17 = dVar18;
				}
			}
			else
			{
				if ((player_wk->attr & 4) == 0)
				{
					if (dVar17 <= zero)
					{
						if (have_analog == 0 && dVar17 <= player_wk->p.jog_speed && dVar14 < 0.05100000f &&
						    -0.05100000f < dVar14 ||
						    (dVar17 = player_wk->p.lim_frict * motion_wk2->frict * final_acc_y + dVar16,
						     zero <= dVar17))
						{
							dVar17 = zero;
						}
					}
					else
					{
						dVar17 = dVar14 + dVar16;
						if ((dVar14 + dVar16) * dVar16 < zero)
						{
							dVar17 = zero;
						}
					}
				}
				else
				{
					if (zero <= final_acc_y ||
					    (dVar18 = player_wk->p.grd_frict * motion_wk2->frict * final_acc_y, dVar18 <= zero)
					    || -dVar16 <= dVar18)
					{
						if (have_analog == 0)
						{
							fVar1 = player_wk->p.jog_speed;

						joined_r0x82287918:
							if (dVar17 <= fVar1 && dVar14 < 0.05100000f && -0.05100000f < dVar14)
							{
								final_acc.x = zero;
								goto LAB_8228793c;
							}
						}

					LAB_82287934:
						dVar17 = dVar14 + dVar16;
					}
					else
					{
						dVar17 = dVar14 + dVar16;
						if (zero <= dVar17 || -dVar18 <= dVar17)
						{
							if (zero < dVar17 && dVar18 < dVar17)
							{
								motion_wk2->accel = dVar17 - dVar18;
								dVar17 = dVar18;
							}
						}
						else
						{
							motion_wk2->accel = dVar17 - dVar18;
							dVar17 = -dVar18;
						}
					}
				}
			}

			goto set_final_acc_x_to_dVar17_LAB_82287938;
		}

		final_acc.x = dVar14 + dVar16;
		fVar1 = player_wk->p.lim_frict * motion_wk2->frict * final_acc_y;
		if (have_analog == 0 &&
		    (final_acc.x < fVar1 && -fVar1 < final_acc.x || final_acc.x < 0.05100000f && -0.05100000f < final_acc.x))
		{
			final_acc.x = zero;
		}
	}

	// set lateral acceleration (i.e. non-forward)
LAB_8228793c:
	if (player_wk->spd.z == zero)
	{
		dVar15 = player_wk->p.lim_frict * motion_wk2->frict * final_acc_y;
		if (dVar12 < dVar15 && -dVar15 < dVar12)
		{
			final_acc.z = zero;
		}
	}
	else
	{
		dVar16 = zero;

		if (final_acc_y < zero)
		{
			dVar16 = player_wk->p.grd_frict_z * motion_wk2->frict * final_acc_y;
		}

		if ((player_wk->attr & 4) == 0)
		{
			if (dVar12 <= zero)
			{
				if (dVar12 < zero)
				{
					dVar15 = dVar16;
				}
			}
			else
			{
				dVar15 = -dVar16;
			}

			dVar16 = dVar12 + dVar15;

			if (dVar12 != zero && dVar15 != zero && dVar16 * dVar12 < zero)
			{
				dVar16 = zero;
			}

			final_acc.z = dVar16;
		}
		else
		{
			if (dVar12 <= zero)
			{
				dVar15 = dVar12;

				if (dVar12 < zero && (dVar15 = dVar12 + dVar16, zero < dVar12 + dVar16))
				{
					dVar15 = zero;
				}
			}
			else
			{
				dVar15 = dVar12 - dVar16;

				if (dVar12 - dVar16 < zero)
				{
					final_acc.z = zero;
					goto done_LAB_82287a28;
				}
			}

			final_acc.z = dVar15;
		}
	}

done_LAB_82287a28:
	final_acc.y = final_acc_y + acc_y_add;
	player_wk->acc.y = final_acc.y;
	player_wk->acc.x = final_acc.x;
	player_wk->acc.z = final_acc.z;
}
