/*
 *  Copyright (C) 2020 Embedded AMS B.V. - All Rights Reserved
 *
 *  This file is part of Embedded Proto.
 *
 *  Embedded Proto is open source software: you can redistribute it and/or
 *  modify it under the terms of the GNU General Public License as published
 *  by the Free Software Foundation, version 3 of the license.
 *
 *  Embedded Proto  is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with Embedded Proto. If not, see <https://www.gnu.org/licenses/>.
 *
 *  For commercial and closed source application please visit:
 *  <https://EmbeddedProto.com/license/>.
 *
 *  Embedded AMS B.V.
 *  Info:
 *    info at EmbeddedProto dot com
 *
 *  Postal address:
 *    Johan Huizingalaan 763a
 *    1066 VH, Amsterdam
 *    the Netherlands
 */

// This file is generated. Please do not edit!
#ifndef DS18B20MESSAGING_H
#define DS18B20MESSAGING_H

#include <cstdint>
#include <MessageInterface.h>
#include <WireFormatter.h>
#include <Fields.h>
#include <MessageSizeCalculator.h>
#include <ReadBufferSection.h>
#include <RepeatedFieldFixedSize.h>
#include <FieldStringBytes.h>
#include <Errors.h>

// Include external proto definitions


enum class DS18B20Role : uint32_t
{
  NONE = 0,
  HEAD_TEMP = 1,
  REFLUX_TEMP = 2,
  PRODUCT_TEMP = 3,
  RADIATOR_TEMP = 4,
  BOILER_TEMP = 5
};

template<uint32_t romCode_LENGTH>
class DS18B20Sensor final: public ::EmbeddedProto::MessageInterface
{
  public:
    DS18B20Sensor() = default;
    DS18B20Sensor(const DS18B20Sensor& rhs )
    {
      set_romCode(rhs.get_romCode());
      set_calibLinear(rhs.get_calibLinear());
      set_calibOffset(rhs.get_calibOffset());
    }

    DS18B20Sensor(const DS18B20Sensor&& rhs ) noexcept
    {
      set_romCode(rhs.get_romCode());
      set_calibLinear(rhs.get_calibLinear());
      set_calibOffset(rhs.get_calibOffset());
    }

    ~DS18B20Sensor() override = default;

    enum class id : uint32_t
    {
      NOT_SET = 0,
      ROMCODE = 1,
      CALIBLINEAR = 2,
      CALIBOFFSET = 3
    };

    DS18B20Sensor& operator=(const DS18B20Sensor& rhs)
    {
      set_romCode(rhs.get_romCode());
      set_calibLinear(rhs.get_calibLinear());
      set_calibOffset(rhs.get_calibOffset());
      return *this;
    }

    DS18B20Sensor& operator=(const DS18B20Sensor&& rhs) noexcept
    {
      set_romCode(rhs.get_romCode());
      set_calibLinear(rhs.get_calibLinear());
      set_calibOffset(rhs.get_calibOffset());
      return *this;
    }

    inline void clear_romCode() { romCode_.clear(); }
    inline ::EmbeddedProto::FieldBytes<romCode_LENGTH>& mutable_romCode() { return romCode_; }
    inline void set_romCode(const ::EmbeddedProto::FieldBytes<romCode_LENGTH>& rhs) { romCode_.set(rhs); }
    inline const ::EmbeddedProto::FieldBytes<romCode_LENGTH>& get_romCode() const { return romCode_; }
    inline const uint8_t* romCode() const { return romCode_.get_const(); }

    inline void clear_calibLinear() { calibLinear_.clear(); }
    inline void set_calibLinear(const EmbeddedProto::doublefixed& value) { calibLinear_ = value; }
    inline void set_calibLinear(const EmbeddedProto::doublefixed&& value) { calibLinear_ = value; }
    inline EmbeddedProto::doublefixed& mutable_calibLinear() { return calibLinear_; }
    inline const EmbeddedProto::doublefixed& get_calibLinear() const { return calibLinear_; }
    inline EmbeddedProto::doublefixed::FIELD_TYPE calibLinear() const { return calibLinear_.get(); }

