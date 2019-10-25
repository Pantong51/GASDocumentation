// Copyright 2019 Dan Kestranek.


#include "GDAbilitySystemComponent.h"

/*NOTE
* FGameplayAbilityInputBinds REQUIRED a Correct Enum Name to bind to correctly. With a wrong enum name you will crash AFTER successfully binding input because unreal cannot find the enum in 
* it's reflection system. If you do not have editor symbols installed it will give you a shit callstack, but the crash will come from
* UEnum* GetBindEnum() { return FindObject<UEnum>(ANY_PACKAGE, *EnumName); } 
* because it cannot find the enum listed.
*/

void UGDAbilitySystemComponent::ReceiveDamage(UGDAbilitySystemComponent * SourceASC, float UnmitigatedDamage, float MitigatedDamage)
{
	ReceivedDamage.Broadcast(SourceASC, UnmitigatedDamage, MitigatedDamage);
}
