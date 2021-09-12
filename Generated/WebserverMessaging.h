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
#ifndef WEBSERVERMESSAGING_H
#define WEBSERVERMESSAGING_H

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


template<uint32_t logMsg_LENGTH>
class SocketLogMessage final: public ::EmbeddedProto::MessageInterface
{
  public:
    SocketLogMessage() = default;
    SocketLogMessage(const SocketLogMessage& rhs )
    {
      set_logMsg(rhs.get_logMsg());
    }

    SocketLogMessage(const SocketLogMessage&& rhs ) noexcept
    {
      set_logMsg(rhs.get_logMsg());
    }

    ~SocketLogMessage() override = default;

    enum class id : uint32_t
    {
      NOT_SET = 0,
      LOGMSG = 1
    };

    SocketLogMessage& operator=(const SocketLogMessage& rhs)
    {
      set_logMsg(rhs.get_logMsg());
      return *this;
    }

    SocketLogMessage& operator=(const SocketLogMessage&& rhs) noexcept
    {
      set_logMsg(rhs.get_logMsg());
      return *this;
    }

    inline void clear_logMsg() { logMsg_.clear(); }
    inline ::EmbeddedProto::FieldString<logMsg_LENGTH>& mutable_logMsg() { return logMsg_; }
    inline void set_logMsg(const ::EmbeddedProto::FieldString<logMsg_LENGTH>& rhs) { logMsg_.set(rhs); }
    inline const ::EmbeddedProto::FieldString<logMsg_LENGTH>& get_logMsg() const { return logMsg_; }
    inline const char* logMsg() const { return logMsg_.get_const(); }


    ::EmbeddedProto::Error serialize(::EmbeddedProto::WriteBufferInterface& buffer) const override
    {
      ::EmbeddedProto::Error return_value = ::EmbeddedProto::Error::NO_ERRORS;

      if(::EmbeddedProto::Error::NO_ERRORS == return_value)
      {
        return_value = logMsg_.serialize_with_id(static_cast<uint32_t>(id::LOGMSG), buffer);
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
          case id::LOGMSG:
            return_value = logMsg_.deserialize_check_type(buffer, wire_type);
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
      clear_logMsg();

    }

    private:

      ::EmbeddedProto::FieldString<logMsg_LENGTH> logMsg_;

};

#endif // WEBSERVERMESSAGING_H