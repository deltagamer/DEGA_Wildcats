#include "basicDefines.hpp"
#include "Crewanimations.hpp"
#include "config_extra.hpp"

class CfgVehicles
{
	class Air;
	class Helicopter: Air
	{
		class Turrets;
		class HitPoints;
	};
	class Helicopter_Base_F: Helicopter
	{
		class HitPoints: HitPoints
		{
			class HitHull;
			class HitFuel;
			class HitEngine;
			class HitAvionics;
			class HitHRotor;
			class HitVRotor;
			class HitGlass1;
			class HitGlass2;
			class HitGlass3;
			class HitGlass4;
			class HitGlass5;				
		};
		class Turrets: Turrets
		{
			class MainTurret;
		};
		class AnimationSources;
		class Eventhandlers;
		class ViewOptics;
	};
////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////AW159 Wildcat////////////////////////////////
///////////////////////////////////////Base/////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
	class DEGA_Wildcat_Base: Helicopter_Base_F
	{
//		expansion = 2; // BAF
		scope = 1;
		side = 1;
		faction = "BLU_F";
		
	    author = "Deltagamer";

        driveOnComponent[] = {"Wheels"};		
		
		selectionHRotorStill = "velka vrtule staticka";
		selectionHRotorMove = "velka vrtule blur";
		selectionVRotorStill = "mala vrtule staticka";
		selectionVRotorMove = "mala vrtule blur";
		
		#include "\DEGA_Wildcats\Kimi\cfg_HMD_Lynx_Unarmed_Metric.hpp"

		tf_RadioType_api = "tf_anarc210";
		tf_hasLRradio_api = 1; // 1 = true, 0 = false
		tf_isolatedAmount_api = 0.2;			
		
		displayname = AW159 Wildcat (Base);
		class Library {libTextDesc = $STR_BAF_CFGVEHICLES_AW159_LYNX_BAF_LIBRARY0;}; 
		
		simulation = "HelicopterX";		
		
		slingLoadMemoryPoint = "slingLoad0";
		slingLoadMaxCargoMass = 1500;
		slingLoadOperator = 1;	
        liftForceCoef = 2.5;
	
        memoryPointDriverOptics = "slingCamera";	/// what memory point is the origin of the camera		
	
		mapSize = 20;
		
		// Crew definition

		crew = "B_Helipilot_F";
		crewVulnerable = true;
		typicalCargo[]={B_Soldier_F,B_Soldier_F};
		driverAction = AW159_Pilot_BAF;
		GetInAction = GetInHigh;
		GetOutAction = GetOutHigh; 
		cargoAction[]={AW159_Cargo_BAF, AW159_Cargo01_BAF, AW159_Cargo01_BAF, AW159_Cargo01_BAF, AW159_Cargo01_BAF, AW159_Cargo01_BAF, AW159_Cargo01_BAF, AW159_Cargo01_BAF};
		cargoIsCoDriver[]={true,false};
		memoryPointsGetInGunner[] = {"pos codriver","pos cargo"};
		memoryPointsGetInGunnerDir[] = {"pos codriver dir","pos cargo dir"};
		memoryPointsGetInCargo[] = {"pos codriver","pos cargo"};
		memoryPointsGetInCargoDir[] = {"pos codriver dir","pos cargo dir"};
		gunnerUsesPilotView=0;
		driverCanSee=31;
		gunnerCanSee=31;
		
		transportSoldier=6;
		transportMaxBackpacks = 15;	

		radarType = 4;
		enableManualFire = false;
		
		// Machine parameters
		maxSpeed = 293;
		accuracy=1.5;
		cost=10000000;
		armor=60;
		damageResistance = 0.00555;
		vehicleClass = "Air";
		laserScanner = true;
		MainRotorSpeed = 0.5; // http://www.youtube.com/watch?v=6s7EXORMHgU
		backRotorSpeed =  3.0;		

		LockDetectionSystem = CM_Lock_Radar  + CM_Lock_Laser;
		IncommingMisslieDetectionSystem = CM_Missile;		

		gunBeg="muzzle_1";
		gunEnd="chamber_1";
		
		memoryPointLMissile = "P strela";
		memoryPointRMissile = "P strela";
		memoryPointGun = "muzzle_1";

		// Guns and equipment
		weapons[] = {"CMFlareLauncher"};
		magazines[] = {"120Rnd_CMFlare_Chaff_Magazine"};
		HeadAimDown = -5.2;

		selectionFireAnim = "zasleh";
		
		threat[]={1, 1, 0.5};
		destrType=DestructWreck;
		
