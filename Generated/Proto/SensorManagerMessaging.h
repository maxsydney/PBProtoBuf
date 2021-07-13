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
#ifndef PROTO_SENSORMANAGERMESSAGING_H
#define PROTO_SENSORMANAGERMESSAGING_H

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
#include <Proto/DS18B20Messaging.h>


enum class SensorManagerCmdType : uint32_t
{
  CMD_NONE = 0,
  CMD_BROADCAST_SENSORS = 2
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

class ConcentrationDataMessage final: public ::EmbeddedProto::MessageInterface
{
  public:
    ConcentrationDataMessage() = default;
    ConcentrationDataMessage(const ConcentrationDataMessage& rhs )
    {
      set_vapourConcentration(rhs.get_vapourConcentration());
      set_boilerConcentration(rhs.get_boilerConcentration());
    }

    ConcentrationDataMessage(const ConcentrationDataMessage&& rhs ) noexcept
    {
      set_vapourConcentration(rhs.get_vapourConcentration());
      set_boilerConcentration(rhs.get_boilerConcentration());
    }

    ~ConcentrationDataMessage() override = default;

    enum class id : uint32_t
    {
      NOT_SET = 0,
      VAPOURCONCENTRATION = 1,
      BOILERCONCENTRATION = 2
    };

    ConcentrationDataMessage& operator=(const ConcentrationDataMessage& rhs)
    {
      set_vapourConcentration(rhs.get_vapourConcentration());
      set_boilerConcentration(rhs.get_boilerConcentration());
      return *this;
    }

    ConcentrationDataMessage& operator=(const ConcentrationDataMessage&& rhs) noexcept
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

template<uint32_t sensor_romCode_LENGTH>
class AssignSensorCommand final: public ::EmbeddedProto::MessageInterface
{
  public:
    AssignSensorCommand() = default;
    AssignSensorCommand(const AssignSensorCommand& rhs )
    {
      set_sensor(rhs.get_sensor());
    }

    AssignSensorCommand(const AssignSensorCommand&& rhs ) noexcept
    {
      set_sensor(rhs.get_sensor());
    }

    ~AssignSensorCommand() override = default;

    enum class id : uint32_t
    {
      NOT_SET = 0,
      SENSOR = 1
    };

    AssignSensorCommand& operator=(const AssignSensorCommand& rhs)
    {
      set_sensor(rhs.get_sensor());
      return *this;
    }

    AssignSensorCommand& operator=(const AssignSensorCommand&& rhs) noexcept
    {
      set_sensor(rhs.get_sensor());
      return *this;
    }

    inline void clear_sensor() { sensor_.clear(); }
    inline void set_sensor(const DS18B20SensorMessage<sensor_romCode_LENGTH>& value) { sensor_ = value; }
    inline void set_sensor(const DS18B20SensorMessage<sensor_romCode_LENGTH>&& value) { sensor_ = value; }
    inline DS18B20SensorMessage<sensor_romCode_LENGTH>& mutable_sensor() { return sensor_; }
    inline const DS18B20SensorMessage<sensor_romCode_LENGTH>& get_sensor() const { return sensor_; }
    inline const DS18B20SensorMessage<sensor_romCode_LENGTH>& sensor() const { return sensor_; }


    ::EmbeddedProto::Error serialize(::EmbeddedProto::WriteBufferInterface& buffer) const override
    {
      ::EmbeddedProto::Error return_value = ::EmbeddedProto::Error::NO_ERRORS;

      if(::EmbeddedProto::Error::NO_ERRORS == return_value)
      {
        return_value = sensor_.serialize_with_id(static_cast<uint32_t>(id::SENSOR), buffer);
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
          case id::SENSOR:
            return_value = sensor_.deserialize_check_type(buffer, wire_type);
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
      clear_sensor();

    }

    private:

      DS18B20SensorMessage<sensor_romCode_LENGTH> sensor_;

};

#endif // PROTO_SENSORMANAGERMESSAGING_H