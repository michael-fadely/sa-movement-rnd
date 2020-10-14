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

int32_t DiffAngle(int angle_a, int angle_b) { return 0; }

void PAdjustAngleYQ(taskwk* taskwk, playerwk* playerwk, int target_angle) {}

void PAdjustAngleYS(taskwk* taskw, playerwk* playerwk, int target_angle) {}

void PAdjustAngleY(taskwk* taskwk, motionwk* motionwk, playerwk* playerwk, int target_angle) {}

void PGetAcceleration(taskwk* const task_wk, motionwk2* const motion_wk2, playerwk* const player_wk)
{
	float fVar1;
	float fVar2;
	float fVar3;
	taskwk* ptVar4;
	int32_t have_analog;
	int32_t diff_angle;
	motionwk2* pmVar7;
	playerwk* ppVar9;
	double dVar10;
	double dVar11;
	double dVar12;
	double dVar13;
	double dVar14;
	double dVar15;
	double dVar16;
	double dVar17;
	double dVar18;
	double dVar19;
	double dVar20;
	double dVar21;
	double zero_reused;
	double zero;
	float stick_power;
	int32_t target_angle;
	NJS_POINT3 final_acc;
	NJS_POINT3 tnorm_cross_velocity;

	playerwk* const lVar8 = player_wk;
	motionwk2* const lVar6 = motion_wk2;
	taskwk* const uVar5 = task_wk;
	ptVar4 = uVar5;
	/* Symbol Ref: No symbol: ?PGetAcceleration@@YAXPAUtaskwk@@PAUmotionwk2@@PAUplayerwk@@@Z::$M84758 */
	pmVar7 = lVar6;
	ppVar9 = lVar8;
	if ((ptVar4->flag & 0x4000U) != 0)
	{
		PGetAccelerationAuto(ptVar4, pmVar7, ppVar9);
		return;
	}
	if ((ppVar9->attr & 0x20000) != 0)
	{
		PGetAccelerationTube(uVar5, lVar6, lVar8);
		return;
	}
	if ((ppVar9->attr & 0x4000) != 0)
	{
		PGetAccelerationStair(uVar5, lVar6, lVar8);
		return;
	}
	fVar1 = (ppVar9->p).weight;
	final_acc.y = fVar1 * vG.y + (pmVar7->acc).y;
	final_acc.x = fVar1 * vG.x + (pmVar7->acc).x;
	final_acc.z = fVar1 * vG.z + (pmVar7->acc).z;
	zero_reused = 0.00000000;
	dVar14 = zero_reused;
	zero = zero_reused;
	dVar15 = zero_reused;
	PConvertVector_G2P(ptVar4, &final_acc);
	have_analog = PCheckPower(ptVar4, &target_angle, &stick_power);
	njOuterProduct(&ppVar9->cstsp->tnorm, &pmVar7->spd, &tnorm_cross_velocity);
	fVar1 = ppVar9->dotp;
	dVar17 = 0.50000000;
	dVar18 = 0.69999999;
	dVar20 = 2.00000000;
	dVar21 = 0.40000001;
	dVar16 = 0.80000001;
	if (((0.10000000 <= fVar1) || (std::abs(tnorm_cross_velocity.y) <= 0.60000002f)) || ((ppVar9->spd).x <= 1.15999997))
	{
		if ((-0.40000001 <= fVar1) || ((ppVar9->spd).x <= 1.15999997))
		{
			if ((fVar1 < -0.30000001) && (1.15999997 < (ppVar9->spd).x))
			{
				final_acc.y = -((ppVar9->p).weight * 0.80000001 - final_acc.y);
				goto LAB_8228731c;
			}
			if ((fVar1 < -0.10000000) && (1.15999997 < (ppVar9->spd).x))
			{
				final_acc.y = -((ppVar9->p).weight * 0.40000001 - final_acc.y);
				goto LAB_8228731c;
			}
			if (fVar1 < 0.50000000)
			{
				fVar3 = (ppVar9->spd).x;
				fVar2 = (ppVar9->p).run_speed;
				if ((fVar3 < fVar2) && (-fVar2 < fVar3))
				{
					final_acc.x = final_acc.x * 4.22499990;
					dVar13 = (double)final_acc.x;
					dVar11 = (double)(final_acc.z * 4.22499990);
					goto LAB_82287324;
				}
			}
			if (0.69999999 <= fVar1)
			{
			LAB_822872d0:
				if ((0.87000000 <= fVar1) ||
				    ((fVar3 = (ppVar9->spd).x, (ppVar9->p).jog_speed <= fVar3 || (fVar3 <= -(ppVar9->p).run_speed))))
					goto LAB_8228731c;
				dVar11 = (double)(final_acc.z * 1.39999998);
			}
			else
			{
				fVar3 = (ppVar9->spd).x;
				fVar2 = (ppVar9->p).run_speed;
				if ((fVar2 <= fVar3) || (fVar3 <= -fVar2))
					goto LAB_822872d0;
				dVar11 = (double)(final_acc.z * 2.00000000);
			}
		}
		else
		{
			final_acc.y = -((ppVar9->p).weight * 5.00000000 - final_acc.y);
		LAB_8228731c:
			dVar11 = (double)final_acc.z;
		}
		dVar13 = (double)final_acc.x;
	}
	else
	{
		final_acc.x = (float)zero;
		final_acc.y = -(ppVar9->p).weight;
		dVar11 = zero;
		dVar13 = zero;
	}
LAB_82287324:
	dVar12 = (double)(ppVar9->spd).x;
	if (have_analog == 0)
	{
		if ((double)(ppVar9->p).run_speed < dVar12)
		{
		LAB_82287398:
			dVar13 = (double)(float)((double)(ppVar9->p).air_resist * dVar12 + dVar13);
			goto LAB_822873a0;
		}
	LAB_8228733c:
		dVar10 = (double)(ppVar9->p).max_x_spd;
		if (dVar10 < dVar12)
		{
			dVar13 = (double)(float)((double)(float)(dVar12 - dVar10) * (double)(ppVar9->p).air_resist + dVar13);
			goto LAB_822873a0;
		}
		if (dVar12 < zero)
			goto LAB_82287398;
	}
	else
	{
		dVar10 = (double)(ppVar9->p).max_x_spd;
		if ((dVar12 <= dVar10) || (fVar1 <= 0.95999998))
			goto LAB_8228733c;
		dVar13 = (double)(float)((double)((float)(dVar12 - dVar10) * (ppVar9->p).air_resist) * 1.70000005 + dVar13);
	LAB_822873a0:
		final_acc.x = (float)dVar13;
	}
	final_acc.y = (ppVar9->p).air_resist_y * (ppVar9->spd).y + final_acc.y;
	dVar10 = (double)final_acc.y;
	final_acc.z = (float)((double)(ppVar9->p).air_resist_z * (double)(ppVar9->spd).z + dVar11);
	dVar11 = (double)final_acc.z;
	dVar19 = 0.70999998;
	if (have_analog == 0)
	{
		if (0.70999998 <= fVar1)
		{
			if (dVar12 <= zero)
			{
				if (dVar12 < zero)
				{
					dVar15 = -(double)(ppVar9->p).slow_down;
				}
				pmVar7->force = (float)zero;
			}
			else
			{
				dVar15 = (double)(ppVar9->p).slow_down;
				pmVar7->force = (float)zero;
			}
		}
		else
		{
			PRotatedByGravity(ptVar4, pmVar7, ppVar9);
			dVar11 = (double)final_acc.z;
			dVar10 = (double)final_acc.y;
			dVar13 = (double)final_acc.x;
			pmVar7->force = (float)zero;
		}
	}
	else
	{
		if ((ptVar4->flag & 0x2000U) == 0)
		{
			if ((fVar1 < 0.94000000) && ((ppVar9->attr & 0x800000) != 0))
			{
				PRotatedByGravityS(uVar5, lVar6, lVar8);
			}
		}
		else
		{
			PGetRotationYAlongThePath(uVar5, lVar6, lVar8);
			zero_reused = -0.80000001;
			target_angle = (pmVar7->ang_aim).y;
		}
		dVar11 = (double)(ppVar9->spd).x;
		dVar15 = (double)(ppVar9->p).max_x_spd;
		if (dVar15 <= dVar11)
		{
			if ((dVar11 < dVar15) || (zero <= (double)ppVar9->dotp))
			{
				dVar15 = (double)(float)((double)((ppVar9->p).run_accel * stick_power) * dVar21);
			}
			else
			{
			LAB_82287578:
				dVar15 = (double)((ppVar9->p).run_accel * stick_power);
			}
		}
		else
		{
			dVar13 = (double)(ppVar9->p).jog_speed;
			dVar15 = zero;
			if (dVar13 <= dVar11)
			{
				dVar21 = (double)(ppVar9->p).run_speed;
				if (dVar21 <= dVar11)
				{
					if ((double)(ppVar9->p).rush_speed <= dVar11)
						goto LAB_82287578;
					fVar1 = (ppVar9->p).run_accel;
					if (stick_power <= 0.89999998)
					{
						dVar15 = (double)(fVar1 * stick_power * 0.30000001);
					}
					else
					{
						dVar15 = (double)(fVar1 * stick_power);
					}
				}
				else
				{
					dVar13 = (double)stick_power;
					if (dVar13 <= dVar18)
					{
						if (dVar11 < (double)(float)((double)(float)(dVar21 * dVar20) * dVar17))
						{
							dVar15 = (double)(float)((double)(ppVar9->p).run_accel * dVar13);
						}
					}
					else
					{
						dVar15 = (double)(float)((double)(ppVar9->p).run_accel * dVar13);
					}
				}
			}
			else
			{
				dVar18 = (double)stick_power;
				if (dVar18 <= dVar17)
				{
					if (dVar11 < (double)(float)(dVar13 * dVar21))
					{
						dVar15 = (double)(float)((double)(ppVar9->p).run_accel * dVar18);
					}
				}
				else
				{
					dVar15 = (double)(float)((double)(ppVar9->p).run_accel * dVar18);
				}
			}
		}
		diff_angle = DiffAngle((ptVar4->ang).y, target_angle);
		dVar18 = (double)(ppVar9->spd).x;
		if ((dVar18 == zero) && (0x1000 < diff_angle))
		{
			(pmVar7->ang_aim).y = target_angle;
			dVar15 = zero;
			PAdjustAngleYQ(ptVar4, ppVar9, target_angle);
		}
		else
		{
			dVar20 = (double)(ppVar9->p).jog_speed;
			if ((dVar18 < (double)(float)((double)(float)((double)(ppVar9->p).run_speed + dVar20) * dVar17)) ||
			    (diff_angle < 0x1001))
			{
				if ((dVar18 < dVar20) || (0xfff < diff_angle))
				{
					if ((dVar18 < (double)(ppVar9->p).dash_speed) || ((ppVar9->attr & 0x800000) == 0))
					{
						if (((dVar20 <= dVar18) && (dVar18 <= (double)(ppVar9->p).rush_speed)) && (0x2000 < diff_angle))
						{
							dVar15 = (double)(float)(dVar15 * dVar16);
						}
						(pmVar7->ang_aim).y = target_angle;
						goto LAB_82287680;
					}
					(pmVar7->ang_aim).y = target_angle;
					PAdjustAngleYS(uVar5, ppVar9, target_angle);
				}
				else
				{
					(pmVar7->ang_aim).y = target_angle;
					PAdjustAngleYS(uVar5, ppVar9, target_angle);
				}
			}
			else
			{
				(pmVar7->ang_aim).y = target_angle;
				dVar15 = (double)(ppVar9->p).slow_down;
			LAB_82287680:
				PAdjustAngleY(ptVar4, (motionwk*)pmVar7, ppVar9, target_angle);
			}
		}
		dVar11 = (double)final_acc.z;
		dVar10 = (double)final_acc.y;
		dVar13 = (double)final_acc.x;
		pmVar7->force = (float)dVar15;
	}
	if ((double)ppVar9->dotp < dVar19)
	{
		fVar1 = (ppVar9->spd).x;
		fVar3 = (ppVar9->p).jog_speed;
		if (((fVar3 <= fVar1) || (fVar1 <= -fVar3)) || (have_analog != 0))
			goto LAB_822876ec;
		final_acc.z = (float)(dVar11 * 10.00000000);
		dVar11 = (double)final_acc.z;
		dVar16 = (double)(float)(dVar13 * 10.00000000);
	LAB_82287938:
		final_acc.x = (float)dVar16;
	}
	else
	{
	LAB_822876ec:
		dVar16 = (double)(ppVar9->spd).x;
		if (dVar16 != zero)
		{
			if (zero <= dVar15)
			{
				dVar17 = (double)(float)((double)((ppVar9->p).lim_frict * pmVar7->frict) * dVar10);
				if (((dVar16 < zero) && (dVar13 < 0.05100000)) && (-0.05100000 < dVar13))
				{
					final_acc.x = (float)(dVar13 + dVar15);
					if ((double)(float)((double)final_acc.x * dVar15) < zero)
					{
						final_acc.x = (float)zero;
					}
					goto LAB_8228793c;
				}
				if ((dVar17 <= zero) || (dVar15 <= dVar17))
				{
					if (have_analog == 0)
					{
						fVar1 = (ppVar9->p).jog_speed;
						goto joined_r0x82287918;
					}
					goto LAB_82287934;
				}
				dVar16 = (double)(float)(dVar13 + dVar15);
				if (dVar17 < dVar16)
				{
					pmVar7->accel = (float)(dVar16 - dVar17);
					dVar16 = dVar17;
				}
			}
			else
			{
				if ((ppVar9->attr & 4) == 0)
				{
					if (dVar16 <= zero)
					{
						if (((((have_analog == 0) && (dVar16 <= (double)(ppVar9->p).jog_speed)) && (dVar13 < 0.05100000)) &&
						     (-0.05100000 < dVar13)) ||
						    (dVar16 = (double)(float)((double)((ppVar9->p).lim_frict * pmVar7->frict) * dVar10 + dVar15),
						     zero <= dVar16))
						{
							dVar16 = zero;
						}
					}
					else
					{
						dVar16 = (double)(float)(dVar13 + dVar15);
						if ((double)(float)((double)(float)(dVar13 + dVar15) * dVar15) < zero)
						{
							dVar16 = zero;
						}
					}
				}
				else
				{
					if (((zero <= dVar10) ||
					     (dVar17 = (double)(float)((double)((ppVar9->p).grd_frict * pmVar7->frict) * dVar10), dVar17 <= zero)) ||
					    (-dVar15 <= dVar17))
					{
						if (have_analog == 0)
						{
							fVar1 = (ppVar9->p).jog_speed;
						joined_r0x82287918:
							if (((dVar16 <= (double)fVar1) && (dVar13 < 0.05100000)) && (-0.05100000 < dVar13))
							{
								final_acc.x = (float)zero;
								goto LAB_8228793c;
							}
						}
					LAB_82287934:
						dVar16 = (double)(float)(dVar13 + dVar15);
					}
					else
					{
						dVar16 = (double)(float)(dVar13 + dVar15);
						if ((zero <= dVar16) || (-dVar17 <= dVar16))
						{
							if ((zero < dVar16) && (dVar17 < dVar16))
							{
								pmVar7->accel = (float)(dVar16 - dVar17);
								dVar16 = dVar17;
							}
						}
						else
						{
							pmVar7->accel = (float)(dVar16 - dVar17);
							dVar16 = -dVar17;
						}
					}
				}
			}
			goto LAB_82287938;
		}
		final_acc.x = (float)(dVar13 + dVar15);
		fVar1 = (float)((double)((ppVar9->p).lim_frict * pmVar7->frict) * dVar10);
		if ((have_analog == 0) &&
		    (((final_acc.x < fVar1 && (-fVar1 < final_acc.x)) || ((final_acc.x < 0.05100000 && (-0.05100000 < final_acc.x))))))
		{
			final_acc.x = (float)zero;
		}
	}
LAB_8228793c:
	if ((double)(ppVar9->spd).z == zero)
	{
		dVar14 = (double)(float)((double)((ppVar9->p).lim_frict * pmVar7->frict) * dVar10);
		if ((dVar11 < dVar14) && (-dVar14 < dVar11))
		{
			final_acc.z = (float)zero;
		}
	}
	else
	{
		dVar15 = zero;
		if (dVar10 < zero)
		{
			dVar15 = (double)(float)((double)((ppVar9->p).grd_frict_z * pmVar7->frict) * dVar10);
		}
		if ((ppVar9->attr & 4) == 0)
		{
			if (dVar11 <= zero)
			{
				if (dVar11 < zero)
				{
					dVar14 = dVar15;
				}
			}
			else
			{
				dVar14 = -dVar15;
			}
			dVar15 = (double)(float)(dVar11 + dVar14);
			if (((dVar11 != zero) && (dVar14 != zero)) && ((double)(float)(dVar15 * dVar11) < zero))
			{
				dVar15 = zero;
			}
			final_acc.z = (float)dVar15;
		}
		else
		{
			if (dVar11 <= zero)
			{
				dVar14 = dVar11;
				if ((dVar11 < zero) && (dVar14 = (double)(float)(dVar11 + dVar15), zero < (double)(float)(dVar11 + dVar15)))
				{
					dVar14 = zero;
				}
			}
			else
			{
				dVar14 = (double)(float)(dVar11 - dVar15);
				if ((double)(float)(dVar11 - dVar15) < zero)
				{
					final_acc.z = (float)zero;
					goto LAB_82287a28;
				}
			}
			final_acc.z = (float)dVar14;
		}
	}
LAB_82287a28:
	final_acc.y = (float)(dVar10 + zero_reused);
	(ppVar9->acc).y = final_acc.y;
	(ppVar9->acc).x = final_acc.x;
	(ppVar9->acc).z = final_acc.z;
}
