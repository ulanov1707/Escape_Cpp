// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "IItem.h"
#include "Weapon.generated.h"


UCLASS()
class ESCAPE_API AWeapon : public AIItem
{
	GENERATED_BODY()
public:
	//AWeapon();
	//UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item | Particles")
		//bool bWeaponParticle;

	//UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item | Sound")
		//class USoundCue* OnEquipedSound;

	//UENUM(VisibleAnywhere, BlueprintReadWrite, Category = "Enum")
		//EWeaponState WeaponState;


	//Since in our game we are using a "Infinity balade:Weapons" assets ,and all weapos there are of type "Skelatal Mesh",thats why we are creating 
	//a SkeletalMeshComonent for those weapons
	//UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "SkeletalMesh")
		//USkeletalMeshComponent* SkeletalMesh;

	//virtual void OverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)override;
	//virtual void OverlapEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)override;

	//void Equip(class AMainCharacter*);

	//FORCEINLINE void SetWeaponState(EWeaponState State) { WeaponState = State; }
	//FORCEINLINE EWeaponState GetWeaponState() { return WeaponState; }

	
};