		class TransportBackpacks
		{
			class _xx_B_Parachute
			{
				backpack = "B_Parachute";
				count = 8;
			};
			class _xx_B_Kitbag
			{
				backpack = "B_Kitbag_cbr";
				count = 2;
			};			
		};
		class TransportItems
		{
			class _xx_FirstAidKit
			{
				name = "FirstAidKit";
				count = 10;
			};
			class _xx_Medikit
			{
				name = "Medikit";
				count = 5;
			};
			class _xx_Toolkit
			{
				name = "Toolkit";
				count = 5;
			};			
		};			
		class RenderTargets /// class for all Picture-in-Picture
		{
			class camera
			{
				renderTarget = "rendertarget4";
				class CameraView1
				{
					pointPosition		= "laserstart"; 	/// memory point of PiP origin
					pointDirection		= "commanderview"; 	/// memory point of PiP direction
					renderQuality 		= 4;			/// what quality should the PiP be
					renderVisionMode 	= 2;			/// zero means standard vision
					fov 				= 0.466;			/// what is the angle of the PiP field of view
				}; 	
			};
		};				
		class AnimationSources : AnimationSources
		{
			class CargoDoorR
			{
				source="door";
				animPeriod=1;
				initPhase=0;
				sound = "MetalOldBigDoorsSound";
			};
			class CargoDoorL
			{
				source="door";
				animPeriod=1;
				initPhase=0;
				sound = "MetalOldBigDoorsSound";
			};	
			class CargoDoorR_action : CargoDoorR
			{
				source="user";
			};
			class CargoDoorL_action : CargoDoorL
			{
				source="user";			
			};			
			class HidePIPMFDPILY
			{
				source="user";
				animPeriod=0;
				initPhase=0;
			};
			class HidePIPMFDPILYCO
			{
				source="user";
				animPeriod=0;
				initPhase=0;
			};		
		};
		class UserActions
		{
			class Pimfdpip1ON
			{
				displayName= "<t color='#ffff00'>Turn On FLIR MFD</t>"; //Yellow
				displayNameDefault = "";
				position="";
				radius=3.6;
				onlyForplayer=true;
				condition="this animationPhase ""copip6"" < 0.5 AND (player == (driver this) && (alive this))";
				statement="this animate [""copip6"",1];";
				priority=9;
			}; 	
			class Pimfdpip1OFF
			{
				displayName= "<t color='#ffff00'>Turn Off FLIR MFD</t>"; //Yellow
				displayNameDefault = "";
				position="";
				radius=3.6;
				onlyForplayer=true;
				condition="this animationPhase ""copip6"" > 0.5 AND (player == (driver this) && (alive this))";
				statement="this animate [""copip6"",0];";
				priority=9;
			};
			class PimfdpipON
			{
				displayName= "<t color='#ffff00'>Turn On FLIR MFD</t>"; //Yellow
				displayNameDefault = "";
				position="";
				radius=3.6;
				onlyForplayer=true;
				condition="this animationPhase ""copip4"" < 0.5 AND (player == (gunner this) && (alive this)) ";
				statement="this animate [""copip4"",1];";
				priority=9;
			}; 	
			class PimfdpipOFF
			{
				displayName= "<t color='#ffff00'>Turn Off FLIR MFD</t>"; //Yellow
				displayNameDefault = "";
				position="";
				radius=3.6;
				onlyForplayer=true;
				condition="this animationPhase ""copip4"" > 0.5 AND (player == (gunner this) && (alive this))";
				statement="this animate [""copip4"",0];";
				priority=9;
			}; 	 			
			class OpenRdoor
			{
				displayName= "<t color='#FF0000'>Open Right Door</t>"; //Red
				displayNameDefault 	= "";
				position="door_right_axis_beg";
				radius=3.7;
				onlyForplayer=false;
                priority = 0;					
				condition="this doorPhase ""CargoDoorR"" < 0.5 AND ((_vehicle getCargoIndex player) >= 0 )";
				statement="this animateDoor [""CargoDoorR"",1];";
			};
			class CloseRdoor
			{
				displayName= "<t color='#FF0000'>Close Right Door</t>"; //Red
				displayNameDefault 	= "";
				position="door_right_axis_beg";
				radius=3.7;
				onlyForplayer=false;
                priority = 0;					
				condition="this doorPhase ""CargoDoorR"" > 0.5 AND ((_vehicle getCargoIndex player) >= 0 )";
				statement="this animateDoor [""CargoDoorR"",0];";
			};
			class OpenLdoor
			{
				displayName= "<t color='#FF0000'>Open Left Door</t>"; //Red
				displayNameDefault 	= "";
				position="door_left_axis_beg";
				radius=3.7;
				onlyForplayer=false;
                priority = 0;					
				condition="this doorPhase ""CargoDoorL"" < 0.5 AND ((_vehicle getCargoIndex player) >= 0 )";
				statement="this animateDoor [""CargoDoorL"",1];";
			};
			class CloseLdoor
			{
				displayName= "<t color='#FF0000'>Close Left Door</t>"; //Red
				displayNameDefault 	= "";
				position="door_left_axis_beg";
				radius=3.7;
				onlyForplayer=false; 
                priority = 0;				
				condition="this doorPhase ""CargoDoorL"" > 0.5 AND ((_vehicle getCargoIndex player) >= 0 )";
				statement="this animateDoor [""CargoDoorL"",0];";				
			};
		};				
		class MarkerLights
		{
			class GreenStill 
			{
				name = "light_nav_right";
				color[] = {0.0, 0.8, 0.0};
				ambient[] = {0.0, 0.08, 0.0};
				intensity = 75;
				drawLight = 1;
				drawLightSize = 0.15;
				drawLightCenterSize = 0.04;
				activeLight = 0;
				blinking = 0;
				dayLight = 0;
				useFlare = 0;
			};	
			class RedBlinking 
			{
				name = "light_nav_top";
				color[] = {0.9, 0.15, 0.1};
				ambient[] = {0.09, 0.015, 0.01};
				intensity = 50;
				blinking = 1;
				blinkingPattern[] = {0.1, 0.9};
				blinkingPatternGuarantee = 0;
				drawLightSize = 0.2;
				drawLightCenterSize = 0.04;
			};
			class RedStill 
			{
				name = "light_nav_left";
				color[] = {0.8, 0.0, 0.0};
				ambient[] = {0.08, 0.0, 0.0};
				intensity = 75;
				drawLight = 1;
				drawLightSize = 0.15;
				drawLightCenterSize = 0.04;
				activeLight = 0;
				blinking = 0;
				dayLight = 0;
				useFlare = 0;
			};	
			class WhiteStill 
			{
				name = "light_nav_back";
				color[] = {1.0, 1.0, 1.0};
				ambient[] = {0.1, 0.1, 0.1};
				blinking = 1;
				intensity = 75;
				blinkingPattern[] = {0.1, 0.9};
				blinkingPatternGuarantee = 0;
				drawLightSize = 0.2;
				drawLightCenterSize = 0.04;
			};	
			
		};			
		class pilotCamera				/// camera for pilot to observe sling loading
        {
            class OpticsIn				/// what is seen if player switches to optics
            {		
                class Wide
                {
                    opticsDisplayName 	= "W";	/// used in case the UI has place to display optics mode
                    initAngleX			= 0;	/// X-axis rotation and its limits
					minAngleX			= -0; 	/// X-axis rotation and its limits
					maxAngleX			= +0;	/// X-axis rotation and its limits
                    initAngleY			= 0; 	/// Y-axis rotation and its limits
					minAngleY			= -0;  	/// Y-axis rotation and its limits
					maxAngleY			= +0; 	/// Y-axis rotation and its limits
                    initFov				= 0.5;	/// Field of view size settings
					minFov				= 0.5;	/// Field of view size settings
					maxFov				= 0.5;	/// Field of view size settings
                    visionMode[] 		= {"Normal","NVG", "TI"};	/// what vision modes are available
                    thermalMode[] 		= {0,1};			/// not necessary as there is no TI mode defined, but just in case
                    gunnerOpticsModel = "A3\drones_f\Weapons_F_Gamma\Reticle\UAV_Optics_Gunner_wide_F.p3d"; /// some optics model
				};
				showMiniMapInOptics				= true;	/// allows showing GPS mini map in optics
				showUAVViewpInOptics			= true;	/// allows showing UAV feed in this optics
				showSlingLoadManagerInOptics 	= true;		/// allows displaying of Sling Loading Assistant
            };
            minTurn                 = 0; 		//turn
            maxTurn                 = 0; 		//turn
            initTurn                = 0; 		//turn
            minElev                 = 80; 		//turn
            maxElev                 = 80; 		//turn
            initElev                = 80; 		//turn
            maxXRotSpeed            = 0.5; 		// movement speed
            maxYRotSpeed            = 0.5; 		// movement speed
            pilotOpticsShowCursor   = 1; 		//to show aimCursor (is useful to see plane direction)
            controllable            = false; 	// set false to have static camera, true to have moving like a turret
        };		
	    class CargoTurret;
		class Turrets: Turrets
		{
			class MainTurret: MainTurret //Gunner
			{
				body = "MainTurret";
				gunnerCompartments = "Compartment1";
				gun = "MainGun";
				animationSourceBody = "MainTurret";
				animationSourceGun = "MainGun";
				stabilizedInAxes = 3;
				gunnername = "Co-Pilot";
				isCopilot = 1;			
				memoryPointGunnerOptics= "commanderview";						
				minElev=-40; maxElev=+20; initElev=0;
				minTurn=-120; maxTurn=120; initTurn=0;
				gunBeg="commanderview";
				gunEnd="laserstart";
				memoryPointGun = "laserstart";
				canLock = 2;
				turretInfoType = "RscOptics_UAV_gunner";
				weapons[] = {"Laserdesignator_mounted"};
				magazines[] = {"Laserbatteries"};	
				proxyType = CPGunner;		
				inGunnerMayFire = true;
				gunnerAction = AW159_Pilot_BAF;
				gunnerGetInAction = GetInHigh;
				gunnerGetOutAction = GetOutHigh;
				gunnerOpticsEffect[] = {};
				gunnerOpticsModel = "";
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
		                visionMode[] = {"Normal","NVG", "Ti"};
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
		                visionMode[] = {"Normal","NVG", "Ti"};
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
			       class Monocular // 1x-3.5x
			       {
				       initAngleX=0; minAngleX=-30; maxAngleX=+30;
				       initAngleY=0; minAngleY=-100; maxAngleY=+100;
				       initFov=1.1; minFov=0.133; maxFov=1.1;
				       visionMode[] = {"Normal","NVG"};
				       gunnerOpticsModel = "";
				       gunnerOpticsEffect[] = {};
			       };
		        };
		        startEngine=false;
	            gunnerHasFlares = false;
	        };  	
			class CargoTurret_01: CargoTurret 						/// position for Firing from Vehicles
			{
				gunnerAction 				= "passenger_inside_2";	/// generic animation for sitting inside with rifle ready
				gunnerCompartments 			= "Compartment2";		/// gunner is not able to switch seats
				memoryPointsGetInGunner 	= "pos cargo right";		/// specific memory points to allow choice of position
				memoryPointsGetInGunnerDir 	= "pos cargo dir right";	/// direction of get in action
				gunnerName 					= "Passenger (Right Seat)";	/// name of the position in the Action menu
				proxyIndex 					= 7;					/// what cargo proxy is used according to index in the model
				maxElev 					= 15;					/// what is the highest possible elevation of the turret
				minElev 					= -60;					/// what is the lowest possible elevation of the turret
				maxTurn 					= -23;					/// what is the left-most possible turn of the turret
				minTurn 					= -100;					/// what is the right-most possible turn of the turret
				isPersonTurret 				= 1;					/// enables firing from vehicle functionality
				ejectDeadGunner 			= 0;					/// seatbelts included
				enabledByAnimationSource 	= "CargoDoorR";				/// doesn't work unless the said animation source is 1
				gunnerDoor="CargoDoorR";
				usepip = 0;
				gunnerOutOpticsModel = "";
				gunnerOpticsModel = "";
				startEngine = 0;
	            outGunnerMayFire = 1;
                inGunnerMayFire = 0;
				commanding=-2;
				memoryPointGunnerOptics="";
				LODTurnedIn = 1;
				LODTurnedOut = 1;
			};
			class CargoTurret_02: CargoTurret 						/// position for Firing from Vehicles
			{
				gunnerAction 				= "passenger_inside_2";	/// generic animation for sitting inside with rifle ready
				gunnerCompartments 			= "Compartment2";		/// gunner is not able to switch seats
				memoryPointsGetInGunner 	= "pos cargo left";		/// specific memory points to allow choice of position
				memoryPointsGetInGunnerDir 	= "pos cargo dir left";	/// direction of get in action
				gunnerName 					= "Passenger (Left Seat)";	/// name of the position in the Action menu
				proxyIndex 					= 8;					/// what cargo proxy is used according to index in the model
				maxElev 					= 15;					/// what is the highest possible elevation of the turret
				minElev 					= -60;					/// what is the lowest possible elevation of the turret
				maxTurn 					= 100;					/// what is the left-most possible turn of the turret
				minTurn 					= 23;					/// what is the right-most possible turn of the turret
				isPersonTurret 				= 1;					/// enables firing from vehicle functionality
				ejectDeadGunner 			= 0;					/// seatbelts included
				enabledByAnimationSource 	= "CargoDoorL";				/// doesn't work unless the said animation source is 1
				gunnerDoor="CargoDoorL";
				usepip = 0;
				gunnerOutOpticsModel = "";
				gunnerOpticsModel = "";
				startEngine = 0;
	            outGunnerMayFire = 1;
                inGunnerMayFire = 0;
				commanding=-2;
				memoryPointGunnerOptics="";
				LODTurnedIn = 1;
				LODTurnedOut = 1;				
			};						
		};	
		class HitPoints:HitPoints
		{
			class HitGlass1:HitGlass1 {armor=0.5;};
			class HitGlass2:HitGlass2 {armor=0.5;};
			class HitGlass3:HitGlass3 {armor=0.5;};
			class HitGlass4:HitGlass4 {armor=0.5;};
			class HitGlass5:HitGlass5 {armor=0.5;};
			class HitEngine {armor=0.5;material=51;name="motor";visual="motor";passThrough=0.5;};
			class HitAvionics {armor=0.15;material=51;name="elektronika";visual="elektronika";passThrough=0.2;};			
			class HitVRotor {armor=0.3;material=51;name="mala vrtule";visual="mala vrtule staticka";passThrough=0.1;};
			class HitHRotor {armor=0.2;material=51;name="velka vrtule";visual="velka vrtule staticka";passThrough=0.1;};			
			class HitGlass6 {armor=0.5;material=-1;name="glass6";visual="glass6";passThrough=0;};
			class HitGlass7 {armor=0.5;material=-1;name="glass7";visual="glass7";passThrough=0;};
			class HitGlass8 {armor=0.5;material=-1;name="glass8";visual="glass8";passThrough=0;};
			class HitGlass9 {armor=0.5;material=-1;name="glass9";visual="glass9";passThrough=0;};
			class HitGlass10{armor=0.5;material=-1;name="glass10";visual="glass10";passThrough=0;};
			class HitGlass11{armor=0.5;material=-1;name="glass11";visual="glass11";passThrough=0;};			
		};
		class Reflectors
		{
			class Right
			{
				color[] = {7000,7500,10000};
				ambient[] = {70,75,100};
				intensity = 50;
				size = 1;
				innerAngle = 20;				/// angle from light direction vector where the light is at full strength
				outerAngle = 135;				/// angle from light direction vector where the light is completely faded out
				coneFadeCoef = 10;				/// coefficient of fading the light between inner and outer cone angles
				position = "laserstart";
				direction = "commanderview";
				hitpoint = "glass11";
				selection = "glass11";
				useFlare = 1;
				dayLight = 0;
				FlareSize = 15;
				class Attenuation
				{
					start = 0;
					constant = 0;
					linear = 1;
					quadratic = 0;
					hardLimitStart = 200;
					hardLimitEnd = 250;
				};
			};
		};
		class Exhausts
		{
			class Exhaust1
			{
				position = "exhaust1";
				direction = "exhaust1_dir";
				effect = "ExhaustEffectHeli";
			};
			class Exhaust2
			{
				position = "exhaust2";
				direction = "exhaust2_dir";
				effect = "ExhaustEffectHeli";
			};
		};
		// materials
		class Damage
		{
			tex[]={};
			mat[]={
			"DEGA_Wildcats\data\Lynx_base.rvmat",
			"DEGA_Wildcats\data\Lynx_base_damage.rvmat",
			"DEGA_Wildcats\data\Lynx_base_destruct.rvmat",
			
			"DEGA_Wildcats\data\Lynx_glass.rvmat",
			"DEGA_Wildcats\data\Lynx_glass_damage.rvmat",
			"DEGA_Wildcats\data\Lynx_glass_damage.rvmat",
			
			"DEGA_Wildcats\data\Lynx_interior.rvmat",
			"DEGA_Wildcats\data\Lynx_interior_damage.rvmat",
			"DEGA_Wildcats\data\Lynx_interior_destruct.rvmat"
			};
		};
		attenuationEffectType="OpenHeliAttenuation";
		emptySound[]=
		{
			"",
			0,
			1
		};
		soundGeneralCollision1[]=
		{
			"A3\Sounds_F\vehicles\crashes\helis\Heli_coll_default_int_1",
			1,
			1,
			100
		};
		soundGeneralCollision2[]=
		{
			"A3\Sounds_F\vehicles\crashes\helis\Heli_coll_default_int_2",
			1,
			1,
			100
		};
		soundGeneralCollision3[]=
		{
			"A3\Sounds_F\vehicles\crashes\helis\Heli_coll_default_int_3",
			1,
			1,
			100
		};
		soundCrashes[]=
		{
			"soundGeneralCollision1",
			0.33000001,
			"soundGeneralCollision2",
			0.33000001,
			"soundGeneralCollision3",
			0.33000001
		};
		soundLandCrashes[]=
		{
			"emptySound",
			0
		};
		soundBuildingCrash[]=
		{
			"soundGeneralCollision1",
			1,
			"soundGeneralCollision2",
			1,
			"soundGeneralCollision3",
			1
		};
		soundArmorCrash[]=
		{
			"soundGeneralCollision1",
			1,
			"soundGeneralCollision2",
			1,
			"soundGeneralCollision3",
			1
		};
		soundWoodCrash[]=
		{
			"soundGeneralCollision1",
			1,
			"soundGeneralCollision2",
			1,
			"soundGeneralCollision3",
			1
		};
		soundBushCollision1[]=
		{
			"A3\Sounds_F\vehicles\crashes\helis\Heli_coll_bush_int_1",
			1,
			1,
			100
		};
		soundBushCollision2[]=
		{
			"A3\Sounds_F\vehicles\crashes\helis\Heli_coll_bush_int_2",
			1,
			1,
			100
		};
		soundBushCollision3[]=
		{
			"A3\Sounds_F\vehicles\crashes\helis\Heli_coll_bush_int_3",
			1,
			1,
			100
		};
		soundBushCrash[]=
		{
			"soundBushCollision1",
			0.33000001,
			"soundBushCollision2",
			0.33000001,
			"soundBushCollision3",
			0.33000001
		};
		soundWaterCollision1[]=
		{
			"A3\Sounds_F\vehicles\crashes\helis\Heli_coll_water_ext_1",
			1,
			1,
			100
		};
		soundWaterCollision2[]=
		{
			"A3\Sounds_F\vehicles\crashes\helis\Heli_coll_water_ext_2",
			1,
			1,
			100
		};
		soundWaterCrashes[]=
		{
			"soundWaterCollision1",
			0.5,
			"soundWaterCollision2",
			0.5
		};
		soundDammage[]=
		{
			"A3\Sounds_F\vehicles\crashes\helis\Heli_crash_default_int_1",
			10,
			1
		};
		soundGetIn[]=
		{
			"A3\Sounds_F\vehicles\air\Heli_Light_03\open",
			1,
			1
		};
		soundGetOut[]=
		{
			"A3\Sounds_F\vehicles\air\Heli_Light_03\close",
			1,
			1,
			50
		};
		soundEngineOnInt[]=
		{
			"A3\Sounds_F\vehicles\air\Heli_Light_03\heli_start_int",
			0.39810717,
			1
		};
		soundEngineOnExt[]=
		{
			"A3\Sounds_F\vehicles\air\Heli_Light_03\heli_start_ext",
			2.5118864,
			1,
			600
		};
		soundEngineOffInt[]=
		{
			"A3\Sounds_F\vehicles\air\Heli_Light_03\heli_stop_int",
			0.39810717,
			1
		};
		soundEngineOffExt[]=
		{
			"A3\Sounds_F\vehicles\air\Heli_Light_03\heli_stop_ext",
			2.5118864,
			1,
			600
		};
		soundLocked[]=
		{
			"\A3\Sounds_F\weapons\Rockets\locked_1",
			1,
			1
		};
		soundIncommingMissile[]=
		{
			"\A3\Sounds_F\weapons\Rockets\locked_3",
			1,
			1.5
		};
		rotorDamageInt[]=
		{
			"A3\Sounds_F\vehicles\air\noises\heli_damage_rotor_int_open_1",
			1,
			1
		};
		rotorDamageOut[]=
		{
			"A3\Sounds_F\vehicles\air\noises\heli_damage_rotor_ext_1",
			2.5118864,
			1,
			150
		};
		rotorDamage[]=
		{
			"rotorDamageInt",
			"rotorDamageOut"
		};
		tailDamageInt[]=
		{
			"A3\Sounds_F\vehicles\air\noises\heli_damage_tail",
			1,
			1
		};
		tailDamageOut[]=
		{
			"A3\Sounds_F\vehicles\air\noises\heli_damage_tail",
			1,
			1,
			300
		};
		tailDamage[]=
		{
			"tailDamageInt",
			"tailDamageOut"
		};
		landingSoundInt0[]=
		{
			"A3\Sounds_F\vehicles\air\noises\landing_wheels_small_int1",
			1,
			1,
			100
		};
		landingSoundInt1[]=
		{
			"A3\Sounds_F\vehicles\air\noises\landing_wheels_small_int2",
			1,
			1,
			100
		};
		landingSoundInt[]=
		{
			"landingSoundInt0",
			0.5,
			"landingSoundInt1",
			0.5
		};
		landingSoundOut0[]=
		{
			"A3\Sounds_F\vehicles\air\noises\landing_wheels_ext1",
			1.7782794,
			1,
			100
		};
		landingSoundOut1[]=
		{
			"A3\Sounds_F\vehicles\air\noises\landing_wheels_ext2",
			1.7782794,
			1,
			100
		};
		landingSoundOut[]=
		{
			"landingSoundOut0",
			0.5,
			"landingSoundOut1",
			0.5
		};
		slingCargoAttach0[]=
		{
			"A3\Sounds_F\vehicles\air\noises\SL_engineUpEndINT",
			1,
			1
		};
		slingCargoAttach1[]=
		{
			"A3\Sounds_F\vehicles\air\noises\SL_1hookLock",
			1,
			1,
			80
		};
		slingCargoAttach[]=
		{
			"slingCargoAttach0",
			"slingCargoAttach1"
		};
		slingCargoDetach0[]=
		{
			"A3\Sounds_F\dummysound",
			1,
			1
		};
		slingCargoDetach1[]=
		{
			"A3\Sounds_F\vehicles\air\noises\SL_1hookUnlock",
			1,
			1,
			80
		};
		slingCargoDetach[]=
		{
			"slingCargoDetach0",
			"slingCargoDetach1"
		};
		slingCargoDetachAir0[]=
		{
			"A3\Sounds_F\vehicles\air\noises\SL_unhook_air_int",
			1,
			1
		};
		slingCargoDetachAir1[]=
		{
			"A3\Sounds_F\vehicles\air\noises\SL_unhook_air_ext",
			1,
			1,
			80
		};
		slingCargoDetachAir[]=
		{
			"slingCargoDetach0",
			"slingCargoDetach1"
		};
		slingCargoRopeBreak0[]=
		{
			"A3\Sounds_F\vehicles\air\noises\SL_rope_break_int",
			1,
			1
		};
		slingCargoRopeBreak1[]=
		{
			"A3\Sounds_F\vehicles\air\noises\SL_rope_break_ext",
			1,
			1,
			80
		};
		slingCargoRopeBreak[]=
		{
			"slingCargoDetach0",
			"slingCargoDetach1"
		};
		gearUpExt[]=
		{
			"A3\Sounds_F\vehicles\air\Heli_Transport_01\gear_up_OUT",
			1,
			1,
			1000
		};
		gearUpInt[]=
		{
			"A3\Sounds_F\vehicles\air\Heli_Transport_01\gear_up_IN",
			1,
			1,
			100
		};
		gearUp[]=
		{
			"gearUpInt",
			"gearUpExt"
		};
		gearDownInt[]=
		{
			"A3\Sounds_F\vehicles\air\Heli_Transport_01\gear_down_IN",
			1,
			1,
			100
		};
		gearDownExt[]=
		{
			"A3\Sounds_F\vehicles\air\Heli_Transport_01\gear_down_OUT",
			1,
			1,
			1000
		};
		gearDown[]=
		{
			"gearDownInt",
			"gearDownExt"
		};
		class Sounds
		{
			class EngineExt
			{
				sound[]=
				{
					"A3\Sounds_F\vehicles\air\Heli_Light_03\heli_engine_ext",
					1.7782794,
					1,
					700
				};
				frequency="rotorSpeed";
				volume="camPos*((rotorSpeed-0.72)*4)";
			};
			class RotorExt
			{
				sound[]=
				{
					"A3\Sounds_F\vehicles\air\Heli_Light_03\heli_rotor_ext",
					1.4125376,
					1,
					1100
				};
				frequency="rotorSpeed * (1-rotorThrust/5)";
				volume="camPos*(0 max (rotorSpeed-0.1))*(1 + rotorThrust)";
			};
			class RotorNoiseExt
			{
				sound[]=
				{
					"A3\Sounds_F\vehicles\air\Heli_Light_03\rotor_swist",
					1,
					1,
					300
				};
				frequency=1;
				volume="camPos * (rotorThrust factor [0.7, 0.9])";
				cone[]={0.69999999,1.3,1,0};
			};
			class EngineInt
			{
				sound[]=
				{
					"A3\Sounds_F\vehicles\air\Heli_Light_03\heli_engine_int",
					1,
					1
				};
				frequency="rotorSpeed";
				volume="(1-camPos)*((rotorSpeed-0.75)*4)";
			};
			class RotorInt
			{
				sound[]=
				{
					"A3\Sounds_F\vehicles\air\Heli_Light_03\heli_rotor_int",
					1.7782794,
					1
				};
				frequency="rotorSpeed * (1-rotorThrust/5)";
				volume="(1-camPos)*(0 max (rotorSpeed*rotorSpeed-0.1))*(1 + rotorThrust)";
			};
			class TransmissionDamageExt_phase1
			{
				sound[]=
				{
					"A3\Sounds_F\vehicles\air\noises\heli_damage_transmission_ext_1",
					1,
					1,
					150
				};
				frequency="0.66 + rotorSpeed / 3";
				volume="camPos * (transmissionDamage factor [0.3, 0.35]) * (transmissionDamage factor [0.5, 0.45]) * (rotorSpeed factor [0.2, 0.5])";
			};
			class TransmissionDamageExt_phase2
			{
				sound[]=
				{
					"A3\Sounds_F\vehicles\air\noises\heli_damage_transmission_ext_2",
					1,
					1,
					150
				};
				frequency="0.66 + rotorSpeed / 3";
				volume="camPos * (transmissionDamage factor [0.45, 0.5]) * (rotorSpeed factor [0.2, 0.5])";
			};
			class TransmissionDamageInt_phase1
			{
				sound[]=
				{
					"A3\Sounds_F\vehicles\air\noises\heli_damage_transmission_int_1",
					1,
					1,
					150
				};
				frequency="0.66 + rotorSpeed / 3";
				volume="(1 - camPos) * (transmissionDamage factor [0.3, 0.35]) * (transmissionDamage factor [0.5, 0.45]) * (rotorSpeed factor [0.2, 0.5])";
			};
			class TransmissionDamageInt_phase2
			{
				sound[]=
				{
					"A3\Sounds_F\vehicles\air\noises\heli_damage_transmission_int_2",
					1,
					1,
					150
				};
				frequency="0.66 + rotorSpeed / 3";
				volume="(1 - camPos) * (transmissionDamage factor [0.45, 0.5]) * (rotorSpeed factor [0.2, 0.5])";
			};
			class damageAlarmInt
			{
				sound[]=
				{
					"A3\Sounds_F\vehicles\air\noises\heli_alarm_opfor",
					0.31622776,
					1
				};
				frequency=1;
				volume="engineOn * (1 - camPos) * ( 1 - ((transmissionDamage factor [0.61, 0.60]) * (motorDamage factor [0.61, 0.60]) * (rotorDamage factor [0.51, 0.50]))) * (rotorSpeed factor [0.0, 0.001])";
			};
			class damageAlarmExt
			{
				sound[]=
				{
					"A3\Sounds_F\vehicles\air\noises\heli_alarm_opfor",
					0.2238721,
					1,
					20
				};
				frequency=1;
				volume="engineOn * camPos * ( 1 - ((transmissionDamage factor [0.61, 0.60]) * (motorDamage factor [0.61, 0.60]) * (rotorDamage factor [0.51, 0.50]))) * (rotorSpeed factor [0, 0.001])";
			};
			class rotorLowAlarmInt
			{
				sound[]=
				{
					"A3\Sounds_F\vehicles\air\noises\heli_alarm_rotor_low",
					0.31622776,
					1
				};
				frequency=1;
				volume="engineOn * (1 - camPos) * (rotorSpeed factor [0.9, 0.8999]) * (rotorSpeed factor [-0.5, 1]) * (speed factor [3, 3.01])";
			};
			class rotorLowAlarmExt
			{
				sound[]=
				{
					"A3\Sounds_F\vehicles\air\noises\heli_alarm_rotor_low",
					0.2238721,
					1,
					20
				};
				frequency=1;
				volume="engineOn * camPos * (rotorSpeed factor [0.9, 0.8999]) * (rotorSpeed factor [-0.5, 1]) * (speed factor [3, 3.01])";
			};
			class scrubLandInt
			{
				sound[]=
				{
					"A3\Sounds_F\vehicles\air\noises\scrubLandInt_open",
					1,
					1,
					100
				};
				frequency=1;
				volume="2 * (1-camPos) * (scrubLand factor[0.02, 0.05])";
			};
			class scrubLandExt
			{
				sound[]=
				{
					"A3\Sounds_F\vehicles\air\noises\scrubLandExt",
					1,
					1,
					100
				};
				frequency=1;
				volume="camPos * (scrubLand factor[0.02, 0.05])";
			};
			class scrubBuildingInt
			{
				sound[]=
				{
					"A3\Sounds_F\vehicles\air\noises\scrubBuildingInt",
					1,
					1,
					100
				};
				frequency=1;
				volume="2 * (1 - camPos) * (scrubBuilding factor[0.02, 0.05])";
			};
			class scrubBuildingExt
			{
				sound[]=
				{
					"A3\Sounds_F\vehicles\air\noises\scrubBuildingExt",
					1,
					1,
					100
				};
				frequency=1;
				volume="camPos * (scrubBuilding factor[0.02, 0.05])";
			};
			class scrubTreeInt
			{
				sound[]=
				{
					"A3\Sounds_F\vehicles\air\noises\scrubTreeExt",
					1,
					1,
					100
				};
				frequency=1;
				volume="(1 - camPos) * ((scrubTree) factor [0, 0.01])";
			};
			class scrubTreeExt
			{
				sound[]=
				{
					"A3\Sounds_F\vehicles\air\noises\scrubTreeExt",
					1,
					1,
					100
				};
				frequency=1;
				volume="camPos * ((scrubTree) factor [0, 0.01])";
			};
			class RainExt
			{
				sound[]=
				{
					"A3\Sounds_F\vehicles\noises\rain1_ext",
					1,
					1,
					100
				};
				frequency=1;
				volume="camPos * (rain - rotorSpeed/2) * 2";
			};
			class RainInt
			{
				sound[]=
				{
					"A3\Sounds_F\vehicles\noises\rain1_int",
					1,
					1,
					100
				};
				frequency=1;
				volume="(1-camPos)*(rain - rotorSpeed/2)*2";
			};
			class SlingLoadDownExt
			{
				sound[]=
				{
					"A3\Sounds_F\vehicles\air\noises\SL_engineDownEXT",
					1,
					1,
					500
				};
				frequency=1;
				volume="camPos*(slingLoadActive factor [0,-1])";
			};
			class SlingLoadUpExt
			{
				sound[]=
				{
					"A3\Sounds_F\vehicles\air\noises\SL_engineUpEXT",
					1,
					1,
					500
				};
				frequency=1;
				volume="camPos*(slingLoadActive factor [0,1])";
			};
			class SlingLoadDownInt
			{
				sound[]=
				{
					"A3\Sounds_F\vehicles\air\noises\SL_engineDownINT",
					1,
					1,
					500
				};
				frequency=1;
				volume="(1-camPos)*(slingLoadActive factor [0,-1])";
			};
			class SlingLoadUpInt
			{
				sound[]=
				{
					"A3\Sounds_F\vehicles\air\noises\SL_engineUpINT",
					1,
					1,
					500
				};
				frequency=1;
				volume="(1-camPos)*(slingLoadActive factor [0,1])";
			};
			class WindInt
			{
				sound[]=
				{
					"A3\Sounds_F\vehicles\air\noises\wind_open_int",
					0.56234133,
					1,
					50
				};
				frequency=1;
				volume="(1-camPos)*(speed factor[5, 50])*(speed factor[5, 50])";
			};
			class GStress
			{
				sound[]=
				{
					"A3\Sounds_F\vehicles\noises\vehicle_stress2b",
					0.35481337,
					1,
					50
				};
				frequency=1;
				volume="engineOn * (1-camPos) * ((gmeterZ factor[1.5, 2.5]) + (gmeterZ factor[0.5, -0.5]))";
			};
		};
		class SoundsExt
		{
			class SoundEvents
			{
			};
			class Sounds
			{
				class EngineExt
				{
					sound[]=
					{
						"A3\Sounds_F\vehicles\air\Heli_Light_03\heli_engine_ext",
						1.7782794,
						1,
						700
					};
					frequency="rotorSpeed";
					volume="camPos*((rotorSpeed-0.72)*4)";
				};
				class RotorExt
				{
					sound[]=
					{
						"A3\Sounds_F\vehicles\air\Heli_Light_03\heli_rotor_ext",
						1.4125376,
						1,
						1100
					};
					frequency="rotorSpeed * (1-rotorThrust/5)";
					volume="camPos*(0 max (rotorSpeed-0.1))*(1 + rotorThrust)";
				};
				class RotorNoiseExt
				{
					sound[]=
					{
						"A3\Sounds_F\vehicles\air\Heli_Light_03\rotor_swist",
						1,
						1,
						300
					};
					frequency=1;
					volume="camPos * (rotorThrust factor [0.7, 0.9])";
					cone[]={0.69999999,1.3,1,0};
				};
				class EngineInt
				{
					sound[]=
					{
						"A3\Sounds_F\vehicles\air\Heli_Light_03\heli_engine_int",
						1,
						1
					};
					frequency="rotorSpeed";
					volume="(1-camPos)*((rotorSpeed-0.75)*4)";
				};
				class RotorInt
				{
					sound[]=
					{
						"A3\Sounds_F\vehicles\air\Heli_Light_03\heli_rotor_int",
						1.7782794,
						1
					};
					frequency="rotorSpeed * (1-rotorThrust/5)";
					volume="(1-camPos)*(0 max (rotorSpeed*rotorSpeed-0.1))*(1 + rotorThrust)";
				};
				class TransmissionDamageExt_phase1
				{
					sound[]=
					{
						"A3\Sounds_F\vehicles\air\noises\heli_damage_transmission_ext_1",
						1,
						1,
						150
					};
					frequency="0.66 + rotorSpeed / 3";
					volume="camPos * (transmissionDamage factor [0.3, 0.35]) * (transmissionDamage factor [0.5, 0.45]) * (rotorSpeed factor [0.2, 0.5])";
				};
				class TransmissionDamageExt_phase2
				{
					sound[]=
					{
						"A3\Sounds_F\vehicles\air\noises\heli_damage_transmission_ext_2",
						1,
						1,
						150
					};
					frequency="0.66 + rotorSpeed / 3";
					volume="camPos * (transmissionDamage factor [0.45, 0.5]) * (rotorSpeed factor [0.2, 0.5])";
				};
				class TransmissionDamageInt_phase1
				{
					sound[]=
					{
						"A3\Sounds_F\vehicles\air\noises\heli_damage_transmission_int_1",
						1,
						1,
						150
					};
					frequency="0.66 + rotorSpeed / 3";
					volume="(1 - camPos) * (transmissionDamage factor [0.3, 0.35]) * (transmissionDamage factor [0.5, 0.45]) * (rotorSpeed factor [0.2, 0.5])";
				};
				class TransmissionDamageInt_phase2
				{
					sound[]=
					{
						"A3\Sounds_F\vehicles\air\noises\heli_damage_transmission_int_2",
						1,
						1,
						150
					};
					frequency="0.66 + rotorSpeed / 3";
					volume="(1 - camPos) * (transmissionDamage factor [0.45, 0.5]) * (rotorSpeed factor [0.2, 0.5])";
				};
				class damageAlarmInt
				{
					sound[]=
					{
						"A3\Sounds_F\vehicles\air\noises\heli_alarm_opfor",
						0.31622776,
						1
					};
					frequency=1;
					volume="engineOn * (1 - camPos) * ( 1 - ((transmissionDamage factor [0.61, 0.60]) * (motorDamage factor [0.61, 0.60]) * (rotorDamage factor [0.51, 0.50]))) * (rotorSpeed factor [0.0, 0.001])";
				};
				class damageAlarmExt
				{
					sound[]=
					{
						"A3\Sounds_F\vehicles\air\noises\heli_alarm_opfor",
						0.2238721,
						1,
						20
					};
					frequency=1;
					volume="engineOn * camPos * ( 1 - ((transmissionDamage factor [0.61, 0.60]) * (motorDamage factor [0.61, 0.60]) * (rotorDamage factor [0.51, 0.50]))) * (rotorSpeed factor [0, 0.001])";
				};
				class rotorLowAlarmInt
				{
					sound[]=
					{
						"A3\Sounds_F\vehicles\air\noises\heli_alarm_rotor_low",
						0.31622776,
						1
					};
					frequency=1;
					volume="engineOn * (1 - camPos) * (rotorSpeed factor [0.9, 0.8999]) * (rotorSpeed factor [-0.5, 1]) * (speed factor [3, 3.01])";
				};
				class rotorLowAlarmExt
				{
					sound[]=
					{
						"A3\Sounds_F\vehicles\air\noises\heli_alarm_rotor_low",
						0.2238721,
						1,
						20
					};
					frequency=1;
					volume="engineOn * camPos * (rotorSpeed factor [0.9, 0.8999]) * (rotorSpeed factor [-0.5, 1]) * (speed factor [3, 3.01])";
				};
				class scrubLandInt
				{
					sound[]=
					{
						"A3\Sounds_F\vehicles\air\noises\scrubLandInt_open",
						1,
						1,
						100
					};
					frequency=1;
					volume="2 * (1-camPos) * (scrubLand factor[0.02, 0.05])";
				};
				class scrubLandExt
				{
					sound[]=
					{
						"A3\Sounds_F\vehicles\air\noises\scrubLandExt",
						1,
						1,
						100
					};
					frequency=1;
					volume="camPos * (scrubLand factor[0.02, 0.05])";
				};
				class scrubBuildingInt
				{
					sound[]=
					{
						"A3\Sounds_F\vehicles\air\noises\scrubBuildingInt",
						1,
						1,
						100
					};
					frequency=1;
					volume="2 * (1 - camPos) * (scrubBuilding factor[0.02, 0.05])";
				};
				class scrubBuildingExt
				{
					sound[]=
					{
						"A3\Sounds_F\vehicles\air\noises\scrubBuildingExt",
						1,
						1,
						100
					};
					frequency=1;
					volume="camPos * (scrubBuilding factor[0.02, 0.05])";
				};
				class scrubTreeInt
				{
					sound[]=
					{
						"A3\Sounds_F\vehicles\air\noises\scrubTreeExt",
						1,
						1,
						100
					};
					frequency=1;
					volume="(1 - camPos) * ((scrubTree) factor [0, 0.01])";
				};
				class scrubTreeExt
				{
					sound[]=
					{
						"A3\Sounds_F\vehicles\air\noises\scrubTreeExt",
						1,
						1,
						100
					};
					frequency=1;
					volume="camPos * ((scrubTree) factor [0, 0.01])";
				};
				class RainExt
				{
					sound[]=
					{
						"A3\Sounds_F\vehicles\noises\rain1_ext",
						1,
						1,
						100
					};
					frequency=1;
					volume="camPos * (rain - rotorSpeed/2) * 2";
				};
				class RainInt
				{
					sound[]=
					{
						"A3\Sounds_F\vehicles\noises\rain1_int",
						1,
						1,
						100
					};
					frequency=1;
					volume="(1-camPos)*(rain - rotorSpeed/2)*2";
				};
				class SlingLoadDownExt
				{
					sound[]=
					{
						"A3\Sounds_F\vehicles\air\noises\SL_engineDownEXT",
						1,
						1,
						500
					};
					frequency=1;
					volume="camPos*(slingLoadActive factor [0,-1])";
				};
				class SlingLoadUpExt
				{
					sound[]=
					{
						"A3\Sounds_F\vehicles\air\noises\SL_engineUpEXT",
						1,
						1,
						500
					};
					frequency=1;
					volume="camPos*(slingLoadActive factor [0,1])";
				};
				class SlingLoadDownInt
				{
					sound[]=
					{
						"A3\Sounds_F\vehicles\air\noises\SL_engineDownINT",
						1,
						1,
						500
					};
					frequency=1;
					volume="(1-camPos)*(slingLoadActive factor [0,-1])";
				};
				class SlingLoadUpInt
				{
					sound[]=
					{
						"A3\Sounds_F\vehicles\air\noises\SL_engineUpINT",
						1,
						1,
						500
					};
					frequency=1;
					volume="(1-camPos)*(slingLoadActive factor [0,1])";
				};
				class WindInt
				{
					sound[]=
					{
						"A3\Sounds_F\vehicles\air\noises\wind_open_int",
						0.56234133,
						1,
						50
					};
					frequency=1;
					volume="(1-camPos)*(speed factor[5, 50])*(speed factor[5, 50])";
				};
				class GStress
				{
					sound[]=
					{
						"A3\Sounds_F\vehicles\noises\vehicle_stress2b",
						0.35481337,
						1,
						50
					};
					frequency=1;
					volume="engineOn * (1-camPos) * ((gmeterZ factor[1.5, 2.5]) + (gmeterZ factor[0.5, -0.5]))";
				};
			};
		};		
	};
