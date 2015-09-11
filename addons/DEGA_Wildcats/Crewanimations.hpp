
class CfgMovesBasic
{
	class DefaultDie;
	class ManActions
	{
		AW159_Cargo_BAF="AW159_Cargo_BAF";
		AW159_Cargo01_BAF="AW159_Cargo01_BAF";
		AW159_Pilot_BAF="AW159_Pilot_BAF";
	};
};
class CfgMovesMaleSdr: CfgMovesBasic
{
	class States
	{
		class Crew;	
		class AW159_Cargo_BAF: Crew
		
		{
			file="\DEGA_Wildcats\Data\Anim\AW159_Cargo";
			connectTo[]=
			{
				"AW159_KIA_Cargo_BAF",
				1
			};
			speed=1e+010;
		};
		class AW159_KIA_Cargo_BAF: DefaultDie
		{
			actions="DeadActions";
			file="\DEGA_Wildcats\Data\Anim\AW159_KIA_Cargo";
			speed=1e+010;
			terminal=1;
			soundEnabled=0;
			looped=0;
			connectTo[]=
			{
				"DeadState",
				0.1
			};
		};
		
		class AW159_Cargo01_BAF: Crew
		{
			file="\DEGA_Wildcats\Data\Anim\AW159_Cargo01";
			connectTo[]=
			{
				"AW159_KIA_Cargo_BAF",
				1
			};
			speed=1e+010;
		};
		
		class AW159_Pilot_BAF: Crew
		{
			file="\DEGA_Wildcats\Data\Anim\AW159_Pilot";
			connectTo[]=
			{
				"AW159_KIA_Pilot_BAF",
				1
			};
			speed=1e+010;
		};
		class AW159_KIA_Pilot_BAF: DefaultDie
		{
			actions="DeadActions";
			file="\DEGA_Wildcats\Data\Anim\AW159_Kia_Pilot";
			speed=1e+010;
			terminal=1;
			soundEnabled=0;
			looped=0;
			connectTo[]=
			{
				"DeadState",
				0.1
			};
		};
	};
};
class CfgMovesWomen: CfgMovesBasic
{
	class DefaultDie;
	class ManActions
	{	
		AW159_Cargo_BAF="crew";
		AW159_Cargo01_BAF="crew";
		AW159_Pilot_BAF="crew";	
	};
};