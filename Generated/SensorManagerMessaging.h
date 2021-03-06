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
#ifndef SENSORMANAGERMESSAGING_H
#define SENSORMANAGERMESSAGING_H

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
#include <DS18B20Messaging.h>


enum class SensorManagerCmdType : uint32_t
{
  CMD_NONE = 0,
  CMD_BROADCAST_SENSORS = 1
};

class SensorManagerCommandMessage final: public ::EmbeddedProto::MessageInterface
{
  public:
    SensorManagerCommandMessage() = default;
    SensorManagerCommandMessage(const SensorManagerCommandMessage& rhs )
    {
      set_cmdType(rhs.get_cmdType());
    }

    SensorManagerCommandMessage(const SensorManagerCommandMessage&& rhs ) noexcept
    {
      set_cmdType(rhs.get_cmdType());
    }

    ~SensorManagerCommandMessage() override = default;

    enum class id : uint32_t
    {
      NOT_SET = 0,
      CMDTYPE = 1
    };

    SensorManagerCommandMessage& operator=(const SensorManagerCommandMessage& rhs)
    {
      set_cmdType(rhs.get_cmdType());
      return *this;
    }

    SensorManagerCommandMessage& operator=(const SensorManagerCommandMessage&& rhs) noexcept
    {
      set_cmdType(rhs.get_cmdType());
      return *this;
    }

    inline void clear_cmdType() { cmdType_ = static_cast<SensorManagerCmdType>(0); }
    inline void set_cmdType(const SensorManagerCmdType& value) { cmdType_ = value; }
    inline void set_cmdType(const SensorManagerCmdType&& value) { cmdType_ = value; }
    inline const SensorManagerCmdType& get_cmdType() const { return cmdType_; }
    inline SensorManagerCmdType cmdType() const { return cmdType_; }


    ::EmbeddedProto::Error serialize(::EmbeddedProto::WriteBufferInterface& buffer) const override
    {
      ::EmbeddedProto::Error return_value = ::EmbeddedProto::Error::NO_ERRORS;

      if((static_cast<SensorManagerCmdType>(0) != cmdType_) && (::EmbeddedProto::Error::NO_ERRORS == return_value))
      {
        EmbeddedProto::uint32 value = 0;
        value.set(static_cast<uint32_t>(cmdType_));
        return_value = value.serialize_with_id(static_cast<uint32_t>(id::CMDTYPE), buffer);
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
          case id::CMDTYPE:
            if(::EmbeddedProto::WireFormatter::WireType::VARINT == wire_type)
            {
              uint32_t value = 0;
              return_value = ::EmbeddedProto::WireFormatter::DeserializeVarint(buffer, value);
              if(::EmbeddedProto::Error::NO_ERRORS == return_value)
              {
                set_cmdType(static_cast<SensorManagerCmdType>(value));
              }
            }
            else
            {
              // Wire type does not match field.
              return_value = ::EmbeddedProto::Error::INVALID_WIRETYPE;
            }
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
      clear_cmdType();

    }

    private:

      SensorManagerCmdType cmdType_ = static_cast<SensorManagerCmdType>(0);

};

class FlowrateData final: public ::EmbeddedProto::MessageInterface
{
  public:
    FlowrateData() = default;
    FlowrateData(const FlowrateData& rhs )
    {
      set_refluxFlowrate(rhs.get_refluxFlowrate());
      set_productFlowrate(rhs.get_productFlowrate());
    }

    FlowrateData(const FlowrateData&& rhs ) noexcept
    {
      set_refluxFlowrate(rhs.get_refluxFlowrate());
      set_productFlowrate(rhs.get_productFlowrate());
    }

    ~FlowrateData() override = default;

    enum class id : uint32_t
    {
      NOT_SET = 0,
      REFLUXFLOWRATE = 1,
      PRODUCTFLOWRATE = 2
    };

    FlowrateData& operator=(const FlowrateData& rhs)
    {
      set_refluxFlowrate(rhs.get_refluxFlowrate());
      set_productFlowrate(rhs.get_productFlowrate());
      return *this;
    }

    FlowrateData& operator=(const FlowrateData&& rhs) noexcept
    {
      set_refluxFlowrate(rhs.get_refluxFlowrate());
      set_productFlowrate(rhs.get_productFlowrate());
      return *this;
    }