///	
/// NATO	
///		
////////////////////////////////////////////////////////////////////////////////
/////////////////////////////AW159 BAF Wildcat Unarmed//////////////////////////
////////////////////////////////////////////////////////////////////////////////	
	class DEGA_Wildcat_Unarmed_BAF: DEGA_Wildcat_Base
	{
	    author = "Deltagamer";
        scope = 2;	
		displayname = AW159 BAF Wildcat (Unarmed);
		hiddenSelections[] = {"camo1", "camo2"};
		model = "\DEGA_Wildcats\AW159_BAF_unarmed";
		picture = "\DEGA_Wildcats\data\UI\picture_lynx_unarmed_ca.paa";
		icon = "\DEGA_Wildcats\data\UI\icon_lynx_unarmed_ca.paa";		
        hiddenSelectionsTextures[]={"\DEGA_Wildcats\data\lynx_base_co.paa", "\DEGA_Wildcats\data\ah64d_details_co.paa"};
		_generalMacro = "DEGA_Wildcat_Unarmed_BAF";			
		class Turrets: Turrets
		{
			class MainTurret: MainTurret {};
			class CargoTurret_01: CargoTurret_01 {};
			class CargoTurret_02: CargoTurret_02 {};						
		};
	};	
////////////////////////////////////////////////////////////////////////////////
/////////////////////////AW159 BAF Wildcat Hellfire Armed///////////////////////
////////////////////////////////////////////////////////////////////////////////	
	class DEGA_Wildcat_Hellfire_Armed_BAF: DEGA_Wildcat_Base
	{
	    author = "Deltagamer";
        scope = 2;	
		displayname = AW159 BAF Wildcat (Hellfire - Armed);
		model = "\DEGA_Wildcats\AW159_BAF_Hellfire_armed";
		picture = "\DEGA_Wildcats\data\UI\picture_lynx_ca.paa";
		icon = "\DEGA_Wildcats\data\UI\icon_lynx_ca.paa";
		#include "\DEGA_Wildcats\Kimi\cfg_HMD_Lynx_Armed_Metric.hpp"
		_generalMacro = "DEGA_Wildcat_Hellfire_Armed_BAF";
		memoryPointLMissile = "missile_1";
 		memoryPointRMissile = "missile_2";			
		hiddenSelections[] = {"camo1", "camo2"};
        hiddenSelectionsTextures[]={"\DEGA_Wildcats\data\lynx_base_co.paa", "\DEGA_Wildcats\data\ah64d_details_co.paa"};			
		class Turrets: Turrets
		{
			class MainTurret: MainTurret //Gunner
			{
				weapons[] = {"Master_Arm_Safe_US_Helos_Kimi",  "Laserdesignator_mounted", "HellfireLauncherN", "HellfireLauncherL"};
				magazines[] = {"Laserbatteries", "4Rnd_Hellfire_N", "4Rnd_Hellfire_L"};	
	        };  	
	        class CargoTurret_01: CargoTurret_01 {};
	        class CargoTurret_02: CargoTurret_02 {};
		};
	};
