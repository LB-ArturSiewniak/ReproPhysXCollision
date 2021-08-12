
#include <AzCore/Serialization/SerializeContext.h>
#include <AzCore/Serialization/EditContext.h>
#include <AzCore/Serialization/EditContextConstants.inl>

#include "ReproPhysXCollisionSystemComponent.h"

namespace ReproPhysXCollision
{
    void ReproPhysXCollisionSystemComponent::Reflect(AZ::ReflectContext* context)
    {
        if (AZ::SerializeContext* serialize = azrtti_cast<AZ::SerializeContext*>(context))
        {
            serialize->Class<ReproPhysXCollisionSystemComponent, AZ::Component>()
                ->Version(0)
                ;

            if (AZ::EditContext* ec = serialize->GetEditContext())
            {
                ec->Class<ReproPhysXCollisionSystemComponent>("ReproPhysXCollision", "[Description of functionality provided by this System Component]")
                    ->ClassElement(AZ::Edit::ClassElements::EditorData, "")
                        ->Attribute(AZ::Edit::Attributes::AppearsInAddComponentMenu, AZ_CRC("System"))
                        ->Attribute(AZ::Edit::Attributes::AutoExpand, true)
                    ;
            }
        }
    }

    void ReproPhysXCollisionSystemComponent::GetProvidedServices(AZ::ComponentDescriptor::DependencyArrayType& provided)
    {
        provided.push_back(AZ_CRC("ReproPhysXCollisionService"));
    }

    void ReproPhysXCollisionSystemComponent::GetIncompatibleServices(AZ::ComponentDescriptor::DependencyArrayType& incompatible)
    {
        incompatible.push_back(AZ_CRC("ReproPhysXCollisionService"));
    }

    void ReproPhysXCollisionSystemComponent::GetRequiredServices([[maybe_unused]] AZ::ComponentDescriptor::DependencyArrayType& required)
    {
    }

    void ReproPhysXCollisionSystemComponent::GetDependentServices([[maybe_unused]] AZ::ComponentDescriptor::DependencyArrayType& dependent)
    {
    }
    
    ReproPhysXCollisionSystemComponent::ReproPhysXCollisionSystemComponent()
    {
        if (ReproPhysXCollisionInterface::Get() == nullptr)
        {
            ReproPhysXCollisionInterface::Register(this);
        }
    }

    ReproPhysXCollisionSystemComponent::~ReproPhysXCollisionSystemComponent()
    {
        if (ReproPhysXCollisionInterface::Get() == this)
        {
            ReproPhysXCollisionInterface::Unregister(this);
        }
    }

    void ReproPhysXCollisionSystemComponent::Init()
    {
    }

    void ReproPhysXCollisionSystemComponent::Activate()
    {
        ReproPhysXCollisionRequestBus::Handler::BusConnect();
    }

    void ReproPhysXCollisionSystemComponent::Deactivate()
    {
        ReproPhysXCollisionRequestBus::Handler::BusDisconnect();
    }
}
