#ifndef PBPROTOBUF_IO_READABLE
#define PBPROTOBUF_IO_READABLE

#include <ReadBufferInterface.h>

class Readable : public ::EmbeddedProto::ReadBufferInterface
{
    //! Store a maximum of MAX_SIZE bytes in the buffer
    static constexpr uint32_t MAX_SIZE = 128;

  public:
    Readable();
    ~Readable() override = default;

    /** \see ::EmbeddedProto::ReadBufferInterface::get_size() */
    uint32_t get_size() const override;

    /** \see ::EmbeddedProto::ReadBufferInterface::get_max_size() */
    uint32_t get_max_size() const override;

    /** \see ::EmbeddedProto::ReadBufferInterface::peak() */
    bool peek(uint8_t& byte) const override;

    /** \see ::EmbeddedProto::ReadBufferInterface::advance() */
    void advance() override;

    /** \see ::EmbeddedProto::ReadBufferInterface::advance(const uint32_t N) */
    void advance(const uint32_t N) override;

    /** \see ::EmbeddedProto::ReadBufferInterface::pop() */
    bool pop(uint8_t& byte) override;

    //! Return a pointer to the data array
    uint8_t* get_data_array();

    //! Return a non constant reference to the number of bytes written to the data array.
    uint32_t& get_bytes_written();

    //! Clear all indices, in effect allowing the data to be overwritten.
    void clear();

    //! Push new data into the buffer.
    bool push(const uint8_t& byte);

  private:

    //! The array in which the data received over uart is stored.
    uint8_t data_[MAX_SIZE];

    //! The number of bytes currently received and stored in the data array.
    uint32_t write_index_;

    //! The number of bytes read from the data array.
    uint32_t read_index_;
};

#endif // PBPROTOBUF_IO_READABLE