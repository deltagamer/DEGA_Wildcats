﻿class MFD
{
	class AirplaneHUD 
	{
		class Bones {};
		class Draw {};
		topLeft="HUD_top_left";
		topRight="HUD_top_right";
		bottomLeft="HUD_bottom_left";
		borderLeft=0;
		borderRight=0;
		borderTop=0;
		borderBottom=0;
		color[]={0.15000001,1,0.15000001,1};
		enableParallax=0;
		////
		helmetMountedDisplay=1;
		helmetPosition[]={0,0,0};
		helmetRight[]={0,0,0};
		helmetDown[]={0,0,0};
	};
	class Kimi_HUD_1
	{
		topLeft="HUD_top_left";
		topRight="HUD_top_right";
		bottomLeft="HUD_bottom_left";
		borderLeft=0;
		borderRight=0;
		borderTop=0;
		borderBottom=0;
		color[]={0.15000001,1,0.15000001,1};
		enableParallax=0;
		class Bones
		{
			class PlaneOrientation
			{
				type="fixed";
				pos[]={0.5,0.5};
			};
			class GunnerAim
			{
				type="vector";
				source="weapon";
				pos0[]={0.5,"0.9 - 0.04 + 0.02667"};
				pos10[]={"0.5 + 0.0111","0.9 - 0.04 + 0.02667 + 0.0133"};
			};
			class Target
			{
				source="target";
				type="vector";
				pos0[]={0.5,0.5};
				pos10[]={0.85,0.85};
			};
			class Velocity
			{
				type="vector";
				source="velocity";
				pos0[]={0.5,0.5};
				pos10[]={0.65,0.65};
			};
			class Velocity_slip
			{
				type="vector";
				source="velocity";
				pos0[]={0.5,0.845};
				pos10[]={0.53,0.845};
			};
			class VspeedBone
			{
				type="linear";
				source="vspeed";
				//sourceScale=0.19685; // 1000x feet per min
				sourceScale=1; // 100x feet per min
				min=-10;
				max=10;
				minPos[]={0.93,0.20};
				maxPos[]={0.93,0.80};
			};
			class RadarAltitudeBone
			{
				type="linear";
				source="altitudeAGL";
				//sourceScale=0.19685; // 1000x feet per min
				sourceScale=1;
				min=0;
				max=60;
				minPos[]={0.965,0.20};
				maxPos[]={0.965,0.80};
			};
			class HorizonBankRot
			{
				type="rotational";
				source="horizonBank";
				center[]={0.5,0.5};
				min=-3.1416;
				max=3.1416;
				//max=0.52359998;
				minAngle=-180;
				maxAngle=180;
				aspectRatio=1;
			};
			class ForwardVec
			{
				type = "vector";
				source = "forward";
				pos0[] = {0,0};
				pos10[] = {0.2193,0.2193};
			};
			class WeaponAim
			{
				type = "vector";
				source = "weapon";
				pos0[] = {0.5,0.5};
				pos10[] = {0.753,0.753};
			};
			class Level0
			{
				type="horizon";
				pos0[]={0.5,0.5};
				pos10[]={0.78,0.78};
				angle=0;
			};
		};
		class Draw
		{
			color[]={0.18000001,1,0.18000001};
			alpha=1;
			condition="on";
			//condition="((speed this) =< 19.44)";
			class Horizont
			{
				clipTL[]={0.15,0.15};
				clipBR[]={0.85,0.85};
				class Dimmed
				{
					class Level0
					{
						type="line";
						points[]=
						{
							
							{
								"Level0",
								{-0.42,0},
								1
							},
							
							{
								"Level0",
								{-0.38,0},
								1
							},
							{},/// 1
							
							{
								"Level0",
								{-0.37,0},
								1
							},
							
							{
								"Level0",
								{-0.33,0},
								1
							},
							{},/// 2
							
							{
								"Level0",
								{-0.32,0},
								1
							},
							
							{
								"Level0",
								{-0.28,0},
								1
							},
							{},/// 3
							
							{
								"Level0",
								{-0.27,0},
								1
							},
							
							{
								"Level0",
								{-0.23,0},
								1
							},
							{},/// 4
							
							{
								"Level0",
								{-0.22,0},
								1
							},
							
							{
								"Level0",
								{-0.18,0},
								1
							},
							{},/// 5
							
							{
								"Level0",
								{-0.17,0},
								1
							},
							
							{
								"Level0",
								{-0.13,0},
								1
							},
							{},/// 6
							
							{
								"Level0",
								{-0.12,0},
								1
							},
							
							{
								"Level0",
								{-0.08,0},
								1
							},
							{}, /// 7
							///////////////////////////////
							{
								"Level0",
								{0.42,0},
								1
							},
							
							{
								"Level0",
								{0.38,0},
								1
							},
							{},/// 1
							
							{
								"Level0",
								{0.37,0},
								1
							},
							
							{
								"Level0",
								{0.33,0},
								1
							},
							{},/// 2
							
							{
								"Level0",
								{0.32,0},
								1
							},
							
							{
								"Level0",
								{0.28,0},
								1
							},
							{},/// 3
							
							{
								"Level0",
								{0.27,0},
								1
							},
							
							{
								"Level0",
								{0.23,0},
								1
							},
							{},/// 4
							
							{
								"Level0",
								{0.22,0},
								1
							},
							
							{
								"Level0",
								{0.18,0},
								1
							},
							{},/// 5
							
							{
								"Level0",
								{0.17,0},
								1
							},
							
							{
								"Level0",
								{0.13,0},
								1
							},
							{},/// 6
							
							{
								"Level0",
								{0.12,0},
								1
							},
							
							{
								"Level0",
								{0.08,0},
								1
							}
							/// 7
						};
					};
				};
			};
			/*class StaticBank
			{
				type="line";
				width=3;
				points[]=
				{
					////////////////////////////////////////////////////// LEFT
					{{0.4782,0.2510},1},	// 5º r25
					{{0.4773,0.2410},1},	// 5º r26
					{},	
					{{0.4566,0.2538},1},	// 10º r25
					{{0.4549,0.2439},1},	// 10º r26
					{},	
					{{0.4353,0.2585},1},	// 15º r25
					{{0.4301,0.2392},1},	// 15º r27
					{},	
					{{0.4145,0.2651},1},	// 20º r25
					{{0.4111,0.2557},1},	// 20º r26
					{},	
					{{0.3943,0.2734},1},	// 25º r25
					{{0.3901,0.2644},1},	// 25º r26
					{},	
					{{0.3750,0.2835},1},	// 30º r25
					{{0.3650,0.2662},1},	// 30º r27
					{},	
					{{0.3232,0.3232},1}, 	// 45º r25
					{{0.3091,0.3091},1},	// 45º r27
					{},	
					{{0.2835,0.3750},1}, 	// 60º r25
					{{0.2662,0.3650},1},	// 60º r27
					{},	
					/////////////////////////////////////////////////////// RIGHT
					{{"0.5 + (0.5- 0.4782)",0.2510},1},	// 5º r25
					{{"0.5 + (0.5- 0.4773)",0.2410},1},	// 5º r26
					{},	
					{{"0.5 + (0.5- 0.4566)",0.2538},1},	// 10º r25
					{{"0.5 + (0.5- 0.4549)",0.2439},1},	// 10º r26
					{},	
					{{"0.5 + (0.5- 0.4353)",0.2585},1},	// 15º r25
					{{"0.5 + (0.5- 0.4301)",0.2392},1},	// 15º r27
					{},	
					{{"0.5 + (0.5- 0.4145)",0.2651},1},	// 20º r25
					{{"0.5 + (0.5- 0.4111)",0.2557},1},	// 20º r26
					{},	
					{{"0.5 + (0.5- 0.3943)",0.2734},1},	// 25º r25
					{{"0.5 + (0.5- 0.3901)",0.2644},1},	// 25º r26
					{},	
					{{"0.5 + (0.5- 0.3750)",0.2835},1},	// 30º r25
					{{"0.5 + (0.5- 0.3650)",0.2662},1},	// 30º r27
					{},	
					{{"0.5 + (0.5- 0.3232)",0.3232},1}, // 45º r25
					{{"0.5 + (0.5- 0.3091)",0.3091},1},	// 45º r27
					{},	
					{{"0.5 + (0.5- 0.2835)",0.3750},1}, // 60º r25
					{{"0.5 + (0.5- 0.2662)",0.3650},1},	// 60º r27
					{},	
					/////////////////////////////////////////////////////// CENTER
					{{0.5,"0.5 - 0.25"},1}, 	// 0º r25
					{{0.5,"0.5 - 0.28"},1}		// 0º r27
				};
			};*/
			class HorizonBankRot
			{
				type="line";
				width=3;
				points[]=
				{
					
					{
						"HorizonBankRot",
						{0,0.25},
						1
					},
					
					{
						"HorizonBankRot",
						{-0.01,0.23},
						1
					},
					
					{
						"HorizonBankRot",
						{0.01,0.23},
						1
					},
					
					{
						"HorizonBankRot",
						{0,0.25},
						1
					}
				};
			};
			class Static_HAD_BOX
			{
				clipTL[]={0,1};
				clipBR[]={1,0};
				type="line";
				width=5;
				points[]=
				{
					{{"0.5-0.1","0.9-0.04"},1},
					{{"0.5-0.1","0.9+0.04"},1},
					{{"0.5+0.1","0.9+0.04"},1},
					{{"0.5+0.1","0.9-0.04"},1},
					{{"0.5-0.1","0.9-0.04"},1},
					{},
					{{"0.5-0.1","0.9-0.04+0.02667"},1},
					{{"0.5-0.092","0.9-0.04+0.02667"},1},
					{},
					{{"0.5+0.1","0.9-0.04+0.02667"},1},
					{{"0.5+0.092","0.9-0.04+0.02667"},1},
					{},
					{{0.5,"0.9-0.04"},1},
					{{0.5,"0.9-0.032"},1},
					{},
					{{0.5,"0.9+0.04"},1},
					{{0.5,"0.9+0.032"},1},
					{}
				};
			};
			class Gunner_HAD
			{
				type="line";
				width=6;
				points[]=
				{
					{"GunnerAim",{-0.015,-0.008},1},
					{"GunnerAim",{-0.015,0.008},1},
					{"GunnerAim",{0.015,0.008},1},
					{"GunnerAim",{0.015,-0.008},1},
					{"GunnerAim",{-0.015,-0.008},1}
				};
			};
			class Centerline
			{
				type="line";
				width=7;
				points[]=
				{
					{ { 0.5,0.49 },1 },
					{ { 0.5,0.47 },1 },
					{},
					{ { 0.5,0.51 },1 },
					{ { 0.5,0.53 },1 },
					{},
					{ { 0.49,0.5 },1 },
					{ { 0.47,0.5 },1 },
					{},
					{ { 0.51,0.5 },1 },
					{ { 0.53,0.5 },1 },
					{}
				};
			};
			class Slip_ball_group
			{
				class Slip_bars
				{
					type="line";
					width=4;
					points[]=
					{
						{{"0.5-0.018","0.9-0.04"},1},
						{{"0.5-0.018","0.9-0.075"},1},
						{},
						{{"0.5+0.018","0.9-0.04"},1},
						{{"0.5+0.018","0.9-0.075"},1}
					};
				};
				class Slip_ball
				{
					type = "line";
					width = 6.0;
					points[]=
					{
						{"Velocity_slip",1,{"0 * 0.75","-0.02 * 0.75"},1},
						{"Velocity_slip",1,{"0.0099999998 * 0.75","-0.01732 * 0.75"},1},
						{"Velocity_slip",1,{"0.01732 * 0.75","-0.0099999998 * 0.75"},1},
						{"Velocity_slip",1,{"0.02 * 0.75","0 * 0.75"},1},
						{"Velocity_slip",1,{"0.01732 * 0.75","0.0099999998 * 0.75"},1},
						{"Velocity_slip",1,{"0.0099999998 * 0.75","0.01732 * 0.75"},1},
						{"Velocity_slip",1,{"0 * 0.75","0.02 * 0.75"},1},
						{"Velocity_slip",1,{"-0.0099999998 * 0.75","0.01732 * 0.75"},1},
						{"Velocity_slip",1,{"-0.01732 * 0.75","0.0099999998 * 0.75"},1},
						{"Velocity_slip",1,{"-0.02 * 0.75","0 * 0.75"},1},
						{"Velocity_slip",1,{"-0.01732 * 0.75","-0.0099999998 * 0.75"},1},
						{"Velocity_slip",1,{"-0.0099999998 * 0.75","-0.01732 * 0.75"},1},
						{"Velocity_slip",1,{"0 * 0.75","-0.02 * 0.75"},1},
						{},
						{"Velocity_slip",1,{"0 * 0.6","-0.02 * 0.6"},1},
						{"Velocity_slip",1,{"0.0099999998 * 0.6","-0.01732 * 0.6"},1},
						{"Velocity_slip",1,{"0.01732 * 0.6","-0.0099999998 * 0.6"},1},
						{"Velocity_slip",1,{"0.02 * 0.6","0 * 0.6"},1},
						{"Velocity_slip",1,{"0.01732 * 0.6","0.0099999998 * 0.6"},1},
						{"Velocity_slip",1,{"0.0099999998 * 0.6","0.01732 * 0.6"},1},
						{"Velocity_slip",1,{"0 * 0.6","0.02 * 0.6"},1},
						{"Velocity_slip",1,{"-0.0099999998 * 0.6","0.01732 * 0.6"},1},
						{"Velocity_slip",1,{"-0.01732 * 0.6","0.0099999998 * 0.6"},1},
						{"Velocity_slip",1,{"-0.02 * 0.6","0 * 0.6"},1},
						{"Velocity_slip",1,{"-0.01732 * 0.6","-0.0099999998 * 0.6"},1},
						{"Velocity_slip",1,{"-0.0099999998 * 0.6","-0.01732 * 0.6"},1},
						{"Velocity_slip",1,{"0 * 0.6","-0.02 * 0.6"},1},
						{},
						{"Velocity_slip",1,{"0 * 0.5","-0.02 * 0.5"},1},
						{"Velocity_slip",1,{"0.0099999998 * 0.5","-0.01732 * 0.5"},1},
						{"Velocity_slip",1,{"0.01732 * 0.5","-0.0099999998 * 0.5"},1},
						{"Velocity_slip",1,{"0.02 * 0.5","0 * 0.5"},1},
						{"Velocity_slip",1,{"0.01732 * 0.5","0.0099999998 * 0.5"},1},
						{"Velocity_slip",1,{"0.0099999998 * 0.5","0.01732 * 0.5"},1},
						{"Velocity_slip",1,{"0 * 0.5","0.02 * 0.5"},1},
						{"Velocity_slip",1,{"-0.0099999998 * 0.5","0.01732 * 0.5"},1},
						{"Velocity_slip",1,{"-0.01732 * 0.5","0.0099999998 * 0.5"},1},
						{"Velocity_slip",1,{"-0.02 * 0.5","0 * 0.5"},1},
						{"Velocity_slip",1,{"-0.01732 * 0.5","-0.0099999998 * 0.5"},1},
						{"Velocity_slip",1,{"-0.0099999998 * 0.5","-0.01732 * 0.5"},1},
						{"Velocity_slip",1,{"0 * 0.5","-0.02 * 0.5"},1},
						{},
						{"Velocity_slip",1,{"0 * 0.4","-0.02 * 0.4"},1},
						{"Velocity_slip",1,{"0.0099999998 * 0.4","-0.01732 * 0.4"},1},
						{"Velocity_slip",1,{"0.01732 * 0.4","-0.0099999998 * 0.4"},1},
						{"Velocity_slip",1,{"0.02 * 0.4","0 * 0.4"},1},
						{"Velocity_slip",1,{"0.01732 * 0.4","0.0099999998 * 0.4"},1},
						{"Velocity_slip",1,{"0.0099999998 * 0.4","0.01732 * 0.4"},1},
						{"Velocity_slip",1,{"0 * 0.4","0.02 * 0.4"},1},
						{"Velocity_slip",1,{"-0.0099999998 * 0.4","0.01732 * 0.4"},1},
						{"Velocity_slip",1,{"-0.01732 * 0.4","0.0099999998 * 0.4"},1},
						{"Velocity_slip",1,{"-0.02 * 0.4","0 * 0.4"},1},
						{"Velocity_slip",1,{"-0.01732 * 0.4","-0.0099999998 * 0.4"},1},
						{"Velocity_slip",1,{"-0.0099999998 * 0.4","-0.01732 * 0.4"},1},
						{"Velocity_slip",1,{"0 * 0.4","-0.02 * 0.4"},1},
						{},
						{"Velocity_slip",1,{"0 * 0.30","-0.02 * 0.30"},1},
						{"Velocity_slip",1,{"0.0099999998 * 0.30","-0.01732 * 0.30"},1},
						{"Velocity_slip",1,{"0.01732 * 0.30","-0.0099999998 * 0.30"},1},
						{"Velocity_slip",1,{"0.02 * 0.30","0 * 0.30"},1},
						{"Velocity_slip",1,{"0.01732 * 0.30","0.0099999998 * 0.30"},1},
						{"Velocity_slip",1,{"0.0099999998 * 0.30","0.01732 * 0.30"},1},
						{"Velocity_slip",1,{"0 * 0.30","0.02 * 0.30"},1},
						{"Velocity_slip",1,{"-0.0099999998 * 0.30","0.01732 * 0.30"},1},
						{"Velocity_slip",1,{"-0.01732 * 0.30","0.0099999998 * 0.30"},1},
						{"Velocity_slip",1,{"-0.02 * 0.30","0 * 0.30"},1},
						{"Velocity_slip",1,{"-0.01732 * 0.30","-0.0099999998 * 0.30"},1},
						{"Velocity_slip",1,{"-0.0099999998 * 0.30","-0.01732 * 0.30"},1},
						{"Velocity_slip",1,{"0 * 0.30","-0.02 * 0.30"},1},
						{},
						{"Velocity_slip",1,{"0 * 0.20","-0.02 * 0.20"},1},
						{"Velocity_slip",1,{"0.0099999998 * 0.20","-0.01732 * 0.20"},1},
						{"Velocity_slip",1,{"0.01732 * 0.20","-0.0099999998 * 0.20"},1},
						{"Velocity_slip",1,{"0.02 * 0.20","0 * 0.20"},1},
						{"Velocity_slip",1,{"0.01732 * 0.20","0.0099999998 * 0.20"},1},
						{"Velocity_slip",1,{"0.0099999998 * 0.20","0.01732 * 0.20"},1},
						{"Velocity_slip",1,{"0 * 0.20","0.02 * 0.20"},1},
						{"Velocity_slip",1,{"-0.0099999998 * 0.20","0.01732 * 0.20"},1},
						{"Velocity_slip",1,{"-0.01732 * 0.20","0.0099999998 * 0.20"},1},
						{"Velocity_slip",1,{"-0.02 * 0.20","0 * 0.20"},1},
						{"Velocity_slip",1,{"-0.01732 * 0.20","-0.0099999998 * 0.20"},1},
						{"Velocity_slip",1,{"-0.0099999998 * 0.20","-0.01732 * 0.20"},1},
						{"Velocity_slip",1,{"0 * 0.20","-0.02 * 0.20"},1},
						{},
						{"Velocity_slip",1,{"0 * 0.1","-0.02 * 0.1"},1},
						{"Velocity_slip",1,{"0.0099999998 * 0.1","-0.01732 * 0.1"},1},
						{"Velocity_slip",1,{"0.01732 * 0.1","-0.0099999998 * 0.1"},1},
						{"Velocity_slip",1,{"0.02 * 0.1","0 * 0.1"},1},
						{"Velocity_slip",1,{"0.01732 * 0.1","0.0099999998 * 0.1"},1},
						{"Velocity_slip",1,{"0.0099999998 * 0.1","0.01732 * 0.1"},1},
						{"Velocity_slip",1,{"0 * 0.1","0.02 * 0.1"},1},
						{"Velocity_slip",1,{"-0.0099999998 * 0.1","0.01732 * 0.1"},1},
						{"Velocity_slip",1,{"-0.01732 * 0.1","0.0099999998 * 0.1"},1},
						{"Velocity_slip",1,{"-0.02 * 0.1","0 * 0.1"},1},
						{"Velocity_slip",1,{"-0.01732 * 0.1","-0.0099999998 * 0.1"},1},
						{"Velocity_slip",1,{"-0.0099999998 * 0.1","-0.01732 * 0.1"},1},
						{"Velocity_slip",1,{"0 * 0.1","-0.02 * 0.1"},1}
					};
				};
			};
			class GunCross_CIRCLE
			{
				type="group";
				class CCIP_circle
				{
					type = "line";
					width = 4.0;
					points[] = 
					{
						{ "ForwardVec",1,"PlaneOrientation",1,{ "-1.2000 * 0.04","-0.0000 * 0.04" },1 },
						{ "ForwardVec",1,"PlaneOrientation",1,{ "-1.0000 * 0.04","-0.0000 * 0.04" },1 },
						{ "ForwardVec",1,"PlaneOrientation",1,{ "-0.9877 * 0.04","-0.1736 * 0.04" },1 },
						{ "ForwardVec",1,"PlaneOrientation",1,{ "-0.9397 * 0.04","-0.3420 * 0.04" },1 },
						{ "ForwardVec",1,"PlaneOrientation",1,{ "-0.8660 * 0.04","-0.5000 * 0.04" },1 },
						{ "ForwardVec",1,"PlaneOrientation",1,{ "-0.7660 * 0.04","-0.6428 * 0.04" },1 },
						{ "ForwardVec",1,"PlaneOrientation",1,{ "-0.6428 * 0.04","-0.7660 * 0.04" },1 },
						{ "ForwardVec",1,"PlaneOrientation",1,{ "-0.5000 * 0.04","-0.8660 * 0.04" },1 },
						{ "ForwardVec",1,"PlaneOrientation",1,{ "-0.3420 * 0.04","-0.9397 * 0.04" },1 },
						{ "ForwardVec",1,"PlaneOrientation",1,{ "-0.1736 * 0.04","-0.9877 * 0.04" },1 },
						{ "ForwardVec",1,"PlaneOrientation",1,{ "-0.0000 * 0.04","-1.0000 * 0.04" },1 },
						{ "ForwardVec",1,"PlaneOrientation",1,{ "0.1736 * 0.04","-0.9877 * 0.04" },1 },
						{ "ForwardVec",1,"PlaneOrientation",1,{ "0.3420 * 0.04","-0.9397 * 0.04" },1 },
						{ "ForwardVec",1,"PlaneOrientation",1,{ "0.5000 * 0.04","-0.8660 * 0.04" },1 },
						{ "ForwardVec",1,"PlaneOrientation",1,{ "0.6428 * 0.04","-0.7660 * 0.04" },1 },
						{ "ForwardVec",1,"PlaneOrientation",1,{ "0.7660 * 0.04","-0.6428 * 0.04" },1 },
						{ "ForwardVec",1,"PlaneOrientation",1,{ "0.8660 * 0.04","-0.5000 * 0.04" },1 },
						{ "ForwardVec",1,"PlaneOrientation",1,{ "0.9397 * 0.04","-0.3420 * 0.04" },1 },
						{ "ForwardVec",1,"PlaneOrientation",1,{ "0.9877 * 0.04","-0.1736 * 0.04" },1 },
						{ "ForwardVec",1,"PlaneOrientation",1,{ "1.0000 * 0.04","-0.0000 * 0.04" },1 },
						{ "ForwardVec",1,"PlaneOrientation",1,{ "1.2000 * 0.04","-0.0000 * 0.04" },1 },
						{ },
						{ "ForwardVec",1,"PlaneOrientation",1,{ "-1.2000 * 0.04","0.0000 * 0.04" },1 },
						{ "ForwardVec",1,"PlaneOrientation",1,{ "-1.0000 * 0.04","0.0000 * 0.04" },1 },
						{ "ForwardVec",1,"PlaneOrientation",1,{ "-0.9877 * 0.04","0.1736 * 0.04" },1 },
						{ "ForwardVec",1,"PlaneOrientation",1,{ "-0.9397 * 0.04","0.3420 * 0.04" },1 },
						{ "ForwardVec",1,"PlaneOrientation",1,{ "-0.8660 * 0.04","0.5000 * 0.04" },1 },
						{ "ForwardVec",1,"PlaneOrientation",1,{ "-0.7660 * 0.04","0.6428 * 0.04" },1 },
						{ "ForwardVec",1,"PlaneOrientation",1,{ "-0.6428 * 0.04","0.7660 * 0.04" },1 },
						{ "ForwardVec",1,"PlaneOrientation",1,{ "-0.5000 * 0.04","0.8660 * 0.04" },1 },
						{ "ForwardVec",1,"PlaneOrientation",1,{ "-0.3420 * 0.04","0.9397 * 0.04" },1 },
						{ "ForwardVec",1,"PlaneOrientation",1,{ "-0.1736 * 0.04","0.9877 * 0.04" },1 },
						{ "ForwardVec",1,"PlaneOrientation",1,{ "-0.0000 * 0.04","1.0000 * 0.04" },1 },
						{ "ForwardVec",1,"PlaneOrientation",1,{ "0.1736 * 0.04","0.9877 * 0.04" },1 },
						{ "ForwardVec",1,"PlaneOrientation",1,{ "0.3420 * 0.04","0.9397 * 0.04" },1 },
						{ "ForwardVec",1,"PlaneOrientation",1,{ "0.5000 * 0.04","0.8660 * 0.04" },1 },
						{ "ForwardVec",1,"PlaneOrientation",1,{ "0.6428 * 0.04","0.7660 * 0.04" },1 },
						{ "ForwardVec",1,"PlaneOrientation",1,{ "0.7660 * 0.04","0.6428 * 0.04" },1 },
						{ "ForwardVec",1,"PlaneOrientation",1,{ "0.8660 * 0.04","0.5000 * 0.04" },1 },
						{ "ForwardVec",1,"PlaneOrientation",1,{ "0.9397 * 0.04","0.3420 * 0.04" },1 },
						{ "ForwardVec",1,"PlaneOrientation",1,{ "0.9877 * 0.04","0.1736 * 0.04" },1 },
						{ "ForwardVec",1,"PlaneOrientation",1,{ "1.0000 * 0.04","0.0000 * 0.04" },1 },
						{ "ForwardVec",1,"PlaneOrientation",1,{ "1.2000 * 0.04","0.0000 * 0.04" },1 },
						{ },
						{ "ForwardVec",1,"PlaneOrientation",1,{ "-0.0000 * 0.04","-1.0000 * 0.04" },1 },
						{ "ForwardVec",1,"PlaneOrientation",1,{ "-0.0000 * 0.04","-1.2000 * 0.04" },1 },
						{ },
						{ "ForwardVec",1,"PlaneOrientation",1,{ "-0.0000 * 0.04","1.0000 * 0.04" },1 },
						{ "ForwardVec",1,"PlaneOrientation",1,{ "-0.0000 * 0.04","1.2000 * 0.04" },1 },
						{ },
						{ "ForwardVec",1,"PlaneOrientation",1,{ 0.005,0 },1 },
						{ "ForwardVec",1,"PlaneOrientation",1,{ -0.005,0 },1 },
						{ },
						{ "ForwardVec",1,"PlaneOrientation",1,{ 0,0.005 },1 },
						{ "ForwardVec",1,"PlaneOrientation",1,{ 0,-0.005 },1 }
					};
				};
			};
			class WeaponName
			{
				type="text";
				source="weapon";
				sourceScale=1;
				align="right";
				scale=1;
				pos[]=
				{
					{0.61,0.86},
					1
				};
				right[]=
				{
					{0.65,0.86},
					1
				};
				down[]=
				{
					{0.61,0.90},
					1
				};
			};
			class Ammo_ALL
			{
				type="group";
				//condition="mgun";
				condition="on";
				class Ammo_count_ALL
				{
					type="text";
					source="ammo";
					sourceScale=1;
					align="right";
					scale=1;
					pos[]=
					{
						{0.61,0.89},
						1
					};
					right[]=
					{
						{0.65,0.89},
						1
					};
					down[]=
					{
						{0.61,0.93},
						1
					};
				};
			};
			/*class Ammo_RKT
			{
				type="group";
				condition="rocket";
				class Ammo_count_RKT
				{
					type="text";
					source="ammo";
					sourceScale=1;
					align="right";
					scale=1;
					pos[]=
					{
						{0.61,0.89},
						1
					};
					right[]=
					{
						{0.65,0.89},
						1
					};
					down[]=
					{
						{0.61,0.93},
						1
					};
				};
			};
			class Ammo_AGM
			{
				type="group";
				condition="AAmissile";
				class Ammo_count_AGM
				{
					type="text";
					source="ammo";
					sourceScale=1;
					align="right";
					scale=1;
					pos[]=
					{
						{0.61,0.89},
						1
					};
					right[]=
					{
						{0.65,0.89},
						1
					};
					down[]=
					{
						{0.61,0.93},
						1
					};
				};
			};
			class Ammo_AAM
			{
				type="group";
				condition="ATmissile";
				class Ammo_count_AAM
				{
					type="text";
					source="ammo";
					sourceScale=1;
					align="right";
					scale=1;
					pos[]=
					{
						{0.61,0.89},
						1
					};
					right[]=
					{
						{0.65,0.89},
						1
					};
					down[]=
					{
						{0.61,0.93},
						1
					};
				};
			};
			class Ammo_Bomb
			{
				type="group";
				condition="Bomb";
				class Ammo_count_Bomb
				{
					type="text";
					source="ammo";
					sourceScale=1;
					align="right";
					scale=1;
					pos[]=
					{
						{0.61,0.89},
						1
					};
					right[]=
					{
						{0.65,0.89},
						1
					};
					down[]=
					{
						{0.61,0.93},
						1
					};
				};
			};
			*/
			class LightsGroup
			{
				type="group";
				condition="lights";
				class LightsText
				{
					type="text";
					source="static";
					text="LIGHTS";
					align="right";
					scale=1;
					pos[]=
					{
						
						{
							0.03,
							"0.53 + 0.055"
						},
						1
					};
					right[]=
					{
						
						{
							0.07,
							"0.53 + 0.055"
						},
						1
					};
					down[]=
					{
						
						{
							0.03,
							"0.53 + 0.095"
						},
						1
					};
				};
			};
			class CollisionLightsGroup
			{
				type="group";
				condition="collisionlights";
				class CollisionLightsText
				{
					type="text";
					source="static";
					text="A-COL";
					align="right";
					scale=1;
					pos[]=
					{
						
						{
							0.03,
							"0.53 + 0.105"
						},
						1
					};
					right[]=
					{
						
						{
							0.07,
							"0.53 + 0.105"
						},
						1
					};
					down[]=
					{
						
						{
							0.03,
							"0.53 + 0.145"
						},
						1
					};
				};
			};
			class ATMissileTOFGroup
			{
				condition="ATmissile";
				type="group";
				class TOFtext
				{
				type="text";
				align="right";
				source="static";
				text="TOF=";
				scale=1;
				pos[]=
				{
					{0.61,0.92},
					1
				};
				right[]=
				{
					{0.65,0.92},
					1
				};
				down[]=
				{
					{0.61,0.96},
					1
				};
			};
				class TOFnumber
				{
				type="text";
				source="targetDist";
				sourcescale = 0.0025;
				align="right";
				scale=1;
				pos[]=
				{
					{0.69,0.92},
					1
				};
				right[]=
				{
					{0.73,0.92},
					1
				};
				down[]=
				{
					{0.69,0.96},
					1
				};
			};
			};
			class RangeNumber
			{
				type="text";
				source="targetDist";
				sourceScale=1;
				align="left";
				scale=1;
				pos[]=
				{
					{0.39,0.89},
					1
				};
				right[]=
				{
					{0.43,0.89},
					1
				};
				down[]=
				{
					{0.39,0.93},
					1
				};
			};
			class RangeText
			{
				type="text";
				source="static";
				text="RNG";
				align="left";
				scale=1;
				pos[]=
				{
					{0.39,0.86},
					1
				};
				right[]=
				{
					{0.43,0.86},
					1
				};
				down[]=
				{
					{0.39,0.90},
					1
				};
			};
			class SpeedNumber
			{
				type="text";
				align="right";
				scale=1;
				source="speed";
				sourceScale=3.6;
				pos[]=
				{
					{0.03,0.475},
					1
				};
				right[]=
				{
					{0.08,0.475},
					1
				};
				down[]=
				{
					{0.03,0.525},
					1
				};
			};
			class TorqueNumber
			{
				condition = "simulRTD";
				class Torque_number
				{
					type="text";
					align="left";
					scale=1;
					source="rtdRotorTorque";
					//sourceScale=312.5;
					sourceScale = 363;
					pos[]=
					{
						{0.065,0.175},
						1
					};
					right[]=
					{
						{0.115,0.175},
						1
					};
					down[]=
					{
						{0.065,0.225},
						1
					};
				};
				class Torquetext
				{
					type="text";
					source="static";
					text="%";
					align="right";
					scale=1;
					pos[]=
					{
						{0.07,0.175},
						1
					};
					right[]=
					{
						{0.12,0.175},
						1
					};
					down[]=
					{
						{0.07,0.225},
						1
					};
				};
			};
			class AltNumber: SpeedNumber
			{
				align="right";
				source="altitudeAGL";
				sourceScale=1;
				pos[]=
				{
					{0.83,0.475},
					1
				};
				right[]=
				{
					{0.88,0.475},
					1
				};
				down[]=
				{
					{0.83,0.525},
					1
				};
			};
			class ASLNumber
			{
				type="text";
				source="altitudeASL";
				sourceScale=1;
				align="right";
				scale=1;
				pos[]=
				{
					{0.835,0.18},
					1
				};
				right[]=
				{
					{0.875,0.18},
					1
				};
				down[]=
				{
					{0.835,0.22},
					1
				};
			};
			class VspeedScalePosta
			{
					type="line";
					width=5;
					points[]= 
					{
					{ { 0.98,0.20 },1 },	// 1G
					{ { 1.00,0.20 },1 },
					{},
					{ { 0.93,0.20 },1 },	//
					{ { 0.95,0.20 },1 },
					{},
					{ { 0.98,0.35 },1 },	// 2G
					{ { 1.00,0.35 },1 },
					{},
					{ { 0.93,0.35 },1 },	//
					{ { 0.95,0.35 },1 },
					{},
					{ { 0.94,0.38 },1 },  
					{ { 0.95,0.38 },1 },
					{},
					{ { 0.94,0.41 },1 },  
					{ { 0.95,0.41 },1 },
					{},
					{ { 0.94,0.44 },1 },  
					{ { 0.95,0.44 },1 },
					{},
					{ { 0.94,0.47 },1 },  
					{ { 0.95,0.47 },1 },
					{},
					{ { 0.98,0.50 },1 },	// 3G
					{ { 1.00,0.50 },1 },
					{},
					{ { 0.93,0.50 },1 },	//
					{ { 0.95,0.50 },1 },
					{},
					{ { 0.94,0.53 },1 },  
					{ { 0.95,0.53 },1 },
					{},
					{ { 0.94,0.56 },1 },  
					{ { 0.95,0.56 },1 },
					{},
					{ { 0.94,0.59 },1 },  
					{ { 0.95,0.59 },1 },
					{},
					{ { 0.94,0.62 },1 },  
					{ { 0.95,0.62 },1 },
					{},
					{ { 0.98,0.65 },1 },	// 4G
					{ { 1.00,0.65 },1 },
					{},
					{ { 0.93,0.65 },1 },	//
					{ { 0.95,0.65 },1 },
					{},
					{ { 0.99,0.68 },1 },  
					{ { 0.98,0.68 },1 },
					{},
					{ { 0.99,0.71 },1 },  
					{ { 0.98,0.71 },1 },
					{},
					{ { 0.99,0.74 },1 },  
					{ { 0.98,0.74 },1 },
					{},
					{ { 0.99,0.77 },1 },  
					{ { 0.98,0.77 },1 },
					{},
					{ { 0.98,0.80 },1 },	// 5G
					{ { 1.00,0.80 },1 },
					{},
					{ { 0.93,0.80 },1 },	//
					{ { 0.95,0.80 },1 },
					{}
					};
			};
			class RadarAltitudeBand
			{
				clipTL[]={0,0.2};
				clipBR[]={1,0.8};
				class radarbanda
				{
				type="line";
				width=17;
				points[]=
				{
					{
						"RadarAltitudeBone",
						{0,0},
						1
					},
					
					{
						"RadarAltitudeBone",
						{0,0.60},
						1
					}
				};
				};
			};
			class VspeedBand
			{
				type="line";
				width=3;
				points[]=
				{
					{
						"VspeedBone",
						{-0.01,0.0},
						1
					},
					
					{
						"VspeedBone",
						{-0.025,-0.015},
						1
					},
					
					{
						"VspeedBone",
						{-0.025,0.015},
						1
					},
					
					{
						"VspeedBone",
						{-0.01,0.0},
						1
					},
					{}
				};
				};
			class HeadingNumber: SpeedNumber
			{
				source="heading";
				//source="compass";
				sourceScale=1;
				align="center";
				pos[]=
				{
					{0.5,0.01},
					1
				};
				right[]=
				{
					{0.56,0.01},
					1
				};
				down[]=
				{
					{0.5,0.06},
					1
				};
			};
			class Center_box
			{
				type = "line";
				width = 3.0;
				points[] = 
				{
					{ { 0.44,0.005 },1 },
					{ { "0.44 + 0.12",0.005 },1 },
					{ { "0.44 + 0.12","0.005 + 0.06" },1 },
					{ { 0.44,"0.005 + 0.06" },1 },
					{ { 0.44,0.005 },1 }};
			};
			class HeadingArrow
			{
				type="line";
				width=7;
				points[]=
				{
					
					{
						
						{
							"0.5",
							"0.128 + 0.03"
						},
						1
					},
					
					{
						{0.5,0.128},
						1
					}
					
				};
			};
			class HeadingScale
			{
				type="scale";
				horizontal=1;
				source="heading";
				sourceScale=1;
				width=5;
				top=0.12;
				center=0.5;
				bottom=0.88;
				lineXleft="0.03 + 0.085";
				lineYright="0.02 + 0.085";
				lineXleftMajor="0.04 + 0.085";
				lineYrightMajor="0.02 + 0.085";
				majorLineEach=3;
				numberEach=3;
				//step="18 / 9";
				//stepSize="(0.70 - 0.3) / 15";
				step=10;
				stepSize="0.05";
				align="center";
				scale=1;
				pos[]=
				{
					0.119,
					"0.0 + 0.065"
				};
				right[]=
				{
					0.159,
					"0.0 + 0.065"
				};
				down[]=
				{
					0.119,
					"0.04 + 0.065"
				};
			};
			class Fuel_Text
			{
				type="text";
				source="static";
				text="Fuel";
				align="right";
				scale=1;
				pos[]=
				{
					{0.03,0.90},
					1
				};
				right[]=
				{
					{0.07,0.90},
					1
				};
				down[]=
				{
					{0.03,0.94},
					1
				};
			};
			class Fuel_Number
			{
				type="text";
				source="fuel";
				sourceScale=100;
				align="right";
				scale=1;
				pos[]=
				{
					{0.10,0.90},
					1
				};
				right[]=
				{
					{0.14,0.90},
					1
				};
				down[]=
				{
					{0.10,0.94},
					1
				};
			};
		};
		helmetMountedDisplay=1;
		helmetPosition[]={-0.040,0.040,0.10};
		helmetRight[]={0.080000001,0,0};
		helmetDown[]={-0,-0.080000001,0};
	};
	class Kimi_HUD_2
	{
		topLeft="HUD_top_left";
		topRight="HUD_top_right";
		bottomLeft="HUD_bottom_left";
		borderLeft=0;
		borderRight=0;
		borderTop=0;
		borderBottom=0;
		color[]={0.15000001,1,0.15000001,1};
		enableParallax=0;
		class Bones
		{
			class Velocity
			{
				type="vector";
				source="velocity";
				pos0[]={0.5,0.5};
				pos10[]={0.75,0.75};
			};
			class ForwardVec1
			{
				type = "vector";
				source = "forward";
				pos0[] = {0,0};
				pos10[] = {0.25,0.25};
			};
			class ForwardVec
			{
				type = "vector";
				source = "forward";
				pos0[] = {0,0};
				pos10[] = {0.253,0.253};
			};
			class WeaponAim
			{
				type = "vector";
				source = "weapon";
				pos0[] = {0.5,0.5};
				pos10[] = {0.753,0.753};
			};
			class WeaponAim1
			{
				type = "vector";
				source = "weapon";
				pos0[] = {0,0};
				pos10[] = {0.253,0.23};
			};
			class Target
			{
				type="vector";
				source="target";
				pos0[]={0.5,0.5};
				pos10[]={0.753,0.753};
			};
			class RadarContact
			{
				//source="radar";
				type="fixed";
				pos[]={0,0};
			};
		};
		class Draw
		{
			color[]={0.18000001,1,0.18000001};
			alpha=1;
			condition="on";
			class PlaneMovementCrosshair
			{
				type="line";
				width=7;
				points[]=
				{
					{
						"ForwardVec1",1,"Velocity",1,
						{0,-0.02},
						1
					},
					
					{
						"ForwardVec1",1,"Velocity",1,
						{0.0099999998,-0.01732},
						1
					},
					
					{
						"ForwardVec1",1,"Velocity",1,
						{0.01732,-0.0099999998},
						1
					},
					
					{
						"ForwardVec1",1,"Velocity",1,
						{0.02,0},
						1
					},
					
					{
						"ForwardVec1",1,"Velocity",1,
						{0.01732,0.0099999998},
						1
					},
					
					{
						"ForwardVec1",1,"Velocity",1,
						{0.0099999998,0.01732},
						1
					},
					
					{
						"ForwardVec1",1,"Velocity",1,
						{0,0.02},
						1
					},
					
					{
						"ForwardVec1",1,"Velocity",1,
						{-0.0099999998,0.01732},
						1
					},
					
					{
						"ForwardVec1",1,"Velocity",1,
						{-0.01732,0.0099999998},
						1
					},
					
					{
						"ForwardVec1",1,"Velocity",1,
						{-0.02,0},
						1
					},
					
					{
						"ForwardVec1",1,"Velocity",1,
						{-0.01732,-0.0099999998},
						1
					},
					
					{
						"ForwardVec1",1,"Velocity",1,
						{-0.0099999998,-0.01732},
						1
					},
					
					{
						"ForwardVec1",1,"Velocity",1,
						{0,-0.02},
						1
					},
					{},
					
					{
						"ForwardVec1",1,"Velocity",1,
						{0.039999999,0},
						1
					},
					
					{
						"ForwardVec1",1,"Velocity",1,
						{0.02,0},
						1
					},
					{},
					
					{
						"ForwardVec1",1,"Velocity",1,
						{-0.039999999,0},
						1
					},
					
					{
						"ForwardVec1",1,"Velocity",1,
						{-0.02,0},
						1
					},
					{},
					
					{
						"ForwardVec1",1,"Velocity",1,
						{0,-0.039999999},
						1
					},
					
					{
						"ForwardVec1",1,"Velocity",1,
						{0,-0.02},
						1
					}
				};
			};
			class Gunner_AIM
			{
				type = "line";
				width = 7.0;
				points[] = 
				{
					{ "ForwardVec",1,"WeaponAim",1,{ 0,-0.020 },1 },
					{ "ForwardVec",1,"WeaponAim",1,{ 0,-0.010 },1 },
					{  },
					{ "ForwardVec",1,"WeaponAim",1,{ 0,-0.0225 },1 },
					{ "ForwardVec",1,"WeaponAim",1,{ 0,-0.0325 },1 },
					{  },
					{ "ForwardVec",1,"WeaponAim",1,{ 0,0.010 },1 },
					{ "ForwardVec",1,"WeaponAim",1,{ 0,0.020 },1 },
					{  },
					{ "ForwardVec",1,"WeaponAim",1,{ 0,0.0225 },1 },
					{ "ForwardVec",1,"WeaponAim",1,{ 0,0.0325 },1 },
					{  },
					{ "ForwardVec",1,"WeaponAim",1,{ -0.020,0 },1 },
					{ "ForwardVec",1,"WeaponAim",1,{ -0.010,0 },1 },
					{  },
					{ "ForwardVec",1,"WeaponAim",1,{ -0.0225,0 },1 },
					{ "ForwardVec",1,"WeaponAim",1,{ -0.0325,0 },1 },
					{  },
					{ "ForwardVec",1,"WeaponAim",1,{ 0.010,0 },1 },
					{ "ForwardVec",1,"WeaponAim",1,{ 0.020,0 },1 },
					{  },
					{ "ForwardVec",1,"WeaponAim",1,{ 0.0225,0 },1 },
					{ "ForwardVec",1,"WeaponAim",1,{ 0.0325,0 },1 }
				};
			};
			class TargetACQ
			{
				type="line";
				width=2;
				points[]=
				{
					//////////////////////////////////////////////// UP
					/*{ "ForwardVec1",1,"target",{ 0,-0.10 },1 },
					{ "ForwardVec1",1,"target",{ 0,-0.095 },1 },
					{},
					{ "ForwardVec1",1,"target",{ 0,-0.09 },1 },
					{ "ForwardVec1",1,"target",{ 0,-0.085 },1 },
					{},
					{ "ForwardVec1",1,"target",{ 0,-0.080 },1 },
					{ "ForwardVec1",1,"target",{ 0,-0.075 },1 },
					{},
					{ "ForwardVec1",1,"target",{ 0,-0.070 },1 },
					{ "ForwardVec1",1,"target",{ 0,-0.065 },1 },
					{},
					*/
					{ "ForwardVec",1,"target",{ 0,-0.060 },1 },
					{ "ForwardVec",1,"target",{ 0,-0.055 },1 },
					{},
					{ "ForwardVec",1,"target",{ 0,-0.050 },1 },
					{ "ForwardVec",1,"target",{ 0,-0.045 },1 },
					{},
					{ "ForwardVec",1,"target",{ 0,-0.040 },1 },
					{ "ForwardVec",1,"target",{ 0,-0.035 },1 },
					{},
					{ "ForwardVec",1,"target",{ 0,-0.030 },1 },
					{ "ForwardVec",1,"target",{ 0,-0.025 },1 },
					{},
					{ "ForwardVec",1,"target",{ 0,-0.020 },1 },
					{ "ForwardVec",1,"target",{ 0,-0.015 },1 },
					{},
					{ "ForwardVec",1,"target",{ 0,-0.010 },1 },
					{ "ForwardVec",1,"target",{ 0,-0.005 },1 },
					{},
					//////////////////////////////////////////////// center
					{ "ForwardVec",1,"target",{ 0,0 },1 },
					{ "ForwardVec",1,"target",{ 0,0 },1 },
					{},
					/////////////////////////////////////////////// DOWN
					/*{ "ForwardVec1",1,"target",{ 0,0.10 },1 },
					{ "ForwardVec1",1,"target",{ 0,0.095 },1 },
					{},
					{ "ForwardVec1",1,"target",{ 0,0.09 },1 },
					{ "ForwardVec1",1,"target",{ 0,0.085 },1 },
					{},
					{ "ForwardVec1",1,"target",{ 0,0.080 },1 },
					{ "ForwardVec1",1,"target",{ 0,0.075 },1 },
					{},
					{ "ForwardVec1",1,"target",{ 0,0.070 },1 },
					{ "ForwardVec1",1,"target",{ 0,0.065 },1 },
					{},*/
					{ "ForwardVec",1,"target",{ 0,0.060 },1 },
					{ "ForwardVec",1,"target",{ 0,0.055 },1 },
					{},
					{ "ForwardVec",1,"target",{ 0,0.050 },1 },
					{ "ForwardVec",1,"target",{ 0,0.045 },1 },
					{},
					{ "ForwardVec",1,"target",{ 0,0.040 },1 },
					{ "ForwardVec",1,"target",{ 0,0.035 },1 },
					{},
					{ "ForwardVec",1,"target",{ 0,0.030 },1 },
					{ "ForwardVec",1,"target",{ 0,0.025 },1 },
					{},
					{ "ForwardVec",1,"target",{ 0,0.020 },1 },
					{ "ForwardVec",1,"target",{ 0,0.015 },1 },
					{},
					{ "ForwardVec",1,"target",{ 0,0.010 },1 },
					{ "ForwardVec",1,"target",{ 0,0.005 },1 },
					{},
					/////////////////////////////////////////////// LEFT
					/*{ "ForwardVec1",1,"target",{ -0.10, 0 },1 },
					{ "ForwardVec1",1,"target",{ -0.095, 0 },1 },
					{},
					{ "ForwardVec1",1,"target",{ -0.09, 0 },1 },
					{ "ForwardVec1",1,"target",{ -0.085, 0 },1 },
					{},
					{ "ForwardVec1",1,"target",{ -0.080, 0 },1 },
					{ "ForwardVec1",1,"target",{ -0.075, 0 },1 },
					{},
					{ "ForwardVec1",1,"target",{ -0.070, 0 },1 },
					{ "ForwardVec1",1,"target",{ -0.065, 0 },1 },
					{},*/
					{ "ForwardVec",1,"target",{ -0.060, 0 },1 },
					{ "ForwardVec",1,"target",{ -0.055, 0 },1 },
					{},
					{ "ForwardVec",1,"target",{ -0.050, 0 },1 },
					{ "ForwardVec",1,"target",{ -0.045, 0 },1 },
					{},
					{ "ForwardVec",1,"target",{ -0.040, 0 },1 },
					{ "ForwardVec",1,"target",{ -0.035, 0 },1 },
					{},
					{ "ForwardVec",1,"target",{ -0.030, 0 },1 },
					{ "ForwardVec",1,"target",{ -0.025, 0 },1 },
					{},
					{ "ForwardVec",1,"target",{ -0.020, 0 },1 },
					{ "ForwardVec",1,"target",{ -0.015, 0 },1 },
					{},
					{ "ForwardVec",1,"target",{ -0.010, 0 },1 },
					{ "ForwardVec",1,"target",{ -0.005, 0 },1 },
					{},
					/////////////////////////////////////////////// RIGHT
					/*{ "ForwardVec1",1,"target",{ 0.10, 0 },1 },
					{ "ForwardVec1",1,"target",{ 0.095, 0 },1 },
					{},
					{ "ForwardVec1",1,"target",{ 0.09, 0 },1 },
					{ "ForwardVec1",1,"target",{ 0.085, 0 },1 },
					{},
					{ "ForwardVec1",1,"target",{ 0.080, 0 },1 },
					{ "ForwardVec1",1,"target",{ 0.075, 0 },1 },
					{},
					{ "ForwardVec1",1,"target",{ 0.070, 0 },1 },
					{ "ForwardVec1",1,"target",{ 0.065, 0 },1 },
					{},*/
					{ "ForwardVec",1,"target",{ 0.060, 0 },1 },
					{ "ForwardVec",1,"target",{ 0.055, 0 },1 },
					{},
					{ "ForwardVec",1,"target",{ 0.050, 0 },1 },
					{ "ForwardVec",1,"target",{ 0.045, 0 },1 },
					{},
					{ "ForwardVec",1,"target",{ 0.040, 0 },1 },
					{ "ForwardVec",1,"target",{ 0.035, 0 },1 },
					{},
					{ "ForwardVec",1,"target",{ 0.030, 0 },1 },
					{ "ForwardVec",1,"target",{ 0.025, 0 },1 },
					{},
					{ "ForwardVec",1,"target",{ 0.020, 0 },1 },
					{ "ForwardVec",1,"target",{ 0.015, 0 },1 },
					{},
					{ "ForwardVec",1,"target",{ 0.010, 0 },1 },
					{ "ForwardVec",1,"target",{ 0.005, 0 },1 },
					{}
				};
			};
		};
		helmetMountedDisplay=1;
		helmetPosition[]={-0.035,0.035,0.10};
		helmetRight[]={0.070000001,0,0};
		helmetDown[]={-0,-0.070000001,0};
	};
};