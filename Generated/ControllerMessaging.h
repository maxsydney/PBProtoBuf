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


enum class ControllerDataRequestType : uint32_t
{
  NONE = 0,
  TUNING = 1,
  SETTINGS = 2,
  PERIPHERAL_STATE = 3
};

enum class ComponentState : uint32_t
{
  OFF_STATE = 0,
  ON_STATE = 1
};

enum class PumpMode : uint32_t
{
  PUMP_OFF = 0,
  ACTIVE_CONTROL = 1,
  MANUAL_CONTROL = 2
};

class PumpSpeeds final: public ::EmbeddedProto::MessageInterface
{
  public:
    PumpSpeeds() = default;
    PumpSpeeds(const PumpSpeeds& rhs )
    {
      set_refluxPumpSpeed(rhs.get_refluxPumpSpeed());
      set_productPumpSpeed(rhs.get_productPumpSpeed());
    }

    PumpSpeeds(const PumpSpeeds&& rhs ) noexcept
    {
      set_refluxPumpSpeed(rhs.get_refluxPumpSpeed());
      set_productPumpSpeed(rhs.get_productPumpSpeed());
    }

    ~PumpSpeeds() override = default;

    enum class id : uint32_t
    {
      NOT_SET = 0,
      REFLUXPUMPSPEED = 1,
      PRODUCTPUMPSPEED = 2
    };

    PumpSpeeds& operator=(const PumpSpeeds& rhs)
    {
      set_refluxPumpSpeed(rhs.get_refluxPumpSpeed());
      set_productPumpSpeed(rhs.get_productPumpSpeed());
      return *this;
    }

    PumpSpeeds& operator=(const PumpSpeeds&& rhs) noexcept
    {
      set_refluxPumpSpeed(rhs.get_refluxPumpSpeed());
      set_productPumpSpeed(rhs.get_productPumpSpeed());
      return *this;
    }

    inline void clear_refluxPumpSpeed() { refluxPumpSpeed_.clear(); }
    inline void set_refluxPumpSpeed(const EmbeddedProto::doublefixed& value) { refluxPumpSpeed_ = value; }
    inline void set_refluxPumpSpeed(const EmbeddedProto::doublefixed&& value) { refluxPumpSpeed_ = value; }
    inline EmbeddedProto::doublefixed& mutable_refluxPumpSpeed() { return refluxPumpSpeed_; }
    inline const EmbeddedProto::doublefixed& get_refluxPumpSpeed() const { return refluxPumpSpeed_; }
    inline EmbeddedProto::doublefixed::FIELD_TYPE refluxPumpSpeed() const { return refluxPumpSpeed_.get(); }

    inline void clear_productPumpSpeed() { productPumpSpeed_.clear(); }
    inline void set_productPumpSpeed(const EmbeddedProto::doublefixed& value) { productPumpSpeed_ = value; }
    inline void set_productPumpSpeed(const EmbeddedProto::doublefixed&& value) { productPumpSpeed_ = value; }
    inline EmbeddedProto::doublefixed& mutable_productPumpSpeed() { return productPumpSpeed_; }
    inline const EmbeddedProto::doublefixed& get_productPumpSpeed() const { return productPumpSpeed_; }
    inline EmbeddedProto::doublefixed::FIELD_TYPE productPumpSpeed() const { return productPumpSpeed_.get(); }


