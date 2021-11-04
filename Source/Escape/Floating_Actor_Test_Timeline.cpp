// Fill out your copyright notice in the Description page of Project Settings.


#include "Floating_Actor_Test_Timeline.h"
#include"Components/TimelineComponent.h"

// Sets default values
AFloating_Actor_Test_Timeline::AFloating_Actor_Test_Timeline()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}



// Called when the game starts or when spawned
void AFloating_Actor_Test_Timeline::BeginPlay()
{
	Super::BeginPlay();

	if (CurveFloat)//if CurveFloat assigned
	{
		//binds a  function to delegate (basically to access a "TimelineProgress" function we need to use "TProgress")
		TProgress.BindUFunction(this, FName("TimelineProgress"));
		//same as above
		TFinished.BindUFunction(this, FName("OnTimelineFinished"));


		//Binds a curve with function.Take value from curve and pass value(alpha) 
		//the delegate TProgress which is actually our function "TimelineProgress"
		Timeline.AddInterpFloat(CurveFloat, TProgress,FName("alpha"));

		//when timeline finished calls "TFinished" which is deleagte to our OnTimelineFinised()
		//we dont need it for now , but you can call it if u need 
		//Timeline.SetTimelineFinishedFunc(TFinished);

		//looping of timeline
		Timeline.SetLooping(true);
		

		StartLoc = EndLoc = GetActorLocation();
		EndLoc.Z += ZOffset;

		Timeline.PlayFromStart();

		//you can use this one as well
		//Timeline.Play();

	}
}

// Called every frame
void AFloating_Actor_Test_Timeline::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	Timeline.TickTimeline(DeltaTime);//passing delta time to a Timeline

}

void AFloating_Actor_Test_Timeline::TimelineProgress(float Value)//Update function
{
	FVector NewLoc = FMath::Lerp(StartLoc, EndLoc, Value);
	SetActorLocation(NewLoc);
}

//when Timeline Finished
void AFloating_Actor_Test_Timeline::OnTimelineFinised()
{
	//if the timline currently at the begining not at the Finish 
	if (Timeline.GetPlaybackPosition() == 0.0f)
	{
		//pplays from start
		Timeline.PlayFromStart();
	}
	//GetTimelineLength() gives a time of last node of Curve which is logically the EndPoint of curve
	else if(Timeline.GetPlaybackPosition()==Timeline.GetTimelineLength())
	{
		//plays Reverse
		Timeline.Reverse();
	}
	
}