    inline void clear_refluxFlowrate() { refluxFlowrate_.clear(); }
    inline void set_refluxFlowrate(const EmbeddedProto::doublefixed& value) { refluxFlowrate_ = value; }
    inline void set_refluxFlowrate(const EmbeddedProto::doublefixed&& value) { refluxFlowrate_ = value; }
    inline EmbeddedProto::doublefixed& mutable_refluxFlowrate() { return refluxFlowrate_; }
    inline const EmbeddedProto::doublefixed& get_refluxFlowrate() const { return refluxFlowrate_; }
    inline EmbeddedProto::doublefixed::FIELD_TYPE refluxFlowrate() const { return refluxFlowrate_.get(); }

    inline void clear_productFlowrate() { productFlowrate_.clear(); }
    inline void set_productFlowrate(const EmbeddedProto::doublefixed& value) { productFlowrate_ = value; }
    inline void set_productFlowrate(const EmbeddedProto::doublefixed&& value) { productFlowrate_ = value; }
    inline EmbeddedProto::doublefixed& mutable_productFlowrate() { return productFlowrate_; }
    inline const EmbeddedProto::doublefixed& get_productFlowrate() const { return productFlowrate_; }
    inline EmbeddedProto::doublefixed::FIELD_TYPE productFlowrate() const { return productFlowrate_.get(); }


    ::EmbeddedProto::Error serialize(::EmbeddedProto::WriteBufferInterface& buffer) const override
    {
      ::EmbeddedProto::Error return_value = ::EmbeddedProto::Error::NO_ERRORS;

      if((0.0 != refluxFlowrate_.get()) && (::EmbeddedProto::Error::NO_ERRORS == return_value))
      {
        return_value = refluxFlowrate_.serialize_with_id(static_cast<uint32_t>(id::REFLUXFLOWRATE), buffer);
      }

      if((0.0 != productFlowrate_.get()) && (::EmbeddedProto::Error::NO_ERRORS == return_value))
      {
        return_value = productFlowrate_.serialize_with_id(static_cast<uint32_t>(id::PRODUCTFLOWRATE), buffer);
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
          case id::REFLUXFLOWRATE:
            return_value = refluxFlowrate_.deserialize_check_type(buffer, wire_type);
            break;

          case id::PRODUCTFLOWRATE:
            return_value = productFlowrate_.deserialize_check_type(buffer, wire_type);
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
      clear_refluxFlowrate();
      clear_productFlowrate();

    }

    private:

      EmbeddedProto::doublefixed refluxFlowrate_ = 0.0;
      EmbeddedProto::doublefixed productFlowrate_ = 0.0;

};

class ConcentrationData final: public ::EmbeddedProto::MessageInterface
{
  public:
    ConcentrationData() = default;
    ConcentrationData(const ConcentrationData& rhs )
    {
      set_vapourConcentration(rhs.get_vapourConcentration());
      set_boilerConcentration(rhs.get_boilerConcentration());
    }

    ConcentrationData(const ConcentrationData&& rhs ) noexcept
    {
      set_vapourConcentration(rhs.get_vapourConcentration());
      set_boilerConcentration(rhs.get_boilerConcentration());
    }

    ~ConcentrationData() override = default;

    enum class id : uint32_t
    {
      NOT_SET = 0,
      VAPOURCONCENTRATION = 1,
      BOILERCONCENTRATION = 2
    };

    ConcentrationData& operator=(const ConcentrationData& rhs)
    {
      set_vapourConcentration(rhs.get_vapourConcentration());
      set_boilerConcentration(rhs.get_boilerConcentration());
      return *this;
    }

    ConcentrationData& operator=(const ConcentrationData&& rhs) noexcept
    {
      set_vapourConcentration(rhs.get_vapourConcentration());
      set_boilerConcentration(rhs.get_boilerConcentration());
      return *this;
    }

    inline void clear_vapourConcentration() { vapourConcentration_.clear(); }
    inline void set_vapourConcentration(const EmbeddedProto::doublefixed& value) { vapourConcentration_ = value; }
    inline void set_vapourConcentration(const EmbeddedProto::doublefixed&& value) { vapourConcentration_ = value; }
    inline EmbeddedProto::doublefixed& mutable_vapourConcentration() { return vapourConcentration_; }
    inline const EmbeddedProto::doublefixed& get_vapourConcentration() const { return vapourConcentration_; }
    inline EmbeddedProto::doublefixed::FIELD_TYPE vapourConcentration() const { return vapourConcentration_.get(); }

    inline void clear_boilerConcentration() { boilerConcentration_.clear(); }
    inline void set_boilerConcentration(const EmbeddedProto::doublefixed& value) { boilerConcentration_ = value; }
    inline void set_boilerConcentration(const EmbeddedProto::doublefixed&& value) { boilerConcentration_ = value; }
    inline EmbeddedProto::doublefixed& mutable_boilerConcentration() { return boilerConcentration_; }
    inline const EmbeddedProto::doublefixed& get_boilerConcentration() const { return boilerConcentration_; }
    inline EmbeddedProto::doublefixed::FIELD_TYPE boilerConcentration() const { return boilerConcentration_.get(); }


