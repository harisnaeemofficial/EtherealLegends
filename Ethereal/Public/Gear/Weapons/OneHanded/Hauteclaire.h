// © 2014 - 2016 Soverance Studios. All Rights Reserved.

#pragma once

#include "Gear/Weapons/Weapon_Master.h"
#include "Hauteclaire.generated.h"

/**
 * 
 */
UCLASS()
class ETHEREAL_API AHauteclaire : public AWeapon_Master
{
	GENERATED_BODY()
	
public:

	AHauteclaire(const FObjectInitializer& ObjectInitializer);

	// BeginPlay Override
	virtual void BeginPlay() override;

	// Collider
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Collision)
	UBoxComponent* SwordCollider = CreateDefaultSubobject<UBoxComponent>(TEXT("SwordCollider"));
};
