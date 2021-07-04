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
#ifndef CONTROLLERMESSAGING_H
#define CONTROLLERMESSAGING_H

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


class ControllerStateMessage final: public ::EmbeddedProto::MessageInterface
{
  public:
    ControllerStateMessage() = default;
    ControllerStateMessage(const ControllerStateMessage& rhs )
    {
      set_propOutput(rhs.get_propOutput());
      set_integralOutput(rhs.get_integralOutput());
      set_derivOutput(rhs.get_derivOutput());
      set_totalOutput(rhs.get_totalOutput());
    }

    ControllerStateMessage(const ControllerStateMessage&& rhs ) noexcept
    {
      set_propOutput(rhs.get_propOutput());
      set_integralOutput(rhs.get_integralOutput());
      set_derivOutput(rhs.get_derivOutput());
      set_totalOutput(rhs.get_totalOutput());
    }

    ~ControllerStateMessage() override = default;

    enum class id : uint32_t
    {
      NOT_SET = 0,
      PROPOUTPUT = 1,
      INTEGRALOUTPUT = 2,
      DERIVOUTPUT = 3,
      TOTALOUTPUT = 4
    };

    ControllerStateMessage& operator=(const ControllerStateMessage& rhs)
    {
      set_propOutput(rhs.get_propOutput());
      set_integralOutput(rhs.get_integralOutput());
      set_derivOutput(rhs.get_derivOutput());
      set_totalOutput(rhs.get_totalOutput());
      return *this;
    }

    ControllerStateMessage& operator=(const ControllerStateMessage&& rhs) noexcept
    {
      set_propOutput(rhs.get_propOutput());
      set_integralOutput(rhs.get_integralOutput());
      set_derivOutput(rhs.get_derivOutput());
      set_totalOutput(rhs.get_totalOutput());
      return *this;
    }

    inline void clear_propOutput() { propOutput_.clear(); }
    inline void set_propOutput(const EmbeddedProto::doublefixed& value) { propOutput_ = value; }
    inline void set_propOutput(const EmbeddedProto::doublefixed&& value) { propOutput_ = value; }
    inline EmbeddedProto::doublefixed& mutable_propOutput() { return propOutput_; }
    inline const EmbeddedProto::doublefixed& get_propOutput() const { return propOutput_; }
    inline EmbeddedProto::doublefixed::FIELD_TYPE propOutput() const { return propOutput_.get(); }

    inline void clear_integralOutput() { integralOutput_.clear(); }
    inline void set_integralOutput(const EmbeddedProto::doublefixed& value) { integralOutput_ = value; }
    inline void set_integralOutput(const EmbeddedProto::doublefixed&& value) { integralOutput_ = value; }
    inline EmbeddedProto::doublefixed& mutable_integralOutput() { return integralOutput_; }
    inline const EmbeddedProto::doublefixed& get_integralOutput() const { return integralOutput_; }
    inline EmbeddedProto::doublefixed::FIELD_TYPE integralOutput() const { return integralOutput_.get(); }

    inline void clear_derivOutput() { derivOutput_.clear(); }
    inline void set_derivOutput(const EmbeddedProto::doublefixed& value) { derivOutput_ = value; }
    inline void set_derivOutput(const EmbeddedProto::doublefixed&& value) { derivOutput_ = value; }
    inline EmbeddedProto::doublefixed& mutable_derivOutput() { return derivOutput_; }
    inline const EmbeddedProto::doublefixed& get_derivOutput() const { return derivOutput_; }
    inline EmbeddedProto::doublefixed::FIELD_TYPE derivOutput() const { return derivOutput_.get(); }

    inline void clear_totalOutput() { totalOutput_.clear(); }
    inline void set_totalOutput(const EmbeddedProto::doublefixed& value) { totalOutput_ = value; }
    inline void set_totalOutput(const EmbeddedProto::doublefixed&& value) { totalOutput_ = value; }
    inline EmbeddedProto::doublefixed& mutable_totalOutput() { return totalOutput_; }
    inline const EmbeddedProto::doublefixed& get_totalOutput() const { return totalOutput_; }
    inline EmbeddedProto::doublefixed::FIELD_TYPE totalOutput() const { return totalOutput_.get(); }


    ::EmbeddedProto::Error serialize(::EmbeddedProto::WriteBufferInterface& buffer) const override
    {
      ::EmbeddedProto::Error return_value = ::EmbeddedProto::Error::NO_ERRORS;

      if((0.0 != propOutput_.get()) && (::EmbeddedProto::Error::NO_ERRORS == return_value))
      {
        return_value = propOutput_.serialize_with_id(static_cast<uint32_t>(id::PROPOUTPUT), buffer);
      }

      if((0.0 != integralOutput_.get()) && (::EmbeddedProto::Error::NO_ERRORS == return_value))
      {
        return_value = integralOutput_.serialize_with_id(static_cast<uint32_t>(id::INTEGRALOUTPUT), buffer);
      }

      if((0.0 != derivOutput_.get()) && (::EmbeddedProto::Error::NO_ERRORS == return_value))
      {
        return_value = derivOutput_.serialize_with_id(static_cast<uint32_t>(id::DERIVOUTPUT), buffer);
      }

      if((0.0 != totalOutput_.get()) && (::EmbeddedProto::Error::NO_ERRORS == return_value))
      {
        return_value = totalOutput_.serialize_with_id(static_cast<uint32_t>(id::TOTALOUTPUT), buffer);
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
          case id::PROPOUTPUT:
            return_value = propOutput_.deserialize_check_type(buffer, wire_type);
            break;

          case id::INTEGRALOUTPUT:
            return_value = integralOutput_.deserialize_check_type(buffer, wire_type);
            break;

          case id::DERIVOUTPUT:
            return_value = derivOutput_.deserialize_check_type(buffer, wire_type);
            break;

          case id::TOTALOUTPUT:
            return_value = totalOutput_.deserialize_check_type(buffer, wire_type);
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
      clear_propOutput();
      clear_integralOutput();
      clear_derivOutput();
      clear_totalOutput();

    }

    private:

      EmbeddedProto::doublefixed propOutput_ = 0.0;
      EmbeddedProto::doublefixed integralOutput_ = 0.0;
      EmbeddedProto::doublefixed derivOutput_ = 0.0;
      EmbeddedProto::doublefixed totalOutput_ = 0.0;

};

#endif // CONTROLLERMESSAGING_H