    ::EmbeddedProto::Error serialize(::EmbeddedProto::WriteBufferInterface& buffer) const override
    {
      ::EmbeddedProto::Error return_value = ::EmbeddedProto::Error::NO_ERRORS;

      if((0.0 != vapourConcentration_.get()) && (::EmbeddedProto::Error::NO_ERRORS == return_value))
      {
        return_value = vapourConcentration_.serialize_with_id(static_cast<uint32_t>(id::VAPOURCONCENTRATION), buffer);
      }

      if((0.0 != boilerConcentration_.get()) && (::EmbeddedProto::Error::NO_ERRORS == return_value))
      {
        return_value = boilerConcentration_.serialize_with_id(static_cast<uint32_t>(id::BOILERCONCENTRATION), buffer);
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
          case id::VAPOURCONCENTRATION:
            return_value = vapourConcentration_.deserialize_check_type(buffer, wire_type);
            break;

          case id::BOILERCONCENTRATION:
            return_value = boilerConcentration_.deserialize_check_type(buffer, wire_type);
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
      clear_vapourConcentration();
      clear_boilerConcentration();

    }

    private:

      EmbeddedProto::doublefixed vapourConcentration_ = 0.0;
      EmbeddedProto::doublefixed boilerConcentration_ = 0.0;

};

template<uint32_t address_LENGTH>
class AssignSensorCommand final: public ::EmbeddedProto::MessageInterface
{
  public:
    AssignSensorCommand() = default;
    AssignSensorCommand(const AssignSensorCommand& rhs )
    {
      set_role(rhs.get_role());
      set_address(rhs.get_address());
    }

    AssignSensorCommand(const AssignSensorCommand&& rhs ) noexcept
    {
      set_role(rhs.get_role());
      set_address(rhs.get_address());
    }

    ~AssignSensorCommand() override = default;

    enum class id : uint32_t
    {
      NOT_SET = 0,
      ROLE = 1,
      ADDRESS = 2
    };

    AssignSensorCommand& operator=(const AssignSensorCommand& rhs)
    {
      set_role(rhs.get_role());
      set_address(rhs.get_address());
      return *this;
    }

    AssignSensorCommand& operator=(const AssignSensorCommand&& rhs) noexcept
    {
      set_role(rhs.get_role());
      set_address(rhs.get_address());
      return *this;
    }

    inline void clear_role() { role_ = static_cast<DS18B20Role>(0); }
    inline void set_role(const DS18B20Role& value) { role_ = value; }
    inline void set_role(const DS18B20Role&& value) { role_ = value; }
    inline const DS18B20Role& get_role() const { return role_; }
    inline DS18B20Role role() const { return role_; }

    inline void clear_address() { address_.clear(); }
    inline ::EmbeddedProto::FieldBytes<address_LENGTH>& mutable_address() { return address_; }
    inline void set_address(const ::EmbeddedProto::FieldBytes<address_LENGTH>& rhs) { address_.set(rhs); }
    inline const ::EmbeddedProto::FieldBytes<address_LENGTH>& get_address() const { return address_; }
    inline const uint8_t* address() const { return address_.get_const(); }


    ::EmbeddedProto::Error serialize(::EmbeddedProto::WriteBufferInterface& buffer) const override
    {
      ::EmbeddedProto::Error return_value = ::EmbeddedProto::Error::NO_ERRORS;

      if((static_cast<DS18B20Role>(0) != role_) && (::EmbeddedProto::Error::NO_ERRORS == return_value))
      {
        EmbeddedProto::uint32 value = 0;
        value.set(static_cast<uint32_t>(role_));
        return_value = value.serialize_with_id(static_cast<uint32_t>(id::ROLE), buffer);
      }

      if(::EmbeddedProto::Error::NO_ERRORS == return_value)
      {
        return_value = address_.serialize_with_id(static_cast<uint32_t>(id::ADDRESS), buffer);
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
          case id::ROLE:
            if(::EmbeddedProto::WireFormatter::WireType::VARINT == wire_type)
            {
              uint32_t value = 0;
              return_value = ::EmbeddedProto::WireFormatter::DeserializeVarint(buffer, value);
              if(::EmbeddedProto::Error::NO_ERRORS == return_value)
              {
                set_role(static_cast<DS18B20Role>(value));
              }
            }
            else
            {
              // Wire type does not match field.
              return_value = ::EmbeddedProto::Error::INVALID_WIRETYPE;
            }
            break;

          case id::ADDRESS:
            return_value = address_.deserialize_check_type(buffer, wire_type);
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
      clear_role();
      clear_address();

    }

    private:

      DS18B20Role role_ = static_cast<DS18B20Role>(0);
      ::EmbeddedProto::FieldBytes<address_LENGTH> address_;

};

class TemperatureData final: public ::EmbeddedProto::MessageInterface
{
  public:
    TemperatureData() = default;
    TemperatureData(const TemperatureData& rhs )
    {
      set_headTemp(rhs.get_headTemp());
      set_refluxCondensorTemp(rhs.get_refluxCondensorTemp());
      set_prodCondensorTemp(rhs.get_prodCondensorTemp());
      set_radiatorTemp(rhs.get_radiatorTemp());
      set_boilerTemp(rhs.get_boilerTemp());
      set_timeStamp(rhs.get_timeStamp());
    }

