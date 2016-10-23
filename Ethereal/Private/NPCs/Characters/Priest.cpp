// © 2014 - 2016 Soverance Studios
// http://www.soverance.com

// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at

// http://www.apache.org/licenses/LICENSE-2.0

// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#include "Ethereal.h"
#include "Gear/EtherealGearMaster.h"
#include "Blueprint/UserWidget.h"
#include "Priest.h"

APriest::APriest(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	static ConstructorHelpers::FObjectFinder<USkeletalMesh> NPCMesh(TEXT("SkeletalMesh'/Game/EtherealParty/OldWizard/OldWizard.OldWizard'"));
	static ConstructorHelpers::FObjectFinder<UClass> AnimBP(TEXT("AnimBlueprint'/Game/EtherealParty/OldWizard/Anim_OldWizard.Anim_OldWizard_C'"));
	static ConstructorHelpers::FClassFinder<UUserWidget> Widget(TEXT("/Game/Blueprints/Widgets/ShopMenu"));

	// Set Default Objects
	SM_Mesh = NPCMesh.Object;
	W_InteractWidget = Widget.Class;

	// Create objects
	Mesh = ObjectInitializer.CreateDefaultSubobject<USkeletalMeshComponent>(this, TEXT("Mesh"));
	Mesh->SetupAttachment(RootComponent);
	Mesh->SetAnimInstanceClass(AnimBP.Object);
	Mesh->SkeletalMesh = SM_Mesh;
	Mesh->SetRelativeScale3D(FVector(0.15f, 0.15f, 0.15f));

	IsUsable = true;
	InteractAnimType = EInteractAnims::IA_Talk;

	DoInteract.AddDynamic(this, &APriest::Interact);
}

// Called when the game starts or when spawned
void APriest::BeginPlay()
{
	Super::BeginPlay();

	// Get the GearManager Actor
	for (TActorIterator<AEtherealGearManager> ActorItr(GetWorld()); ActorItr; ++ActorItr)
	{
		GearManager = *ActorItr; // set the instance of the GearManager actor
	}

	if (GearManager)
	{
		SpawnDefaultShopItems();  // Spawn the Shop's default items.
	}
}

// Interact with this NPC
void APriest::Interact()
{
	Shrug = true;
	IsUsable = false;

	if (!InteractWidget) // only run this code if the widget does not exist
	{
		InteractWidget = CreateWidget<UUserWidget>(GetWorld(), W_InteractWidget);  // creates the widget
		InteractWidget->AddToViewport();
	}
	else
	{
		bool IsInView = InteractWidget->IsInViewport();

		if (!IsInView) // check to be sure it is not already in the viewport
		{
			InteractWidget->AddToViewport(); // if not, add it to the viewport
		}
	}
}

// Disabled the Interact Widget associated with this NPC
void APriest::DisableInteractWidget()
{
	InteractWidget->RemoveFromViewport();
	IsUsable = true;
	Yawn = true;
}

