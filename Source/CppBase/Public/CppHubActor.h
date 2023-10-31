// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CppHubActor.generated.h"

class ACppBaseActor;

UCLASS()
class CPPBASE_API ACppHubActor : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ACppHubActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	// Сначала нам необходимо создать две переменные, которые будут отвечать
	// за частоту срабатывания таймера в секундах, и мы сделаем их доступной в Blueprints
	UPROPERTY(EditAnywhere)
	float SpawnTimerRate = 2.0f;

	UPROPERTY(EditAnywhere)
	float DestroyTimerRate = 1.0f;


	//Далее нам необходимо объявить несколько дескрипторов таймера,
	// которые будут хранить информацию о своих таймерах.
	// Через данные переменные, мы будем иметь возможность манипулировать таймерами.

	FTimerHandle SpawnTimerHandle;
	FTimerHandle DestroyTimerHandle;

	// Теперь нам нужно объявить методы, которые будут вызываться при срабатывании таймера.

	void OnTimeToSpawn();
	void OnTimeToDestroy();

	// Массив объектов, который мы будем заполнять по мере спауна новых объектов
	UPROPERTY()
	TArray<ACppBaseActor*> SpawnedObjects;

	UPROPERTY(EditAnywhere)
	TSubclassOf<ACppBaseActor> CppClass;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	const int32 TotalTimerCount = 10; //данная переменная будет хранить информацию о максимальной количестве срабатываний таймера
	int32 CurrentTimerCount = 0; //текущее число срабатываний
};