    TemperatureData(const TemperatureData&& rhs ) noexcept
    {
      set_headTemp(rhs.get_headTemp());
      set_refluxCondensorTemp(rhs.get_refluxCondensorTemp());
      set_prodCondensorTemp(rhs.get_prodCondensorTemp());
      set_radiatorTemp(rhs.get_radiatorTemp());
      set_boilerTemp(rhs.get_boilerTemp());
      set_timeStamp(rhs.get_timeStamp());
    }

    ~TemperatureData() override = default;

    enum class id : uint32_t
    {
      NOT_SET = 0,
      HEADTEMP = 1,
      REFLUXCONDENSORTEMP = 2,
      PRODCONDENSORTEMP = 3,
      RADIATORTEMP = 4,
      BOILERTEMP = 5,
      TIMESTAMP = 6
    };

    TemperatureData& operator=(const TemperatureData& rhs)
    {
      set_headTemp(rhs.get_headTemp());
      set_refluxCondensorTemp(rhs.get_refluxCondensorTemp());
      set_prodCondensorTemp(rhs.get_prodCondensorTemp());
      set_radiatorTemp(rhs.get_radiatorTemp());
      set_boilerTemp(rhs.get_boilerTemp());
      set_timeStamp(rhs.get_timeStamp());
      return *this;
    }

    TemperatureData& operator=(const TemperatureData&& rhs) noexcept
    {
      set_headTemp(rhs.get_headTemp());
      set_refluxCondensorTemp(rhs.get_refluxCondensorTemp());
      set_prodCondensorTemp(rhs.get_prodCondensorTemp());
      set_radiatorTemp(rhs.get_radiatorTemp());
      set_boilerTemp(rhs.get_boilerTemp());
      set_timeStamp(rhs.get_timeStamp());
      return *this;
    }

    inline void clear_headTemp() { headTemp_.clear(); }
    inline void set_headTemp(const EmbeddedProto::doublefixed& value) { headTemp_ = value; }
    inline void set_headTemp(const EmbeddedProto::doublefixed&& value) { headTemp_ = value; }
    inline EmbeddedProto::doublefixed& mutable_headTemp() { return headTemp_; }
    inline const EmbeddedProto::doublefixed& get_headTemp() const { return headTemp_; }
    inline EmbeddedProto::doublefixed::FIELD_TYPE headTemp() const { return headTemp_.get(); }

    inline void clear_refluxCondensorTemp() { refluxCondensorTemp_.clear(); }
    inline void set_refluxCondensorTemp(const EmbeddedProto::doublefixed& value) { refluxCondensorTemp_ = value; }
    inline void set_refluxCondensorTemp(const EmbeddedProto::doublefixed&& value) { refluxCondensorTemp_ = value; }
    inline EmbeddedProto::doublefixed& mutable_refluxCondensorTemp() { return refluxCondensorTemp_; }
    inline const EmbeddedProto::doublefixed& get_refluxCondensorTemp() const { return refluxCondensorTemp_; }
    inline EmbeddedProto::doublefixed::FIELD_TYPE refluxCondensorTemp() const { return refluxCondensorTemp_.get(); }

    inline void clear_prodCondensorTemp() { prodCondensorTemp_.clear(); }
    inline void set_prodCondensorTemp(const EmbeddedProto::doublefixed& value) { prodCondensorTemp_ = value; }
    inline void set_prodCondensorTemp(const EmbeddedProto::doublefixed&& value) { prodCondensorTemp_ = value; }
    inline EmbeddedProto::doublefixed& mutable_prodCondensorTemp() { return prodCondensorTemp_; }
    inline const EmbeddedProto::doublefixed& get_prodCondensorTemp() const { return prodCondensorTemp_; }
    inline EmbeddedProto::doublefixed::FIELD_TYPE prodCondensorTemp() const { return prodCondensorTemp_.get(); }

