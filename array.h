#include <cstdio>
#include <initializer_list>

namespace vurm
{
    template <typename Type>
    class array
    {
        public:
        array ( ) { ; }
        array ( unsigned size );
        array ( unsigned size, std::initializer_list<Type> list );
        ~array ( )
        {
            delete [ ] _ptr;
        };
        const unsigned size ( );
        bool reinitialize ( unsigned size );
        bool reinitialize ( unsigned size, std::initializer_list<Type> list );
        Type* begin ( );
        Type* end ( );
        // For testing:
        void _print ( );

        protected:
        unsigned _size = 0U;
        bool _is_initialized = false;
        Type* _ptr = nullptr; // main pointer for the actual data
        inline bool initialize ( unsigned size );
        inline bool deinitialize ( );
    };

    template <typename Type>
    array<Type>::array ( unsigned size )
    {
        if ( initialize ( size ) )
            ; // todo: catch exception
    }

    template <typename Type>
    array<Type>::array ( unsigned size, std::initializer_list<Type> list )
    {
        if ( initialize ( size ) )
            ; // todo: catch exception
        for ( int _i = 0; _i < size; _i++ )
        {
            *( _ptr + _i ) = *( list.begin ( ) + _i );
        }
    }

    /// @brief Returns the actual size of the array
    /// @return size of array
    template <typename Type>
    const unsigned array<Type>::size ( )
    {
        return _size;
    }

    template <typename Type>
    inline bool array<Type>::initialize ( unsigned size )
    {
        if ( !size )
        {
            ; // todo: exception when the user requests an array with a size of 0
            return true;
        }
        _ptr = new Type [ size ];
        if ( _ptr == nullptr )
        {
            ; // todo: exception when no more memory can be allocated for the new array
            return true;
        }
        _size = size;
        _is_initialized = true;
        return false;
    }

    template <typename Type>
    inline bool array<Type>::deinitialize ( )
    {
        if ( !_is_initialized )
            return true;
        delete [ ] _ptr;
        _size = 0U;
        _is_initialized = false;
        ; // todo: returns "true" when an exception is caught during memory release
        return false;
    }

    template <typename Type>
    bool array<Type>::reinitialize ( unsigned size )
    {
        deinitialize ( );
        return initialize ( size );
    }

    template <typename Type>
    bool array<Type>::reinitialize ( unsigned size, std::initializer_list<Type> list )
    {
        deinitialize ( );
        if ( initialize ( size ) )
        {
            for ( int _i = 0; _i < size; _i++ )
            {
                *( _ptr + _i ) = *( list.begin ( ) + _i );
            }
            return false;
        }
        return true;
    }

    template <typename Type>
    Type* array<Type>::begin ( )
    {
        return _ptr;
    }

    template <typename Type>
    Type* array<Type>::end ( )
    {
        if ( _is_initialized )
            return _ptr;
        return nullptr;
    }

    /// @brief Prints all elements in the array for testing purposes
    template <typename Type>
    void array<Type>::_print ( )
    {
        if ( _is_initialized && _size )
            for ( int _i = 0; _i < _size; _i++ )
                printf ( "%d ", *( _ptr + _i ) );
    }
} // namespace vurm
