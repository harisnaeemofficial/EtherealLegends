// © 2014 - 2016 Soverance Studios. All Rights Reserved.

#include "Ethereal.h"
#include "Fire.h"

// Sets default values
AFire::AFire(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	// Get Assets, References Obtained Via Right Click in Editor
	//ConstructorHelpers::FObjectFinder<USoundCue> AudioObject(TEXT("SoundCue'/Game/Audio/Party/Dash1_Cue.Dash1_Cue'"));
	//ConstructorHelpers::FObjectFinder<UParticleSystem> CastParticleObject(TEXT("ParticleSystem'/Game/Elemental/Logo/FrozenLogo/_FX_LogoReveal_ICE._FX_LogoReveal_ICE'"));
	ConstructorHelpers::FObjectFinder<UParticleSystem> ChargeParticleObject(TEXT("ParticleSystem'/Game/Blueprints/Gear/Magic/SpellEffects/Particles/ChargeFX/ChargeParticle.ChargeParticle'"));
	ConstructorHelpers::FObjectFinder<UTexture2D> LargeIconObject(TEXT("Texture2D'/Game/Blueprints/Widgets/UI-Images/Icons_Magic/fire.fire'"));
	ConstructorHelpers::FObjectFinder<UTexture2D> SmallIconObject(TEXT("Texture2D'/Game/Blueprints/Widgets/UI-Images/Icons_Magic/fire-small.fire-small'"));

	// Set Default Values
	Name = EMasterGearList::GL_Fire;
	Type = EMasterGearTypes::GT_Black;
	Description = "Generate a powerful burst of flame, incinerating everything at close range.";
	MPCost = 60;
	ATK = 5;
	DEF = 0;
	SPD = 0;
	HP = -120;
	MP = 40;
	Duration = 10;
	CastTime = 30;
	CritMultiplier = 0;
	HasteMultiplier = 0;
	DefenseMultiplier = 0;
	TargetType = EMagic_TargetTypes::TT_Enemy;
	AnimType = EMagic_AnimTypes::AT_ForwardBlast;

	// Set Default Objects
	//S_CastAudio = AudioObject.Object;
	//P_CastFX = CastParticleObject.Object;
	P_ChargeFX = ChargeParticleObject.Object;
	LargeIcon = LargeIconObject.Object;
	SmallIcon = SmallIconObject.Object;

	// Attachment
	//CastAudio->SetupAttachment(GetRootComponent());
	//CastAudio->Sound = S_CastAudio;
	//CastAudio->bAutoActivate = false;
	//CastFX->SetupAttachment(GetRootComponent());
	//CastFX->Template = P_CastFX;
	//CastFX->bAutoActivate = false;
	ChargeFX->SetupAttachment(GetRootComponent());
	ChargeFX->Template = P_ChargeFX;
	ChargeFX->bAutoActivate = false;
}

// Called when the game starts or when spawned
void AFire::BeginPlay()
{
	Super::BeginPlay();

	// Bind the Use function to the event dispatcher for Item Use
	QuitCharging.AddDynamic(this, &AFire::Cancel);
}

void AFire::Cancel()
{
	GEngine->AddOnScreenDebugMessage(-1, 10.f, FColor::Red, "Fire casting was cancelled.");
}



