// © 2014 - 2016 Soverance Studios. All Rights Reserved.

#include "Ethereal.h"
#include "Berserk.h"

// Sets default values
ABerserk::ABerserk(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	// Get Assets, References Obtained Via Right Click in Editor
	ConstructorHelpers::FObjectFinder<USoundCue> AudioObject(TEXT("SoundCue'/Game/Audio/Party/BerserkCast_Cue.BerserkCast_Cue'"));
	ConstructorHelpers::FObjectFinder<UParticleSystem> CastParticleObject(TEXT("ParticleSystem'/Game/InfinityBladeEffects/Effects/FX_Ability/Heal/P_BerserkCast.P_BerserkCast'"));
	ConstructorHelpers::FObjectFinder<UParticleSystem> ChargeParticleObject(TEXT("ParticleSystem'/Game/Blueprints/Gear/Magic/SpellEffects/Particles/ChargeFX/ChargeParticle.ChargeParticle'"));
	ConstructorHelpers::FObjectFinder<UTexture2D> LargeIconObject(TEXT("Texture2D'/Game/Blueprints/Widgets/UI-Images/Icons_Magic/berserk.berserk'"));
	ConstructorHelpers::FObjectFinder<UTexture2D> SmallIconObject(TEXT("Texture2D'/Game/Blueprints/Widgets/UI-Images/Icons_Magic/berserk-small.berserk-small'"));

	// Set Default Values
	Name = EMasterGearList::GL_Berserk;
	Type = EMasterGearTypes::GT_Support;
	Description = "Temporarily increase ATK, boosting attack damage by 25%.";
	MPCost = 45;
	ATK = 10;
	DEF = -25;
	SPD = 5;
	HP = 250;
	MP = -50;
	Duration = 60;
	CastTime = 30;
	CritMultiplier = 0.25f;
	HasteMultiplier = 0;
	DefenseMultiplier = 0;
	TargetType = EMagic_TargetTypes::TT_Player;
	AnimType = EMagic_AnimTypes::AT_ForwardBlast;

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
void ABerserk::BeginPlay()
{
	Super::BeginPlay();

	// Bind the Use function to the event dispatcher for Item Use
	QuitCharging.AddDynamic(this, &ABerserk::Cancel);
}

void ABerserk::Cancel()
{
	GEngine->AddOnScreenDebugMessage(-1, 10.f, FColor::Red, "Berserk casting was cancelled.");
}