////////////////////////////////////////////////////////////////////////////////
//////////////////////////AW159 BAF Wildcat Cannon Armed////////////////////////
////////////////////////////////////////////////////////////////////////////////	
	class DEGA_Wildcat_Cannon_Armed_BAF: DEGA_Wildcat_Base
	{
	    author = "Deltagamer";
        scope = 2;	
		displayname = AW159 BAF Wildcat (Cannon - Armed);
		model = "\DEGA_Wildcats\AW159_BAF_Cannon_armed";
		picture = "\DEGA_Wildcats\data\UI\picture_lynx_ca.paa";
		icon = "\DEGA_Wildcats\data\UI\icon_lynx_ca.paa";
		#include "\DEGA_Wildcats\Kimi\cfg_HMD_Lynx_Armed_Metric.hpp"
		_generalMacro = "DEGA_Wildcat_Cannon_Armed_BAF";	
        selectionFireAnim = "zasleh";		
		hiddenSelections[] = {"camo1", "camo2"};
        hiddenSelectionsTextures[]={"\DEGA_Wildcats\data\lynx_base_co.paa", "\DEGA_Wildcats\data\ah64d_details_co.paa"};
		class AnimationSources : AnimationSources
		{
			class ReloadMGAnim{source="reload";weapon="M621";};
        };
		weapons[] = {"Master_Arm_Safe_US_Helos_Kimi", "M621", "CRV7_PG_12rnd", "CMFlareLauncher"};
		magazines[] = {"1200Rnd_20mm_M621", "12Rnd_CRV7", "120Rnd_CMFlare_Chaff_Magazine"};		
		class Turrets: Turrets
		{
			class MainTurret: MainTurret {};  	
	        class CargoTurret_01: CargoTurret_01 {};
	        class CargoTurret_02: CargoTurret_02 {};
		};
	};			
