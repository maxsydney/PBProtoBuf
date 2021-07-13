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
#ifndef ONEWIREBUSMESSAGING_H
#define ONEWIREBUSMESSAGING_H

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


class TemperatureDataMessage final: public ::EmbeddedProto::MessageInterface
{
  public:
    TemperatureDataMessage() = default;
    TemperatureDataMessage(const TemperatureDataMessage& rhs )
    {
      set_headTemp(rhs.get_headTemp());
      set_refluxCondensorTemp(rhs.get_refluxCondensorTemp());
      set_prodCondensorTemp(rhs.get_prodCondensorTemp());
      set_radiatorTemp(rhs.get_radiatorTemp());
      set_boilerTemp(rhs.get_boilerTemp());
    }

    TemperatureDataMessage(const TemperatureDataMessage&& rhs ) noexcept
    {
      set_headTemp(rhs.get_headTemp());
      set_refluxCondensorTemp(rhs.get_refluxCondensorTemp());
      set_prodCondensorTemp(rhs.get_prodCondensorTemp());
      set_radiatorTemp(rhs.get_radiatorTemp());
      set_boilerTemp(rhs.get_boilerTemp());
    }

    ~TemperatureDataMessage() override = default;

    enum class id : uint32_t
    {
      NOT_SET = 0,
      HEADTEMP = 1,
      REFLUXCONDENSORTEMP = 2,
      PRODCONDENSORTEMP = 3,
      RADIATORTEMP = 4,
      BOILERTEMP = 5
    };

    TemperatureDataMessage& operator=(const TemperatureDataMessage& rhs)
    {
      set_headTemp(rhs.get_headTemp());
      set_refluxCondensorTemp(rhs.get_refluxCondensorTemp());
      set_prodCondensorTemp(rhs.get_prodCondensorTemp());
      set_radiatorTemp(rhs.get_radiatorTemp());
      set_boilerTemp(rhs.get_boilerTemp());
      return *this;
    }

    TemperatureDataMessage& operator=(const TemperatureDataMessage&& rhs) noexcept
    {
      set_headTemp(rhs.get_headTemp());
      set_refluxCondensorTemp(rhs.get_refluxCondensorTemp());
      set_prodCondensorTemp(rhs.get_prodCondensorTemp());
      set_radiatorTemp(rhs.get_radiatorTemp());
      set_boilerTemp(rhs.get_boilerTemp());
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

    }

    private:

      EmbeddedProto::doublefixed headTemp_ = 0.0;
      EmbeddedProto::doublefixed refluxCondensorTemp_ = 0.0;
      EmbeddedProto::doublefixed prodCondensorTemp_ = 0.0;
      EmbeddedProto::doublefixed radiatorTemp_ = 0.0;
      EmbeddedProto::doublefixed boilerTemp_ = 0.0;

};

template<uint32_t sensors_REP_LENGTH, 
uint32_t sensors_romCode_LENGTH>
class DeviceDataMessage final: public ::EmbeddedProto::MessageInterface
{
  public:
    DeviceDataMessage() = default;
    DeviceDataMessage(const DeviceDataMessage& rhs )
    {
      set_sensors(rhs.get_sensors());
    }

    DeviceDataMessage(const DeviceDataMessage&& rhs ) noexcept
    {
      set_sensors(rhs.get_sensors());
    }

    ~DeviceDataMessage() override = default;

    enum class id : uint32_t
    {
      NOT_SET = 0,
      SENSORS = 1
    };

    DeviceDataMessage& operator=(const DeviceDataMessage& rhs)
    {
      set_sensors(rhs.get_sensors());
      return *this;
    }

    DeviceDataMessage& operator=(const DeviceDataMessage&& rhs) noexcept
    {
      set_sensors(rhs.get_sensors());
      return *this;
    }

    inline const DS18B20SensorMessage<sensors_romCode_LENGTH>& sensors(uint32_t index) const { return sensors_[index]; }
    inline void clear_sensors() { sensors_.clear(); }
    inline void set_sensors(uint32_t index, const DS18B20SensorMessage<sensors_romCode_LENGTH>& value) { sensors_.set(index, value); }
    inline void set_sensors(uint32_t index, const DS18B20SensorMessage<sensors_romCode_LENGTH>&& value) { sensors_.set(index, value); }
    inline void set_sensors(const ::EmbeddedProto::RepeatedFieldFixedSize<DS18B20SensorMessage<sensors_romCode_LENGTH>, sensors_REP_LENGTH>& values) { sensors_ = values; }
    inline void add_sensors(const DS18B20SensorMessage<sensors_romCode_LENGTH>& value) { sensors_.add(value); }
    inline ::EmbeddedProto::RepeatedFieldFixedSize<DS18B20SensorMessage<sensors_romCode_LENGTH>, sensors_REP_LENGTH>& mutable_sensors() { return sensors_; }
    inline DS18B20SensorMessage<sensors_romCode_LENGTH>& mutable_sensors(uint32_t index) { return sensors_[index]; }
    inline const ::EmbeddedProto::RepeatedFieldFixedSize<DS18B20SensorMessage<sensors_romCode_LENGTH>, sensors_REP_LENGTH>& get_sensors() const { return sensors_; }
    inline const ::EmbeddedProto::RepeatedFieldFixedSize<DS18B20SensorMessage<sensors_romCode_LENGTH>, sensors_REP_LENGTH>& sensors() const { return sensors_; }


    ::EmbeddedProto::Error serialize(::EmbeddedProto::WriteBufferInterface& buffer) const override
    {
      ::EmbeddedProto::Error return_value = ::EmbeddedProto::Error::NO_ERRORS;

      if(::EmbeddedProto::Error::NO_ERRORS == return_value)
      {
        return_value = sensors_.serialize_with_id(static_cast<uint32_t>(id::SENSORS), buffer);
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
          case id::SENSORS:
            return_value = sensors_.deserialize_check_type(buffer, wire_type);
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
      clear_sensors();

    }

    private:

      ::EmbeddedProto::RepeatedFieldFixedSize<DS18B20SensorMessage<sensors_romCode_LENGTH>, sensors_REP_LENGTH> sensors_;

};

#endif // ONEWIREBUSMESSAGING_H