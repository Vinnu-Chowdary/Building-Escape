// Fill out your copyright notice in the Description page of Project Settings.


#include "OpenDoor.h"

#include "GameFramework/Actor.h"

// Sets default values for this component's properties
UOpenDoor::UOpenDoor()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts 
void UOpenDoor::BeginPlay()
{
	Super::BeginPlay();
	Owner = GetOwner();       // Getting the Owning Door.
	ActorThatOpens = GetWorld()->GetFirstPlayerController()->GetPawn();
	
	
}

void UOpenDoor::OpenDoor()
{
	Owner->SetActorRotation(FRotator(0.f, OpenAngle, 0.f));
}

void UOpenDoor::CloseDoor()
{
	Owner->SetActorRotation(FRotator(0.f, 0.f, 0.f));
}

// Called every frame
void UOpenDoor::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// Poll the Trigger Volume (Check) For Every Frame 
	// If the ActorThantOpeens is in the volume 
	if (PressurePlate->IsOverlappingActor(ActorThatOpens))
	{
		OpenDoor();
		LastDoorOpenedTime = GetWorld()->GetTimeSeconds();
	}
	if (GetWorld()->GetTimeSeconds() - LastDoorOpenedTime > DoorClosingDelay)
	{
		CloseDoor();
	}
	
	// Check If it is Time to close the Door :: 


}

