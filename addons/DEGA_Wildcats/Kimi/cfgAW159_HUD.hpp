// common definition for all vectors projected into HUD space


#define XtoYscale  (SizeX10deg/SizeY10deg)

#define CIRCLE(bone,scale) \
{bone,{0,__EVAL(-scale/XtoYscale)},1},{bone,{__EVAL(+0.7*scale),__EVAL(-0.7*scale/XtoYscale)},1}, \
{bone,{+scale,0},1},                  {bone,{__EVAL(+0.7*scale),__EVAL(+0.7*scale/XtoYscale)},1}, \
{bone,{0,__EVAL(+scale/XtoYscale)},1},{bone,{__EVAL(-0.7*scale),__EVAL(+0.7*scale/XtoYscale)},1}, \
{bone,{-scale,0},1},                  {bone,{__EVAL(-0.7*scale),__EVAL(-0.7*scale/XtoYscale)},1}, \
{bone,{0,__EVAL(-scale/XtoYscale)},1}

#define CIRCLE_BIG(bone,scale) \
{bone,{0,__EVAL(-scale/XtoYscale)},1},{bone,{__EVAL(+0.50*scale),__EVAL(-0.87*scale/XtoYscale)},1},{bone,{__EVAL(+0.87*scale),__EVAL(-0.50*scale/XtoYscale)},1}, \
{bone,{__EVAL(+scale),0},1},                  {bone,{__EVAL(+0.87*scale),__EVAL(+0.50*scale/XtoYscale)},1},{bone,{__EVAL(+0.50*scale),__EVAL(+0.87*scale/XtoYscale)},1}, \
{bone,{0,__EVAL(+scale/XtoYscale)},1},{bone,{__EVAL(-0.50*scale),__EVAL(+0.87*scale/XtoYscale)},1},{bone,{__EVAL(-0.87*scale),__EVAL(+0.50*scale/XtoYscale)},1}, \
{bone,{__EVAL(-scale),0},1},                  {bone,{__EVAL(-0.87*scale),__EVAL(-0.50*scale/XtoYscale)},1},{bone,{__EVAL(-0.50*scale),__EVAL(-0.87*scale/XtoYscale)},1}, \
{bone,{0,__EVAL(-scale/XtoYscale)},1}

#define CIRCLE_MARK(bone,scaleIn,scaleOut,angle) \
{bone,{__EVAL(scaleIn *sin(angle)),__EVAL(-scaleIn *cos(angle)/XtoYscale)},1}, \
{bone,{__EVAL(scaleOut*sin(angle)),__EVAL(-scaleOut*cos(angle)/XtoYscale)},1}

#define POINT(bone,xx,yy) \
{bone,{__EVAL(xx),__EVAL(yy/(XtoYscale))},1}

#define POINT2(xx,yy) \
{{__EVAL(xx),__EVAL(yy/(XtoYscale))},1}

#define POINT_END() {}