    ::EmbeddedProto::Error serialize(::EmbeddedProto::WriteBufferInterface& buffer) const override
    {
      ::EmbeddedProto::Error return_value = ::EmbeddedProto::Error::NO_ERRORS;

      if((0.0 != refluxPumpSpeed_.get()) && (::EmbeddedProto::Error::NO_ERRORS == return_value))
      {
        return_value = refluxPumpSpeed_.serialize_with_id(static_cast<uint32_t>(id::REFLUXPUMPSPEED), buffer);
      }

      if((0.0 != productPumpSpeed_.get()) && (::EmbeddedProto::Error::NO_ERRORS == return_value))
      {
        return_value = productPumpSpeed_.serialize_with_id(static_cast<uint32_t>(id::PRODUCTPUMPSPEED), buffer);
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
          case id::REFLUXPUMPSPEED:
            return_value = refluxPumpSpeed_.deserialize_check_type(buffer, wire_type);
            break;

          case id::PRODUCTPUMPSPEED:
            return_value = productPumpSpeed_.deserialize_check_type(buffer, wire_type);
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
      clear_refluxPumpSpeed();
      clear_productPumpSpeed();

    }

    private:

      EmbeddedProto::doublefixed refluxPumpSpeed_ = 0.0;
      EmbeddedProto::doublefixed productPumpSpeed_ = 0.0;

};

class ControllerSettings final: public ::EmbeddedProto::MessageInterface
{
  public:
    ControllerSettings() = default;
    ControllerSettings(const ControllerSettings& rhs )
    {
      set_refluxPumpMode(rhs.get_refluxPumpMode());
      set_productPumpMode(rhs.get_productPumpMode());
      set_manualPumpSpeeds(rhs.get_manualPumpSpeeds());
    }

    ControllerSettings(const ControllerSettings&& rhs ) noexcept
    {
      set_refluxPumpMode(rhs.get_refluxPumpMode());
      set_productPumpMode(rhs.get_productPumpMode());
      set_manualPumpSpeeds(rhs.get_manualPumpSpeeds());
    }

    ~ControllerSettings() override = default;

    enum class id : uint32_t
    {
      NOT_SET = 0,
      REFLUXPUMPMODE = 1,
      PRODUCTPUMPMODE = 2,
      MANUALPUMPSPEEDS = 3
    };

    ControllerSettings& operator=(const ControllerSettings& rhs)
    {
      set_refluxPumpMode(rhs.get_refluxPumpMode());
      set_productPumpMode(rhs.get_productPumpMode());
      set_manualPumpSpeeds(rhs.get_manualPumpSpeeds());
      return *this;
    }

    ControllerSettings& operator=(const ControllerSettings&& rhs) noexcept
    {
      set_refluxPumpMode(rhs.get_refluxPumpMode());
      set_productPumpMode(rhs.get_productPumpMode());
      set_manualPumpSpeeds(rhs.get_manualPumpSpeeds());
      return *this;
    }

    inline void clear_refluxPumpMode() { refluxPumpMode_ = static_cast<PumpMode>(0); }
    inline void set_refluxPumpMode(const PumpMode& value) { refluxPumpMode_ = value; }
    inline void set_refluxPumpMode(const PumpMode&& value) { refluxPumpMode_ = value; }
    inline const PumpMode& get_refluxPumpMode() const { return refluxPumpMode_; }
    inline PumpMode refluxPumpMode() const { return refluxPumpMode_; }

    inline void clear_productPumpMode() { productPumpMode_ = static_cast<PumpMode>(0); }
    inline void set_productPumpMode(const PumpMode& value) { productPumpMode_ = value; }
    inline void set_productPumpMode(const PumpMode&& value) { productPumpMode_ = value; }
    inline const PumpMode& get_productPumpMode() const { return productPumpMode_; }
    inline PumpMode productPumpMode() const { return productPumpMode_; }

    inline void clear_manualPumpSpeeds() { manualPumpSpeeds_.clear(); }
    inline void set_manualPumpSpeeds(const PumpSpeeds& value) { manualPumpSpeeds_ = value; }
    inline void set_manualPumpSpeeds(const PumpSpeeds&& value) { manualPumpSpeeds_ = value; }
    inline PumpSpeeds& mutable_manualPumpSpeeds() { return manualPumpSpeeds_; }
    inline const PumpSpeeds& get_manualPumpSpeeds() const { return manualPumpSpeeds_; }
    inline const PumpSpeeds& manualPumpSpeeds() const { return manualPumpSpeeds_; }