void APriest::SpawnDefaultShopItems()
{
	TArray<EMasterGearList> DefaultShopList;

	EMasterGearList Consumable0 = EMasterGearList::GL_Potion;
	DefaultShopList.AddUnique(Consumable0);
	EMasterGearList Consumable1 = EMasterGearList::GL_HiPotion;
	DefaultShopList.AddUnique(Consumable1);
	EMasterGearList Consumable2 = EMasterGearList::GL_Ether;
	DefaultShopList.AddUnique(Consumable2);
	EMasterGearList Consumable3 = EMasterGearList::GL_HiEther;
	DefaultShopList.AddUnique(Consumable3);
	EMasterGearList Consumable4 = EMasterGearList::GL_Adrenaline;
	DefaultShopList.AddUnique(Consumable4);
	EMasterGearList Consumable5 = EMasterGearList::GL_SentinelBrew;
	DefaultShopList.AddUnique(Consumable5);
	EMasterGearList Consumable6 = EMasterGearList::GL_Reraise;
	DefaultShopList.AddUnique(Consumable6);

	EMasterGearList Magic0 = EMasterGearList::GL_Cure2;
	DefaultShopList.AddUnique(Magic0);
	EMasterGearList Magic1 = EMasterGearList::GL_Regen;
	DefaultShopList.AddUnique(Magic1);
	EMasterGearList Magic2 = EMasterGearList::GL_Refresh;
	DefaultShopList.AddUnique(Magic2);
	EMasterGearList Magic3 = EMasterGearList::GL_Fire;
	DefaultShopList.AddUnique(Magic3);
	EMasterGearList Magic4 = EMasterGearList::GL_Blizzard;
	DefaultShopList.AddUnique(Magic4);
	EMasterGearList Magic5 = EMasterGearList::GL_Thunder;
	DefaultShopList.AddUnique(Magic5);
	EMasterGearList Magic6 = EMasterGearList::GL_Berserk;
	DefaultShopList.AddUnique(Magic6);
	EMasterGearList Magic7 = EMasterGearList::GL_Barrier;
	DefaultShopList.AddUnique(Magic7);

	EMasterGearList Weapon0 = EMasterGearList::GL_Joyeuse;
	DefaultShopList.AddUnique(Weapon0);
	EMasterGearList Weapon1 = EMasterGearList::GL_Hauteclaire;
	DefaultShopList.AddUnique(Weapon1);
	EMasterGearList Weapon2 = EMasterGearList::GL_BalloonSword;
	DefaultShopList.AddUnique(Weapon2);
	EMasterGearList Weapon3 = EMasterGearList::GL_SpartanShield;
	DefaultShopList.AddUnique(Weapon3);
	EMasterGearList Weapon4 = EMasterGearList::GL_DiablosDread;
	DefaultShopList.AddUnique(Weapon4);
	EMasterGearList Weapon5 = EMasterGearList::GL_Juggernaut;
	DefaultShopList.AddUnique(Weapon5);
	EMasterGearList Weapon6 = EMasterGearList::GL_Claymore;
	DefaultShopList.AddUnique(Weapon6);
	EMasterGearList Weapon7 = EMasterGearList::GL_Marauder;
	DefaultShopList.AddUnique(Weapon7);
	EMasterGearList Weapon8 = EMasterGearList::GL_ShortBow;
	DefaultShopList.AddUnique(Weapon8);
	EMasterGearList Weapon9 = EMasterGearList::GL_EagleEye;
	DefaultShopList.AddUnique(Weapon9);
	EMasterGearList Weapon10 = EMasterGearList::GL_EurytosBow;
	DefaultShopList.AddUnique(Weapon10);
	EMasterGearList Weapon11 = EMasterGearList::GL_WoodenArrow;
	DefaultShopList.AddUnique(Weapon11);
	EMasterGearList Weapon12 = EMasterGearList::GL_IronArrow;
	DefaultShopList.AddUnique(Weapon12);
	EMasterGearList Weapon13 = EMasterGearList::GL_FlameArrow;
	DefaultShopList.AddUnique(Weapon13);

	EMasterGearList Armor0 = EMasterGearList::GL_ClothCap;
	DefaultShopList.AddUnique(Armor0);
	EMasterGearList Armor1 = EMasterGearList::GL_ClothTunic;
	DefaultShopList.AddUnique(Armor1);
	EMasterGearList Armor2 = EMasterGearList::GL_ClothGloves;
	DefaultShopList.AddUnique(Armor2);
	EMasterGearList Armor3 = EMasterGearList::GL_ClothPants;
	DefaultShopList.AddUnique(Armor3);
	EMasterGearList Armor4 = EMasterGearList::GL_ClothShoes;
	DefaultShopList.AddUnique(Armor4);
	EMasterGearList Armor5 = EMasterGearList::GL_ClothCape;
	DefaultShopList.AddUnique(Armor5);
	EMasterGearList Armor6 = EMasterGearList::GL_SilverRing;
	DefaultShopList.AddUnique(Armor6);
	EMasterGearList Armor7 = EMasterGearList::GL_AdamanHelm;
	DefaultShopList.AddUnique(Armor7);
	EMasterGearList Armor8 = EMasterGearList::GL_AdamanCuirass;
	DefaultShopList.AddUnique(Armor8);
	EMasterGearList Armor9 = EMasterGearList::GL_AdamanGauntlets;
	DefaultShopList.AddUnique(Armor9);
	EMasterGearList Armor10 = EMasterGearList::GL_AdamanCuisses;
	DefaultShopList.AddUnique(Armor10);
	EMasterGearList Armor11 = EMasterGearList::GL_AdamanSabatons;
	DefaultShopList.AddUnique(Armor11);
	EMasterGearList Armor12 = EMasterGearList::GL_KnightsCape;
	DefaultShopList.AddUnique(Armor12);
	EMasterGearList Armor13 = EMasterGearList::GL_DarksteelRing;
	DefaultShopList.AddUnique(Armor13);
	EMasterGearList Armor14 = EMasterGearList::GL_WarHelm;
	DefaultShopList.AddUnique(Armor14);
	EMasterGearList Armor15 = EMasterGearList::GL_WarCoat;
	DefaultShopList.AddUnique(Armor15);
	EMasterGearList Armor16 = EMasterGearList::GL_WarGloves;
	DefaultShopList.AddUnique(Armor16);
	EMasterGearList Armor17 = EMasterGearList::GL_WarBrais;
	DefaultShopList.AddUnique(Armor17);
	EMasterGearList Armor18 = EMasterGearList::GL_WarBoots;
	DefaultShopList.AddUnique(Armor18);
	EMasterGearList Armor19 = EMasterGearList::GL_ThiefsShroud;
	DefaultShopList.AddUnique(Armor19);
	EMasterGearList Armor20 = EMasterGearList::GL_ShadowRing;
	DefaultShopList.AddUnique(Armor20);

	for (EMasterGearList Item : DefaultShopList)  // for each item in the inventory...
	{
		AEtherealGearMaster* Gear = GearManager->CreateGear(Item); // create the new item

		if (Gear)
		{
			Gear->AttachToComponent(Mesh, FAttachmentTransformRules::SnapToTargetIncludingScale, TEXT("ItemSocket"));  // attach gear to Priest
			ShopInventory.AddUnique(Gear);  // Add gear into the Priest's Shop Inventory
		}		
	}
}
