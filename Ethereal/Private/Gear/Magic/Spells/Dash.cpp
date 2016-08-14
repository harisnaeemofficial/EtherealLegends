// © 2014 - 2016 Soverance Studios. All Rights Reserved.

#include "Ethereal.h"
#include "Dash.h"

// Sets default values
ADash::ADash(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	// Get Assets, References Obtained Via Right Click in Editor
	ConstructorHelpers::FObjectFinder<USoundCue> AudioObject(TEXT("SoundCue'/Game/Audio/Party/Dash1_Cue.Dash1_Cue'"));
	ConstructorHelpers::FObjectFinder<UParticleSystem> CastParticleObject(TEXT("ParticleSystem'/Game/Elemental/Logo/FrozenLogo/_FX_LogoReveal_ICE._FX_LogoReveal_ICE'"));
	ConstructorHelpers::FObjectFinder<UParticleSystem> ChargeParticleObject(TEXT("ParticleSystem'/Game/Blueprints/Gear/Magic/SpellEffects/Particles/ChargeFX/ChargeParticle.ChargeParticle'"));
	ConstructorHelpers::FObjectFinder<UTexture2D> LargeIconObject(TEXT("Texture2D'/Game/Blueprints/Widgets/UI-Images/Icons_Magic/dash.dash'"));
	ConstructorHelpers::FObjectFinder<UTexture2D> SmallIconObject(TEXT("Texture2D'/Game/Blueprints/Widgets/UI-Images/Icons_Magic/dash-small.dash-small'"));

	// Set Default Values
	Name = EMasterGearList::GL_Dash;
	Type = EMasterGearTypes::GT_Ancient;
	Description = "Quickly move forward in an evasive maneuver.";
	MPCost = 35;
	ATK = 0;
	DEF = 0;
	SPD = 0;
	HP = 25;
	MP = 15;
	Duration = 0;
	CastTime = 0;
	CritMultiplier = 0;
	HasteMultiplier = 0;
	DefenseMultiplier = 0;
	TargetType = EMagic_TargetTypes::TT_Player;
	AnimType = EMagic_AnimTypes::AT_Dash;

	// Set Default Objects
	S_CastAudio = AudioObject.Object;
	P_CastFX = CastParticleObject.Object;
	P_ChargeFX = ChargeParticleObject.Object;
	LargeIcon = LargeIconObject.Object;
	SmallIcon = SmallIconObject.Object;

	// Attachment
	CastAudio->SetupAttachment(GetRootComponent());
	CastAudio->Sound = S_CastAudio;
	CastAudio->bAutoActivate = false;
	CastFX->SetupAttachment(GetRootComponent());	
	CastFX->Template = P_CastFX;
	CastFX->bAutoActivate = false;
	ChargeFX->SetupAttachment(GetRootComponent());
	ChargeFX->Template = P_ChargeFX;
	ChargeFX->bAutoActivate = false;
}

// Called when the game starts or when spawned
void ADash::BeginPlay()
{
	Super::BeginPlay();

	// Bind the Use function to the event dispatcher for Item Use
	QuitCharging.AddDynamic(this, &ADash::Cancel);
}

void ADash::Cancel()
{
	GEngine->AddOnScreenDebugMessage(-1, 10.f, FColor::Red, "Dash casting was cancelled.");
}



