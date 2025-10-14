#pragma once

namespace Offsets {
    namespace Il2CppObject {
        constexpr const static size_t klass = 0x0;
        constexpr const static size_t monitor = 0x8;
    }

    namespace Il2CppClass {
        constexpr const static size_t name = 0x10;
        constexpr const static size_t namespaze = 0x18;
        constexpr const static size_t byval_arg = 0x20;
        constexpr const static size_t parent = 0x58;
        constexpr const static size_t static_fields = 0xB8;
        constexpr const static size_t typeHierarchy = 0xC8;
        constexpr const static size_t typeHierarchyDepth = 0x120;
    }

    namespace BaseMovement {
        constexpr const static size_t TargetMovement = 0x3C;
        constexpr const static size_t Grounded = 0x54;
    }

    namespace PlayerWalkMovement {
        constexpr const static size_t groundTime = 0x110;
        constexpr const static size_t jumpTime = 0x118;
        constexpr const static size_t landTime = 0x120;
        constexpr const static size_t groundAngleNew = 0x108;
        constexpr const static size_t nextSprintTime = 0x198;
    }

    namespace ConsoleSystem_Option {
        constexpr const static size_t IsFromServer = 0x7;
    }

    namespace Projectile {
        constexpr const static size_t projectileID = 0x128;
    }
}