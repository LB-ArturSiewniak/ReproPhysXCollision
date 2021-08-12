
#pragma once

#include <AzCore/EBus/EBus.h>
#include <AzCore/Interface/Interface.h>

namespace ReproPhysXCollision
{
    class ReproPhysXCollisionRequests
    {
    public:
        AZ_RTTI(ReproPhysXCollisionRequests, "{c16e6322-3e87-4a28-ad76-c5c0652b34b2}");
        virtual ~ReproPhysXCollisionRequests() = default;
        // Put your public methods here
    };
    
    class ReproPhysXCollisionBusTraits
        : public AZ::EBusTraits
    {
    public:
        //////////////////////////////////////////////////////////////////////////
        // EBusTraits overrides
        static constexpr AZ::EBusHandlerPolicy HandlerPolicy = AZ::EBusHandlerPolicy::Single;
        static constexpr AZ::EBusAddressPolicy AddressPolicy = AZ::EBusAddressPolicy::Single;
        //////////////////////////////////////////////////////////////////////////
    };

    using ReproPhysXCollisionRequestBus = AZ::EBus<ReproPhysXCollisionRequests, ReproPhysXCollisionBusTraits>;
    using ReproPhysXCollisionInterface = AZ::Interface<ReproPhysXCollisionRequests>;

} // namespace ReproPhysXCollision
