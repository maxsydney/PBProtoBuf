#include "Writable.h"

void Writable::clear()
{
  _writeIndex = 0;
}

uint32_t Writable::get_size() const
{
  return _writeIndex;
}

uint32_t Writable::get_max_size() const
{
  return MAX_SIZE;
}

uint32_t Writable::get_available_size() const
{
  return MAX_SIZE - _writeIndex;
}

bool Writable::push(const uint8_t byte)
{
  bool return_value = MAX_SIZE > _writeIndex;
  if(return_value)
  {
    _buffer[_writeIndex] = byte;
    ++_writeIndex;
  }
  return return_value;
}

bool Writable::push(const uint8_t* bytes, const uint32_t length)
{
  bool return_value = MAX_SIZE > (_writeIndex + length);
  if(return_value)
  {
    memcpy(_buffer + _writeIndex, bytes, length);
    _writeIndex += length;
  }
  return return_value;
}