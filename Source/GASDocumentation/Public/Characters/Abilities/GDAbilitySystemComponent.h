// Copyright 2019 Dan Kestranek.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemComponent.h"
#include "GDAbilitySystemComponent.generated.h"

/*NOTE
* FGameplayAbilityInputBinds REQUIRED a Correct Enum Name to bind to correctly. With a wrong enum name you will crash AFTER successfully binding input because unreal cannot find the enum in 
* it's reflection system. If you do not have editor symbols installed it will give you a shit callstack, but the crash will come from
* UEnum* GetBindEnum() { return FindObject<UEnum>(ANY_PACKAGE, *EnumName); } 
* because it cannot find the enum listed.
*/

DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FReceivedDamageDelegate, UGDAbilitySystemComponent*, SourceASC, float, UnmitigatedDamage, float, MitigatedDamage);

/**
 * 
 */
UCLASS()
class GASDOCUMENTATION_API UGDAbilitySystemComponent : public UAbilitySystemComponent
{
	GENERATED_BODY()
	
public:
	bool CharacterAbilitiesGiven = false;
	bool StartupEffectsApplied = false;

	FReceivedDamageDelegate ReceivedDamage;

	// Called from GDDamageExecCalculation. Broadcasts on ReceivedDamage whenever this ASC receives damage.
	virtual void ReceiveDamage(UGDAbilitySystemComponent* SourceASC, float UnmitigatedDamage, float MitigatedDamage);
};