////////////////////////////////////////////////////////////////////////////////
/////////////////////////////AW159 RDAF Wildcat Unarmed/////////////////////////
////////////////////////////////////////////////////////////////////////////////	
	class DEGA_Wildcat_Unarmed_RDAF: DEGA_Wildcat_Base
	{
	    author = "Deltagamer";
        scope = 2;	
		displayname = AW159 RDAF Wildcat (Unarmed);
		hiddenSelections[] = {"camo1", "camo2"};
		model = "\DEGA_Wildcats\AW159_BAF_unarmed";
		picture = "\DEGA_Wildcats\data\UI\picture_lynx_unarmed_ca.paa";
		icon = "\DEGA_Wildcats\data\UI\icon_lynx_unarmed_ca.paa";		
        hiddenSelectionsTextures[]={"\DEGA_Wildcats\Skins\lynx_base_rdaf_co.paa", "\DEGA_Wildcats\data\ah64d_details_co.paa"};
		_generalMacro = "DEGA_Wildcat_Unarmed_RDAF";			
		class Turrets: Turrets
		{
			class MainTurret: MainTurret {};
			class CargoTurret_01: CargoTurret_01 {};
			class CargoTurret_02: CargoTurret_02 {};						
		};
	};	
////////////////////////////////////////////////////////////////////////////////
/////////////////////////AW159 RDAF Wildcat Hellfire Armed//////////////////////
////////////////////////////////////////////////////////////////////////////////	
	class DEGA_Wildcat_Hellfire_Armed_RDAF: DEGA_Wildcat_Base
	{
	    author = "Deltagamer";
        scope = 2;	
		displayname = AW159 RDAF Wildcat (Hellfire - Armed);
		model = "\DEGA_Wildcats\AW159_BAF_Hellfire_armed";
		picture = "\DEGA_Wildcats\data\UI\picture_lynx_ca.paa";
		icon = "\DEGA_Wildcats\data\UI\icon_lynx_ca.paa";
		#include "\DEGA_Wildcats\Kimi\cfg_HMD_Lynx_Armed_Metric.hpp"
		_generalMacro = "DEGA_Wildcat_Hellfire_Armed_RDAF";
		memoryPointLMissile = "missile_1";
 		memoryPointRMissile = "missile_2";			
		hiddenSelections[] = {"camo1", "camo2"};
        hiddenSelectionsTextures[]={"\DEGA_Wildcats\Skins\lynx_base_rdaf_co.paa", "\DEGA_Wildcats\data\ah64d_details_co.paa"};			
		class Turrets: Turrets
		{
			class MainTurret: MainTurret //Gunner
			{
				weapons[] = {"Master_Arm_Safe_US_Helos_Kimi",  "Laserdesignator_mounted", "HellfireLauncherN", "HellfireLauncherL"};
				magazines[] = {"Laserbatteries", "4Rnd_Hellfire_N", "4Rnd_Hellfire_L"};	
	        };  	
	        class CargoTurret_01: CargoTurret_01 {};
	        class CargoTurret_02: CargoTurret_02 {};
		};
	};