    inline void clear_radiatorTemp() { radiatorTemp_.clear(); }
    inline void set_radiatorTemp(const EmbeddedProto::doublefixed& value) { radiatorTemp_ = value; }
    inline void set_radiatorTemp(const EmbeddedProto::doublefixed&& value) { radiatorTemp_ = value; }
    inline EmbeddedProto::doublefixed& mutable_radiatorTemp() { return radiatorTemp_; }
    inline const EmbeddedProto::doublefixed& get_radiatorTemp() const { return radiatorTemp_; }
    inline EmbeddedProto::doublefixed::FIELD_TYPE radiatorTemp() const { return radiatorTemp_.get(); }

    inline void clear_boilerTemp() { boilerTemp_.clear(); }
    inline void set_boilerTemp(const EmbeddedProto::doublefixed& value) { boilerTemp_ = value; }
    inline void set_boilerTemp(const EmbeddedProto::doublefixed&& value) { boilerTemp_ = value; }
    inline EmbeddedProto::doublefixed& mutable_boilerTemp() { return boilerTemp_; }
    inline const EmbeddedProto::doublefixed& get_boilerTemp() const { return boilerTemp_; }
    inline EmbeddedProto::doublefixed::FIELD_TYPE boilerTemp() const { return boilerTemp_.get(); }

    inline void clear_timeStamp() { timeStamp_.clear(); }
    inline void set_timeStamp(const EmbeddedProto::uint32& value) { timeStamp_ = value; }
    inline void set_timeStamp(const EmbeddedProto::uint32&& value) { timeStamp_ = value; }
    inline EmbeddedProto::uint32& mutable_timeStamp() { return timeStamp_; }
    inline const EmbeddedProto::uint32& get_timeStamp() const { return timeStamp_; }
    inline EmbeddedProto::uint32::FIELD_TYPE timeStamp() const { return timeStamp_.get(); }


    ::EmbeddedProto::Error serialize(::EmbeddedProto::WriteBufferInterface& buffer) const override
    {
      ::EmbeddedProto::Error return_value = ::EmbeddedProto::Error::NO_ERRORS;

      if((0.0 != headTemp_.get()) && (::EmbeddedProto::Error::NO_ERRORS == return_value))
      {
        return_value = headTemp_.serialize_with_id(static_cast<uint32_t>(id::HEADTEMP), buffer);
      }

      if((0.0 != refluxCondensorTemp_.get()) && (::EmbeddedProto::Error::NO_ERRORS == return_value))
      {
        return_value = refluxCondensorTemp_.serialize_with_id(static_cast<uint32_t>(id::REFLUXCONDENSORTEMP), buffer);
      }

      if((0.0 != prodCondensorTemp_.get()) && (::EmbeddedProto::Error::NO_ERRORS == return_value))
      {
        return_value = prodCondensorTemp_.serialize_with_id(static_cast<uint32_t>(id::PRODCONDENSORTEMP), buffer);
      }

      if((0.0 != radiatorTemp_.get()) && (::EmbeddedProto::Error::NO_ERRORS == return_value))
      {
        return_value = radiatorTemp_.serialize_with_id(static_cast<uint32_t>(id::RADIATORTEMP), buffer);
      }

      if((0.0 != boilerTemp_.get()) && (::EmbeddedProto::Error::NO_ERRORS == return_value))
      {
        return_value = boilerTemp_.serialize_with_id(static_cast<uint32_t>(id::BOILERTEMP), buffer);
      }

      if((0U != timeStamp_.get()) && (::EmbeddedProto::Error::NO_ERRORS == return_value))
      {
        return_value = timeStamp_.serialize_with_id(static_cast<uint32_t>(id::TIMESTAMP), buffer);
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
          case id::HEADTEMP:
            return_value = headTemp_.deserialize_check_type(buffer, wire_type);
            break;

          case id::REFLUXCONDENSORTEMP:
            return_value = refluxCondensorTemp_.deserialize_check_type(buffer, wire_type);
            break;

          case id::PRODCONDENSORTEMP:
            return_value = prodCondensorTemp_.deserialize_check_type(buffer, wire_type);
            break;

          case id::RADIATORTEMP:
            return_value = radiatorTemp_.deserialize_check_type(buffer, wire_type);
            break;

          case id::BOILERTEMP:
            return_value = boilerTemp_.deserialize_check_type(buffer, wire_type);
            break;

          case id::TIMESTAMP:
            return_value = timeStamp_.deserialize_check_type(buffer, wire_type);
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
      clear_headTemp();
      clear_refluxCondensorTemp();
      clear_prodCondensorTemp();
      clear_radiatorTemp();
      clear_boilerTemp();
      clear_timeStamp();

    }

    private:

      EmbeddedProto::doublefixed headTemp_ = 0.0;
      EmbeddedProto::doublefixed refluxCondensorTemp_ = 0.0;
      EmbeddedProto::doublefixed prodCondensorTemp_ = 0.0;
      EmbeddedProto::doublefixed radiatorTemp_ = 0.0;
      EmbeddedProto::doublefixed boilerTemp_ = 0.0;
      EmbeddedProto::uint32 timeStamp_ = 0U;

};

template<uint32_t addresses_REP_LENGTH, 
uint32_t addresses_LENGTH>
class DeviceData final: public ::EmbeddedProto::MessageInterface
{
  public:
    DeviceData() = default;
    DeviceData(const DeviceData& rhs )
    {
      set_addresses(rhs.get_addresses());
    }