    ::EmbeddedProto::Error serialize(::EmbeddedProto::WriteBufferInterface& buffer) const override
    {
      ::EmbeddedProto::Error return_value = ::EmbeddedProto::Error::NO_ERRORS;

      if((static_cast<PumpMode>(0) != refluxPumpMode_) && (::EmbeddedProto::Error::NO_ERRORS == return_value))
      {
        EmbeddedProto::uint32 value = 0;
        value.set(static_cast<uint32_t>(refluxPumpMode_));
        return_value = value.serialize_with_id(static_cast<uint32_t>(id::REFLUXPUMPMODE), buffer);
      }

      if((static_cast<PumpMode>(0) != productPumpMode_) && (::EmbeddedProto::Error::NO_ERRORS == return_value))
      {
        EmbeddedProto::uint32 value = 0;
        value.set(static_cast<uint32_t>(productPumpMode_));
        return_value = value.serialize_with_id(static_cast<uint32_t>(id::PRODUCTPUMPMODE), buffer);
      }

      if(::EmbeddedProto::Error::NO_ERRORS == return_value)
      {
        return_value = manualPumpSpeeds_.serialize_with_id(static_cast<uint32_t>(id::MANUALPUMPSPEEDS), buffer);
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
          case id::REFLUXPUMPMODE:
            if(::EmbeddedProto::WireFormatter::WireType::VARINT == wire_type)
            {
              uint32_t value = 0;
              return_value = ::EmbeddedProto::WireFormatter::DeserializeVarint(buffer, value);
              if(::EmbeddedProto::Error::NO_ERRORS == return_value)
              {
                set_refluxPumpMode(static_cast<PumpMode>(value));
              }
            }
            else
            {
              // Wire type does not match field.
              return_value = ::EmbeddedProto::Error::INVALID_WIRETYPE;
            }
            break;

          case id::PRODUCTPUMPMODE:
            if(::EmbeddedProto::WireFormatter::WireType::VARINT == wire_type)
            {
              uint32_t value = 0;
              return_value = ::EmbeddedProto::WireFormatter::DeserializeVarint(buffer, value);
              if(::EmbeddedProto::Error::NO_ERRORS == return_value)
              {
                set_productPumpMode(static_cast<PumpMode>(value));
              }
            }
            else
            {
              // Wire type does not match field.
              return_value = ::EmbeddedProto::Error::INVALID_WIRETYPE;
            }
            break;

          case id::MANUALPUMPSPEEDS:
            return_value = manualPumpSpeeds_.deserialize_check_type(buffer, wire_type);
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
      clear_refluxPumpMode();
      clear_productPumpMode();
      clear_manualPumpSpeeds();

    }

    private:

      PumpMode refluxPumpMode_ = static_cast<PumpMode>(0);
      PumpMode productPumpMode_ = static_cast<PumpMode>(0);
      PumpSpeeds manualPumpSpeeds_;

};

class ControllerState final: public ::EmbeddedProto::MessageInterface
{
  public:
    ControllerState() = default;
    ControllerState(const ControllerState& rhs )
    {
      set_propOutput(rhs.get_propOutput());
      set_integralOutput(rhs.get_integralOutput());
      set_derivOutput(rhs.get_derivOutput());
      set_totalOutput(rhs.get_totalOutput());
      set_timeStamp(rhs.get_timeStamp());
    }

    ControllerState(const ControllerState&& rhs ) noexcept
    {
      set_propOutput(rhs.get_propOutput());
      set_integralOutput(rhs.get_integralOutput());
      set_derivOutput(rhs.get_derivOutput());
      set_totalOutput(rhs.get_totalOutput());
      set_timeStamp(rhs.get_timeStamp());
    }

    ~ControllerState() override = default;

    enum class id : uint32_t
    {
      NOT_SET = 0,
      PROPOUTPUT = 1,
      INTEGRALOUTPUT = 2,
      DERIVOUTPUT = 3,
      TOTALOUTPUT = 4,
      TIMESTAMP = 5
    };