    inline void clear_calibOffset() { calibOffset_.clear(); }
    inline void set_calibOffset(const EmbeddedProto::doublefixed& value) { calibOffset_ = value; }
    inline void set_calibOffset(const EmbeddedProto::doublefixed&& value) { calibOffset_ = value; }
    inline EmbeddedProto::doublefixed& mutable_calibOffset() { return calibOffset_; }
    inline const EmbeddedProto::doublefixed& get_calibOffset() const { return calibOffset_; }
    inline EmbeddedProto::doublefixed::FIELD_TYPE calibOffset() const { return calibOffset_.get(); }


    ::EmbeddedProto::Error serialize(::EmbeddedProto::WriteBufferInterface& buffer) const override
    {
      ::EmbeddedProto::Error return_value = ::EmbeddedProto::Error::NO_ERRORS;

      if(::EmbeddedProto::Error::NO_ERRORS == return_value)
      {
        return_value = romCode_.serialize_with_id(static_cast<uint32_t>(id::ROMCODE), buffer);
      }

      if((0.0 != calibLinear_.get()) && (::EmbeddedProto::Error::NO_ERRORS == return_value))
      {
        return_value = calibLinear_.serialize_with_id(static_cast<uint32_t>(id::CALIBLINEAR), buffer);
      }

      if((0.0 != calibOffset_.get()) && (::EmbeddedProto::Error::NO_ERRORS == return_value))
      {
        return_value = calibOffset_.serialize_with_id(static_cast<uint32_t>(id::CALIBOFFSET), buffer);
      }

      return return_value;
    };

    ::EmbeddedProto::Error deserialize(::EmbeddedProto::ReadBufferInterface& buffer) override
    {
      ::EmbeddedProto::Error return_value = ::EmbeddedProto::Error::NO_ERRORS;
      ::EmbeddedProto::WireFormatter::WireType wire_type = ::EmbeddedProto::WireFormatter::WireType::VARINT;
      uint32_t id_number = 0;
      id id_tag = id::NOT_SET;

      ::EmbeddedProto::Error tag_value = ::EmbeddedProto::WireFormatter::DeserializeTag(buffer, wire_type, id_number);
      while((::EmbeddedProto::Error::NO_ERRORS == return_value) && (::EmbeddedProto::Error::NO_ERRORS == tag_value))
      {
        id_tag = static_cast<id>(id_number);
        switch(id_tag)
        {
          case id::ROMCODE:
            return_value = romCode_.deserialize_check_type(buffer, wire_type);
            break;

          case id::CALIBLINEAR:
            return_value = calibLinear_.deserialize_check_type(buffer, wire_type);
            break;

          case id::CALIBOFFSET:
            return_value = calibOffset_.deserialize_check_type(buffer, wire_type);
            break;

          default:
            break;
        }

        if(::EmbeddedProto::Error::NO_ERRORS == return_value)
        {
          // Read the next tag.
          tag_value = ::EmbeddedProto::WireFormatter::DeserializeTag(buffer, wire_type, id_number);
        }
      }

      // When an error was detect while reading the tag but no other errors where found, set it in the return value.
      if((::EmbeddedProto::Error::NO_ERRORS == return_value)
         && (::EmbeddedProto::Error::NO_ERRORS != tag_value)
         && (::EmbeddedProto::Error::END_OF_BUFFER != tag_value)) // The end of the buffer is not an array in this case.
      {
        return_value = tag_value;
      }

      return return_value;
    };

    void clear() override
    {
      clear_romCode();
      clear_calibLinear();
      clear_calibOffset();

    }

    private:

      ::EmbeddedProto::FieldBytes<romCode_LENGTH> romCode_;
      EmbeddedProto::doublefixed calibLinear_ = 0.0;
      EmbeddedProto::doublefixed calibOffset_ = 0.0;

};

#endif // DS18B20MESSAGING_H