    DeviceData(const DeviceData&& rhs ) noexcept
    {
      set_addresses(rhs.get_addresses());
    }

    ~DeviceData() override = default;

    enum class id : uint32_t
    {
      NOT_SET = 0,
      ADDRESSES = 1
    };

    DeviceData& operator=(const DeviceData& rhs)
    {
      set_addresses(rhs.get_addresses());
      return *this;
    }

    DeviceData& operator=(const DeviceData&& rhs) noexcept
    {
      set_addresses(rhs.get_addresses());
      return *this;
    }

    inline const ::EmbeddedProto::FieldBytes<addresses_LENGTH>& addresses(uint32_t index) const { return addresses_[index]; }
    inline void clear_addresses() { addresses_.clear(); }
    inline void set_addresses(uint32_t index, const ::EmbeddedProto::FieldBytes<addresses_LENGTH>& value) { addresses_.set(index, value); }
    inline void set_addresses(uint32_t index, const ::EmbeddedProto::FieldBytes<addresses_LENGTH>&& value) { addresses_.set(index, value); }
    inline void set_addresses(const ::EmbeddedProto::RepeatedFieldFixedSize<::EmbeddedProto::FieldBytes<addresses_LENGTH>, addresses_REP_LENGTH>& values) { addresses_ = values; }
    inline void add_addresses(const ::EmbeddedProto::FieldBytes<addresses_LENGTH>& value) { addresses_.add(value); }
    inline ::EmbeddedProto::RepeatedFieldFixedSize<::EmbeddedProto::FieldBytes<addresses_LENGTH>, addresses_REP_LENGTH>& mutable_addresses() { return addresses_; }
    inline ::EmbeddedProto::FieldBytes<addresses_LENGTH>& mutable_addresses(uint32_t index) { return addresses_[index]; }
    inline const ::EmbeddedProto::RepeatedFieldFixedSize<::EmbeddedProto::FieldBytes<addresses_LENGTH>, addresses_REP_LENGTH>& get_addresses() const { return addresses_; }
    inline const ::EmbeddedProto::RepeatedFieldFixedSize<::EmbeddedProto::FieldBytes<addresses_LENGTH>, addresses_REP_LENGTH>& addresses() const { return addresses_; }


    ::EmbeddedProto::Error serialize(::EmbeddedProto::WriteBufferInterface& buffer) const override
    {
      ::EmbeddedProto::Error return_value = ::EmbeddedProto::Error::NO_ERRORS;

      if(::EmbeddedProto::Error::NO_ERRORS == return_value)
      {
        return_value = addresses_.serialize_with_id(static_cast<uint32_t>(id::ADDRESSES), buffer);
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
          case id::ADDRESSES:
            return_value = addresses_.deserialize_check_type(buffer, wire_type);
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
      clear_addresses();

    }

    private:

      ::EmbeddedProto::RepeatedFieldFixedSize<::EmbeddedProto::FieldBytes<addresses_LENGTH>, addresses_REP_LENGTH> addresses_;

};

template<uint32_t headTempSensor_romCode_LENGTH, 
uint32_t refluxTempSensor_romCode_LENGTH, 
uint32_t productTempSensor_romCode_LENGTH, 
uint32_t radiatorTempSensor_romCode_LENGTH, 
uint32_t boilerTempSensor_romCode_LENGTH>
class AssignedSensorRegistry final: public ::EmbeddedProto::MessageInterface
{
  public:
    AssignedSensorRegistry() = default;
    AssignedSensorRegistry(const AssignedSensorRegistry& rhs )
    {
      set_headTempSensor(rhs.get_headTempSensor());
      set_refluxTempSensor(rhs.get_refluxTempSensor());
      set_productTempSensor(rhs.get_productTempSensor());
      set_radiatorTempSensor(rhs.get_radiatorTempSensor());
      set_boilerTempSensor(rhs.get_boilerTempSensor());
    }