    ControllerState& operator=(const ControllerState& rhs)
    {
      set_propOutput(rhs.get_propOutput());
      set_integralOutput(rhs.get_integralOutput());
      set_derivOutput(rhs.get_derivOutput());
      set_totalOutput(rhs.get_totalOutput());
      set_timeStamp(rhs.get_timeStamp());
      return *this;
    }

    ControllerState& operator=(const ControllerState&& rhs) noexcept
    {
      set_propOutput(rhs.get_propOutput());
      set_integralOutput(rhs.get_integralOutput());
      set_derivOutput(rhs.get_derivOutput());
      set_totalOutput(rhs.get_totalOutput());
      set_timeStamp(rhs.get_timeStamp());
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

    inline void clear_timeStamp() { timeStamp_.clear(); }
    inline void set_timeStamp(const EmbeddedProto::uint32& value) { timeStamp_ = value; }
    inline void set_timeStamp(const EmbeddedProto::uint32&& value) { timeStamp_ = value; }
    inline EmbeddedProto::uint32& mutable_timeStamp() { return timeStamp_; }
    inline const EmbeddedProto::uint32& get_timeStamp() const { return timeStamp_; }
    inline EmbeddedProto::uint32::FIELD_TYPE timeStamp() const { return timeStamp_.get(); }


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
      clear_propOutput();
      clear_integralOutput();
      clear_derivOutput();
      clear_totalOutput();
      clear_timeStamp();

    }

    private:

      EmbeddedProto::doublefixed propOutput_ = 0.0;
      EmbeddedProto::doublefixed integralOutput_ = 0.0;
      EmbeddedProto::doublefixed derivOutput_ = 0.0;
      EmbeddedProto::doublefixed totalOutput_ = 0.0;
      EmbeddedProto::uint32 timeStamp_ = 0U;

};

class IIRLowpassFilterTuning final: public ::EmbeddedProto::MessageInterface
{
  public:
    IIRLowpassFilterTuning() = default;
    IIRLowpassFilterTuning(const IIRLowpassFilterTuning& rhs )
    {
      set_sampleFreq(rhs.get_sampleFreq());
      set_cutoffFreq(rhs.get_cutoffFreq());
    }

    IIRLowpassFilterTuning(const IIRLowpassFilterTuning&& rhs ) noexcept
    {
      set_sampleFreq(rhs.get_sampleFreq());
      set_cutoffFreq(rhs.get_cutoffFreq());
    }

    ~IIRLowpassFilterTuning() override = default;

    enum class id : uint32_t
    {
      NOT_SET = 0,
      SAMPLEFREQ = 1,
      CUTOFFFREQ = 2
    };

    IIRLowpassFilterTuning& operator=(const IIRLowpassFilterTuning& rhs)
    {
      set_sampleFreq(rhs.get_sampleFreq());
      set_cutoffFreq(rhs.get_cutoffFreq());
      return *this;
    }

    IIRLowpassFilterTuning& operator=(const IIRLowpassFilterTuning&& rhs) noexcept
    {
      set_sampleFreq(rhs.get_sampleFreq());
      set_cutoffFreq(rhs.get_cutoffFreq());
      return *this;
    }

    inline void clear_sampleFreq() { sampleFreq_.clear(); }
    inline void set_sampleFreq(const EmbeddedProto::doublefixed& value) { sampleFreq_ = value; }
    inline void set_sampleFreq(const EmbeddedProto::doublefixed&& value) { sampleFreq_ = value; }
    inline EmbeddedProto::doublefixed& mutable_sampleFreq() { return sampleFreq_; }
    inline const EmbeddedProto::doublefixed& get_sampleFreq() const { return sampleFreq_; }
    inline EmbeddedProto::doublefixed::FIELD_TYPE sampleFreq() const { return sampleFreq_.get(); }

