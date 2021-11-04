// Fill out your copyright notice in the Description page of Project Settings.


#include "MovingPlatform_Rotatable.h"
#include "Components/SceneComponent.h"
AMovingPlatform_Rotatable::AMovingPlatform_Rotatable() {

	PitchVal = 0.f;
    YawVal = 0.f;
	RollVal = 0.f;

}
void AMovingPlatform_Rotatable::BeginPlay() {
	Super::BeginPlay();
	
	



}

void AMovingPlatform_Rotatable::Tick(float DeltaTime) {


	Super::Tick(DeltaTime);
    //class	UStaticMeshComponent* Meshh=GetMesh();
	//FRotator NewRotation = Meshh->GetComponentRotation();

	// NewRotation.Pitch += PitchValue;
	// NewRotation.Yaw += YawValue;
	 //NewRotation.Roll += RollValue;

	 //SetActorRotation(NewRotation);

	//FQuat QuatRotation = FQuat(NewRotation);

	//AddActorLocalRotation(QuatRotation, false, 0, ETeleportType::None);

	//Rotates an object
	FQuat QuatRotation = FRotator(PitchVal, YawVal, RollVal).Quaternion();
	AddActorLocalRotation(QuatRotation, false, 0, ETeleportType::None);

	
	


}