    AssignedSensorRegistry(const AssignedSensorRegistry&& rhs ) noexcept
    {
      set_headTempSensor(rhs.get_headTempSensor());
      set_refluxTempSensor(rhs.get_refluxTempSensor());
      set_productTempSensor(rhs.get_productTempSensor());
      set_radiatorTempSensor(rhs.get_radiatorTempSensor());
      set_boilerTempSensor(rhs.get_boilerTempSensor());
    }

    ~AssignedSensorRegistry() override = default;

    enum class id : uint32_t
    {
      NOT_SET = 0,
      HEADTEMPSENSOR = 1,
      REFLUXTEMPSENSOR = 2,
      PRODUCTTEMPSENSOR = 3,
      RADIATORTEMPSENSOR = 4,
      BOILERTEMPSENSOR = 5
    };

    AssignedSensorRegistry& operator=(const AssignedSensorRegistry& rhs)
    {
      set_headTempSensor(rhs.get_headTempSensor());
      set_refluxTempSensor(rhs.get_refluxTempSensor());
      set_productTempSensor(rhs.get_productTempSensor());
      set_radiatorTempSensor(rhs.get_radiatorTempSensor());
      set_boilerTempSensor(rhs.get_boilerTempSensor());
      return *this;
    }

    AssignedSensorRegistry& operator=(const AssignedSensorRegistry&& rhs) noexcept
    {
      set_headTempSensor(rhs.get_headTempSensor());
      set_refluxTempSensor(rhs.get_refluxTempSensor());
      set_productTempSensor(rhs.get_productTempSensor());
      set_radiatorTempSensor(rhs.get_radiatorTempSensor());
      set_boilerTempSensor(rhs.get_boilerTempSensor());
      return *this;
    }

    inline void clear_headTempSensor() { headTempSensor_.clear(); }
    inline void set_headTempSensor(const DS18B20Sensor<headTempSensor_romCode_LENGTH>& value) { headTempSensor_ = value; }
    inline void set_headTempSensor(const DS18B20Sensor<headTempSensor_romCode_LENGTH>&& value) { headTempSensor_ = value; }
    inline DS18B20Sensor<headTempSensor_romCode_LENGTH>& mutable_headTempSensor() { return headTempSensor_; }
    inline const DS18B20Sensor<headTempSensor_romCode_LENGTH>& get_headTempSensor() const { return headTempSensor_; }
    inline const DS18B20Sensor<headTempSensor_romCode_LENGTH>& headTempSensor() const { return headTempSensor_; }

    inline void clear_refluxTempSensor() { refluxTempSensor_.clear(); }
    inline void set_refluxTempSensor(const DS18B20Sensor<refluxTempSensor_romCode_LENGTH>& value) { refluxTempSensor_ = value; }
    inline void set_refluxTempSensor(const DS18B20Sensor<refluxTempSensor_romCode_LENGTH>&& value) { refluxTempSensor_ = value; }
    inline DS18B20Sensor<refluxTempSensor_romCode_LENGTH>& mutable_refluxTempSensor() { return refluxTempSensor_; }
    inline const DS18B20Sensor<refluxTempSensor_romCode_LENGTH>& get_refluxTempSensor() const { return refluxTempSensor_; }
    inline const DS18B20Sensor<refluxTempSensor_romCode_LENGTH>& refluxTempSensor() const { return refluxTempSensor_; }

    inline void clear_productTempSensor() { productTempSensor_.clear(); }
    inline void set_productTempSensor(const DS18B20Sensor<productTempSensor_romCode_LENGTH>& value) { productTempSensor_ = value; }
    inline void set_productTempSensor(const DS18B20Sensor<productTempSensor_romCode_LENGTH>&& value) { productTempSensor_ = value; }
    inline DS18B20Sensor<productTempSensor_romCode_LENGTH>& mutable_productTempSensor() { return productTempSensor_; }
    inline const DS18B20Sensor<productTempSensor_romCode_LENGTH>& get_productTempSensor() const { return productTempSensor_; }
    inline const DS18B20Sensor<productTempSensor_romCode_LENGTH>& productTempSensor() const { return productTempSensor_; }