    inline void clear_cutoffFreq() { cutoffFreq_.clear(); }
    inline void set_cutoffFreq(const EmbeddedProto::doublefixed& value) { cutoffFreq_ = value; }
    inline void set_cutoffFreq(const EmbeddedProto::doublefixed&& value) { cutoffFreq_ = value; }
    inline EmbeddedProto::doublefixed& mutable_cutoffFreq() { return cutoffFreq_; }
    inline const EmbeddedProto::doublefixed& get_cutoffFreq() const { return cutoffFreq_; }
    inline EmbeddedProto::doublefixed::FIELD_TYPE cutoffFreq() const { return cutoffFreq_.get(); }


    ::EmbeddedProto::Error serialize(::EmbeddedProto::WriteBufferInterface& buffer) const override
    {
      ::EmbeddedProto::Error return_value = ::EmbeddedProto::Error::NO_ERRORS;

      if((0.0 != sampleFreq_.get()) && (::EmbeddedProto::Error::NO_ERRORS == return_value))
      {
        return_value = sampleFreq_.serialize_with_id(static_cast<uint32_t>(id::SAMPLEFREQ), buffer);
      }

      if((0.0 != cutoffFreq_.get()) && (::EmbeddedProto::Error::NO_ERRORS == return_value))
      {
        return_value = cutoffFreq_.serialize_with_id(static_cast<uint32_t>(id::CUTOFFFREQ), buffer);
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
          case id::SAMPLEFREQ:
            return_value = sampleFreq_.deserialize_check_type(buffer, wire_type);
            break;

          case id::CUTOFFFREQ:
            return_value = cutoffFreq_.deserialize_check_type(buffer, wire_type);
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
      clear_sampleFreq();
      clear_cutoffFreq();

    }

    private:

      EmbeddedProto::doublefixed sampleFreq_ = 0.0;
      EmbeddedProto::doublefixed cutoffFreq_ = 0.0;

};

class ControllerTuning final: public ::EmbeddedProto::MessageInterface
{
  public:
    ControllerTuning() = default;
    ControllerTuning(const ControllerTuning& rhs )
    {
      set_setpoint(rhs.get_setpoint());
      set_PGain(rhs.get_PGain());
      set_IGain(rhs.get_IGain());
      set_DGain(rhs.get_DGain());
    }

    ControllerTuning(const ControllerTuning&& rhs ) noexcept
    {
      set_setpoint(rhs.get_setpoint());
      set_PGain(rhs.get_PGain());
      set_IGain(rhs.get_IGain());
      set_DGain(rhs.get_DGain());
    }

    ~ControllerTuning() override = default;

    enum class id : uint32_t
    {
      NOT_SET = 0,
      SETPOINT = 1,
      PGAIN = 2,
      IGAIN = 3,
      DGAIN = 4
    };

    ControllerTuning& operator=(const ControllerTuning& rhs)
    {
      set_setpoint(rhs.get_setpoint());
      set_PGain(rhs.get_PGain());
      set_IGain(rhs.get_IGain());
      set_DGain(rhs.get_DGain());
      return *this;
    }

    ControllerTuning& operator=(const ControllerTuning&& rhs) noexcept
    {
      set_setpoint(rhs.get_setpoint());
      set_PGain(rhs.get_PGain());
      set_IGain(rhs.get_IGain());
      set_DGain(rhs.get_DGain());
      return *this;
    }

    inline void clear_setpoint() { setpoint_.clear(); }
    inline void set_setpoint(const EmbeddedProto::doublefixed& value) { setpoint_ = value; }
    inline void set_setpoint(const EmbeddedProto::doublefixed&& value) { setpoint_ = value; }
    inline EmbeddedProto::doublefixed& mutable_setpoint() { return setpoint_; }
    inline const EmbeddedProto::doublefixed& get_setpoint() const { return setpoint_; }
    inline EmbeddedProto::doublefixed::FIELD_TYPE setpoint() const { return setpoint_.get(); }

