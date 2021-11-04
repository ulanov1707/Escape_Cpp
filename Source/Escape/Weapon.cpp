// Fill out your copyright notice in the Description page of Project Settings.

#include "Weapon.h"
#include"Components/SkeletalMeshComponent.h"
#include"MainCharacter.h"
#include"Engine/SkeletalMeshSocket.h"
#include"Sound/SoundCue.h"
#include"Kismet/GameplayStatics.h"
#include"Particles/ParticleSystemComponent.h"
/*
AWeapon::AWeapon()
{
	SkeletalMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("SkeletalMesh"));
	SkeletalMesh->SetupAttachment(GetRootComponent());

	WeaponState = EWeaponState::enEWS_PickUp;

	bWeaponParticle = false;
}
void AWeapon::OverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	Super::OverlapBegin(OverlappedComponent, OtherActor, OtherComp, OtherBodyIndex, bFromSweep, SweepResult);

	// weapon can be picked up only if character(OtherActor) ovelaped with weapon and WeaponState is "EWS_Pickup"
	if ((WeaponState == EWeaponState::enEWS_PickUp) && OtherActor)
	{
		//here we are Converting overlapped actor to MainCharacter 
		//if it can be converted that mean MainCharacter overlapped not an enemies and etc.
		//otherwise an enemies also could get a weapon ,but we added a Check	
		AMainCharacter* Main = Cast<AMainCharacter>(OtherActor);
		if (Main) //and if its  a MainCharacter
		{
			//sets a wepon to the ActiveOvelappingItem.NOTE:Doesn't sets to the EquipedWeapon
			Main->SetActiveOvelappingItem(this);

		}
	}
}
*/
/*
void  AWeapon::OverlapEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	Super::OverlapEnd(OverlappedComponent, OtherActor, OtherComp, OtherBodyIndex);

	AMainCharacter* Main = Cast<AMainCharacter>(OtherActor);
	if (Main) //and if its  a MainCharacter
	{

		Main->SetActiveOvelappingItem(nullptr);

	}
}
*/
/*
//picks up a weapon 
void  AWeapon::Equip(AMainCharacter* Character)
{
	if (Character)
	{
		//didit understand Recall lecture 59
		SkeletalMesh->SetCollisionResponseToChannel(ECollisionChannel::ECC_Camera, ECollisionResponse::ECR_Ignore);
		SkeletalMesh->SetCollisionResponseToChannel(ECollisionChannel::ECC_Pawn, ECollisionResponse::ECR_Ignore);
		//dosnt simulates physics
		SkeletalMesh->SetSimulatePhysics(false);

		const USkeletalMeshSocket* RightSocket = Character->GetMesh()->GetSocketByName("RightHandSocket");

		if (RightSocket)
		{
			//attaches actor to the socket(weapon)
			RightSocket->AttachActor(this, Character->GetMesh());
			//it doesnt rorates when we pick up a weapon
			bRotate = false;

			//destroys an old weapon
			Character->GetEquippedWeapon()->Destroy();

			//sets a weapon of this class to the main character
			Character->SetEquippedWeapon(this);
			Character->SetActiveOvelappingItem(nullptr);
		}
		//plays a sound when we pick up a weapon
		if (OnEquipedSound)
			UGameplayStatics::PlaySound2D(this, OnEquipedSound);
		//its deactivets a particle effects on the weapon if you set it "true" in the editor
		if (bWeaponParticle == true)
		{
			//"IdleParticlesComponent" is a variable from parent class "Item"
			//if in the editer you set it to "true" then when you pick up a weapon the particele effects will be off
			IdleParticlesComponent->Deactivate();
		}
	}
}

*/