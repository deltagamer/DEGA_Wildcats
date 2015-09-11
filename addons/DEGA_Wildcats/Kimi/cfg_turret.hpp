class Turrets: Turrets
{
	class MainTurret: MainTurret
	{
		showHMD = 1; /// yeah
		stabilizedInAxes=3;
		minElev=-40;
		maxElev=20;
		initElev=0;
		minTurn=-120;
		maxTurn=120;
		initTurn=0;
		//turretInfoType = "RscOptics_UAV_Gunner";
		turretInfoType="Rsc_HMDs_Kimi_Helo_UI_Turret";
		copilotHasFlares = 1;
		gunnerHasFlares = 0;
		weapons[]=
		{
			"Laserdesignator_mounted",
			"CMFlareLauncher"
		};
		magazines[]=
		{
			"Laserbatteries",
			"168Rnd_CMFlare_Chaff_Magazine"
		};
		LockDetectionSystem="1 + 2 + 4 + 8";
		incomingMissileDetectionSystem=16;
		TurretCanSee = "1+2+4+8+16";
		gunnerOpticsEffect[]={};
		gunnerOpticsModel="";
		class OpticsIn 
		{
			class WideNGS
			{
				opticsDisplayName = "W";
				initAngleX = 0;
				minAngleX = -35;
				maxAngleX = 10;
				initAngleY = 0;
				minAngleY = -100;
				maxAngleY = 100;
				initFov = 0.466;
				minFov = 0.466;
				maxFov = 0.466;
				visionMode[] = {"Normal",/*"NVG", */"Ti"};
				thermalMode[] = {0, 1};
				gunnerOpticsColor[]= {0.15000001,1,0.15000001,1};
				gunnerOpticsModel = "A3\Weapons_F\Reticle\Optics_Gunner_MBT_03_w_F.p3d";
				directionStabilized=0;
				opticsPPEffects[]=
				{
					"OpticsCHAbera2",
					"OpticsBlur2"
				};
			};
			class Wide 
			{
				opticsDisplayName = "W";
				initAngleX = 0;
				minAngleX = -35;
				maxAngleX = 10;
				initAngleY = 0;
				minAngleY = -100;
				maxAngleY = 100;
				initFov = 0.466;
				minFov = 0.466;
				maxFov = 0.466;
				visionMode[] = {"Normal",/*"NVG",*/ "Ti"};
				thermalMode[] = {0, 1};
				gunnerOpticsColor[]= {0.15000001,1,0.15000001,1};
				gunnerOpticsModel = "A3\Weapons_F\Reticle\Optics_Gunner_MBT_02_w_F.p3d";
				//gunnerOpticsModel = "A3\drones_f\Weapons_F_Gamma\Reticle\UAV_Optics_Gunner_wide_F.p3d";
				directionStabilized=1;
				opticsPPEffects[]=
				{
					"OpticsCHAbera2",
					"OpticsBlur2"
				};
				gunnerOpticsEffect[]=
				{
					"TankCommanderOptics1"
				};
			};
			class WideL: Wide 
			{
				opticsDisplayName = "WL";
				initFov = 0.2;
				minFov = 0.2;
				maxFov = 0.2;
				//gunnerOpticsModel = "A3\Weapons_F\Reticle\Optics_Gunner_MBT_02_w_F.p3d";
				//gunnerOpticsModel = "A3\drones_f\Weapons_F_Gamma\Reticle\UAV_Optics_Gunner_wide_F.p3d";
				gunnerOpticsModel = "A3\Weapons_F\Reticle\Optics_Gunner_MBT_02_m_F.p3d";
				gunnerOpticsColor[]= {0,0,0,1};
				directionStabilized=1;	// Camera Stabilizing Boolean
				opticsPPEffects[]=
				{
					"OpticsCHAbera2",
					"OpticsBlur2"
				};
			};
			class Medium : Wide 
			{
				opticsDisplayName = "M";
				initFov = 0.1;
				minFov = 0.1;
				maxFov = 0.1;
				directionStabilized=1;	// Camera Stabilizing Boolean
				gunnerOpticsColor[]= {0,0,0,1};
				//gunnerOpticsModel = "A3\drones_f\Weapons_F_Gamma\Reticle\UAV_Optics_Gunner_medium_F.p3d";
				gunnerOpticsModel = "A3\Weapons_F\Reticle\Optics_Gunner_MBT_02_m_F.p3d";
			};
			class Narrow : Wide 
			{
				opticsDisplayName = "N";
				gunnerOpticsColor[]= {0,0,0,1};
				gunnerOpticsModel = "A3\Weapons_F\Reticle\Optics_Gunner_MBT_02_n_F.p3d";
				//gunnerOpticsModel = "A3\drones_f\Weapons_F_Gamma\Reticle\UAV_Optics_Gunner_narrow_F.p3d";
				directionStabilized=1;	// Camera Stabilizing Boolean
				initFov = 0.02;
				minFov = 0.02;
				maxFov = 0.02;
			};
			class Narrower : Wide 
			{
				opticsDisplayName = "N";
				gunnerOpticsColor[]= {0,0,0,1};
				gunnerOpticsModel = "A3\Weapons_F\Reticle\Optics_Gunner_MBT_02_n_F.p3d";
				//gunnerOpticsModel = "A3\drones_f\Weapons_F_Gamma\Reticle\UAV_Optics_Gunner_narrow_F.p3d";
				directionStabilized=1;	// Camera Stabilizing Boolean
				initFov = 0.01;
				minFov = 0.01;
				maxFov = 0.01;
			};
		};
		class OpticsOut
		{
			class Monocular
			{
				initAngleX=0;
				minAngleX=-30;
				maxAngleX=30;
				initAngleY=0;
				minAngleY=-100;
				maxAngleY=100;
				initFov=1.1;
				minFov=0.133;
				maxFov=1.1;
				visionMode[]=
				{
					"Normal",
					"NVG"
				};
				gunnerOpticsModel="";
				gunnerOpticsEffect[]={};
			};
		};
		startEngine=0;
	};
};