    inline void clear_PGain() { PGain_.clear(); }
    inline void set_PGain(const EmbeddedProto::doublefixed& value) { PGain_ = value; }
    inline void set_PGain(const EmbeddedProto::doublefixed&& value) { PGain_ = value; }
    inline EmbeddedProto::doublefixed& mutable_PGain() { return PGain_; }
    inline const EmbeddedProto::doublefixed& get_PGain() const { return PGain_; }
    inline EmbeddedProto::doublefixed::FIELD_TYPE PGain() const { return PGain_.get(); }

    inline void clear_IGain() { IGain_.clear(); }
    inline void set_IGain(const EmbeddedProto::doublefixed& value) { IGain_ = value; }
    inline void set_IGain(const EmbeddedProto::doublefixed&& value) { IGain_ = value; }
    inline EmbeddedProto::doublefixed& mutable_IGain() { return IGain_; }
    inline const EmbeddedProto::doublefixed& get_IGain() const { return IGain_; }
    inline EmbeddedProto::doublefixed::FIELD_TYPE IGain() const { return IGain_.get(); }

    inline void clear_DGain() { DGain_.clear(); }
    inline void set_DGain(const EmbeddedProto::doublefixed& value) { DGain_ = value; }
    inline void set_DGain(const EmbeddedProto::doublefixed&& value) { DGain_ = value; }
    inline EmbeddedProto::doublefixed& mutable_DGain() { return DGain_; }
    inline const EmbeddedProto::doublefixed& get_DGain() const { return DGain_; }
    inline EmbeddedProto::doublefixed::FIELD_TYPE DGain() const { return DGain_.get(); }


    ::EmbeddedProto::Error serialize(::EmbeddedProto::WriteBufferInterface& buffer) const override
    {
      ::EmbeddedProto::Error return_value = ::EmbeddedProto::Error::NO_ERRORS;

      if((0.0 != setpoint_.get()) && (::EmbeddedProto::Error::NO_ERRORS == return_value))
      {
        return_value = setpoint_.serialize_with_id(static_cast<uint32_t>(id::SETPOINT), buffer);
      }

      if((0.0 != PGain_.get()) && (::EmbeddedProto::Error::NO_ERRORS == return_value))
      {
        return_value = PGain_.serialize_with_id(static_cast<uint32_t>(id::PGAIN), buffer);
      }

      if((0.0 != IGain_.get()) && (::EmbeddedProto::Error::NO_ERRORS == return_value))
      {
        return_value = IGain_.serialize_with_id(static_cast<uint32_t>(id::IGAIN), buffer);
      }

      if((0.0 != DGain_.get()) && (::EmbeddedProto::Error::NO_ERRORS == return_value))
      {
        return_value = DGain_.serialize_with_id(static_cast<uint32_t>(id::DGAIN), buffer);
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
          case id::SETPOINT:
            return_value = setpoint_.deserialize_check_type(buffer, wire_type);
            break;

          case id::PGAIN:
            return_value = PGain_.deserialize_check_type(buffer, wire_type);
            break;

          case id::IGAIN:
            return_value = IGain_.deserialize_check_type(buffer, wire_type);
            break;

          case id::DGAIN:
            return_value = DGain_.deserialize_check_type(buffer, wire_type);
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
      clear_setpoint();
      clear_PGain();
      clear_IGain();
      clear_DGain();

    }

    private:

      EmbeddedProto::doublefixed setpoint_ = 0.0;
      EmbeddedProto::doublefixed PGain_ = 0.0;
      EmbeddedProto::doublefixed IGain_ = 0.0;
      EmbeddedProto::doublefixed DGain_ = 0.0;

};

class ControllerCommand final: public ::EmbeddedProto::MessageInterface
{
  public:
    ControllerCommand() = default;
    ControllerCommand(const ControllerCommand& rhs )
    {
      set_fanState(rhs.get_fanState());
      set_LPElementDutyCycle(rhs.get_LPElementDutyCycle());
      set_HPElementDutyCycle(rhs.get_HPElementDutyCycle());
    }

