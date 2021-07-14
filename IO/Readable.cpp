#include "Readable.h"

Readable::Readable()
  : data_{0},
    write_index_(0),
    read_index_(0)
{

}

uint32_t Readable::get_size() const
{
  return write_index_;
}

uint32_t Readable::get_max_size() const
{
  return MAX_SIZE;
}

bool Readable::peek(uint8_t& byte) const
{
  bool return_value = write_index_ > read_index_;
  if(return_value)
  {
    byte = data_[read_index_];
  }
  return return_value;
}

void Readable::advance()
{
  ++read_index_;
}

void Readable::advance(const uint32_t N)
{
  read_index_ += N;
}

bool Readable::pop(uint8_t& byte)
{
  bool return_value = write_index_ > read_index_;
  if(return_value) {
    byte = data_[read_index_];
    ++read_index_;
  }
  return return_value;
}

uint8_t* Readable::get_data_array()
{
  return data_;
}

uint32_t& Readable::get_bytes_written()
{
  return write_index_;
}

void Readable::clear()
{
  read_index_ = 0;
  write_index_ = 0;
}

bool Readable::push(uint8_t& byte)
{
  bool return_value = MAX_SIZE > write_index_;
  if(return_value)
  {
    data_[write_index_] = byte;
    ++write_index_;
  }
  return return_value;
}