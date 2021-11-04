// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "MainAnimInstance.generated.h"

/**
 * 
 */
UCLASS()
class ESCAPE_API UMainAnimInstance : public UAnimInstance
{
	GENERATED_BODY()

public:
		//kind of a constuctor , inherited from UAnimInstance class
		virtual void NativeInitializeAnimation() override;

	//this function in the Unreal in blueprint pannel, we will connect to a "Event Blueprint Updete Animation" which works every frame
	//so our function will be called every frame 
	UFUNCTION(BlueprintCallable, Category = AnimationProperties)
		void UpdateAniamtionProperties();

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Movement)
		float MovementSpeed;


	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Movement)
		bool bIsInAir;//checks if the character in the air or not

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Movement)
		class APawn* Pawn;//refenence to Pawn(didnt really understand) Recall lecure 39

		//we added a MainCharacter because we need to get some varibales from Main like :MovementStatus etc.
		//and access them in the blueprint to set for sprinting soe animation 
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Movement)
		class  AMainCharacter* Main;

	//UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Movement)
		//bool Dead;
	
};
