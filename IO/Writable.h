#ifndef PBPROTOBUF_IO_WRITABLE
#define PBPROTOBUF_IO_WRITABLE

#include "WriteBufferInterface.h"
#include <cstddef>
#include <cstring>

class Writable : public EmbeddedProto::WriteBufferInterface
{
    public:
        Writable() = default;
        ~Writable() = default;

        //! Delete all data in the buffer.
        void clear();

        //! Obtain the total number of bytes currently stored in the buffer.
        uint32_t get_size() const;

        //! Obtain the total number of bytes which can at most be stored in the buffer.
        uint32_t get_max_size() const;

        //! Obtain the total number of bytes still available in the buffer.
        uint32_t get_available_size() const;

        //! Push a single byte into the buffer.
        /*!
            \param[in] byte The data to append after previously added data in the buffer.
            \return True when there was space to add the byte.
        */
        bool push(const uint8_t byte);

        //! Push an array of bytes into the buffer.
        /*!
            The given array will be appended after already addded data in the buffer.
            \param[in] bytes Pointer to the array of bytes.
            \param[in] length The number of bytes in the array.
            \return True when there was space to add the bytes.
        */
        bool push(const uint8_t* bytes, const uint32_t length);

        // Get the buffer
        const uint8_t* get_buffer(void) const { return _buffer; }

    private:

        static constexpr size_t MAX_SIZE = 1024; 
        uint8_t _buffer[MAX_SIZE] {};
        uint32_t _writeIndex = 0;
};

#endif // PBPROTOBUF_IO_WRITABLE