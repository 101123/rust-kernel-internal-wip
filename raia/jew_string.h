#pragma once

template <typename T, size_t N>
class jew_string {
public:
    consteval jew_string( const T( &string )[ N ] ) {
        int32_t idx = 0;

        for ( int32_t i = 0; i < N - 1; i++ ) {
            T c = string[ i ];

            // If we have an ascii character, remap to jew range
            if ( c < 0x80 ) {
                uint32_t uc = c + 0x590;

                data_[ idx++ ] = ( char )( 0xc0 + ( uc >> 6 ) );
                data_[ idx++ ] = ( char )( 0x80 + ( uc & 0x3f ) );
            }

            else {
                data_[ idx++ ] = c;
            }
        }

        // Add null terminator
        data_[ idx++ ] = ( T )'\0';
    }

    const T* data() {
        return ( const T* )data_;
    };

private:
    // TODO: Compute actual required size
    char data_[ N * 5 ] = {};
};

#define J( String ) \
    ([]() -> auto { \
        static jew_string string( String ); \
        return string.data(); \
    }())