#define DEF_HORIZONT(XX) class LevelP##XX:Level0 {type=line;points[]={{LevelP##XX,{-0.20,+0.03},1},{LevelP##XX,{-0.20,0},1},{LevelP##XX,{-0.05,0},1},{},{LevelP##XX,{ 0.05,0},1},{LevelP##XX,{+0.20,0},1},{LevelP##XX,{+0.20,+0.03},1};};}; \
	class VALP_1_##XX\
	{\
		type=text;\
		source=static;\
		text=#XX;\
		align=left;\
		scale=1;\
		sourceScale=1;\
		pos[]={LevelP##XX,{-0.23,0.035},1};\
		right[]={LevelP##XX,{-0.13,0.035},1};\
		down[]={LevelP##XX,{-0.23,0.085},1};\
	};\
	class VALP_2_##XX:VALP_1_##XX\
	{\
		align=right;\
		pos[]={LevelP##XX,{0.22,0.035},1};\
		right[]={LevelP##XX,{0.32,0.035},1};\
		down[]={LevelP##XX,{0.22,0.085},1};\
	}

#define DEF_HORIZONTMinus(XX) class LevelM##XX:Level0 {type=line;points[]={{LevelM##XX,{-0.20,-0.03},1},{LevelM##XX,{-0.20,0},1},{LevelM##XX,{-0.15,0},1},{},{LevelM##XX,{-0.10,0},1},{LevelM##XX,{-0.05,0},1},{},{LevelM##XX,{ 0.05,0},1},{LevelM##XX,{+0.10,0},1},{},{LevelM##XX,{ 0.15,0},1},{LevelM##XX,{+0.20,0},1},{LevelM##XX,{+0.20,-0.03},1};};}; \
	class VALM_1_##XX\
	{\
		type=text;\
		source=static;\
		text=-##XX;\
		align=left;\
		scale=1;\
		sourceScale=1;\
		pos[]={LevelM##XX,{-0.23,-0.085},1};\
		right[]={LevelM##XX,{-0.13,-0.085},1};\
		down[]={LevelM##XX,{-0.23,-0.035},1};\
	};\
	class VALM_2_##XX:VALM_1_##XX\
	{\
		align=right;\
		pos[]={LevelM##XX,{0.22,-0.085},1};\
		right[]={LevelM##XX,{0.32,-0.085},1};\
		down[]={LevelM##XX,{0.22,-0.035},1};\
	}


class Pos10Vector
{
	type=vector;
	// position of 0-degree dive line
	pos0[]={PosX0Center,PosY0Center};
	// position of 10 degree bank and 10-degree dive (used to adjust scale)
	//pos10[]={2.0,PosY0Center+1.3};
	pos10[]={__EVAL(PosX0Center+SizeX10deg),__EVAL(PosY0Center+SizeY10deg)};
};

topLeft = "HUD LH";
topRight = "HUD PH";
bottomLeft = "HUD LD";
/// adjust position inside of memory points LOD
borderLeft = 0;
borderRight = 0;
borderTop = 0;
borderBottom = 0;
color[]={0,1,0,0.1}; // master color

class Bones
{

	class PlaneW
	{
		type=fixed;
		pos[]={PosX0Center,PosYCenterHorizont};
	};

	class WeaponAim: Pos10Vector
	{
		source=weapon;
	};
	class GunnerAim: Pos10Vector
	{
		source=weapon;
		pos0[]={0,-0.0025};
		pos10[]={0.01,0.0025};
	};
	class Target: Pos10Vector
	{
		source=target;
	};
	class Velocity: Pos10Vector
	{
		type=vector;
		source=velocity;
		pos0[]={0.5,PosY0Center};
		pos10[]={__EVAL(0.5+SizeX10deg),__EVAL(PosY0Center+SizeY10deg)};
	};

	class ILS_H
	{
		type=ils;
		// position when centered
		pos0[]={0.5,PosY0Center};
		// position when 3-degree off in both directions
		pos3[]={__EVAL(0.5+SizeX10deg*3/10),PosY0Center};
	};
	class ILS_W:ILS_H
	{
		pos3[]={0.5,__EVAL(PosY0Center+SizeY10deg*3/10)};
	};
	class Level0: Pos10Vector
	{
		pos0[]={0.5,PosYCenterHorizont};
		pos10[]={__EVAL(0.5+SizeX10deg),__EVAL(PosYCenterHorizont+SizeY10deg)};
		type=horizon;
		// horizon angle to which this line corresponds to
		angle=0;
	};
	class LevelP10: Level0 {angle=+10;};
	class LevelM10: Level0 {angle=-10;};
	class LevelP20: Level0 {angle=+20;};
	class LevelM20: Level0 {angle=-20;};
	class LevelP30: Level0 {angle=+30;};
	class LevelM30: Level0 {angle=-30;};
	class LevelP40: Level0 {angle=+40;};
	class LevelM40: Level0 {angle=-40;};
	class LevelP50: Level0 {angle=+50;};
	class LevelM50: Level0 {angle=-50;};
/*	class TargetDistanceMissile
	{
		type=rotational;
		source=targetDist;
		center[]={0,0};
		min=100;
		max=3000;
		minAngle=-120;
		maxAngle=+120;
	}; */
};
class Draw
{
	alpha=0.6;
	color[]={0.0,0.5,0.05};
	condition="on";

	//color[]={0.5,0.05,0.05};
	class PlaneW
	{
		clipTL[]={0.0,1.0};
		clipBR[]={1.0,0.0};

		type=line;
		width = 4.0;

		points[]={
			CIRCLE(PlaneW,0.02),{},

		};
	};
	class PlaneHeading
	{
		clipTL[]={0.0,1.0};
		clipBR[]={1.0,0.0};
		type=line;
		width = 4.0;

		points[]={
			CIRCLE(Velocity,0.02),{},
			{Velocity, { 0.04, __EVAL(0/XtoYscale)}, 1}, {Velocity, { 0.02, __EVAL(0/XtoYscale)}, 1},{},
			{Velocity, {-0.04, __EVAL(0/XtoYscale)}, 1}, {Velocity, {-0.02, __EVAL(0/XtoYscale)}, 1},{},
			{Velocity, {0, __EVAL(-0.04/XtoYscale)}, 1}, {Velocity, {0, __EVAL(-0.02/XtoYscale)}, 1},{}
		};
	};
	class Static
	{
		clipTL[]={0.0,0.1};
		clipBR[]={1.0,0.0};
		type=line;
		width = 4.0;
		points[]={
//			{{0.21, 0.52}, 1}, {{0.19, 0.50}, 1},{{0.21, 0.48}, 1},{},
			{{0.79, 0.52}, 1}, {{0.81, 0.50}, 1},{{0.79, 0.48}, 1},{},
			{{0.52, 0.08+0.06}, 1}, {{0.50, 0.06+0.06}, 1},{{0.48, 0.08+0.06}, 1},{},


			{{0.5-0.1, 0.9-0.04}, 1},
			{{0.5-0.1, 0.9+0.04}, 1},
			{{0.5+0.1, 0.9+0.04}, 1},
			{{0.5+0.1, 0.9-0.04}, 1},
			{{0.5-0.1, 0.9-0.04}, 1},{},

			{{0.5-0.1, 0.9}, 1},
			{{0.5-0.092, 0.9}, 1},{},

			{{0.5+0.1, 0.9}, 1},
			{{0.5+0.092, 0.9}, 1},{},

			{{0.5, 0.9-0.04}, 1},
			{{0.5, 0.9-0.032}, 1},{},

			{{0.5, 0.9+0.04}, 1},
			{{0.5, 0.9+0.032}, 1},{},
		};
	};
	class Gunner
	{
		type=line;
		width = 4.0;
		points[]={
			{GunnerAim,{0.5-0.015, 0.9-0.008}, 1},
			{GunnerAim,{0.5-0.015, 0.9+0.008}, 1},
			{GunnerAim,{0.5+0.015, 0.9+0.008}, 1},
			{GunnerAim,{0.5+0.015, 0.9-0.008}, 1},
			{GunnerAim,{0.5-0.015, 0.9-0.008}, 1},
		};
	};

/*	class Target
	{
		type=line;
		points[]={
			POINT(Target,-0.05,-0.05),
			POINT(Target,+0.05,-0.05),
			POINT(Target,+0.05,+0.05),
			POINT(Target,-0.05,+0.05),
			POINT(Target,-0.05,-0.05)
		};
	};    */

#ifndef NO_RADAR
	class RadarTargets
	{
		type=radar;
		pos0[]={PosX0Center,PosY0Center};
		pos10[]={__EVAL(PosX0Center+SizeX10deg),__EVAL(PosY0Center+SizeY10deg)};

		points[]={
			POINT2(-0.05,-0.05),
			POINT2(+0.05,-0.05),
			POINT2(+0.05,+0.05),
			POINT2(-0.05,+0.05),
			POINT2(-0.05,-0.05)
		};
	};
#endif

	class MGun
	{
		condition="mgun";
		class Circle
		{
			type=line;
			width = 4.0;

			points[]={
				POINT(WeaponAim,0.05, 0.0), POINT(WeaponAim,0.015, 0.0),{},
				POINT(WeaponAim,0.0, 0.05), POINT(WeaponAim,0.0, 0.015),{},
				POINT(WeaponAim,-0.05, 0.0), POINT(WeaponAim,-0.015, 0.0),{},
				POINT(WeaponAim,0.0, -0.05), POINT(WeaponAim,0.0, -0.015),{},

			};
		};
	};


	class Bomb
	{
		condition="bomb";
		class Circle
		{
			type=line;
	       		width = 4.0;

			points[]={
				CIRCLE_BIG(WeaponAim,0.1),{},
				{Velocity,0.001,WeaponAim,{0.0, 0.0}, 1}, {Velocity,{0.0, 0.0}, 1},{},
				POINT(Target,0.0,-0.07),
				POINT(Target,+0.07,0.0),
				POINT(Target,0.0,+0.07),
				POINT(Target,-0.07,0.0),
				POINT(Target,0.0,-0.07),
			};
		};
	};
	class AAMissile
	{
		condition="AAmissile";
		class Circle
		{
			type=line;
			width = 4.0;

			points[]={
				CIRCLE_BIG(WeaponAim,0.25),{},
				POINT(Target,0.0,-0.07),
				POINT(Target,+0.07,0.0),
				POINT(Target,0.0,+0.07),
				POINT(Target,-0.07,0.0),
				POINT(Target,0.0,-0.07),
			};
		};
	};
	class ATMissile
	{
		condition="ATmissile";
		class Circle
		{
			type=line;
			width = 4.0;

			points[]={
				{WeaponAim,{-0.15, -0.15}, 1},{WeaponAim,{-0.15, -0.15+0.02}, 1},{},
				{WeaponAim,{-0.15, +0.15}, 1},{WeaponAim,{-0.15, +0.15-0.02}, 1},{},
				{WeaponAim,{0.15, -0.15}, 1},{WeaponAim,{0.15, -0.15+0.02}, 1},{},
				{WeaponAim,{0.15, +0.15}, 1},{WeaponAim,{0.15, +0.15-0.02}, 1},{},
				{WeaponAim,{-0.15, -0.15}, 1},{WeaponAim,{-0.15+0.02, -0.15}, 1},{},
				{WeaponAim,{-0.15, +0.15}, 1},{WeaponAim,{-0.15+0.02, +0.15}, 1},{},
				{WeaponAim,{0.15, -0.15}, 1},{WeaponAim,{0.15-0.02, -0.15}, 1},{},
				{WeaponAim,{0.15, +0.15}, 1},{WeaponAim,{0.15-0.02, +0.15}, 1},{},
			};
		};
	};
	class Rockets
	{
		condition="Rocket";
		class Circle
		{
			type=line;
			width = 4.0;

			points[]={
				{WeaponAim,{-0.25, -0.25}, 1},{WeaponAim,{-0.25, -0.25+0.05}, 1},{},
				{WeaponAim,{-0.25, +0.25}, 1},{WeaponAim,{-0.25, +0.25-0.05}, 1},{},
				{WeaponAim,{0.25, -0.25}, 1},{WeaponAim,{0.25, -0.25+0.05}, 1},{},
				{WeaponAim,{0.25, +0.25}, 1},{WeaponAim,{0.25, +0.25-0.05}, 1},{},
				{WeaponAim,{-0.25, -0.25}, 1},{WeaponAim,{-0.25+0.05, -0.25}, 1},{},
				{WeaponAim,{-0.25, +0.25}, 1},{WeaponAim,{-0.25+0.05, +0.25}, 1},{},
				{WeaponAim,{0.25, -0.25}, 1},{WeaponAim,{0.25-0.05, -0.25}, 1},{},
				{WeaponAim,{0.25, +0.25}, 1},{WeaponAim,{0.25-0.05, +0.25}, 1},{},

				POINT(WeaponAim,0.035, 0.035), POINT(WeaponAim,0.01, 0.01),{},
				POINT(WeaponAim,-0.035, 0.035), POINT(WeaponAim,-0.01, 0.01),{},
				POINT(WeaponAim,-0.035, -0.035), POINT(WeaponAim,-0.01, -0.01),{},
				POINT(WeaponAim,0.035, -0.035), POINT(WeaponAim,0.01, -0.01),{},

			};
		};
	};


	class SpeedNumber
	{
		type=text;
		align=right;
		scale=1; // text size
		source=speed;
		sourceScale=3.6; // convert from m/s to km/h
		pos[]={{0.06,0.47},1};
		right[]={{0.14-0.02,0.47},1};
		down[]={{0.06,0.52},1};
	};

	class AltNumber:SpeedNumber
	{
		source=altitudeAGL;
		sourceScale=1;
		pos[]={{0.86-0.15,0.47},1};
		right[]={{0.94-0.15-0.02,0.47},1};
		down[]={{0.86-0.15,0.52},1};
	};

	class AltScale
	{
		type=scale;
		scale=1; // text size
		source=altitudeAGL;
		sourceScale=1;
		align=right;
		width = 4.0;

		pos[]={0.86,0.82};
		right[]={0.94-0.02,0.82};
		down[]={0.86,0.87};

		lineXleft = 0.825;
		lineYright = 0.835;
		lineXleftMajor = 0.825;
		lineYrightMajor = 0.845;

		bottom= 0.2;
		top = 0.85;
		center = 0.50;
		step = 20;
		StepSize = (0.85- 0.2)/20;

		horizontal = false;
		min = none;
		max = none;
		numberEach = 5;
		majorLineEach = 5;
	};





	class weapons
	{
		type=text;
		source=weapon;
		align=right;
		scale=0.5; // text size
		sourceScale=1;
		pos[]={{0.1,0.88},1};
		right[]={{0.16-0.02,0.88},1};
		down[]={{0.1,0.92},1};
	};
	class ammo
	{
		type=text;
		source=ammo;
		align=right;
		scale=0.5; // text size
		sourceScale=1;
		pos[]={{0.1,0.93},1};
		right[]={{0.16-0.02,0.93},1};
		down[]={{0.1,0.97},1};
	};
/*	class weaponDistNumber
	{
		type=text;
		scale=1; // text size
		source=weaponDist;
		align=center;
		sourceScale=1;
		pos[]={{0.51,0.1},1};
		right[]={{0.59,0.1},1};
		down[]={{0.51,0.15},1};
	};    */


	class HeadingScale
	{
		type=scale;
		scale=1; // text size
		source=Heading;
		sourceScale=1;
		align=center;
		width = 4.0;

		pos[]={0.32-0.01,0.0+0.05};
		right[]={0.38-0.01,0.0+0.05};
		down[]={0.32-0.01,0.04+0.05};

		lineXleft = 0.06+0.05;
		lineYright = 0.05+0.05;
		lineXleftMajor = 0.07+0.05;
		lineYrightMajor = 0.04+0.05;

		bottom= 0.70;
		center = 0.50;
		top = 0.30;
		step = 10;
		StepSize = (0.70- 0.3)/15;

		horizontal = true;
		min = none;
		max = none;
		numberEach = 3;
		majorLineEach = 3;
	};
	
	class HorizontalLine
	{
		clipTL[]={0.2, 0.12};
		clipBR[]={0.8, 0.96};		

		class HorizontalLineDraw
		{		
			type=line;
			source = Level0;
		
			#define lineSegmentWidth 0.075/2
			points[]=
			{
				/*{Level0, {-8*lineSegmentWidth, 0.02}, 1},	
				{Level0, {-7*lineSegmentWidth, 0.02}, 1},
				{},*/
				{Level0, {-6*lineSegmentWidth, 0.02}, 1},	
				{Level0, {-5*lineSegmentWidth, 0.02}, 1},
				{},
				{Level0, {-4*lineSegmentWidth, 0.02}, 1},	
				{Level0, {-3*lineSegmentWidth, 0.02}, 1},
				{},
				{Level0, {-2*lineSegmentWidth, 0.02}, 1},	
				{Level0, {-1*lineSegmentWidth, 0.02}, 1},
				
				{},
				
				{Level0, {1*lineSegmentWidth, 0.02}, 1},	
				{Level0, {2*lineSegmentWidth, 0.02}, 1},
				{},
				{Level0, {3*lineSegmentWidth, 0.02}, 1},	
				{Level0, {4*lineSegmentWidth, 0.02}, 1},
				{},
				{Level0, {5*lineSegmentWidth, 0.02}, 1},	
				{Level0, {6*lineSegmentWidth, 0.02}, 1}/*,
				{},
				{Level0, {7*lineSegmentWidth, 0.02}, 1},	
				{Level0, {8*lineSegmentWidth, 0.02}, 1}*/							
			};
		};
	};
};