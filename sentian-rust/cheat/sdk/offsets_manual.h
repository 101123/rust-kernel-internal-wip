#pragma once

namespace Offsets {
    namespace Il2CppObject {
        constexpr const static size_t klass = 0x0;
    }

    namespace Il2CppClass {
        constexpr const static size_t name = 0x10;
        constexpr const static size_t namespaze = 0x18;
        constexpr const static size_t byval_arg = 0x20;
        constexpr const static size_t parent = 0x58;
        constexpr const static size_t static_fields = 0xB8;
    }

    namespace BaseMovement {
        constexpr const static size_t TargetMovement = 0x3C;
    }

    namespace IProto {
        constexpr const static size_t WriteToStreamDelta_vtableoff = 0x1B8;
        constexpr const static size_t WriteToStream_vtableoff = 0x1E8;
    }
}