////////////////////////////////////////////////////////////////////////////////
//////////////////////////AW159 RDAF Wildcat Cannon Armed///////////////////////
////////////////////////////////////////////////////////////////////////////////	
	class DEGA_Wildcat_Cannon_Armed_RDAF: DEGA_Wildcat_Base
	{
	    author = "Deltagamer";
        scope = 2;	
		displayname = AW159 RDAF Wildcat (Cannon - Armed);
		model = "\DEGA_Wildcats\AW159_BAF_Cannon_armed";
		picture = "\DEGA_Wildcats\data\UI\picture_lynx_ca.paa";
		icon = "\DEGA_Wildcats\data\UI\icon_lynx_ca.paa";
		#include "\DEGA_Wildcats\Kimi\cfg_HMD_Lynx_Armed_Metric.hpp"
		_generalMacro = "DEGA_Wildcat_Cannon_Armed_RDAF";	
        selectionFireAnim = "zasleh";		
		hiddenSelections[] = {"camo1", "camo2"};
        hiddenSelectionsTextures[]={"\DEGA_Wildcats\Skins\lynx_base_rdaf_co.paa", "\DEGA_Wildcats\data\ah64d_details_co.paa"};
		class AnimationSources : AnimationSources
		{
			class ReloadMGAnim{source="reload";weapon="M621";};
        };
		weapons[] = {"Master_Arm_Safe_US_Helos_Kimi", "M621", "CRV7_PG_12rnd", "CMFlareLauncher"};
		magazines[] = {"1200Rnd_20mm_M621", "12Rnd_CRV7", "120Rnd_CMFlare_Chaff_Magazine"};		
		class Turrets: Turrets
		{
			class MainTurret: MainTurret {};  	
	        class CargoTurret_01: CargoTurret_01 {};
	        class CargoTurret_02: CargoTurret_02 {};
		};
	};	
