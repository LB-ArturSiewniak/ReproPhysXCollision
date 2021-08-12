
#pragma once

#include <AzCore/Component/Component.h>

#include <ReproPhysXCollision/ReproPhysXCollisionBus.h>

namespace ReproPhysXCollision
{
    class ReproPhysXCollisionSystemComponent
        : public AZ::Component
        , protected ReproPhysXCollisionRequestBus::Handler
    {
    public:
        AZ_COMPONENT(ReproPhysXCollisionSystemComponent, "{3faff566-7365-4fd2-b7ce-05b55b15fa9d}");

        static void Reflect(AZ::ReflectContext* context);

        static void GetProvidedServices(AZ::ComponentDescriptor::DependencyArrayType& provided);
        static void GetIncompatibleServices(AZ::ComponentDescriptor::DependencyArrayType& incompatible);
        static void GetRequiredServices(AZ::ComponentDescriptor::DependencyArrayType& required);
        static void GetDependentServices(AZ::ComponentDescriptor::DependencyArrayType& dependent);

        ReproPhysXCollisionSystemComponent();
        ~ReproPhysXCollisionSystemComponent();

    protected:
        ////////////////////////////////////////////////////////////////////////
        // ReproPhysXCollisionRequestBus interface implementation

        ////////////////////////////////////////////////////////////////////////

        ////////////////////////////////////////////////////////////////////////
        // AZ::Component interface implementation
        void Init() override;
        void Activate() override;
        void Deactivate() override;
        ////////////////////////////////////////////////////////////////////////
    };
}
