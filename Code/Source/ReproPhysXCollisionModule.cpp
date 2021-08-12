
#include <AzCore/Memory/SystemAllocator.h>
#include <AzCore/Module/Module.h>

#include "ReproPhysXCollisionSystemComponent.h"

namespace ReproPhysXCollision
{
    class ReproPhysXCollisionModule
        : public AZ::Module
    {
    public:
        AZ_RTTI(ReproPhysXCollisionModule, "{2627e6b9-fe0b-48e5-91f7-8a1820ec8ba3}", AZ::Module);
        AZ_CLASS_ALLOCATOR(ReproPhysXCollisionModule, AZ::SystemAllocator, 0);

        ReproPhysXCollisionModule()
            : AZ::Module()
        {
            // Push results of [MyComponent]::CreateDescriptor() into m_descriptors here.
            m_descriptors.insert(m_descriptors.end(), {
                ReproPhysXCollisionSystemComponent::CreateDescriptor(),
            });
        }

        /**
         * Add required SystemComponents to the SystemEntity.
         */
        AZ::ComponentTypeList GetRequiredSystemComponents() const override
        {
            return AZ::ComponentTypeList{
                azrtti_typeid<ReproPhysXCollisionSystemComponent>(),
            };
        }
    };
}// namespace ReproPhysXCollision

AZ_DECLARE_MODULE_CLASS(Gem_ReproPhysXCollision, ReproPhysXCollision::ReproPhysXCollisionModule)
