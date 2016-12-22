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
#include "Armor_Master.h"

AArmor_Master::AArmor_Master(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	
}

// Called when the game starts or when spawned
void AArmor_Master::BeginPlay()
{
	Super::BeginPlay();

	// Bind this function to the event dispatcher for Bind Gear
	OnBindGear.AddDynamic(this, &AArmor_Master::BindArmor);
	OnRemoveGear.AddDynamic(this, &AArmor_Master::RemoveArmor);
}

// Custom code when binding
void AArmor_Master::BindArmor()
{
	ArmorMesh->SetVisibility(true);
	ArmorMesh->SetMasterPoseComponent(OwnerReference->GetMesh());
}

// Custom code when binding
void AArmor_Master::RemoveArmor()
{
	ArmorMesh->SetVisibility(false);
}
