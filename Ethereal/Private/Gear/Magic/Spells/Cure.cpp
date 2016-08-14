// © 2014 - 2016 Soverance Studios. All Rights Reserved.

#include "Ethereal.h"
#include "Cure.h"

// Sets default values
ACure::ACure(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	// Get Assets, References Obtained Via Right Click in Editor
	ConstructorHelpers::FObjectFinder<USoundCue> AudioObject(TEXT("SoundCue'/Game/EtherealParty/OldWizard/Audio/Absolut_Cure_Cue.Absolut_Cure_Cue'"));
	ConstructorHelpers::FObjectFinder<UParticleSystem> CastParticleObject(TEXT("ParticleSystem'/Game/Blueprints/Gear/Magic/SpellEffects/Particles/Spell_Cure.Spell_Cure'"));
	ConstructorHelpers::FObjectFinder<UParticleSystem> ChargeParticleObject(TEXT("ParticleSystem'/Game/Blueprints/Gear/Magic/SpellEffects/Particles/ChargeFX/ChargeParticle.ChargeParticle'"));
	ConstructorHelpers::FObjectFinder<UTexture2D> LargeIconObject(TEXT("Texture2D'/Game/Blueprints/Widgets/UI-Images/Icons_Magic/cure.cure'"));
	ConstructorHelpers::FObjectFinder<UTexture2D> SmallIconObject(TEXT("Texture2D'/Game/Blueprints/Widgets/UI-Images/Icons_Magic/cure-small.cure-small'"));

	// Set Default Values
	Name = EMasterGearList::GL_Cure;
	Type = EMasterGearTypes::GT_White;
	Description = "Temporarily increase SPD, improving cast time and movement speed by 20%.";
	MPCost = 60;
	ATK = 0;
	DEF = 0;
	SPD = 20;
	HP = -240;
	MP = -40;
	Duration = 60;
	CastTime = 40;
	CritMultiplier = 0;
	HasteMultiplier = 0.20f;
	DefenseMultiplier = 0;
	TargetType = EMagic_TargetTypes::TT_Player;
	AnimType = EMagic_AnimTypes::AT_Standard;

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
void ACure::BeginPlay()
{
	Super::BeginPlay();

	// Bind the Use function to the event dispatcher for Item Use
	QuitCharging.AddDynamic(this, &ACure::Cancel);
}

void ACure::Cancel()
{
	GEngine->AddOnScreenDebugMessage(-1, 10.f, FColor::Red, "Cure casting was cancelled.");
}



