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
#ifndef MESSAGEBASE_H
#define MESSAGEBASE_H

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


enum class PBMessageType : uint32_t
{
  Unknown = 0,
  General = 1,
  TemperatureData = 2,
  FlowrateData = 3,
  ControllerTuning = 4,
  ControllerCommand = 5,
  ControllerSettings = 6,
  ControllerDataRequest = 7,
  SensorManagerCommand = 8,
  DeviceData = 9,
  AssignSensor = 10,
  ConcentrationData = 11,
  ControllerState = 12,
  SocketLog = 13
};

template<uint32_t payload_LENGTH>
class MessageWrapper final: public ::EmbeddedProto::MessageInterface
{
  public:
    MessageWrapper() = default;
    MessageWrapper(const MessageWrapper& rhs )
    {
      set_type(rhs.get_type());
      set_timeStamp(rhs.get_timeStamp());
      set_payload(rhs.get_payload());
    }

    MessageWrapper(const MessageWrapper&& rhs ) noexcept
    {
      set_type(rhs.get_type());
      set_timeStamp(rhs.get_timeStamp());
      set_payload(rhs.get_payload());
    }

    ~MessageWrapper() override = default;

    enum class id : uint32_t
    {
      NOT_SET = 0,
      TYPE = 1,
      TIMESTAMP = 2,
      PAYLOAD = 3
    };

    MessageWrapper& operator=(const MessageWrapper& rhs)
    {
      set_type(rhs.get_type());
      set_timeStamp(rhs.get_timeStamp());
      set_payload(rhs.get_payload());
      return *this;
    }

    MessageWrapper& operator=(const MessageWrapper&& rhs) noexcept
    {
      set_type(rhs.get_type());
      set_timeStamp(rhs.get_timeStamp());
      set_payload(rhs.get_payload());
      return *this;
    }

    inline void clear_type() { type_ = static_cast<PBMessageType>(0); }
    inline void set_type(const PBMessageType& value) { type_ = value; }
    inline void set_type(const PBMessageType&& value) { type_ = value; }
    inline const PBMessageType& get_type() const { return type_; }
    inline PBMessageType type() const { return type_; }

    inline void clear_timeStamp() { timeStamp_.clear(); }
    inline void set_timeStamp(const EmbeddedProto::uint64& value) { timeStamp_ = value; }
    inline void set_timeStamp(const EmbeddedProto::uint64&& value) { timeStamp_ = value; }
    inline EmbeddedProto::uint64& mutable_timeStamp() { return timeStamp_; }
    inline const EmbeddedProto::uint64& get_timeStamp() const { return timeStamp_; }
    inline EmbeddedProto::uint64::FIELD_TYPE timeStamp() const { return timeStamp_.get(); }

    inline void clear_payload() { payload_.clear(); }
    inline ::EmbeddedProto::FieldBytes<payload_LENGTH>& mutable_payload() { return payload_; }
    inline void set_payload(const ::EmbeddedProto::FieldBytes<payload_LENGTH>& rhs) { payload_.set(rhs); }
    inline const ::EmbeddedProto::FieldBytes<payload_LENGTH>& get_payload() const { return payload_; }
    inline const uint8_t* payload() const { return payload_.get_const(); }


    ::EmbeddedProto::Error serialize(::EmbeddedProto::WriteBufferInterface& buffer) const override
    {
      ::EmbeddedProto::Error return_value = ::EmbeddedProto::Error::NO_ERRORS;

      if((static_cast<PBMessageType>(0) != type_) && (::EmbeddedProto::Error::NO_ERRORS == return_value))
      {
        EmbeddedProto::uint32 value = 0;
        value.set(static_cast<uint32_t>(type_));
        return_value = value.serialize_with_id(static_cast<uint32_t>(id::TYPE), buffer);
      }

      if((0U != timeStamp_.get()) && (::EmbeddedProto::Error::NO_ERRORS == return_value))
      {
        return_value = timeStamp_.serialize_with_id(static_cast<uint32_t>(id::TIMESTAMP), buffer);
      }

      if(::EmbeddedProto::Error::NO_ERRORS == return_value)
      {
        return_value = payload_.serialize_with_id(static_cast<uint32_t>(id::PAYLOAD), buffer);
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
          case id::TYPE:
            if(::EmbeddedProto::WireFormatter::WireType::VARINT == wire_type)
            {
              uint32_t value = 0;
              return_value = ::EmbeddedProto::WireFormatter::DeserializeVarint(buffer, value);
              if(::EmbeddedProto::Error::NO_ERRORS == return_value)
              {
                set_type(static_cast<PBMessageType>(value));
              }
            }
            else
            {
              // Wire type does not match field.
              return_value = ::EmbeddedProto::Error::INVALID_WIRETYPE;
            }
            break;

          case id::TIMESTAMP:
            return_value = timeStamp_.deserialize_check_type(buffer, wire_type);
            break;

          case id::PAYLOAD:
            return_value = payload_.deserialize_check_type(buffer, wire_type);
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
      clear_type();
      clear_timeStamp();
      clear_payload();

    }

    private:

      PBMessageType type_ = static_cast<PBMessageType>(0);
      EmbeddedProto::uint64 timeStamp_ = 0U;
      ::EmbeddedProto::FieldBytes<payload_LENGTH> payload_;

};

#endif // MESSAGEBASE_H