///	
/// AAF	
///	
////////////////////////////////////////////////////////////////////////////////
//////////////////////AW159 AAF Wildcat Unarmed (Green)/////////////////////////
////////////////////////////////////////////////////////////////////////////////	
	class DEGA_Wildcat_Unarmed_Green_AAF: DEGA_Wildcat_Base
	{
	    author = "Deltagamer";
        scope = 2;	
		displayname = AW159 AAF Green Wildcat (Unarmed);
		faction = "IND_F";	
		crew = "I_helipilot_F";
		typicalCargo[]={I_Soldier_lite_F,I_Soldier_lite_F};	
		side = 2;		
		hiddenSelections[] = {"camo1", "camo2"};
		model = "\DEGA_Wildcats\AW159_BAF_unarmed";
		picture = "\DEGA_Wildcats\data\UI\picture_lynx_unarmed_ca.paa";
		icon = "\DEGA_Wildcats\data\UI\icon_lynx_unarmed_ca.paa";		
        hiddenSelectionsTextures[]={"\a3\air_f_epb\Heli_Light_03\data\heli_light_03_base_co.paa", "\DEGA_Wildcats\data\ah64d_details_co.paa"};
		_generalMacro = "DEGA_Wildcat_Unarmed_Green_AAF";			
		class Turrets: Turrets
		{
			class MainTurret: MainTurret {};
			class CargoTurret_01: CargoTurret_01 {};
			class CargoTurret_02: CargoTurret_02 {};						
		};
	};	