    ControllerCommand(const ControllerCommand&& rhs ) noexcept
    {
      set_fanState(rhs.get_fanState());
      set_LPElementDutyCycle(rhs.get_LPElementDutyCycle());
      set_HPElementDutyCycle(rhs.get_HPElementDutyCycle());
    }

    ~ControllerCommand() override = default;

    enum class id : uint32_t
    {
      NOT_SET = 0,
      FANSTATE = 1,
      LPELEMENTDUTYCYCLE = 2,
      HPELEMENTDUTYCYCLE = 3
    };

    ControllerCommand& operator=(const ControllerCommand& rhs)
    {
      set_fanState(rhs.get_fanState());
      set_LPElementDutyCycle(rhs.get_LPElementDutyCycle());
      set_HPElementDutyCycle(rhs.get_HPElementDutyCycle());
      return *this;
    }

    ControllerCommand& operator=(const ControllerCommand&& rhs) noexcept
    {
      set_fanState(rhs.get_fanState());
      set_LPElementDutyCycle(rhs.get_LPElementDutyCycle());
      set_HPElementDutyCycle(rhs.get_HPElementDutyCycle());
      return *this;
    }

    inline void clear_fanState() { fanState_ = static_cast<ComponentState>(0); }
    inline void set_fanState(const ComponentState& value) { fanState_ = value; }
    inline void set_fanState(const ComponentState&& value) { fanState_ = value; }
    inline const ComponentState& get_fanState() const { return fanState_; }
    inline ComponentState fanState() const { return fanState_; }

    inline void clear_LPElementDutyCycle() { LPElementDutyCycle_.clear(); }
    inline void set_LPElementDutyCycle(const EmbeddedProto::doublefixed& value) { LPElementDutyCycle_ = value; }
    inline void set_LPElementDutyCycle(const EmbeddedProto::doublefixed&& value) { LPElementDutyCycle_ = value; }
    inline EmbeddedProto::doublefixed& mutable_LPElementDutyCycle() { return LPElementDutyCycle_; }
    inline const EmbeddedProto::doublefixed& get_LPElementDutyCycle() const { return LPElementDutyCycle_; }
    inline EmbeddedProto::doublefixed::FIELD_TYPE LPElementDutyCycle() const { return LPElementDutyCycle_.get(); }

    inline void clear_HPElementDutyCycle() { HPElementDutyCycle_.clear(); }
    inline void set_HPElementDutyCycle(const EmbeddedProto::doublefixed& value) { HPElementDutyCycle_ = value; }
    inline void set_HPElementDutyCycle(const EmbeddedProto::doublefixed&& value) { HPElementDutyCycle_ = value; }
    inline EmbeddedProto::doublefixed& mutable_HPElementDutyCycle() { return HPElementDutyCycle_; }
    inline const EmbeddedProto::doublefixed& get_HPElementDutyCycle() const { return HPElementDutyCycle_; }
    inline EmbeddedProto::doublefixed::FIELD_TYPE HPElementDutyCycle() const { return HPElementDutyCycle_.get(); }


