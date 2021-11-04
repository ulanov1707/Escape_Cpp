// Fill out your copyright notice in the Description page of Project Settings.


#include "MainAnimInstance.h"
#include"GameFramework/CharacterMovementComponent.h"
#include"MainCharacter.h"


void  UMainAnimInstance::NativeInitializeAnimation()
{
	//cheacks wether Pawn is noy assigned  (will be true at first time)
	if (Pawn == nullptr)
	{
		//will try to get owner of AnimationInstace
		Pawn = TryGetPawnOwner();
		//for sprinting
		if (Main)
		{
			Main = Cast<AMainCharacter>(Pawn);
		}
	}

	
}

void UMainAnimInstance::UpdateAniamtionProperties()
{

	if (Pawn == nullptr)
	{

		Pawn = TryGetPawnOwner();
	}

	if (Pawn)
	{
		//retuns a speed of  Pawn at particular frame
		FVector Speed = Pawn->GetVelocity();
		FVector HorizontalSpeed = FVector(Speed.X, Speed.Y, 0.f);
		//returns a lenght(magnitude) of vector
		MovementSpeed = HorizontalSpeed.Size();

		//IsFalling()-return true if object is  falling and false ,if it is not
		bIsInAir = Pawn->GetMovementComponent()->IsFalling();

		//for spriting 
		if (Main == nullptr)
		{
			Main = Cast<AMainCharacter>(Pawn);
		}

	}

}
