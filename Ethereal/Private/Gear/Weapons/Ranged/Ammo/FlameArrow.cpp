// © 2014 - 2016 Soverance Studios
// http://www.soverance.com

// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at

// http ://www.apache.org/licenses/LICENSE-2.0

// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
#include "Ethereal.h"
#include "FlameArrow.h"

#define LOCTEXT_NAMESPACE "EtherealText"

// Sets default values
AFlameArrow::AFlameArrow(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	// Get Assets, References Obtained Via Right Click in Editor
	static ConstructorHelpers::FObjectFinder<USkeletalMesh> SkeletalMeshObject(TEXT("SkeletalMesh'/Game/VFX/sphere_skeletal.sphere_skeletal'"));
	static ConstructorHelpers::FObjectFinder<UStaticMesh> StaticMeshObject(TEXT("StaticMesh'/Game/Weapons/Ranged/Ammo/DemonArrow.DemonArrow'"));
	static ConstructorHelpers::FObjectFinder<UStaticMesh> OffhandMeshObject(TEXT("StaticMesh'/Game/VFX/sphere.sphere'"));
	ConstructorHelpers::FObjectFinder<UTexture2D> LargeIconObject(TEXT("Texture2D'/Game/Blueprints/Widgets/UI-Images/Icons_Gear/WeaponIcon_DemonArrows.WeaponIcon_DemonArrows'"));
	ConstructorHelpers::FObjectFinder<UTexture2D> SmallIconObject(TEXT("Texture2D'/Game/Blueprints/Widgets/UI-Images/Icons_Gear/WeaponIcon_DemonArrows-small.WeaponIcon_DemonArrows-small'"));


	// Set Default Objects

	Name = EMasterGearList::GL_FlameArrow;
	NameText = LOCTEXT("FlameArrowText", "Flame Arrow");
	Type = EMasterGearTypes::GT_Ammo;
	Description = "Arrows tipped with flaming wax.";
	MPCost = 0.0f;
	ATK = 25.0f;
	DEF = 0.0f;
	SPD = 0.0f;
	HP = 100.0f;
	MP = 0.0f;
	LargeIcon = LargeIconObject.Object;
	SmallIcon = SmallIconObject.Object;

	SK_WeaponSkeletalMesh = SkeletalMeshObject.Object;
	SM_WeaponStaticMesh = StaticMeshObject.Object;
	SM_WeaponOffhandMesh = StaticMeshObject.Object;

	// Set Mesh
	WeaponSkeletalMesh->SetSkeletalMesh(SK_WeaponSkeletalMesh);
	WeaponStaticMesh->SetStaticMesh(SM_WeaponStaticMesh);
	WeaponOffhandMesh->SetStaticMesh(SM_WeaponOffhandMesh);

	//WeaponStaticMesh->SetVisibility(true);
	//WeaponStaticMesh->SetRelativeRotation(FRotator(180.0f, 90.0f, 0.0f));
	//SwordCollider->SetBoxExtent(FVector(10.0f, 15.0f, 60.0f));
	//SwordCollider->SetRelativeLocation(FVector(0.0f, 0.0f, 60.0f));
}

// Called when the game starts or when spawned
void AFlameArrow::BeginPlay()
{
	Super::BeginPlay();
}

#undef LOCTEXT_NAMESPACE