////////////////////////////////////////////////////////////////////////////////
//////////////////AW159 AAF Wildcat Hellfire Armed (Green)//////////////////////
////////////////////////////////////////////////////////////////////////////////	
	class DEGA_Wildcat_Hellfire_Armed_Green_AAF: DEGA_Wildcat_Base
	{
	    author = "Deltagamer";
        scope = 2;	
		displayname = AW159 AAF Green Wildcat (Hellfire - Armed);
		faction = "IND_F";	
		crew = "I_helipilot_F";
		typicalCargo[]={I_Soldier_lite_F,I_Soldier_lite_F};
		side = 2;		
		model = "\DEGA_Wildcats\AW159_BAF_Hellfire_armed";
		picture = "\DEGA_Wildcats\data\UI\picture_lynx_ca.paa";
		icon = "\DEGA_Wildcats\data\UI\icon_lynx_ca.paa";
		#include "\DEGA_Wildcats\Kimi\cfg_HMD_Lynx_Armed_Metric.hpp"
		_generalMacro = "DEGA_Wildcat_Hellfire_Armed_Green_AAF";
		memoryPointLMissile = "missile_1";
 		memoryPointRMissile = "missile_2";			
		hiddenSelections[] = {"camo1", "camo2"};
        hiddenSelectionsTextures[]={"\a3\air_f_epb\Heli_Light_03\data\heli_light_03_base_co.paa", "\DEGA_Wildcats\data\ah64d_details_co.paa"};			
		class Turrets: Turrets
		{
			class MainTurret: MainTurret //Gunner
			{
				weapons[] = {"Master_Arm_Safe_US_Helos_Kimi",  "Laserdesignator_mounted", "HellfireLauncherN", "HellfireLauncherL"};
				magazines[] = {"Laserbatteries", "4Rnd_Hellfire_N", "4Rnd_Hellfire_L"};	
	        };  	
	        class CargoTurret_01: CargoTurret_01 {};
	        class CargoTurret_02: CargoTurret_02 {};
		};
	};
////////////////////////////////////////////////////////////////////////////////
///////////////////AW159 AAF Wildcat Cannon Armed (Green)///////////////////////
////////////////////////////////////////////////////////////////////////////////	
	class DEGA_Wildcat_Cannon_Armed_Green_AAF: DEGA_Wildcat_Base
	{
	    author = "Deltagamer";
        scope = 2;	
		displayname = AW159 AAF Green Wildcat (Cannon - Armed);
		faction = "IND_F";	
		crew = "I_helipilot_F";
		typicalCargo[]={I_Soldier_lite_F,I_Soldier_lite_F};		
		side = 2;		
		model = "\DEGA_Wildcats\AW159_BAF_Cannon_armed";
		picture = "\DEGA_Wildcats\data\UI\picture_lynx_ca.paa";
		icon = "\DEGA_Wildcats\data\UI\icon_lynx_ca.paa";
		#include "\DEGA_Wildcats\Kimi\cfg_HMD_Lynx_Armed_Metric.hpp"
		_generalMacro = "DEGA_Wildcat_Cannon_Armed_Green_AAF";	
        selectionFireAnim = "zasleh";		
		hiddenSelections[] = {"camo1", "camo2"};
        hiddenSelectionsTextures[]={"\a3\air_f_epb\Heli_Light_03\data\heli_light_03_base_co.paa", "\DEGA_Wildcats\data\ah64d_details_co.paa"};
		class AnimationSources : AnimationSources
		{
			class ReloadMGAnim{source="reload";weapon="M621";};
        };
		weapons[] = {"Master_Arm_Safe_US_Helos_Kimi", "M621", "CRV7_PG_12rnd", "CMFlareLauncher"};
		magazines[] = {"1200Rnd_20mm_M621", "12Rnd_CRV7", "120Rnd_CMFlare_Chaff_Magazine"};		
		class Turrets: Turrets
		{
			class MainTurret: MainTurret {};  	
	        class CargoTurret_01: CargoTurret_01 {};
	        class CargoTurret_02: CargoTurret_02 {};
		};
	};	
////////////////////////////////////////////////////////////////////////////////
////////////////////AW159 AAF Wildcat Unarmed (Digital)/////////////////////////
////////////////////////////////////////////////////////////////////////////////	
	class DEGA_Wildcat_Unarmed_Digital_AAF: DEGA_Wildcat_Base
	{
	    author = "Deltagamer";
        scope = 2;	
		displayname = AW159 AAF Digital Wildcat (Unarmed);
		faction = "IND_F";	
		crew = "I_helipilot_F";
		typicalCargo[]={I_Soldier_lite_F,I_Soldier_lite_F};	
		side = 2;		
		hiddenSelections[] = {"camo1", "camo2"};
		model = "\DEGA_Wildcats\AW159_BAF_unarmed";
		picture = "\DEGA_Wildcats\data\UI\picture_lynx_unarmed_ca.paa";
		icon = "\DEGA_Wildcats\data\UI\icon_lynx_unarmed_ca.paa";		
        hiddenSelectionsTextures[]={"\a3\air_f_epb\Heli_Light_03\data\heli_light_03_base_indp_co.paa", "\DEGA_Wildcats\data\ah64d_details_co.paa"};
		_generalMacro = "DEGA_Wildcat_Unarmed_Digital_AAF";			
		class Turrets: Turrets
		{
			class MainTurret: MainTurret {};
			class CargoTurret_01: CargoTurret_01 {};
			class CargoTurret_02: CargoTurret_02 {};						
		};
	};	
////////////////////////////////////////////////////////////////////////////////
////////////////AW159 AAF Wildcat Hellfire Armed (Digital)//////////////////////
////////////////////////////////////////////////////////////////////////////////	
	class DEGA_Wildcat_Hellfire_Armed_Digital_AAF: DEGA_Wildcat_Base
	{
	    author = "Deltagamer";
        scope = 2;	
		displayname = AW159 AAF Digital Wildcat (Hellfire - Armed);
		faction = "IND_F";	
		crew = "I_helipilot_F";
		typicalCargo[]={I_Soldier_lite_F,I_Soldier_lite_F};
		side = 2;		
		model = "\DEGA_Wildcats\AW159_BAF_Hellfire_armed";
		picture = "\DEGA_Wildcats\data\UI\picture_lynx_ca.paa";
		icon = "\DEGA_Wildcats\data\UI\icon_lynx_ca.paa";
		#include "\DEGA_Wildcats\Kimi\cfg_HMD_Lynx_Armed_Metric.hpp"
		_generalMacro = "DEGA_Wildcat_Hellfire_Armed_Digital_AAF";
		memoryPointLMissile = "missile_1";
 		memoryPointRMissile = "missile_2";			
		hiddenSelections[] = {"camo1", "camo2"};
        hiddenSelectionsTextures[]={"\a3\air_f_epb\Heli_Light_03\data\heli_light_03_base_indp_co.paa", "\DEGA_Wildcats\data\ah64d_details_co.paa"};			
		class Turrets: Turrets
		{
			class MainTurret: MainTurret //Gunner
			{
				weapons[] = {"Master_Arm_Safe_US_Helos_Kimi",  "Laserdesignator_mounted", "HellfireLauncherN", "HellfireLauncherL"};
				magazines[] = {"Laserbatteries", "4Rnd_Hellfire_N", "4Rnd_Hellfire_L"};	
	        };  	
	        class CargoTurret_01: CargoTurret_01 {};
	        class CargoTurret_02: CargoTurret_02 {};
		};
	};
////////////////////////////////////////////////////////////////////////////////
/////////////////AW159 AAF Wildcat Cannon Armed (Digital)///////////////////////
////////////////////////////////////////////////////////////////////////////////	
	class DEGA_Wildcat_Cannon_Armed_Digital_AAF: DEGA_Wildcat_Base
	{
	    author = "Deltagamer";
        scope = 2;	
		displayname = AW159 AAF Digital Wildcat (Cannon - Armed);
		faction = "IND_F";	
		crew = "I_helipilot_F";
		typicalCargo[]={I_Soldier_lite_F,I_Soldier_lite_F};		
		side = 2;		
		model = "\DEGA_Wildcats\AW159_BAF_Cannon_armed";
		picture = "\DEGA_Wildcats\data\UI\picture_lynx_ca.paa";
		icon = "\DEGA_Wildcats\data\UI\icon_lynx_ca.paa";
		#include "\DEGA_Wildcats\Kimi\cfg_HMD_Lynx_Armed_Metric.hpp"
		_generalMacro = "DEGA_Wildcat_Cannon_Armed_Digital_AAF";	
        selectionFireAnim = "zasleh";		
		hiddenSelections[] = {"camo1", "camo2"};
        hiddenSelectionsTextures[]={"\a3\air_f_epb\Heli_Light_03\data\heli_light_03_base_indp_co.paa", "\DEGA_Wildcats\data\ah64d_details_co.paa"};
		class AnimationSources : AnimationSources
		{
			class ReloadMGAnim{source="reload";weapon="M621";};
        };
		weapons[] = {"Master_Arm_Safe_US_Helos_Kimi", "M621", "CRV7_PG_12rnd", "CMFlareLauncher"};
		magazines[] = {"1200Rnd_20mm_M621", "12Rnd_CRV7", "120Rnd_CMFlare_Chaff_Magazine"};		
		class Turrets: Turrets
		{
			class MainTurret: MainTurret {};  	
	        class CargoTurret_01: CargoTurret_01 {};
	        class CargoTurret_02: CargoTurret_02 {};
		};
	};		
};