    ::EmbeddedProto::Error serialize(::EmbeddedProto::WriteBufferInterface& buffer) const override
    {
      ::EmbeddedProto::Error return_value = ::EmbeddedProto::Error::NO_ERRORS;

      if((static_cast<ComponentState>(0) != fanState_) && (::EmbeddedProto::Error::NO_ERRORS == return_value))
      {
        EmbeddedProto::uint32 value = 0;
        value.set(static_cast<uint32_t>(fanState_));
        return_value = value.serialize_with_id(static_cast<uint32_t>(id::FANSTATE), buffer);
      }

      if((0.0 != LPElementDutyCycle_.get()) && (::EmbeddedProto::Error::NO_ERRORS == return_value))
      {
        return_value = LPElementDutyCycle_.serialize_with_id(static_cast<uint32_t>(id::LPELEMENTDUTYCYCLE), buffer);
      }

      if((0.0 != HPElementDutyCycle_.get()) && (::EmbeddedProto::Error::NO_ERRORS == return_value))
      {
        return_value = HPElementDutyCycle_.serialize_with_id(static_cast<uint32_t>(id::HPELEMENTDUTYCYCLE), buffer);
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
          case id::FANSTATE:
            if(::EmbeddedProto::WireFormatter::WireType::VARINT == wire_type)
            {
              uint32_t value = 0;
              return_value = ::EmbeddedProto::WireFormatter::DeserializeVarint(buffer, value);
              if(::EmbeddedProto::Error::NO_ERRORS == return_value)
              {
                set_fanState(static_cast<ComponentState>(value));
              }
            }
            else
            {
              // Wire type does not match field.
              return_value = ::EmbeddedProto::Error::INVALID_WIRETYPE;
            }
            break;

          case id::LPELEMENTDUTYCYCLE:
            return_value = LPElementDutyCycle_.deserialize_check_type(buffer, wire_type);
            break;

          case id::HPELEMENTDUTYCYCLE:
            return_value = HPElementDutyCycle_.deserialize_check_type(buffer, wire_type);
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
      clear_fanState();
      clear_LPElementDutyCycle();
      clear_HPElementDutyCycle();

    }

    private:

      ComponentState fanState_ = static_cast<ComponentState>(0);
      EmbeddedProto::doublefixed LPElementDutyCycle_ = 0.0;
      EmbeddedProto::doublefixed HPElementDutyCycle_ = 0.0;

};

class ControllerDataRequest final: public ::EmbeddedProto::MessageInterface
{
  public:
    ControllerDataRequest() = default;
    ControllerDataRequest(const ControllerDataRequest& rhs )
    {
      set_requestType(rhs.get_requestType());
    }

    ControllerDataRequest(const ControllerDataRequest&& rhs ) noexcept
    {
      set_requestType(rhs.get_requestType());
    }

    ~ControllerDataRequest() override = default;

    enum class id : uint32_t
    {
      NOT_SET = 0,
      REQUESTTYPE = 1
    };

    ControllerDataRequest& operator=(const ControllerDataRequest& rhs)
    {
      set_requestType(rhs.get_requestType());
      return *this;
    }

    ControllerDataRequest& operator=(const ControllerDataRequest&& rhs) noexcept
    {
      set_requestType(rhs.get_requestType());
      return *this;
    }

    inline void clear_requestType() { requestType_ = static_cast<ControllerDataRequestType>(0); }
    inline void set_requestType(const ControllerDataRequestType& value) { requestType_ = value; }
    inline void set_requestType(const ControllerDataRequestType&& value) { requestType_ = value; }
    inline const ControllerDataRequestType& get_requestType() const { return requestType_; }
    inline ControllerDataRequestType requestType() const { return requestType_; }


    ::EmbeddedProto::Error serialize(::EmbeddedProto::WriteBufferInterface& buffer) const override
    {
      ::EmbeddedProto::Error return_value = ::EmbeddedProto::Error::NO_ERRORS;

      if((static_cast<ControllerDataRequestType>(0) != requestType_) && (::EmbeddedProto::Error::NO_ERRORS == return_value))
      {
        EmbeddedProto::uint32 value = 0;
        value.set(static_cast<uint32_t>(requestType_));
        return_value = value.serialize_with_id(static_cast<uint32_t>(id::REQUESTTYPE), buffer);
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
          case id::REQUESTTYPE:
            if(::EmbeddedProto::WireFormatter::WireType::VARINT == wire_type)
            {
              uint32_t value = 0;
              return_value = ::EmbeddedProto::WireFormatter::DeserializeVarint(buffer, value);
              if(::EmbeddedProto::Error::NO_ERRORS == return_value)
              {
                set_requestType(static_cast<ControllerDataRequestType>(value));
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
      clear_requestType();

    }

    private:

      ControllerDataRequestType requestType_ = static_cast<ControllerDataRequestType>(0);

};

#endif // CONTROLLERMESSAGING_H