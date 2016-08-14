// © 2014 - 2016 Soverance Studios. All Rights Reserved.

#include "Ethereal.h"
#include "Weapon_Master.h"

AWeapon_Master::AWeapon_Master(const FObjectInitializer& ObjectInitializer)
{
	// Asset, Reference Obtained Via Right Click in Editor
	static ConstructorHelpers::FObjectFinder<USkeletalMesh> SkeletalMeshObject(TEXT("SkeletalMesh'/Game/VFX/sphere_skeletal.sphere_skeletal'"));
	static ConstructorHelpers::FObjectFinder<UStaticMesh> StaticMeshObject(TEXT("StaticMesh'/Game/VFX/sphere.sphere'"));
	static ConstructorHelpers::FObjectFinder<UStaticMesh> OffhandMeshObject(TEXT("StaticMesh'/Game/VFX/sphere.sphere'"));

	// Set Default Objects
	SK_WeaponSkeletalMesh = SkeletalMeshObject.Object;
	SM_WeaponStaticMesh = StaticMeshObject.Object;
	SM_WeaponOffhandMesh = StaticMeshObject.Object;

	// Create
	WeaponSkeletalMesh = ObjectInitializer.CreateDefaultSubobject < USkeletalMeshComponent >(this, TEXT("Weapon Skeletal Mesh"));
	WeaponStaticMesh = ObjectInitializer.CreateDefaultSubobject < UStaticMeshComponent >(this, TEXT("Weapon Static Mesh"));
	WeaponOffhandMesh = ObjectInitializer.CreateDefaultSubobject < UStaticMeshComponent >(this, TEXT("Weapon Offhand Mesh"));

	// Set Mesh
	WeaponSkeletalMesh->SetSkeletalMesh(SK_WeaponSkeletalMesh);
	WeaponStaticMesh->SetStaticMesh(SM_WeaponStaticMesh);
	WeaponOffhandMesh->SetStaticMesh(SM_WeaponOffhandMesh);

	// Configure Mesh
	SetupSKComponentsWithCollision(WeaponSkeletalMesh);
	SetupSMComponentsWithCollision(WeaponStaticMesh);
	SetupSMComponentsWithCollision(WeaponOffhandMesh);
}

// Called when the game starts or when spawned
void AWeapon_Master::BeginPlay()
{
	Super::BeginPlay();

	// Attachment
	WeaponSkeletalMesh->AttachToComponent(RootComponent, FAttachmentTransformRules::SnapToTargetIncludingScale);
	WeaponStaticMesh->AttachToComponent(RootComponent, FAttachmentTransformRules::SnapToTargetIncludingScale);
	WeaponOffhandMesh->AttachToComponent(RootComponent, FAttachmentTransformRules::SnapToTargetIncludingScale);
}


// SetVisible
void AWeapon_Master::SetVisible()
{
	if (IsVisible == true)
	{
		switch (Type)
		{
			case EMasterGearTypes::GT_None:
				break;
			case EMasterGearTypes::GT_OneHanded:
				WeaponSkeletalMesh->SetVisibility(true);
				WeaponStaticMesh->SetVisibility(true);
				WeaponOffhandMesh->SetVisibility(false);
				break;
			case EMasterGearTypes::GT_TwoHanded:
				WeaponSkeletalMesh->SetVisibility(true);
				WeaponStaticMesh->SetVisibility(true);
				WeaponOffhandMesh->SetVisibility(false);
				break;
			case EMasterGearTypes::GT_Ranged:
				WeaponSkeletalMesh->SetVisibility(true);
				WeaponStaticMesh->SetVisibility(true);
				WeaponOffhandMesh->SetVisibility(false);
				break;
			case EMasterGearTypes::GT_CastingOrb:
				WeaponSkeletalMesh->SetVisibility(false);
				WeaponStaticMesh->SetVisibility(true);
				WeaponOffhandMesh->SetVisibility(true);
				break;
			case EMasterGearTypes::GT_Theurgy:
				break;
			case EMasterGearTypes::GT_Necromancy:
				break;
			case EMasterGearTypes::GT_Support:
				break;
			case EMasterGearTypes::GT_Ancient:
				break;
			case EMasterGearTypes::GT_Shield:
				WeaponSkeletalMesh->SetVisibility(true);
				WeaponStaticMesh->SetVisibility(true);
				break;
			case EMasterGearTypes::GT_Ammo:
				break;
			case EMasterGearTypes::GT_Head:
				break;
			case EMasterGearTypes::GT_Cape:
				break;
			case EMasterGearTypes::GT_Body:
				break;
			case EMasterGearTypes::GT_Hands:
				break;
			case EMasterGearTypes::GT_Legs:
				break;
			case EMasterGearTypes::GT_Feet:
				break;
			case EMasterGearTypes::GT_Consumable:
				break;
			case EMasterGearTypes::GT_KeyItem:
				break;
			default:
				break;
		}
	}	
}

void AWeapon_Master::OnHit(UObject* CharacterMaster)
{
	if (IsVisible)
	{

	}
}