    inline void clear_radiatorTempSensor() { radiatorTempSensor_.clear(); }
    inline void set_radiatorTempSensor(const DS18B20Sensor<radiatorTempSensor_romCode_LENGTH>& value) { radiatorTempSensor_ = value; }
    inline void set_radiatorTempSensor(const DS18B20Sensor<radiatorTempSensor_romCode_LENGTH>&& value) { radiatorTempSensor_ = value; }
    inline DS18B20Sensor<radiatorTempSensor_romCode_LENGTH>& mutable_radiatorTempSensor() { return radiatorTempSensor_; }
    inline const DS18B20Sensor<radiatorTempSensor_romCode_LENGTH>& get_radiatorTempSensor() const { return radiatorTempSensor_; }
    inline const DS18B20Sensor<radiatorTempSensor_romCode_LENGTH>& radiatorTempSensor() const { return radiatorTempSensor_; }

    inline void clear_boilerTempSensor() { boilerTempSensor_.clear(); }
    inline void set_boilerTempSensor(const DS18B20Sensor<boilerTempSensor_romCode_LENGTH>& value) { boilerTempSensor_ = value; }
    inline void set_boilerTempSensor(const DS18B20Sensor<boilerTempSensor_romCode_LENGTH>&& value) { boilerTempSensor_ = value; }
    inline DS18B20Sensor<boilerTempSensor_romCode_LENGTH>& mutable_boilerTempSensor() { return boilerTempSensor_; }
    inline const DS18B20Sensor<boilerTempSensor_romCode_LENGTH>& get_boilerTempSensor() const { return boilerTempSensor_; }
    inline const DS18B20Sensor<boilerTempSensor_romCode_LENGTH>& boilerTempSensor() const { return boilerTempSensor_; }


    ::EmbeddedProto::Error serialize(::EmbeddedProto::WriteBufferInterface& buffer) const override
    {
      ::EmbeddedProto::Error return_value = ::EmbeddedProto::Error::NO_ERRORS;

      if(::EmbeddedProto::Error::NO_ERRORS == return_value)
      {
        return_value = headTempSensor_.serialize_with_id(static_cast<uint32_t>(id::HEADTEMPSENSOR), buffer);
      }

      if(::EmbeddedProto::Error::NO_ERRORS == return_value)
      {
        return_value = refluxTempSensor_.serialize_with_id(static_cast<uint32_t>(id::REFLUXTEMPSENSOR), buffer);
      }

      if(::EmbeddedProto::Error::NO_ERRORS == return_value)
      {
        return_value = productTempSensor_.serialize_with_id(static_cast<uint32_t>(id::PRODUCTTEMPSENSOR), buffer);
      }

      if(::EmbeddedProto::Error::NO_ERRORS == return_value)
      {
        return_value = radiatorTempSensor_.serialize_with_id(static_cast<uint32_t>(id::RADIATORTEMPSENSOR), buffer);
      }

      if(::EmbeddedProto::Error::NO_ERRORS == return_value)
      {
        return_value = boilerTempSensor_.serialize_with_id(static_cast<uint32_t>(id::BOILERTEMPSENSOR), buffer);
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
          case id::HEADTEMPSENSOR:
            return_value = headTempSensor_.deserialize_check_type(buffer, wire_type);
            break;

          case id::REFLUXTEMPSENSOR:
            return_value = refluxTempSensor_.deserialize_check_type(buffer, wire_type);
            break;

          case id::PRODUCTTEMPSENSOR:
            return_value = productTempSensor_.deserialize_check_type(buffer, wire_type);
            break;

          case id::RADIATORTEMPSENSOR:
            return_value = radiatorTempSensor_.deserialize_check_type(buffer, wire_type);
            break;

          case id::BOILERTEMPSENSOR:
            return_value = boilerTempSensor_.deserialize_check_type(buffer, wire_type);
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
      clear_headTempSensor();
      clear_refluxTempSensor();
      clear_productTempSensor();
      clear_radiatorTempSensor();
      clear_boilerTempSensor();

    }

    private:

      DS18B20Sensor<headTempSensor_romCode_LENGTH> headTempSensor_;
      DS18B20Sensor<refluxTempSensor_romCode_LENGTH> refluxTempSensor_;
      DS18B20Sensor<productTempSensor_romCode_LENGTH> productTempSensor_;
      DS18B20Sensor<radiatorTempSensor_romCode_LENGTH> radiatorTempSensor_;
      DS18B20Sensor<boilerTempSensor_romCode_LENGTH> boilerTempSensor_;

};

#endif // SENSORMANAGERMESSAGING_H