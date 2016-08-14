// © 2014 - 2016 Soverance Studios. All Rights Reserved.

#include "Ethereal.h"
#include "Hauteclaire.h"

// Sets default values
AHauteclaire::AHauteclaire(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	// Get Assets, References Obtained Via Right Click in Editor
	static ConstructorHelpers::FObjectFinder<USkeletalMesh> SkeletalMeshObject(TEXT("SkeletalMesh'/Game/InfinityBladeWeapons/Weapons/Blade/Swords/Blade_BlackKnight/SK_Hauteclaire.SK_Hauteclaire'"));
	static ConstructorHelpers::FObjectFinder<UStaticMesh> StaticMeshObject(TEXT("StaticMesh'/Game/VFX/sphere.sphere'"));
	static ConstructorHelpers::FObjectFinder<UStaticMesh> OffhandMeshObject(TEXT("StaticMesh'/Game/VFX/sphere.sphere'"));
	ConstructorHelpers::FObjectFinder<UTexture2D> LargeIconObject(TEXT("Texture2D'/Game/Blueprints/Widgets/UI-Images/Icons_Gear/WeaponIcon_Hauteclaire.WeaponIcon_Hauteclaire'"));
	ConstructorHelpers::FObjectFinder<UTexture2D> SmallIconObject(TEXT("Texture2D'/Game/Blueprints/Widgets/UI-Images/Icons_Gear/WeaponIcon_Hauteclaire-small.WeaponIcon_Hauteclaire-small'"));


	// Set Default Objects

	Name = EMasterGearList::GL_Hauteclaire;
	Type = EMasterGearTypes::GT_OneHanded;
	Description = "A dark weapon said to have been forged by a demigod.";
	MPCost = 0.0f;
	ATK = 20.0f;
	DEF = 50.0f;
	SPD = 50.0f;
	HP = 150.0f;
	MP = 25.0f;
	LargeIcon = LargeIconObject.Object;
	SmallIcon = SmallIconObject.Object;

	SK_WeaponSkeletalMesh = SkeletalMeshObject.Object;
	SM_WeaponStaticMesh = StaticMeshObject.Object;
	SM_WeaponOffhandMesh = StaticMeshObject.Object;

	// Set Mesh
	WeaponSkeletalMesh->SetSkeletalMesh(SK_WeaponSkeletalMesh);
	WeaponStaticMesh->SetStaticMesh(SM_WeaponStaticMesh);
	WeaponOffhandMesh->SetStaticMesh(SM_WeaponOffhandMesh);

	WeaponSkeletalMesh->SetVisibility(true);
	SwordCollider->SetBoxExtent(FVector(10.0f, 10.0f, 60.0f));
	SwordCollider->SetRelativeLocation(FVector(0.0f, 0.0f, 55.0f));
}

// Called when the game starts or when spawned
void AHauteclaire::BeginPlay()
{
	Super::BeginPlay();
}



